<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <?php require("cabeceras.php"); ?>
  </head>
  <body>
    <?php require("menu.php"); ?>
    <h1>Modificar contribuyente</h1>
    <?php
      $id_contribuyente=$_POST['id_contribuyente'];
      $id_contribuyenteNuevo=$_POST['id_contribuyenteNuevo'];
      $nombre=$_POST['nombre'];
      $direccion=$_POST['direccion'];
      $telefono=$_POST['telefono'];
      require("EnlaceBD.php");
      global $enlace;
      //echo $id_contribuyente." ".$id_contribuyenteNuevo." ".$nombre." ".$direccion." ".$telefono."<br>";
      $sql="UPDATE contribuyentes
            SET ID_Contribuyente='$id_contribuyenteNuevo', Nombre='$nombre', Direccion='$direccion', Telefono='$telefono'
            WHERE ID_Contribuyente='$id_contribuyente'";
      $datos=@mysqli_query($enlace,$sql);
      $contribuyentes=array();
      if ($datos) {
        $sqlContri="SELECT * FROM contribuyentes";
        $resultadoContribuyentes=@mysqli_query($enlace,$sqlContri);
        while ($contribuyente = mysqli_fetch_array($resultadoContribuyentes,MYSQLI_ASSOC)) {
          $contribuyentes[]=$contribuyente;
        }
        echo "
          <table class='table table-hover'>
            <tr class='table-dark'>
              <th>Contribuyente</th>
              <th>Nombree</th>
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
      }else {
        echo "Por alguna razon no se guardaron los datos";
      }
      mysqli_close($enlace);
    ?>
  </body>
</html>