#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX_LEN 240

void printnotchangePtr(const char *ap_str)//ap_str = �Ű������� �����ͺ�������
{
	printf("%s\n", ap_str);
}
char* printchangeArr(char(*ap_str)[MAX_LEN])
{
	char* temp;//����ü �����ͺ����̵� �Ϲݺ����� ����Ű�� ������ �����̵�
	//�ӽ÷� �����ϴ� ��쿡�� (����: swapbyreference �Լ� Ȥ�� ���Ḯ��Ʈ �������Լ�
	char strawberry[MAX_LEN] = "strawberry";//strcpy_s�� strncpy_s�� ����
	//�ݵ�� ���� ũ��� (MAX_LEN����) �迭ũ�� ����
	temp = strcpy(*ap_str, strawberry);
	return *ap_str;
}
void printnotchangeArr(const char(*ap_str)[MAX_LEN])
{
	//1���� char�� �迭�� �Ű������� ������ ��� ap_str = &arr1D
	printf("%s\n", *ap_str);
}

int main(void)
{
	//���ڿ������ �ʱ�ȭ�� �����ͺ����� char�� �迭 ����
	//const char* ptr_notchange_str = "banana";
	//printnotchangePtr(ptr_notchange_str);
	//char arr_str[MAX_LEN] = "banana";//�迭ũ�⸦ MAX_LEN���� ������ ������ �ȵ�
	//printf("%s\n",printchangeArr(&arr_str));
	//char arr_notchange_str[MAX_LEN] = "banana";
	//printnotchangeArr(&arr_notchange_str);

	char arr3D[2][3][5] = { {"hihi", "hehe", "haha"},{"abcd", "efgh"} };
	char(*ptr)[3][5] = arr3D;
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++)
			printf("%s\n", *(*(ptr + i) + j) + 0);//printf("%s\n", *(ptr + i) + j);�� ���ϰ��
		printf("\n");
	}
	/*char arr3D[][3][5] = { {"abcd", "efgh", "ijkl"}, {"mnop","qrst", "uvwx"} };
	char arr2D[3][5] = { "abcd", "efgh", "ijkl" };
	char(*ptr)[3][5] = &arr2D;
	for (unsigned int i = 0; i < 3; i++) {
			printf("%s\n", *(*(ptr + 0) + i) + 0);
	}
	ptr = arr3D;
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			printf("%s\n", *(*(ptr+i)+j)+0);
		}
	}*/

	return 0;
}