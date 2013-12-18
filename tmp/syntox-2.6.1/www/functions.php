<?php

////////////////////////////////////////////////////////////
function dotToSvg($userdir, $dotoutputfile, $svgoutputfile, $erroutputfile)
{
  global $tr, $ln;
  // On transforme DOT en SVG
  if (file_exists($dotoutputfile) && filesize($dotoutputfile)>0){
      
      $nodes=0;
      $file = fopen($dotoutputfile,'r');
      while(!feof($file)){
	  fgets($file, 1024);
	  $nodes++;
      }
      fclose($file);
      
      if ($nodes > 10000){
	print '<H5>Too much nodes</H5>';
      } else {
	$command=DOTDIR."/dot -Tsvg $dotoutputfile -o $svgoutputfile 2> $erroutputfile";
	//print $command . '<br>';
	//print "<a href=\"$dotoutputfile\">DOT</a><br>";
	passthru($command);
	if (file_exists($erroutputfile) && filesize($erroutputfile)>0){
	  $file = fopen($erroutputfile,'r');
	  while(!feof($file)){
	    $ligne=str_replace(array('\t', '\n'), array('&nbsp;', '<BR>'), fgets($file, 1024));
	    print $ligne;
	  }
	}
      }
  } else {
    die (__FILE.'('.__LINE__.')');
  }
}

////////////////////////////////////////////////////////////
function removeOldDirectories($userdatadir, $min){
  global $verbose;
  if ($verbose)
    print '<H2>RemoveOldDirectories</H2>';
  // On efface les vieux dossiers utilisateur
  //die($userdir);
  if (file_exists($userdatadir)){
    @$dir=opendir($userdatadir);
    while ($entry=readdir($dir)){
      if($entry=="lexicon.txt.zip" || $entry==".." || $entry == ".")
	continue;
      //print "$entry <br>";
      $last_modified=filemtime("$userdatadir/$entry");
      $diff = time() - $last_modified;
      // Vieux = 10 minute(s)
      if($diff > $min*60){
	@$dir2=opendir("$userdatadir/$entry");
	while ($entry2=readdir($dir2)){
	  if($entry2==".." || $entry2 == ".")
	    continue;
	  //print "$userdatadir/$entry/$entry2 <br>";
	  unlink("$userdatadir/$entry/$entry2");
	}
	if (!rmdir("$userdatadir/$entry"))
	  die("It's not possible to remove $userdatadir/$entry directory");
      }
    }
  }
}

////////////////////////////////////////////////////////////
function createUserDirectory($home, $userdir){

  global $verbose;
  if ($verbose)
    print '<H2>CreateUserDirectory</H2>';
  // Création d'un dossier utilisateur
  if (!file_exists($home))	{
    if (!mkdir($home, 0755))
      die('cannot create directory '.$home);
  }   
  
  // Création d'un dossier utilisateur
  if (!file_exists($userdir)){
    if (!mkdir($userdir, 0755))
      die('cannot create directory '.$userdir);
  }
}

////////////////////////////////////////////////////////////
function makeVersionFile($versionoutputfile, $program){
  global $verbose;
  if ($verbose)
    print '<H2>MakeVersionFile</H2>';
  //phpinfo();
  //die(__FILE__.'('.__LINE__.')');
  $command = $program;
  $command .= " --version";
  $command .= " > ".$versionoutputfile;
  exec($command);
}

////////////////////////////////////////////////////////////
function makeOutFile($grammarfile, 
		     $lexiconfile, 
		     $inputfile, 
		     $erroutputfile, 
		     $outputfile,
		     $dotforestfile,
		     $dotitemsfile, 
		     $compactlexiconfile,
		     $xmlfile, 
		     $program){
  global $duration, $_POST, $_FILES, $analyse, $tr, $ln;
  global $verbose;
  if ($verbose)
    print '<H2>MakeOutFile</H2>';
  //phpinfo(INFO_VARIABLES);
  //die(__FILE__.'('.__LINE__.')');
  $time_before_parsing=microtime(true);

  $command = $program;
  // 20 seconds max
  $command .= " -maxTime 20";
  $command .= " -grammarFile $grammarfile -lexiconFile $lexiconfile";
  if ($compactlexiconfile)
    $command .= " -compactLexiconDirectory data -compactLexiconFile $compactlexiconfile";
  if ($inputfile)
    $command .= " -inputFile $inputfile";
  if (isset($_POST) && isset($_POST['maxLength']) && ($_POST['maxLength']!='0'))
    if ($_POST['maxLength'] <= '500')
      $command .= " -maxLength " . $_POST['maxLength'];
    else {
      die ('Max Stage too big');
    }

  if (isset($_POST) && isset($_POST['maxUsages']) && ($_POST['maxUsages']!='0'))
    if ($_POST['maxUsages'] <= '5000')
      $command .= " -maxUsages " . $_POST['maxUsages'];
    else
      die ('Max Usages too big');
  
  if (isset($_POST) && isset($_POST['xml']) && ($_POST['xml']=='yes'))
    $command .= " -xml $xmlfile";
  if ($verbose || (isset($_POST) && isset($_POST['verbose']) && ($_POST['verbose']=='yes')))
    $command .= ' --verbose';
  if (isset($_POST) && isset($_POST['trace']) && ($_POST['trace']=='yes'))
    $command .= ' --trace';
  if (isset($_POST) && isset($_POST['dotforest']) && ($_POST['dotforest']=='yes'))
    $command .= " -dotforest $dotforestfile";
  if (isset($_POST) && isset($_POST['dotitems']) && ($_POST['dotitems']=='yes'))
    $command .= " -dotitems $dotitemsfile";
  if (isset($_POST) && isset($_POST['reduceAll']) && ($_POST['reduceAll']=='yes'))
    $command .= ' --reduceAll';
  $command .= " > $outputfile";
  $command .= " 2> $erroutputfile";
  if ($verbose)
    print '<P>'.$command . '<BR>';
  //die(__FILE__.'('.__LINE__.')');
  
  if (isset($_POST) && isset($_POST['xml']) && ($_POST['xml']=='yes'))
    print "<a href=\"$xmlfile\">XML</a><br>";
  passthru($command);
  $time_after_parsing=microtime(true);
  $duration = $time_after_parsing-$time_before_parsing;
}

////////////////////////////////////////////////////////////
function makeDataFile($grammarfile, $lexiconfile, $inputfile, $withinput, $input){
  global $_POST, $_FILES, $tr, $ln;
  global $verbose;
  if ($verbose)
    print '<H2>MakeDataFile</H2>';
  //phpinfo(INFO_VARIABLES);
  //die(__FILE__.'('.__LINE__.')');
  $fileOutput = fopen($grammarfile, 'w');
  fwrite($fileOutput, "@grammar «\n");
  fwrite($fileOutput, "#line 1\n");
  if (isset($_POST['grammarText'])){
    fwrite($fileOutput, '#file "'.trad('grammar',$ln).'"'."\n");
    fwrite($fileOutput, str_replace("\r", "", stripslashes($_POST['grammarText'])));
  }
  else if (isset($_FILES['grammarFile'])) {
    fwrite($fileOutput, '#file "'.$_FILES['grammarFile']['name'].'"'."\n");
    if (is_readable($_FILES['grammarFile']['tmp_name'])){
      $fg=fopen($_FILES['grammarFile']['tmp_name'],'r');
      while (!feof($fg)){
	$buffer=fgets($fg, 4096);
	fwrite($fileOutput, $buffer);
      }
      fclose($fg);
    }
    else
      die('Illegible grammar file');
  }
  fwrite($fileOutput, "\n»\n");
  if (isset($_POST['axiom']) && ($_POST['axiom']!='')){
    fwrite($fileOutput, '#file "'.trad('axiom',$ln).'"'."\n");
    fwrite($fileOutput, "#line 1\n");
    fwrite($fileOutput, "@axiom «".$_POST['axiom']."»\n");
  }
  fclose($fileOutput);
  
  $fileOutput = fopen($lexiconfile,'w');
  fwrite($fileOutput, "@lexicon «\n");
  fwrite($fileOutput, "#line 1\n");
  if (isset($_POST['lexiconText'])){
    fwrite($fileOutput, '#file "'.trad('lexicon',$ln).'"'."\n");
    fwrite($fileOutput, str_replace("\r", "", stripslashes($_POST['lexiconText'])));
  } 
  else if (isset($_FILES['lexiconFile'])) {
    fwrite($fileOutput, '#file "'.$_FILES['lexiconFile']['name'].'"'."\n");
    if (is_readable($_FILES['lexiconFile']['tmp_name'])){
      $fg=fopen($_FILES['lexiconFile']['tmp_name'],'r');
      while (!feof($fg)){
	$buffer=fgets($fg, 4096);
	fwrite($fileOutput, $buffer);
      }
      fclose($fg);
    }
    else
      die('Illegible lexicon file');
  }
  fwrite($fileOutput, "\n»\n");
  fclose($fileOutput);

  if ($withinput){
    $fileOutput = fopen($inputfile,'w');
    fwrite($fileOutput, "@input  «\n");
    fwrite($fileOutput, '#file "'.trad('input',$ln).'"'."\n");
    fwrite($fileOutput, "#line 1\n");
    fwrite($fileOutput, str_replace("\r", "", $input)."»\n");
    fclose($fileOutput);
  }
  
  /* if (isset($_POST['lexiconHost'])){ */
  /*   fwrite($fileOutput, "@lexiconHost «".$_POST['lexiconHost']."»\n"); */
  /* }  */
  /* if (isset($_POST['lexiconPort'])){ */
  /*   fwrite($fileOutput, "@lexiconPort «".$_POST['lexiconPort']."»\n"); */
  /* }  */
  /* fclose($fileOutput); */
}

////////////////////////////////////////////////////////////
function makeInputFile($inputfile){
  global $_POST, $_FILES, $tr, $ln;
  global $verbose;
  if ($verbose)
    print '<H2>MakeInputFile</H2>';
  $fileInput = fopen($inputfile,'w');
  if (isset($_POST['inputData']) && $_POST['inputData']!=''){
    fwrite($fileInput, str_replace("\r", "", stripslashes($_POST['inputData'])));
  } 
  fclose($fileInput);
}

////////////////////////////////////////////////////////////
function xmlToOut($userdir, $xmloutputfile, $xslfile, $outputfile, $parameters)
{
  global $_REQUEST, $ln;
  if (!file_exists($xslfile))
    die("File $xslfile doesn't exist");
  
  $docxml = new DOMDocument();
  $docxml->load($xmloutputfile, LIBXML_PARSEHUGE|LIBXML_ERR_NONE|LIBXML_NOBLANKS|LIBXML_NOCDATA|LIBXML_NOERROR) or die('&ccedil;a bogue &ccedil;a bogue fonctions.php(12): '.$xmloutputfile);
  $docxsl = new DOMDocument();
  $docxsl->load($xslfile) or die('functions.php(261): '.$xslfile);
  $xslt = new XsltProcessor();
  $xslt->importStylesheet($docxsl);
  while (list($clef,$val)=each($parameters)){
    $xslt->setParameter(null, $clef, $val);
  }
  $obj = $xslt->transformToXML($docxml);
  $file = fopen($outputfile, "w");
  fwrite($file, $obj);
  fclose($file);
}
  
?>
