/*
function procesarFormulario (){
	var errores = 0;
	var nombre = document.getElementById('nombre').value;
	if (nombre=== "") {
		errores +=1;
		document.getElementById("msg-nombre").style.display = "block";
	}

	var email = document.getElementById('email').value;
	if (email=== "") {
		errores +=1;
		document.getElementById("msg-email").style.display = "block";
	}
	if (errores== 0) {
		document.getElementById("formulario-registro").submit();
	}
} */

function procesarFormulario (){
	var errores = "";
	var nombre = document.getElementById('nombre').value;
	if (nombre=== "") {
		errores += "El campo Nombre es obligatorio <br>";
	}

	var email = document.getElementById('email').value;
	if (email=== "") {
		errores += "El campo Correo electronico es obligatorio <br>";
	}

	if (errores=== "") {
		document.getElementById("formulario-registro").submit();

	}else{
		document.getElementById("msg-general").innerHTML = errores;
		document.getElementById("msg-general").style.display = "block";
	}
}