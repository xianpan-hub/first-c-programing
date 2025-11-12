//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	char arr_abc[26] = { 0 };
//	char arr_in[2] = { 0 };
//	int arr_da[26] = { 0 };
//	int size_abc = sizeof(arr_abc) / sizeof(arr_abc[0]);
//	int size = sizeof(arr_in)/ sizeof(arr_in[0]);
//	int bool = 0;
//	for (int i = 0; i <= size_abc - 1; i++)
//	{
//		arr_abc[i] = 'a' + i;
//	}
//	for (int i = 0; i <= size - 1; i++)
//	{
//		printf("input arr_in[%d]:", i);
//		scanf("%c", &arr_in[i]);
//		while (getchar() != '\n');
//	}
//	for (int i = 0; i <= size - 1; i++)
//	{
//		static int j =0;
//		if (arr_in[i] >='a'&& arr_in[i]<='z')
//		{
//
//			arr_da[arr_in[i] -'a']++;
//		}
//		else
//		{
//			j++;
//		}
//		if(i==size-1)
//		{
//			printf("wrong input,%d times\n", j);
//		}
//	}
//	for (int i = 0; i <= size_abc - 1; i++)
//	{
//		if (arr_da[i] != 0)
//		{
//			printf("%c appear %2d times\n", arr_abc[i], arr_da[i]);
//			bool = 1;
//		}
//		if (i == size_abc - 1)
//		{
//			if (bool = 1)
//			{
//				printf("the other appears 0 times\n");
//			}
//			else
//			{
//				printf("the all appears 0 times\n");
//			}
//		}
//	}
//}
//#include "ar.h"
//int main()
//{
//	int tem = 1;
//	int arr[NUM] = { 0 };
//	int arr_[NUM] = { 0 };
//	SC(arr, NUM);
//	T(arr, arr_, NUM,tem);
//	PR(arr, NUM);
//	PR(arr_, NUM);
//	return 0;
//
//}