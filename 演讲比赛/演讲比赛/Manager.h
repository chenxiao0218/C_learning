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
	//退出系统
	void exitSystem();
	//开始比赛前把上一轮比赛的信息清除一下
	void initSystem();
	//创建选手信息
	void speakerCreat();
	//开始比赛
	void matchStart();
	//抽签
	void speechDraw();
	//比赛（随机分数
	void sorceGet();
	//保存比赛结果
	void saveResult();
	//展示比赛结果
	void showResult();
	//清空文件夹
	void clearResult();

	//第一轮的选手编号
	vector<int> v1;
	//第二轮的选手编号
	vector<int> v2;
	//前三名的选手编号
	vector<int> v3;
	//比赛伦次
	int m_index=1;
	map<int, Speaker> m_speaker;

	//从文件中获取的信息
	map<int, vector<string>> m_message;

	//result文件内是否为空
	bool m_empty_flag;

};