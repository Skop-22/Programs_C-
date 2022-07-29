<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
    <body>
        <?php require("menu.php"); ?>
        <h1>Modificar Contribucion</h1>
        <?php 
            $folio=$_POST['Folio'];
            $ID_Contribuyente=$_POST['id_contribuyente'];
            $Fecha=$_POST['Fecha'];
            $Periodo=$_POST['Periodo'];
            $Cantidad=$_POST['Cantidad'];
            require("EnlaceBD.php");
            global $enlace;
            /*echo "Folio= ".$folio."<br>";
            echo "ID_Contribuyente= ".$ID_Contribuyente."<br>";
            echo "Fecha=   ".$Fecha."<br>";
            echo "Periodo= ".$Periodo."<br>";
            echo "Cantidad= ".$Cantidad."<br>"."<br>"."<br>";*/
            $sql="UPDATE contribuciones SET Fecha='$Fecha', Periodo='$Periodo', Cantidad='$Cantidad' WHERE Folio='$folio'";
            $datos=@mysqli_query($enlace,$sql);
            $Contribucione=array();
            if ($datos) {
                $sqlContri="SELECT * FROM contribuciones";
                $resultadoContribuciones=@mysqli_query($enlace,$sqlContri);
                while ($Contribuciones = mysqli_fetch_array($resultadoContribuciones,MYSQLI_ASSOC)) {
                  $Contribucione[]=$Contribuciones;
                }
                echo "
                    <table class='table table-hover'>
                        <tr class='table-dark'>
                            <th>Folio</th>
                            <th>ID_Contribuyente</th>
                            <th>Fecha</th>
                            <th>Periodo</th>
                            <th>Cantidad</th>
                        </tr>
                ";
                foreach ($Contribucione as $Contribuciones) {
                    echo "<tr class='table-light'>";
                    echo "<td>".$Contribuciones['Folio']."</td>";
                    echo "<td>".$Contribuciones['ID_Contribuyente']."</td>";
                    echo "<td>".$Contribuciones['Fecha']."</td>";
                    echo "<td>".$Contribuciones['Periodo']."</td>";
                    echo "<td>".$Contribuciones['Cantidad']."</td>";
                    echo "<tr>";
                }
                echo "</table>";
              }else {
            echo "Por alguna razon no se guardaron los datos";
            }
            mysqli_close($enlace);
        ?>
    </body>
</html>