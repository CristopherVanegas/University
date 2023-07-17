<?php
$inc = include("con_db.php");
if ($inc) {
	$consulta = "SELECT * FROM nombres";
	$resultado = mysqli_query($conex, $consulta);
	if ($resultado) {
		while ($row = $resultado->fetch_array()) {
			$id = $row['id'];
			$name = $row['name'];
			$surname = $row['surname'];
?>
			<div>
				<h2><?php echo $name; ?></h2>
				<div>
					<p>
						<b>ID: </b> <?php echo $id ?><br>
						<b>surname: </b> <?php echo $surname ?><br>
					</p>
				</div>
			</div>
<?php
		}
	}
}
?>