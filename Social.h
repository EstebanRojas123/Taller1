#pragma once
#include "Software.h"
#include <iostream>
#include "Usuario.h"
#include <vector>
using namespace std;

class Social : public Software{
    private:
        vector<Usuario>amigos;
        
    
    public:
        Social(string nombre,string developer,int edad,int precio);
        vector<Usuario>getAmigos();
        
        
};

Social :: Social(string nombre,string developer,int edad,int precio):Software(nombre,developer,edad,precio){};

vector<Usuario> Social::getAmigos(){
    return this -> amigos;
}