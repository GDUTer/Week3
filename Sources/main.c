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
	printf("������˵���ţ�");
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
	printf("������˵���ţ�");
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
	printf("����ʱ��Ϊ��%d ms\n", clock() - start);
	//for (i = 0;i < end;i++)
		//printf("%d\t", a[i]);
	write(a, end);
	return 0;
}


void CreateMenu()
{
	printf("\n  ��������ѡ��˵��˵�\n"
		"1.���� 10��000����������\n2.���� 50��000����������\n3.����200��000����������\n4.����100�����ݣ�����1000��\n\n");
}

void SortMenu()
{
	printf("\n  ����ʽѡ��˵��˵�\n"
		"1.�������򣨵ݹ�棩1.0		2.��������\n"
		"3.�������򣨵ݹ�棩2.0		4.������������\n"
		"5.�������򣨷ǵݹ�棩		6.��������\n"
		"7.�鲢����(�������ڲ���10000����)\n\n");
}