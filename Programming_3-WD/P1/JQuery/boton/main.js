$(document).ready(function() {

    
    $(".boton").click(function() {
        let name = $("#name").val();
        let surname = $("#surname").val();
        var valor = $(".boton").text();
        alert("El valor del boton es: " + valor)
        alert(`Bienvenido ${name} ${surname}`);
        $(".boton").text("Nuevo valor");
    })
})