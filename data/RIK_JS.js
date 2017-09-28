
$(document).ready(function(){
		
	var goPress = false;
	var light = false;
	
	
	//функции для работы с мобильным телефоном
	$('html').on("touchstart", "#goForword", function(e){
		$('#goForword').css('background-color','red');
	
	});
	$('html').on("touchend", "#goForword", function(e){
		$('#goForword').css('background-color','green');
	
	});
	//==============================================	
		
	$('#flashOnOff').click(function(){
		if ($('#flashOnOff').html() == "Включить фонарь") {
			$(document).load('http://192.168.1.40:8080/enabletorch');
			$('#flashOnOff').html("Выключить фонарь");
		} else {
			$(document).load('http://192.168.1.40:8080/disabletorch');
			$('#flashOnOff').html("Включить фонарь");
		}   
		return;
	}) 
		
	
	
	//отлавливаем нажатие клавиш
	$('html').keydown(function(eventObject){ 
		 
		 if(event.keyCode == 70){
			 if(light){
				$(document).load('http://192.168.1.40:8080/disabletorch');
				light = false;
			 }
			 else{
				$(document).load('http://192.168.1.40:8080/enabletorch');
				light = true;
			 }
		 }
		 
		if(!goPress)
		{
			 //вперд
			if (event.keyCode == 87) { //если нажали Enter, то true
				$(document).load('http://192.168.1.36/forword');
				goPress = true;
				return;
			}
			
			//лево
			if (event.keyCode == 65) { //если нажали Enter, то true
				$(document).load('http://192.168.1.36/left');
				goPress = true;
				return;
			}
			
			//право
			if (event.keyCode == 68) { //если нажали Enter, то true
				$(document).load('http://192.168.1.36/right');
				goPress = true;
				return;
			}
			
			//back
			if (event.keyCode == 83) { //если нажали Enter, то true
				$(document).load('http://192.168.1.36/back');
				goPress = true;
				return;
			}
		}
		
	});
	
	//отлавливаем когда клавиша отпущена	
	$('html').keyup(function(eventObject){ 
		if ((event.keyCode == 87 || event.keyCode == 65 || event.keyCode == 68 || event.keyCode == 83) && goPress) { //если нажали Enter, то true ***|| event.keyCode == 65 || event.keyCode == 68)
			$(document).load('http://192.168.1.36/reset');
			goPress = false;
			return;
		}
		
		/*if(event.keyCode == 65 || event.keyCode == 68)
		{
			goPress = false;
		}*/
	});
	
	
});


				