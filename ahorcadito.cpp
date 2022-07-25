#include<iostream>
#include<string>
using namespace std ;

string palabra_original ;
string palabra_mostrar ;
int vidas ;
string palabraCorta;
string palabraIntermedia;
string palabraAvanzada;

void mostrar() ;
void ingresar(char x) ;
void inicializar(string palabra_original) ;
void menu();

int main(){
  menu();
  return 0;
	while(vidas>0 && palabra_mostrar!=palabra_original){
		char x ;
		cin >> x ;
		ingresar(x) ;
		mostrar() ;
	}
	if(vidas>0){ 
    cout << "ganaste! " << endl ;
    } else if(palabra_original.length() == palabraCorta.length()){
    cout << "se ha ganado un punto" << endl;
    }  else if(palabra_original.length() == palabraIntermedia.length()){
    cout << "se ha ganado dos puntos" << endl;
    } else if(palabra_original.length() == palabraAvanzada.length()){
    cout << "se ha ganado tres puntos" << endl;
    }else cout << "perdiste, la palabra era: " << palabra_original << endl ;
  }

void mostrar(){
	cout << "vidas: " << vidas << endl ;
	cout << palabra_mostrar << endl ;
}

void inicializar(string palabra_original){
	if(palabra_original.length() > 0 || palabra_original.length() <= 5){
    palabraCorta = palabra_original;
    vidas = 4;
  } else if(palabra_original.length() > 5 || palabra_original.length() <= 12){
    palabraIntermedia = palabra_original;
    vidas = 6;
  } else{
    palabraAvanzada = palabra_original;
    vidas = 8;
  }
	palabra_original = palabra_original;
	
	for(int i=0 ; i<palabra_original.length() ; i++){
		if(palabra_original[i]>='A' && palabra_original[i]<='Z'){
			palabra_original[i]+=32 ;
		}
	}
	
	for(int i=0 ; i<palabra_original.length() ; i++){
		if(palabra_original[i]>='a' && palabra_original[i]<='z'){
			palabra_mostrar+='_' ;
		} else{
			palabra_mostrar+=palabra_original[i] ;
		}
	}	
}

void ingresar (char x){
	
	bool perdiVidas=true ;
	
	for(int i=0 ; i<palabra_original.length() ; i++){
		if(x==palabra_original[i]){
			perdiVidas=false ;
			palabra_mostrar[i]=x ;
		}
	}
	
	if(perdiVidas) vidas-- ;
	
}

void menu(){
  int opcion;
	while(opcion != 4){
		cout << "***************************************" << endl;
    cout << "Bienvenido al ahorcadito de SYN" << endl;
		cout << "1. Jugar con una palabra de nivel bajo" << endl;
		cout << "2. Jugar con una palabra de nivel intermedio" << endl;
		cout << "3. Jugar con una palabra de nivel avanzado" << endl;
		cout << "4. Salir" << endl;
		cout << "***************************************" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:{ string palabra;
        palabra = "samy";
        inicializar(palabra);
        mostrar();     
      } break;
      case 2:{ string palabra;
        palabra = "perdona";
        inicializar(palabra);
        mostrar();
      } break;
      case 3:{string palabra;
        palabra = "parangutirimicuaro";
        inicializar(palabra);
        mostrar();
      } break;
    }
  }
}
