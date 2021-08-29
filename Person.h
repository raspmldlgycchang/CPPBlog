#pragma once
#define __CRT_SECURE_NO_WARNINGS

#define MAX_LEN 32
#include<stdio.h>
#include <string>
#include<string.h>
enum class CLASSIFICATION { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };


class Person {
public:
	CLASSIFICATION m_grade;
	int m_len;
	int m_max_len;
	char *mp_str;
	char mArray_str[MAX_LEN];
	std::string mstring_str;
public:
	Person(const char(*ap_str)[MAX_LEN]) {
		//m_len = strlen(ap_str) + 1;����
		m_len = strlen(*ap_str) + 1;
		Init();

		if (m_max_len < m_len) {
			mp_str = (char*)malloc(m_len);
			*mp_str = 0;
		}
		strcpy_s(mArray_str, m_len, *ap_str);
	}
	Person() {
		//���ڿ��ޱ�
		//�迭�����͸� �Ű������� ����Ͽ��⿡ �����ͷ� ap_str�� �޴´ٸ� �Ȱ��� ������ char (*ap_str)[MAX_LEN]���� ������ �Ǿ�� �ϰ�
		//�迭�� ����ϴ� ���� �迭�����͸� �Ű������� ����ϴ� �ٺ����� ������ ���� aArray_str�̶�� ������ �޾Ƽ� �̰Ϳ� �ּҿ����ڸ� ����
		//&aArray_str�� �迭�����Ϳ� �Ѱ��ִ� ���� 1�����迭 �� �ƴ϶� ������ �迭���� ����Ǵ� �迭�� �Լ��� �Ű������� �ѱ� ���� ��Ģ�̰�
		//���� 1�����迭�� �迭�����Ͱ� �ƴ� char *ptr�̶�� �ܼ��� ������ ������ �Ű������� ����Ͽ��� ������
		//������ �迭�� �ݵ��(char���� ���ؼ��Դϴ�) �迭�����ͷ� �Լ��� �Ű������� �޾ƾ� �մϴ�
		char aArray_str[MAX_LEN];
		puts(aArray_str);
		rewind(stdin);
		SetString1(&aArray_str);
		mp_str = aArray_str;
	}
	void SetString1(char(*ap_str)[MAX_LEN]) {
		//m_len = strlen(ap_str) + 1;
		m_len = strlen(*ap_str) + 1;
		mp_str = (char*)malloc(m_len);
		strcpy_s(mp_str, m_len, *ap_str);
	}
	void SetString2(const std::string& ap_str) {
		mstring_str = ap_str;
	}
	void Init() {
		mp_str = 0;
		m_max_len = 1;
		mp_str = (char*)malloc(1);
		*mp_str = 0;
	}
	void ShowString()
	{
		printf("%s\n", mp_str);
	}
	void Destroy() {
		free(mp_str);
		Init();
	}
	~Person() {
		free(mp_str);
	}
};

