#pragma once
#include "Software.h"
#include <iostream>
using namespace std;

class Seguridad : public Software{
    private:
        string malware;
    
    public:
        Seguridad(string nombre,string developer,int edad,int precio,string malware);
        string getMalware();
        void setMalware(string malware);
    
};

Seguridad :: Seguridad(string nombre,string developer,int edad,int precio,string malware):Software(nombre,developer,edad,precio){
    this -> malware = malware;
};

string Seguridad::getMalware(){
    return this -> malware;
};

void Seguridad::setMalware(string malware){
    this -> malware = malware;
};