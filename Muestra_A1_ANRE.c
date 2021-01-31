#include <stdio.h>
#include <math.h>
int main(){
	//Andrés Rodriguez Estrada. Matricula ES1921017240
	//Estructura de Datos. Cuarto semestre. Bloque 1.
	//Profesor Julio Cesar Paz Carreño
	//Tamaño de muestra
	
	//Defino las variables a utilizar y las inicializo para evitar problemas de valores
	
	 float poblacion=0;
	 float error=0;
	 float p=0;
	 float q=0;
	 float tamMuestra=0;
	 float confianza = 0;
	  int nivelConfianza=0;
	 
	 //Imprimo por pantalla un mensaje de Bienvenida y explicacion del funcionamiento del programa
	 printf("Este programa calcula el tama�o de una muestra dada una poblacion.\n");
	 
	 //Solicito se ingrese el tama�o de la poblacion
	 printf("\nPor favor, ingrese el tama�o de la poblacion: ");
	 //Leo el tama�o de la poblacion 
	 scanf("%f", &poblacion);
	 //Solicito el porcentaje de confianza
	 printf("\nPor favor, el porcentaje de confianza: ");
	 //Leo el nivel de confianza. Es importante destacar que estoy utilizando un entero para poder dar uso a un Switch
	 scanf("%d", &nivelConfianza);	 
	 
	 //Creo un switch que definir� el valor estadistico del nivel de confianza, en base al porcentaje dado, con 3 opciones:
	 
	 switch(nivelConfianza){
	 
	 	//Defino cada uno de los casos
	 	case 90: confianza = 1.64;
	 		break;
	 	case 95: confianza = 1.96;
	 		break;
	 	case 99 : confianza = 2.575;
	 		break;
	 		
	 	//Defino un valor por defecto, que es equivalente al 95 por ciento, algo comun. 
	 	default: confianza = 1.96;
	 		break;
	 }
	 
	 //solicito el porcentaje de error.
	 printf("\nPor favor, ingrese el porcentaje de error: ");
	 //Leo el porcentaje de error. Puedo recibirlo como entero y despues asignar un valor porcentual en un float. 
	 //En este caso hago todo el calculo en un mismo tipo de dato
	 scanf("%f", &error);
	 //Si el valor no esta dado en un decimal que represente un porcentaje, lo divido entre 100. Caso contrario lo dejo igual.
	 if(error>1){
	 	error = error/100;
	 }
	 
	 //Solicito el valor de P, en formato decimal
	 printf("\nPor favor, ingrese el valor de p en formato decimal: ");
	 //Leo el valor de P
	 scanf("%f", &p);
	 
	 //En base al valor de p, y considerando que q es igual a 1*p, realizo el calculo correspondiente y asigno valor.
	 q=1-p;
	 printf("\nCalculando el valor de q, considerando que q = 1-p: %.2f",q);
	 
	 //Muestro los datos generales de la operacion.
	 printf("\nValores: \nTam poblacion: %.2f. \nPorcentaje confianza: %.2f. \nPorcentaje error: %.2f. \nValor p: %.2f, \nValor q: %.2f.",poblacion,confianza,error,p,q);	 
	 printf("\nCalculando tama�o de muestra. Espere\n....\n.....");
	 
	 //Realizo el calculo de la muestra
	 tamMuestra = ((confianza*confianza)*p*q*poblacion)/(((error*error)*(poblacion-1))+((confianza*confianza)*p*q));
	 //Muestro el resultado correspondiente utilizando la funcion floor que redondea hacia abajo el resultado
	 //Considernado que la logica indica que la muestra debe ser un numero entero
	 printf("\nEl tama�o ideal de la muestra es de: %.2f", floor(tamMuestra));
	 
	
}
