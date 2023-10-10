/*function procesarFormulario (){

	var errores = "";
	var nombre = $("#nombre").val();

	
	if (nombre === "") {
		errores += "El campo Nombre es obligatorio <br>";
	}

	var email = $("#email").val();
	if (email=== "") {
		errores += "El campo Correo electronico es obligatorio <br>";
	}

	if (errores=== "") {
		$("#formulario-registro").submit();

	}else{
		$("#msg-general").html(errores);
		$("#msg-general").show();
	}
}*/

$("#btn-guardar").click(function(){
	var errores = "";
	var nombre = $("#nombre").val();

	
	if (nombre === "") {
		errores += "El campo Nombre es obligatorio <br>";
	}

	var email = $("#email").val();
	if (email=== "") {
		errores += "El campo Correo electronico es obligatorio <br>";
	}

	if (errores=== "") {
		$.ajax({
			url: "control.php",
			type: "POST",
			data: {
				nombre: $("#nombre").val(),
				email: $("#email").val(),
				clave: $("#clave").val(),
				tipoPlan: $("#tipo-plan").val(),
				observacion: $("#observacion").val(),
			},
			success: function(data){
				alert(data);
			}
		});
	}else{
		$("#msg-general").html(errores);
		$("#msg-general").show();
	}
});

$.ajax({
	url: "https://jsonplaceholder.typicode.com/users",
	success: function(respuesta){
		for(var i=0; i<respuesta.length;i++){
			$("#contenedor-cartas").append(`<div class="col"> 

				<div class="card" style="width: 18rem;">
				  <div class="card-body">
				    <h5 class="card-title">${respuesta[i].name }</h5>
				    <h6 class="card-subtitle mb-2 text-muted">${respuesta[i].email }</h6>
				    <p class="card-text">${respuesta[i].website }</p>
				</div>




				</div>`);
		}
	}
})


$("#btn-ocultar-cartas").click(function(){
	$(".col").hide();
});