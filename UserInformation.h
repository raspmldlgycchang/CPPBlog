#pragma once
typedef struct UserInformation UI;
typedef struct UserInformation* P_UI;
typedef char AGE;
typedef char NAME_TYPE[12];

struct UserInformation {
	char name[12];
	int age;
};
struct UserInformationAdd {
	char name[12];
	int age;
	short money;//�л��̴� 6������ �ִٰ� �����ϰ� �ϰڽ��ϴ�
};
void ArrangeMemberByAGE(UI* p_u,int count)
{//���� ����ü ���Ҹ� ���Ƿ� �ƹ��ų� ����Ű�� �����ϹǷ� ù ��° ���Ҹ� ����Ű�� �ϰ� ���� ���Ҵ� �ּҿ������� �����Ѵ�
	for (int pass = 0; pass < count; pass++) {
		for (int i = count - 1; count > pass; count--) {//������ �ε������� �ٿ����鼭 i�ε����� ����
			if (p_u->age < (p_u--)->age) {
				int tmp = p_u->age;
				p_u->age = (p_u--)->age;
				(p_u--)->age = tmp;
			}
			p_u++;
		}
	}
}
void ShowUIAdd(struct UserInformationAdd*);
void SetMoney(UI* p_u, AGE age, int index) {
	//p_u���� ù ��° ������ �ּҸ� �Ѱ��־� �ٸ� ����ü�� ��������� �����Ѵ�
	//�����ڿ켱����: ->������ > &������ > +(����������)
	//&(p_u + index)->age : age������ �ּ�(�����ͺ������� �����ؼ� ����, �ֳĸ� ������ ������ ������ �ּҿ����� ����ϱ� �����̴�)
	//�����ͺ����� �ּҿ��꿡 ���ؼ� +1�� �ϸ� ���� age������ �ش��ϴ� �����ͺ����̹Ƿ� +1�� ������ ������ ���ָ� 4����Ʈ��ŭ �����Ѵ�
	//���� &(p_u + index)->age+1 �� UserInformationAdd�� money������ ����ų �� �ְ� �� ù ��° ������ ���߾���, �ι�° �������δ� ĳ������ ����
	//�� �κ��� �� �𸣽ðڴ� �в����� void*��(13-5��,6����) �������ּ���~
	//short*�� ĳ������ ���ְ�, ���� ���� �����Ǿ�� �ߴ� ������ UserInformationAdd�� ��ü�� ����Ű���� �ϴ°�, �׸��� ������ ����p_u�� UserInformation�� 
	//��ü�̹Ƿ� p_u�� �ٷ� money������ �����ϴ� ���� �Ұ����ϴ�, ������ �ּҿ����� �����ͺ����� ����Ű�� �ڷ����� ������ ����� �����ٴ� Ư����
	//�ּҿ����� Ư���� Ȱ���Ͽ���
	struct UserInformationAdd data;
	data.age = age;
	strcpy_s(data.name, 12, "������");
	p_u = (P_UI)&data;
	*(short*)(&(p_u + index)->age + 1) = 30000;
	ShowUIAdd(&data);
}

void ShowUIAdd(struct UserInformationAdd* p_data) {
	printf("UserInformationAdd ����ü �����Դϴ� :%d, %s, %hd", p_data->age, p_data->name, p_data->money);
}

P_UI FindByAGE(UI* p_u, AGE age, int count) {

	for (int i = 0; i < count; i++) {
		if ((p_u + i)->age == age) {
			return p_u;
		}
	}
	return NULL;
}