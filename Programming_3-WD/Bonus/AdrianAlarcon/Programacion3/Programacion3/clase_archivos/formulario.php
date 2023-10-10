<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ingreso de Estudiantes</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">   
</head>
<body>
    <div class="container">
        <br>
        <form action="controlador.php" method="POST"> <!--cuerpo de la peticion-->
        <input type="hidden" name="opcion" value="guardar">
        <div class="mb-3">
            <label for="cedula" class="form-label"> Cedula </label>
            <input type="text" class="form-control" id="cedula" name="cedula" required="required">
        </div>
        <div class="mb-3">
            <label for="nombre" class="form-label"> Nombre </label>
            <input type="text" class="form-control" id="nombre" name="nombre" required="required">
        </div>
        <div class="mb-3">
            <label for="correo" class="form-label"> Correo </label>
            <input type="email" class="form-control" id="correo" name="correo" required="required">
        </div>
        <button type="submit" class="btn btn-primary">Guardar</button>
        </form>
    </div>
</body>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
</html>