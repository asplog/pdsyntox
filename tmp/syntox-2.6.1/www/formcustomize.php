<?php
$firstName='';
$lastName='';
$email='';
if (isset($_SESSION['firstName']))
  $firstName=$_SESSION['firstName'];
if (isset($_SESSION['lastName']))
  $lastName=$_SESSION['lastName'];
if (isset($_SESSION['email']))
  $email=$_SESSION['email'];

print '<DIV id="customize" class="popup"><DIV class="subpopup"><FORM name="customize" enctype="multipart/form-data" action="index.php" method="post" target="_top"><INPUT type="hidden" name="task" value="customize"><TABLE border="0"><TBODY ><TR><TD colspan="2"></TD><TD align="right"><BUTTON type="button" onclick="JavaScript:document.getElementById(\'customize\').style.display=\'none\';"><IMG src="images/stock_calc-cancel.png" alt="" width="12" height="12"></BUTTON></TD></TR><TR><TD colspan=2><INPUT class="strong" type="submit" value="'.trad('customize',$ln).'">&nbsp;<INPUT type="reset" value="'.trad('reset',$ln).'"></TD></TR><TR><TD colspan="2"><HR></TD></TR><TR><TD>'.trad('first name',$ln).'</TD><TD><INPUT name="firstName" type="text" maxlength="32" value="'.$firstName.'"></TD></TR><TR><TD>'.trad('last name',$ln).'</TD><TD><INPUT name="lastName" type="text" maxlength="32" value="'.$lastName.'"></TD></TR><TR><TD>'.trad('email',$ln).'</TD><TD><INPUT name="email" type="text" maxlength="32" value="'.$email.'"></TD></TR><TR><TD colspan="2"><HR></TD></TR></TABLE><TABLE border="0"><TBODY >';
formCustomize($grammar, $lexicon, $compactLexicon, $postEdition);
print '</TBODY></TABLE></FORM></DIV></DIV>';

?>
