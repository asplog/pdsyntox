<?php

if (isset ($_POST['forgot'])){
  if (isset($_POST['login']) && ($_POST['login'] != '')) {
    $subject=trad('subjectForgot');
    $body=str_replace('#login', $_POST['login'], trad('bodyForgot'));
    header("Location: mailto:lionel.clement@labri.fr?subject=$subject&body=$body");
    echo '<meta http-equiv="refresh" content="0;URL=index.php">';
  } else {
    echo '<body onLoad="alert(\''.trad('loginRequired').'\')">';
    echo '<meta http-equiv="refresh" content="0;URL=index.php">';
  }
 }
?>