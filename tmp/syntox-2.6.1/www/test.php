<?php

////////////////////////////////////////////////////////////
function test(){
  global $ln, $tr;
  global $_COOKIE;
  $tab = array(
	       1 => array('Firefox/1', false, trad('you are using an old version of Firefox',$ln)),
	       2 => array('Firefox/2', false, trad('you are using an old version of Firefox',$ln)),
	       3 => array('Mozilla', true, ''),
	       4 => array('Firefox', true, ''),
	       5 => array('Safari', false, trad('safari is not a browser usable with GAT',$ln)),
	       6 => array('Opera', false, trad('opera is not a browser usable with GAT',$ln)),
	       7 => array('MSIE', false, trad('microsoft Internet Explorer is not a browser usable with GAT',$ln)));
  
  foreach ($tab as $key=>$value){
    if (strpos($_SERVER['HTTP_USER_AGENT'], $value[0])){
      if ($value[1] == false){
	echo "<center>";
	echo "<H2>".$value[2]."</h2>";
	echo "<H2>".trad('thanks to use a recent version of <a href="http://www.mozilla.com/">Firefox</a>',$ln).'</h2>';
	echo "</center>";
	die('');
      }
    }
  }
  return TRUE;
}

?>

