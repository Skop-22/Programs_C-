<!DOCTYPE html>
<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
<body>
    <?php 
        //programa en php
        $ID_Contribuyentes=$_POST['id_contribuyente'];//variable
        $Nombre=$_POST['nombre'];//variable
        $Direccion=$_POST['direccion'];//variable
        $Telefono=$_POST['telefono'];//variable
        require("EnlaceBD.php");
        global $enlace;

        /*
        echo "$ID_Contribuyentes $Nombre $Direccion $Telefono";
        var_dump($_POST);*/

        $sql="INSERT INTO contribuyentes (ID_Contribuyente,Nombre,Direccion,Telefono) VALUES('$ID_Contribuyentes','$Nombre','$Direccion','$Telefono')";
        $datos=@mysqli_query($enlace,$sql);
        $contribuyentes=array();
        if ($datos){
            echo "Datos guardados";
            $sqlContri="SELECT * FROM contribuyentes";
            $resultadosContribuyentes=@mysqli_query($enlace,$sqlContri);
            while ($contribuyente = mysqli_fetch_array($resultadosContribuyentes,MYSQLI_ASSOC)) {
                $contribuyentes[]=$contribuyente;
            }
            echo "
                <table>
                    <tr>
                        <th>Contribuyente</th>
                        <th>Nombre</th>
                        <th>Direccion</th>
                        <th>Telefono</th>
                    </tr>
            ";
            foreach ($contribuyentes as $contribuyente) {
                echo "<tr>";
                echo "<td>".$contribuyente['ID_Contribuyente']."</td>";
                echo "<td>".$contribuyente['Nombre']."</td>";
                echo "<td>".$contribuyente['Direccion']."</td>";
                echo "<td>".$contribuyente['Telefono']."</td>";
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