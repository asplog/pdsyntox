<?php
$in=array_merge($in, 
		array('-transportation-items-'=> array('menus' => array('content' => array('values' => array('car', 'taxi', 'motorcycle', 'street', 'truck', 'train', 'airplane', 'helicopter', 'airport', 'port', 'subway station', 'subway', 'bus stop', 'bus', 'bicycle'),
											   'name' => '',
											   'required' => true,
											   'checked' => 0,
											   'folding' => false)),
						       
						       'radios' => $_radiosDeterminerNumber,
						       'buttons' => $_buttonsModifier,
						       'fs' => "[#content#, $_fsDeterminerNumberModifier]"),
		      
		      

		      '-transportation-predicates-'=> array('menus' => array('content' => array('values' => array('arrive', 'depart', 'disembark', 'drive', 'take-of', 'land', 'sail', 'tow', 'fly', 'ride'),
												'name' => '',
												'required' => true,
												'checked' => 0,
												'folding' => false)),
							    'radios' => $_radiosTenseAspect,
							    'checkboxes' => $_checkboxesNegative,
							    'fs' => "[#content#, diathesis:active, $_fsTenseAspectNegative]"),
		      
		      
		      '-transportation-predicates-withoutTenseAspectNegative-'=> array('menus' => array('content' => array('values' => array('arrive', 'depart', 'disembark', 'drive', 'take-of', 'land', 'sail', 'tow', 'fly', 'ride'),
															  'name' => '',
															  'required' => true,
															  'checked' => 0,
															  'folding' => false)),
										      'fs' => "[#content#, diathesis:active]"),
		      
		      
		      'car' => array('fs' => "PRED:car"),
		      'taxi' => array('fs' => "PRED:taxi"),
		      'motorcycle' => array('fs' => "PRED:motorcycle"),
		      'street' => array('fs' => "PRED:street"),
		      'truck' => array('fs' => "PRED:truck"),
		      'train' => array('fs' => "PRED:train"),
		      'airplane' => array('fs' => "PRED:airplane"),
		      'helicopter' => array('fs' => "PRED:helicopter"),
		      'airport' => array('fs' => "PRED:airport"),
		      'port' => array('fs' => "PRED:port"),
		      'subway station' => array('fs' => "PRED:subway_station"),
		      'subway' => array('fs' => "PRED:subway"),
		      'bus stop' => array('fs' => "PRED:bus_stop"),
		      'bus' => array('fs' => "PRED:bus"),
		      'bicycle' => array('fs' => "PRED:bicycle"),
		      'bike' => array('fs' => "PRED:bicycle"),
		      
		      'arrive' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									  ),
							 'location' => array('values' => array(''),
									     'name' => 'to',
									     'required' => false,
									     'checked' => 0,
									     'folding' => true,
									     'newTD' => true)),
					'fs' => "PRED:to-arrive, subj:#agent#, location:#location#"),
		      
		      'depart' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									  ),
							 'location' => array('values' => array(''),
									     'name' => 'from',
									     'required' => false,
									     'checked' => 0,
									     'folding' => true,
									     'newTD' => true)),
					'fs' => "PRED:to-depart, subj:#agent#, location:#location#"),
		      
		      'disembark' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									  ),
							    'object' => array('values' => $items,
									      'name' => 'what is unload from ship, aircraft…',
									      'required' => false,
									      'checked' => 0,
									      'folding' => true,
									     'newTD' => true)),
					'fs' => "PRED:to-disembark, subj:#agent#, obj:#object#"),
		      
		      'drive' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									 )),
				       'fs' => "PRED:to-drive, subj:#agent#"),
		      
		      'take-of' => array('menus' => array('agent' => array('values' => $personalities,
									   'name' => 'agent',
									   'required' => true,
									   'checked' => 0,
									   'folding' => true
									   )),
					 'fs' => "PRED:to-take-of, subj:#agent#"),

		      'land' => array('menus' => array('agent' => array('values' => $personalities,
									'name' => 'agent',
									'required' => true,
									'checked' => 0,
									'folding' => true
									)),
				      'fs' => "PRED:to-land, subj:#agent#"),

		      'sail' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									  )),
					'fs' => "PRED:to-sail, subj:#agent#"),
		      
		      'tow' => array('menus' => array('agent' => array('values' => $personalities,
								       'name' => 'agent',
								       'required' => true,
								       'checked' => 0,
								       'folding' => true
								       ),
						      'patient' => array('values' => $items,
									 'name' => 'patient',
									 'required' => false,
									 'checked' => 0,
									 'folding' => true,
									 'newTD' => true)),
				     'fs' => "PRED:to-tow, subj:#agent#, obj:#patient#"),
		      
		      'fly' => array('menus' => array('agent' => array('values' => $personalities,
									  'name' => 'agent',
									  'required' => true,
									  'checked' => 0,
									  'folding' => true
									  )),
					'fs' => "PRED:to-fly, subj:#agent#"),
		      
		      'ride' => array('menus' => array('agent' => array('values' => $personalities,
									'name' => 'agent',
									'required' => true,
									'checked' => 0,
									'folding' => true
									),
						       'object' => array('values' => array(array('bike-lv', 'bike'), array('motocycle-lv', 'motocycle'), array('skateboard-lv', 'skateboard'), array('horse-lv', 'horse'), array('poney-lv', 'poney')),
									 'name' => 'object',
									 'required' => true,
									 'checked' => 0,
									 'folding' => true,
									 'newTD' => true)),
				      'fs' => "PRED:to-ride(#object#), subj:#agent#"),
		      'bike-lv' => array('fs' => "bike"),
		      
		      
		      
));

?>
