#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

char caracter = ' '; // variable para almacenar caracter de archivo
char datoe = ' ';
int recorrido = 0;
int x=1;
char alfa[62] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', 
                 '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '%', '=', '(', ')', 'V', 'F',
                 ',', ';', '|', '&', '!', '<', '>', '^', '[', ']', char(10), '@', '.'};

int contadortokens=0;
int xpos=-1;
vector<char> listarecorrido;
vector<int> listarerrores;
// primera tabla compacta
int tabla[200][3] = {
    // Aquí irían los valores de la tabla
};

/*
   Aquí va los metodos
*/
int comprobacion=0;
int cont=0;
vector<int> listatokems;

int alfabeto(char c) { // Método para obtener la posición de cada caracter dentro de nuestro alfabeto
    for (int i = 0; i <= 62; i++) {
        if (c == alfa[i]) {
            return i;
            break;
        }
    }
    return 0;
}

void tablasCompactas(int pos, int l, char c) { // Realiza el recorrido en las Tablas Compactadas
    // alfabeto(pos);
    int t2c1 = 0;
    int aux = 0;

    if (recorrido >= 0) {
        int estado = tabla1[recorrido][1]; // nos da el inicio de donde buscar
        int estadoFinal = tabla1[recorrido][2] + estado; // nos da el fin
        
        while(aux <= 888){
        	if(estado == tabla2[aux][0]){
        		t2c1 = estado;
        		break;
			}
			aux++;
		}
		
		bool a = false;
		int aux2 = 0;
		int error = 0;
		
		for (int j = t2c1; j < estadoFinal; j++) {
		    if (pos == tabla2[j][2]) {
		        aux2 = tabla2[j][1];
		        a = true;
		        break;
		    } else {
		        a = false;
		        error = tabla2[j][2];
		    }
		}
		
		if (a == true) {
		  recorrido = aux2;
		}
		
		if (recorrido < 0) {
		  listatokens.push_back(recorrido);
		  recorrido = 0;
		  x = pos;
		  contadortokens++;
		}
		
		if (a == false) {
		  	if (error == 68) {
		    	recorrido = 0;
		  	} else {
		    if ((pos == 57) || (pos == 59)) {
		      if (recorrido > 0) {
		        // cout << "linea" << 1 << ": Sentencia mal escrita" << endl;
		      }
		      listaerrores.push_back(1);
		      recorrido = 0;
		    } else {
		      // cout << "linea" << 1 << " error " << error << " caracter: " << endl;
		      listaerrores.push_back(1);
		      recorrido = 0;
		    }
		  }
		}
		
    }else{
    	cout<<"Es negativo"<<endl;
	}
}

void metodoArchivo() {
    // Lee caracter por caracter del archivo.c
    // int linea = 0; // Esta variable no se utiliza en el código actual

    ifstream fichero; // Variable fichero para leer los datos
    fichero.open("archivo.c"); // Abre el archivo "archivo.c"

    fichero.get(caracter); // Intenta leer el primer caracter del archivo

    if (fichero.fail()) { // Si ocurre un error al abrir o leer el archivo
        cout << "Error al abrir el archivo archivo.c" << endl;
    } else {
        while (!fichero.eof()) { // Mientras no se llegue al final del archivo
            listarecorrido.push_back(caracter); // Agrega el caracter a la lista listarecorrido
            fichero.get(caracter); // Lee el siguiente caracter
        }
    }

    fichero.close(); // Cierra el archivo
}

int main(){
	metodoArchivo();
	int f = listarecorrido.size();
	int linea = 1;
	int nuevapos = 0;
	int poslinea = 0;
	
	for (int j = 0; j < f; j++) {
	    if (xpos != -1) {
	        j--;
	        xpos = -1;
	        x = -1;
	        comprobacion++;
	    }
	    if (poslinea == j) {
	        if (nuevapos == 59) {
	            linea++;
	        }
	    }
	    nuevapos = alfabeto(listarecorrido[j]);
	    tablasCompactas(nuevapos, linea, listarecorrido[j]);
	    xpos = x; // Asigna el valor de x a xpos

		// ... (resto del código que ya hemos analizado)
		
		int e = listaerrores.size();
		int w = listatokens.size();
		
		if (e > 0) {
		    // Si hay errores, imprime un mensaje por cada error
		    for (int i = 0; i < e; i++) {
		        cout << "Error en linea: " << listaerrores[i] << endl;
		        conterrores++;
		    }
		    cout << "Total de Errores: " << conterrores << endl;
		} else {
		    // Si no hay errores, imprime los tokens leídos
		    for (int i = 0; i < w; i++) {
		        cout << "Token leido: " << listatokens[i] << endl;
		    }
		    cout << "Compilacion Exitosa" << endl;
		    cout << "Numero total de tokens: " << contadortokens << endl;
		}
	    
	}
}
