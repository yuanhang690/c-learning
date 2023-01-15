#include <stdio.h>
#include <stdlib.h>
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void bubble_sort(int* arr,int sz){
	int i=0,j=0;
	int temp;
	for(i=0;i<sz-1;i++){
		//一趟排序 
		for(j=0;j<sz-1-i;j++){
			if(arr[j]>arr[j+1]){//两两比较 
				temp=arr[j];
				arr[j]=arr[j+1];//交换 
				arr[j+1]=temp;
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int main(){
	int arr[]={9,8,7,6,5,4,3,2,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr, sz);
	//运用qsort函数 
	//	void qsort(void* base, //base中存放的是待排序数据中第一个对象的地址
	//			size_t num, //排序数据元素的个数
	//			size_t size,//排序数据中一个元素的大小，单位是字节
	//			int (*cmp)(const void* e1, const void* e2)//是用来比较待排序数据中的2个元素的函数
	//			);
	qsort(arr , sz , sizeof(arr[0]) , cmp_int);
	print_arr(arr, sz);
	return 0;
}


