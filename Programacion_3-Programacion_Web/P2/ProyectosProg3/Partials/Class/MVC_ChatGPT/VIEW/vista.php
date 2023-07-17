<?php
class Vista
{
    public function mostrarDatos($datos)
    {
        echo "<table>";
        echo "<tr><th>ID</th><th>Name</th><th>Surname</th></tr>";

        foreach ($datos as $fila) {
            echo "<tr>";
            echo "<td>" . $fila['id'] . "</td>";
            echo "<td>" . $fila['name'] . "</td>";
            echo "<td>" . $fila['surname'] . "</td>";
            echo "</tr>";
        }

        echo "</table>";
    }
}
