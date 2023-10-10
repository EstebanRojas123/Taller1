#pragma once
#include "Software.h"
#include <iostream>
using namespace std;

class Produccion : public Software{
    private:
        string tipo;
    
    public:
        Produccion(string nombre,string developer,int edad,int precio,string tipo);
        string getTipo();
        void setTipo(string genero);
    
};

Produccion :: Produccion(string nombre,string developer,int edad,int precio,string tipo):Software(nombre,developer,edad,precio){
    this -> tipo = tipo;
};

string Produccion::getTipo(){
    return this -> tipo;
};

void Produccion::setTipo(string tipo){
    this -> tipo = tipo;
};
