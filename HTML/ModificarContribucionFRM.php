<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
    <body>
        <?php require("menu.php");  ?>
        <h1>Modificar Contribuciones</h1>
        <?php 
        require("EnlaceBD.php");
        global $enlace;
        $sql2="SELECT * FROM contribuciones ORDER BY ID_Contribuyente ASC";
        $resultadoContribuciones=@mysqli_query($enlace,$sql2);
        @$opcion="";
        while ($contribucion = mysqli_fetch_array($resultadoContribuciones,MYSQLI_ASSOC)){
            $opcion.="<option value=".$contribucion['ID_Contribuyente'].">".$contribucion['ID_Contribuyente']."</option>";
       }
       ?>
       <form class="" action="ModificarContribucionesDatosFrm.php" method="post">
       <div class="mb-3">
         <label class="form-label" for="ID_Contribuyente">Clave Del Contribuyente que Desea Modificar</label>
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