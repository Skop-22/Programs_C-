<!DOCTYPE html>
<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
<body>
    <?php require("menu.php"); ?>
        <h1>Reporte de contribuciones</h1>
        <?php
        require("EnlaceBD.php");
        global $enlace;
        $sql2="SELECT * FROM contribuciones ORDER BY folio DESC";
        $resultadoContribuciones=@mysqli_query($enlace,$sql2);
        while ($contribucion = mysqli_fetch_array($resultadoContribuciones,MYSQLI_ASSOC)) {
        $contribuciones[]=$contribucion;
        }
        echo "
            <table class='table table-hover'>
            <tr class='table-dark'>
            <th>Folio</th>
            <th>Fecha</th>
            <th>Periodo</th>
            <th>Contribuyente</th>
            <th>Cantidad</th>
            </tr>
        ";
        foreach ($contribuciones as $renglon) {
            echo "<tr class='table-light'>";
            echo "<td>".$renglon['Folio']."</td>";
            echo "<td>".$renglon['Fecha']."</td>";
            echo "<td>".$renglon['Periodo']."</td>";
            echo "<td>".$renglon['ID_Contribuyente']."</td>";
            echo "<td>".$renglon['Cantidad']."</td>";
            echo "</tr>";
        }
        echo "</table>";
        @mysqli_close($enlace);
    ?>
</body>
</html>