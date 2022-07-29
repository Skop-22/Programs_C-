<?php
    //mysqli_conect srive para conectar un servidor 
    //mariadb o mysql y a una base de datos del mismo
    $enlace=mysqli_connect("localhost","root","","ico6");
    if(!$enlace){
        die("Error de conexion");
    }
?>