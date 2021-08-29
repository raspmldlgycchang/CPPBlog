#include<malloc.h>
#include "Person.h"
/*//Person Ŭ���� �������ߴٰ� ������ ���� �ּ�ó����
class Person {
public:
	CLASSIFICATION m_grade;
	int m_len;
	int m_max_len;
	char* mp_str;
	char mArray_str[MAX_LEN];
public:
	Person();
	Person(const char(*ap_str)[MAX_LEN]);
	~Person();
	void SetString1(char(*ap_str)[MAX_LEN]);
	void SetString2(const std::string& ap_str);
	void Init();
	void Destroy();
	void ShowString();
};*/

class Student:public Person {
private:
	int m_age;
public:
	Student():Person(){}
	Student(CLASSIFICATION grade, const char(*ap_str)[MAX_LEN]) :Person(ap_str)
	//����: Person(*ap_str) ����: �Ű������� 2���������͸� �Ѱ��־�� �ϹǷ�(1�����迭�� &������, ��, 1������������ &������ ���� ��)
	{
		//Person(ap_str);
		m_grade = grade;
		switch (grade) {
		case CLASSIFICATION::FRESHMAN:
			this->m_age = 20;
			break;
		case CLASSIFICATION::SOPHOMORE:
			m_age = 21;
			break;
		case CLASSIFICATION::JUNIOR:
			m_age = 22;
			break;
		case CLASSIFICATION::SENIOR:
			m_age = 23;
			break;
		default:
			break;
		};
	}
};

int main()
{
	//�����͸� ������� �ʰ� ���ھ��� �������Լ��̿��ؼ� ��ü ������ �κ�
	Student std1;

	//��������� �κ�
	//------
	const char name_in[MAX_LEN] = "ȫ�浿";
	const char(*ptr_in)[MAX_LEN] = &name_in;
	enum CLASSIFICATION grade_in;
	grade_in = CLASSIFICATION::SOPHOMORE;
	
	Student std_tmp(grade_in,ptr_in);
	
	Student std_cp = std_tmp;
	delete[] std_tmp.mArray_str;

	printf("std_cp�� mArray_str���������\t %s�� �޸𸮰� ����Ǿ��� �� �޸𸮿� ���� ����Ǿ��� ������ ������ ������ �����Դϴ�\n", std_cp.mArray_str);
	//---

	//���������� �޸𸮰� �Ҵ�Ǿ� ���� ����� �������� Ȯ���غ��� �κ�
	std_tmp.ShowString();
	
	return 0;
}