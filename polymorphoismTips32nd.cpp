//����ü�����ͺ����� ����ü����Ŭ������������� ����޼��������ϴ� ���
#include<stdio.h>
#define MAX_PET 2
class Pet {
public:
	virtual void Sound(){}
	virtual void Eat(){}
	virtual Pet* CreatePet() { return NULL; }
	virtual char* GetName() { return NULL; }
};

//*(p+0~4) �� *(ptr+0~4)�� �Ű��������� ������ ����ü �� ������ �����ּ�,
//1���� char*�� ������ ���� �����ֱ�
class Dog :public Pet {
public:
	void Sound() { printf("�۸�~\n"); }
	void Eat() { printf("���ٱ�\n"); }
	//��ġ throws Exception�� �� �� catch������ throw new MyException("Hwang");�� �ϸ�
	//��ĳ������ �Ͼ�� �����ϴ�
	Pet* CreatePet() { return new Dog; }
	char* GetName() { return (char*)"Dog"; }
};
class Cat :public Pet{
public:
	void Sound() { printf("�߿�~\n"); }
	void Eat() { printf("����\n"); }
	Pet* CreatePet() { return new Cat; }
	char* GetName() { return (char*)"Cat"; }
};
//�� Ŭ������ Ŭ���� ������ �迭
//ap_dog_count[0]~ap_dog_count[�߰�]
Pet* gp_pet_table[MAX_PET] = { new Dog, new Cat };

void AddPet(Pet* ap_list[],int* ap_pet_count)
{
	int select;
	//������ ���ڸ� ������Ű�� ������ ������ �迭�� ������ ��ü�� �����Ҵ����� �߰�
	//�����͹迭���� �� ���ҷ� �̵��ؼ� �׷��� �̰Ŵ� �̹� �Ҵ��� �Ϸ��� �ڿ� �� ������ �ɷ��ְ�
	//p_handle->h�� �̿��߾���
	//������ ���⼭�� �ܼ��� �����͹迭�� �����Ҵ��� �̿��Ұž�
	//�ڿ� �߰��ؼ� �ϴ� ���� �����ϳ�
	for (int i = 0; i < MAX_PET; i++) {
		printf("%s -> %d\n", gp_pet_table[i]->GetName(), i);
	}
	scanf_s("%d", &select);
	ap_list[*ap_pet_count] = gp_pet_table[select]->CreatePet();//�Լ���ȯ���̿�(�������ε��� ���� ����Ŭ���� �޼������)
	(*ap_pet_count)++;
}
void PetSound(Pet* ap_list[], int pet_count)
{
	for (int i = 0; i < pet_count; i++) {
		ap_list[i]->Sound();
	}
}
void PetEat(Pet* ap_list[], int pet_count)
{
	//�����͹迭�� ���Ҵ� Ŭ���������ͺ����̹Ƿ�
	//����ü�� �����ϰ� �����Ѵ�
	for (int i = 0; i < pet_count; i++) {
		ap_list[i]->Eat();//�������ε����� ����Ŭ������ �޼���� ���ٰ� ����Ŭ������ �޼��带 �����Ѵ�
	}
}
int main(void)
{
	Pet* p_list[20];//�����͹迭 20������(�ִ���Ұ���)
	int pet_count = 0,select=0;
	while (select != 4) {
		printf("[Menu] ");
		printf("1. AddPet 2. PetSound 3. PetEat 4. Exit :");
		scanf_s("%d", &select);
		//�θ�Ŭ������ �ۼ��� virtualŰ���带 �� �޼��带 �������ε��� ����
		//����Ŭ������ �޼��带 ���������ν�(�� �̶�, ��ĳ�����̱� ������ �θ� ��ü��
		//���� �����Ŀ�, ����Ŭ������ �޼���� ����)
		if (select == 1)	AddPet(p_list, &pet_count);
		else if (select == 2)	PetSound(p_list, pet_count);
		else if(select==3)	PetEat(p_list, pet_count);
	}
	//�Լ��� ���ؼ� �����Ҵ��� ��(�Ű������� ���� �� NULL�� ���´���)
	//�����޸������ϴ� �ڵ尡 �ݵ�� �ʿ��ϴ�(���Ḯ��Ʈ NODE **pp_head����)
	//�����͹迭�̹Ƿ� �� ������ �����ϴ� �ڵ尡 �ʿ��ѵ� 
	//�ϳ��� ���ҿ� �Ҵ�� ���� �迭�� �ƴ϶� �ϳ��� Ŭ���� ��ü�ϱ� 
	//delete���� �ؾ��ϰ� delete[]���� �ϸ� �ȵȴ�
	for (int i = 0; i < pet_count; i++) {
		//1�� ������Ű�� ������ 1�� �� �ε������� �����ͺ����� ����Ǿ��ִ�
		delete p_list[i];
	}
	//�ϳ��� ����ü�����ͺ����� �����Ҵ������ϱ� �̰� �����Ҵ��ϰ�
	//�̰� ���̳�
	//new�� ���ؼ� ������ �� ��� �����ؾ���
	for (int i = 0; i <MAX_PET; i++) {
		delete gp_pet_table[i];
	}
	return 0;
}