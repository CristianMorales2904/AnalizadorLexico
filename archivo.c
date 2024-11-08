#include <iostream>
using namespace std;
 
int main(){

int opcion;
float a,b,suma,resta,multiplicacion,division;
cout<<"MI CALCULADORA BASICA"<<endl;
cout<<"1. Suma"<<endl;
cout<<"2. Resta"<<endl;
cout<<"3. Multilpicacion"<<endl;
cout<<"4. Division"<<endl;
cout<<"Ingrese numero de opcion: ";
cin>>opcion;
 
if(opcion == 1)
	{cout<<"Ingrese primer numero a sumar: ";
	cin>>a;
	cout<<"Ingrese segundo numero a sumar: ";
	cin>>b;
	suma = a + b;
	cout<<"La suma es: "<<suma;
	}
 
if(opcion == 2)
	{cout<<"Ingrese primer numero a restar: ";
	cin>>a;
	cout<<"Ingrese segundo numero a restar: ";
	cin>>b;
	resta = a - b;
	cout<<"La resta es: "<<resta;
	}
 
if(opcion == 3)
	{cout<<"Ingrese primer numero a multiplicar: ";
	cin>>a;
	cout<<"Ingrese segundo numero a multiplicar: ";
	cin>>b;
	multiplicacion = a * b;
	cout<<"La multiplicacion es: "<<multiplicacion;
	}
 
if(opcion == 4)
	{cout<<"Ingrese primer numero a dividir: ";
	cin>>a;
	cout<<"Ingrese divisor: ";
	cin>>b;
	division = a / b;
	cout<<"La division es: "<<division;
	}
return 0;
}