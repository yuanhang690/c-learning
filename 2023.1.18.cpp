#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
///继17号
int main() {
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48	解释：sizeof里放着数组名，所以算得是整个数组大小，3行4列共12个元素，12*4=48

	printf("%d\n", sizeof(a[0][0]));//4		解释：表示第一行第一个元素，就是4
	printf("%d\n", sizeof(a[0]));//16	解释：a[i]表示的是第i行的数组名，这里为第一行数组名
								//		（可以将二维数组的每一行看成一个一维数组）所以求的是第一行的大小4*4=16
								//a[0]表示整个第一行

	printf("%d\n", sizeof(a[0] + 1));//4/8		解释：a[0]为数组名，没有单独出现所以这里表示第一行第一个元素的地址
							//					+1就表示第二个元素的地址

	printf("%d\n", sizeof(*(a[0] + 1)));//4		//解释：结合上题这里算的是第一行第二个元素的大小

	printf("%d\n", sizeof(a + 1));//4		解释：数组名a没有单独出现，也没有取地址，这里表示首元素的地址
											//a+1就是第二行的地址
	//注意：二维数组首元素的是第一行

	printf("%d\n", sizeof(*(a + 1)));//16		解释：a+1是第二行地址，整个解引用找到了第二行，
									//			所以这里算得是第二行的大小

	printf("%d\n", sizeof(&a[0] + 1));//4		解释：a[0]是第一行的数组名，&后加1就是第二行的地址


	printf("%d\n", sizeof(*(&a[0] + 1)));//16		解释：结合上题加了解引用后就找到第二行，算的是第二行的大小4*4=16

	printf("%d\n", sizeof(*a));//16			解释：a是数组名没有单独出现，也没有&，因此这里a是首元素地址即第一行，
												//加了*后算的是第一行的大小4*4=16

	printf("%d\n", sizeof(a[3]));//16		解释a[3]算的是第四行的数组名（假如存在的话），但是即使没有也会通过数组的类型
					//来计算大小sizeof()内部的表达式在实际上是不算的
			

	return 0;

	}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//程序的结果是什么？
//答：2,5

