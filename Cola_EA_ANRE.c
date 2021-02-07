//Importo las librerias necesarias
#include <stdio.h>

//Andrés Rodriguez Estrada. Matricula ES1921017240
//Estructura de Datos. Cuarto semestre. Bloque 1.
//Profesor Julio Cesar Paz Carreño
//Cola con funciones. Evidencia de Aprendizaje.


//Declaro los prototipos de mis funciones
void verificarVacia(int cola[], int tam);
void verificarLlena(int cola[], int tam);
void insertarElemento(int cola[], int tam);
void sacarElemento(int cola[], int tam);
//Creo o llamo al metodo main
int main(){
    //Creo una variable que almacenará el tamaño de la cola
    int tam;
    int estado=0;
 
    //Muestro un mensaje de bienvenida y solicito al usuario el tamaño para la cola.
    printf("\nEste programa permite manipular datos enteros mediante una cola.\nPor favor, ingresa un tamaño para la cola: ");
    scanf("%d",&tam);
    int cola[tam];
    //Inicializo en cero todos los elementos del arreglo con un ciclo for
    for(int i=0;i<tam;i++){

        cola[i]=0;
    }
    printf("\nLongitud definida. Accediendo al menu.\n");

    //Creo un menu que me permitirá navegar entre las distintas opciones de la cola.
    int opcion=0;
    do{
        //Muestro por pantalla el menu
        printf("\nMenu de manipulacion de cola.");
        printf("\n1. Verificar si la cola esta vacia.");
        printf("\n2. Verificar si la cola esta llena.");
        printf("\n3. Insertar un elemento en la cola.");
        printf("\n4. Sacar un elemento de la cola");
        printf("\n5. Salir.");
        printf("\n\n Por favor ingrese la opcion deseada: ");

        //Leo la opcion deseada
        scanf("%d",&opcion);

            //Creo un Switch que me permitirá manipular el menu y sus correspondientes acciones
            switch (opcion)
            {
            case 1:
                verificarVacia(cola,tam);
                break;

            case 2:
                verificarLlena(cola,tam);
                break;

            case 3:
                insertarElemento(cola,tam);
                break;

            case 4:
                sacarElemento(cola,tam);
                break;

            case 5:
                printf("\nSaliendo..\n...\n....");
                break;
            
            default:
                printf("\n Has ingresado una opcion inexistente.");
                break;
            }

         


    }while(opcion!=5);


}//Fin metodo  main

//Creo cada una de las funciones que requiero 
void verificarVacia(int cola[], int tam){

    //Verifico si la cola esta vacia consultando el primer elemento del array.
    if (cola[(tam - 1)] == 0)
    {
        printf("\nLa cola esta vacia.");
    }
    else
    {
        printf("\nLa cola no esta vacia.");
    }
}//Fin metodo verificarVacia

void verificarLlena(int cola[], int tam){
    //Para saber si la cola esta llena, el indice 0 debe ser distinto de 0
    //Para saber si la cola no esta llena pero tiene elementos,
    //el ultimo indice debe ser distinto de cero y el primero debe ser igual a 0
    //Por medio de ifs realizaré esas comprobaciones

    if (cola[(tam - 1)] != 0)
    {
        if (cola[0] != 0)
        {
            printf("\nLa cola esta llena.");
        }
        else
        {
            printf("\nLa cola tiene elementos, pero no esta llena.");
        }
    }
    else
    {
        printf("\nLa cola esta vacia.");
    }
}//Fin metodo verificarLlena

void insertarElemento(int cola[], int tam){
    //inicialmente verifico que la cola no este llena.
    if (cola[0] == 0)
    {

        //Creo un ciclo que leerá el valor, verificará que sea mayor a cero.
        //Si es igual o menor a cero, se solicitará al usuario ingresar otro valor.
        int centinela = 1;
        int valor;
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

        //Si la cola esta vacia, solo agrego el elemento a la ultima posicion  del array.
        if (cola[(tam - 1)] == 0)
        {
            cola[(tam - 1)] = valor;
        }
        else
        {

            //Creo un ciclo for que modificará todos los valores del array.
            //tendrá un limite de un elemento menor al tamaño total del array para no desbordarlo
            //Creo un centinela que verificará que se inserte una unica vez el elemento
            int centinela = 0;
            for (int i = (tam - 1); i >= 0; i--)
            {
                if (cola[i] == 0)
                {
                    cola[i] = valor;
                    centinela = 1;
                }
                if (centinela == 1)
                {
                    valor = 0;
                }
            }
        }
    }
    else
    //Si la cola esta llena, envio un mensaje informandolo
    {
        printf("\nLo sentimos, la cola esta llena. No es posible agregar mas elementos.");
    }

    //Por ultimo imprimo la cola
    printf("\nValores contenidos en la cola: ");
    for (int i = 0; i < tam; i++)
    {
        printf("\n%d", cola[i]);
    }

}//Fin del metodo insertarElemento

void sacarElemento(int cola[], int tam){
    //Considerando que se trata de una cola, siempre saldrá el elemento del ultimo indice  de la cola
    //Y todos los que esten debajo de el se recorrerán una posicion hacia arriba.
    //Antes de sacar un elemento, verifico que la cola no este vacia.
    if (cola[(tam - 1)] != 0)
    {

        //Inicialmente muestro el elemento que ha salido de la cola:
        printf("\nEl elemento que ha salido de la cola es: %d", cola[(tam - 1)]);

        //Despues recorro los valores. Es importante destacar que cada que un elemento sale,
        //Forzozamente debe agregarse un valor nulo(0 en este caso) al final de la cola, para no tener errores

        for (int i = (tam - 1); i >= 0; i--)
        {

            if (i != 0)
            {
                cola[i] = cola[i - 1];
            }
            else
            {
                cola[i] = 0;
            }
        }

        //Muestro nuevamente los valores de mi cola
        printf("\nValores contenidos en la cola: ");
        for (int i = 0; i < tam; i++)
        {
            printf("\n%d", cola[i]);
        }
    } //Fin if comprobacion valores de cola
    else
    {

        printf("\nLa cola esta vacia, no es posible sacar un elemento de ella.");

        //Muestro nuevamente los valores de mi cola
        printf("\nValores contenidos en la cola: ");
        for (int i = 0; i < tam; i++)
        {
            printf("\n%d", cola[i]);
        }
    } //Fin else comprobacion valores de cola
}

