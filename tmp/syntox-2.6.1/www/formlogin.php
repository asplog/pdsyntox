<?php
print '<DIV class="login" id="login">';
if (isset ($_SESSION['login'])){
  print '<FORM action="index.php" method="post" name="login"><INPUT type="hidden" name="task" value="logout"></INPUT><TABLE border="1"><TR><TD><TABLE border="0"><TR><TD align="center" colspan="2">'.ucfirst(trad('account',$ln)).'</TD></TR><TR><TD><H1>'.$_SESSION['firstName'].' '.$_SESSION['lastName'].'</H1></TD></TR><TR><TD><INPUT type="submit" value="'.ucfirst(trad('logout',$ln)).'"></TD></TR></TABLE></TD></TR></TABLE></FORM>';
 } else {
  print '
<FORM name="login" action="index.php" method="post"><INPUT type="hidden" name="task" value="login"><TABLE border="1"><TR><TD><TABLE border="0" bgcolor="lightgrey"><TR><TD align="center" colspan="2"><B>'.ucfirst(trad('login',$ln)).'</B></TD></TR><TR><TD>'.ucfirst(trad('username',$ln)).'</TD><TD><INPUT name="login" type="text"></TD></TR><TR><TD>'.ucfirst(trad('password',$ln)).'</TD><TD><INPUT name="pwd" type="password" value=""></TD></TR><TR><TD colspan="2"><INPUT type="submit" value="'.ucfirst(trad('login',$ln)).'"></TD></TR><TR><TD colspan="2"><BUTTON type="button" onclick="document.getElementById(\'createuser\').style.display=\'block\';">'.ucfirst(trad('create a new account',$ln)).'</BUTTON></TD></TR></TABLE></TD></TR></TABLE></FORM>';
 }
print '</DIV>';
?>
