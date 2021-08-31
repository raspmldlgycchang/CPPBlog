#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX_PET_COUNT 40
#define PET_TABLE_COUNT 2
class Pet{
public:
	virtual Pet* CreatePet() {
		return NULL;
	}
	virtual const char* GetPetName() {
		return NULL;
	}
	virtual void Feed(){}
	virtual void Bark(){}
};

class Dog : public Pet{
public:
	//virtual Ű����� �θ� Ŭ�������� �ݵ�� ������� �ϰ�, �ڽ�Ŭ������ ���� �ʾƵ� �˴ϴ�
	// ���� ��� A<-B<-C���� A�� �����ְ� B�� C�� �� �����൵ �˴ϴ�
	// �׷��� �����Ҿƹ���, �Ҿƹ���, �θ� �̷��� ��� ������ ��� ���������� �� ���� ����ȴٸ�
	// ��� virtualŰ���� ���� �Լ��� �ڽ�Ŭ�������� ��� �� �������(B,C���� ���) CŬ������ �ۼ��ϴ� �����ڰ�
	// B�� ���� �� �� �ֱ� ������ �����ִ� ���� ����˴ϴ�
	virtual Pet* CreatePet() {
		return new Dog;
	}
	virtual const char* GetPetName() {
		return "������";
	}
	void Feed() {
		printf("������������� � ���̶�!���� ������ ����� ���� �����ؿ�\n");
	}
	void Bark() {
		printf("����!^^\n");
	}
};

class Cat : public Pet{
public:
	virtual Pet* CreatePet() {
		return new Cat;
	}
	virtual const char* GetPetName() {
		return "�����";
	}
	void Feed() {
		printf("�߿��̵��� �����̳� ����� ��ƽ������ �����ؿ�^^\n");
	}
	void Bark() {
		printf("�Ŀ�~\n");
	}
};

int main()
{
	int select;//�޴� �߿� ������ ��ȣ ����
	int type;//�������� �߿��� �� ���� ���� Ÿ�� ���� ��ȣ ����
	Pet* p_pet_list[MAX_PET_COUNT];
	Pet* p_pet_table[PET_TABLE_COUNT] = {new Dog, new Cat};
	int pet_count=0;
	while (1) {
		printf("\n[ �޴� ]\n");
		printf("1. �ű� ��� 2. �� ���̱� 3. �ǰ�����üũ(Bark) 4. ���� : ");
		scanf_s("%d", &select);
		if (select == 1) {
			for (int i = 0; i < PET_TABLE_COUNT; i++) {
				printf("%d. %s ", i, p_pet_table[i]->GetPetName());
			}
			printf(": ");
			scanf_s("%d", &type);
			p_pet_list[pet_count] = p_pet_table[type]->CreatePet();
			pet_count++;
		}
		else if (select == 2) {
			for (int i = 0; i < pet_count; i++) {
				p_pet_list[i]->Feed();
			}

		}
		else if (select == 3) {
			for (int i = 0; i < pet_count; i++) {
				p_pet_list[i]->Bark();
			}

		}
		else if (select == 4)	break;

	}
	for (int i = 0; i < pet_count; i++) {
		delete* (p_pet_list + i); //delete p_pet_list[i];
	}
	return 0;
}