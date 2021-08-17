//#define _CRT_SECURE_NO_WARNINGS // if use 'strcpy' or 'scanf'
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//atoi
#define MAX_LEN 11
class Student {
protected:
	int m_grade;
	char m_name[11];
	void* studentNum;//�й��� ���� ���ڿ��� �ڷ��� ������
public:
	Student(int, const char*, char*, char);
	~Student() {}
	void Study() {
		exam();
	}
	void exam();
};

class Researcher : public Student{

public:
	Researcher(int grade, const char* name, const char* studentNum, char flag) : Student(grade, name, (char*)studentNum, flag) {}
	void research() {}
	
	//overriding
	void exam();
};

Student::Student(int grade, const char* name, char* studentNum, char flag)// Student * const this
{
	m_grade = grade;
	//Ȥ�� this->m_grade = grade;

	strcpy_s(this->m_name, sizeof(char) * MAX_LEN, name);
	//Ȥ�� strcpy_s(m_name, sizeof(char)*MAX_LEN, name);

	//�й��� ���� ���ڿ��� �ڷ��� ������
	void* tmp_stdNum = studentNum;
	if (flag == 0)	*(char*)tmp_stdNum = atoi((const char*)studentNum);
	else if (flag == 1) {//short�� ������ ���ڿ�
		char* tmp_shortPtr = (char*)studentNum;//1����Ʈ�� ���� �ּ� ����Ų �ڿ�
		//���� �ּҿ��� 1����Ʈ�� �ּҿ����ؼ� �� �о����
		for (int i = 0; i < 2; i++)	*(((char*)tmp_stdNum)+i) = *(tmp_shortPtr+i);//for�� �� �� �� ������ 1����Ʈ�� ������ ��� �����ؾ� �ϹǷ�
	}
	this->studentNum = studentNum;
}


//Ŭ���� �ܺο� �����ϴ� ���: 3ȸ �ι�° ���� 00:47:35
void Student::exam() {//Student const *this ������
	printf("Student class : exam\n");
}

void Researcher::exam() {
	printf("Researcher class : exam\n");
}

int main(void)
{
	int grade = 95;
	const char name[12] = "ȫ�浿";
	const char* ptr = name;//������ �Ű�������(�迭������ ����) ����ϴ� ������ �Լ��� �����Ƿ� �迭�� ������ �ȵǰ� ������ ������ ������ �ϹǷ�
					 //�ش� �κ� ���� ������ ������: https://blog.naver.com/raspmldlgycchang8753/222468500445
	
	Researcher cDer(grade, ptr, "2020123456", char(2));
	cDer.exam();

	//��ĳ����
	//����ü ������ ó�� Ȥ�� �Ϲݺ����� �����ͺ���ó�� ����Ű�� �ּҰ� ������ ����
	Student *cBase = (Student*)&cDer;//�й��� ���� ���ڿ��� �ڷ��� ������
	//flag�� �й��� �ش��ϴ� ��������� � ������ ������ �ڷ����� ������ ������ �𸣴ϱ� void���������� ����
	//������ �� �ڷ����� �˷�����ϹǷ� flag�� �˷��ش�(0: char��, 1: short��, 2: int��)

	cBase->exam();//�ڽ�Ŭ�����޼���������̵� 
	return 0;
}