#include<stdio.h>
#include<string.h>
#include "UserInformation.h"


int main()
{
	const int count = 5;
	UI u[count] = { {"ȫ", 23} ,{"��", 22} ,{"��", 21} ,{"��", 20} ,{"��", 25}};
	ArrangeMemberByAGE(&u[0], count);
	//����ü������ �Ϲݺ����� �����ϴ�
	//���� ����ü �迭�� �⺻ �ڷ����� �迭�� ������ �����ϴ�
	SetMoney(u, 19, 0);
	
	return 0;
}