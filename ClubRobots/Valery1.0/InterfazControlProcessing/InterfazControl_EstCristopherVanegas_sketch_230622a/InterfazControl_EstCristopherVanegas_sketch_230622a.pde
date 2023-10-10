boolean boton1Pulsado = false;
boolean boton2Pulsado = false;

void setup() {
  size(400, 200);
}

void draw() {
  background(255);
  
  // Dibujar botón 1
  fill(200);
  if (boton1Pulsado) {
    fill(100);
  }
  rect(50, 100, 100, 50);
  
  // Dibujar botón 2
  fill(200);
  if (boton2Pulsado) {
    fill(100);
  }
  rect(250, 100, 100, 50);
  
  // Agregar texto en los botones
  fill(255);
  textAlign(CENTER, CENTER);
  fill(0, 0, 0);
  textSize(16);
  text("W", 50, 100, 100, 50);
  text("S", 250, 100, 100, 50);
  
}

void keyPressed() {
  if (key == 'w' || key == 'W') {
    println("Adelante");
  }
  else if (key == 's' || key == 'S') {
    println("Atras");
  }
}

void mousePressed() {
  // Verificar si el mouse está dentro del área del botón 1
  if (mouseX >= 50 && mouseX <= 150 && mouseY >= 100 && mouseY <= 150) {
    boton1Pulsado = true;
    boton2Pulsado = false;
    println("Adelante");
  }
  
  // Verificar si el mouse está dentro del área del botón 2
  if (mouseX >= 250 && mouseX <= 350 && mouseY >= 100 && mouseY <= 150) {
    boton1Pulsado = false;
    boton2Pulsado = true;
    println("Atras");
  }
}
