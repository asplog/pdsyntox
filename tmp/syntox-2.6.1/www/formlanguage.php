<?php
print '<DIV id="language" class="popup"><DIV class="subpopup"><FORM name="language" enctype="multipart/form-data" action="index.php" method="post" target="_top"><INPUT type="hidden" name="task" value="language"><TABLE border="0"><TBODY><TR><TD colspan="2"></TD><TD align="right"><BUTTON type="button" onclick="JavaScript:document.getElementById(\'language\').style.display=\'none\';"><IMG src="images/stock_calc-cancel.png" alt="" width="12" height="12"></BUTTON></TD></TR><TR><TD><INPUT type="radio" name="ln" value="0"';
if ($ln==0)
  print ' checked';
print'>Fran&ccedil;ais<BR >';
/***
print '<INPUT type="radio" name="ln" value="1"';
if ($ln==1)
  print ' checked';
print'>Espa&ntilde;ol<BR >';
print '<INPUT type="radio" name="ln" value="2" disabled="true"';
if ($ln==2)
  print ' checked';
print'>Italiano<BR >';
print '<INPUT type="radio" name="ln" value="3" disabled="true"';
if ($ln==3)
  print ' checked';
print'>Deutsch<BR >';
***/
print '<INPUT  type="radio" name="ln" value="9"';
if ($ln==9)
  print ' checked';
print '>English<BR >';
print '</TD></TR><TR><TD colspan=2><INPUT class="strong" type="submit" value="'.trad('done',$ln).'">&nbsp;<INPUT type="reset" value="'.trad('reset',$ln).'"></TD></TR></TBODY></TABLE></FORM></DIV></DIV>';
?>
