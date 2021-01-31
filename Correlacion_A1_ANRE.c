//Importo las Librerias necesarias
#include <stdio.h>
#include <math.h>

//Andrés Rodriguez Estrada. Matricula ES1921017240
//Estructura de Datos. Cuarto semestre. Bloque 1.
//Profesor Julio Cesar Paz Carreño
//Correlacion de Pearson.

int main(){


    //Creo una variable que almacenará el tamaño de los datos
    int tam;
    //Doy Bienvenida y explicacion del funcionamiento del programa
    printf("\nBienvenido. Este programa calcula la correlacion de Pearson a partir de dos grupos de datos relacionados.");
    printf("\nPor favor, ingresa la cantidad de datos que se analizarán. Considera que crearas 2 grupos de datos del mismo tamaño\n pero con distintos valores relacionados entre si.");
    scanf("%d", &tam);

    //Creo dos arreglos de tipo double que contengan los datos a verificar, se denominarán X y Y.
    double datosX [tam];
    double datosY [tam];

    //Solicito al usuario me de los datos de cada uno de los grupos.

    //Datos del grupo X
    printf("\nRellenemos los datos del grupo X.");
    for(int i = 0; i<tam;i++){
        printf("\n%d. Dame un dato para el grupo X:", (i+1));
        scanf("%lf", &datosX[i]);
    }//Fin for datos del grupo X

    //Datos del grupo Y
    printf("\nAhora los datos del grupo Y.");
    for(int i = 0; i<tam;i++){
        printf("\n%d. Dame un dato para el grupo Y:", (i+1));
        scanf("%lf", &datosY[i]);
    }//Fin for datos del grupo Y

    //Muestro un mensaje de espera.
    printf("\nDatos almacenados.\nRealizando calculos. Espere.\n...\n......\n........");

    //Una vez obtenidos los datos, creo un ciclo for que recorrerá cada uno de los grupos simultaneamente, y hará las operaciones pertinentes
    //Para ello creo variables que funcionarán como acumuladores. Inicializo en cero para no obtener errores de calculo.

    double sumaX=0;
    double sumaY=0;
    double sumaX2=0;
    double sumaY2=0;
    double sumaXY=0;
    for(int i=0;i<tam;i++){
        //asigno el valor del indice correspondiente a la suma de X
        sumaX+=datosX[i];
        //asigno el valor del indice correspondiente a la suma de y
        sumaY+=datosY[i];
        //asigno el valor del indice correspondiente a la suma cuadrada de x, elevando el valor al cuadrado
        sumaX2+=(datosX[i]*datosX[i]);
        //asigno el valor del indice correspondiente a la suma cuadrada de y, elevando el valor al cuadrado
        sumaY2+=(datosY[i]*datosY[i]);
        //asigno el valor dle indice correspondiente a la suma de los valores multiplicados entre si, de X por Y
        sumaXY+=(datosX[i]*datosY[i]);
    }//FIn for calculos numericos

    //una vez obtenidos los datos necesarios para calcular la correlacion, procedo a efectuar la formula

    double correlacionPearson=0;

    correlacionPearson= ((tam*sumaXY)-(sumaX*sumaY))/sqrt(((tam*sumaX2)-(sumaX*sumaX))*((tam*sumaY2)-(sumaY*sumaY)));

    //Imprimo el indice de correlacion de Pearson
    printf("\nEl indice de correlacion de Pearson de los datos dados es de: %.4lf",correlacionPearson);





    



}//Fin metodo Main

