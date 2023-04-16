#pragma once

//розмір одновимірного масиву
#define ARRLEN 5000
int* Array;

//кількість перерізів
#define SECT 3
//кількість рядків
#define ROW 10
//кількість стовпців
#define COL 150
int*** Array3D;

//виділення пам`яті для одновимірного масиву
#define _1DAllocation(_1dArr, SIZE){ _1dArr = (int*)malloc(SIZE * sizeof(int)); }
//очищення пам`яті виділенної для одновимірного масиву
#define _1DRelease(_1dArr){ free(_1dArr); }
//вивід даних одновимірного масиву
#define _1DPrint(_1dArr, SIZE){ for (int i = 0; i < SIZE; i++)							  \
								{														  \
									printf("%4d ", _1dArr[i]);							  \
								}}														  \

//виділення пам`яті для тривимірного масиву
#define _3DAllocation(_3dArr, sector, row, col) { _3dArr = (int***)malloc(SECT * sizeof(int**));      \
													for (int k = 0; k < SECT; k++)					  \
													{												  \
													_3dArr[k] = (int**)malloc(ROW * sizeof(int*));	  \
													for (int i = 0; i < ROW; i++)					  \
													_3dArr[k][i] = (int*)malloc(COL * sizeof(int));	  \
													}}												  \
//очищення пам`яті виділенної для тривимірного масиву
#define _3DRelease(_3dArr, sector, row, col) {  for (int k = 0; k < SECT; k++)                        \
												{												      \
												for (int i = 0; i < ROW; i++)						  \
												free(_3dArr[k][i]);								      \
												free(_3dArr[k]);									  \
												}													  \
												free(_3dArr); }									      \
//вивід даних тривимірного масиву
#define _3DPrint(_3dArr, sector, row, col) { for (int k = 0; k < sector; k++)					      \
												{													  \
												for (int j = 0; j < col; j++)						  \
												{											          \
												for (int i = 0; i < row; i++)					      \
													printf("%4d ", _3dArr[k][j][i]);			      \
													putchar('\n');							          \
												}											          \
												putchar('\n');										  \
												}}													  \


enum {
	_MEASUREMENTS = 1,
	_TESTING = 2,
	_EXIT = 3
};

enum {
	_3DARRAY = 1,
	_ARRAY = 2
};

enum {
	_FALSE,
	_TRUE
};

enum {
	_EXCHANGE4 = 1,
	_SELECT2 = 2,
	_QUICKSORT = 3,
	_ALL = 4
};

enum {
	_RANDOM,
	_ORDERED,
	_BACKORDERED
};