/*
 ============================================================================
 Name        : ejer9_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>



#define VACIO -1
#define OCUPADO 0
#define T 2

typedef struct
{
    //campos o atributos
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    int isEmpty;

}eAlumno;


void MostrarUnAlumno(eAlumno);
void MostrarTodosLosAlumnos(eAlumno[], int);

eAlumno PedirDatos();
void CargarAlumno(eAlumno[], int);

void OrdenarAlumnosPorLegajo(eAlumno[], int);

void InicializarAlumnos(eAlumno[], int);

int BuscarLibre(eAlumno[], int);




int main()
{
    setbuf(stdout, NULL);
    eAlumno listaAlumnos[T];//={{100,5,9,7,"Juan"},{101,9,8,8.5,"Maria"},{103,9,7,7.5,"Ana"}};

    int opcion;

    InicializarAlumnos(listaAlumnos, T);

    do
    {
        printf("1. ALTA\n");
        printf("2. BAJA\n");
        printf("3. MODIFICACION\n");
        printf("4. ORDENAR y MOSTRAR\n");
        printf("10. Salir\n");
        printf("Elija una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                CargarAlumno(listaAlumnos, T);
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:
                OrdenarAlumnosPorLegajo(listaAlumnos, T);
                printf("\nLista Ordenada por legajo:\n");
                MostrarTodosLosAlumnos(listaAlumnos, T);
            break;
        }
    }while(opcion!=10);


    return 0;
}
void MostrarUnAlumno(eAlumno unAlumno)
{
    printf("%d %d %d %f %s\n", unAlumno.legajo,
                               unAlumno.nota1,
                               unAlumno.nota2,
                               unAlumno.promedio,
                               unAlumno.nombre);
}
void MostrarTodosLosAlumnos(eAlumno lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
    	if(lista[i].isEmpty == OCUPADO)
    	{
    		 MostrarUnAlumno(lista[i]);
    	}

    }
}

eAlumno PedirDatos()
{
    eAlumno alumnoIngresado;

    printf("Ingrese legajo: ");
    scanf("%d", &alumnoIngresado.legajo);
    printf("Ingrese Nota 1: ");
    scanf("%d", &alumnoIngresado.nota1);
    printf("Ingrese Nota 2: ");
    scanf("%d", &alumnoIngresado.nota2);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", alumnoIngresado.nombre);

    alumnoIngresado.promedio = (float)(alumnoIngresado.nota1 + alumnoIngresado.nota2)/2;

    alumnoIngresado.isEmpty = OCUPADO;

    return alumnoIngresado;
}
/*convertir en int*/
void CargarAlumno(eAlumno lista[], int tam)
{
    int i;
    i=BuscarLibre(lista, tam);
    if(i!=-1)
    {
    	 lista[i] = PedirDatos();
    	 printf("Dato generado con exito");
    }
    else
    {
    	printf("No hay espacio!!!");
    }


}

void OrdenarAlumnosPorLegajo(eAlumno lista[], int tam)
{
    int i;
    int j;
    eAlumno auxiliar;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].legajo<lista[j].legajo)
            {
               auxiliar = lista[i];
               lista[i] = lista[j];
               lista[j] = auxiliar;
            }
        }
    }
}


void InicializarAlumnos(eAlumno lista[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty = VACIO;
	}
}

int BuscarLibre(eAlumno lista[], int tam)
{
	int i;
	int index;
	index = -1;
	for(i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


