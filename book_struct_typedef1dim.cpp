#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_BOOK_KIND 1//å �о� �ִ� ����(�ڵ�ȭ��ɽ� ������ �κ�1)
#define MAX_ONE_CATEGORY 260//����ڿ��� �Է��� �޴� �����Ҵ� �ڵ屸���� ���� �κ�1
#define MAX_BOOK_SIZE 1000//����ڿ��� �Է��� �޴� �����Ҵ� �ڵ屸���� ���� �κ�2
typedef unsigned int HANDLE;
void error_handling(const char* msg);
typedef struct reg {
	char author[20];//�۰�
	char company[20];//���ǻ�
}reg;
typedef struct bookInfo {//���Ḯ��Ʈ�� ����
	char year[20];//���ǳ⵵
	char name[40];//å�̸�
	reg owner;//�۰�,���ǻ�
	HANDLE h;//�˻�,������ ���� �ڵ鰪
	bookInfo* p_next;
}bookInfo;
//�� ī�װ��� BOOK_TYPE�̶�� 1��������ü������ �ڷ����� �ش�
class Book {
private:
	bookInfo bookInfomation;
public:
	virtual char* GetName() { return NULL; }
	virtual Book* CreateBook() { return NULL; }
	HANDLE SetString(unsigned int ap_book_cout);
};

typedef Book BOOK_TYPE[MAX_ONE_CATEGORY];
class Inmune :public Book {
public:
	char* GetName() { return (char*)"�ι�"; }
	Book* CreateBook() { return new Inmune; }
};
Book* gp_book_table[MAX_BOOK_KIND] = { new Inmune };//�ڵ�ȭ��ɽ� ������ �κ�2
//å �о� ��� �����ϰ� ��� �о߸� �����ְ� ����ڰ� �� �߿��� �����ϰ� �ϱ� ����

//Ŭ������ ����� ���� �ּ��� �޸� ����� ���ؼ� �����߰�
//linked List��� ������ ������ top��� 1��������ü�����ͺ������� �����մϴ�
bookInfo* top;//bookInfo* top = NULL;//���Ḯ��Ʈ�� �Ҵ�Ǿ����� ������ NULL����Ȼ���
//å������ �����ϴ� �Լ� : ���� �ڵ鰪�� �޾Ƽ� ���ϴ� ��ġ�� �ֱ� ���ؼ� �ڵ鰪�� å���� ��ȯ
HANDLE Book::SetString(unsigned int ap_book_count) {
	//bookInfo����ü ���� ����
	bookInfo* new_book = new bookInfo;//����ü���� 1���� ������ ����ü�����ͺ����޸��Ҵ�
	//bookInfo����ü ���� �ʱ�ȭ
	//linked List��� ������ ���� : ������ ����
	printf("å �̸�: ");
	rewind(stdin);
	scanf("%s", new_book->name);
	printf("���ǳ⵵: ");
	rewind(stdin);
	scanf("%s", new_book->year);
	printf("���� : ");
	rewind(stdin);
	scanf("%s", (new_book->owner).author);
	printf("���ǻ�: ");
	rewind(stdin);
	scanf("%s", (new_book->owner).company);
	//linked List��� ������ ���� : ��������� ��������� ����Ŵ
	new_book->p_next = top;
	top = new_book;
	new_book->h = ap_book_count+1;//�ڵ鰪�� 1���� �����ε� ap_book_count�� 0���� �����̶�
	printf("%d: ���ο� ����� �ڵ鰪\n", new_book->h);
	return new_book->h;//�ڵ鰪�� 1���� �����̶� ��ȯ���� 1�̻� �ڿ����� ����
}
HANDLE AddBook(Book* ap_book_list[], unsigned int ap_book_count)
//����ڰ� ���� å�鸸 ����ִ� �迭�� �� �迭�� ���� ���� ������, ����ġ ã�Ƽ� �߰�
{
	int select;//å �о� �� ��� �о� ���������� �޴� ����
	if (ap_book_count < MAX_ONE_CATEGORY) {
		for (int i = 0; i < MAX_BOOK_KIND; i++)
			printf(" %d. %s  ", i, gp_book_table[i]->GetName());
		scanf("%d", &select);
		//����ִ� ��ġ�� �ִ´�
		ap_book_list[ap_book_count] = gp_book_table[select]->CreateBook();//Ŭ������ü�� �Ź� ����
		//�߰��� å ���� �Է�
		ap_book_list[ap_book_count] = new Book;
		(ap_book_list[ap_book_count])->SetString(ap_book_count);

		return ap_book_list[ap_book_count]->SetString(ap_book_count);//�ش� �о߿� ���ο� å�� ����ϴ� �Լ�
		
	}
	else {
		printf("�� �о��� �ִ� �ο��� �ʰ��Ͽ� �Է��� �Ͻ� �� �����ϴ�.\n");
		printf("�ִ� %d�Ǳ��� �� �о߿� �����ϵ��� �����ϼ̽��ϴ�\n\n", MAX_ONE_CATEGORY);
	}
	return 0;//AddBook����
}
int is_empty() {
	return top == NULL;
}
void PrintStack()//�ش� �о��� ��� å�� ����ϴ� �Լ�
{
	if (!is_empty()) {
		bookInfo* p = top;
		while (p) {
			printf("%8s %8s %8s %8s\n", p->year, p->name, (p->owner).author, (p->owner).company);
			p = p->p_next;
		}
		printf("\n\n");
	}
}
//ap_book_list�� ���� å���� �迭�� ���� ��Ƽ� �־��ְ�
//�ڵ鰪�� ���⼭ �ٷ� ����ؼ�
//ã�� ���� ���⼭ ã��
//���� ���ݱ��� ������ ���� ����ü�����͹迭�� �̿����� �ʰ� 1��������ü�����͹迭�� �˻�,����

void DeleteNode(unsigned int a_book_count) {//p_next����(����ü���)
	//�߰�����1���� �����޸������� ������ ���� �޸𸮿� ���ؼ���, �̸� �Ҵ��ϰ� �����߱⿡
	//�߾�� �ߴ� �Ѱ踦 �غ��� �κ�: a_book_count��� ������� �Է��� ���� ���� ap_book_list�迭��
	//���Ҹ� �������� �Ҵ��� �ߴ� �ڵ带 ���������ν� �غ�
	/*for (int i = 0; i < a_book_count; i++) {
		bookInfo* p = top->p_next;
		free(top);
		top = p;
	}*/
	//Ȥ�� is_empty��ȯ������ ����ִٸ� ��ȯ�ϵ��� ����
	while (1) {
		bookInfo* top_save_next;
		if (is_empty())
			error_handling("stack is empty!");
		int result = top->h;
		printf("%d :�ڵ鰪 �����մϴ�\n", result);
		top_save_next = top->p_next;
		free(top);
		top = top_save_next;
	}
}




void main()
{
	int select = 0;;
	unsigned int book_count = 0;

	Book* p_book_list[MAX_BOOK_SIZE];//�ϴ��� ����ڿ��� �ִ� ���� �Է¾ȹް� ���ؼ� ����
	while (1) {
		printf("���������ý����Դϴ�. � �۾��� �Ͻðڽ��ϱ�?\n");
		printf(" [ Menu ] ");
		printf(" 1. AddBook  2. FindBook  3. DeleteBook  4. Exit :");
		rewind(stdin);
		scanf_s("%d", &select);
		if (select == 4)	break;
		if (select == 1) {
			//AddBook���� �Է¹��� �ִ� �迭ũ�⸦ �ʰ����� �������� book_count����
			int handle = AddBook(p_book_list, book_count);//�ڵ鰪�� SetString���� ��ȯ
			if(handle){//handle!=0
				book_count++;
			}
		}
	}
	DeleteNode(book_count);//bookInfo���Ḯ��Ʈ�������

	for (int i = 0; i < MAX_BOOK_KIND; i++)
		delete gp_book_table[i];//å ������ ��Ƴ��� �����͹迭 �����޸� ����
	for (int i = 0; i < book_count; i++)
		delete p_book_list[i];//����ڰ� �Է��� å�鸸 ��Ƴ��� �����͹迭 �����޸� ����
}
void error_handling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(0);
}