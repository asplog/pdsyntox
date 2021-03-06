<?php
$ol=array('098', '099', '100', 
	  '101', '102', '103', '104', '105', '106', '107', '108', '109', '110', '111',
	  '201', '202', '203', '204', '205', '206', '207',
	  '301',
	  '401');


//////////////////////////////////////////////////
// On lit data/xxx
// On assigne $titlexxx := $title 
//////////////////////////////////////////////////
foreach ($ol as $li){
  include('data/'.$li);
  ${'title'.$li}=$title;
  ${'subtitle'.$li}=$subtitle;
  ${'in'.$li}=$in;
  ${'gr'.$li}=$gr;
  ${'lx'.$li}=$lx;
  if (isset($pe))
    ${'pe'.$li}=$pe;
}

$samples = array('Formal 1' => 
		 array('title' => $title098,
		       'subtitle' => $subtitle098,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in098,
		       'grammar' => 1, 
		       'grammarRows' => 14, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr098, 
		       'lexicon' => 1, 
		       'lexiconRows' => 12, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx098,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'Formal 2' => 
		 array('title' => $title099,
		       'subtitle' => $subtitle099,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in099,
		       'grammar' => 1, 
		       'grammarRows' => 14, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr099, 
		       'lexicon' => 1, 
		       'lexiconRows' => 12, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx099,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'Formal 3' => 
		 array('title' => $title100,
		       'subtitle' => $subtitle100,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in100,
		       'grammar' => 1, 
		       'grammarRows' => 14, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr100, 
		       'lexicon' => 1, 
		       'lexiconRows' => 12, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx100,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'French 1' => 
		 array('title' => $title101,
		       'subtitle' => $subtitle101,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in101,
		       'grammar' => 1, 
		       'grammarRows' => 14, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr101, 
		       'lexicon' => 1, 
		       'lexiconRows' => 12, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx101,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'French 2' =>
		 array('title' => $title102,
		       'subtitle' => $subtitle102,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in102,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr102, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx102,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'French 3' =>
		 array('title' => $title103,
		       'subtitle' => $subtitle103,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in103,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr103, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx103,
		       'postEdition' => false, 
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => ''
		       ),
		 'French 4' =>
		 array('title' => $title104,
		       'subtitle' => $subtitle104,
		    'task' => 'synthesize', 
		    'input' => 1, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in104,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr104, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx104,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe104
		    ),
		 'French 5' =>
		 array('title' => $title105,
		    'subtitle' => $subtitle105,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in105,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr105, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx105,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe105
		    ),
		 'French 6' =>
		 array('title' => $title106,
		    'subtitle' => $subtitle106,
		    'task' => 'synthesize', 
		    'input' => 1, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in106,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr106, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx106,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe106
		    ),
		 'French 7' =>
		 array('title' => $title107,
		    'subtitle' => $subtitle107,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in107,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr107, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx107,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe107
		    ),
		 'French 8' =>
		 array('title' => $title108,
		    'subtitle' => $subtitle108,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in108,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr108, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx108,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe108
		    ),
		 'French 9' =>
		 array('title' => $title109,
		    'subtitle' => $subtitle109,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in109,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr109, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx109,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe109
		    ),
		 'French 10' =>
		 array('title' => $title110,
		    'subtitle' => $subtitle110,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 30, 
		    'inputCols' => 80, 
		    'inputData' => $in110,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr110, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx110,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe110
		    ),
		 'French 11' =>
		 array('title' => $title111,
		    'subtitle' => $subtitle111,
		    'task' => 'synthesize', 
		    'input' => 2, 
		    'inputRows' => 8, 
		    'inputCols' => 80, 
		    'inputData' => $in111,
		    'grammar' => 1, 
		    'grammarRows' => 38, 
		    'grammarCols' => 80, 
		    'grammarText' => $gr111, 
		    'lexicon' => 1, 
		    'lexiconRows' => 24, 
		    'lexiconCols' => 80, 
		    'lexiconButtons' => '', 
		    'lexiconText' => $lx111,
		    'postEdition' => 1, 
		    'postEditionRows' => 12, 
		    'postEditionCols' => 80, 
		    'postEditionText' => $pe111
		    ),
		 'Test 1' =>
		 array('title' => $title201,
		       'subtitle' => $subtitle201,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in201,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr201, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx201,
		       'postEdition' => false
		       ),
		 'Test 2' =>
		 array('title' => $title202,
		       'subtitle' => $subtitle202,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in202,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr202, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx202,
		       'postEdition' => false
		       ),
		 'Test 3' =>
		 array('title' => $title203,
		       'subtitle' => $subtitle203,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in203,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr203, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx203,
		       'postEdition' => false
		       ),
		 'Test 4' =>
		 array('title' => $title204,
		       'subtitle' => $subtitle204,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in204,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr204, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx204,
		       'postEdition' => false
		       ),
		 'Test 5' =>
		 array('title' => $title205,
		       'subtitle' => $subtitle205,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in205,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr205, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx205,
		       'postEdition' => false
		       ),
		 'Test 6' =>
		 array('title' => $title206,
		       'subtitle' => $subtitle206,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in206,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr206, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx206,
		       'postEdition' => false
		       ),
		 'Test 7' =>
		 array('title' => $title207,
		       'subtitle' => $subtitle207,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in207,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr207, 
		       'lexicon' => false, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx207,
		       'postEdition' => false
		       ),
		 'Music 1' =>
		 array('title' => $title301,
		       'subtitle' => $subtitle301,
		       'task' => 'synthesize', 
		       'input' => 1, 
		       'inputRows' => 8, 
		       'inputCols' => 80, 
		       'inputData' => $in301,
		       'grammar' => 1, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr301, 
		       'lexicon' => 1, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx301,
		       'postEdition' => false
		       ),
		 'Message' =>
		 array('title' => $title402,
		       'subtitle' => $subtitle402,
		       'task' => 'synthesize', 
		       'input' => 5, // 3: lettre, 4: email, 5:message 
		       'inputData' => $in402,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr402, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx402,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe402
		       ),
		 'Email' =>
		 array('title' => $title403,
		       'subtitle' => $subtitle403,
		       'task' => 'synthesize', 
		       'input' => 4, // 3: lettre, 4: email, 5:message 
		       'inputData' => $in403,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr403, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx403,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe403
		       ),
		 'Letter' =>
		 array('title' => $title404,
		       'subtitle' => $subtitle404,
		       'task' => 'synthesize', 
		       'input' => 3, // 3: lettre, 4: email, 5:message 
		       'inputData' => $in404,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr404, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx404,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe404
		       ),
		 'Message 2' =>
		 array('title' => $title303,
		       'subtitle' => $subtitle303,
		       'task' => 'synthesize', 
		       'input' => 5, // 3: lettre, 4: email, 5:message 
		       'inputData' => $in303,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr303, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx303,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe303
		       ),
		 'NLG with a data list 1' =>
		 array('title' => $title303,
		       'subtitle' => $subtitle303,
		       'task' => 'synthesize', 
		       'input' => 6, // 3: lettre, 4: email, 5:message interractif, 6: message automatique 
		       'inputData' => $in303,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr303, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx303,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe303
		       ),
		 'NLG with a data list 2' =>
		 array('title' => $title303,
		       'subtitle' => $subtitle303,
		       'task' => 'synthesize', 
		       'input' => 7, // 3: lettre, 4: email, 5:message interractif, 6-7: message automatique 
		       'inputData' => $in303,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr303, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx303,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe303
		       ),
		 'NLG with manual entry' =>
		 array('title' => $title303,
		       'subtitle' => $subtitle303,
		       'task' => 'synthesize', 
		       'input' => 5, // 3: lettre, 4: email, 5:message interractif, 6: message automatique 
		       'inputData' => $in303,
		       'grammar' => 3, 
		       'grammarRows' => 38, 
		       'grammarCols' => 80, 
		       'grammarText' => $gr303, 
		       'lexicon' => 3, 
		       'lexiconRows' => 24, 
		       'lexiconCols' => 80, 
		       'lexiconButtons' => '', 
		       'lexiconText' => $lx303,
		       'postEdition' => 3,
		       'postEditionRows' => 12, 
		       'postEditionCols' => 80, 
		       'postEditionText' => $pe303
		       )
		 );

$menus = array(array('name' => 'formal grammars', 
		     'available' => true,
		     'submenu' => 
		     array(
			   array('name' => 'Formal 1', 'task' => 'sample'),
			   array('name' => 'Formal 2', 'task' => 'sample'),
			   array('name' => 'Formal 3', 'task' => 'sample'),
			   )
		     ), 
	       array('name' => 'French grammar', 
		     'available' => true,
		     'submenu' => 
		     array(
			   array('name' => 'French 1', 'task' => 'sample'),
			   array('name' => 'French 2', 'task' => 'sample'), 
			   array('name' => 'French 3', 'task' => 'sample'), 
			   array('name' => 'French 4', 'task' => 'sample'),
			   array('name' => 'French 5', 'task' => 'sample'), 
			   array('name' => 'French 6', 'task' => 'sample'), 
			   array('name' => 'French 7', 'task' => 'sample'), 
			   array('name' => 'French 8', 'task' => 'sample'), 
			   array('name' => 'French 9', 'task' => 'sample'),
			   array('name' => 'French 10', 'task' => 'sample'),
			   array('name' => 'French 11', 'task' => 'sample')
			   )
		     ), 
	       array('name' => 'Tests', 
		     'available' => true,
		     'submenu' => 
		     array(
			   array('name' => 'Test 1', 'task' => 'sample'),
			   array('name' => 'Test 2', 'task' => 'sample'),
			   array('name' => 'Test 3', 'task' => 'sample'),
			   array('name' => 'Test 4', 'task' => 'sample'),
			   array('name' => 'Test 5', 'task' => 'sample'),
			   array('name' => 'Test 6', 'task' => 'sample'),
			   array('name' => 'Test 7', 'task' => 'sample')
			   )
		     ),
	       array('name' => 'Music', 
		     'available' => true,
		     'submenu' => 
		     array(
			   array('name' => 'Music 1', 'task' => 'sample')
			   )
		     ) 
	       /* array('name' => 'Syntactic inputs',  */
	       /* 	     'available' => true, */
	       /* 	     'submenu' =>  */
	       /* 	     array( */
	       /* 		   array('name' => 'Syntactic 1', 'task' => 'sample') */
	       /* 		   ) */
	       /* 	     ),  */
	       /***
		   array('name' => 'Conceptual inputs', 
		   'available' => true,
		   'submenu' => 
		   array(
		   //array('name' => 'Email'),
			   //array('name' => 'Message'),
			   array('name' => 'NLG with a data list 1', 'task' => 'sample'),
			   array('name' => 'NLG with a data list 2', 'task' => 'sample'),
			   array('name' => 'NLG with manual entry', 'task' => 'sample')
			   )
			   ) 
	       ***/
	       );

?>