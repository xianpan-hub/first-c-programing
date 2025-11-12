
#ifndef AR_H
#define AR_H
#define NUM 7
#define EX(a,b) do{int temp=a;a=b;b=temp;}while(0)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void SC(int* arr, int size);
void PR(int* arr, int size);
void OR_NO(int* arr, int size);
void OR_FI(int* arr, int size);
void OR_ST(int* arr, int size);
void FI_TW(int* arr, int size);
void AV(int (*arr)[3], int size1, int size2, int* arr_av, int size_);
void SC_(int (*arr)[3], int size1, int size2);
void PR_(int (*arr)[3], int size1, int size2);
void PR_T(int (*arr)[3], int size1, int size2);
void T(int* arr,int* arr_, int size,int tem);
#endif
