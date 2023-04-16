#include "Algorithms.h"
#include <stdio.h>
#include "Utilites.h"



//сортування методом #4 прямого обміну (Шейкерне сортування) одновимірного масиву
clock_t Exchange4(int* A,const int size) 
{
    int L, R, k, temp;
    clock_t timeStart, timeStop;

    timeStart = clock();

    L = 0;
    R = size - 1;
    k = 0;
    while (L < R)
    {
        for (int i = L; i < R; i++)
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                k = i;
            }
     
        R = k;
        
        for (int i = R - 1; i >= L; i--)
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                k = i;
            }
      
        L = k + 1;
    }

    timeStop = clock();

    return timeStop - timeStart;
}

//сортування методом #4 прямого обміну (Шейкерне сортування) тривимірного масиву
clock_t Exchange43D(int*** Arr3D, const int sector, const int col, const int row)   
{
    int L, R, t, temp;
    clock_t timeStart, timeStop;

    timeStart = clock();

    for (int k = 0; k < sector; k++)
    {
        L = 0;
        R = col - 1;
        t = 0;
        while (L < R)
        {
            for (int i = L; i < R; i++)
                if (Arr3D[k][0][i] > Arr3D[k][0][i + 1])
                {
                    for (int j = 0; j < row; j++)
                    {
                        temp = Arr3D[k][j][i];
                        Arr3D[k][j][i] = Arr3D[k][j][i + 1];
                        Arr3D[k][j][i + 1] = temp;
                    }
                    t = i;
                }
            R = t;
            for (int i = R - 1; i >= L; i--)
                if (Arr3D[k][0][i] > Arr3D[k][0][i + 1])
                {
                    for (int j = 0; j < row; j++)
                    {
                        temp = Arr3D[k][j][i];
                        Arr3D[k][j][i] = Arr3D[k][j][i + 1];
                        Arr3D[k][j][i + 1] = temp;
                    }
                    t = i;
                }
            L = t + 1;
        }
    }

    timeStop = clock();

    return timeStop - timeStart;
}


//сортування методом #2 прямого вибору одновимірного масиву
clock_t Select2(int* A, const int size)
{
    int imin, temp;
    clock_t timeStart, timeStop;

    timeStart = clock();

    for (int s = 0; s < size - 1; s++)
    {
        imin = s;
        for (int i = s + 1; i < size; i++)
            if (A[i] < A[imin]) imin = i;
        temp = A[imin];
        A[imin] = A[s];
        A[s] = temp;
    }

    timeStop = clock();

    return timeStop - timeStart;
}

//сортування методом #2 прямого вибору тривимірного масиву
clock_t Select23D(int*** Arr3D, const int sector, const int col, const int row)     
{
    int imin, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int k = 0; k < sector; k++)
    {
        for (int s = 0; s < col - 1; s++)
        {
            imin = s;
            for (int i = s + 1; i < col; i++)
                if (Arr3D[k][0][i] < Arr3D[k][0][imin]) imin = i;
            for (int i = 0; i < row; i++)
            {
                tmp = Arr3D[k][i][imin];
                Arr3D[k][i][imin] = Arr3D[k][i][s];
                Arr3D[k][i][s] = tmp;
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}


//сортування метод «швидкого сортування» (сортування Хоара) одновимірного масиву
void QuickSort(int L, int R)        
{
    int B, temp, i, j;

    B = Array[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j)
    {
        while (Array[i] < B) i = i + 1;
        while (Array[j] > B) j = j - 1;
        if (i <= j)
        {
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    }
    if (L < j) QuickSort(L, j);
    if (i < R) QuickSort(i, R);
}

//сортування метод «швидкого сортування» (сортування Хоара) тривимірного масиву
void QuickSort3D(int L, int R, int k)
{
    int B, temp, i, j;

    B = Array3D[k][0][(L + R) / 2];
    i = L;
    j = R;
    while (i <= j)
    {
        while (Array3D[k][0][i] < B) i = i + 1;
        while (Array3D[k][0][j] > B) j = j - 1;
        if (i <= j)
        {
            for (int m = 0; m < ROW; m++)
            {
                temp = Array3D[k][m][i];
                Array3D[k][m][i] = Array3D[k][m][j];
                Array3D[k][m][j] = temp;
            }
            i = i + 1;
            j = j - 1;
        }
    }
    if (L < j) QuickSort3D(L, j, k);
    if (i < R) QuickSort3D(i, R, k);
}
