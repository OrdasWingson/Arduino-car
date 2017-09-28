//функция получения адреса
function getAddres(addres)
{
	addres=addres.substr(addres.indexOf("/")+2, addres.length);
	addres=addres.substr(0,addres.indexOf("/"));
	return addres;
}

$(document).ready(function(){
	var _mode="";
	var addres = getAddres(location.href);
	var pos;
	
	
	$.getJSON("http://"+ addres +"/config", function(result){
        $.each(result, function(key, field){
			
			if(key == "ssid")
			{
				$("input[name='ssid']").val(field);
			}
			
			if(key == "password")
			{
				$("input[name='password']").val(field);
			}
			
			
			if(key == "state")
			{
				$("#mode").html(field);
				_mode = field;
			}
        });
	});
	

	$("#blockAP").css('visibility','hidden').css('position', 'absolute');
	//обработка события выбора режима
	$("input[name=dzen]").click(function() {
		if($("#client").is(":checked"))
		{
			$("#blockAP").css('visibility','hidden').css('position', 'absolute');
			$("#clientPoint").css('visibility','visible').css('position', 'relative');			
		}
		else if($("#softAP").is(":checked"))
		{
			$("#clientPoint").css('visibility','hidden').css('position', 'absolute');
			$("#blockAP").css('visibility','visible').css('position', 'relative');
		}
	});
	
	//нажатие кнопки запуск
	$("#startBTN").click(function() {
		if(_mode == "STA")
		{
			if($("#client").is(":checked")){
				location.href = "http://"+ addres +"/index.html";
			}
			else{
				$(document).load('http://' + addres + '/mode="ap"');
			}
			
		}
		else if(_mode == "AP")
		{
			if($("#softAP").is(":checked")){
				location.href = "http://"+ addres +"/index.html";
			}
			else{
				$(document).load('http://' + addres + '/mode?mode="sta"');
			}
		}
		
	});

	
	
});