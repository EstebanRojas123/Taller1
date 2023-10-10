#include <iostream>
#include "Usuario.h"
#include "Software.h"
#include "Juego.h"
#include "Ofimatica.h"
#include "Seguridad.h"
#include "Produccion.h"
#include "Social.h"
#include <vector>
#include <fstream>
#include <typeinfo>


using namespace std;

void desplegarSoftwares(vector<Software*>&softwares){
    cout <<"Softwares de la tienda: "<<endl;
    for(size_t i = 0;i<softwares.size();i++){
       
        cout <<i+1<<" "<<softwares[i]->getNombre()<<endl;
    }
    cout <<""<<endl;
}


Software* buscarSoftware(string nom,vector<Software*>&softwares){
    for(int i = 0;i<softwares.size();i++){
        if(softwares[i] -> getNombre() ==  nom){
            return softwares[i];
        }
    }
    return nullptr;
}
bool verificarSofUs(Usuario*u,Software* soft){
    for(int i = 0;i<u -> getSoftwares().size();i++){
        if(u->getSoftwares()[i]->getNombre()==soft -> getNombre()){
            return true;
        }
    }
    return false;
}

//selecciona el software a agregar y verifica si existe en la base de datos
void seleccionarSoftware(Usuario* u,vector<Software*>&softwares){
    
    desplegarSoftwares(softwares);
    cout<<"Escriba nombre del software a agregar: "<<endl;
    cout<<">";
    string n;
    cin>>n;

    Software* s = buscarSoftware(n,softwares); //busco al software por nombre

    if(s!=nullptr){
               //si el software existe intento agregarlo
               bool esta = verificarSofUs(u,s);


                if(esta==true){
                    cout <<"El software ya esta en la biblioteca del usuario."<<endl;
                }

                else{
                    u -> addSoftware(s);
                    cout << "Software agregado!"<<endl;
                }

    }else{
        cout << "[!] Software no encontrado"<<endl;
    }

}


void eliminarSoftware(Usuario* u,vector<Software*>&Softwares){
    vector<Software*> listaUsuario = u->getSoftwares();

    if(listaUsuario.size()>0){
    cout << "Softwares instalados: "<<endl;
    for(size_t i = 0;i<listaUsuario.size();i++){
        cout << " -"<<listaUsuario[i] ->getNombre()<<endl;
        }


        cout << "Ingrese nombre del software a eliminar: "<<endl;
        cout << ">";
        string nom;
        cin>>nom;

        
       
        Software* ss;
        for(int i = 0;i<u->getSoftwares().size();i++){
            if(u->getSoftwares()[i]->getNombre()==nom){
                ss = u->getSoftwares()[i];
            }
        }

    }
}

//una vez que se ingrese el usuario se preguntará la operacion que desea ejecutar
void subMenu(Usuario*u,vector<Software*>&softwares){
    cout<<"Que operacion desea realizar: "<<endl;
    cout<<"[1] Agregar Software."<<endl;
    cout<<"[2] Eliminar software"<<endl;
    cout <<">";
    string op;
    cin>>op;

   
    while(op!="1" && op!="2"){  //control de error en caso que se ingrese otra opcion
        cout << ""<<endl;
        cout<<"[!] Operacion incorrecta!";
        cout<<"Que operacion desea realizar: "<<endl;
        cout<<"[1] Agregar Software."<<endl;
        cout<<"[2] Eliminar software"<<endl;
        
        cin>>op;
    }

    if(op=="1"){
        seleccionarSoftware(u,softwares);
    }

    else if(op=="2"){
        eliminarSoftware(u,softwares);
    }
}

void menuPrincipal(Usuario* u, vector<Software*>&softwares) {
    cout << "Usuario: " << u->getNombre() << endl;
    cout << "Correo: " << u->getCorreo() << endl;
    cout << "Edad: " << u->getEdad() << endl;

    vector<Software*> listaUsuario = u->getSoftwares();

    if(listaUsuario.size()>0){
    cout << "Softwares instalados: "<<endl;
    for(size_t i = 0;i<listaUsuario.size();i++){
        cout << " -"<<listaUsuario[i] ->getNombre()<<endl;
        }
    }
    else{
        cout << "El usuario no tiene softwares en su biblioteca!"<<endl;
    }
    
   cout << ""<< endl;
   subMenu(u,softwares);

}

//funcion que verifica si el usuario esta registrado 
Usuario* existeUsuario(vector<Usuario*>&usuarios,string nom,string pass){
    for(size_t i = 0;i<usuarios.size();i++){
        if(usuarios[i] -> getNombre()==nom && usuarios[i] -> getPass()==pass){
            return usuarios[i];
        }
    }
    return nullptr;
}

//Menu de acceso: solicita el nombre de usuario y contraseña 

void desplegarMenu(vector<Usuario*>&usuarios,vector<Software*>&softwares){
   string resp;
    
    while(resp!="2"){
        cout << "[1] Ingresar"<<endl;
        cout << "[2] Salir"<<endl;
        cout << "> ";
        cin >> resp;
        
        if(resp=="1"){
            cout <<"-Ingrese Nombre de Usuario:";
            string us;
            cin >> us;
            
            cout << "-Ingrese password: ";
            string pass;
            cin >>pass;
            Usuario* u = existeUsuario(usuarios,us,pass); //verifico si el usuario existe
            if(u!=nullptr){
                cout << ""<<endl;
                cout <<"Acceso Correcto!!"<<endl;
             
                menuPrincipal(u,softwares);
                
            }else{                                      // si no existe el codigo contiua preguntando
                cout <<"[!] Acceso Incorrecto!"<<endl;
            }
        }
       cout << ""<<endl;
    }
    
}

void poblarUsuarios(vector<Usuario*> &usuarios){ //función encargada de poblar la lista de usuarios
    //1 admin
    Usuario* u1 = new Usuario("Piccolo","1",40,"pic1",true);
    
    //4 ninios
    Usuario* u2 = new Usuario("Goten","2",11,"",false);
    Usuario* u3 = new Usuario("Trunks","3",12,"",false);
    Usuario* u4 = new Usuario("Pan","3",10,"",false);
    Usuario* u5 = new Usuario("Arale","5",10,"",false);
    
    //10 adultos
    Usuario* u6 = new Usuario("Goku","6",30,"goku1",false);
    Usuario* u7 = new Usuario("Vegeta","7",30,"vegeta1",false);
    Usuario* u8 = new Usuario("Yamcha","8",30,"yamcha1",false);
    Usuario* u9 = new Usuario("Arale","9",30,"arale1",false);
    Usuario* u10 = new Usuario("Tenshinhan","10",30,"ten1",false);
    Usuario* u11 = new Usuario("Gohan","11",30,"gohan1",false);
    Usuario* u12 = new Usuario("Chaoz","12",30,"chaoz1",false);
    Usuario* u13 = new Usuario("Yajirobe","13",30,"yaji1",false);
    Usuario* u14 = new Usuario("Krilin","14",30,"krilin1",false);
    Usuario* u15 = new Usuario("Roshi","15",30,"roshi1",false);
    
    usuarios.push_back(u1); 
    usuarios.push_back(u2); 
    usuarios.push_back(u3); 
    usuarios.push_back(u4); 
    usuarios.push_back(u5); 
    usuarios.push_back(u6); 
    usuarios.push_back(u7); 
    usuarios.push_back(u8); 
    usuarios.push_back(u9); 
    usuarios.push_back(u10); 
    usuarios.push_back(u11); 
    usuarios.push_back(u12); 
    usuarios.push_back(u13); 
    usuarios.push_back(u14); 
    usuarios.push_back(u15); 
}
void poblarJuegos(vector<Software*> &softwares){
        //plataformas
        Juego* j1 = new Juego("Super Mario","Nintendo",6,69000,"plataformas");
        Juego* j2 = new Juego("Crash Bandicoot","Naughty dog",6,69000,"plataformas");
        //FPS
        Juego* j3 = new Juego("Call of Duty","Activision",18,69000,"FPS");
        Juego* j4 = new Juego("Doom","idSoftware",18,69000,"FPS");
        //Rol
        Juego* j5 = new Juego("Skyrim","Bethesda",18,69000,"rol");
        Juego* j6 = new Juego("The witcher 3","CD PROYEKT",18,69000,"rol");
        //TERROR
        Juego* j7 = new Juego("Silent Hill 2","Konami",18,69000,"terror");
        Juego* j8 = new Juego("Resident evil","Capcom",18,69000,"terror");
        //Puzzle
        Juego* j9 = new Juego("Portal","Valve",6,69000,"puzzle");
        Juego* j10 = new Juego("Tetris","Aleksei Pajitnov",6,69000,"puzzle");
        //Deportes
        Juego* j11 = new Juego("FIFA 23","EA",6,69000,"Deportes");
        Juego* j12 = new Juego("PES2006","Konami",6,69000,"Deportes");
        //Simulacion
        Juego* j13 = new Juego("The Sims 4","Maxis",6,69000,"Simulacion");
        Juego* j14 = new Juego("Cities: Skylines","Colosal order",6,69000,"Simulacion");
        //estrategia:
        Juego* j15 = new Juego("StarCraft II","Blizzard",6,69000,"estrategia");
        Juego* j16 = new Juego("Age of Empires II","Ensemble Studios",6,69000,"estrategia");
        //carreras
        Juego* j17 = new Juego("Forza Horizon","Playground Games",6,69000,"carreras");
        Juego* j18 = new Juego("Gran Turismo","Polyphony Digital",6,69000,"carreras");
        //Accion
        Juego* j19 = new Juego("Uncharted 4","Naughty Dog",6,69000,"Accion");
        Juego* j20 = new Juego("God Of War","Santa Monica",18,69000,"Accion");
        //agregar
        softwares.push_back(j1);
        softwares.push_back(j2);
        softwares.push_back(j3);
        softwares.push_back(j4);
        softwares.push_back(j5);
        softwares.push_back(j6);
        softwares.push_back(j7);
        softwares.push_back(j8);
        softwares.push_back(j9);
        softwares.push_back(j10);
        softwares.push_back(j11);
        softwares.push_back(j12);
        softwares.push_back(j13);
        softwares.push_back(j14);
        softwares.push_back(j15);
        softwares.push_back(j16);
        softwares.push_back(j17);
        softwares.push_back(j18);
        softwares.push_back(j19);
        softwares.push_back(j20);
}
void poblarOfimatica(vector<Software*> &softwares){
    Ofimatica* o1 = new Ofimatica("Microsoft Office", "Microsoft", 12, 1000, 4);
    Ofimatica* o2 = new Ofimatica("LibreOffice", "The Document Foundation", 12, 1000, 4);
    Ofimatica* o3 = new Ofimatica("Google Workspace", "Google", 12, 1000, 4);
    Ofimatica* o4 = new Ofimatica("WPS Office", "Kingsoft", 12, 1000, 4);
    Ofimatica* o5 = new Ofimatica("Apache OpenOffice", "Apache Software Foundation", 12, 1000, 4);
    
    softwares.push_back(o1);
    softwares.push_back(o2);
    softwares.push_back(o3);
    softwares.push_back(o4);
    softwares.push_back(o5);
}
void poblarProduccion(vector<Software*> &softwares){
    Produccion* p1 = new Produccion("AutoCAD", "Autodesk", 18, 4000, "Diseño");
    Produccion* p2 = new Produccion("SolidWorks", "Dassault Systèmes", 18, 6000, "Diseño");
    Produccion* p3 = new Produccion("Maya", "Autodesk", 18, 3000, "Diseño");
    Produccion* p4 = new Produccion("Revit", "Autodesk", 18, 4500, "Fotos");
    Produccion* p5 = new Produccion("Adobe Premiere Pro", "Adobe", 18, 239, "Video"); 
    
    softwares.push_back(p1);
    softwares.push_back(p2);
    softwares.push_back(p3);
    softwares.push_back(p4);
    softwares.push_back(p5);
    
}
void poblarSocial(vector<Software*> &softwares,vector<Usuario*> &usuarios){
    

    Social* s1 = new Social("Facebook", "Meta Platforms", 13, 0);
    Social* s2 = new Social("Twitter", "Twitter", 13, 0);
    Social* s3 = new Social("Instagram", "Meta Platforms", 13, 0);
    Social* s4 = new Social("LinkedIn", "LinkedIn Corporation", 18, 0);
    Social* s5 = new Social("Snapchat", "Snap", 13, 0);
    
    softwares.push_back(s1);
    softwares.push_back(s2);
    softwares.push_back(s3);
    softwares.push_back(s4);
    softwares.push_back(s5);
    
    Usuario* goku = usuarios[5];
    goku ->addSoftware(s1);
    goku ->addSoftware(s2);    

     /*
    vector<Software*>listaVegeta = usuarios[6].getSoftwares();
    vector<Software*>listaYamcha = usuarios[7].getSoftwares();
   
   
    listaVegeta.push_back(s1);
    listaVegeta.push_back(s3);
    listaYamcha.push_back(s1);
    listaYamcha.push_back(s3);
    
    Usuario u6("Goku","6",30,"goku1",false);
    Usuario u7("Vegeta","7",30,"vegeta1",false);
    Usuario u8("Yamcha","8",30,"yamcha1",false);
    
    */
    
}

int main()
{   
    vector<Software*>softwares; //declaro el vector tipo juego
    vector<Usuario*>usuarios; //declaro el vector tipo usuario
    //poblar base de datos:
    poblarUsuarios(usuarios); //lleno mi lista de usuarios
    poblarJuegos(softwares);
    poblarProduccion(softwares);
    poblarOfimatica(softwares);
    poblarSocial(softwares,usuarios);
    desplegarMenu(usuarios,softwares);

    return 0;
}