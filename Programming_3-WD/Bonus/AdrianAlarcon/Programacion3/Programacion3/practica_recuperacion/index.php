<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

    <input type="text" id="nombre" name="nombre"> 
    <br>
    <input type="text" id="apellido" name="apellido"> 
    <br>
    <input type="text" id="nombre_completo" name="nombre_completo" readonly="readonly"> 
    <br>
    <button onclick="concatenarNombre()">Concatenar</button>
    <br>
    <button onclick="borrarTodo()">Borrar</button>
    <br>
    <button onclick="enviarTabla()">Enviar a Tabla</button>

    <div>
        <table border="1">
            <tr>
                <th>Nombre</th>
                <th>Apellido</th>
                <th>Nombre completo</th>
            </tr>
            <tbody id="cuerpo_tabla">
        </table>
    </div>

</body>

    <script type="text/javascript">
        function concatenarNombre(){
            var nombre = document.getElementById("nombre").value; // siempre recibe un string
            var apellido = document.getElementById("apellido").value;
            var nombreCompleto = document.getElementById("nombre_completo");
            nombreCompleto.value = nombre + " " + apellido;
        }
        function borrarTodo(){
            document.getElementById("nombre").value="";
            document.getElementById("apellido").value="";
            document.getElementById("nombre_completo").value="";
        }

        function enviarTabla() {
            document.getElementById("cuerpo_tabla").innerHTML=`<tr>
                        <td>
                        ${document.getElementById("nombre").value}
                        </td>
                        <td>
                        ${document.getElementById("apellido").value}
                        </td>
                        <td>
                        ${document.getElementById("nombre_completo").value}
                        </td>
                        </tr>`
        }
    </script>
</html>
