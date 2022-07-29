<!DOCTYPE html>
<html lang="en">
<head>
    <?php require("cabeceras.php"); ?>
    <title></title>
</head>
<body>
<?php require("menu.php"); ?>
    <h1>Nuevo Contribuyente</h1>
    <form class="" action="NuevoContribuyenteDatos.php"method="post">
    <div class="mb-3">
        <label class="form-label" for="id_contribuyente">Clave de Contribuyente</label>
        <input class="form-control" type="text" name="id_contribuyente" id="id_contribuyente">
    </div>
    <div class="mb-3">
        <label for="nombre" class="form-label">Nombre</label>
        <input class="form-control" type="text"  name="nombre" id="nombre">
    </div>
    <div class="mb-3">
        <label for="direccion" class="form-label">Direccion</label>
        <textarea class="form-control" name="direccion" id="direccion" cols="50" rows="8"></textarea>
    </div>
    <div class="mb-3">
        <label for="telefono" class="form-label">Telefono</label>
        <input class="form-control" type="text" name="telefono" id="telefono">
    </div class="mb-3">
    <input type="submit" name="guardar" value="Guardar" class="btn btn-dark">
    <input type="reset" name="limpiar" value="Limpiar" class="btn btn-dark">
    </form>
</body>
</html>