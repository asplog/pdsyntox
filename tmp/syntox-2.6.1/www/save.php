<?php

if (isset($_POST['fileName']) && $_POST['fileName']!='')
  $_SESSION['fileName'] = $_POST['fileName'];
if (isset($_SESSION['fileName'])){
  $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.input', 'w');
  if ($file){
    fwrite($file, str_replace("\r", "", stripslashes($_POST['inputData'])));
    fclose($file);
  }
  else
    die (__FILE__+'('+__LINE__+')');
  $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.grammar', 'w');
  if ($file){
    fwrite($file, str_replace("\r", "", stripslashes($_POST['grammarText'])));
    fclose($file);
  }
  else
    die (__FILE__+'('+__LINE__+')');
  $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.lexicon', 'w');
  if ($file){
    fwrite($file, str_replace("\r", "", stripslashes($_POST['lexiconText'])));
    fclose($file);
  }
  else
    die (__FILE__+'('+__LINE__+')');
  $file=fopen($_SESSION['directory'].'/'.$_SESSION['fileName'].'.postEdition', 'w');
  if ($file){
    fwrite($file, str_replace("\r", "", stripslashes($_POST['postEditionText'])));
    fclose($file);
  }
  else
    die (__FILE__+'('+__LINE__+')');
}

?>
