#pragma once
#include "Software.h"
#include <iostream>
using namespace std;

class Juego : public Software{
    private:
        string genero;
    
    public:
        Juego(string nombre,string developer,int edad,int precio,string genero);
        string getGenero();
        void setGenero(string genero);
    
};


Juego :: Juego(string nombre,string developer,int edad,int precio,string genero):Software(nombre,developer,edad,precio){
    this -> genero = genero;
};

string Juego::getGenero(){
    return this -> genero;
};

void Juego::setGenero(string genero){
    this -> genero = genero;
};