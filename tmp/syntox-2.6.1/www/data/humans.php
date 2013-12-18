<?php
$in=array_merge($in, 
		array('me' => array('fs' => '[PRED:pro, person:1, number:sg]'),
		      'me (represent of a compagny)' => array('fs' => '[PRED:pro, person:1, number:pl]'),
		      'you' => array('fs' => '[PRED:pro, person:2, number:sg]'),
		      'you (in polite society)' => array('fs' => '[PRED:pro, person:2, number:pl]'),
		      'him' => array('fs' => '[PRED:pro, person:3, number:sg, gender:ms]'),
		      'her' => array('fs' => '[PRED:pro, person:3, number:sg, gender:fm]'),
		      'we' => array('fs' => '[PRED:pro, person:1, number:pl]'),
		      'you (several persons)' => array('fs' => '[PRED:pro, person:2, number:pl]'),
		      'them (masculine)' => array('fs' => '[PRED:pro, person:3, number:pl, gender:ms]'),
		      'them (feminine)' => array('fs' => '[PRED:pro, person:3, number:pl, gender:fm]'),
		      'someone' => array('fs' => '[PRED:literal_person, name:[FORM:"#name#"], surname:[FORM:"#surname#"], #gender#, #civ#, number:sg, person:3]',
					 'texts' => array('surname' => array('name' => 'Family name'),
							  'name' => array('name' => 'Name', 'newTD' => true)),
					 'radios' => array('gender' => array('values' => array('M' => 'gender:ms', 
											       'F' => 'gender:fm'), 
									     'name' => 'gender',
									     'checked' => 0),
							   'civ' => array('name' => 'personality',
									  'values' => array('familiar person' => 'civ:familiar',
											    'important person' => 'civ:important'),
									     'checked' => 0))), 
		      
		      
		      'listed person' => array('fs' => '[FORM:"#civ# #name# #surname#", #gender#, number:sg, person:3]',
					       'evals' => array('surname' => '$Surname',
								'name' => '$Name',
								'gender' => '($Gender == "M") ? "gender:ms" : "gender:fm"',
								'civ' => '($Gender == "M") ? "M." : "Mme."')),
		      
		      
		      )
		);
?>
