<?php

require_once 'config.php';

$users = [];

$sql = 'SELECT * FROM usuarios';
$stmt = $pdo->query($sql);

while ($row = $stmt->fetch()) {
    $users[] = $row;
}

echo json_encode($users);
