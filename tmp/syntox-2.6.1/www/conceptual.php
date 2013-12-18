<?php

////////////////////////////////////////////////
//
////////////////////////////////////////////////
function is_assoc($var) {
    return is_array($var) && array_keys($var)!==range(0,sizeof($var)-1);
}

////////////////////////////////////////////////
//
////////////////////////////////////////////////
function dupliVar($v){
  if (is_assoc($v)){
    print '{';
    $first=true;
    foreach($v as $key => $val){
      if ($first) $first=false; else print ",\n";
      print '\'' . $key . '\':';
      dupliVar($val);
    }
    print '}';
  }
  else if (is_array($v)){
    print '[';
    $first=true;
    foreach($v as $val){
      if ($first) $first=false; else print ',';
      dupliVar($val);
    }
    print ']';
  }
  else if (is_int($v)){
    print $v;
  }
  else if (is_string($v)){
    print "'".str_replace("'", "\'", $v)."'";
  }
  else if (is_bool($v)){
    if ($v)
      print 'true';
    else
      print 'false';
  }
  else if ($v==NULL){
      print 'null';
  }
  else {
    print gettype($v);
    die('');
  }
}

    
////////////////////////////////////////////////
//
////////////////////////////////////////////////
//phpinfo();
//print_r($inputData);
//die(__FILE__.'('.__LINE__.')');
print "<SCRIPT type=\"text/javascript\">\n//<!--\n";
print "var fsRoot='';\n";
print "var fsFinal='';\n";
print "var defs = \n";
dupliVar($inputData);
print "//-->\n</SCRIPT>\n";
?>
