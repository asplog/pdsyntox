<?php
  //phpinfo();
  //die('chpasswd.php(3)');
if ((isset($_POST['passwd']) && ($_POST['passwd'] != ''))
    && (isset($_POST['passwd1']) && ($_POST['passwd1'] != ''))
    && (isset($_POST['passwd2']) && ($_POST['passwd2'] != ''))){
  $ok=false;
  $str='';
  if (($_POST['passwd1'] == $_POST['passwd2'])) {
    $file = fopen('users/passwd', "r+");
    while(!feof($file)){
      $seek=ftell($file);
      $rlogin=trim(fread($file, 64));
      fread($file, 1);
      $rpasswd=trim(fread($file, 64));
      fread($file, 1);
      $rfirstName=trim(fread($file, 64));
      fread($file, 1);
      $rlastName=trim(fread($file, 64));
      fread($file, 1);
      $remail=trim(fread($file, 64));
      fread($file, 1);
      $rconf=trim(fread($file, 64));
      fread($file, 1);
      fread($file, 1);
      if ($rlogin == $_SESSION['login']){
	if ($rpasswd == crypt($_POST['passwd'], $rpasswd)) {
	  $ok=true;
	  fseek($file, $seek);
	  $passwd=crypt($_POST['passwd1']);
	  fprintf($file, "%64s\n%64s\n%64s\n%64s\n%64s\n%64s\n\n", $rlogin, $passwd, $rfirstName, $rlastName, $remail, $rconf);
	  
	} else {
	  print '<body onLoad="alert(\''.ucfirst(trad('password failed',$ln)).'\')">';
	}
	break;
      }
    }
    fclose($file);
  } else {
    print '<body onLoad="alert(\''.ucfirst(trad('confirm password',$ln)).'\')">';
  }
  if (!$ok){
    print '<body onLoad="alert(\''.ucfirst(trad('password modification failed',$ln)).'\')">';
  }
 } else {
  print '<body onLoad="alert(\''.ucfirst(trad('old and new password required',$ln)).'\')">';
 }
?>
