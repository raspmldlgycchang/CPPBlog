#include<stdio.h>
#include<string.h>

#define MAX_COUNT 2;
typedef char NAME_TYPE[14];

void SetName(NAME_TYPE* p, int count) {//�����ּҿ� �� �л���, char (*p)[14]�� ����
	const char* ptr = "ȫ�浿";
	const char arr[14] = "�迬��";
	strcpy_s(*(p + 0), strlen(ptr) + 1, ptr);
	strcpy_s(*(p + 1), 14, arr);

	for (int i = 0; i < count; i++) {
		printf("%s\n", *(p + i) + 0);
	}
}//p�� �迭 ������(char (*p)[14])
//2���� �迭 arr
int main()
{
	NAME_TYPE Name_2DArray[2];//char Name_2DArray[2][14];
	NAME_TYPE* p;//char (*p)[14];
	p = Name_2DArray;

	const char* ptr = "ȫ�浿";
	const char arr[14] = "�迬��";
	strcpy_s(*(p + 0),strlen(ptr)+1, ptr);
	strcpy_s(*(p + 1), 14, arr);

	SetName((p+0), 2);//SetName�� p������ ������ �迭�� MAX_LEN�� 14������ �ֳĸ� �Ű����� p�� �׸�ó�� *(p+0)+0�� �����Ѿ� ��
	//char (*p)[14] = Name_2DArray;//p�� Name_2DArray�� ù ��° 1���� �迭�� �����ּҿ� �ּҿ����� ���� �޸��ּ���
	return 0;
}