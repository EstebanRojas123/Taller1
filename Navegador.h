#pragma once
#include "Software.h"
#include <iostream>
#include "Usuario.h"
#include <vector>
using namespace std;

class Navegador : public Software{
    private:
        vector<Usuario>amigos;
        
    
    public:
        Navegador(string nombre,string developer,int edad,int precio);
        vector<Usuario>amigos();
        
        
};