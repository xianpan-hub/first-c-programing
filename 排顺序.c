//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//#include<windows.h>
//int main()
//{
//	system("shutdown -s -t 60");
//	char input[20] = {"0"};
//	char answer[20] = {"I am a pig" };
//	printf("please input:I am a pig\n");
//	scanf("%s", &input);
//	if (strcmp(input, answer) == 0)
//		system("shutdown \a");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float H_input = 0;
	float C_input = 0;
	scanf("%f %f", &H_input, &C_input);
	float C = (H_input - 32) * 5 / 9.0;
	float H = (C_input / (5 / 9.0)) + 32;
	printf("%.2f %.2f", C, H);
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define PI 3.14159265357
//#include<stdio.h>
//int main()
//{
//    int d = 0;
//    int h = 0;
//    scanf("%d %d", &d, &h);
//    if (d <= 0 || h <= 0)
//    {
//        printf("ÊäÈë´íÎó");
//        return 0;
//    }
//    float L = 2 * PI * d;
//    double S = 2*(PI * (d / 2.0) * (d / 2.0)) + L * h;
//    double V = PI*(d/2.0)*(d / 2.0) * h;
//    printf("%.2f %.2lf %.2lf", L, S, V);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int H = 0;
//	int C = 0;
//	int L = 0;
//	scanf("%d %d %d", &H, &C, &L);
//	int a1 = H + C + L;
//	float a2 = H * C * L;
//	float a3 = (H + C + L) / 3.0;
//	printf("%d %.2f %.2f", a1, a2, a3);
//	return 0;
//}