<?php

$conf='1101';

define ('VERSION', '2.6.1');

// MAXIMUM number of nodes for a graph
define ('MAXSTATES', 1200);

// MAXIMUM number of transitions for a graph
define ('MAXTRANSITIONS', 1200);

// SYNTOX bin directory
define ('SYNTOXDIR', '/usr/local/bin');

// SYNTOX
define ('SYNTOX', 'syntox');

// dot bin directory
define ('DOTDIR', '/usr/local/bin');

// XSL files directory
define ('XSLDIR', $_SERVER['DOCUMENT_ROOT']."/syntox/xsl");

// Where the web server could create directories for temporaries
define ('USERDATADIR', 'userdata');

// Where the web server could write logs
define ('LOGDIR', 'log');

if (isset($_SESSION['login']) && isset($_SESSION['conf'])){
  $conf=$_SESSION['conf'];
}

$k=0;
$grammar=substr($conf, $k++, 1);
$lexicon=substr($conf, $k++, 1);
$compactLexicon=substr($conf, $k++, 1);
$postEdition=substr($conf, $k++, 1);

if (isset($_GET['ln'])){
  $ln=$_GET['ln'];
  $_SESSION['ln']=$ln;
 } 
 else if (isset($_SESSION['ln'])){
   $ln=$_SESSION['ln'];
 }
 else{
   $ln='9';
 }

?>
