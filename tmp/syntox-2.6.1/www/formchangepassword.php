<?php
print '<DIV id="chpasswd" class="popup"><DIV class="subpopup"><FORM name="changepassword" enctype="multipart/form-data" action="index.php" method="post" target="_top"><INPUT type="hidden" name="task" value="chpasswd"><TABLE border="0"><TBODY ><TR><TD colspan="2"></TD><TD align="right"><BUTTON type="button" onclick="JavaScript:document.getElementById(\'chpasswd\').style.display=\'none\';"><IMG src="images/stock_calc-cancel.png" alt="" width="12" height="12"></BUTTON></TD></TR><TR><TD colspan=2><INPUT class="strong" type="submit" value="'.trad('change password',$ln).'">&nbsp;<INPUT type="reset" value="'.trad('reset',$ln).'"></TD></TR><TR><TD colspan="2"><HR></TD></TR><TR><TD>'.trad('password',$ln).'*</TD><TD><INPUT name="passwd" type="password" maxlength="32"></TD></TR><TR><TD>'.trad('new password',$ln).'*</TD><TD><INPUT name="passwd1" type="password" maxlength="32"></TD></TR><TR><TD>'.trad('confirm new password',$ln).'*</TD><TD><INPUT name="passwd2" type="password" maxlength="32"></TD></TR></TBODY></TABLE></FORM></DIV></DIV>';
?>