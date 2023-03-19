#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//通讯录
//1.通讯录中能存放1000人的信息
//信息：
//名字+年龄+性别+电话+住址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录的信息
//
void menu() {
	printf("************************************\n");
	printf("*****  1.add      2.del     ********\n");
	printf("*****  3.search   4.modify  ********\n");
	printf("*****  5.sort     6.print   ********\n");
	printf("**********  0. exit   **************\n");
	printf("************************************\n");
	
	
}
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
};
//创建通讯录
//

int main() {
	int input = 0;
	Contact Con;
	InitContact(&Con);
	do {
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&Con);
			break;
		case DEL:
			DelContact(&Con); 
			break;
		case SEARCH:
			SearchContact(&Con);
			break;
		case MODIFY:
			ModifyContact(&Con);
			break;
		case SORT:
			//待完善
			break;
		case PRINT:
			PrintContact(&Con);
			break;
		case EXIT:
			printf("退出程序\n");
			break;
		}

	} while (input);
	return 0;
}
