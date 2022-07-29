<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
    <body>
        <?php require("menu.php"); ?>
        <h1>Modificar Contribuyente</h1>
        <?php
        require("EnlaceBD.php");
        global $enlace;
        $sqlContribuyentes="SELECT * FROM contribuyentes ORDER BY Nombre ASC";
        $resultadoContribuyentes=@mysqli_query($enlace,$sqlContribuyentes);
        @$opcion="";
        while ($contribuyente = @mysqli_fetch_array($resultadoContribuyentes,MYSQLI_ASSOC)) {
            $opcion.="<option value=".$contribuyente['ID_Contribuyente'].">".$contribuyente['Nombre']."</option>";
      }
     ?>
     <form class="" action="ModificarContribuyenteDatosFrm.php" method="post">
       <div class="mb-3">
         <label class="form-label" for="ID_Contribuyente">Contribuyente</label>
         <!--<input type="text" name="id_contribuyente" id="id_contribuyente" value=""><br>-->
         <select class="form-select" name="ID_Contribuyente" id="ID_Contribuyente">
           <option value=""></option>
           <?php echo $opcion; ?>
         </select>
       </div>
        <input type="submit" name="modificar" value="Modificar" class="btn btn-dark">
        <input type="reset" name="limpiar" value="Limpiar" class="btn btn-dark">
     </form>
    </body>
</html>