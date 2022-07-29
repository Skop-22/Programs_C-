<?php 
    echo '
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark" >
  <div class="container-fluid">
    <a class="navbar-brand" href="index.php">Principal</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
            Contribuciones
          </a>
          <ul class="dropdown-menu" aria-labelledby="navbarDropdown">
            <li><a class="dropdown-item" href="ContribucionNuevaFRM.php">Nuevo</a></li>
            <li><a class="dropdown-item" href="ModificarContribucionFRM.php">Modificar</a></li>
            <li><hr class="dropdown-divider"></li>
            <li><a class="dropdown-item" href="reportContribuciones.php">Reporte</a></li>
          </ul>
        </li>
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdow" role="button" data-bs-toggle="dropdown" aria-expanded="false">
            contribuyentes
          </a>
          <ul class="dropdown-menu" aria-labelledby="navbarDropdow">
            <li><a class="dropdown-item" href="contribuyenteNuevoFrm.php">Nuevo</a></li>
            <li><a class="dropdown-item" href="ModificarContribuyenteFRM.php">Modificar</a></li>
            <li><hr class="dropdown-divider"></li>
            <li><a class="dropdown-item" href="reporteContribuyentes.php">Reporte</a></li>
          </ul>
        </li>
      </ul>
    </div>
  </div>
</nav>';
?>