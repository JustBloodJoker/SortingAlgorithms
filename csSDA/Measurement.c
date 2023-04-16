#include "Measurement.h"
#include <stdio.h>
#include "Utilites.h"
#include "FillArray.h"
#include "Algorithms.h"

clock_t result[measurements_number];

float Measurement()
{
    long int sum = 0;
    clock_t temp;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    //-----------------------------------------------------------
        /* Методика усереднення результатів виміру:
        Крок 1. Відкидається rejected_number перших вимірів з індексами
        від 0 до rejected_number-1.
        Крок 2. Серед інших елементів знаходимо min_max_number вимірів з мінімальними значеннями та min_max_number вимірів з максимальними значеннями, і також відкидаємо їх.
        Крок 3. Знаходимо середнє значення вимірів, що залишилися.
        */
        //-----------------------------------------------------------
            /* Крок 1. Для виконання Кроку 1 просто починаємо алгоритм з
            індексу rejected_number.
            */
            /* Крок 2.
            Для знаходження min_max_number мінімальних і максимальних
            значень вимірів виконуємо min_max_number ітерацій головного
            цикла алгоритму шейкерного сортування в діапазоні індексів від
            rejected_number до measurements_number-1.
            В результаті, min_max_number мінімальних значень вимірів будуть знаходитись на позиціях в діапазоні індексів від
            rejected_number до rejected_number+min_max_number-1, а
            min_max_number максимальних значень вимірів – на позиціях в
            діапазоні індексів від measurements_number-min_max_number до
            measurements_number-1.
            */
    
    for (int j = 0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (result[i] > result[i + 1])
            {
                temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--)
        {
            if (result[i] > result[i + 1])
            {
                temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;
                k = i;
            }
        }
        L = k + 1;
    }
    // Крок 3.
        /* Знаходимо середнє значення вимірів після відкидання
        rejected_number перших вимірів та min_max_number вимірів з
        мінімальними значеннями і min_max_number вимірів з максимальними значеннями, тобто середнє значення вимірів в діапазоні
        індексів від rejected_number + min_max_number до
        measurements_number - min_max_number - 1.
        */
    for (int i = rejected_number + min_max_number; i <
        measurements_number - min_max_number; i++)
        sum += result[i];
    /* Кількість вимірів, що залишилась для обчислення середнього
    значення, дорівнює
    measurements_number – 2 * min_max_number - rejected_number
    */
    return (float)sum / (measurements_number -
        2 * min_max_number - rejected_number);
}

void _1DOption(void(FillFunction)(int*, const int), clock_t(SortFunction)(int*, const int));
void _3DOption(void(FillFunction)(int***, const int, const int, const int), clock_t(SortFunction)(int***, const int, const int, const int));

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом #4 прямого обміну (Шейкерне сортування) 
//одновимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void Exchange4Measurement(int mode)
{
    switch (mode) {
    case _RANDOM:
    {
        _1DOption(FillRandomArray, Exchange4);
        break;
    }
    case _ORDERED:
    {
        _1DOption(FillOrderedArray, Exchange4);
        break;
    }
    case _BACKORDERED:
    {
        _1DOption(FillBackOrderedArray, Exchange4);
        break;
    }
    }
}

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом #4 прямого обміну (Шейкерне сортування)
//тривимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void Exchange4Measurement3D(int mode)
{
    switch (mode) {
    case _RANDOM:
    {
        _3DOption(FillRandom3DArray, Exchange43D);
        break;
    }
    case _ORDERED:
    {
        _3DOption(FillOrdered3DArray, Exchange43D);
        break;
    }
    case _BACKORDERED:
    {
        _3DOption(FillBackOrdered3DArray, Exchange43D);
        break;
    }
    }
}

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом #2 прямого вибору 
//одновимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void Select2Measurement(int mode)
{
    switch (mode) {
    case _RANDOM:
    {
        _1DOption(FillRandomArray, Select2);
        break;
    }
    case _ORDERED:
    {
        _1DOption(FillOrderedArray, Select2);
        break;
    }
    case _BACKORDERED:
    {
        _1DOption(FillBackOrderedArray, Select2);
        break;
    }
    }
}

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом #2 прямого вибору 
//тривимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void Select2Measurement3D(int mode)
{
    switch (mode) {
    case _RANDOM:
    {
        _3DOption(FillRandom3DArray, Select23D);
        break;
    }
    case _ORDERED:
    {
        _3DOption(FillOrdered3DArray, Select23D);
        break;
    }
    case _BACKORDERED:
    {
        _3DOption(FillBackOrdered3DArray, Select23D);
        break;
    }
    }
}

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом швидкого сортування (сортування Хоара)
//одновимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void QuickSortMeasurement(int mode)
{
    clock_t time_start, time_stop;

    for (int i = 0; i < measurements_number; i++)
    {
        switch (mode) {
        case _RANDOM:
            FillRandomArray(Array, ARRLEN);
            break;
        case _ORDERED:
            FillOrderedArray(Array, ARRLEN);
            break;
        case _BACKORDERED:
            FillBackOrderedArray(Array, ARRLEN);
            break;
        }

        time_start = clock();
        QuickSort(0, ARRLEN - 1);
        time_stop = clock();
        result[i] = time_stop - time_start;
    }
}

//функція яка заповнює result[measurements_number] поверненими значеннями функції сортування методом швидкого сортування (сортування Хоара)
//тривимірного масиву при трьох варіантах заповнення масиву (залежить від переданого варіанту у функцію)
void QuickSortMeasurement3D(int mode)
{
    clock_t time_start, time_stop;

    for (int i = 0; i < measurements_number; i++)
    {
        switch (mode) {
        case _RANDOM:
            FillRandom3DArray(Array3D, SECT, COL, ROW);
            break;
        case _ORDERED:
            FillOrdered3DArray(Array3D, SECT, COL, ROW);
            break;
        case _BACKORDERED:
            FillBackOrdered3DArray(Array3D, SECT, COL, ROW);
            break;
        }

        time_start = clock();
        for (int k = 0; k < SECT; k++)
        {
            QuickSort3D(0, COL - 1, k);
        }
        time_stop = clock();
        result[i] = time_stop - time_start;
    }
}

void _1DOption(void(FillFunction)(int*, const int), clock_t(SortFunction)(int*, const int))
{
    for (int i = 0; i < measurements_number; i++)
    {
           FillFunction(Array, ARRLEN);
           result[i] = SortFunction(Array, ARRLEN);
    }
}

void _3DOption(void(FillFunction)(int***, const int, const int, const int), clock_t(SortFunction)(int***, const int, const int, const int))
{
    for (int i = 0; i < measurements_number; i++)
    {
        FillFunction(Array3D, SECT, COL, ROW);
        result[i] = SortFunction(Array3D, SECT, COL, ROW);
    }
}



