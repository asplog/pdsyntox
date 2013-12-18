<?php

$in=array_merge($in, 
		array('-transaction-predicates-'=> array('menus' => array('content' => array('values' => array('order', 'pay off', 'rent', 'book', 'sold', 'buy', 'etc.'),
											     'name' => '',
											     'required' => true,
											     'checked' => 0,
											     'folding' => false)),
							 
							 'radios' => $_radiosTenseAspect,
							 'checkboxes' => $_checkboxesNegative,
							 'fs' => "[#content#, diathesis:active, $_fsTenseAspectNegative]"),
		      
		      
		      '-transaction-predicates-withoutTenseAspectNegative-'=> array('menus' => array('content' => array('values' => array('order', 'pay off', 'rent', 'book', 'sold', 'buy', 'etc.'),
															'name' => '',
															'required' => true,
															'checked' => 0,
															'folding' => false)),
										    
										    'fs' => "[#content#, diathesis:active]"),
		      
		      
		      'order' => array('menus' => array('agent' => array('values' => $personalities,
									 'name' => 'Who is ordering',
									 'required' => true,
									 'checked' => 0,
									 'folding' => true
									 ),
							'patient' => array('values' => $items,
									   'name' => 'Object ordered',
									   'required' => true,
									   'checked' => 0,
									   'folding' => true,
									   'newTD' => true
									   ),
							'recipient' => array('values' => $personalities,
									     'name' => 'to whom',
									     'required' => false,
									     'checked' => 0,
									     'folding' => true,
									     'newTD' => true)),
				       'fs' => "PRED:to-order, subj:#agent#, obj:#patient#, à-obj:#recipient#"),
		      
		      'pay off' => array('menus' => array('agent' => array('values' => $personalities,
									   'name' => 'Agent',
									   'required' => true,
									   'checked' => 0,
									   'folding' => true
									   ),
							  'patient' => array('values' => $items,
									     'name' => 'Object',
									     'required' => true,
									     'checked' => 0,
									     'folding' => true,
									     'newTD' => true
									     ),
							  'recipient' => array('values' => $personalities,
									       'name' => 'Recipient',
									       'required' => false,
									       'checked' => 0,
									       'folding' => true,
									       'newTD' => true)),
					 'fs' => "PRED:to-pay-off, subj:#agent#, obj:#patient#, à-obj:#recipient#"),
		      
		      'rent' => array('menus' => array('agent' => array('values' => $personalities,
									'name' => 'Agent',
									'required' => true,
									'folding' => true,
									'checked' => 0
									),
						       'patient' => array('values' => $items,
									  'name' => 'Object',
									  'required' => true,
									  'folding' => true,
									  'checked' => 0,
									  'newTD' => true
									  ),
						       'recipient' => array('values' => $personalities,
									    'name' => 'Recipient',
									    'required' => false,
									    'checked' => 0,
									    'folding' => true,
									    'newTD' => true)),
				      'fs' => "PRED:to-rent, subj:#agent#, obj:#patient#, à-obj:#recipient#"),
		      
		      'book' => array('menus' => array('agent' => array('values' => $personalities,
									'name' => 'Agent',
									'required' => true,
									'folding' => true,
									'checked' => 0
									),
						       'patient' => array('values' => $items,
									  'name' => 'Object',
									  'required' => true,
									  'folding' => true,
									  'checked' => 0,
									  'newTD' => true
									  ),
						       'recipient' => array('values' => $personalities,
									    'name' => 'Recipient',
									    'required' => false,
									    'checked' => 0,
									    'folding' => true,
									    'newTD' => true)),
				      'fs' => "PRED:to-rent, subj:#agent#, obj:#patient#, à-obj:#recipient#"),
		      'buy' => array('menus' => array('agent' => array('values' => $personalities,
								       'name' => 'Agent',
								       'required' => true,
								       'folding' => true,
								       'checked' => 0
								       ),
						      'patient' => array('values' => $items,
									 'name' => 'Object',
									 'required' => true,
									 'folding' => true,
									 'checked' => 0,
									 'newTD' => true
									 ),
						      'recipient' => array('values' => $personalities,
									   'name' => 'Recipient',
									   'required' => false,
									   'checked' => 0,
									   'folding' => true,
									   'newTD' => true)),
				     'fs' => "PRED:to-buy, subj:#agent#, obj:#patient#, à-obj:#recipient#"),
		      'sold' => array('menus' => array('agent' => array('values' => $personalities,
									'name' => 'Agent',
									'required' => true,
									'folding' => true,
									'checked' => 0
									),
						       'patient' => array('values' => $items,
									  'name' => 'Object',
									  'required' => true,
									  'folding' => true,
									  'checked' => 0,
									  'newTD' => true
									  ),
						       'recipient' => array('values' => $personalities,
									    'name' => 'Recipient',
									    'required' => false,
									    'checked' => 0,
									    'folding' => true,
									    'newTD' => true)),
				      'fs' => "PRED:to-sold, subj:#agent#, obj:#patient#, à-obj:#recipient#")
		      )
		);
?>
		