<!DOCTYPE html>
<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
<body>
    <?php require("menu.php"); ?>
    <h1>Reporte de contribuyentes</h1>
    <?php
    require("EnlaceBD.php");
    global $enlace;
    $sqlContri="SELECT * FROM contribuyentes";
    $resultadoContribuyentes=@mysqli_query($enlace,$sqlContri);
    while ($contribuyente = mysqli_fetch_array($resultadoContribuyentes,MYSQLI_ASSOC)) {
    $contribuyentes[]=$contribuyente;
    }
    echo "
    <table class='table table-hover'>
        <tr class='table-dark'>
        <th>Contribuyente</th>
        <th>Nombre</th>
        <th>Direcci&oacute;n</th>
        <th>Tel&eacute;fono</th>
        </tr>
    ";
    foreach ($contribuyentes as $contribuyente) {
        echo "<tr class='table-light'>";
        echo "<td>".$contribuyente['ID_Contribuyente']."</td>";
        echo "<td>".$contribuyente['Nombre']."</td>";
        echo "<td>".$contribuyente['Direccion']."</td>";
        echo "<td>".$contribuyente['Telefono']."</td>";
        echo "<tr>";
    }
    echo "</table>";
    ?>
</body>
</html>