#include <stdio.h>

#include "FillArray.h"
#include "Utilites.h"


//���������� ����������� ������� ����������� �����
void FillRandomArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = rand();
}

//���������� �������������� ������� ����������� �����
void FillOrderedArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = i;
}

//���������� �������� �������������� ������� ����������� �����
void FillBackOrderedArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = size - i;
}

//���������� �������������� ������� ���������� �����
void FillOrdered3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    int number = 0;
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for(int k = 0; k < col; k++)
            Arr3D[i][j][k] = number++;
           
}

//���������� �������� �������������� ������� ���������� �����
void FillBackOrdered3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    int number = sector * row * col;
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++)
                Arr3D[i][j][k] = number--;
}

//���������� ����������� ������� ���������� �����
void FillRandom3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++)
                Arr3D[i][j][k] = rand() % (sector * row * col);
}


