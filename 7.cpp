#include <stdio.h>
#include<string.h>
#define MAX_LEN 12
typedef struct UserInformation UI;
typedef struct UserInformation* P_UI;
struct UserInformation {
	char name[12];
	int age;
};

int main()
{
	UI u[2];
	P_UI p_u[2] = {&u[0], &u[1]};
	//ù��° ��Ҵ� ����ü�����ͺ����̿��ؼ� �ʱ�ȭ
	p_u[0]->age = 23;
	const char* ap_str = "ȫ�浿";
	//�Ʒ� �� �� ��� ����
	strcpy_s(p_u[0]->name, strlen(ap_str) + 1, "ȫ�浿");
	strcpy_s(p_u[0]->name, strlen(ap_str) + 1, ap_str);
	
	p_u[1]->age = 24;
	const char name[12] = "�迬��";
	const char(*ap_str1)[MAX_LEN] = &name;
	strcpy_s(p_u[1]->name, MAX_LEN, *ap_str1);
	
	for(int i=0;i<2;i++)	printf("%d, %s\n", p_u[i]->age, p_u[i]->name);
	
	//�ٸ��ʱ�ȭ�������
	//�ݵ�� ������� ������� �ʱ�ȭ���ֱ�
	UI u2[2] = { {"���",23}, {"�Ƿη�", 22} };

	//�����ͺ����� ����ų �� �ִ� ũ�⸦ �������(������ ����ü ���� 1���� ����Ű�� ����ü ������ ������ �Ѵ�)
	//�ּҿ����� �̿��ؼ� ���� ����ü ������ ����ų �� �ֵ��� �Ѵ�(�̶� ����ü��������� �־ �� ���� ����Ʈ ���� ���߾�
	//�� ���� ����Ʈ ���� ����� �ش��ϴ� �ּҿ��� �����ؼ� �� ���� ����Ʈ ���� ����� �ش��ϴ� �ּҿ��� ������ �Ǿ��ֱ� ������
	//����ü ������ �迭�� ������ ���Ҹ� ����ü ������ ����(�ϳ��� ����ü ������ ����ų �� �ֵ��� �ڷ����� ������ ����)�� ����ų �� �ִ�
	P_UI p_u3 = &u2[0];
	//�ּҿ������� for������ �� ���Ҹ� ��� ����Ѵ�
	for (int i = 0; i < 2;i++) {
		printf("%d, %s\n", p_u3->age, p_u3->name);
		p_u3++;
	}

	return 0;
}