#include <stdio.h>
void swap(char* buff1,char* buff2,int width){
	int i=0;
	char tmp;
	for(i=0;i<width;i++){
		tmp=*buff1;
		*buff1=*buff2;
		*buff2=tmp;
		buff1++;
		buff2++;
	}
}
void bubble_sort(void* base,int sz,int width,int (*cmp)(const void *e1,const void *e2)){
	int i=0;
	for(i=0;i<sz;i++){
		int j=0;
		for(j=0;j<sz-1-i;j++){
			if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0){
				swap((char*)base+j*width,(char*)base+(j+1)*width, width);
			}
		}
	}
}
int cmp_int(const void* e1,const void*e2){
	return *(int*)e1-*(int*)e2;
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
	

int main(){
	//整形数据的排序
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//排序
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	//打印
	print_arr(arr, sz);
	return 0;
}
