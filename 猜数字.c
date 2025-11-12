#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//#include<windows.h>
//int menu()
//{
//	printf("------1.play---2.quit------\n");
//	int input = 0;
//	printf("option:");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("game begins\n");
//			return 1;
//	}
//	else if (input == 2)
//	{
//		printf("game quits\n");
//		return 2;
//	}
//	else
//	{
//		printf("wrong input,choose again\n");
//		return 0;
//	}
//
//}
//void game()
//{
//	printf("I have thought a number ranging from 1 to 100,you can guess now\nYour number:");
//	int real_number = ((rand()%100)+1);
//	int number = 0;
//	scanf("%d", &number);
//	do 
//	{
//		if (number > real_number)
//		{
//			printf("the real_number is smaller,geuss again:");
//			scanf("%d", &number);
//		}
//		if (number < real_number)
//		{
//			printf("the real_number is bigger,geuss again:");
//			scanf("%d", &number);
//		}
//	}
//	while(number !=real_number);
//	if(number == real_number)
//		printf("great,right,the real_number is %d\n",real_number);
//	return;
//}
//int main()
//{
//	int output = menu();
//	srand(time(0));
//	while (output != 2)
//	{
//		if (output == 1)
//		{
//			game();
//		}
//		output = menu();
//	}
//	if (output == 2)
//	return 0;
//}
#include<stdio.h>
int main()
{
	float H_input = 0;
	float C_input = 0;
	scanf("%f %f", &H_input, &C_input);
	float C = (H_input - 32) * 5 / 9.0;
	float H = (C_input * 9 / 5.0) + 32;
	printf("%.2f %.2f", C, H);
	return 0;
}