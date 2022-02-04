#include<iostream>
#include<string.h>//memset strlen strcpy_s
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define MAX_LEN 240
class HandleManager {
private:
	char** mp_str;
	unsigned int m_max_len=MAX_LEN, m_max_count;
public:
	HandleManager(unsigned int a_max_count = 5) {
		m_max_count = a_max_count;
		mp_str = new char* [m_max_count];
		for (unsigned int i = 0; i < m_max_count; i++) {
			*(mp_str + i) = new char[m_max_len];
		}
		for (unsigned int i = 0; i < m_max_count; i++)
			memset(mp_str[i], 0, sizeof(char));//ù����Ʈ 0(�ι���)
	}
	~HandleManager();
	unsigned int SetString(const char* ap_string);

};

HandleManager::~HandleManager() {
	for (unsigned int i = 0; i < m_max_count; i++) {
		delete mp_str[i];
		cout << "mp_str[" << i << "] �����޸����� �� ��ü�Ҹ�Ϸ�" << endl;
	}
	delete[] mp_str;

}
unsigned int HandleManager::SetString(const char* ap_string)
{
	int len = strlen(ap_string) + 1;
	char* p;
	p = new char[len];
	strcpy_s(p, len, ap_string);
	cout << p << " : p " << endl;

	unsigned int i;
	char* p_char = mp_str[0];
	for (i = 0; i < m_max_count; i++) {
		if (mp_str[i]) {
			break;
		}
		else
			continue;
	}
	if (i < m_max_count) {
		memcpy(mp_str[i], p, len);
		return 1;
	}
	return 0xFFFFFFFF;
}
int main(void)
{
	HandleManager str_list_users;
	unsigned int list1 = str_list_users.SetString("�ȳ��ϼ���");
	unsigned int list2 = str_list_users.SetString("���� ���������Դϴ�1");
	unsigned int list3 = str_list_users.SetString("���� ���������Դϴ�2");
	unsigned int list4 = str_list_users.SetString("���� ���������Դϴ�3");
	unsigned int list5 = str_list_users.SetString("���� ���������Դϴ�4");
	unsigned int error = str_list_users.SetString("���� ���������Դϴ�5");

	cout << list1 << list2 << list3 << list4 << list5 << endl;
	return 0;
}