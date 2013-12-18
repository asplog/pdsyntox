<?php

// Affichage d'un bouton close
print '&nbsp;<button onClick=javascript:self.close()>'.ucfirst(trad('close this window',$ln)).'</button><br><hr>';

//phpinfo(INFO_VARIABLES);
//die(__FILE__.'('.__LINE__.')');

$userdir=USERDATADIR.'/'.$id_session;
$verbose=false;
if (isset($_POST) && isset($_POST['verbose']) && ($_POST['verbose']=='yes'))
  $verbose=true;

// On efface les vieux dossiers utilisateur
removeOldDirectories(USERDATADIR, 1);

// Création d'un nouveau dossier utilisateur
createUserDirectory(USERDATADIR, $userdir);

$attributes=array();
if (isset($_POST) && isset($_POST['attributes'])){
  print "<H5>Danger: eval('attributes')</H5>";
  eval('$attributes='.stripcslashes($_POST['attributes']).';');
}

$relation=array();
if (isset($_POST) && isset($_POST['relation'])){
  print "<H5>Danger: eval('relation')</H5>";
  eval ('$relation='.stripcslashes($_POST['relation']).';');
}

// Transforme en tableau associatif
$relationAssoc=array();
$i=0;
foreach($relation as $tuple){
  $relationAssoc[$i]=array();
  $j=0;
  foreach($tuple as $element){
    $relationAssoc[$i][$attributes[$j]] = $element;
    $j++;
  }
  $i++;
}

/***/
if (sizeof($relationAssoc)>0){
  print(__FILE__.'('.__LINE__.')');
  print '<table border="1">';
  print '<tr>';
  print '<td><b>Num</b></td>';
  for($i=0 ; $i<sizeof($attributes) ; $i++)
    print '<td><b>'.$attributes[$i].'</b></td>';
  print '</tr>';
  for($i=0 ; $i<sizeof($relation) ; $i++){
    print '<tr>';
    print '<td>'.(string)($i+1).'</td>';
    for($j=0 ; $j<sizeof($relation[$i]) ; $j++)
      print '<td>'.$relation[$i][$j].'</td>';
    print '</tr>';
  }
  print '</table>';
  /***/
} else {
  //print(__FILE__.'('.__LINE__.')');
  $relationAssoc=array(0);
}

$sub=array();
foreach($_POST as $postAttr => $postVal){
  if ((substr($postAttr, 0, 5)=='eval:')){
    //print(__FILE__.'('.__LINE__.')');
    //print "<H5>Danger: eval(".$postAttr.")</H5>";
    eval ('$sub = array_merge($sub, '.stripcslashes($postVal).');');
  }
}

if (sizeof($relationAssoc)>1)
  print '<OL>';
for($tuple=0 ; $tuple < sizeof($relationAssoc) ; $tuple++){
  //print(__FILE__.'('.__LINE__.')');
  if (sizeof($relationAssoc)>1)
    print '<LI>';
  
  //print '<HR>';
  //print "<H3>Tuple</H3>";
  //print_r($relation[$tuple]);
  
  $inputData=stripcslashes($_POST['inputData']);
  
  foreach($sub as $subAttr => $subVal){
    $pattern='/\$(\w*)/';
    $replace='\$relationAssoc['.$tuple.'][\'$1\']';
    $subVal2 = preg_replace($pattern, $replace, $subVal);

    /* print '<h5>$subVal2</h5>'; */
    /* print ($subVal2); */
    /* print '<HR>'; */
    eval('$subVal2 = '.$subVal2.';');
    /* print '<h5>$subVal2</h5>'; */
    /* print ($subVal2); */
    /* print '<HR>'; */
  
    $pattern='/\$'.$subAttr.'/';
    $replace=$subVal2;
    $inputData=stripcslashes(preg_replace($pattern, stripcslashes($replace), $inputData));
  }
  //print '<HR>'; 
  //print ($inputData);
  
  // Fabrication du fichier data
  $grammarfile=$userdir."/tmp.grammar.txt";
  $lexiconfile=$userdir."/tmp.lexicon.txt";
  $inputfile=$userdir."/tmp.input.txt";
  if (isset($_POST['inputData'])){
    //print "<H5>Danger: eval('inputData')</H5>";
    makeDataFile($grammarfile, $lexiconfile, $inputfile, true, $inputData);
  } else {
    makeDataFile($grammarfile, $lexiconfile, $inputfile, false, null);
  }   
  
  // Affichage du numéro de version
  $versionoutputfile=$userdir."/tmp.version";
  makeVersionFile($versionoutputfile, SYNTOXDIR.'/'.SYNTOX);
  $version = '<p>Syntox ';
  $fichier = fopen($versionoutputfile,'r');
  while(!feof($fichier)){
    $ligne=fgets($fichier, 1024);
    $version .= $ligne;
  }
  fclose($fichier);
  $version .= '</p>';
  print $version;

  $errfile=$userdir.'/tmp.err';
  $outputfile=$userdir.'/tmp.out';
  $xmlfile=$userdir.'/tmp.xml';
  $dotforestfile=$userdir.'/tmp-forest.dot';
  $dotitemsfile=$userdir.'/tmp-items.dot';
  $compactlexiconfile=false;
  $duration=0;
  if (isset($_POST['compactLexicon']))
    $compactlexiconfile=$_POST['compactLexicon'];
  makeOutFile($grammarfile,
	      $lexiconfile, 
	      $inputfile,
	      $errfile, 
	      $outputfile, 
	      $dotforestfile,
	      $dotitemsfile,
	      $compactlexiconfile,
	      $xmlfile,
	      SYNTOXDIR.'/'.SYNTOX);
  
  print sprintf("<p>".trad('delay',$ln).": %.3f ".trad('second(s)',$ln).'</p>', $duration);
  
  if (file_exists($errfile) && filesize($errfile)>0){
    $file = fopen($errfile,'r');
    $i=1;
    while(!feof($file)){
      $line=trim(fgets($file, 10240));
      print $line;
      if (($i++) > 20000){
	print 'â¦';
	break;
      }
    }
    fclose($file);
  }
  
  $content='';
  $patterns=array('/^(.*)⇒(.*)/');
  $replace=array("	\$_ =~ s/\\1/\\2/g;\n");
  if (isset($_POST['postEditionText'])){
    $input=explode("\n", str_replace("\r", '', stripslashes($_POST['postEditionText'])));
    foreach($input as $line){
      $content .= preg_replace($patterns, $replace, $line);
    }
  }
  else if (isset($_FILES['postEditionFile'])) {
    //die(__FILE__.'('.__LINE__.')');
    if (is_readable($_FILES['postEditionFile']['tmp_name'])){
      $file=$_FILES['postEditionFile']['tmp_name'];
      $f=fopen($file, 'r') or exit('Unable to open file!');
      while (!feof($f)){
	$line=fgets($f);
	$content .= preg_replace($patterns, $replace, $line);
      }
      fclose($f);
    }
    else
      die('Illegible postEdition file');
  }
  
  //
  $perloutputfile=$userdir."/tmp.perl";
  $perlfile = fopen($perloutputfile,'w');
  fwrite($perlfile, "#!/opt/local/bin/perl\nwhile (<>) {\n");
  fwrite($perlfile, $content."\n");
  fwrite($perlfile, "print $_;\n}");
  fclose($perlfile);
  
  $output2file=$userdir."/tmp.out2";
  $command = 'perl ' . $perloutputfile . ' < '. $outputfile . ' > ' . $output2file;
  passthru($command);
  //$output2file=$userdir."/tmp.out2";
  //$command = $perlfile . ' < '. $outputfile . ' > ' . $output2file;
  //passthru($command);
  
  if (isset($_POST) && isset($_POST['style']) && ($_POST['style']=='1')){
    $file = fopen($output2file,'r');
    $i=1;
    while(!feof($file)){
      $line=trim(fgets($file, 10240));
      print '<TEXTAREA cols="80" rows="120" name="" value="">';
      print $line;
      print '</TEXTAREA>';
      $i++;
    }
    fclose($file);
  }
  else {
    $file = fopen($output2file,'r');
    $i=1;
    while(!feof($file)){
      $line=trim(fgets($file, 10240));
      print '<DIV>';
      print $line;
      print '</DIV>';
      $i++;
    }
    fclose($file);
  }
  if (sizeof($relationAssoc)>1)
    print '</LI>';
}
if (sizeof($relationAssoc)>1)
  print '</OL>';

/***/
if (file_exists($dotforestfile)){
  $svgfile=$userdir."/tmp-forest.svg";
  dotToSvg($userdir, $dotforestfile, $svgfile, $errfile);
  print "<object data=\"$svgfile\" type=\"image/svg+xml\" align=\"middle\"></object>";
}
/***/

/***/
if (file_exists($dotitemsfile)){
  $svgfile=$userdir."/tmp-items.svg";
  dotToSvg($userdir, $dotitemsfile, $svgfile, $errfile);
  print "<object data=\"$svgfile\" type=\"image/svg+xml\" align=\"middle\"></object>";
 }
/***/

/***/
if (file_exists($xmlfile)){
  print '<h3>xmlToDot</h3>';
  // Affichage de la forêt
  $parameters=array('idForest' => 'none');
  $dotfile=XSLDIR."/tmp.dot";
  $xslfile=XSLDIR."/xml2dot-Cgraph.xsl";
  xmlToOut($userdir, $xmlfile, $xslfile, $dotfile, $parameters);
  print '<h3>DotToSvg</h3>';
  $svgfile=$userdir."/tmp.svg";
  dotToSvg($userdir, $dotfile, $svgfile, $errfile);
  print "<object data=\"$svgfile\" type=\"image/svg+xml\" align=\"middle\"></object>";
 }
/***/

?>