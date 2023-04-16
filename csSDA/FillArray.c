#include <stdio.h>

#include "FillArray.h"
#include "Utilites.h"


//заповнення випадковими числами одновимірний масив
void FillRandomArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = rand();
}

//заповнення впорядкованими числами одновимірний масив
void FillOrderedArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = i;
}

//заповнення обернено впорядкованими числами одновимірний масив
void FillBackOrderedArray(int* Arr, const int size)
{
    for (int i = 0; i < size; i++) Arr[i] = size - i;
}

//заповнення впорядкованими числами тривимірний масив
void FillOrdered3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    int number = 0;
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for(int k = 0; k < col; k++)
            Arr3D[i][j][k] = number++;
           
}

//заповнення обернено впорядкованими числами тривимірний масив
void FillBackOrdered3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    int number = sector * row * col;
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++)
                Arr3D[i][j][k] = number--;
}

//заповнення випадковими числами тривимірний масив
void FillRandom3DArray(int*** Arr3D, const int sector, const int col, const int row)
{
    for (int i = 0; i < sector; i++)
        for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++)
                Arr3D[i][j][k] = rand() % (sector * row * col);
}


