//Importo las librerias necesarias
#include <stdio.h>

//Andrés Rodriguez Estrada. Matricula ES1921017240
//Estructura de Datos. Cuarto semestre. Bloque 1.
//Profesor Julio Cesar Paz Carreño
//Pila con funciones.

//Declaro mis funciones
void verificarPilaVacia(int pila[]);
void verificarPilaLlena(int pila[], int tam);
void mostrarPila(int pila[], int tam);
void insertarElemento(int pila[], int tam);
void eliminarElemento(int pila[], int tam);
//Creo o llamo al metodo main
int main()
{
    //Creo una variable que almacenará el tamaño de la pila
    int tam;

    //Muestro un mensaje de bienvenida y solicito al usuario el tamaño para la pila.
    printf("\nEste programa permite manipular datos enteros mediante una pila.\nPor favor, ingresa un tamaño para la pila: ");
    scanf("%d", &tam);
    int pila[tam];
    //Inicializo en cero todos los elementos del arreglo con un ciclo for
    for (int i = 0; i < tam; i++)
    {

        pila[i] = 0;
    }
    printf("\nLongitud definida. Accediendo al menu.\n");

    //Creo un menu que me permitirá navegar entre las distintas opciones de la pila.
    int opcion = 0;
    do
    {
        //Muestro por pantalla el menu
        printf("\nMenu de manipulacion de pila.");
        printf("\n1. Verificar si la pila esta vacia.");
        printf("\n2. Verificar si la pila esta llena.");
        printf("\n3. Insertar un elemento en la pila.");
        printf("\n4. Sacar un elemento de la pila");
        printf("\n5. Salir.");
        printf("\n\n Por favor ingrese la opcion deseada: ");

        //Leo la opcion deseada
        scanf("%d", &opcion);

        //Creo un Switch que me permitirá manipular el menu y sus correspondientes acciones
        switch (opcion)
        {
        case 1:
            verificarPilaVacia(pila);
            break;

        case 2:
            verificarPilaLlena(pila, tam);

            break;

        case 3:
            insertarElemento(pila, tam);
            break;

        case 4:

            eliminarElemento(pila, tam);

            break;

        case 5:
            printf("\nSaliendo..\n...\n....");
            break;

        default:
            printf("\n Has ingresado una opcion inexistente.");
            break;
        }

    } while (opcion != 5);

} //Fin metodo  main

void verificarPilaVacia(int pila[])
{
    //Verifico si la pila esta vacia consultando el primer elemento del array.
    if (pila[0] == 0)
    {
        printf("\nLa pila esta vacia.");
    }
    else
    {
        printf("\nLa pila no esta vacia.");
    }
}

void verificarPilaLlena(int pila[], int tam)
{

    //Creo un ciclo for que realizará 2 acciones. En primer lugar verificará que los valores sean distintos de 0
    //Y ademas verificará cuantos valores son distintos de cero, para verificar si la pila esta vacia, si esta llena
    //o si tiene elementos.

    //Creo una variable denominada estada, que fungirá como valor booleano para definir un true o false
    //Cambiará en base a if-else en lineas posteriores, siempre lo inicializo como falso o 0
    int estado = 0;

    //Defino un contador que almacenará la cantidad de veces que haya un elemento diferente de 0
    int contador = 0;
    for (int i = 0; i < tam; i++)
    {
        if (pila[i] != 0)
        {
            //Si un elemento de la pila es distinto de 0, el contador incrementará su valor en uno,
            //para saber cuantos elementos hay en la pila
            contador += 1;
            //Si un elemento de la pila es distinto de 0, el valor de estado cambiará a 1 o true
            estado = 1;
        }
    }

    //Obtenidos los datos muestro mensajes en base a los valores obtenidos.
    //Si el contador tiene el mismo valor que el tamaño, la pila esta llena.
    //Si estado es igual a 1, la pila tiene elementos.
    if (estado == 1)
    {
        if (contador == tam)
        {
            printf("\nLa Pila esta llena.");
        }
        else
        {
            if (contador == 1)
            {
                printf("\nLa pila contiene elementos pero no esta llena. Solo tiene %d elemento.", contador);
            }
            else
            {
                printf("\nLa pila contiene elementos pero no esta llena. Solo tiene %d elementos.", contador);
            }
        }
    }
    else
    {
        printf("\nLa pila esta vacia.");
    }
}

void mostrarPila(int pila[], int tam)
{
    //Muestro los valores de la pila con un for
    printf("\nValores contenidos en la pila: ");
    for (int i = 0; i < tam; i++)
    {
        printf("\n%d", pila[i]);
    }
}

void insertarElemento(int pila[], int tam)
{

    int centinela = 1;
    int valor;
    //inicialmente verifico que la pila no este llena.
    if (pila[tam - 1] == 0)
    {

        //Creo un ciclo que leerá el valor, verificará que sea mayor a cero.
        //Si es igual o menor a cero, se solicitará al usuario ingresar otro valor.

        while (centinela == 1)
        {
            printf("\nPor favor, ingresa un numero mayor a 0:");
            scanf("%d", &valor);
            if (valor <= 0)
            {
                printf("\nHas ingresado un numero no valido. Intenta nuevamente.");
            }
            else
            {
                centinela = 0;
            }
        } //Fin ciclo while

        //Si la pila esta vacia, solo agrego el elemento a la posicion 0 del array.
        if (pila[0] == 0)
        {
            pila[0] = valor;
        }
        else
        {
            //Defino una variable como auxiliar que me ayudará a intercambiar valores
            int auxiliar;
            //Creo un ciclo for que modificará todos los valores del array.
            //tendrá un limite de un elemento menor al tamaño total del array para no desbordarlo
            for (int i = (tam - 1); i >= 0; i--)
            {
                if (i == 0)
                {
                    pila[i] = valor;
                }
                else
                {
                    pila[i] = pila[i - 1];
                }
            }
        }
    }
    else
    //Si la pila esta llena, envio un mensaje informandolo
    {
        printf("\nLo sentimos, la pila esta llena. No es posible agregar mas elementos.");
    }

    //Llamo por ultimo al metodo mostrar pila
    mostrarPila(pila, tam);
}

void eliminarElemento(int pila[], int tam)
{
    //Considerando que se trata de una pila, siempre saldrá el elemento de la posicion 0 de la pila
    //Y todos los que esten debajo de el se recorrerán una posicion hacia arriba.
    //Antes de sacar un elemento, verifico que la pila no este vacia.
    if (pila[0] != 0)
    {

        //Inicialmente muestro el elemento que ha salido de la pila:
        printf("\nEl elemento que ha salido de la pila es: %d", pila[0]);

        //Despues recorro los valores. Es importante destacar que cada que un elemento sale,
        //Forzozamente debe agregarse un valor nulo(0 en este caso) al final de la pila, para no tener errores

        for (int i = 0; i < tam; i++)
        {

            if (i != tam - 1)
            {
                pila[i] = pila[i + 1];
            } //Fin if
            else
            {
                //En el ultimo elemento del array agrego un 0.
                //Siempre en este indice, pues teoricamente es el que queda libre
                pila[i] = 0;
            }
        } //Fin for para reacomodar

        //Muestro nuevamente los valores de mi pila
        mostrarPila(pila, tam);
    } //Fin if comprobacion valores de pila
    else
    {

        printf("\nLa pila esta vacia, no es posible sacar un elemento de ella.");

        //Muestro nuevamente los valores de mi pila
        mostrarPila(pila, tam);
    } //Fin else comprobacion valores de pila
}