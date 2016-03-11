#include<iostream>
#include "rational.h"
#include <vector>
#include <string>
#include <sstream>

using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main(int argc,char* argv[]){
	bool acabar=false;
	vector<rational> racionales;
	vector<string>historial;
	while(!acabar){
		int opcion;
		cout<< "-------------------------------------------------------------"<<endl;
		cout<<"1-Crear racionales"<<endl
		<<"2-Suma de racionales"<<endl
		<<"3-Resta de racionales"<<endl
		<<"4-Multiplicacion de racionales"<<endl
		<<"5-Division de racionales"<<endl
		<<"6-Ver historial"<<endl
		<<"7-Salir"<<endl
		<<"seleccionar opcion: ";
		cin>>opcion;
		cout<< "-------------------------------------------------------------"<<endl;
		
		if(opcion==1){
			int numerator;
			int denominator;
			cout<<"Ingrese el numerador del racional: ";
			cin>>numerator;
			cout<<"Ingrese el denominador del racional: ";
                        cin>>denominator;
			rational nuevo(numerator,denominator);
			racionales.push_back(nuevo);

			
		}else{
			if(opcion==2){
				for(int i=0; i<racionales.size();i++){
					cout<<i+1<<"."<<racionales[i]<<endl;
				}
				int operando1,operando2;
				cout<<"Elija posicion primer operando: ";
				cin>>operando1;
				cout<<"Elija posicion segundo operando: ";
                                cin>>operando2;
				
				
				rational respuesta = racionales[operando1 -1] + racionales[operando2 -1];
				respuesta.simplificar();
				cout<< "Calculando..."<<endl;
				cout<< "La respuesta es: "<<respuesta<<endl;
				
				stringstream ss;
                                ss<<racionales[operando1 -1]<<" + "<< racionales[operando2 -1]<<" = "<<respuesta;
                                historial.push_back(ss.str());
			}else{
				if(opcion==3){
					for(int i=0; i<racionales.size();i++){
                                        	cout<<i+1<<"."<<racionales[i]<<endl;
                                	}
                                	int operando1,operando2;
                                	cout<<"Elija posicion primer operando: ";
                                	cin>>operando1;
                                	cout<<"Elija posicion segundo operando: ";
                                	cin>>operando2;

                                	rational respuesta = racionales[operando1 -1] - racionales[operando2 -1];
                                	respuesta.simplificar();
					cout<< "Calculando..."<<endl;
					cout<< "La respuesta es: "<<respuesta<<endl;
					stringstream ss;
                                        ss<<racionales[operando1 -1]<<" - "<< racionales[operando2 -1]<<" = "<<respuesta;
					historial.push_back(ss.str());
				}else{
					if(opcion==4){
						for(int i=0; i<racionales.size();i++){
                                        		cout<<i+1<<"."<<racionales[i]<<endl;
                                		}
                                		int operando1,operando2;
                                		cout<<"Elija posicion primer operando: ";
                                		cin>>operando1;
                                		cout<<"Elija posicion segundo operando: ";
                                		cin>>operando2;

                                		rational respuesta;
                                		respuesta = racionales[operando1 -1] * racionales[operando2 -1];
						respuesta.simplificar();
						cout<< "Calculando..."<<endl;
                                		cout<< "La respuesta es: "<<respuesta<<endl;
						
						stringstream ss;
                                        	ss<<racionales[operando1 -1]<<" * "<< racionales[operando2 -1]<<" = "<<respuesta;
                                        	historial.push_back(ss.str());
					}else{
						if(opcion==5){
							for(int i=0; i<racionales.size();i++){
                                        			cout<<i+1<<"."<<racionales[i]<<endl;
                                			}
                                			int operando1,operando2;
                                			cout<<"Elija posicion primer operando: ";
                                			cin>>operando1;
                                			cout<<"Elija posicion segundo operando: ";
                                			cin>>operando2;

                                			rational respuesta;
                                			respuesta = racionales[operando1 -1] / racionales[operando2 -1];
							respuesta.simplificar();
							cout<< "Calculando..."<<endl;
                                			cout<< "La respuesta es: "<<respuesta<<endl;

							stringstream ss;
                                        		ss<<racionales[operando1 -1]<<" / "<< racionales[operando2 -1]<<" = "<<respuesta;
                                        		historial.push_back(ss.str());
						}else{
							if(opcion==6){
								for(int i=0; i<historial.size();i++){
									cout<< i+1<<")"<<historial[i]<<endl;
								}
							}else{
								if(opcion==7){
									cout<<"GRACIAS POR UTILIZAR EL PROGRAMA";
									acabar=true;
								}else{
									cout<< "OPCION INCORRECTA!!";
								}
							}
							
						}
					}
				}
			}
		}
	}
	return 0;
}
