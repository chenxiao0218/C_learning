#pragma once
#include<iostream>
#include<string>
#include"speaker.h"
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<deque>
#include<fstream>


using namespace std;
class SpeakerManager {
public:
	void showMenu();
	SpeakerManager();
	~SpeakerManager();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ����ǰ����һ�ֱ�������Ϣ���һ��
	void initSystem();
	//����ѡ����Ϣ
	void speakerCreat();
	//��ʼ����
	void matchStart();
	//��ǩ
	void speechDraw();
	//�������������
	void sorceGet();
	//����������
	void saveResult();
	//չʾ�������
	void showResult();
	//����ļ���
	void clearResult();

	//��һ�ֵ�ѡ�ֱ��
	vector<int> v1;
	//�ڶ��ֵ�ѡ�ֱ��
	vector<int> v2;
	//ǰ������ѡ�ֱ��
	vector<int> v3;
	//�����״�
	int m_index=1;
	map<int, Speaker> m_speaker;

	//���ļ��л�ȡ����Ϣ
	map<int, vector<string>> m_message;

	//result�ļ����Ƿ�Ϊ��
	bool m_empty_flag;

};