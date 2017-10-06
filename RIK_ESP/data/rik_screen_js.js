function getAddres(addres)
{
	addres=addres.substr(addres.indexOf("/")+2, addres.length);
	addres=addres.substr(0,addres.indexOf("/"));
	return addres;
}

$(document).ready(function(){
		
	var goPress = false;//переменная нажатия кнопки
	var light = false;//прерменная включения света
	var visibleButt = true
	var arrButtID = ["#goForword", "#goBack", "#goLeft", "#goRight", "#lightON"]
	var addres = getAddres(location.href);
	var webcamAddres; //IP адрес камеры
	
	
	//функция скрытия кнопок
	function hideButt(numb, visibility){
		
		for(var i = 0; i < arrButtID.length; i++)
		{			
			if(visibility){
				if(i == numb) continue;
				$(arrButtID[i]).css('visibility','hidden');
				visibleButt = false;
			}
			else{
				$(arrButtID[i]).css('visibility','visible');
				visibleButt = true;
			}
		}
	}
	
	$("#setting").click(function(){
		location.href = "http://"+ addres +"/rik_menu.html";
	});
	
	
	
	//функция подключения камеры
	$("#agreeIP").click(function(){
		webcamAddres = $("#inputAddres").val();
		$("#browser_video").attr("src","http://"+ webcamAddres +"/video");
		return;
	}); 
	
	
//функции для работы с мобильным телефоном
	$('html').on("touchstart", "#goForword", function(){
		$(document).load('http://'+ addres +'/forword');
		hideButt(0, visibleButt);
		return;
	
	});
	$('html').on("touchstart", "#goBack", function(){
		$(document).load('http://'+ addres +'/back');
		hideButt(1, visibleButt);
		return;
	
	});
	$('html').on("touchstart", "#goLeft", function(){
		$(document).load('http://'+ addres +'/left');
		hideButt(2, visibleButt);
		return;
	
	});
	$('html').on("touchstart", "#goRight", function(){
		$(document).load('http://'+ addres +'/right');
		hideButt(3, visibleButt);
		return;
	
	});
	$('html').on("touchstart", "#lightON", function(){
		if(light){
			$(document).load('http://'+ webcamAddres +'/disabletorch');
			light = false;
		}
		else{
			$(document).load('http://'+ webcamAddres +'/enabletorch');
			light = true;
		}
		return;
	
	});
		
	
	//функции прекращения касания
	$('html').on("touchend", ".buttonRIK", function(e){
		$(document).load('http://'+ addres +'/reset');
		hideButt(0, visibleButt);
	});
	
	
//==============================================	
	//отлавливаем нажатие клавиш
	$('html').keydown(function(eventObject){ 
		 
		if(event.keyCode == 70){
			 if(light){
				$(document).load('http://'+ webcamAddres +'/disabletorch');
				light = false;
			 }
			 else{
				$(document).load('http://'+ webcamAddres +'/enabletorch');
				light = true;
			 }
		 }
		 
		if(!goPress)
		{
			 //вперд
			if (event.keyCode == 87) { 
				$(document).load('http://'+ addres +'/forword');
				goPress = true;
				return;
			}
			
			//лево
			if (event.keyCode == 65) { 
				$(document).load('http://'+ addres +'/left');
				goPress = true;
				return;
			}
			
			//право
			if (event.keyCode == 68) { 
				$(document).load('http://'+ addres +'/right');
				goPress = true;
				return;
			}
			
			//back
			if (event.keyCode == 83) { 
				$(document).load('http://'+ addres +'/back');
				goPress = true;
				return;
			}
		}
		
	});
	
	//отлавливаем когда клавиша отпущена	
	$('html').keyup(function(eventObject){ 
		if ((event.keyCode == 87 || event.keyCode == 65 || event.keyCode == 68 || event.keyCode == 83) && goPress) { //если нажали Enter, то true ***|| event.keyCode == 65 || event.keyCode == 68)
			$(document).load('http://'+ addres +'/reset');
			goPress = false;
			return;
		}
		
	});
	
	
});


				