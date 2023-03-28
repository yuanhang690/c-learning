#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//静态版
//void InitContact(Contact* pc) {
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态版&&文件
void InitContact(Contact* pc) {
	//初始化容量为3
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	//最大容量：3
	pc->capacity = DEFAULT_SZ;
	//加载文件
	LoadContact(pc);
}

//加载通讯录
void LoadContact(Contact* pc) {
	
	FILE* pf=fopen("contact.dat", "r");
	if (pf == NULL) {
		perror("LoadContact");
		return;
	}
	PeoInfo tem = { 0 };
	
	while (fread(&tem, sizeof(PeoInfo), 1, pf)) {
		//考虑增容
		CheckContact(pc);
		pc->data[pc->sz] = tem;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//是否增容
void CheckContact(Contact* pc) {
	if (pc->sz == pc->capacity) {
		//考虑增大容量
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL) {
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else {
			perror("AddContact");
			printf("添加联系人失败\n");
			return;
		}

	}
}


//保存通讯录（写入文件）
void SaveContact(Contact* pc) {
	FILE* pf=fopen("contact.dat", "w");
	if (pf == NULL) {
		perror("SaveContact");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

void DestoryContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
//动态版本-增加联系人
void AddContact(Contact* pc) {
	//考虑增容
	CheckContact(pc);
	printf("请输入姓名：>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
}


//静态版本
//void AddContact(Contact* pc) {
//	if (pc->sz == MAX) {
//		printf("通讯录已满，无法添加！\n");
//		return;
//	}
//	printf("请输入姓名：>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄：>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别：>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话：>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址：>");
//	scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//}
void PrintContact(Contact* pc) {
	int i = 0;
	printf("%-15s\t%-8s\t%-8s\t%-20s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++) {						//data里不要填sz，因为不从0开始
		printf("%-15s\t%-8d\t%-8s\t%-20s\t%-30s\n", pc->data[i].name
			, pc->data[i].age
			, pc->data[i].sex
			, pc->data[i].tele
			, pc->data[i].addr);

												  
	}
}
int FindByName(Contact* pc, char name[]) {
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->data[i].name, name) == 0)
			return i;//找到了，返回下标
	}
	return -1;
	//没找到，返回-1
}
void DelContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("通讯录为空，无需删除");
		return;
	}
	printf("请输入要删除的人名：>");
	scanf("%s", name);
	int pos=FindByName(pc, name);
	if (pos == -1) {
		printf("要删除的人不存在,请重选\n");
		return;
	}
	//1.查找指定联系人
	else {
		int i = 0;
		for (i = pos; i < pc->sz-1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功！\n");
	}
	//2.删除

}
void SearchContact(Contact* pc) {
	if (pc->sz == 0) {
		printf("通讯录为空！");
		return;
	}
	char name[MAX_NAME];
	printf("请输入要查找的人名：>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("要查找的人不存在,请重选\n");
		return;
	}
	else {
		printf("%-15s\t%-8s\t%-8s\t%-20s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-15s\t%-8d\t%-8s\t%-20s\t%-30s\n",pc->data[pos].name,pc->data[pos].age,
													pc->data[pos].sex,
													pc->data[pos].tele,
													pc->data[pos].addr);

		printf("查找成功！\n");
	}
}
void ModifyContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的人名：>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("查无此人！");
		return;
	}
	else {
		printf("请您修改：\n");
		printf("请输入姓名：>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", pc->data[pos].addr);
	}
	printf("修改成功！\n");
}