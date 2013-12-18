////////////////////////////////////////////////
//
////////////////////////////////////////////////
function writeFsFinal(){
    if (typeof(document.template.sourceText) != 'undefined')
	document.template.sourceText.value=fsRoot;
    if (typeof(document.template.localSourceText) != 'undefined')
	document.template.localSourceText.value=fsSource;
    fsFinal = fsRoot;
    var regexp = /(<[^>]*>)/g;
    fsFinal = fsFinal.replace(regexp, '');
    var fsFinalOld='';
    while (fsFinal!=fsFinalOld){
	fsFinalOld=fsFinal;
	regexp = /((,\s*)?[^:, \[]*:(?![^,\s\]]))/g;
	fsFinal = fsFinal.replace(regexp, '');
	regexp = /((,\s*)?[^:,\[\s]*:(\[\]|\(\)|""))/g;
	fsFinal = fsFinal.replace(regexp, '');
	regexp = /(,\s*([,\]\)]))/g;
	fsFinal = fsFinal.replace(regexp, '$2');
	}
    document.template.inputData.value='Axiom	'+fsFinal;
}

////////////////////////////////////////////////
//
////////////////////////////////////////////////
function fsRootApply(id, name, value, add){
    //alert("fsRootApply\nid:" + id + "\n" + 'name:' + name + "\n" + "value:" + value);
    var regexp = new RegExp('(<ID_'+name+'_'+id+'>)(.*)(</ID_'+name+'_'+id+'>)');
    var table=regexp.exec(fsRoot);
    if (add && table[2]!='')
	fsRoot = fsRoot.replace(regexp, '$1$2,'+value+'$3'); 
    else
	fsRoot = fsRoot.replace(regexp, '$1'+value+'$3'); 
    writeFsFinal();
}

////////////////////////////////////////////////
//
////////////////////////////////////////////////
function addBlock(idFather, id, def, name, color, folding, verbose){
    var divId=0;
    if (typeof(defs[def])=='undefined'){
	alert('"' + def + '" is not yet defined\n');
    	return;
    }
    var radios = defs[def]['radios'];
    var checkboxes = defs[def]['checkboxes'];
    var texts = defs[def]['texts'];
    var buttons = defs[def]['buttons'];
    var menus = defs[def]['menus'];
    var dates = defs[def]['dates'];
    var times = defs[def]['times'];
    var emails = defs[def]['emails'];
    var evals = defs[def]['evals'];
    var fs = defs[def]['fs'];
    if (verbose)
	alert("idFather:" + idFather + "\nid:" + id + "\ndef:" + def + "\nname:" + name + "\nfs:" + fs + "\nradios:" + radios + "\ncheckboxes:" + checkboxes + "\ntexts:" + texts );
    fsSource=fs;
    divId=0;
    
    var div = document.getElementById('div_'+id);
    if (div==null){
	alert('fatal intern error line 70');
	return;
    }
    var fieldset = document.getElementById('fieldset_'+id);
    if (fieldset!=null)
    	div.removeChild(fieldset);

    ////////////////////////////////////////////////
    if ((typeof(defs[def]['input']) != 'undefined') && (defs[def]['input']=='hidden')){
    	var input=document.createElement('INPUT');
    	div.appendChild(input);
    	input.setAttribute('type', 'hidden');
    	input.setAttribute('name', 'inputData');
    } else if ((typeof(defs[def]['input']) != 'undefined') && (defs[def]['input']=='input')){
    	var fieldset=document.createElement('FIELDSET');
    	div.appendChild(fieldset);
    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Syntox Input';
    	var textarea=document.createElement('TEXTAREA');
    	fieldset.appendChild(textarea);
    	textarea.setAttribute('name', 'inputData');
    	textarea.setAttribute('rows', '8');
    	textarea.setAttribute('cols', '80');
    } else if ((typeof(defs[def]['input']) != 'undefined') && (defs[def]['input']=='source')){
    	var fieldset=document.createElement('FIELDSET');
    	div.appendChild(fieldset);
    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Source Input';
    	textarea=document.createElement('TEXTAREA');
    	fieldset.appendChild(textarea);
    	textarea.setAttribute('name', 'sourceText');
    	textarea.setAttribute('readonly', 'yes');
    	textarea.setAttribute('rows', '8');
    	textarea.setAttribute('cols', '80');
    	var fieldset=document.createElement('FIELDSET');
    	div.appendChild(fieldset);
    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Syntox Input';
    	var textarea=document.createElement('TEXTAREA');
    	fieldset.appendChild(textarea);
    	textarea.setAttribute('name', 'inputData');
    	textarea.setAttribute('readonly', 'yes');
    	textarea.setAttribute('rows', '8');
    	textarea.setAttribute('cols', '80');
    } else if ((typeof(defs[def]['input']) != 'undefined') && (defs[def]['input']=='local source')){
    	var fieldset=document.createElement('FIELDSET');
    	div.appendChild(fieldset);
    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Local source input';
	var textarea=document.createElement('TEXTAREA');
    	fieldset.appendChild(textarea);
    	textarea.setAttribute('name', 'localSourceText');
    	textarea.setAttribute('readonly', 'yes');
    	textarea.setAttribute('rows', '8');
    	textarea.setAttribute('cols', '80');
	var fieldset=document.createElement('FIELDSET');
    	div.appendChild(fieldset);
    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Syntox Input';
	textarea=document.createElement('TEXTAREA');
    	fieldset.appendChild(textarea);
    	textarea.setAttribute('name', 'inputData');
    	textarea.setAttribute('readonly', 'yes');
    	textarea.setAttribute('rows', '8');
    	textarea.setAttribute('cols', '80');
    }
    
    if (typeof(fs) != "undefined") {
	if (id==0)
	    fsRoot = fs;
        var regexp = new RegExp('(<ID_'+name+'_'+idFather+'>)(.*)(</ID_'+name+'_'+idFather+'>)');
    	fsRoot = fsRoot.replace(regexp, '$1'+fs+'$3'); 
        fsRoot = fsRoot.replace(/#([^#]*)#/g, '<ID_$1_'+id+'></ID_$1_'+id+'>'); 
    	writeFsFinal();
    }
    
    if (typeof(evals) != "undefined") {

	/***
	fieldset=document.createElement('FIELDSET');
    	if (color % 2 == 0)
	    fieldset.setAttribute('style', 'background-color:lightgray');
	else
	    fieldset.setAttribute('style', 'background-color:silver');
	fieldset.setAttribute('id', 'fieldset_'+id);
	div.appendChild(fieldset);

    	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	var font=document.createElement('FONT');
    	font.setAttribute('class', 'bold');
    	legend.appendChild(font);
    	font.textContent='Eval:'+id;

	var textarea=document.createElement('TEXTAREA');
    	textarea.setAttribute('rows', '4');
    	textarea.setAttribute('cols', '32');
    	textarea.setAttribute('name', 'eval:'+id);
    	fieldset.appendChild(textarea);
	textarea.value = "array(";
	$first=true;
	for (var eval in evals){
    	    if ($first) $first=false; else textarea.value += ',';
	    var localId=eval+'_'+id;
	    textarea.value += "'" + localId + "' => '" + evals[eval] + "'\n";
	    fsRootApply(id, eval, '$'+localId);
	}
	textarea.value += ")";
***/
	
	var input=document.createElement('INPUT');
    	input.setAttribute('type', 'hidden');
    	input.setAttribute('name', 'eval:'+id);
    	div.appendChild(input);
	input.value = "array(";
	$first=true;
	for (var eval in evals){
    	    if ($first) $first=false; else input.value += ',';
	    var localId=eval+'_'+id;
	    input.value += "'" + localId + "' => '" + evals[eval] + "'\n";
	    fsRootApply(id, eval, '$'+localId);
	}
	input.value += ")";

    }
    
    if ((typeof(texts) != "undefined") 
    	|| (typeof(dates) != "undefined") 
    	|| (typeof(times) != "undefined") 
    	|| (typeof(emails) != "undefined")
    	|| (typeof(radios) != "undefined")
    	|| (typeof(checkboxes) != "undefined")
    	|| (typeof(buttons) != "undefined")
    	|| (typeof(menus) != "undefined")) {
	
	fieldset=document.createElement('FIELDSET');
    	if (color % 2 == 0)
	    fieldset.setAttribute('style', 'background-color:lightgray');
	else
	    fieldset.setAttribute('style', 'background-color:silver');
	fieldset.setAttribute('id', 'fieldset_'+id);
	div.appendChild(fieldset);
	
	/************************************************
	var legend=document.createElement('LEGEND');
    	fieldset.appendChild(legend);
    	legend.textContent='id:'+id+' '+fs;
	************************************************/

	if (folding &&
	    id != 0) {
    	    var legend=document.createElement('LEGEND');
    	    fieldset.appendChild(legend);
    	    var div=document.createElement('DIV');
    	    div.setAttribute('id', 'img_on_'+id);
    	    legend.appendChild(div);
    	    var img=document.createElement('IMG');
    	    div.appendChild(img);
    	    img.setAttribute('src', 'images/stock_right.png');
    	    img.setAttribute('alt', 'stock_right.png');
    	    img.setAttribute('border', '0');
    	    img.setAttribute('onclick', 'document.getElementById(\'div_fieldset_'+id+'\').style.display=\'none\'; document.getElementById(\'img_on_'+id+'\').style.display=\'none\'; document.getElementById(\'img_off_'+id+'\').style.display=\'block\';');
	    
    	    div=document.createElement('DIV');
    	    div.setAttribute('id', 'img_off_'+id);
    	    div.setAttribute('style', 'display:none');
    	    legend.appendChild(div);
    	    img=document.createElement('IMG');
    	    div.appendChild(img);
    	    img.setAttribute('src', 'images/stock_down.png');
    	    img.setAttribute('alt', 'stock_down.png');
    	    img.setAttribute('onclick', 'document.getElementById(\'div_fieldset_'+id+'\').style.display=\'block\'; document.getElementById(\'img_off_'+id+'\').style.display=\'none\'; document.getElementById(\'img_on_'+id+'\').style.display=\'block\';');
	}
	div = document.createElement('DIV');
	div.setAttribute('id', 'div_fieldset_'+id);
	fieldset.appendChild(div);
    }
	
    if ((typeof(texts) != "undefined") 
    	|| (typeof(dates) != "undefined") 
    	|| (typeof(times) != "undefined") 
    	|| (typeof(emails) != "undefined")){
	var div2 = document.createElement('DIV');
	div2.setAttribute('id', 'div_'+ ++divId+'_'+id);
	div.appendChild(div2);
    	var table = document.createElement('TABLE');
    	table.setAttribute('border', '0');
    	table.setAttribute('cellspacing', '1');
    	table.setAttribute('cellpadding', '1');
    	div2.appendChild(table);
    	var tr = document.createElement('TR');
    	table.appendChild(tr);
    	var td = document.createElement('TD');
    	tr.appendChild(td);
    	for (var text in texts){
    	    if ((typeof(texts[text]['newTR']) != 'undefined') && texts[text]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(texts[text]['newTD']) != 'undefined') && texts[text]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var div3 = document.createElement('DIV');
	    div3.setAttribute('id', 'div_'+text+'_'+id);
    	    td.appendChild(div3);
    	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+text+'_'+id;
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    div3.appendChild(font);
    	    font.textContent=texts[text]['name']+String.fromCharCode(160);
    	    input =  document.createElement('INPUT');
    	    div3.appendChild(input);
    	    input.setAttribute('type', 'text');
    	    input.setAttribute('name', texts[text]);
    	    input.setAttribute('onchange', 'fsRootApply(\''+id+'\', \''+text+'\', this.value);');
    	    div3.appendChild(input);
	}
    	for (var date in dates){
    	    if ((typeof(dates[date]['newTR']) != 'undefined') && dates[date]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(dates[date]['newTD']) != 'undefined') && dates[date]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var div3 = document.createElement('DIV');
	    div3.setAttribute('id', 'div_'+date+'_'+id);
    	    td.appendChild(div3);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+date+'_'+id;
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    div3.appendChild(font);
    	    font.textContent=dates[date]['name']+String.fromCharCode(160);
    	    input =  document.createElement('INPUT');
    	    div3.appendChild(input);
    	    input.setAttribute('type', 'date');
    	    input.setAttribute('name', dates[date]);
    	    input.setAttribute('onchange', 'fsRootApply(\''+id+'\', \''+date+'\', this.value);');
    	    div3.appendChild(input);
    	}
    	for (var time in times){
    	    if ((typeof(times[time]['newTR']) != 'undefined') && times[time]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(times[time]['newTD']) != 'undefined') && times[time]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var div3 = document.createElement('DIV');
	    div3.setAttribute('id', 'div_'+time+'_'+id);
    	    td.appendChild(div3);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+time+'_'+id;
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    div3.appendChild(font);
    	    font.textContent=times[time]['name']+String.fromCharCode(160);
    	    input =  document.createElement('INPUT');
    	    div3.appendChild(input);
    	    input.setAttribute('type', 'time');
    	    input.setAttribute('name', times[time]);
    	    input.setAttribute('onchange', 'fsRootApply(\''+id+'\', \''+time+'\', this.value);');
    	}
    	for (var email in emails){
    	    if ((typeof(emails[email]['newTR']) != 'undefined') && emails[email]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(emails[email]['newTD']) != 'undefined') && emails[email]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var div3 = document.createElement('DIV');
	    div3.setAttribute('id', 'div_'+email+'_'+id);
    	    td.appendChild(div3);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+email+'_'+id;
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    div3.appendChild(font);
    	    font.textContent=emails[email]['name']+String.fromCharCode(160);
    	    input =  document.createElement('INPUT');
    	    div3.appendChild(input);
    	    input.setAttribute('type', 'email');
    	    input.setAttribute('name', emails[email]);
    	    input.setAttribute('onchange', 'fsRootApply(\''+id+'\', \''+email+'\', this.value);');
    	}
    }
    
    if (typeof(radios) != "undefined") {
 	var div2 = document.createElement('DIV');
	div2.setAttribute('id', 'div_'+ ++divId+'_'+id);
	div.appendChild(div2);
    	var table = document.createElement('TABLE');
    	table.setAttribute('border', '0');
    	table.setAttribute('cellspacing', '1');
    	table.setAttribute('cellpadding', '1');
    	div2.appendChild(table);
    	var tr = document.createElement('TR');
    	table.appendChild(tr);
    	var td = document.createElement('TD');
    	tr.appendChild(td);
        for (var radio in radios){
    	    if ((typeof(radios[radio]['newTR']) != 'undefined') && radios[radio]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(radios[radio]['newTD']) != 'undefined') && radios[radio]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
            var div3 = document.createElement('DIV');
	    td.appendChild(div3);
    	    div3.setAttribute('id', 'div_'+radio+'_'+id);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+radio+'_'+id;
    	    var fieldset = document.createElement('FIELDSET');
	    div3.appendChild(fieldset);
    	    var legend = document.createElement('LEGEND');
    	    fieldset.appendChild(legend);
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    legend.appendChild(font);
    	    font.textContent=radios[radio]['name']+String.fromCharCode(160);;
	    for (var attr in radios[radio]){
    		switch (attr){
    		case 'display':
    		    div3.setAttribute('style', 'display:'+radios[radio][attr]);
    		    break;
    		case 'values':
    		    for (var value in radios[radio][attr]) {
    			var div4=document.createElement('DIV');
    			fieldset.appendChild(div4);
    	    		font=document.createElement('FONT');
    			font.setAttribute('class', 'medium');
    			font.textContent=value+String.fromCharCode(160);
			div4.appendChild(font);
    	    		input =  document.createElement('INPUT');
    			div4.appendChild(input);
    			input.setAttribute('type', 'radio');
    			input.setAttribute('name', id+radio);
    			input.setAttribute('id', id+radio);
    			input.setAttribute('value', radios[radio][attr][value]);
    			var val='fsRootApply(\''+id+'\', \''+radio+'\', \''+radios[radio][attr][value]+'\');';
    			if (input.getAttribute('onchange')!=null)
    			    input.setAttribute('onchange', input.getAttribute('onchange') + val);
    			else
    			    input.setAttribute('onchange', val);
    		    }
    		    break;
    		case 'onchange':
    		    var radios2 = document.getElementsByName(id+radio);
    		    for (var i=0; i<radios2.length; i++){
    		    	var regexp=new RegExp('#([^#]*)#', 'g');
    			if (radios2[i].getAttribute('onchange')!=null)
    			    radios2[i].setAttribute('onchange', radios2[i].getAttribute('onchange') + radios[radio][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    			else
    			    radios2[i].setAttribute('onchange', radios[radio][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    }
    		    break;
    		case 'checked':
    		    if (radios[radio][attr]!='none'){
    			var radios2 = document.getElementsByName(id+radio);
    			radios2[radios[radio][attr]].setAttribute('checked', '');
    			fsRootApply(id, radio, radios2[radios[radio][attr]].getAttribute('value'));
    		    }
    		    break;
    		case 'disabled':
    		    var radios2 = document.getElementsByName(id+radio);
    		    for (var i=0; i<radios2.length; i++){
    			if (radios[radio][attr][i])
    			    radios2[i].setAttribute('disabled', 'yes');
    		    }
    		    break;
    		}
    	    }	
    	}
    }
    
    if (typeof(checkboxes) != "undefined") {
	var div2 = document.createElement('DIV');
	div2.setAttribute('id', 'div_'+ ++divId+'_'+id);
	div.appendChild(div2);
    	var table = document.createElement('TABLE');
    	table.setAttribute('border', '0');
    	table.setAttribute('cellspacing', '1');
    	table.setAttribute('cellpadding', '1');
    	div2.appendChild(table);
    	var tr = document.createElement('TR');
    	table.appendChild(tr);
    	var td = document.createElement('TD');
    	tr.appendChild(td);
        for (var checkbox in checkboxes){
    	    if ((typeof(checkboxes[checkbox]['newTR']) != 'undefined') && checkboxes[checkbox]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(checkboxes[checkbox]['newTD']) != 'undefined') && checkboxes[checkbox]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var div3 = document.createElement('DIV');
	    div3.setAttribute('id', 'div_'+checkbox+'_'+id);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+checkbox+'_'+id;
    	    td.appendChild(div3);
    	    font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    div3.appendChild(font);
    	    font.textContent=checkboxes[checkbox]['name']+String.fromCharCode(160);
    	    div3.appendChild(font);
    	    var input;
    	    for (var attr in checkboxes[checkbox]){
    		switch (attr){
    		case 'display':
    		    fieldset.setAttribute('style', 'display:'+checkboxes[checkbox][attr]);
    		    break;
    		case 'value':
    		    input =  document.createElement('INPUT');
    		    div3.appendChild(input);
    		    input.setAttribute('type', 'checkbox');
    		    input.setAttribute('name', id+checkbox);
    		    var val='fsRootApply(\''+id+'\', \''+checkbox+'\', this.checked ? \''+checkboxes[checkbox][attr]+'\' : \'\');';
    		    if (input.getAttribute('onchange')!=null)
    			input.setAttribute('onchange', input.getAttribute('onchange') + val);
    		    else
    			input.setAttribute('onchange', val);
    		    break;
    		case 'onchange':
    		    var regexp=new RegExp('#([^#]*)#', 'g');
    		    if (input.getAttribute('onchange')!=null)
    			input.setAttribute('onchange', input.getAttribute('onchange') + checkboxes[checkbox][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    else
    			input.setAttribute('onchange', checkboxes[checkbox][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    break;
    		case 'checked':
    		    if (checkboxes[checkbox][attr]){
    			input.setAttribute('checked', 'true');
    			fsRootApply(id, checkbox, checkboxes[checkbox]['value']);
    		    }
    		    break;
    		case 'disabled':
    		    if (checkboxes[checkbox][attr]){
    			input.setAttribute('disabled', checkboxes[checkbox][attr]);
    		    }
    		}
    	    }
    	}
    }
    
    if (typeof(menus) != "undefined") {
	var div2 = document.createElement('DIV');
	div2.setAttribute('id', 'div_'+ ++divId +'_'+id);
	div.appendChild(div2);
    	var table = document.createElement('TABLE');
    	table.setAttribute('border', '0');
    	table.setAttribute('cellspacing', '1');
    	table.setAttribute('cellpadding', '1');
    	div2.appendChild(table);
    	var tr = document.createElement('TR');
    	table.appendChild(tr);
    	var td = document.createElement('TD');
    	td.setAttribute('id', 'td_'+id);
    	tr.appendChild(td);
	var j=0;
        for (var menu in menus){
    	    if ((typeof(menus[menu]['newTR']) != 'undefined') && menus[menu]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(menus[menu]['newTD']) != 'undefined') && menus[menu]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var id2 = menu+'_'+id;
    	    var div3 = document.createElement('DIV');
	    td.appendChild(div3);
    	    div3.setAttribute('id', 'div_'+id2);
	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+id2;
    	    var font=document.createElement('FONT');
    	    font.setAttribute('class', 'bold');
    	    font.textContent=menus[menu]['name']+String.fromCharCode(160);
    	    div3.appendChild(font);
    	    var sel = document.createElement('SELECT');
    	    div3.appendChild(sel);
    	    sel.setAttribute('name', 'select');
    	    var folding2=false;
	    if ((typeof(menus[menu]['folding']) != 'undefined') && menus[menu]['folding']){
		folding2=true;
		sel.setAttribute('onchange', 'addBlock(\''+id+'\', \''+id2+'\', this.value, \''+menu+'\', '+(color+1).toString()+', true);');
	    } else
		sel.setAttribute('onchange', 'addBlock(\''+id+'\', \''+id2+'\', this.value, \''+menu+'\', '+(color).toString()+', false);');
	    for (var attr in menus[menu]){
		switch(attr){
		case 'display':
		    div3.setAttribute('style', 'display:'+menus[menu][attr]);
    		    break;
		case 'values':
		    var values = menus[menu]['values'];
    		    for (var i=0 ; i < values.length ; i++) {
    	       		if (typeof(values[i])=='object'){
			    var opt = document.createElement('OPTION');
    	       		    opt.textContent=values[i][1];
    			    opt.setAttribute('value', values[i][0]);
    	       		    sel.appendChild(opt);
			} else {
			    var opt = document.createElement('OPTION');
    	       		    opt.textContent=values[i];
    			    opt.setAttribute('value', values[i]);
    	       		    sel.appendChild(opt);
    			}
		    }
    		    break;
		case 'zzzonchange':
    		    var regexp=new RegExp('zzz#([^#]*)#', 'g');
    		    if (sel.getAttribute('onchange')!=null)
    			sel.setAttribute('onchange', sel.getAttribute('onchange') + menus[menu][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    else
    			sel.setAttribute('onchange', menus[menu][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    break;
		case 'checked':
		    if (folding2)
			addBlock(id, id2, sel.getElementsByTagName('OPTION')[menus[menu][attr]].value, menu, color+1, folding2);
		    else 
			addBlock(id, id2, sel.getElementsByTagName('OPTION')[menus[menu][attr]].value, menu, color, folding2);
    		    sel.getElementsByTagName('OPTION')[menus[menu][attr]].setAttribute('selected', 'yes');
		    break;
		case 'disabled':
    		    sel.setAttribute('disabled', menus[menu][attr]);
    		    break;
		case 'required':
    		    var opt = document.createElement('OPTION');
		    if (menus[menu][attr]){
    	       		font.textContent += '*'+String.fromCharCode(160);
    	       		opt.setAttribute('value', '-REQUIRED-');
    	       	    }else
			opt.setAttribute('value', '-NOT-REQUIRED-');
    	       	    sel.insertBefore(opt, sel.firstChild);
		    break;
		}
	    }
	}
    }
    
    if (typeof(buttons) != "undefined") {
	var div2 = document.createElement('DIV');
	div2.setAttribute('id', 'div_'+ ++divId+'_'+id);
	div.appendChild(div2);
    	var table = document.createElement('TABLE');
    	table.setAttribute('border', '0');
    	table.setAttribute('cellspacing', '1');
    	table.setAttribute('cellpadding', '1');
    	div2.appendChild(table);
    	var tr = document.createElement('TR');
    	table.appendChild(tr);
    	var td = document.createElement('TD');
    	tr.appendChild(td);
        for (var button in buttons){
    	    if ((typeof(buttons[button]['newTR']) != 'undefined') && buttons[button]['newTR']){
    		tr = document.createElement('TR');
    		table.appendChild(tr);
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    if ((typeof(buttons[button]['newTD']) != 'undefined') && buttons[button]['newTD']){
    		td = document.createElement('TD');
    		tr.appendChild(td);
    	    }
    	    var id2 = button+'_'+id;
	    var div3 = document.createElement('DIV');
	    td.appendChild(div3);
	    div3.setAttribute('id', 'div_'+id2);
    	    //var font=document.createElement('FONT');
    	    //div3.appendChild(font);
    	    //font.textContent='id:'+'div_'+id2;
    	    var input =  document.createElement('INPUT');
    	    div3.appendChild(input);
    	    input.setAttribute('type', 'button');
    	    input.setAttribute('value', buttons[button]['name']);
	    var val='var k=document.getElementsByName(\''+id2+'\').length;';
	    val += 'if (k >= 3) {';
	    val += ' alert(\'too much modifications on this concept.\');';
	    val += '} else {';
	    val += ' var idxxx=k+\'_'+id2+'\';';
	    val += ' var divxxx=document.getElementById(\'div_'+id2+'\');';
	    val += ' var div4=document.createElement(\'DIV\');';
	    val += ' divxxx.appendChild(div4);';
	    val += ' div4.setAttribute(\'id\', \'div_\'+idxxx);';
	    val += ' div4.setAttribute(\'name\', \''+id2+'\');';
	    val += ' addBlock(\''+id+'\', idxxx, \''+buttons[button]['value']+'\', \'\', 0, true, false);';
	    val += ' var fs=\''+defs[buttons[button]['value']]['fs']+'\';';
	    val += ' fs=fs.replace(/#([^#]*)#/g, \'<ID_$1_\'+idxxx+\'></ID_$1_\'+idxxx+\'>\');';
	    val += ' fsRootApply(\''+id+'\', \''+button+'\', fs, true);';
	    
	    val += '}';
	    if (input.getAttribute('onclick')!=null)
    		input.setAttribute('onclick', input.getAttribute('onclick') + val);
    	    else
    		input.setAttribute('onclick', val);
	    for (var attr in buttons[button]){
    		switch (attr){
    		case 'display':
    		    fieldset.setAttribute('style', 'display:'+buttons[button][attr]);
    		    break;
    		case 'onclickzzz':
    		    var regexp=new RegExp('#([^#]*)#', 'g');
    		    if (input.getAttribute('onclick')!=null)
    			input.setAttribute('onclick', input.getAttribute('onclick') + buttons[button][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    else
    			input.setAttribute('onclick', buttons[button][attr].replace(regexp, 'div_'+'$1'+'_'+id));
    		    break;
    		case 'disabled':
    		    if (buttons[button][attr]){
    			input.setAttribute('disabled', buttons[button][attr]);
    		    }
    		}
    	    }
    	}
    }
    

}
