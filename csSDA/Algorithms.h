#pragma once

#include <time.h>

clock_t Exchange4(int* A, const int size);
clock_t Exchange43D(int*** Arr3D, const int sector, const int col, const int row);
clock_t Select2(int* A, const int size);
clock_t Select23D(int*** Arr3D, const int sector, const int col, const int row);
void QuickSort(int L, int R);
void QuickSort3D(int L, int R, int k);


