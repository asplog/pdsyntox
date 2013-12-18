<?php
$in=array_merge($in, 
		array('-food-items-' => array('menus' => array('content' => array('values' => array('fish', '-seafood-', '*deli', '*meat', '*peticular meat', '*chicken', '*cheese', '*milk', '*butter', '*egg', '*vegetables', '*peticular vegetable', '*fruit', '*peticular fruit', '*rice', '*bread', '*pasta', '*grocery bag', '*shopping list', '*coupons'),
										'name' => 'Item',
										'required' => true,
										'checked' => 0,
										'folding' => false)),
					    
					      'radios' => $_radiosDeterminerNumber,
					      'buttons' => $_buttonsModifier,
					      'fs' => "[#content#, $_fsDeterminerNumberModifier]"),
		      
		      'fish' => array('fs' => "PRED:fish"),
		      '-seafood-' => array('menus' => array('content' => array('values' => array('trout', '*catfish', 'salmon', 'whole salmon', 'salmon steak', '*swordfish', '*halibut steak', '*tuna', '*cod', '*crab', '*lobster', '*shrimp', '*scallops', '*mussels', '*oyster', '*clams'),
									     'name' => 'Item',
									     'required' => true,
									     'checked' => 0,
									     'folding' => false)),
					 'fs' => '#content#'),
		      
		      'trout' => array('fs' => "PRED:trout"),
		      'whole salmon' => array('fs' => "PRED:whole_salmon"),
		      'salmon steak' => array('fs' => "PRED:salmon_steak")
		      )
		);
?>
