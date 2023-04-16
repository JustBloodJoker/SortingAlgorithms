#pragma once
#include <time.h>

#define measurements_number 28
#define rejected_number 2
#define min_max_number 3

clock_t result[measurements_number];

float Measurement();

void Exchange4Measurement(int mode);
void Exchange4Measurement3D(int mode);
void Select2Measurement(int mode);
void Select2Measurement3D(int mode);
void QuickSortMeasurement(int mode);
void QuickSortMeasurement3D(int mode);

