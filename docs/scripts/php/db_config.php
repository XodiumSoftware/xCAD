<?php
$host = "your_host";
$username = "your_db_username";
$password = "your_db_password";
$db_name = "your_db_name";

$conn = mysqli_connect($host, $username, $password, $db_name);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>