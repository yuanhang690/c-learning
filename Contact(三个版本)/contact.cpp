#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//��̬��
//void InitContact(Contact* pc) {
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬��&&�ļ�
void InitContact(Contact* pc) {
	//��ʼ������Ϊ3
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	//���������3
	pc->capacity = DEFAULT_SZ;
	//�����ļ�
	LoadContact(pc);
}

//����ͨѶ¼
void LoadContact(Contact* pc) {
	
	FILE* pf=fopen("contact.dat", "r");
	if (pf == NULL) {
		perror("LoadContact");
		return;
	}
	PeoInfo tem = { 0 };
	
	while (fread(&tem, sizeof(PeoInfo), 1, pf)) {
		//��������
		CheckContact(pc);
		pc->data[pc->sz] = tem;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//�Ƿ�����
void CheckContact(Contact* pc) {
	if (pc->sz == pc->capacity) {
		//������������
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL) {
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else {
			perror("AddContact");
			printf("�����ϵ��ʧ��\n");
			return;
		}

	}
}


//����ͨѶ¼��д���ļ���
void SaveContact(Contact* pc) {
	FILE* pf=fopen("contact.dat", "w");
	if (pf == NULL) {
		perror("SaveContact");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

void DestoryContact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
//��̬�汾-������ϵ��
void AddContact(Contact* pc) {
	//��������
	CheckContact(pc);
	printf("������������>");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
}


//��̬�汾
//void AddContact(Contact* pc) {
//	if (pc->sz == MAX) {
//		printf("ͨѶ¼�������޷���ӣ�\n");
//		return;
//	}
//	printf("������������>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("���������䣺>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰��>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ��>");
//	scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//}
void PrintContact(Contact* pc) {
	int i = 0;
	printf("%-15s\t%-8s\t%-8s\t%-20s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++) {						//data�ﲻҪ��sz����Ϊ����0��ʼ
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
			return i;//�ҵ��ˣ������±�
	}
	return -1;
	//û�ҵ�������-1
}
void DelContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ�գ�����ɾ��");
		return;
	}
	printf("������Ҫɾ����������>");
	scanf("%s", name);
	int pos=FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫɾ�����˲�����,����ѡ\n");
		return;
	}
	//1.����ָ����ϵ��
	else {
		int i = 0;
		for (i = pos; i < pc->sz-1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ���\n");
	}
	//2.ɾ��

}
void SearchContact(Contact* pc) {
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�������>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����,����ѡ\n");
		return;
	}
	else {
		printf("%-15s\t%-8s\t%-8s\t%-20s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-15s\t%-8d\t%-8s\t%-20s\t%-30s\n",pc->data[pos].name,pc->data[pos].age,
													pc->data[pos].sex,
													pc->data[pos].tele,
													pc->data[pos].addr);

		printf("���ҳɹ���\n");
	}
}
void ModifyContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ�������>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("���޴��ˣ�");
		return;
	}
	else {
		printf("�����޸ģ�\n");
		printf("������������>");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰��>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", pc->data[pos].addr);
	}
	printf("�޸ĳɹ���\n");
}