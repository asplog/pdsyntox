<?php

if (isset($_SESSION['fileName'])){
  $fileDirectory=$_SESSION['directory'];
  $fileBase=$_SESSION['fileName'];
  $file=$fileDirectory.'/'.$fileBase;
  //print "<script>\nalert('$file');\n</script>";
  if (is_file($file.'.input'))
    unlink($file.'.input');
  if (is_file($file.'.lexicon'))
    unlink($file.'.lexicon');
  if (is_file($file.'.grammar'))
    unlink($file.'.grammar');
  if (is_file($file.'.postEdition'))
    unlink($file.'.postEdition');
  unset($_SESSION['fileName']);
}

?>
