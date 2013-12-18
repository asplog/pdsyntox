<?php

if (isset ($_POST['pwd']) && $_POST['pwd']!='' &&
    isset ($_POST['login']) && $_POST['login']!=''){
  $exists=false;
  $file = fopen('users/passwd', "r");
  while($file && !feof($file)){
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
    if ($login == $_POST['login']){
      $exists=true;
      break;
    }
  }
  fclose($file);
  if ($exists){
    echo '<body onLoad="alert(\''.trad('this login already exists',$ln).'\')">';
  } else {
    $login=$_POST['login'];
    $pwd=$_POST['pwd'];
    $firstName=$_POST['firstName'];
    $lastName=$_POST['lastName'];
    $email=$_POST['email'];
    CreateUserDirectory('users', 'users/'.$login);
    if (isset($_POST['grammar']))
      $grammar=$_POST['grammar']; 
    if (isset($_POST['lexicon']))
      $lexicon=$_POST['lexicon']; 
    if (isset($_POST['lexiconHost']) && ($_POST['lexiconHost']=='on'))
      $lexiconHost='1';
    else
      $lexiconHost='0'; 
    if (isset($_POST['postEdition']) && ($_POST['postEdition']=='on'))
      $postEdition='1';
    else
      $postEdition='0'; 
    $conf=$grammar.$lexicon.$lexiconHost.$postEdition;
    $passwd=crypt($pwd);
    $file = fopen('users/passwd', "a+");
    if ($file){
      fprintf($file, "%64s\n%64s\n%64s\n%64s\n%64s\n%64s\n\n", $login, $passwd, $firstName, $lastName, $email, $conf);
      fclose($file);
    }
    include_once ("login.php");
    login($_POST['login'], $_POST['pwd']);
  }
}

?>