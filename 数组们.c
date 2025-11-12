
#include"ar.h"
void SC(int* arr, int size)
{
	for (int j = 0; j <= size - 1; j++)
	{
		scanf("%d", &arr[j]);
	}
}
void PR(int* arr, int size)
{
	for (int j = 0; j <= size - 1; j++)
	{
		printf("%d ", arr[j]);
		if (j == size - 1)
		{
			printf("\n");
		}
	}
}
void OR_NO(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				EX(arr[j], arr[j + 1]);
			}
		}
	}
}
void OR_FI(int* arr, int size)
{
	for (int i = 0; i <=size - 1; i++)
	{
		int max = arr[i];
		int j_ = 0;
		for (int j=i; j <=size - 1; j++)
		{
			if (max <= arr[j])
			{
				max = arr[j];
				j_ = j;
			}
		}		
		EX(arr[j_], arr[i]);
	}
}
void OR_ST(int* arr, int size)
{

	for (int i = 0; i <=size - 1; i++)
	{	
		for (int j = 0; j <i; j++)
		{
			if (arr[i]> arr[j])
			{
				
				for (int j2 = i; j2-1 >= j; j2--)
				{
					EX(arr[j2-1], arr[j2]);
				}
			}
		}
	}
}
void FI_TW(int* arr, int size)
{
	printf("input a number,we try to find it in arr:\n");
	int num = 0;
	scanf("%d", &num);
	int lef = 0;
	int rig = size - 1;
	do {
		int mid = (lef + rig) / 2;
		if (arr[mid] > num)
		{
			lef = mid + 1;
		}
		else if (arr[mid] < num)
		{
			rig = mid - 1;
		}
		else
		{
			printf("find %d is arr[%d]\n", num, mid);
			break;
		}
	} while (lef <= rig);
	if (lef > rig)
	{
		printf("%d isn't in arr\n", num);
	}
}
void AV(int (*arr)[3], int size1,int size2, int* arr_av, int size_)
{
	for (int i = 0; i <= size1 - 1;i++)
	{
		for (int j = 0; j <= size2 - 1; j++)
		{
			arr_av[i] = arr[i][j] + arr_av[i];
		}
		arr_av[i] = arr_av[i]/(size2);
	}
}
void SC_(int (*arr)[3], int size1, int size2)
{
	for (int i = 0; i <= size1 - 1; i++)
	{
		for (int j = 0; j <= size2 - 1; j++)
		{
			scanf("%d", &arr[i][j]);
			while (getchar() != '\n');
		}
	}
}
void PR_(int (*arr)[3], int size1, int size2)
{
	for (int i = 0; i <= size1 - 1; i++)
	{
		for (int j = 0; j <= size2 - 1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void PR_T(int (*arr)[3], int size1, int size2)
{
	for (int i = 0; i <= size2 - 1; i++)
	{
		for (int j = 0; j <= size1 - 1; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
}
void T(int* arr,int* arr_, int size,int tem)
{
	for (int i = 0; i < size; i++)
	{
		arr_[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				arr_[i]++;
			}
		}
	}
}
