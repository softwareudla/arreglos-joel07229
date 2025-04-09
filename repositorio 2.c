#include <stdio.h>

int main()
{
    char estudiantes[5][30];
    char materias[3][30];
    float NM1[5], NM2[5], NM3[5];
    float maxM1 = 0, minM1 = 10, maxM2 = 0, minM2 = 10, maxM3 = 0, minM3 = 10;
    int aux = 0;
    float maxe = 0, mine = 10;

    printf("=== INGRESO DE MATERIAS ===\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        scanf("%29s", materias[i]);
    }

    printf("\n=== INGRESO DE NOMBRES DE ESTUDIANTES ===\n");
    getchar(); 
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf(" %29[^\n]", estudiantes[i]); 
    }

    printf("\n=== INGRESO DE NOTAS ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nNotas para %s:\n", estudiantes[i]);

        do
        {
            printf("%s: ", materias[0]);
            scanf("%f", &NM1[i]);
            if (NM1[i] < 0 || NM1[i] > 10)
            {
                printf("Error: La nota debe estar entre 0 y 10\n");
            }
        } while (NM1[i] < 0 || NM1[i] > 10);

        do
        {
            printf("%s: ", materias[1]);
            scanf("%f", &NM2[i]);
            if (NM2[i] < 0 || NM2[i] > 10)
            {
                printf("Error: La nota debe estar entre 0 y 10\n");
            }
        } while (NM2[i] < 0 || NM2[i] > 10);

        do
        {
            printf("%s: ", materias[2]);
            scanf("%f", &NM3[i]);
            if (NM3[i] < 0 || NM3[i] > 10)
            {
                printf("Error: La nota debe estar entre 0 y 10\n");
            }
        } while (NM3[i] < 0 || NM3[i] > 10);
    }

    for (int i = 0; i < 5; i++)
    {
        if (NM1[i] >= maxM1)
        {
            maxM1 = NM1[i];
        }
        if (NM1[i] < minM1)
        {
            minM1 = NM1[i];
        }

        if (NM2[i] >= maxM2)
        {
            maxM2 = NM2[i];
        }
        if (NM2[i] < minM2)
        {
            minM2 = NM2[i];
        }

        if (NM3[i] >= maxM3)
        {
            maxM3 = NM3[i];
        }
        if (NM3[i] < minM3)
        {
            minM3 = NM3[i];
        }
    }

    printf("\n=== LISTA DE ESTUDIANTES ===\n");
    printf("N°   Estudiante\n");
    printf("------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%-4d %-15s\n", i + 1, estudiantes[i]);
    }

    printf("\nSeleccione un estudiante (1-5): ");
    while (scanf("%d", &aux) != 1 || aux < 1 || aux > 5)
    {
        printf("Error: Ingrese un numero entre 1 y 5: ");
        while (getchar() != '\n')
        {
        }
    }
    aux--; 

    mine = NM1[aux];
    maxe = NM1[aux];

    if (NM2[aux] < mine)
    {
        mine = NM2[aux];
    }
    if (NM2[aux] > maxe)
    {
        maxe = NM2[aux];
    }
    if (NM3[aux] < mine)
    {
        mine = NM3[aux];
    }
    if (NM3[aux] > maxe)
    {
        maxe = NM3[aux];
    }

    float promedioEst = (NM1[aux] + NM2[aux] + NM3[aux]) / 3;

    printf("\n=== INFORMACION DEL ESTUDIANTE ===\n");
    printf("Nombre      : %s\n", estudiantes[aux]);
    printf("Notas       :\n");
    printf("  %-12s: %.2f\n", materias[0], NM1[aux]);
    printf("  %-12s: %.2f\n", materias[1], NM2[aux]);
    printf("  %-12s: %.2f\n", materias[2], NM3[aux]);
    printf("Nota minima : %.2f\n", mine);
    printf("Nota maxima : %.2f\n", maxe);
    printf("Promedio    : %.2f\n", promedioEst);
    printf("Situacion   : %s\n", (promedioEst >= 6.0) ? "Aprobado" : "Reprobado");

    float sumaM1 = 0, sumaM2 = 0, sumaM3 = 0;
    for (int i = 0; i < 5; i++)
    {
        sumaM1 += NM1[i];
        sumaM2 += NM2[i];
        sumaM3 += NM3[i];
    }

    printf("\n=== NOTAS POR ASIGNATURA ===\n");
    printf("%-15s | Minima | Maxima\n", "Materia");
    printf("-------------------------------\n");
    printf("%-15s | %6.2f | %6.2f\n", materias[0], minM1, maxM1);
    printf("%-15s | %6.2f | %6.2f\n", materias[1], minM2, maxM2);
    printf("%-15s | %6.2f | %6.2f\n", materias[2], minM3, maxM3);

    printf("\n=== PROMEDIOS POR ASIGNATURA ===\n");
    printf("%-15s : %.2f\n", materias[0], sumaM1 / 5);
    printf("%-15s : %.2f\n", materias[1], sumaM2 / 5);
    printf("%-15s : %.2f\n", materias[2], sumaM3 / 5);

    int aprobadosM1 = 0, aprobadosM2 = 0, aprobadosM3 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (NM1[i] >= 6)
            aprobadosM1++;
        if (NM2[i] >= 6)
            aprobadosM2++;
        if (NM3[i] >= 6)
            aprobadosM3++;
    }

    printf("\n=== APROBADOS Y REPROBADOS ===\n");
    printf("%-15s : %d aprobados, %d reprobados\n", materias[0], aprobadosM1, 5 - aprobadosM1);
    printf("%-15s : %d aprobados, %d reprobados\n", materias[1], aprobadosM2, 5 - aprobadosM2);
    printf("%-15s : %d aprobados, %d reprobados\n", materias[2], aprobadosM3, 5 - aprobadosM3);

    printf("\n=== PROMEDIOS DE TODOS LOS ESTUDIANTES ===\n");
    printf("%-15s | Promedio | Estado\n", "Estudiante");
    printf("-----------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        float promedio = (NM1[i] + NM2[i] + NM3[i]) / 3;
        printf("%-15s |   %.2f   | %s\n", estudiantes[i], promedio, (promedio >= 6.0) ? "Aprobado" : "Reprobado");
    }

    return 0;
}