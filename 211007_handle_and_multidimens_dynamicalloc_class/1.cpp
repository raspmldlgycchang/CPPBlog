#include<malloc.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef unsigned int HANDLE;
#define MAX_COUNT 5
#define BUF_SIZE 1024
enum NUM {
	ROCK,
	SCISSORS,
	PAPER
};
typedef struct HandleTournaData* p_Data;
typedef struct HandleTournaData {
	HANDLE h;
	char* p_string;

	int num_result;
	enum NUM enum_result;
	void* p;
}Data;
class HandleTournaManager {
private:
	unsigned int m_len;
	unsigned int m_max_count;
	p_Data mp_data;//�����͹迭
	char* const apointer_string[MAX_COUNT];
public:
	HandleTournaManager();
	~HandleTournaManager();
	void Init();
	HANDLE SetString(const char * ap_string);
};
HandleTournaManager::HandleTournaManager() {
	//����ڰ� ������ ��ŭ ��� ����(<m_max_count�ε���)
	Init();
}
void HandleTournaManager::Init() {
	m_max_count = MAX_COUNT;
	//�����͹迭���� ������ ��带 ã������(mp_data[���������]->h==0)
	//
}
HANDLE HandleTournaManager::SetString(const char* ap_string)
{
	m_len = strlen(ap_string) + 1;
	HandleTournaData* p = mp_data;//����ü �����͹迭 ù��° ���ҿ� 
	//��ġ ���Ḯ��Ʈ ����ó�� ����������̿��ؼ� ������ ��� ã�� ���� ����
	//p��� ������ ����
	//���� ������ �Ʒ��� ����
	/*
	* HandleTournaData * p;
	* p = mp_data;
	*/
	unsigned int i;
	for (i = 0; i < m_max_count; i++) {
		if (p->h == 0)	break;
		else p++;
	}
	if (i < m_max_count) {
		p->
	}

	return 0xFFFFFFFF;
}
int GetMyString(char buffer[], int limit)//����ڷκ��� Ƚ�������ؼ� ���ڿ��Է¹ޱ�
{
	int i;
	for (i = 0; i < limit; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			return 1;
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}
int main(int argc, char* argv[])
{
	HandleTournaManager obj1;
	HandleTournaManager obj2;
	HandleTournaManager obj3;
	int state;
	char input[BUF_SIZE];
	while (1) {
		fputs("For exit (q or Q) : ", stdout);
		fgets(input, BUF_SIZE, stdin);
		if (strcmp(input, "q\n") || strcmp(input, "Q\n"))
			break;
		rewind(stdin);
		state = GetMyString(input, 1023);

		if (state == -1)	printf("your input is : %s\n", input);
		else
		{
			printf("your input was interrupted : %s => ���ڿ����̸� ���ݸ� �ٿ��ּ���!\n", input);
		}
	}
	return 0;
}