#pragma once
#include <iostream>
#include "Software.h"

using namespace std;


class Ofimatica:public Software{
    private:
        int archivos;
    
    public:
        Ofimatica(string nombre,string developer,int edad,int precio,int archivos);
        
        int getArchivos();
        void agregarArchivo();
        
};

Ofimatica::Ofimatica(string nombre,string developer,int edad,int precio,int archivos):Software(nombre,developer,edad,precio){
    this -> archivos = archivos;
};

int Ofimatica::getArchivos(){
    return this -> archivos;
};

void Ofimatica::agregarArchivo(){
    this -> archivos += 1;
};