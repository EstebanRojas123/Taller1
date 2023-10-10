#pragma once
#include "Usuario.h"
#include <iostream>
#include <vector> 


using namespace std;

class Software{
    private:
        string nombre;
        string developer;
        int edad;
        vector<Usuario>usuarios;
        int precio;
    public:
        Software(string nombre,string developer,int edad,int precio);
        
        string getNombre();
        void setNombre(string nombre);
        
        string getDeveloper();
        void setDeveloper(string developer);
        
        int getEdad();
        void setEdad(int edad);
        
        int getPrecio();
        void setPrecio(int precio);
        
        vector<Usuario> getUsuarios();
        
        string toString();
};

Software::Software(string nombre,string developer,int edad,int precio){
  this -> nombre = nombre;
  this -> developer = developer;
  this -> edad = edad;
  this -> precio = precio;
};

//gets y sets
string Software::getNombre(){
    return this -> nombre;
};

void Software::setNombre(string nombre){
    this -> nombre = nombre;
};

vector<Usuario> Software::getUsuarios(){
    return this -> usuarios;
};


string Software::getDeveloper(){
    return this -> developer;
};

void Software::setDeveloper(string developer){
    this -> developer = developer;
};

int Software::getEdad(){
    return this -> edad;
}

void Software::setEdad(int edad){
    this -> edad = edad;
};

int Software::getPrecio(){
    return this -> precio;
};

void Software::setPrecio(int precio){
    this -> precio = precio;
};