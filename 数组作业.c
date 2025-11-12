//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>

//int main()
//{
//	int num1 = 0,num2=0;
//	int* pnum1;
//	int* pnum2;
//	scanf("%d %d", &num1,&num2);
//	pnum1 = (int*)malloc(sizeof(int) * num1);
//	pnum2 = (int*)malloc(sizeof(int) * num2);
//	for (int i = 0; i < num1; i++)
//	{
//		scanf("%d", &pnum1[i]);
//		while (getchar() != '\n');
//	}
//	for (int i = 0; i < num2; i++)
//	{
//		scanf("%d", &pnum2[i]);
//		while (getchar() != '\n');
//	}
//	for (int i = 0; i < num1; i++)
//	{
//		printf("pnum1[%d]=%2d ", i,pnum1[i]);
//		printf("\n");
//	}
//	printf("\n");
//	for (int i = 0; i < num2; i++)
//	{
//		printf("pnum2[%d]=%2d ", i, pnum2[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < num2; i++)
//	{
//		printf("(pnum1*pum2)[%d]=%2d ", i, pnum1[i]	*pnum2[i]);
//	}
//	free(pnum1);
//	free(pnum2);
//	return 0;
//}

////
//int main()
//{
//	int arr1 [] = {8,2,4,5,0,3,1,2,3,6,8,6,3,7,9,7,5,7,6,1};
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//	int l = 0;
//	int arr2[100] = { 0 };
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j <=i; j++)
//		{
//			if (j<i&&arr1[j] == arr1[i])
//			{
//				break;
//			}
//			if (j == i)
//			{
//				arr2[l] = arr1[i];
//				l++;
//			}
//
//		}
//	}
//	for (int i = 0; i < l; i++)
//	{
//			printf("%d ", arr2[i]);	
//	}
//	return 0;
//}

////
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX 100
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int arr1[MAX][MAX] = { 0 };
//	int a, b;
//	int o = 0;
//	scanf("%d %d", &a, &b);
//	for (int i = 0; i < a; i++)
//	{
//		for (int j = 0; j < b; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	for (int i = 0; i < a; i++)
//	{
//		int temp, x, y;
//		for (int j = 0; j < b; j++)
//		{
//			if (j == 0)
//			{
//				temp = arr1[i][j];
//				x = i;
//				y = j;
//			}
//			if (temp < arr1[i][j])
//			{
//				temp = arr1[i][j];
//				x = i;
//				y = j;
//			}
//			if (j == b - 1)
//			{
//				for (int k = 0; k < a; k++)
//				{
//					if (temp > arr1[k][y])
//					{
//						break;
//					}
//					if (k == a - 1)
//					{
//						printf("元素%d位于(%d,%d)是鞍点\n", temp, x, y);
//						o = 1;
//					}
//				}
//			}
//		}
//	}	
//	if (o == 0)
//		{
//			printf("没有鞍点\n");
//		}
//		return 0;
//}

#include<stdio.h>
int main()
{
	float a = 5 / 2.0;
	printf("%f", a);
	return 0;

}
