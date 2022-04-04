#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"data.h"

void Create(int end)
{
	int i = 0;
	int a = 0;
	errno_t ch;
	FILE* fp;
	ch = fopen_s(&fp, "data.txt", "w");
	if (ch)
	{
		exit(0);
	}
	srand((unsigned)time(NULL));//产生随机数种子
	if (fp) {
		for (i = 0; i < end; i++)
		{
			a = (rand() % 1000);
			fprintf(fp, "%d ", a);
		}
		fclose(fp);
	}
}

void read(int* a,int end)
{
	int i = 0;
	errno_t ch;
	FILE* fp;
	ch = fopen_s(&fp, "data.txt", "r");
	if (ch)
	{
		exit(0);
	}
	if (fp) {

		for (i = 0; i < end; i++)
		{
			fscanf_s(fp, "%d ", &a[i]);
		}
		fclose(fp);
	}
}

void write(int* a,int end)
{
	int i = 0;
	errno_t ch;
	FILE* fp;
	ch = fopen_s(&fp, "data.txt", "w");
	if (ch)
	{
		exit(0);
	}
	if (fp) {
		for (i = 0; i < end; i++)
		{
			fprintf(fp, "%d ", a[i]);
		}
		fclose(fp);
	}
}