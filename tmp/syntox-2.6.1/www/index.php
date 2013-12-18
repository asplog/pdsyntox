<?php
if (!isset($_SESSION))
  session_start();
date_default_timezone_set('Europe/Paris');

include_once ('translation.php');
include_once ('configure.php');
if (isset($_COOKIE['syntoxVersion']) && ($_COOKIE['syntoxVersion']!=VERSION))
  {
    // 7 ans
    //$duree=3600*24*365*7;
    $duree=60;
    setcookie('syntoxVersion', VERSION, time()+$duree);
    echo '<body onLoad="alert(\''.ucfirst(trad('new version',$ln)).'\')">';
    echo '<meta http-equiv="refresh" content="6;URL=index.php">';
  }
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>	
<title>SYNTOX</title>

    <LINK REL="SHORTCUT ICON" HREF="">
    <META NAME="Author" LANG="fr" CONTENT="Lionel Clement">
    <META NAME="Description" CONTENT="Site">
    <META NAME="Keywords" LANG="fr" CONTENT=""> 
    <META NAME="robots" CONTENT="all">
    <META NAME="revisit" CONTENT="2 days"> 
    <link rel="stylesheet" type="text/css" href="styles/syntox.css">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    
    <script type="text/javascript">
      <!--//--><![CDATA[//><!--
    var images = new Array()
    function preload() {
	    for (i = 0; i < preload.arguments.length; i++) {
		images[i] = new Image()
		images[i].src = preload.arguments[i]
	    }
	}
//--><!]]>
    </script>
</head>

<body bgcolor="#a0aaaa"> 

<script type="text/javascript">
<!--//--><![CDATA[//><!--

function addText(input, repdeb, repfin) {
  input.focus();
  if(typeof input.selectionStart != 'undefined')
    {
      /* Insertion du code de formatage */
      var start = input.selectionStart;
      var end = input.selectionEnd;
      var insText = input.value.substring(start, end);
      input.value = input.value.substr(0, start) + repdeb + repfin + input.value.substr(end);
      /* Ajustement de la position du curseur */
      var pos;
      pos = start + repdeb.length;
      input.selectionStart = pos;
      input.selectionEnd = pos;
    }
}
var lineObjOffsetTop = 4; 
    
function createTextAreaWithLines(id) 
{ 
  var el = document.createElement('DIV'); 
  var ta = document.getElementById(id); 
  ta.parentNode.insertBefore(el,ta); 
  el.appendChild(ta); 
  
  el.className='textAreaWithLines'; 
  el.style.width = (ta.offsetWidth + 50) + 'px'; 
  ta.style.position = 'absolute'; 
  ta.style.left = '50px'; 
  el.style.height = (ta.offsetHeight + 1) + 'px'; 
  el.style.overflow='hidden'; 
  el.style.position = 'relative'; 
  el.style.width = (ta.offsetWidth + 50) + 'px'; 
  var lineObj = document.createElement('DIV'); 
  lineObj.style.position = 'absolute'; 
  lineObj.style.top = lineObjOffsetTop + 'px'; 
  lineObj.style.left = '0px'; 
  lineObj.style.width = '47px'; 
  el.insertBefore(lineObj,ta); 
  lineObj.style.textAlign = 'right'; 
  lineObj.className='lineObj'; 
  var string = ''; 
  for(var no=1;no<2000;no++){ 
    if(string.length>0)string = string + '<br>'; 
    string = string + no; 
  } 
  
  ta.onkeydown = function() { positionLineObj(lineObj,ta); }; 
  ta.onmousedown = function() { positionLineObj(lineObj,ta); }; 
  ta.onscroll = function() { positionLineObj(lineObj,ta); }; 
  ta.onblur = function() { positionLineObj(lineObj,ta); }; 
  ta.onfocus = function() { positionLineObj(lineObj,ta); }; 
  ta.onmouseover = function() { positionLineObj(lineObj,ta); }; 
  lineObj.innerHTML = string; 
  
} 
    
function positionLineObj(obj,ta) 
{ 
    obj.style.top = (ta.scrollTop * -1 + lineObjOffsetTop) + 'px';    
} 
//--><!]]>
</script>

<?php if (isset($_REQUEST) && isset($_REQUEST['task']) && ($_REQUEST['task']=='synthesize')): ?>
<div class="tl"><img alt="" src="images/tl-1.png"></div>
<div class="main">
  <table border="0" width="100%">
    <tbody>
      <tr>
	<td>
<?php elseif (isset($_REQUEST) && isset($_REQUEST['task']) && ($_REQUEST['task']=='nlg')): ?>
<div class="tl"><img alt="" src="images/tl-1.png"></div>
<div class="tl">
  <table border="0" width="100%">
    <tbody>
      <tr>
	<td>
<?php else:?>
  <div class="tl"><img alt="" src="images/tl-1.png"></div>
  <div class="tl"><img alt="" src="images/tl-2.png"></div>
  <div style="position:absolute; left:744px; top:0px; background:transparent url(images/horizontal-line.png); background-repeat:repeat-x; width:80%; height:164px;"></div>
  <div style="position:absolute; left:0px; top:1044px; background:transparent url(images/vertical-line.png); background-repeat:repeat-y; width:100%; height:100%;"></div>
  <div id="fixedlogo" class="logo" style="display:block;"><img alt="logo" width="132" src="images/logo.png" onClick="initLogo();bigLogo();"></div>
<?php endif; ?>
	  
<!-- Debut du cadre -->
<?php

  include_once ('functions.php');
  include_once ('forms.php');
  include_once ('samples.php');
  
  // Identifieur unique pour l'utilisateur
  $id_session = uniqid();
  
  if(!isset($_REQUEST) || !isset($_REQUEST['task'])){
    formProject(false);
  } else
    
    //phpinfo(INFO_VARIABLES);
    switch ($_REQUEST['task']){
      
    case 'sample':
      //phpinfo();
      //die('task:sample');
      if(isset($_REQUEST['sample'])){
	formProject($_REQUEST['sample']);
      }
      break;
      
    case 'createuser':
      //phpinfo();
      //die('task:createuser');
      include_once ("createuser.php");
      formProject(false);
      break;

    case 'customize':
      //phpinfo();
      //die('task:customize');
      include ('customize.php');
      formProject(false);
      break;
      
    case 'synthesize':
      //phpinfo(INFO_VARIABLES);
      //die('task:synthesize');
      include_once('synthesize.php');
      break;
      
    case 'new':
      //phpinfo();
      //die('task:new');
      unset($_SESSION['fileName']);
      formProject(false);
      break;
      
    case 'open':
      //phpinfo();
      //die('task:open');
      if (isset($_POST['newFileName']) && $_POST['newFileName']!='')
	$_SESSION['fileName'] = $_POST['newFileName'];
      formProject(false);
      break;

    case 'save':
      //phpinfo(INFO_VARIABLES);
      //die('task:save');
      include ('save.php');
      formProject(false);
      break;
      
    case 'remove':
      //phpinfo(INFO_VARIABLES);
      //die('task:remove');
      include ('remove.php');
      formProject(false);
      break;
      
    case 'language':
      //phpinfo();
      //die('task:language');
      $ln=$_POST['ln'];
      $_SESSION['ln']=$ln;
      formProject(false);
      break;
    
    case 'login':
      //phpinfo();
      //die('task:login');
      include_once('login.php');
      if (isset($_POST['login']) && isset($_POST['pwd']))
	login($_POST['login'], $_POST['pwd']);
      formProject(false);
      break;
      
    case 'chpasswd':
      //phpinfo();
      //die('task:chpasswd');
      include_once('chpasswd.php');
      formProject(false);
      break;
      
    case 'logout':
      //phpinfo();
      //die('task:logout');
      unset($_SESSION['login']);
      unset($_SESSION['fileName']);
      formProject(false);
      break;
      
    default:
      phpinfo();
      die('task:default');
      break;
    }
  

?>

<?php if (isset($_REQUEST) && (isset($_REQUEST['task'])) && (($_REQUEST['task']=='synthesize') || ($_REQUEST['task']=='nlg'))): ?>
</td>
</tr>
</tbody>
</table>
</div>
<?php else: ?>
<?php endif; ?>

<!-- Debut du menu -->

<?php

if (!isset($_REQUEST['task']) OR 
    (($_REQUEST['task']!='synthesize') && ($_REQUEST['task']!='nlg') && ($_REQUEST['task']!='formcreateuser'))){
  include_once('formlogin.php');
}

if (!isset($_REQUEST['task']) OR (($_REQUEST['task']!='synthesize') && ($_REQUEST['task']!='nlg'))){
  $projects='&nbsp;'.ucfirst(trad('projects',$ln,$ln)).'&nbsp;';
  if (isset ($_SESSION['login']))
    $myProject='<li><a href="?task=new">&nbsp;'.ucfirst(trad('my projects',$ln)).'&nbsp;</a></li>';
  else
    $myProject='<li class="disabled"><a href="?task=new">&nbsp;'.ucfirst(trad('my project',$ln)).'&nbsp;</a></li>';
  $file=ucfirst(trad('file',$ln));
  $options='&nbsp;'.ucfirst(trad('options',$ln)).'&nbsp;';
  if (isset ($_SESSION['login'])){
    $customize='<li><div onclick="JavaScript:document.getElementById(\'customize\').style.display=\'block\';">&nbsp;'.ucfirst(trad('customize',$ln)).'&nbsp;</div></li>';
  }else{
    $customize='<li class="disabled"><div>&nbsp;'.ucfirst(trad('customize',$ln)).'&nbsp;</div></li>';
  }

  if (isset ($_SESSION['login'])){
    $chpasswd='<li><div onclick="JavaScript:document.getElementById(\'chpasswd\').style.display=\'block\';">&nbsp;'.ucfirst(trad('change password',$ln)).'&nbsp;</div></li>';
  }else{
    $chpasswd='<li class="disabled"><div>&nbsp;'.ucfirst(trad('change password',$ln)).'&nbsp;</div></li>';
  }
  $languages='<li><div onclick="JavaScript:document.getElementById(\'language\').style.display=\'block\';">&nbsp;'.ucfirst(trad('language',$ln)).'&nbsp;</div></li>';
  $uploadALexicon=ucfirst(trad('uploadALexicon',$ln));
  $documentation='&nbsp;'.ucfirst(trad('documentation',$ln)).'&nbsp;';
  $onlineManual=ucfirst(trad('online manual',$ln));
  $manualWeb=ucfirst(trad('manualWeb',$ln));
  $manualFile=ucfirst(trad('manualFile',$ln));
  $manual=ucfirst(trad('manual',$ln));
  $mailingList=ucfirst(trad('mailing list',$ln));
  $mailingListURL=ucfirst(trad('mailingListURL',$ln));
  $contact=ucfirst(trad('contact',$ln));
  $mailTo='mailto:lionel.clement@labri.fr?subject=syntox-'.VERSION;
    
  ////////////////////////////////////////////////////////////
  function menu(&$samplesMenu, $menus, $level)
  {
    $samplesMenu .= "<ul class=\"level$level\">";
    while ($menus){
      $menu=array_shift($menus);
      $samplesMenu .= '<li';
      if (isset ($menu['available']) && (!$menu['available']))
	$samplesMenu .= ' class="disabled"';
      if (isset ($menu['submenu'])){
	$samplesMenu .= ' class="sousmenu">&nbsp;'.ucfirst(trad($menu['name'],$ln)).'&nbsp;';
	@menu($samplesMenu, $menu['submenu'], $level+1);
      } else {
	$samplesMenu .= '><a href="?task='.$menu['task'].'&amp;sample='.$menu['name'].'">&nbsp;'.ucfirst(trad($menu['name'],$ln)).'&nbsp;</a>';
      }
      $samplesMenu .= '</li>';
    }
    $samplesMenu .= "</ul>";
  }

  $samplesMenu = '<li class="sousmenu">&nbsp;'.ucfirst(trad('samples',$ln)).'&nbsp;';
  @menu($samplesMenu, $menus, 3);
  $samplesMenu .= '</li>';
  
  $samples='&nbsp;'.ucfirst(trad('samples',$ln)).'&nbsp;';
      
  print "
<div id=\"menu\">
  <ul class=\"level1\">

    <li class=\"sousmenu\">
      $projects
      <ul class=\"level2\">			      
        $myProject
        $samplesMenu
      </ul>			      
    </li>
    
    <li class=\"sousmenu\">
      $options
      <ul class=\"level2\">			      
	$customize
	$chpasswd
	$languages
      </ul>
    </li>
    <li class=\"sousmenu\">
      $documentation
      <ul class=\"level2\">			      
	
	<li ><div onclick=\"JavaScript:document.getElementById('about').style.display='block';\">&nbsp;".ucfirst(trad('about',$ln))."&nbsp;</div></li>
	<li class=\"disabled\">&nbsp;".ucfirst(trad('coming soon',$ln))."&nbsp;</li>
	<li ><a href=\"http://www.xlfg.org\">&nbsp;".ucfirst(trad('do you know XLFG ?',$ln))."&nbsp;</a></li>
	<li ><a href=\"mailto:lionel.clement@labri.fr?subject=syntox-".VERSION."\">&nbsp;".ucfirst(trad('contact us',$ln))."&nbsp;</a></li>
       <!--<li ><a href=\"2012-01-10_0943.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Intro',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1206.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (1/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1212.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (2/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1219.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (3/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1225.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (4/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1235.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (5/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1241.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (6/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-06_1249.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Rules (7/7)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-23_1138.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Inh./Synth. (1/3)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-23_1216.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Inh./Synth. (2/3)',$ln))."&nbsp;</a></li>-->
        <!--<li ><a href=\"2012-02-23_1236.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Inh./Synth. (3/3)',$ln))."&nbsp;</a></li>-->
	<!--<li ><a href=\"2012-02-23_1304.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Var. Scope',$ln))."&nbsp;</a></li>-->
	<!--<li ><a href=\"2012-02-24_1245.mp4\" target=\"help\">&nbsp;".ucfirst(trad('video Option. terms',$ln))."&nbsp;</a></li>-->
      </ul>
    </li>
  </ul>
</div>";
 }

include_once('formabout.php');
include_once('formlanguage.php');
include_once('formcustomize.php');
include_once('formcreateuser.php');
include_once('formchangepassword.php');

?>

<!-- Fin du menu -->

<!-- Début logo -->

<img id="logo" src="images/logo.png" alt="logo" border="0" style="position:absolute;visibility:hidden;">
<img id="little-bubbles" src="images/little-bubbles.png" alt="little-bubbles" border="0" style="position:absolute;visibility:hidden;">
<img id="bubbles" src="images/bubbles.png" alt="bubbles" border="0" style="position:absolute;visibility:hidden;">
<img id="big-bubbles" src="images/big-bubbles.png" alt="big-bubbles" border="0" style="position:absolute;visibility:hidden;">

<div id="copyright" class="copyrightBorder" style="display:block;">
  <font style="font-size:11px">S</font><font style="font-size:9px">YNTOX&nbsp;©&nbsp;2012-2013&nbsp;</font><font style="font-size:11px">L</font><font style="font-size:9px">IONEL&nbsp;</font><font style="font-size:11px">C</font><font style="font-size:9px">L&Eacute;MENT</font>
<!--
 <p>
    <a href="http://validator.w3.org/check?uri=referer"><img
      src="http://www.w3.org/Icons/valid-html401" alt="Valid HTML 4.01 Transitional" height="31" width="88"></a>
  </p>
-->
</div>

<script type="text/javascript" language="javascript1.2">
<!--//--><![CDATA[//><!--
var x0;
var y0;
var origScale;
var maxScale;
var scale;
var miliSec;
var logo;
var lbubbles;
var bbubbles;
var hbubbles;
var copyright;
var originalWidth;
var wdth;
var hght;
var x;
var y;
var lBubblesOffset;
var bBubblesOffset;
var hBubblesOffset;

function initLogo(){
x0 = (document.body.clientWidth/2);
y0 = (document.body.clientHeight/2);
origScale=0.25;
maxScale=1;
scale=origScale;
miliSec=0;
logo = document.getElementById('logo');
fixedlogo = document.getElementById('fixedlogo');
lbubbles = document.getElementById('little-bubbles');
bbubbles = document.getElementById('bubbles');
hbubbles = document.getElementById('big-bubbles');
originalWidth=366;
logo.style.width = lbubbles.style.width = bbubbles.style.width = hbubbles.style.width = Math.round(origScale*originalWidth);
wdth = parseFloat(logo.width);
hght = parseFloat(logo.height);
x=x0-(wdth/2);
y=y0-(hght/2);
logo.style.left=lbubbles.style.left=bbubbles.style.left=hbubbles.style.left=Math.round(x);
logo.style.top=lbubbles.style.top=bbubbles.style.top=hbubbles.style.top=Math.round(y);
lBubblesOffset=0.0;
bBubblesOffset=0.0;
hBubblesOffset=0.0;
}

function bubbles(s) {
  lBubblesOffset=lBubblesOffset+0.25*s;
  bBubblesOffset=bBubblesOffset+0.5*s;
  hBubblesOffset=hBubblesOffset+0.75*s;
  lbubbles.style.top=Math.round(y-lBubblesOffset);
  bbubbles.style.top=Math.round(y-bBubblesOffset);
  hbubbles.style.top=Math.round(y-hBubblesOffset);
}

function moveLogo() {
  var tim = setTimeout(moveLogo,41);
  miliSec=miliSec+41;
  scale=scale+0.1;
  lbubbles.style.width = bbubbles.style.width = hbubbles.style.width = logo.style.width = Math.round(scale*originalWidth);
  wdth = parseFloat(logo.width);
  hght = parseFloat(logo.height);
  x=x0-(wdth/2);
  y=y0-(hght/2);
  logo.style.left=lbubbles.style.left=bbubbles.style.left=hbubbles.style.left=x;
  logo.style.top=y;
  bubbles(2);
  if (scale > maxScale){
    clearTimeout(tim);
    moveBubbles();
  }
}

function moveBubbles() {
  var tim = setTimeout(moveBubbles,41);
  miliSec=miliSec+41;
  bubbles(1);
  if (miliSec > 3000 ){
    clearTimeout(tim);
    lbubbles.style.visibility=bbubbles.style.visibility=hbubbles.style.visibility=logo.style.visibility='hidden';
    fixedlogo.style.display='block';
  }
}

function bigLogo() {
  lbubbles.style.visibility=bbubbles.style.visibility=hbubbles.style.visibility=logo.style.visibility='visible';
  fixedlogo.style.display='none';
  scale=origScale;
  miliSec=0;
  lBubblesOffset=bBubblesOffset=hBubblesOffset=0.0;
  moveLogo();
}

function littleLogo() {
  logo.visibility=lbubbles.visibility=bbubbles.visibility=hbubbles.visibility='hidden';
  fixedlogo.style.display='block';
}
//--><!]]>
</script>

<?php
if (!isset($_SESSION['logo'])){
  print "<script type=\"text/javascript\">\npreload('images/logo.png','images/little-bubbles.png','images/bubbles.png','images/big-bubbles.png');\n\n</script>";
}
$_SESSION['logo']='yes';
?>

<!-- Fin logo -->
    
  </body>
</html>
