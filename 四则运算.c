#include <stdio.h>

#include <ctype.h>

#include <time.h>

#include <stdlib.h>

#include <windows.h>

#define IDNO_LENGTH 6

#define CALC_KIND 4



char getSignal();

int getResult(int, int, char);

void takeTest();

void falsePrint(int);

void correctPrint(int);





void main()

{

	while (1)

	{

		takeTest();

	}



}




char getSignal()

{

	char signal[CALC_KIND] = { '+', '-', '*', '/' };

	srand((unsigned)time(NULL));

	return signal[rand() % 4];

}





int random(double start, double end)

{

	return (int)(start + (end - start)*rand() / (RAND_MAX + 1.0));

}



//运算

int getResult(int num1, int num2, char signal)

{

	int res;

	switch (signal)

	{

	case '+':

		res = num1 + num2; break;

	case '-':

		res = num1 - num2; break;

	case '*':

		res = num1*num2; break;

	case '/':

		res = num1 / num2; break;

	default:

		res = 0;

		printf("运算符不符合规则\n");

	}

	return res;

}



//列出题目

void takeTest()

{

	int giveRes;

	int num1;

	int num2;

	char signal;

	int printFlag;



	srand((unsigned)time(NULL));

	signal = getSignal();

	num1 = random(0, 100);

	num2 = random(1, 100);



	if (signal == '-')

	{

		if (num1<num2)

		{

			int temp;

			temp = num1;

			num1 = num2;

			num2 = temp;

		}

	}



	if (signal == '/')

	{

		if (num2 == 0)

		{

			int temp;

			temp = num1;

			num1 = num2;

			num2 = temp;

		}

	}



	printf("%d%c%d=", num1, signal, num2);

	scanf_s("%d", &giveRes);

	fflush(stdin);



	if (getResult(num1, num2, signal) == giveRes)

	{

		printFlag = random(1, 5);

		correctPrint(printFlag);

	}

	else

	{

		printFlag = random(1, 4);

		falsePrint(printFlag);

		printf("正确答案：%d\n", getResult(num1, num2, signal));

	}

}





void correctPrint(int num)

{

	switch (num)

	{

	case 1:

		printf("你是对的!\n"); break;

	case 2:

		printf("还好还好!\n"); break;

	case 3:

		printf("正确!\n"); break;

	case 4:

		printf("很好!\n"); break;

	case 5:

		printf("好!\n"); break;

	default:

		printf("加油!\n"); break;

	}

}





void falsePrint(int num)

{

	switch (num)

	{

	case 1:

		printf("错误!"); break;

	case 2:

		printf("错误!"); break;

	case 3:

		printf("加油啊!"); break;

	case 4:

		printf("这是错的!"); break;

	default:

		printf("不对啊啊啊啊啊啊!"); break;

	}

}