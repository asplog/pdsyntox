<?php

// on teste si nos variables sont définies
$formatConf="%1s%1s%1s%1s";

$file = fopen('users/passwd', 'r+');
while(!feof($file)){
  $seek=ftell($file);
  $login=trim(fread($file, 64));
  fread($file, 1);
  $pwd=trim(fread($file, 64));
  fread($file, 1);
  $firstName=trim(fread($file, 64));
  fread($file, 1);
  $lastName=trim(fread($file, 64));
  fread($file, 1);
  $email=trim(fread($file, 64));
  fread($file, 1);
  $conf=trim(fread($file, 64));
  fread($file, 1);
  fread($file, 1);
  if ($login == $_SESSION['login']){
    //phpinfo();
    //print "<script>\nalert('name:$firstName, conf: $conf');\n</script>";
    sscanf($conf, $formatConf, $grammar, $lexicon, $compactLexicon, $postEdition);
    if (isset($_POST['firstName']))
      $firstName=$_POST['firstName'];
    if (isset($_POST['lastName']))
      $lastName=$_POST['lastName'];
    if (isset($_POST['email']))
      $email=$_POST['email'];
    if (isset($_POST['grammar']))
      $grammar=$_POST['grammar']; 
    if (isset($_POST['lexicon']))
      $lexicon=$_POST['lexicon'];
    if (isset($_POST['compactLexicon']) && $_POST['compactLexicon']=='on')
      $compactLexicon='1';
    else  
      $compactLexicon='0';
    if (isset($_POST['postEditionOn']) && ($_POST['postEditionOn']=='on') && isset($_POST['postEdition']))
      $postEdition=$_POST['postEdition']; 
    else
      $postEdition='0'; 
    $conf = sprintf($formatConf, $grammar, $lexicon, $compactLexicon, $postEdition);
    //print "<script>\nalert('$conf');\n</script>";
    fseek($file, $seek);
    fprintf($file, "%64s\n%64s\n%64s\n%64s\n%64s\n%64s\n\n", $login, $pwd, $firstName, $lastName, $email, $conf);
    $_SESSION['firstName'] = $firstName;
    $_SESSION['lastName'] = $lastName;
    $_SESSION['email'] = $email;
    $_SESSION['conf'] = $conf;
    break;
  }
  fclose($file);
}

?>
