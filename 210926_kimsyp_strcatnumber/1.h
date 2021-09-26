#pragma once
int strcmpprinciple(const char* p1, const char* p2)
{
	int len = strlen(p1);
	//��� �켱���� �����ߴµ� ���̰� ��ª���� �񱳴� ������ ������ ���ڿ��� �̱� ���̹Ƿ� �����ʿ�
	if (strlen(p2) < len)	len = strlen(p2);
	int i = 0;
	do {
		if (p1[i] < p2[i])//ascii �ڵ� ��
		{//'A'(65) < 'c'(98+'c'-'a') 
			if (65 <= p1[i] <= 90) {
				return -1;
			}
			//'a' < 'c', 'A' < 'C'�� ���
			else {
				return 1;
			}
		}
		else if (p1[i] > p2[i]) {
			if (65 <= p2[i] <= 90) {//'c' > 'A'
				return 1;
			}
			else {
				//'C' >'A', 'c' > 'a'
				return -1;
			}
		}
		else
			continue;
	} while (i < len && ++i);
	return 0;
}
int strcmpprinciple_2(const char** p1, const char** p2)
{
	int len = strlen(*p1);
	if (strlen(*p2) < len)	len = strlen(*p2);
	int i = 0;
	do {
		if (*((p1[0]) + i) < *((p2[0]) + i))//ascii �ڵ� ��
		//p1[0]
		{//'A'(65) < 'c'(98+'c'-'a') 
			if (65 <= *(*p1 + i) <= 90)
				return -1;
			else
			{
				return 1;
			}
		}
		else if (*((p1[0]) + i) > *((p2[0]) + i))
		{
			if (65 <= *(*p2 + i) <= 90)
				return 1;
			else
				return -1;
		}
		else
			continue;
	} while (i < len && ++i);
	return 0;
}