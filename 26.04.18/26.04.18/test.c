#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int compar(const void* a, const void* b)
//{
//    if (*(int*) a > *(int*) b)
//    {
//        return 1;
//    }
//    else if (*(int*) a < *(int*) b)
//    {
//        return -1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//int sequentialSearch(int arr[], int n, int target) {
//    int i = 0, left = 0, right = n;
//    int mid = n / 2;
//    for (; i < n; i++) {
//        if (arr[mid] > target)
//        {
//            right = mid;
//            mid = (left + mid) / 2;
//        }
//        else if (arr[mid] < target)
//        {
//            left = mid;
//            mid = (mid + right) / 2;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    int a[] = { 8, 3, 5, 9, 2,1,11,14,13,66,100,28 };
//    int n = sizeof(a) / sizeof(int);
//    int tar = 8;
//
//    qsort(a, n, sizeof(int), compar);
//    int idx = sequentialSearch(a, n, tar);
//
//    if (idx != -1)
//        printf("找到：%d，下标：%d\n", tar, idx);
//    else
//        printf("未找到\n");
//    return 0;
//}



//void bubbleSort(int a[], int n)
//{
//	int j = 0, tmp = 0;
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (j = i; j < n; j++)
//		{
//			if (a[i] > a[j])
//			{
//				tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		}
//	}
//}
//
//void print(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//int main()
//{
//	int a[] = { 24, 30, 12, 40, 50, 33 };
//	int  n = 6;
//
//	bubbleSort(a, n);
//	print(a, n);
//	return 0;
//}

