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
        /* �������� ����������� ���������� �����:
        ���� 1. ³��������� rejected_number ������ ����� � ���������
        �� 0 �� rejected_number-1.
        ���� 2. ����� ����� �������� ��������� min_max_number ����� � ���������� ���������� �� min_max_number ����� � ������������� ����������, � ����� �������� ��.
        ���� 3. ��������� ������ �������� �����, �� ����������.
        */
        //-----------------------------------------------------------
            /* ���� 1. ��� ��������� ����� 1 ������ �������� �������� �
            ������� rejected_number.
            */
            /* ���� 2.
            ��� ����������� min_max_number ��������� � ������������
            ������� ����� �������� min_max_number �������� ���������
            ����� ��������� ���������� ���������� � ������� ������� ��
            rejected_number �� measurements_number-1.
            � ���������, min_max_number ��������� ������� ����� ������ ����������� �� �������� � ������� ������� ��
            rejected_number �� rejected_number+min_max_number-1, �
            min_max_number ������������ ������� ����� � �� �������� �
            ������� ������� �� measurements_number-min_max_number ��
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
    // ���� 3.
        /* ��������� ������ �������� ����� ���� ���������
        rejected_number ������ ����� �� min_max_number ����� �
        ���������� ���������� � min_max_number ����� � ������������� ����������, ����� ������ �������� ����� � �������
        ������� �� rejected_number + min_max_number ��
        measurements_number - min_max_number - 1.
        */
    for (int i = rejected_number + min_max_number; i <
        measurements_number - min_max_number; i++)
        sum += result[i];
    /* ʳ������ �����, �� ���������� ��� ���������� ����������
    ��������, �������
    measurements_number � 2 * min_max_number - rejected_number
    */
    return (float)sum / (measurements_number -
        2 * min_max_number - rejected_number);
}

void _1DOption(void(FillFunction)(int*, const int), clock_t(SortFunction)(int*, const int));
void _3DOption(void(FillFunction)(int***, const int, const int, const int), clock_t(SortFunction)(int***, const int, const int, const int));

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� #4 ������� ����� (�������� ����������) 
//������������ ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� #4 ������� ����� (�������� ����������)
//����������� ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� #2 ������� ������ 
//������������ ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� #2 ������� ������ 
//����������� ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� �������� ���������� (���������� �����)
//������������ ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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

//������� ��� �������� result[measurements_number] ����������� ���������� ������� ���������� ������� �������� ���������� (���������� �����)
//����������� ������ ��� ����� �������� ���������� ������ (�������� �� ���������� ������� � �������)
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



