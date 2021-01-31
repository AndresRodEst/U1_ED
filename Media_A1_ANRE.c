#include <stdio.h>
#include <math.h>
int main()
{
    //Andrés Rodriguez Estrada. Matricula ES1921017240
    //Estructura de Datos. Cuarto semestre. Bloque 1.
    //Profesor Julio Cesar Paz Carreño
    //Calculo de medidas de tendencia central y de dispersion.

    //
    //Solicitud de tamaño de arreglo y creacion del arreglo
    //
    int tam = 0;
    printf("\nEste Programa permite calcular la media, moda y mediana de un conjunto de numeros.\n");
    printf("\nPor favor ingrese la cantidad total de numeros a ingresar:");
    scanf("%d", &tam);
    double numeros[tam];
    double acumulador = 0;

    //
    //Recopilacion de datos
    //

    //creo un for que recorrerá el tamaño del arreglo y solicitará datos
    for (int i = 0; i < tam; i++)
    {

        //Solicito y almaceno dato en una posicion dada
        printf("\n%d. Por favor ingrese un numero: ", (i + 1));
        scanf("%lf", &numeros[i]);

        //utilizo un acumulador para almacenar el total de la suma de los numeros
        //Será util en el calculo de la media(promedio)
        acumulador = acumulador + numeros[i];
    }

    printf("\nNumeros almacenados. Calculando estadisticas.\n....\n.....\n........");

    //
    //Calculo de la media(promedio)
    //

    //Hago uso del acumulador e imrpimo por pantalla la division del acumulador entre
    //la cantidad de elementos a considerar, definida por el usuario
    double promedio = acumulador / tam;
    printf("\nLa media de los datos es: %.2lf", promedio);

    //
    //Calculo de la mediana
    //

    double mediana = 0;

    //Usando dos ciclos for ordeno el array de menor a mayor.
    //El primer ciclo itera la cantidad de veces proporcional al tamaño del arreglo
    for (int i = 0; i < tam; i++)
    {

        //El segundo ciclo itera el tamaño del arreglo menos 1, para no desbordar los indices en las
        //consultas internas
        for (int i = 0; i < (tam - 1); i++)
        {

            //Defino una variable auxiliar que me permitirá intercambiar valores
            double auxiliar = 0;

            //Si una pocision arriba de la posiccion en que se esta iterando tiene un valor mayor a la anterior
            //Se hace un intercambio de valores, con la ayuda de la variable auxiliar, y esto se repite en cada iteracion
            if (numeros[i + 1] < numeros[i])
            {
                auxiliar = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = auxiliar;
            } //Fin sentencia if
        }     //Fin for interno

    } //Fin for superior

    //Si el tamaño del arreglo es inpar, selecciono solo el elemento central del arreglo
    if (tam % 2 != 0)
    {

        //Considerando que el arreglo inicia sus indices en 0, tomo el elemento central matematicamente menos 1
        mediana = numeros[(tam / 2)];
    }
    else
    //Por el contrario, si es par, selecciono los dos elementos centrales, y promedio ambos valores
    {
        //nuevamente, dados los indices en 0, tomo los elementos matematicamente menos 1
        mediana = ((numeros[tam / 2 - 1] + numeros[(tam / 2)]) / 2);
    }

    //Imprimo la mediana
    printf("\nLa mediana es: %.2lf", mediana);

    //
    //Calculo de la moda
    //

    //El primer ciclo se encargará de monitorear un unico elemento del arreglo ordenado o desordenado
    //y almacenar el total de veces que existe en el arreglo completo

    //Declaro un arreglo que almacenará las veces que se repite cada uno de los elementos del arreglo original
    int cantidadNumeros[tam];
    for (int contExterno = 0; contExterno < tam; contExterno++)
    {
        //declaro una variable que almacene el elemento de la posicion dada del arreglo de numeros original
        double numero = numeros[contExterno];
        //Declaro un contador que en cada iteracion se reiniciará
        //Se utilizará para contar las veces que se repite un numero
        int contadorRepetidos = 0;

        //Este ciclo recorrerá todo el arreglo original, comparando sus valores para identificar aquellos que sean iguales
        for (int contInterno = 0; contInterno < tam; contInterno++)
        {
            //Si el valor de la posicion dada por el for superior es igual a cualquier valor de cualquier
            //posicion del arreglo original, el contador incrementará en uno
            if (numero == numeros[contInterno])
            {
                //Aqui el contador incrementa si se cumple la condicion
                contadorRepetidos += 1;
            }
        } //Fin for contadorInterno
        //Terminado el ciclo interno, asigno el valor del contador al indice especifico de la iteracion actual
        //Para identificar cuantas veces se repite el valor del indice equivalente de ambos arreglos
        cantidadNumeros[contExterno] = contadorRepetidos;
    } //Fin for contadorExterno

    //Una ves obtenido el arreglo con la cantidad de numeros repetidos
    //Busco el elemento mayor del arreglo

    //Defino e inicializo en 0 una variable que almacenará el numero mayor.
    //Es importante notar que no almacena el mayor valor del arreglo original
    //sino el mayor valor del arreglo que guarda la cantidad de veces que se repiten
    //los valores en el arreglo original
    int mayor = 0;
    //Declaro una variable que almacenará el valor del indice que tiene el valor mas grande
    int indice = 0;
    //Creo un ciclo que recorrerá todos los valores del arreglo original
    for (int i = 0; i < tam; i++)
    {

        //Si el elemento seleccionado del arreglo es mayor al valor de la variable mayor
        //la variable mayor toma el valor del elemento, y la variable indice, toma el valor
        //del indice para identificar en que posicion se encuentra el elemento que mas se repite
        if (cantidadNumeros[i] > mayor)
        {
            mayor = cantidadNumeros[i];
            indice = i;
        }
    }

    //Imprimo la moda
    printf("\nLa moda es: %.2lf", numeros[indice]);

    //
    //Calculo de la varianza
    //

    //Defino una variable que almacene la varianza
    double varianza = 0;
    //Creo un ciclo que recorra todo el arreglo
    for (int i = 0; i < tam; i++)
    {
        //La varianza es igual a la suma del cuadrado de la resta de la media a cada uno de los elementos
        //Que dan como resultado la media. Este for se encarga de hacer esa suma.
        varianza += ((promedio - numeros[i]) * (promedio - numeros[i]));
    }
    //Una vez obtenida la suma, se divide el total entre la cantidad de elementos analizados.
    varianza = varianza / tam;

    printf("\nLa varianza es: %.2lf", varianza);

    //
    //Calculo de desviacion estandar
    //

    //la desviacion estandar es la raiz cuadrada de la varianza
    //Hago uso de la funcion sqrt de la libreria math.h de C para
    //calcular la raiz cuadrada
    double desviacionEst = sqrt(varianza);

    printf("\nLa desviacion estandar es: %.2lf", desviacionEst);

    //
    //Calculo del coeficiente de variacion
    //

    //Este calculo se obtiene dividendo la desviacion estandar entre el promedio
    //Su valor se representa comunmente en porcentaje,para esto multiplico el resultado por 100
    double coeficienteVariacion = desviacionEst / promedio * 100;
    printf("\nEl porcentaje del coeficiente de variacion es: %.2lf", coeficienteVariacion);

    //Mensaje de despedida
    printf("\nFin de los calculos. Saliendo..\n....\n......");

} //Fin funcion main
