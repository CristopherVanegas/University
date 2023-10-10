const ModoOscuro = () => {
    document.querySelector("body").setAttribute("data-bs-theme", "dark");
    document.querySelector("#dl-icon").setAttribute("class", "bi bi-sun-fill");

    const styleElement = document.createElement("style");
    styleElement.innerHTML = `
        .navbar-image {
            height: 450px;
            background-image: url('../Img/Header_Dark.jpg');
            background-size: cover;
            background-position: center;
        }
        body {
            background-color: black;
            color: white;
        }
        .carousel-caption h3,
        .carousel-caption p,
        .p-3.mb-3.bg-light.rounded h4,
        .p-3.mb-3.bg-light.rounded p {
            color: white;
        }
        col-lg-4.p{
            color: white;
        }
        .card-body, .text-muted, d-flex justify-content-between align-items-center{
            color: white;
        }
        .text-dark no-underline{
            color: white;
        }
    `;
    document.head.appendChild(styleElement);
}

const ModoClaro = () => {
    document.querySelector("body").setAttribute("data-bs-theme", "light");
    document.querySelector("#dl-icon").setAttribute("class", "bi bi-moon-fill");

    const styleElement = document.createElement("style");
    styleElement.innerHTML = `
        .navbar-image {
            height: 450px;
            background-image: url('../Img/Header_Light.png');
            background-size: cover;
            background-position: center;
        }
        body {
            background-color: white;
            color: black;
        }
        .carousel-caption h3,
        .carousel-caption p,
        .p-3.mb-3.bg-light.rounded h4,
        .p-3.mb-3.bg-light.rounded p {
            color: black;
        }
        col-lg-4.p{
            color: black;
        }
        .card-body, .text-muted, d-flex justify-content-between align-items-center{
            color: black;
        }
        .text-dark no-underline{
            color: black;
        }
    `;
    document.head.appendChild(styleElement);
}

const CambiarTema = () => {
    const temaActual = document.querySelector("body").getAttribute("data-bs-theme");
    if (temaActual === "light") {
        ModoOscuro();
    } else {
        ModoClaro();
    }
}