<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Nueva contribuci&oacute;n</title>
</head>
<body>
    <?php 
        $fecha=$_POST['fecha'];
        $periodo=$_POST['periodo'];
        $id_contribuyente=$_POST['id_contribuyente'];
        $cantidad=$_POST['cantidad'];
        require("EnlaceBD.php");
        global $enlace;
        $sq ="INSERT INTO contribuciones(Fecha,Periodo,ID_Contribuyente,Cantidad) VALUES('$fecha','$periodo','$id_contribuyente','$cantidad')";
        /*echo "Fecha=   ".$fecha."<br>";
        echo "Periodo= ".$periodo."<br>"; 
        echo "ID_Contribuyentes= ".$id_contribuyente."<br>";
        echo "Cantidad= ".$cantidad."<br>"."<br>"."<br>";*/
        $datos=@mysqli_query($enlace,$sq);
        $contribuciones=array();
        if($datos){
            echo "Datos guardados";
            $sql2="SELECT * FROM contribuciones";
            $resultadoContribuciones=@mysqli_query($enlace,$sql2);
            while ($contribucion = mysqli_fetch_array($resultadoContribuciones,MYSQLI_ASSOC)){
                $contribuciones[]=$contribucion;
            }
            echo "
            <table>
                <tr>
                    <th>Folio</th>
                    <th>Fecha</th>
                    <th>Periodo</th>
                    <th>Contribuyente</th>
                    <th>Cantidad</th>
                </tr>
            ";
            foreach ($contribuciones as $renglon){
                echo "<tr>";
                echo "<td>".$renglon['Folio']."</td>";
                echo "<td>".$renglon['Fecha']."</td>";
                echo "<td>".$renglon['Periodo']."</td>";
                echo "<td>".$renglon['ID_Contribuyente']."</td>";
                echo "<td>".$renglon['Cantidad']."</td>";
                echo "</tr>";
            }
            echo "</table>";
        }else{
            echo "Por alguna razon no se guardaron los datos";
        }
        @mysqli_close($enlace);
    ?>
</body>
</html>