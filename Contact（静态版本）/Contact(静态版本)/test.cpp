#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//ͨѶ¼
//1.ͨѶ¼���ܴ��1000�˵���Ϣ
//��Ϣ��
//����+����+�Ա�+�绰+סַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼����Ϣ
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
//����ͨѶ¼
//

int main() {
	int input = 0;
	Contact Con;
	InitContact(&Con);
	do {
		menu();
		printf("��ѡ��>:");
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
			//������
			break;
		case PRINT:
			PrintContact(&Con);
			break;
		case EXIT:
			printf("�˳�����\n");
			break;
		}

	} while (input);
	return 0;
}
