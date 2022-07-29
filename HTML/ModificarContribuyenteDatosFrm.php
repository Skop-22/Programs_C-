<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <?php require("cabeceras.php"); ?>
  </head>
  <body>
    <?php require("menu.php"); ?>
    <h1>Modificar contribuyente</h1>
    <?php
      $id_contribuyente=$_POST['ID_Contribuyente'];
      require("EnlaceBD.php");
      global $enlace;
      $sqlContribuyentes="SELECT * FROM contribuyentes WHERE ID_Contribuyente='$id_contribuyente'";
      $resultadoContribuyentes=@mysqli_query($enlace,$sqlContribuyentes);
      while ($contribuyente = @mysqli_fetch_array($resultadoContribuyentes,MYSQLI_ASSOC)) {
        $id_contribuyenteActual=$contribuyente['ID_Contribuyente'];
        $nombre=$contribuyente['Nombre'];
        $direccion=$contribuyente['Direccion'];
        $telefono=$contribuyente['Telefono'];
      }
     ?>
     <form class="" action="modifiarContribuyenteDatos.php" method="post">
       <div class="mb-3">
         <label class="form-label" for="id_contribuyenteNuevo">Clave de contribuyente</label>
         <input class="form-control" type="text" name="id_contribuyenteNuevo" id="id_contribuyenteNuevo" value="<?php echo $id_contribuyenteActual; ?>" >
       </div>
       <div class="mb-3">
         <label class="form-label" for="nombre">Nombre</label>
         <input class="form-control" type="text" name="nombre" id="nombre" value="<?php echo $nombre; ?>">
       </div>
       <div class="mb-3">
         <label class="form-label" for="direccion">Direcci&oacute;n</label>
         <textarea class="form-control" name="direccion" id="direccion" rows="4"><?php echo $direccion; ?></textarea>
       </div>
       <div class="mb-3">
         <label class="form-label" for="telefono">Tel&eacute;fono</label>
         <input class="form-control" type="text" name="telefono" id="telefono" value="<?php echo $telefono; ?>">
       </div>
       <input type="hidden" name="id_contribuyente" value="<?php echo $id_contribuyente; ?>">
       <input type="submit" name="guardar" value="Guardar" class="btn btn-dark">
       <input type="reset" name="limpiar" value="Limpiar" class="btn btn-dark">
     </form>
  </body>
</html>