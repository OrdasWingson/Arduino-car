//функция получения адреса
function getAddres(addres)
{
	addres=addres.substr(addres.indexOf("/")+2, addres.length);
	addres=addres.substr(0,addres.indexOf("/"));
	return addres;
}

$(document).ready(function(){
	var _mode; //режим модуля(точка доступа или клиент)
	var addres = getAddres(location.href); //аддрес страницы
	var ssid; //имя сети
	var pass; //пароль
	
	//получаем данные конфигурации сервера
	$.getJSON("http://"+ addres +"/config", function(result){
        $.each(result, function(key, field){
			
			if(key == "ssid")
			{
				$("input[name='ssid']").val(field);
				ssid = field;
			}
			
			if(key == "password")
			{
				$("input[name='password']").val(field);
				pass = field;
			}
			
			
			if(key == "state")
			{
				$("#mode").html(field);
				_mode = field;
			}
        });
	});
	
	
	//нажатие кнопки запуск
	$("#startBTN").click(function() {
		if(_mode == "STA")
		{
			if($("#client").is(":checked")){
				location.href = "http://"+ addres +"/start.html";
			}
			else{
				$(document).load('http://' + addres + '/mode?mode=AP');
			}
			
		}
		else if(_mode == "AP")
		{
			if($("#softAP").is(":checked")){
				location.href = "http://"+ addres +"/start.html";
			}
			else{
				ssid = $("input[name='ssid']").val();
				pass = $("input[name='password']").val();
				$(document).load('http://' + addres + '/mode?mode=STA&ssid='+ ssid +'&pass='+ pass);
			}
		}			
	});

	
	
});