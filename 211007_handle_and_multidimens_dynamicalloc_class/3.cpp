//�������迭 �Ű����� c���
#include<string.h>
#include<stdio.h>
void GetMyString(char(*p)[3]);
int main(void)
{
	char arr[2][3] = { {'h', 'i', 0},"ku"};
	GetMyString(arr);
}
void GetMyString(char(*p)[3])
{
	char arr_copy[3];
	strcpy_s(arr_copy, 3, *(p+0));
	fputs(arr_copy, stdout);
	fputc('\n', stdout);
	fflush(stdout);
	strcpy_s(arr_copy, 3, *(p+1));
	/*�̷��� �ι��������ϰ� ���ڿ����̸�ŭ�� �����ѵ�
	�ι��ڸ� printf�Ҷ��� �� ���־�� �ϹǷ� printf�ϱ����� 
	�ι��ڸ� �־��ִ� ������� �ϸ� ������ ���µ� ������ �𸣰ڽ��ϴ�
	*/
	/*
	strcpy_s(arr_copy, 2, *(p+1));
	int len= strlen(*(p+1));
	arr_copy[len] = 0;
	*/
	fputs(arr_copy, stdout);
	fflush(stdout);
}