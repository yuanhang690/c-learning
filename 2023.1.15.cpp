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
		//һ������ 
		for(j=0;j<sz-1-i;j++){
			if(arr[j]>arr[j+1]){//�����Ƚ� 
				temp=arr[j];
				arr[j]=arr[j+1];//���� 
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
	//����qsort���� 
	//	void qsort(void* base, //base�д�ŵ��Ǵ����������е�һ������ĵ�ַ
	//			size_t num, //��������Ԫ�صĸ���
	//			size_t size,//����������һ��Ԫ�صĴ�С����λ���ֽ�
	//			int (*cmp)(const void* e1, const void* e2)//�������Ƚϴ����������е�2��Ԫ�صĺ���
	//			);
	qsort(arr , sz , sizeof(arr[0]) , cmp_int);
	print_arr(arr, sz);
	return 0;
}


