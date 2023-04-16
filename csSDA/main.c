#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utilites.h"
#include "Measurement.h"
#include "FillArray.h"
#include "TestingAlgorithms.h"

//������� ������� ������ ����������� 
void MainMenu(const int option, const int measurement, const int algorithm);

void Option( void* (Function)(int), const char* FunctionName);

int main(int argc, char **argv)
{
    srand(time(NULL));
 
    while (_TRUE)
    {
        //��������� ���� � ������� ������� ������
        printf("\tMENU\n1.Measurements program\n2.Testing\n3.Exit\n");
        int choose1, choose2, choose3;
        scanf("%d", &choose1);

        system("cls");

        if (choose1 == _MEASUREMENTS || choose1 == _TESTING)
        {
            //���� � ������� ������� ������
            printf("CHOOSE MEASUREMENT SIZE\n1.3D Array\n2.Array\n");
            scanf("%d", &choose2);

            system("cls");

            if (choose2 == _3DARRAY || choose2 == _ARRAY)
            {
                //���� � ������� ������� ��������� ����������
                printf("CHOOSE ALGORITHM\n1.Exchange4\n2.Select2\n3.QuickSort\n4.All algorithms\n");
                scanf("%d", &choose3);

                system("cls");

                //�������� ���� � ������� �������
                MainMenu(choose1, choose2, choose3);
            }
        }
        if (choose1 == _EXIT)
        {
            //����� � �������� ��� ����� ������������ ������� 3 (_EXIT)
            printf("\nProgram was ended!\n");
            break;
        }
    }
   
    return _TRUE;
}

void MainMenu(const int option, const int measurement, const int algorithm) {
    //������ ������
    if (measurement == _3DARRAY)
    {
        system("cls");

        //�������� ���`�� ��� ����������� ������
        _3DAllocation(Array3D, SECT, ROW, COL);

        if (option == _MEASUREMENTS)
        {
            switch (algorithm) {
            case _EXCHANGE4:
                //����� #4 ������� ����� (�������� ����������) 
                Option(Exchange4Measurement3D, "Exchange4");            
                break;
            case _SELECT2:
                //����� #2 ������� ������
                Option(Select2Measurement3D, "Select2");
                break;
            case _QUICKSORT:
                // ����� ��������� ����������� (���������� �����)
                Option(QuickSortMeasurement3D, "QuickSort");
                break;
            case _ALL:
                printf("SECT=%d;  ROW=%d;  COL=%d;\n", SECT, ROW, COL);

                Option(Exchange4Measurement3D, "Exchange4");
                Option(Select2Measurement3D, "Select2");
                Option(QuickSortMeasurement3D, "QuickSort");
                break;
            }
        }

        if (option == _TESTING)
        {
            FillRandom3DArray(Array3D, 2, 5, 5);  
            switch (algorithm) {
            case _EXCHANGE4:
                //���������� ������ #4 ������� ����� (�������� ����������) 
                Exchange43DTest(Array3D, 2, 5, 5);
                break;
            case _SELECT2:
                //���������� ������ #2 ������� ������
                Select23DTest(Array3D, 2, 5, 5);
                break;
            case _QUICKSORT:
                //���������� ������ ��������� ����������� (���������� �����)
                QuickSort3DTest(Array3D, 2, 5, 5);
                break;
            case _ALL:
                FillRandom3DArray(Array3D, 2, 5, 5);
                Exchange43DTest(Array3D, 2, 5, 5);
                FillRandom3DArray(Array3D, 2, 5, 5);
                Select23DTest(Array3D, 2, 5, 5);
                FillRandom3DArray(Array3D, 2, 5, 5);
                QuickSort3DTest(Array3D, 2, 5, 5);
                break;
            } 
        }

        printf("\nPress any button to back in the menu:");
        getch();
        system("cls");

        //�������� ���`�� ��������� ��� ����������� ������
        _3DRelease(Array3D, SECT, ROW, COL);
    }
    if (measurement == _ARRAY)
    {
        system("cls");

        //�������� ���`�� ��� ������������ ������
        _1DAllocation(Array, ARRLEN);

        if (option == _MEASUREMENTS)
        {
            switch (algorithm) {
            case _EXCHANGE4:
                //����� #4 ������� ����� (�������� ����������) 
                Option(Exchange4Measurement, "Exchange4");
                break;
            case _SELECT2:
                //����� #2 ������� ������
                Option(Select2Measurement, "Select2");
                break;
            case _QUICKSORT:
                // ����� ��������� ����������� (���������� �����)
                Option(QuickSortMeasurement, "QuickSort");;
                break;
            case _ALL:
                printf("ARRLEN = %d\n", ARRLEN);

                Option(Exchange4Measurement, "Exchange4");
                Option(Select2Measurement, "Select2");
                Option(QuickSortMeasurement, "QuickSort");
                break;
            }
        }

        if (option == _TESTING)
        {
            FillRandomArray(Array, 20);
            switch (algorithm) {
            case _EXCHANGE4:
                //���������� ������ #4 ������� ����� (�������� ����������) 
                Exchange4Test(Array, 20);
                break;
            case _SELECT2:
                //���������� ������ #2 ������� ������
                Select2Test(Array, 20);
                break;
            case _QUICKSORT:
                //���������� ������ ��������� ����������� (���������� �����)
                QuickSortTest(Array, 20);
                break;
            case _ALL:
                FillBackOrderedArray(Array, 20);
                Exchange4Test(Array, 20);
                putchar('\n');
                FillBackOrderedArray(Array, 20);
                Select2Test(Array, 20);
                putchar('\n');
                FillBackOrderedArray(Array, 20);
                QuickSortTest(Array, 20);
                break;
            }
        }

        printf("\nPress any button to back in the menu:");
        getch();
        system("cls");

        //�������� ������� ���`�� ��� ������������ ������
        _1DRelease(Array);
    }
}

void Option(void* (Function)(int), const char* FunctionName)
{
    printf("\t\t Ordered \t Random \t BackOrdered \n");
   
    printf("%-9s", FunctionName);
    Function(_ORDERED);
    printf("\t%7.2f", Measurement());
    Function(_RANDOM);
    printf("\t\t%7.2f", Measurement());
    Function(_BACKORDERED);
    printf("\t\t%7.2f\n", Measurement());
}
