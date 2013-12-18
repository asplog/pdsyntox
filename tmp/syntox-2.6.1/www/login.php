<?php

////////////////////////////////////////////////////////////
function login($login, $passwd)
{
  global $_POST, $ln, $conf, $grammar, $lexicon;
  
  if (isset ($_POST['erase'])){
    print __FILE__.'('.__LINE__.')';
    die('not yet implemented');
  } else {
    // on teste si nos variables sont définies
    if (isset($_POST['login']) && 
	isset($_POST['pwd']) &&
	($_POST['login'] != '') && 
	($_POST['pwd'] != '')) {
      $ok=false;
      $file = fopen('users/passwd', "r");
      while(!feof($file)){
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
	if ($rlogin == $_POST['login']){
	  if ($rpasswd == crypt($_POST['pwd'], $rpasswd)) {
	    $_SESSION['login'] = $rlogin;
	    $_SESSION['firstName'] = $rfirstName;
	    $_SESSION['lastName'] = $rlastName;
	    $_SESSION['email'] = $remail;
	    $_SESSION['conf'] = $rconf;
	    $_SESSION['directory']='users/'.$login;
	    $conf=$rconf;
	    $k=0;
	    $grammar=substr($conf, $k++, 1);
	    $lexicon=substr($conf, $k++, 1);
	    $lexiconHost=substr($conf, $k++, 1);
	    $postEdition=substr($conf, $k++, 1);
	    print '<meta http-equiv="refresh" content="0.5;URL=index.php?task=new">';
	    $ok=true;
	  }
	  break;
	}
      }
      fclose($file);
      if (!$ok){
	print '<body onLoad="alert(\''.ucfirst(trad('login failed',$ln)).'\')">';
      }
    } else {
      print '<body onLoad="alert(\''.ucfirst(trad('login and password required',$ln)).'\')">';
    }
  }
}

?>
