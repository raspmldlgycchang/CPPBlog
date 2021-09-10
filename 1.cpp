#include<stdio.h>
#include<malloc.h>

struct NODE {
	int data;
	NODE* p_next;
};

class node {
private:
	NODE* mp_head;
	NODE* mp_tail;
	static int m_data;//�� ��° ��ü���� �� �� �ֵ��� �ڵ� �ۼ��� �غ���(�������Լ�����)
public:
	node();
	~node();
	void insertNode()
	{
		int num;
		while (1) {
			printf("�Է��� �����Ϸ��� 999�� �Է����ּ���: ");
			scanf_s("%d", &num);
			if (num != 999) {
				if (mp_head)//if(p_head!=NULL)
				{
					mp_tail->p_next = (NODE*)malloc(sizeof(NODE));
					mp_tail = mp_tail->p_next;
				}
				else {
					mp_tail = mp_head = (NODE*)malloc(sizeof(NODE));
				}
				mp_tail->data = num;
				mp_tail->p_next = NULL;
			}
			else
			{
				break;
			}
		}
	}
	//void DeleteNode() // NODE *this;
	void DeleteNode() // NODE* const this;�� �Ʒ����� ������� �����ϴ� �κп��� ������ ��.
	{
		NODE* p;
		while (mp_head){//while(mp_head!=NULL)
			p = mp_head->p_next;
			free(mp_head);
			mp_head = p;
		}
	}
	void ShowNode()
	{
		NODE* p;
		int i = 0;
		while (mp_head) {
			printf("%d��° ��� %d��\n", i++, mp_head->data);
			mp_head = mp_head->p_next;
		}
		//�̰͵� ����
		/*printf("�̷��Ե� ����ص� �˴ϴ�\n");
		do {
			printf("%d��° ��� %d��\n", i++, mp_head->data);
		} while (mp_head = mp_head->p_next);*/
	}
};
int node::m_data = 0;//static��������� �������� ������ �ʱ�ȭ�ؾ� �Ѵ�
node::node() {
	mp_head = mp_tail = NULL;
	m_data++;
	printf("%d��° �����Դϴ�\n", m_data);
}
node::~node() {
	NODE* p;//p_save_next;
	while (mp_head) {
		p = mp_head->p_next;
		free(mp_head);
		mp_head = p;
	}
}
class tmp {
private:
	static int m_data;
public:
	tmp() {
		changeOtherclassStatic();
	}
	void changeOtherclassStatic() {
		m_data = 5;
	}
};
void insertNodeHead(NODE** pp_head){
	int num;
	NODE* p;
	while (1) {
		printf("�Է��� �����Ϸ��� 999�� �Է����ּ���: ");
		scanf_s("%d", &num);
		if (num != 999) {
			if (*pp_head != NULL) {
				p = *pp_head;
				while (p->p_next != NULL)	p = p->p_next;
				p->p_next = (NODE*)malloc(sizeof(NODE));
				p = p->p_next;
			}
			else {
				p = *pp_head = (NODE*)malloc(sizeof(NODE));
			}
			p->data = num;
			p->p_next = NULL;
		}
		else {
			break;
		}
	}
}
void deleteNodeHead(NODE **pp_head, NODE **pp_tail)
{
	NODE* p;//p_save_next;
	while (*pp_head) {
		p = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p;
	}
	*pp_tail = *pp_head;
	
}
void deleteNodeNotHead(NODE** pp_head, NODE** pp_tail)
{
	NODE* p=*pp_head, * p_save_next;
	while (NULL != p) {
		p_save_next = p->p_next;//free�� p��忡 ����� �ּ��� �޸𸮸� �����ϱ� ���� p->p_next�� �ش��ϴ� ��带 �̸� �����صξ�� �մϴ�
		//������ free(p);�� �ϰ� ������带 ����Ű�� �ϸ� �ȵǴ� ������ ������ �輺���� ���� 18��492�� Ȥ�� �������� Ȥ�� tipsware6ȸ����
		//���� Ȯ�ΰ����Ͻʴϴ�
		free(p);
		p = p_save_next;
	}
	*pp_head = *pp_tail = NULL;//���Ḯ��Ʈ�� ���۰� ���� ��� ������ �����
}
void insertNodeTail(NODE** pp_head, NODE** pp_tail, int num)
{
	while (1) {
		printf("�Է��� �����Ϸ��� 999�� �Է����ּ���: ");
		scanf_s("%d", &num);
		if (num != 999) {
			if (*pp_head)//if(p_head!=NULL)
			{
				(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
				(*pp_tail) = (*pp_tail)->p_next;
			}
			else {
				(*pp_tail) = (*pp_head) = (NODE*)malloc(sizeof(NODE));
			}
			(*pp_tail)->data = num;
			(*pp_tail)->p_next = NULL;
		}
		else
		{
			break;
		}
	}
}
void ShowNode(NODE** pp_head)
{
	NODE* p;
	int i = 0;
	while (*pp_head) {//while(NULL!=*pp_head)
		printf("%d��° ��� %d��\n", i++, (*pp_head)->data);
		(*pp_head) = (*pp_head)->p_next;
	}
	//�̰͵� ����
	/*do {
		printf("%d��° ��� %d��\n", i++, (*pp_head)->data);
	} while ((*pp_head) = (*pp_head)->p_next);*/
}
int main()
{
	//int num;
	//NODE* p_head, * p_tail;
	//p_head = NULL;
	//p_tail = NULL;
	//while (1) {
	//	printf("�Է��� �����Ϸ��� 999�� �Է����ּ���: ");
	//	scanf_s("%d", &num);
	//	if (num != 999) {
	//		if (p_head)//if(p_head!=NULL)
	//		{
	//			p_tail->p_next = (NODE*)malloc(sizeof(NODE));
	//			p_tail = p_tail->p_next;
	//		}
	//		else {
	//			p_tail = p_head = (NODE*)malloc(sizeof(NODE));
	//		}
	//		p_tail->data = num;
	//		p_tail->p_next = NULL;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//NODE* p;
	//int i = 0;
	//while (p_head) {//while(NULL!=p_head)
	//	printf("%d��° ��� %d��\n", i++, p_head->data);
	//	p_head = p_head->p_next;
	//}
	//
	/*do {
		printf("%d��° ��� %d��\n", i++, p_head->data);
	} while (p_head = p_head->p_next);*/


	//while (p_head) {
	//	p = (p_head)->p_next;
	//	free(p_head);
	//	p_head = p;
	//}
	//p_tail = p_head;//while���� ������ p_head�� NULL�������̴�


	//class ����� �ڵ�
	node obj1;
	node obj2;
	node obj3;
	obj1.insertNode();
	obj1.ShowNode();
	obj2.insertNode();
	obj2.ShowNode();
	obj3.insertNode();
	obj3.ShowNode();
}