#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

#define MAX 99999

int main()
{
    //SE DECLARAN LAS VARIABLES QUE SE USARAN PARA EL DESAROLLO DEL PROGAMA
    char seguir = 'n';
    char auxOperandoA[MAX];
    char auxOperandoB[MAX];
    float operandoA;
    float operandoB;
    float suma,resta,multiplicacion,division,factorialA,factorialB;
    int flagSinNumeros=0;
    int flagSinCalcular=0;
    int flagSinA=0;

//UTILIZO UNA SENTENCIA DO WHILE PARA QUE LA CALCULADORA SE EJECUTE UNA VEZ Y SE REEJECUTE CUANDO LA CONDICION ES VEDADERA
    do
    {
        //UTILIZO UN SWITCH PARA DESAROLLAR LAS OPCIONES MULTIPLES.
        switch(menu())
        {
        //EN ESTE CASO PIDO EL VALOR DEL OPEANDO A Y VALIDO QUE SEA NUMERO
        case 1:
            while(!funcion_getStringNumerosFlotantes("Ingrese una operando A : ",auxOperandoA))
            {
                printf("ERROR- La opcion tiene que ser solo numeros\n\n");
                system("pause");

            }
            operandoA=atof(auxOperandoA);
            flagSinA=1;
            break;

        //EN ESTE CASO PIDO EL VALOR DEL OPEANDO B Y VALIDO QUE SEA NUMERO
        case 2:
           if(flagSinA == 1)
           {
            while(!funcion_getStringNumerosFlotantes("Ingrese una operando B : ",auxOperandoB))
            {
                printf("ERROR- La opcion tiene que ser solo numeros\n\n");
                system("pause");

            }
            operandoB=atof(auxOperandoB);
            flagSinNumeros=1;
           }else
           {
            printf("\nNo ingreso operando A, por favor ingrese nuevamente\n");
           }

            break;
        //EN ESTE CASO SE CALCULAN TODAS LAS OPERACIONES Y SE VALIDA QUE HAYAN INGRESADO LOS VALORES
        case 3:
            if(flagSinNumeros == 1 )
            {
                printf("Calculando..");
                suma=funcion_Suma(operandoA,operandoB);
                resta=funcion_Resta(operandoA,operandoB);
                multiplicacion=funcion_Multiplicacion(operandoA,operandoB);
                division=funcion_Division(operandoA,operandoB);


                    factorialA=funcion_Factorial(operandoA);
                    factorialB=funcion_Factorial(operandoB);


            }
            else
            {
                printf("\nNo ingreso numeros\n");
                system("pause");
            };
            flagSinCalcular=1;


            break;
        //EN ESTE CASO SE INFORMA SOBRE LOS RESULTADOS DE LAS OPERACIONES O MUESTRA UN ERROR SI NO SE CALCULARON
        case 4:
            if(flagSinCalcular == 1)
            {

                printf("\nA:%0.2f\n",operandoA);
                printf("\nB:%0.2f\n",operandoB);
                printf("\nLa suma es: %0.2f",suma);
                printf("\nLa resta es: %0.2f",resta);
                printf("\nLa multiplicacion es: %0.2f",multiplicacion);
                printf("\nLa division es: %0.2f",division);
                printf("\nLa factorial de A es: %0.0f",factorialA);
                printf("\nLa factorial de B es: %0.0f\n",factorialB);

            }
            else
            {
                printf("\nNo resolvio las operaciones \n");

            }
            break;
        //EN ESTE CASO SALE DE LA CALCULADORA
        case 5:
            printf("Saliendo...");
            exit(-1);
            break;
        }
        printf("\n Desea continuar usando la calculadora? ");

        scanf("%c",&seguir);
        system("cls");
        fflush(stdin);

    }
    while(seguir == 's' || seguir == 'S' );

    printf("Saliendo...");

    return 0;
}
