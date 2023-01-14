#include <stdio.h>
int input = 0;
void menu() {
	printf("***********************************\n");
	printf(" 1.add			2.sub	  \n");
	printf(" 3.mul			4.div	  \n");
	printf("***********************************\n");
	printf("请选择>");
    scanf("%d", &input);
    
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x-y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int main() {
	int x, y;
	
	int ret = 0;
	do {
		menu();
        
		switch (input) {
        case 1:
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = add(x, y);
            printf("ret = %d\n", ret);
            break;
        case 2:
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = sub(x, y);
            printf("ret = %d\n", ret);
            break;
        case 3:
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = mul(x, y);
            printf("ret = %d\n", ret);
            break;
        case 4:
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = div(x, y);
            printf("ret = %d\n", ret);
            break;
        case 0:
            printf("退出程序\n");
            break;
        default:
            printf("选择错误\n");
            break;
		}
    } while (input);

	return 0;
}
//运用函数指针数组优化后： 
//int main() {
//    int x, y;
//    int input = 1;
//    int ret = 0;
//    int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表
//    //将运算函数存入数组；
//    menu();
//    while (input)
//    {
//        
//        if ((input <= 4 && input >= 1))
//        {
//            printf("输入操作数：");
//            scanf("%d %d", &x, &y);
//            ret = (*p[input])(x, y);//调用
//        }
//        else
//            printf("输入有误\n");
//        printf("ret = %d\n", ret);
//    }
//
//	return 0;
//}

