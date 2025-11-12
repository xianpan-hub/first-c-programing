#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//递归(An=if（）->An-1(自身)+一步代码)、迭代（while()->全部代码）的核心是找通项、递推式，先观察原型（常数），再找规律，并用代码实现
//递归：将复杂问题拆成第一步骤，和剩下步骤；一步步拆至剩下一步为止，递归终止（迭代同理）
//---------------------------------------------------------------------------------------------------------------------------------
//按位顺序打印函数（递归）
// 原型：PR_NUM(123)=printf("1");PR_NUM(23)->用代码实现？
// 打印第一位不好实现？->改为打印最后一位（%10）:PR_NUM(a)=printf("a%10");PR_NUM(a/10);
// 什么时候递归，递归什么时候结束？->if判断，a>=10递归
// 反向输出？->递归结束后，代码从最内层开始运行
void PR_NUM_OR(int a)
{
	static int i = 0;
	//当未拆至剩只下一步，调用自身递归
	if (a >= 10)
	{
		i++;
		PR_NUM_OR(a / 10);
		i--;
	}
	//最外层，最后实现
	printf("%d ", a % 10);
	if (i == 0)
	{
		printf("\n");
	}
}
//按位逆序打印函数（递归）
void PR_NUM_NOR(int a)
{
	//先打印，再递归
	printf("%d ", a % 10);
	static int i = 0;
	//当未拆至剩只下一步，调用自身递归
	if (a >= 10)
	{
		i++;
		PR_NUM_NOR(a / 10);
		i--;
	}
	if (i == 0)
	{
		printf("\n");
	}
}
//my_strlen(递归)：MY_STR(str)=num+1;MY_STR(str+1)(当*str!='\0')
void MY_STR(char* str)
{
	static int num = 0;
	if (*str != '\0')
	{
		num++;
		MY_STR(str + 1);
	}
	else
	{
		printf("%d\n", num);
		num = 0;
	}
}
