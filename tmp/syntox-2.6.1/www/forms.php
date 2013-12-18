<?php

function formCustomize($grammar, $lexicon, $compactLexicon, $postEdition){
  //die($grammar);
  global $tr, $ln;
  print '<TR>';
  print '<TD colspan="2"><H2>'.ucfirst(trad('customization',$ln)).'</H2></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TH colspan="2"><h3>'.trad('grammar',$ln).'</h3></TH>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="grammar" value="1"';
  if ($grammar==1)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('edit the grammar online',$ln)).'</FONT></TD>';
  print '</TR>';

  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="grammar" value="2"';
  if ($grammar==2)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('upload the grammar file',$ln)).'</FONT></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><HR></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TH colspan="2"><h3>'.ucfirst(trad('lexicon',$ln)).'</h3></TH>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="lexicon" value="1"';
  if ($lexicon==1)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('edit the lexicon online',$ln)).'</FONT></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="lexicon" value="2"';
  if ($lexicon==2)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('upload the lexicon file',$ln)).'</FONT></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2">';
  print '<INPUT name="compactLexicon" type="checkbox" name="compactLexicon" onClick="if (!this.checked) document.customize.compactLexicon.disabled=true; else document.customize.compactLexicon.disabled=false;"';
  if ($compactLexicon!='0')
    print ' checked';
  print '><FONT class="italic">'.ucfirst(trad('use a compiled lexicon',$ln)).'</FONT>';
  print '</TD>';
  print '</TR>';

  print '<TR>';
  print '<TD colspan="2"><HR></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TH colspan="2"><h3>'.ucfirst(trad('post-edition',$ln)).'</h3></TH>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><INPUT name="postEditionOn" type="checkbox" name="postEditionOn" onClick="
if (!this.checked) {
var lgth=document.customize.postEdition.length;
for(i=0;i<lgth;i++)
    document.customize.postEdition[i].checked=false;
} else document.customize.postEdition[0].checked=true;"';
  if ($postEdition!='0')
    print ' checked';
  print '><FONT class="italic">'.ucfirst(trad('post-edition',$ln)).'</FONT></TD>';
  print '</TR>';

  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="postEdition" value="1" onClick="document.customize.postEditionOn.checked=true;"';
  if ($postEdition==1)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('edit the post-edition online',$ln)).'</FONT></TD>';
  print '</TR>';

  print '<TR>';
  print '<TD colspan="2"><INPUT type="radio" name="postEdition" value="2" onClick="document.customize.postEditionOn.checked=true;"';
  if ($postEdition==2)
    print 'checked';
  print '><FONT class="italic">'.ucfirst(trad('upload the post-edition file',$ln)).'</FONT></TD>';
  print '</TR>';
  
  print '<TR>';
  print '<TD colspan="2"><HR></TD>';
  print '</TR>';
}

/////////////////
function formProject($sample){
  global $tr, $ln, $samples, $grammar, $lexicon, $compactLexicon, $postEdition;
  
  //print __FILE__.'('.__LINE__.')';
  //die($sample);

  print '<DIV class="main">';
  print '<FORM name="project" id="form" enctype="multipart/form-data" action="index.php" method="post">';
  print "<INPUT type=\"hidden\" name=\"ln\" value=\"$ln\">";

  $title='';
  $subtitle='';
  $grammarButtons='<DIV class="medium">'.ucfirst(trad('special characters',$ln)).'<!--<br><P>-->
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'→\', \'\');">→</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'↑\', \'\');">↑</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'↓\', \'\');">↓</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'⇑\', \'\');">⇑</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'⇓\', \'\');">⇓</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'⊂\', \'\');">⊂</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'∪\', \'\');">∪</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'≠\', \'\');">≠</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'¬\', \'\');">¬</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'∧\', \'\');">∧</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'∨\', \'\');">∨</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'⇒\', \'\');">⇒</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'⇔\', \'\');">⇔</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'≤\', \'\');">≤</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.grammarText, \'≥\', \'\');">≥</button>

</DIV>';
  $lexiconButtons='<DIV class="medium">'.ucfirst(trad('special characters',$ln)).'<!--<br><P>-->
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'∪\', \'\');">∪</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'≠\', \'\');">≠</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'¬\', \'\');">¬</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'∧\', \'\');">∧</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'∨\', \'\');">∨</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'⇒\', \'\');">⇒</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'⇔\', \'\');">⇔</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'≤\', \'\');">≤</button>
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.lexiconText, \'≥\', \'\');">≥</button>
</DIV>';
  $postEditionButtons='<DIV class="medium">'.ucfirst(trad('special characters',$ln)).'<!--<br><P>-->
<button type="button" style="background:white; cursor:default; border:solid 1px black;" onClick="javascript:addText(document.project.postEditionText, \'⇒\', \'\');">⇒</button>
</DIV>';

  if (isset($sample) && ($sample)){
    if (isset($samples[$sample]['task']))
      $task=$samples[$sample]['task'];
    else
      $task='synthesize';
    print "<INPUT id=\"task\" type=\"hidden\" name=\"task\" value=\"$task\">";
    if (isset($samples[$sample]['title'])){
      print '<h3>'.trad($samples[$sample]['title'],$ln).'</h3>';
    }
    
    if (isset($samples[$sample]['subtitle'])){
      print '<h4>'.trad($samples[$sample]['subtitle'],$ln).'</h4>';
    }
    if (isset($samples[$sample]['input']))
      $input=$samples[$sample]['input'];
    if (isset($samples[$sample]['inputRows']))
      $inputRows=$samples[$sample]['inputRows'];
    if (isset($samples[$sample]['inputCols']))
      $inputCols=$samples[$sample]['inputCols'];
    if (isset($samples[$sample]['inputData']))
      $inputData=$samples[$sample]['inputData'];
    if (isset($samples[$sample]['grammar']))
      $grammar=$samples[$sample]['grammar'];
    if (isset($samples[$sample]['grammarRows']))
      $grammarRows=$samples[$sample]['grammarRows'];
    if (isset($samples[$sample]['grammarCols']))
      $grammarCols=$samples[$sample]['grammarCols'];
    if (isset($samples[$sample]['grammarText']))
      $grammarText=$samples[$sample]['grammarText'];
    if (isset($samples[$sample]['lexicon']))
      $lexicon=$samples[$sample]['lexicon'];
    if (isset($samples[$sample]['lexiconRows']))
      $lexiconRows=$samples[$sample]['lexiconRows'];
    if (isset($samples[$sample]['lexiconCols']))
      $lexiconCols=$samples[$sample]['lexiconCols'];
    if (isset($samples[$sample]['lexiconText']))
      $lexiconText=$samples[$sample]['lexiconText'];
    if (isset($samples[$sample]['compactLexicon']))
      $compactLexicon=$samples[$sample]['compactLexicon'];
    if (isset($samples[$sample]['postEdition']))
      $postEdition=$samples[$sample]['postEdition'];
    if ($postEdition){
      $postEditionRows=$samples[$sample]['postEditionRows'];
      $postEditionCols=$samples[$sample]['postEditionCols'];
      $postEditionText=$samples[$sample]['postEditionText'];
    } 
  } else {
    $task='synthesize';
    print "<INPUT id=\"task\" type=\"hidden\" name=\"task\" value=\"$task\">";
    //$grammar dans configure.php;
    $grammarRows=32;
    $grammarCols=80;
    $grammarText='';
    //$lexicon dans configure.php;
    $lexiconRows=32;
    $lexiconCols=80;
    $lexiconText='';
    $input=1;
    $inputRows=12;
    $inputCols=80;
    $inputData='';
    //$postEdition dans configure.php;
    $postEditionRows=12;
    $postEditionCols=80;
    $postEditionText='';

    if (isset($_SESSION['login']) &&
	isset($_SESSION['directory']) &&
	isset($_SESSION['fileName'])){
    print '<h3>'.$_SESSION['fileName'].'</h3>';
      
    }
    if (isset($_SESSION['login']) &&
	isset($_SESSION['directory']) &&
	isset($_SESSION['fileName']) &&
	file_exists($_SESSION['directory'].'/'.$_SESSION['fileName'].'.grammar')){
      $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.grammar', 'r');
      while(!feof($file)){
	$line=fread($file, 8000);
	$grammarText .= $line;
      }
      fclose ($file);
    }
    if (isset($_SESSION['login']) &&
	isset($_SESSION['directory']) &&
	isset($_SESSION['fileName']) &&
	file_exists($_SESSION['directory'].'/'.$_SESSION['fileName'].'.lexicon')){
      $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.lexicon', 'r');
      while(!feof($file)){
	$line=fread($file, 8000);
	$lexiconText .= $line;
      }
      fclose ($file);
    }
    if (isset($_SESSION['login']) &&
	isset($_SESSION['directory']) &&
	isset($_SESSION['fileName']) &&
	file_exists($_SESSION['directory'].'/'.$_SESSION['fileName'].'.input')){
      $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.input', 'r');
      while(!feof($file)){
	$line=fread($file, 8000);
	$inputData .= $line;
      }
      fclose ($file);
    }
    if (isset($_SESSION['login']) &&
	isset($_SESSION['directory']) &&
	isset($_SESSION['fileName']) &&
	file_exists($_SESSION['directory'].'/'.$_SESSION['fileName'].'.postEdition')){
      $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.postEdition', 'r');
      while(!feof($file)){
	$line=fread($file, 8000);
	$postEditionText .= $line;
      }
      fclose ($file);
    }
    if (isset($_SESSION['login'])){
      print '<DIV class="project">';
      print '<DIV class="projectOpen" id="messageOpen">';
      print '<SELECT name="newFileName">';
      if (isset($_SESSION['login']) &&
	  isset($_SESSION['directory']) &&
	  file_exists($_SESSION['directory'])){
	$pattern='/.*\.grammar/';
	@$dir=opendir($_SESSION['directory']);
	while ($entry=readdir($dir)){
	  if($entry==".." || $entry == ".")
	    continue;
	  if (preg_match($pattern, $entry)){
	    $e=substr($entry, 0, -8);
	    print "<OPTION VALUE=\"$e\">$e</OPTION>";
	  }
	}
      }
      print '</SELECT>';
      print '<INPUT type="submit" name="open" value="'.ucfirst(trad('done',$ln)).'" onclick="javascript: document.getElementById(\'task\').value=\'open\'; document.getElementById(\'messageOpen\').style.display=\'none\'; document.getElementById(\'form\').target=\'_self\'; ">';
      print '</DIV>';
      

      
      print '<FIELDSET><LEGEND><FONT class="medium">'.ucfirst(trad('project',$ln)).'</FONT></LEGEND>';
      print '<INPUT type="submit" name="New" value="'.ucfirst(trad('new',$ln)).'" onclick="javascript:document.getElementById(\'task\').value=\'new\'; document.getElementById(\'form\').target=\'_self\'; ">&nbsp;';
      print '<BUTTON type="button" onclick="JavaScript: document.getElementById(\'messageOpen\').style.display=\'block\'; this.disabled=\'yes\'">'.trad('open',$ln).'</button>&nbsp;';
      print '<INPUT id="fileInput" type="hidden" name="fileName" value="">';

      if (isset($_SESSION['fileName'])){
	print '<INPUT type="submit" name="save" value="'.ucfirst(trad('save',$ln)).'" onclick="javascript:document.getElementById(\'task\').value=\'save\';   document.getElementById(\'form\').target=\'_self\'; document.getElementById(\'fileInput\').value=\''.$_SESSION['fileName'].'\'; ">&nbsp;';
      } else {
	print '<INPUT type="submit" name="save" value="'.ucfirst(trad('save',$ln)).'" onclick="javascript:p=prompt(\'File\', \'\'); document.getElementById(\'fileInput\').value=p; document.getElementById(\'task\').value=\'save\'; document.getElementById(\'form\').target=\'_self\'; ">&nbsp;';
      }
      // BUTTON ???
      print '<INPUT id="buttonSaveAs" type="submit" name="save" value="'.ucfirst(trad('save as',$ln)).'" onclick="javascript:p=prompt(\''.ucfirst(trad('project name',$ln)).'\', \'\'); document.getElementById(\'fileInput\').value=p; document.getElementById(\'task\').value=\'save\'; document.getElementById(\'form\').target=\'_self\'; ">';
      if (isset($_SESSION['fileName'])){
	print '&nbsp;';
	print '<BUTTON type="button" id="buttonRemove" onclick="JavaScript: document.getElementById(\'messageRemove\').style.display=\'block\'; this.disabled=\'yes\'">'.trad('remove',$ln).'</BUTTON>&nbsp;';
      }
      print '</FIELDSET>';
      print '</DIV>';
      if (isset($_SESSION['fileName'])){
	print '<DIV id="messageRemove" class="popup"><DIV class="subpopup"><TABLE border="0"><TR><TD><TABLE border="0"><TR align="left"><TD><SPAN style="font-size:16px; color:#080808;">'.ucfirst(trad('remove the project', $ln)).'&nbsp;'.$_SESSION['fileName'].'&nbsp;?</SPAN></TD></TR><TR><TD align="right"><BUTTON type="button" onclick="JavaScript:document.getElementById(\'buttonRemove\').removeAttribute(\'disabled\'); document.getElementById(\'messageRemove\').style.display=\'none\';">'.ucfirst(trad('no', $ln)).'</BUTTON></TD><TD align="right"><INPUT type="submit" name="remove" value="'.ucfirst(trad('yes',$ln)).'" onclick="JavaScript: document.getElementById(\'task\').value=\'remove\'; document.getElementById(\'messageRemove\').style.display=\'none\';"></TD></TR></TABLE></TD></TR></TABLE></DIV></DIV>';      
      }
    }
  }
  
  print '<TABLE bgcolor="lightgray" border="0"><tbody>';
  
  if ($input<=3){
    /*** Buttons ***/
    print '<TR><TD align="left" colspan="2">';
    print '<INPUT class="strong" type="submit" value="'.ucfirst(trad($task,$ln)).'" onclick="javascript: document.getElementById(\'form\').target=\'CS\'; ">&nbsp;<INPUT type="reset" value="'.ucfirst(trad('reset',$ln)).'">&nbsp;';
    print '</TD></TR>';
    /*******/
    

    /*******/
    /*** Output window ***/
    print '<TR><TD align="left" colspan="2">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('output',$ln)).'</FONT></LEGEND>';   
    print '<TABLE>';
    print '<TR>';
    print '<TD><DIV class="medium">&nbsp;'.ucfirst(trad('maxLength',$ln)).'<INPUT type="radio" name="maxLength" value="no" checked onClick="document.getElementById(\'maxLength\').style.display=\'none\'; document.getElementById(\'maxLength\').value=\'0\';"><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="maxLength" value="yes" onClick="document.getElementById(\'maxLength\').style.display=\'block\'; document.getElementById(\'maxLength\').value=\'10\';"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT><INPUT id="maxLength" type="text" name="maxLength" value="0" style="display: none;"></DIV></TD>';
    print '</TR>';
    print '<TR>';
    print '<TD><DIV class="medium">&nbsp;'.ucfirst(trad('maxUsages',$ln)).'<INPUT type="radio" name="maxUsages" value="no" checked onClick="document.getElementById(\'maxUsages\').style.display=\'none\'; document.getElementById(\'maxUsages\').value=\'0\';"><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="maxUsages" value="yes" onClick="document.getElementById(\'maxUsages\').style.display=\'block\'; document.getElementById(\'maxUsages\').value=\'10\';"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT><INPUT id="maxUsages" type="text" name="maxUsages" value="0" style="display: none;"></DIV></TD>';
    print '</TR>';
    print '<TR>';
    print '<TD><DIV class="medium">&nbsp;'.ucfirst(trad('reduce all rules',$ln)).'<INPUT type="radio" name="reduceAll" value="no" checked><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="reduceAll" value="yes"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
    print '</TR>';
    print '<INPUT type="hidden" name="trace" value="yes" checked>';
    /***/
    print '<TR>';
    print '<TD><DIV class="admin">&nbsp;'.ucfirst(trad('verbose mode',$ln)).'<INPUT type="radio" name="verbose" value="no" checked><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="verbose" value="yes"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
    print '</TR>';
    print '<TR>';
    print '<TD><DIV class="admin">&nbsp;'.ucfirst(trad('give an XML output',$ln)).'<INPUT type="radio" name="xml" value="no" checked ><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="xml" value="yes" ><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
    print '</TR>';
    print '<TR>';
    print '<TD><DIV class="admin">&nbsp;'.ucfirst(trad('draw the items',$ln)).'<INPUT type="radio" name="dotitems" value="no" checked><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="dotitems" value="yes"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
    print '</TR>';
    print '<TR>';
    print '<TD><DIV class="admin">&nbsp;'.ucfirst(trad('draw the shared forest',$ln)).'<INPUT type="radio" name="dotforest" value="no" checked><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="dotforest" value="yes"><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
    print '</TR>';
    /***/
    print '</TABLE>';
    print '</FIELDSET></TD>';
    print '</TR>';
    /*******/
  }
  
  /*** Input window ***/
  /*** Regular input ***/
  if ($input==1){
    print '<TR><TD align="left" colspan="2">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('input',$ln)).'</FONT></LEGEND>';   
    print "<TEXTAREA name=\"inputData\" rows=\"$inputRows\" cols=\"$inputCols\">$inputData</TEXTAREA>";
    print '</FIELDSET>';
    print '</TD></TR>';
  }
  /*** Menu input ***/
  else if ($input==2){
    print '<TR><TD align="left" colspan="2">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('input',$ln)).'</FONT></LEGEND>';   
    print '<DIV><SELECT onchange="document.project.inputData.value=this.value;" >';
    foreach ($inputData as $select){
      print "<OPTION VALUE=\"".$select[1]."\">".$select[0]."</OPTION>";
    }
    print '</SELECT></DIV>';
    print "<DIV><TEXTAREA name=\"inputData\" rows=\"$inputRows\" cols=\"$inputCols\">".$inputData[0][1].'</TEXTAREA></DIV>';
    print '</FIELDSET>';
    print '</TD></TR>';
  }
  /*******/
  //opt.setAttribute(\'value\', defs[i]);
  
  /*** input conceptual ***/
  else if ($input>=3){
    /***
	print '<TR>';
	print '<TD><DIV class="admin">&nbsp;'.ucfirst(trad('verbose mode',$ln)).'<INPUT type="radio" name="verbose" value="no"><FONT class="italic">'.ucfirst(trad('no',$ln)).'</FONT><INPUT type="radio" name="verbose" value="yes" checked><FONT class="italic">'.ucfirst(trad('yes',$ln)).'</FONT></DIV></TD>';
	print '</TR>';
    ***/
    include_once ('configure.php');
    include_once ('conceptual.php');
    print '<SCRIPT type="text/javascript" src="conceptualMenus.js"></SCRIPT>';
    print '<TR><TD align="left">';
    print '<DIV id="div_0" style="background-color:silver">';
    switch ($input){
    case 3: 
      print '<SCRIPT type="text/javascript">';
      print "//<!--\n";
      print "addBlock('', '0', 'letter', '', 0, false);";
      print "//-->\n";
      print '</SCRIPT>';
      break;
    case 4: 
      print '<SCRIPT type="text/javascript">';
      print "//<!--\n";
      print "addBlock('', '0', 'email', '', 0, false);";
      print "//-->\n";
      print '</SCRIPT>';
      break;
    case 5: 
      print '<SCRIPT type="text/javascript">';
      print "//<!--\n";
      print "addBlock('', '0', '-root-', '', 0, false);";
      print "//-->\n";
      print '</SCRIPT>';
      break;
    case 6: 
      $attributes = array("Name", "Surname", "Gender", "Transaction", "Object", "Quant", "Date", "Today");
      $relation = array(array("Jean", "Larochelle", "M", "to-rent", "car", "1", "2013-03-01", "2013-04-18"),
			array("Marie", "Dubois", "F", "to-buy", "trout", "600", "2013-06-01", "2013-04-18"),
			array("Pierre", "Lafeuille", "M", "to-sold", "salmon-steak", "3", "2013-01-01", "2013-04-18"),
			array("Jeanne", "Mabille", "F", "to-buy", "whole-salmon", "43", "2013-04-18", "2013-04-18"),
			array("Berthe", "Tournille", "F", "to-order", "trout", "45", "2013-06-01", "2013-04-18"),
			array("Hervé", "Labouille", "M", "to-book", "room", "1", "2013-04-01", "2013-04-18"),
			);

      print '<INPUT name="attributes" type="hidden" value="';
      htmlspecialchars(var_export($attributes));
      print '">';
      print '<INPUT name="relation" type="hidden" value="';
      htmlspecialchars(var_export($relation));
      print '">';
      print '<SCRIPT type="text/javascript">';
      print "//<!--\n";
      print "addBlock('', '0', '-transaction-', '', 0, false);";
      print "//-->\n";
      print '</SCRIPT>';
      break;

    case 7: 
      $attributes = array("Name", "Surname", "Gender", "Q1", "Q2");
      $relation = array(array("Jean", "Larochelle", "M", "56", "123"),
			array("Marie", "Dubois", "F", "87", "34"),
			array("Pierre", "Lafeuille", "M", "45", "98"),
			array("Jeanne", "Mabille", "F", "56", "98"),
			array("Berthe", "Tournille", "F", "129", "2"),
			array("Hervé", "Labouille", "M", "67", "43"),
			);

      print '<INPUT name="attributes" type="hidden" value="';
      htmlspecialchars(var_export($attributes));
      print '">';
      print '<INPUT name="relation" type="hidden" value="';
      htmlspecialchars(var_export($relation));
      print '">';
      print '<SCRIPT type="text/javascript">';
      print "//<!--\n";
      print "addBlock('', '0', '-win-lose-', '', 0, false);";
      print "//-->\n";
      print '</SCRIPT>';
      break;
    }
    print '</DIV>';
    print '</TD></TR>';
    
    /*** Buttons ***/
    print '<TR><TD align="left" colspan="2">';
    print '<INPUT class="strong" type="submit" value="'.ucfirst(trad($task,$ln)).'" onclick="javascript:
document.getElementById(\'form\').target=\'CS\'; ">';
    print '</TD></TR>';
    /*******/
    
    //print '<TEXTAREA name="listRules" rows="20" cols="80" id="listRules"></TEXTAREA>';
    
    if (isset($attributes) && (sizeof($attributes)>0)){
      print '<TABLE border="1">';
      print '<THEAD>';
      for ($i=0 ; $i < sizeof($attributes) ; $i++){
	print '<TH>&nbsp;' . $attributes[$i] . '&nbsp;</TH>';
      }
      print '</THEAD>';
      print '<TBODY>';
      for ($i=0 ; $i < sizeof($relation) ; $i++){
	print '<TR>';
	for ($j=0 ; $j < sizeof($relation[$i]) ; $j++){
	  print '<TD>&nbsp;' . $relation[$i][$j] . '&nbsp;</TD>';
	}
	print '</TR>';
      }
      print '</TBODY>';
      print '</TABLE>';
    }
  }
  /*******/
  
  /*** Grammar ***/
  if ($grammar==1){
    print '<TR>';
    print '<TD valign="top" align="left">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('grammar',$ln)).'</FONT></LEGEND>';
    if (isset($grammarText)){
      print $grammarButtons;
      print "<TEXTAREA id=\"grammarText\" name=\"grammarText\" onKeyPress=\"isKeyPressed(event, this);\" rows=\"$grammarRows\" cols=\"$grammarCols\">";
      print $grammarText;
      print '</TEXTAREA>';
      print '<SCRIPT type="text/javascript">
//<!--
createTextAreaWithLines(\'grammarText\');
//-->
</SCRIPT>'; 
    }
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($grammar==2){
    print '<TR>';
    print '<TD valign="top" align="left">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('upload the grammar file',$ln)).'</FONT></LEGEND>';
    print '<INPUT type="hidden" name="MAX_FILE_SIZE" value="10000000">';
    print '<INPUT type="file" name="grammarFile">';
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($grammar==3){
    print '<INPUT type="hidden" name="grammarText" value="'.$grammarText.'">';
  }
  /*******/
  
  /*** Lexicon ***/
  if ($lexicon==1){
    print '<TR>';
    print '<TD valign="top" align="left">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('lexicon',$ln)).'</FONT>&nbsp;</LEGEND>';
    print $lexiconButtons;
    print "<TEXTAREA id=\"lexiconText\" name=\"lexiconText\"  OnKeyPress=\"javascript:
	if (event.keyCode=='9' & event.altKey) addText(document.getElementById('lexiconText'), '	', '');
	\" rows=\"$lexiconRows\" cols=\"$lexiconCols\">";
    print $lexiconText;
    print '</TEXTAREA>';
    print "<SCRIPT type=\"text/javascript\">\n// <!--\ncreateTextAreaWithLines('lexiconText');\n// -->\n</SCRIPT>"; 
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($lexicon==2){
    print '<TR>';
    print '<TD valign="top" align="left">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('upload the lexicon file',$ln)).'</FONT>&nbsp;</LEGEND>';
    print '<INPUT type="hidden" name="MAX_FILE_SIZE" value="10000000">';
    print '<INPUT type="file" name="lexiconFile">';
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($lexicon==3){
    print '<INPUT type="hidden" name="lexiconText" value="'.$lexiconText.'">';
  }
  /*******/
  
  if ($compactLexicon==1){
    print '<TR>';
    print '<TD valign="top" align="left">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('use the compiled lexicon',$ln)).'</FONT>&nbsp;</LEGEND>';
    print '<SELECT name="compactLexicon">';
    print "<OPTION VALUE=\"\">&nbsp;</OPTION>";
    $pattern='/.*\.fsa/';
    @$dir=opendir('data');
    while ($entry=readdir($dir)){
      if($entry==".." || $entry == ".")
	continue;
      if (preg_match($pattern, $entry)){
	$e=substr($entry, 0, -4);
	print "<OPTION VALUE=\"$e\">$e</OPTION>";
      }
    }
    print '</SELECT>';
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  /*** Post-edition***/
  if ($postEdition==1){
    print '<TR><TD align="left" colspan="2">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('post-edition',$ln)).'</FONT>&nbsp;&nbsp;</LEGEND>';   
    print $postEditionButtons;
    print "<TEXTAREA id=\"postEditionText\" name=\"postEditionText\" OnKeyPress=\"javascript:if (event.keyCode=='9' & event.altKey) addText(document.getElementById('postEditionText'), '	', '');\" rows=\"$postEditionRows\" cols=\"$postEditionCols\">$postEditionText</TEXTAREA>";
    print '</FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($postEdition==2){
    print '<TR><TD align="left" colspan="2">';
    print '<FIELDSET><LEGEND><FONT class="large">'.ucfirst(trad('upload the post-edition file',$ln)).'</FONT>&nbsp;</LEGEND><INPUT type="hidden" name="MAX_FILE_SIZE" value="10000000"><INPUT type="file" name="postEditionFile"></FIELDSET>';
    print '</TD>';
    print '</TR>';
  }
  else if ($postEdition==3){
    print '<INPUT type="hidden" name="postEditionText" value="'.$postEditionText.'">';
  }
  /*******/
  
  print '</TABLE>';
  print '</FORM>';
  print '</DIV>';
  
}

?>
