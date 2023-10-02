#include <iostream>
#include "Persona.cpp"
#include <cstdlib>
#include <windows.h>//gotoxy

#include <sstream>
#include <fstream> //archivo escritura
#define NOMBRE_ARCHIVO "Libro1.csv"

using namespace std;

int x=0, y=0;
int menuvar, servidor, cposicion=0, booleano, contador=0, caso=1, conthijo=0, sangreM, sangreH, respuesta, indiceH, indiceM, diferenciaE, contfamilia=0, familia=0, aux=0;
string nom1, nom2, apel1, apel2, posicion;
Persona objpersona;
Persona cosos[500];//personas

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

/*
//IMPRESION CLIENTE / SERVIDOR
void servidor_cliente() {
    gotoxy(0, 0); cout << "----Hecho por Tiffany Jordan----";
        gotoxy(0, 1); cout << "------------Menu-----------";
        gotoxy(0, 2); cout << "Seleccione:";
        gotoxy(0, 3); cout << "1) Cliente";
        gotoxy(0, 4); cout << "2) Servidor";
        gotoxy(0, 5); cin >> servidor;
        while (servidor > 2 || servidor <= 0) {
            gotoxy(0, 5); cout<<"          ";
            gotoxy(0, 6); cin >> servidor;
        }
        system("cls");
}*/


//Menu crear primer grupo
void menuprimer() {
    //Menu se debe presentar debajo de la presentacion de los cosos
    gotoxy(0, 0); cout << "------------Menu-----------";
    gotoxy(0, 1); cout << "0) Creacion de Primer Grupo (Valido solo una vez)";
    gotoxy(0, 2); cout << "***Seleccione la opcion***";
    gotoxy(0, 3); cin >> menuvar;
    while (menuvar !=0) {
        gotoxy(0, 3); cout << "               ";
        gotoxy(0, 3); cin >> menuvar;
    }
}

void bucleposicion() {
        do {
            caso = 0;
            posicion = to_string(x) + to_string(y);

            for (int i = 0; i <= (contador-1); i++) {
                if (cosos[i].getPosicion() == posicion) {
                    caso++;
                }
            }
            if (caso == 0) {
                objpersona.setPosx(x);
                objpersona.setPosy(y);
                posicion = to_string(x) + to_string(y);
                objpersona.setPosicion(posicion);
            }
            if (caso != 0) {
                x = rand() % 100;
                y = rand() % 10;
            }
        } while (caso != 0);
}
void creacionprimergrupo() {

    setlocale(LC_CTYPE, "Spanish");

    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ';';
   

    for (int i = 0; i < 100; i++) {
        objpersona.setCodigo(contador);
        contador++;

        //leemos todas las lineas
        getline(archivo, linea);
        stringstream stream(linea);

        //Extrar todos los valores
        getline(stream, nom1, delimitador);
        getline(stream, nom2, delimitador);
        getline(stream, apel1, delimitador);
        getline(stream, apel2, delimitador);

        objpersona.setFamilia(0);
        objpersona.setHijo(1);//si son hijos se pueden unir
        objpersona.setNombre1(nom1);
        objpersona.setNombre2(nom2);
        objpersona.setApellido1(apel1);
        objpersona.setApellido2(apel2);
        objpersona.setEdad(18+rand()%23);

        booleano = rand() % 2;
        objpersona.setTrabaja(booleano);

        //Sueldo
        if (booleano == 1) {
            objpersona.setSueldo(float(10000+rand()%10000000)/100);
        }
        if (booleano == 0) {
            objpersona.setSueldo(0);
        }

        objpersona.setAnimo(0+rand()%5);
        objpersona.setSexo(rand()%2); //0 hombre 1-mujer

        x = rand() % 100;
        y = rand() % 10;

        objpersona.setCasado(0);
        objpersona.setSangre(rand()%8);
        objpersona.setVivo(1);
        objpersona.setRevivido(0);

        if (cposicion==0) {
            objpersona.setPosx(x);
            objpersona.setPosy(y);
            posicion = to_string(x) + to_string(y);
            objpersona.setPosicion(posicion);
            cposicion = 1;
        }
        if (cposicion >= 2) {
            bucleposicion();

        }
        cposicion++;
        cosos[i] = objpersona;
    }
    archivo.close();
    contador = contador - 1;
}

void presentacionmenu() {
    system("cls");
    for (int i = 0; i < 100; i++) {
        x = cosos[i].getPosx(); 
        y = cosos[i].getPosy();
        gotoxy(x, y); cout<<"*";
    }
}

void creacionhijo(int familia) {//hijo - 1
        contador++;
        objpersona.setCodigo(contador);
        objpersona.setFamilia(familia);
        objpersona.setEdad(1);
        objpersona.setTrabaja(0);
        objpersona.setSueldo(0);
        objpersona.setAnimo(0 + rand() % 5);

        booleano = rand() % 2;
        objpersona.setSexo(booleano); //0 hombre 1-mujer
        /*
        if (booleano==0) {//hombre
        
        }
       
        if (booleano==0) {//mujer

        }*/

        //nombres
        /*
        objpersona.setNombre1(cosos[j].getSangre());
        objpersona.setNombre2(cosos[j].getSangre());
        objpersona.setApellido1(apel1);
        objpersona.setApellido2(apel2);*/

        x = rand() % 100;
        y = rand() % 10;
        bucleposicion();

        objpersona.setCasado(0);
        objpersona.setSangre(rand() % 8);
        objpersona.setVivo(1);
        objpersona.setHijo(1);
        objpersona.setRevivido(0);

        cosos[contador] = objpersona;
    }
    

void hijos() {
    //familia sigue indefinidamente
    indiceM = 0;
    indiceH = 0;
    for (int i = 1; i <= familia; i++) {
        for (int j = 0; j <= contador; j++) {
            //Mujer
            if ((cosos[j].getFamilia() == familia) && (cosos[j].getFamilia() !=0) && (cosos[j].getSexo() == 1) && (cosos[j].getCasado() == 1)) {
                sangreM= cosos[j].getSangre();
                indiceM = j;

            }
            //Hombre
            if ((cosos[j].getFamilia() == familia) && (cosos[j].getFamilia() != 0) && (cosos[j].getSexo() == 0) && (cosos[j].getCasado() == 1)) {
                sangreH = cosos[j].getSangre();
                indiceH = j;

            }

            //0,2,4,6 positivos      1,3,5,7 negativo
            //MUJERES
            if (sangreM==0 || sangreM == 2 || sangreM == 4 || sangreM == 6 ) {
                sangreM = 1; //positivo
            }
            if (sangreM == 1 || sangreM == 3 || sangreM == 5 || sangreM == 7) {
                sangreM = 0; //negativo
            }

            //HOMBRES
            if (sangreH == 0 || sangreH == 2 || sangreH == 4 || sangreH == 6) {
                sangreH = 1;//positivo
            }
            if (sangreH == 1 || sangreH == 3 || sangreH == 5 || sangreH == 7) {
                sangreH = 0;//negativo
            }

            if ((sangreM==sangreH) && (cosos[indiceM].getFamilia()== cosos[indiceH].getFamilia())) {
                creacionhijo(familia);
                conthijo++;
            }
        }
    }


    conthijo = 0;
    //misma familia
    //hijo
    // ambos sangre positiva o negativas
    // si nino nombre de padre
    // si nina nombre de madre
    // apellido del padre, segundo apellido de la madre
    // cuanto hijos nacieron
    // y se debe generar los datos.....
    //presentacionmenu();
    //menu();
}

void covid() {


    //presentacionmenu();
    //menu();
}

void destruccion() {


    //presentacionmenu();
    //menu();
}

void lucha() {


    //presentacionmenu();
    //menu();
}

void tiempo() {


    //presentacionmenu();
    //menu();
}

void resucitar() {


    //presentacionmenu();
    //menu();
}

void cine() {


    //presentacionmenu();
    //menu();
}

void identificacion() {


    //presentacionmenu();
    //menu();
}


void generarparejas() {
    //Puse el minimo de edad para casarse de 18
    for (int i = 0; i <= contador; i++) {//Mujeres
        if ((cosos[i].getVivo() == 1) && (cosos[i].getCasado() == 0) && (cosos[i].getSexo() == 1) && (cosos[i].getFamilia() == 0) && (cosos[i].getEdad() >= 18) && (cosos[i].getHijo() == 1)) {
            indiceM = i;

            for (int j = 0; j <= contador; j++) {//Hombres
                if ((cosos[i].getVivo() == 1) && (cosos[j].getCasado() == 0) && (cosos[j].getSexo() == 0) && (cosos[j].getFamilia() == 0) && (cosos[indiceM].getFamilia() == 0) && (cosos[j].getEdad() >= 18) && (cosos[j].getHijo() == 1)) {
                    if (cosos[j].getSueldo() >= cosos[i].getSueldo()) {//sueldo
                        diferenciaE = (cosos[j].getEdad() - cosos[i].getEdad());
                        if (diferenciaE >= 5) {
                            indiceH = j;

                            familia++;
                            contfamilia++;
                            cosos[indiceM].setCasado(1);
                            cosos[indiceM].setFamilia(familia);
                            cosos[indiceH].setFamilia(familia);
                            cosos[indiceH].setCasado(1);

                        }
                    }
                }
            }
        }
    }
    //diferencia de 5 , mayor el macho
    //el sueldo debe ser mayor que el de la hembra
    //escribir cuantas parejas se emparejaron
    gotoxy(45, 11); cout << "***Se han creado " << contfamilia << " familias";
    contfamilia = 0;
}

void decisiones(int menuvar) {
    if (menuvar == 1) {
        generarparejas();
    }
    if (menuvar == 2) {
        hijos();
    }
    if (menuvar == 3) {
        covid();
    }
    if (menuvar == 4) {
        destruccion();
    }
    if (menuvar == 5) {
        lucha();
    }
    if (menuvar == 6) {
        tiempo();
    }
    if (menuvar == 7) {
        resucitar();
    }
    if (menuvar == 8) {
        cine();
    }
    if (menuvar == 9) {
        identificacion();
    }
}
void vueltapregunta() {
    gotoxy(45, 12); cout << "Quieres volver al menu?";
    gotoxy(45, 13); cout << "1) Si";
    gotoxy(45, 14); cout << "2) No";
    gotoxy(45, 15); cin >> respuesta;
    if (respuesta == 1) {
        gotoxy(45, 15); cout << "                               ";
        gotoxy(45, 12); cout << "                               ";
        gotoxy(45, 13); cout << "                 ";
        gotoxy(45, 14); cout << "             ";
        gotoxy(45, 11); cout << "                                     ";
        gotoxy(0, 22); cout << "               ";
        gotoxy(0, 22); cin >> menuvar;
        while (menuvar >= 10 || menuvar <= 0) {
            gotoxy(0, 22); cout << "               ";
            gotoxy(0, 22); cin >> menuvar;
        }
        decisiones(menuvar);
    }

}
//Menu 
void menu() {
    //Menu se debe presentar debajo de la presentacion de los cosos
    gotoxy(0, 11); cout << "------------Menu-----------";
    gotoxy(0, 12); cout << "1) Generar parejas";
    gotoxy(0, 13); cout << "2) Generar hijos";
    gotoxy(0, 14); cout << "3) Enfermedad covid";
    gotoxy(0, 15); cout << "4) Destruccion global";
    gotoxy(0, 16); cout << "5) Lucha del mas fuerte";
    gotoxy(0, 17); cout << "6) Avance de tiempo";
    gotoxy(0, 18); cout << "7) Resucitar";
    gotoxy(0, 19); cout << "8) Ir al cine";
    gotoxy(0, 20); cout << "9) Identificacion y reporte";
    gotoxy(0, 21); cout << "***Seleccione una opcion***";
    gotoxy(0, 22); cin >> menuvar;
    while (menuvar >= 10 || menuvar <= 0) {
        gotoxy(0, 22); cout << "               ";
        gotoxy(0, 22); cin >> menuvar;
    }
    decisiones(menuvar);

}


int main()
{
    srand(time(NULL));
    menuprimer();
    creacionprimergrupo();
    presentacionmenu();
    menu();
    vueltapregunta();


    /*
        for (int i = 0; i < 100; i++) {
            if (cosos[i].getFamilia()!=0) {
                aux++;
            }
        
    }*/
        //gotoxy(45, 12); cout << "***Se han creado "<<aux;
        
        return 0;
}
