#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//我国的高考志愿投档是严格按照高考分数从高到低的顺序排列，排列的规则如下：
//首先按照总分降序排列；当总分相同时，再按照语文分数降序排序；当语文分数也相同时，
//再按照数学分数降序排序；当数学分数也相同时，再按照英语分数降序排序。所有分数都相同时，
//再按照录入的顺序排列。这样，每个考生的位序都是唯一的。
//现在给定n（10≤n≤1000）个人的有关信息，按照上述规则排序之后
//，输出最前面的m（1≤m≤n）个人的序号。
int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	int a[100][3];
	for (i = 0; i < n; i++) {//读取三科成绩
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	}
	int b[100];
	for (i = 0; i < n; i++) {//记录总分
		b[i] = a[i][0] + a[i][1] + a[i][2];

	}
	int aa[100];
	for (i = 0; i < n; i++) {
		aa[i] = 0;
	}
	int count = 1;
	for (i = 0; i < n; i++) {
		count = 1;
		for (j = 0; j < n; j++) {
			//比较，如果比下一个小，排名加1
			if (b[i] < b[j]) {
				count++;
			}
			else if (b[i] == b[j]) {
				if (a[i][0] < a[j][0]) {
					count++;
				}
				else if ((a[i][0] == a[j][0]) && (a[i][1] < a[j][1])) {
					count++;
				}
				else if ((a[i][0] == a[j][0]) && (a[i][1] == a[j][1]) && (a[i][2] < a[j][2])) {
					count++;
				}
				else if ((a[i][0] == a[j][0]) && (a[i][1] == a[j][1]) && (a[i][2] == a[j][2]) && (i > j)) {
					count++;
				}
			}
		}
		aa[i] = count;
	}
	int bb = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			//两重循环，从第一名开始输出
			if (aa[j] == bb) {
				printf("%d ", j + 1);
				bb++;
				break;
			}
		}
	}


	return 0;
}