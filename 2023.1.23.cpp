//给定n（1≤n≤100）个学生的姓名和成绩，按照成绩从高到低排序输出。学生的姓名不会重复，
//如果有成绩相同的，则原来在名单中靠前的同学仍然排列在前面。
//第一行输入n，表示共几个学生，后免输入n个学生的名字，成绩，用空格分隔，每输入一个人后换行 
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	char arr[20];
	int i = 0, n = 0,count=0,j=0,x;
	struct student {
		char name[20];
		int score;
	};
	struct student stu[50];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s%d", stu[i].name, &stu[i].score);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (stu[j].score < stu[j + 1].score) {
				strcpy(arr, stu[j].name);
				strcpy(stu[j].name, stu[j + 1].name);
				strcpy(stu[j + 1].name, arr);
				x = stu[j].score;
				stu[j].score = stu[j + 1].score;
				stu[j + 1].score = x;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s ", stu[i].name);
		printf("%d\n", stu[i].score);
	}
	
	
	return 0;
}
