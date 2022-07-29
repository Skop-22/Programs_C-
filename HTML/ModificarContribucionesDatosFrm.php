<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
</head>
    <body>
        <?php require("menu.php"); ?>
        <h1>Contribuciones Datos</h1>
        <?php 
        $id_contribuyente=$_POST['ID_Contribuyente'];
        require("EnlaceBD.php");
        global $enlace;
        $sql2="SELECT * FROM contribuciones WHERE ID_Contribuyente='$id_contribuyente'";
        $resultadoContribuciones=@mysqli_query($enlace,$sql2);
        while ($contribucion = mysqli_fetch_array($resultadoContribuciones,MYSQLI_ASSOC)){
            $Folio=$contribucion['Folio'];
            $Fecha=$contribucion['Fecha'];
            $Periodo=$contribucion['Periodo'];
            $Cantidad=$contribucion['Cantidad'];
        }
        ?>
    <form class="" action="ModificarContribucionNuvadatos.php" method="post">
    <div class="mb-3">
    <label class="form-label" for="Folio">Folio</label>
    <select class="form-select" name="Folio" id="Folio">
            <option value="<?php echo $Folio;?>"><?php echo $Folio;?></option>
        </select>
    </div>
    <div class="mb-3">
    <label class="form-label" for="id_contribuyente">contribuyente</label>
    <select class="form-select" name="id_contribuyente" id="id_contribuyente">
            <option value="<?php echo $id_contribuyente;?>"><?php echo $id_contribuyente;?></option>
        </select>
    </div>
    <div class="mb-3">
        <label class="form-label" for="Fecha">Fecha</label>
        <input class="form-control" type="date" name="Fecha" id="Fecha" value="<?php echo $Fecha;?>">
    </div>
    <div class="mb-3">
        <label class="form-label" for="Perido">Mes de pago</label>
        <select class="form-select" class="" name="Periodo" id="Periodo">
            <option value="<?php echo $Periodo;?>"><?php echo $Periodo;?></option>
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
        <label class="form-label" for="Cantidad">Cantidad</label>
        <input class="form-control"  type="text" name="Cantidad" id="Cantidad" value="<?php echo $Cantidad;?>">
    </div>
    <input type="submit" name="guardar" value="Guardar" class="btn btn-dark">
    <input type="reset" name="limpiar" value="Limpiar" class="btn btn-dark">
    </form>
    </body>
</html>