#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef unsigned int HANDLE;
typedef struct HandleData {
	HANDLE h;
	char* p_string;
}HandleData;
class HandleUsers {
private:
	char** pp;
	unsigned int m_gen_value;
	unsigned int m_max_user_cnt, m_max_count;
	HandleData** mp_users;
public:
	HandleUsers(unsigned int a_max_user_cnt = 8, unsigned int a_max_count = 8) {
		m_max_user_cnt = a_max_user_cnt;
		m_max_count = a_max_count;
		mp_users = new HandleData * [m_max_user_cnt];
		for (unsigned int j = 0; j < m_max_user_cnt; j++)
			*(mp_users + j) = new HandleData[m_max_count];
		for (unsigned int j = 0; j < m_max_user_cnt; j++)
			memset(*(mp_users + j), 0, sizeof(HandleData) * m_max_count);
		m_gen_value = 1;
	}
	~HandleUsers() {
		HandleData* p_handle = mp_users[0];
		for (unsigned int j = 0; j < m_max_user_cnt; j++) {
			p_handle = &mp_users[j][0];
			/*������ ������ �ּҿ����� ������ ������ �ڷ������� �ϰ�*/
			/*HandleData*�� �ڷ����̶� ����ü����ũ�⸸ŭ ����*/
			/*#�����ͺ����ּҿ���*/
			for (unsigned int i = 0; i < m_max_count; i++) {
				if (p_handle != NULL) {
					delete[] p_handle->p_string;
					p_handle++;
				}
			}
			delete[] mp_users[j];
		}
		delete mp_users;
	}
	HANDLE SetString(const char* ap_string)
	{
		int len = strlen(ap_string) + 1;
		HandleData* p_handle = mp_users[0];
		//HandleData* p_handle = &mp_users[0][0];�� ����
		//�����͹迭�� ������ �迭�� ������ �����ϹǷ�
		//mp_users[0]�� mp_users[0]�迭�� ù��°������ �ּҸ� ����Ű�� ����
		for (unsigned int j = 0; j < m_max_user_cnt; j++) {
			p_handle = &mp_users[j][0];
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString�Լ����� �����մϴ�: %s,�ڵ鰪: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*j�� ������Ų��(return�ȵǸ�ٱ�for�� �����ؼ� 
			p_handle = &mp_users[j++][0];�� �� ��ġ���� ������ �Ͱ� ����
			�̷��� j�� ������Ų�ڿ� ���� for�� �ٽ� �ݺ�*/
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString�Լ����� �����մϴ�: %s,�ڵ鰪: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*���⵵ return�� �����Ƿ� j�� ������Ű��(return�ȵǸ�
			�ٱ�for�� �����ؼ� p_handle = &mp_users[j++][0];�� 
			�� ��ġ���� ������ �Ͱ� ����
			�̷��� j�� ������Ų�ڿ� ���� for�� �ٽùݺ�*/
			printf("���� ������ ����ڰ� ���ҽ��ϴ�\n");
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString�Լ����� �����մϴ�: %s,�ڵ鰪: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*���return�̰����ߴٸ� �Ʒ��� ����ڼ� ���� ó�����ָ�Ǽ� ���̻��ڵ�Ⱦ�*/
			
		}
		printf("����� ���� �Ѿ����ϴ�. �Լ��� �����մϴ�\n");
		return 0xFFFFFFFF;
	}
	void ShowString(HANDLE h_str)
	{

	}
};
int main(void)
{
	HandleUsers users_lists(2,1);
	const char* ap_string = "�ȳ��ϼ���~";
	/*�پ��� ���ڿ� �Է� ���ÿ� realloc�� malloc�� �Է¹��� ���ڿ� �Ű������� ���� ���� ���̰� �����
	realloc�ϴ� �Ϳ� ���� ���ø� �����帮���� �Ʒ����� ���м� ���� ������ �ۼ��߽��ϴ�*/
	/*���м� ���� ���븸���ε� ����� ���డ���մϴ�*/
	/*-----------------------------------------------------*/
	char* ap_string_1 = NULL;
	char* message = NULL;
	const int MAX_LEN = 100;
	int len;
	char aArr_string_1[MAX_LEN] = { 0, };
	puts("�Է����ּ���~:");
	if (scanf_s("%s", aArr_string_1, MAX_LEN) == 0) {
		fprintf(stderr, "Please input string");
		exit(EXIT_FAILURE);
	}
	int totalsize = 0;
	len = strlen(aArr_string_1) + 1;

	if (ap_string_1 != NULL) {
		totalsize += len;/*���⼭�� �ǹ̰� �� �������� realloc�� �ǹ̸� ��Ȯ�� �ϰ��� ���� �Ѱ� �� �����߽��ϴ�*/
		ap_string_1 = (char*)realloc(ap_string_1, totalsize);
		memcpy(ap_string_1, aArr_string_1, totalsize);
	}
	else {
		ap_string_1 = (char*)malloc(MAX_LEN);
		memcpy(ap_string_1, aArr_string_1, len);
		printf("%s : �����޸��Ҵ�\n", ap_string_1);
	}
	/*-----------------------------------------------------*/
	HANDLE h_user1_str1 = users_lists.SetString(ap_string);
	char aArr_string[MAX_LEN] = "�ݰ����ϴ�~";
	ap_string = aArr_string;
	HANDLE h_user2_str1 = users_lists.SetString(ap_string);
	strcpy_s(aArr_string, 16, "�Ǻ˰ڽ��ϴپ�~");
	ap_string = aArr_string;
	HANDLE h_error = users_lists.SetString(ap_string);
	if(ap_string_1)	free(ap_string_1);
	/*const char���������� ������ �����޸��Ҵ����� �ʾƵ� �˴ϴ�!������ ������ �̶����� ����� �׷��Ա� �����Դϴ�*/
	return 0;
}