#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Software;

class Usuario{
    private:
        string usuario;
        string pass;
        int edad;
        string correo;
        bool log;
        vector<Software*>softwares;
        

    public:
        Usuario(string usuario,string pass,int edad,string correo,bool log);
        
        string getNombre();
        void setNombre(string us);

        string getPass();
        void setPass(string pass);

        int getEdad();
        void setEdad(int edad);

        string getCorreo();
        void setCorreo(string correo);
        
        bool getLog();
        
        vector<Software*>getSoftwares();
        void addSoftware(Software* software);

        void mostrarSoftwares();
      
        void setSoftwares(vector<Software*>lista);
};
#include "Software.h"

Usuario :: Usuario(string usuario,string pass,int edad,string correo,bool log){
    this -> usuario = usuario;
    this -> pass = pass;
    this -> edad = edad;
    this -> correo = correo;
    this -> log = log;
};

string Usuario::getNombre(){
    return this -> usuario;
}

void Usuario :: setNombre(string us){
    this -> usuario = us;
}

string Usuario :: getPass(){
    return this -> pass;
}

void Usuario :: setPass(string pass){
    this -> pass = pass;
}

int Usuario :: getEdad(){
    return this -> edad;
}

void Usuario::setEdad(int edad){
    this -> edad = edad;
}

string Usuario::getCorreo(){
    return this -> correo;
}

void Usuario::setCorreo(string correo){
    this -> correo = correo;
}

bool Usuario::getLog(){
    return this -> log;
}

vector<Software*>Usuario::getSoftwares(){
    return this -> softwares;
}

void Usuario::addSoftware(Software*software){
    this -> softwares.push_back(software);
}


void Usuario::mostrarSoftwares(){
    if (this->softwares.empty()) {
        cout << "No hay software registrado." << endl;
    } else {
        cout << "Lista de Software:" << endl;
        for (Software* software : this->softwares) {
            cout << "Nombre: " << software->getNombre() << endl;
             
        }
    }

}

void Usuario::setSoftwares(vector<Software*>lista){
    this -> softwares = lista;
}
