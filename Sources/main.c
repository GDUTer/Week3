#include<stdio.h>
#include"sort.h"
#include<time.h>
#include"data.h"
int a[200000] = { 0 };
int temp[200000];
int main()
{
	int i, scan, end = 0,scan2,flag=0;
	CreateMenu();
	printf("请输入菜单编号：");
	scanf_s("%d", &scan);
	if (scan == 1) {
		end = 10000;
		Create(end);
		read(a, end);
	}
	else if (scan == 2) {
		end = 50000;
		Create(end);
		read(a, end);
	}
	else if (scan == 3) {
		end = 200000;
		Create(end);
		read(a, end);
	}
	else if (scan == 4)
	{
		flag = 1;
		end = 100;
		Create(end);
		read(a, end);
	}

	SortMenu();
	printf("请输入菜单编号：");
	scanf_s("%d", &scan2);

	int start = clock();
	if (scan == 4) {
		for (int i = 0;i < 1000;i++) {
			Create(end);
			read(a, end);
			if (scan2 == 1)
			{
				QuickSort_Recursion(a, 0, end - 1);
			}
			else if (scan2 == 3)
			{
				QuickSort_Recursion2(a, 0, end - 1);
			}
			else if (scan2 == 5)
			{
				QuickSort(a, end);
			}
			else if (scan2 == 2)
			{
				CountSort(a, end, 999);
			}
			else if (scan2 == 4)
			{
				RadixCountSort(a, end);
			}
			else if (scan2 == 6)
			{
				insertSort(a, end);
			}
			else if (scan2 == 7)
			{
				MergeSort(a, 0, end - 1, a);
			}
		}
	}
	else {
		if (scan2 == 1)
		{
			QuickSort_Recursion(a, 0, end - 1);
		}
		else if (scan2 == 3)
		{
			QuickSort_Recursion2(a, 0, end - 1);
		}
		else if (scan2 == 5)
		{
			QuickSort(a, end);
		}
		else if (scan2 == 2)
		{
			CountSort(a, end, 999);
		}
		else if (scan2 == 4)
		{
			RadixCountSort(a, end);
		}
		else if (scan2 == 6)
		{
			insertSort(a, end);
		}
		else if (scan2 == 7)
		{
			MergeSort(a, 0, end - 1, a);
		}
	}
	printf("运行时长为：%d ms\n", clock() - start);
	//for (i = 0;i < end;i++)
		//printf("%d\t", a[i]);
	write(a, end);
	return 0;
}


void CreateMenu()
{
	printf("\n  生成数据选择菜单菜单\n"
		"1.生成 10，000个测试数据\n2.生成 50，000个测试数据\n3.生成200，000个测试数据\n4.生成100个数据，测试1000次\n\n");
}

void SortMenu()
{
	printf("\n  排序方式选择菜单菜单\n"
		"1.快速排序（递归版）1.0		2.计数排序\n"
		"3.快速排序（递归版）2.0		4.基数计数排序\n"
		"5.快速排序（非递归版）		6.插入排序\n"
		"7.归并排序(不能用于测试10000以上)\n\n");
}