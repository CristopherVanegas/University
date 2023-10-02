#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    int codigo;
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    int edad;
    bool trabaja;
    float sueldo;
    int animo;
    int familia;
    bool sexo;
    int posx;
    int posy;
    bool casado;
    int sangre; //0,2,4,6 positivos      1,3,5,7 negativo
    bool vivo;
    bool revivido;
    bool hijo;
    string posicion;


public:
    void setCodigo(int valor) {
        codigo = valor;
    }
    int getCodigo()
    {
        return codigo;
    }

    void setNombre1(string valor) {
        nombre1 = valor;
    }
    string getNombre1()
    {
        return nombre1;
    }

    void setNombre2(string valor) {
        nombre2 = valor;
    }
    string getNombre2()
    {
        return nombre2;
    }

    void setApellido1(string valor) {
        apellido1 = valor;
    }
    string getApellido1()
    {
        return apellido1;
    }

    void setApellido2(string valor) {
        apellido2 = valor;
    }
    string getApellido2()
    {
        return apellido2;
    }

    void setEdad(int valor) {
        edad = valor;
    }
    int getEdad()
    {
        return edad;
    }

    void setTrabaja(bool valor) {
        trabaja = valor;
    }
    bool getTrabaja()
    {
        return trabaja;
    }

    void setSueldo(float valor) {
        sueldo = valor;
    }
    float getSueldo()
    {
        return sueldo;
    }

    void setAnimo(int valor) {
        animo = valor;
    }
    int getAnimo()
    {
        return animo;
    }

    void setSexo(bool valor) {
        sexo = valor;
    }
    bool getSexo()
    {
        return sexo;
    }
    void setHijo(bool valor) {
        hijo = valor;
    }
    bool getHijo()
    {
        return hijo;
    }

    void setPosx(int valor) {
        posx = valor;
    }
    int getPosx()
    {
        return posx;
    }

    void setPosy(int valor) {
        posy = valor;
    }
    int getPosy()
    {
        return posy;
    }

    void setCasado(bool valor) {
        casado = valor;
    }
    bool getCasado()
    {
        return casado;
    }

    void setSangre(int valor) {
        sangre = valor;
    }
    int getSangre()
    {
        return sangre;
    }

    void setFamilia(int valor) {
        familia = valor;
    }
    int getFamilia()
    {
        return familia;
    }

    void setVivo(bool valor) {
        vivo = valor;
    }
    bool getVivo()
    {
        return vivo;
    }

    void setRevivido(bool valor) {
        revivido = valor;
    }
    bool getRevivido()
    {
        return revivido;
    }

    void setPosicion(string valor) {
        posicion = valor;
    }
    string getPosicion()
    {
        return posicion;
    }


};