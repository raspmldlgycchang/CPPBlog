#include<stdio.h>

//�ڵ� ��ó: Do it!C��� �Թ� 20-2�� �Լ������� ����
int Sum(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
//int (*p[4])(int, int) = { &Sum, &Sub, &Mul,&Div };
//���� ������ ǥ���� �����ϰ� �� ��
typedef int (*FT_TYPE)(int, int);
FT_TYPE funcPtrArr[4] = { &Sum, &Sub, &Mul,&Div };

int main(void)
{
	int result[4];
	for (int i = 0; i < 4; i++)	result[i] = funcPtrArr[i](6, 3);


	int (*p[4])(int, int)= { &Sum, &Sub, &Mul,&Div };

	FT_TYPE *temp = &p[0];//�ڽŰ� ���� ������ ������ �����ͺ����� �����Ѿ� �մϴ�.// p����
	//(��, p�� 2�����̹Ƿ� p[0]�� �� ����ŵ�ϴ�)
	for (int i = 0; i < 4; i++) {
		result[i] = (*temp)(6, 3);
		temp++;//�����ͺ����� �����ͺ����� �ڷ��� == �ڽ��� ����Ű�� ������ �ڷ��� ũ�⸸ŭ 
		//�ּҿ��꿡�� �����մϴ�.
	}

	for (int i = 0; i < 4; i++)	printf("%d ",result[i]);

	return 0;
}