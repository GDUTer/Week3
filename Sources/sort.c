#include<stdio.h>
#include"sort.h"
int cnt[10][25000] = { 0 };
void swap(int* a, int* b)
{
	int s = *a;
	*a = *b;
	*b = s;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort2(int* a, int begin,int end)
{
	int i, j;
	for (i = begin;i < end+1; i++)
	{
		int x = a[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (x < a[j])
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = x;
	}
}

void insertSort(int* a, int n)
{
	int i, j;
	for (i = 1;i < n; i++)
	{
		int x = a[i];
		for (j = i - 1;j >= 0;j--)
		{
			if (x < a[j])
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = x;
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin, j = mid+1, k = begin;//i☞a的前一半，j☞a后一半，k☞temp
	for (;i <= mid && j <= end;k++)
	{
		if (a[i] < a[j]) {
			temp[k] = a[i++];
		}
		else {
			temp[k] = a[j++];
		}
	}
	while (j <= end ) {
		temp[k] = a[j];
		k++;
		j++;
	}
	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp)
{

	int temp2[10000];
	if (begin == end)
		temp[begin] = a[begin];
	else 
	{
		int mid = (end + begin) / 2;
		MergeSort(a, begin, mid, temp2);
		MergeSort(a, mid+1, end, temp2);
		MergeArray(temp2, begin, mid, end, temp);
	}

}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	int p0 = 0, p1 = size-1, p = 0;
	while (p <=p1)
	{
		if (a[p] == 0) {
			swap(&a[p], &a[p0]);
			p0++;
			p++;
		}

		else if (a[p] == 2)
		{
			swap(&a[p], &a[p1]);
			p1--;
		}
		else
			p++;
	}
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
	int i, j = 0;
	int cnt[1000] = { 0 };

	for (i = 0;i < size;i++) {
		cnt[a[i]]++;
	}
	for (i = 0;i < size;i++) {
		while (cnt[j] == 0)
			j++;
		a[i] = j;
		cnt[j]--;
	}
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	int flag = 1, i, w = 0, wcnt=0,j;
	//确定最大数的位数wcnt,和对应位数的最小数w（如100，1000，10这样子）
	for (i = 0;i < size;i++)
	{
		int n = 1;
		while (n < a[i]) {
			n *= 10;
		}
		if (n > w)
			w = n;
	}
	w /= 10;
	while (w)
	{
		w/= 10;
		wcnt++;
	}

	//w复用于得到数据的第n位，当w=10，取个位；当w=100，取十位……
	w = 10;

	for (;wcnt;wcnt--) 
	{
		int p[10] = {0};//p[i]指cnt[i][]，用于标记再二维数组中存到第几位
		//int p2[10] = { 0 };
		int p2;//初始化为0,指向cnt[i][]。在二维数组cnt[i][j]中，若j>1,则cnt[i][j]>cnt[i][j-1]，所以应从cnt[i][0]开始，排队赋值给原数组a[];
		for (i = 0;i < size;i++) {//把a[]的数据计到二维数组cnt[][]中
			cnt[(a[i] % w) / (w / 10)][p[(a[i] % w) / (w / 10)]] = a[i];
			p[(a[i]%w)/(w/10)]++;
		}

		for (i = 0,j=0;i < size;) {//将计入cnt中的数依次赋值给a[]
			p2 = 0;
			while (p2!=p[j]&&i<size) {
				a[i] = cnt[j][p2];
				p2++;
				i++;
			}
			j++;
		}
		w *= 10;//变为下一位
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int  p2 = end, p = begin;
	while (p < p2)
	{
		while (a[p2] >= a[p] && p < p2)
			p2--;
		if (p >= p2)break;
		swap(&a[p2], &a[p]);
		p++;
		while (a[p] < a[p2] && p < p2)
		p++;
		if (p >= p2)break;
		swap(&a[p], &a[p2]);
		p2--;
	}
	if (begin< p) {
		QuickSort_Recursion(a, begin, p);
	}
	if(p+1<end){
		QuickSort_Recursion(a, p + 1, end);
	}
}

void QuickSort_Recursion2(int* a, int begin, int end)//优化版
{
	if (begin + 20 > end)
	{
		insertSort(a,end-begin+1);
	}
	else {
		int p=Partition(a, begin, end);
		QuickSort_Recursion(a, begin, p);
		QuickSort_Recursion(a, p + 1, end);
	}
}//优化版

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end)
{	
	//三数取中，与begin交换
	int b[3] = { a[begin ], a[end], a[(begin + end) / 2]};
	insertSort(b, 3);
	if (b[1] == a[end]){
		swap(&a[begin], &a[end]);
	}
	else if (b[1] == a[begin + end] / 2) {
		swap(&a[begin], &a[(end+begin)/2]);
	}
	//将大于/小于枢轴的数，放置于枢轴两边
	while (begin < end)
	{
		while (a[end] >= b[1] && begin < end)
			end--;
		a[begin] = a[end];
		while (a[begin] <= b[1] && begin < end)
			begin++;
		a[end] = a[begin];
	}
	a[begin] = b[1];
	return begin;
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size)
{
	int stack[300];//数组栈
	int p = 1;//指向栈顶
	int begin = 0;
	stack[0] = size - 1;
	while (p>0)
	{
		if (stack[p-1] > begin + 20) {
			stack[p]=Partition(a, begin, stack[p-1]);
			p++;
		}
		else {
			insertSort2(a,begin,stack[p-1]);
			begin = stack[p-1] + 1;
			p--;
		}
	}
}
