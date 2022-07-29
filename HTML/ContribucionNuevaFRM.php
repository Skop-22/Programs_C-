<!DOCTYPE html>
<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
    <title>Nueva contribuci&oacute;n</title>
</head>
<body>
<?php require("menu.php"); ?>
    <h1>Nueva contribuci&oacute;n</h1>
    <?php
        require("EnlaceBD.php");
        global $enlace;
        $sqlContribuyentes="SELECT * FROM contribuyentes ORDER BY nombre ASC";
        $resultadoContribuyentes=@mysqli_query($enlace,$sqlContribuyentes);
        @$opcion="";
        while ($contribuyente = @mysqli_fetch_array($resultadoContribuyentes,MYSQLI_ASSOC)) {
            $opcion.="<option value=".$contribuyente['ID_Contribuyente'].">".$contribuyente['Nombre']."</option>";//opcionde de concatenacion
        }
    ?>
    <form class="" action="ContribucionesNuvadatos.php" method="post">
    <div class="mb-3">
        <label class="form-label" for="fecha">Fecha</label>
        <input class="form-control" type="date" name="fecha" id="fecha" value="">
    </div>
    <div class="mb-3">
        <label class="form-label" for="periodo">Mes de pago</label>
        <select class="form-select" class="" name="periodo" id="periodo">
            <option value="enero">Enero</option>
            <option value="febrero">Febrero</option>
            <option value="marso">Marso</option>
            <option value="abril">Abril</option>
            <option value="mayo">Mayo</option>
            <option value="junio">Junio</option>
            <option value="julio">Julio</option>
            <option value="agosto">Agosto</option>
            <option value="septiembre">Septiembre</option>
            <option value="octubre">Octubre</option>
            <option value="nobiembre">Nobiembre</option>
            <option value="diciembre">Diciembre</option>
        </select>
    </div>
    <div class="mb-3">
        <label class="form-label" for="id_contribuyente">contribuyente</label>
        <!--<input type="text" name="id_contribuyente" id="id_contribuyente" value=""><br>-->
        <select class="form-select" name="id_contribuyente" id="id_contribuyente">
            <option value=""></option>
            <?php echo $opcion;?>
        </select>
    </div>
    <div class="mb-3">
        <label class="form-label" for="cantidad">Cantidad</label>
        <input class="form-control"  type="text" name="cantidad" id="cantidad" value=""><br>
    </div>
    <input type="submit" name="guardar" value="Guardar" class="btn btn-dark">
    <input type="reset" name="limpiar" value="Limpiar" class="btn btn-dark">
    </form>
</body>
</html>