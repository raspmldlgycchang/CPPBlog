#include"../Project01/1.h"
#include"../Project01/gycchang_class.h"
#include"../Project01/node_struct.h"
int main(int argc, char* argv[])
//strcmpprinciple�� ������ ���� ���ο��� ����
{
	const char* p1 = "hello";
	const char* p2 = "hi";
	printf("%d %d(��������� Ȯ��)\n", strcmpprinciple_2(&p1, &p2), strcmp(p1, p2));

	printf("%d %d(��������� Ȯ��)\n", strcmpprinciple("a", "A"), strcmp("a", "A"));
	return 0;
}