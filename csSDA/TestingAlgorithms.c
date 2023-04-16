#include <stdio.h>
#include "Utilites.h"
#include "Algorithms.h"


//1D array tests

void Exchange4Test(int* Arr, const int size)     //���������� ������ #4 ������� ����� (�������� ����������) 
{
    printf("\tExchange4\n");
    printf("Unsorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');

    Exchange4(Arr, size);

    printf("Sorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');
}
void Select2Test(int* Arr, const int size)   //���������� ������ #2 ������� ������
{
    printf("\tSelect2\n");
    printf("Unsorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');
   
    Select2(Arr, size);
    
    printf("Sorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');
}
void QuickSortTest(int* Arr, const int size) //���������� ������ ��������� ����������� (���������� �����)
{
    printf("\tQuickSort\n");
    printf("Unsorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');
    
    QuickSort(0, size - 1);
    
    printf("Sorted mas:\n");
    _1DPrint(Arr, size);
    putchar('\n');
}


//3D array tests
void Exchange43DTest(int*** Arr3D, const int sector, const int row, const  int col) //���������� ������ #4 ������� ����� (�������� ����������) 
{
    printf("Exchange4\n");
    printf("Unsorted mas:\n");
    _3DPrint(Arr3D, sector , row , col);

    Exchange43D(Arr3D, sector, col, row);

    printf("Sorted mas:\n");
    _3DPrint(Arr3D, sector, row, col);
}
void Select23DTest(int*** Arr3D, const int sector, const int row, const int col)  //���������� ������ #2 ������� ������
{
    int imin, temp;
    printf("Select2\n");
    printf("Unsorted mas:\n");
    _3DPrint(Arr3D, sector, row, col);

    Select23D(Arr3D, sector, col, row);

    printf("Sorted mas:\n");
    _3DPrint(Arr3D, sector, row, col);
}
void QuickSort3DTest(int*** Arr3D, const int sector, const  int row, const int col) //���������� ������ ��������� ����������� (���������� �����)
{
    printf("QuickSort\n");
    printf("Unsorted mas:\n");
    _3DPrint(Arr3D, sector, row, col);

    for (int k = 0; k < sector; k++)
    {
        QuickSort3D(0, col - 1, k);
    }

    printf("Sorted mas:\n");
    _3DPrint(Arr3D, sector, row, col);
}

