#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
//matriz de 3 dimensiones, 1 ciudad, sucursales, meses del año, llenar con un objeto, rango de valor de ventas
//nombre del cliente es al rango, crear un arreglo, donde se pondran 10 nombres, crear otro arreglo donde se pongan productos
//todo esto se hara mediante un rango
//clientes que mas compran por ciudad, producto mas solicitado por ciudad,(producto mas vendido en todo el ecuador este se hace en casa)
using namespace std;
int tiend[6][5][12];
string client[]={"HUGO","IVAN","PABLO","LUCAS","GEORGE","JOSE","JORGE","LUIS","ERNES","CRISTHIAN"};
string prod[]={"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10"};
string sucursal[]={"s1","s2","s3","s4","s5"};
string mes[]={"ENERO","FEBRERO","MAZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
int vent[10];
int sumac[6],sumas[5],sumam[12];
string ciudad[]={"GUAYAQUIL","CUENCA","QUITO","PLAYAS","MANTA","AMBATO"};
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}
int rell(){
    srand(time(NULL));
   for(int a=0;a<10;a++){
       vent[a]=rand()%200;
   }
   for(int c=0;c<6;c++){
       gotoxy(0,c*32);cout<<ciudad[c];
    for(int s=0;s<5;s++){
             gotoxy((s*8)+13,3);cout<<sucursal[s];
        for(int m=0;m<12;m++){
            gotoxy(0,(m*2)+5);cout<<mes[m];
                tiend[c][s][m]=500+rand()%6000;
                gotoxy((s*8)+12,(m*2)+5);cout<<tiend[c][s][m];
        }
    }
}

  for(int c=0;c<6;c++){
        sumac[c]=0;
    for(int s=0;s<5;s++){
            sumas[s]=0;
        for(int m=0;m<12;m++){
                sumam[m]=0;
                sumac[c]=sumac[c]+tiend[c][s][m];
                sumas[s]=sumas[s]+tiend[c][s][m];
                sumam[m]=sumam[m]+tiend[c][s][m];
        }
    }

}
}

void may(){
    rell();
    cout<<endl;
    int ciu=sumac[0];
    string mac=ciudad[0];
    for(int c=0;c<6;c++){
        if(ciu<sumac[c]){
            ciu=sumac[c];
            sumac[c]=ciu;
            mac=ciudad[c];
            ciudad[c]=mac;
        }
        else{
            ciu=ciu;
            sumac[c]=sumac[c];
            mac=mac;
            ciudad[c]=ciudad[c];
        }
    }

    cout<<"venta mayor: "<<ciu<<" pertenece a la ciudad: "<< mac<<endl;
    int suc=sumas[0];
    string mas=sucursal[0];
    for(int s=0;s<5;s++){
        if(suc<sumas[s]){
            suc=sumas[s];
            sumas[s]=suc;
            mas=sucursal[s];
            sucursal[s]=mas;
        }
        else{
            suc=suc;
            sumas[s]=sumas[s];
            mas=mas;
            sucursal[s]=sucursal[s];
        }
    }

    cout<<"venta mayor: "<<suc<<" pertenece a la sucursal: "<< mas<<endl;
     int me=sumam[0];
    string mam=mes[0];
    for(int m=0;m<12;m++){
        if(suc<sumas[m]){
            me=sumam[m];
            sumam[m]=me;
            mam=mes[m];
            mes[m]=mam;
        }
        else{
            me=me;
            sumam[m]=sumam[m];
            mam=mam;
            mes[m]=mes[m];
        }
    }

    cout<<"venta general de la ciudad: "<<me<<" pertenece al mes: "<< mam<<endl;
}



int main()
{
    may();
    return 0;
}
