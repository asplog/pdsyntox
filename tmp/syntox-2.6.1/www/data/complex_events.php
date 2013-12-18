<?php

$predicatesWithoutTenseAspectNegative=array(array('-transaction-predicates-withoutTenseAspectNegative-', '-transaction-predicates-'),
					    array('-transportation-predicates-withoutTenseAspectNegative-', '-transportation-predicates-'));
$predicates=array(array('-transaction-predicates-', '-transaction-predicates-'),
		  array('-transportation-predicates-', '-transportation-predicates-'));

$in=array_merge($in, 
		array('-complex-events-'=> array('menus' => array('content' => array('values' => array('causation (simultaneous)', 'causation', 'succession (contiguous events)', 'succession', 'etc.'),
										     'name' => '',
										     'required' => true,
										     'checked' => 0,
										     'folding' => false)),
						 'fs' => '#content#'),
		      
		      
		      'causation (simultaneous)'=> array('menus' => array('cause' => array('values' => $predicatesWithoutTenseAspectNegative,
											   'name' => 'Cause',
											   'required' => true,
											   'checked' => 0,
											   'folding' => true),
									  'effect' => array('values' => $predicatesWithoutTenseAspectNegative,
											    'name' => 'Effect',
											    'required' => true,
											    'checked' => 0,
											    'folding' => true,
											    'newTD' => true)),
							 
							 'radios' => $_radiosTenseAspect,
							 'fs' => '[PRED:cause, #tense#, #aspect#, arg1:#cause#, arg2:#effect#]'),
		      
		      'causation'=> array('menus' => array('cause' => array('values' => $predicatesWithoutTenseAspectNegative,
									    'name' => 'Cause',
									    'required' => true,
									    'checked' => 0,
									    'folding' => true),
							   'effect' => array('values' => $predicatesWithoutTenseAspectNegative,
									     'name' => 'Effect',
									     'required' => true,
									     'checked' => 0,
									     'folding' => true,
									     'newTD' => true)),
					  
					  'radios' => array('tense' => array('name' => 'Tense',
									     'values' => array('present -> present' => 'tenseCause:present, tenseEffect:present',
											       'present -> future' => 'tenseCause:present, tenseEffect:future',
											       'past - past' => 'tenseCause:past, tenseEffect:past, aspectCause:accomplished',
											       'past - present' => 'tenseCause:past, tenseEffect:present, aspectCause:accomplished',
											       'past - future' => 'tenseCause:past, tenseEffect:future, aspectCause:accomplished',
											       'future - future' => 'tenseCause:future, tenseEffect:future, aspectCause:accomplished'),
									     'checked' => 0,
									     'onchange' => '\
if ((this.value==\'tenseCause:present, tenseEffect:present\')		\
    ||(this.value==\'tenseCause:past, tenseEffect:present\')){	\
    document.getElementById(\'#aspect#\').style.display=\'none\';	\
 } else {								\
     document.getElementById(\'#aspect#\').style.display=\'block\';	\
     if ((this.value==\'tenseCause:past, tenseEffect:past\')){		\
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[3].style.display=\'block\'; \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[0].style.display=\'none\'; \
	 if (document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked){	\
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked=false; \
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked=true; \
             document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].onchange(); \
	 }								\
     }									\
     else if ((this.value==\'tenseCause:present, tenseEffect:future\')	\
              ||(this.value==\'tenseCause:past, tenseEffect:future\')	\
              ||(this.value==\'tenseCause:future, tenseEffect:future\')){ \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[0].style.display=\'block\'; \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[3].style.display=\'none\'; \
	 if (document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked){	\
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked=false; \
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked=true; \
             document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].onchange(); \
	 }								\
	 document.getElementById(\'#aspect#\').onchange();		\
     }									\
 }									\
'),
							     
							    'aspect' => array('name' => 'Aspect effect',
									      'values' => array('near future' => 'aspectEffect:nearfuture',
												'accomplished' => 'aspectEffect:accomplished',
												'unaccomplished' => 'aspectEffect:unaccomplished',
												'accomplished in the past' => 'aspectEffect:pastaccomplished'),
									      'display' => 'none',
									      'checked' => 1,
									      'disabled' => array(false, false, false, false),
									      'newTD' => true),
							    
							    ),
					  
					  'fs' => '[PRED:cause, #tense#, #aspect#, arg1:#cause#, arg2:#effect#]'),
		      
		      
		      'succession (contiguous events)'=> array('menus' => array('first_event' => array('values' => $predicatesWithoutTenseAspectNegative,
												       'name' => 'First event',
												       'required' => true,
												       'checked' => 0,
												       'folding' => true),
										'second_event' => array('values' => $predicatesWithoutTenseAspectNegative,
													'name' => 'Second event',
													'required' => true,
													'checked' => 0,
													'folding' => true,
													'newTD' => true)),
							       
							       'radios' => $_radiosTenseAspect,
							       'fs' => '[PRED:succession, #tense#, #aspect#, arg1:#first_event#, arg2:#second_event#]'),
		      
		      'succession'=> array('menus' => array('first_event' => array('values' => $predicatesWithoutTenseAspectNegative,
										   'name' => 'First event',
										   'required' => true,
										   'checked' => 0,
										   'folding' => true),
							    'second_event' => array('values' => $predicatesWithoutTenseAspectNegative,
										    'name' => 'Second event',
										    'required' => true,
										    'checked' => 0,
										    'folding' => true,
										    'newTD' => true)),
					   
					   'radios' => array('tense' => array('name' => 'Tense',
									      'values' => array('present -> present' => 'tenseFirst_Event:present, tenseSecond_Event:present',
												'present -> future' => 'tenseFirst_Event:present, tenseSecond_Event:future',
												'past - past' => 'tenseFirst_Event:past, tenseSecond_Event:past, aspectFirst_Event:accomplished',
												'past - present' => 'tenseFirst_Event:past, tenseSecond_Event:present, aspectFirst_Event:accomplished',
												'past - future' => 'tenseFirst_Event:past, tenseSecond_Event:future, aspectFirst_Event:accomplished',
												'future - future' => 'tenseFirst_Event:future, tenseSecond_Event:future, aspectFirst_Event:accomplished'),
									      'checked' => 0,
									      'onchange' => '\
if ((this.value==\'tenseFirst_Event:present, tenseSecond_Event:present\') \
    ||(this.value==\'tenseFirst_Event:past, tenseSecond_Event:present\')){ \
    document.getElementById(\'#aspect#\').style.display=\'none\';	\
 } else {								\
     document.getElementById(\'#aspect#\').style.display=\'block\';	\
     if ((this.value==\'tenseFirst_Event:past, tenseSecond_Event:past\')){		\
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[3].style.display=\'block\'; \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[0].style.display=\'none\'; \
	 if (document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked){	\
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked=false; \
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked=true; \
             document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].onchange(); \
	 }								\
     }									\
     else if ((this.value==\'tenseFirst_Event:present, tenseSecond_Event:future\')	\
              ||(this.value==\'tenseFirst_Event:past, tenseSecond_Event:future\')	\
              ||(this.value==\'tenseFirst_Event:future, tenseSecond_Event:future\')){ \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[0].style.display=\'block\'; \
	 document.getElementById(\'#aspect#\').getElementsByTagName(\'DIV\')[3].style.display=\'none\'; \
	 if (document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked){	\
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[3].checked=false; \
	     document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].checked=true; \
             document.getElementById(\'#aspect#\').getElementsByTagName(\'input\')[0].onchange(); \
	 }								\
	 document.getElementById(\'#aspect#\').onchange();		\
     }									\
 }									\
'),
							     
							     'aspect' => array('name' => 'Aspect second_event',
									       'values' => array('near future' => 'aspectSecond_Event:nearfuture',
												 'accomplished' => 'aspectSecond_Event:accomplished',
												 'unaccomplished' => 'aspectSecond_Event:unaccomplished',
												 'accomplished in the past' => 'aspectSecond_Event:pastaccomplished'),
									       'display' => 'none',
									       'checked' => 1,
									       'disabled' => array(false, false, false, false),
									       'newTD' => true),
							     
							     ),
					   
					   'fs' => '[PRED:succession, #tense#, #aspect#, arg1:#first_event#, arg2:#second_event#]'),
		      
		      
		      ));
?>
