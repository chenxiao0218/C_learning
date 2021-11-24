#include"Manager.h"

void SpeakerManager::showMenu() {
	cout << "--------------------" << endl;
	cout << "1.开启这一轮演讲比赛" << endl;
	cout << "2.查看往届演讲比赛" << endl;
	cout << "3.清空往届记录" << endl;
	cout << "4.退出演讲比赛系统" << endl;
	cout << endl;
}

SpeakerManager::SpeakerManager() {
	this->initSystem();
	this->speakerCreat();
}
SpeakerManager::~SpeakerManager() {

}

void SpeakerManager::exitSystem() {
	cout << "欢迎下次使用";
	system("pause");
	exit(0);
}

void SpeakerManager::initSystem() {
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_message.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_empty_flag = 1;
}

void SpeakerManager::speakerCreat() {
	string nameseed = "ABCDEFGHIJKLMNOPQ";
	for (int i = 0; i < 12; i++) {
		Speaker person;
		
		person.m_name = "选手";
		person.m_name += nameseed[i];
		for (int j = 0; j < 2; j++) {
			person.m_score[j] = 0;
		}
		this->v1.push_back(10001+i);
		this->m_speaker.insert(make_pair(10001 + i, person));
		//this->v4.insert(pair<int, Speaker>(10001 + i, person)); 两者意义一样
	}
}

void SpeakerManager::matchStart() {
	//第一轮抽签
	this->speechDraw();
	//第一轮分配分数
	this->sorceGet();


	this->m_index++;

	//第二轮抽签
	this->speechDraw();
	//第二轮分配分数
	this->sorceGet();
	this->saveResult();
	system("cls");
}

//抽签
void SpeakerManager::speechDraw() {
	cout << "第" << this->m_index << "轮选手正在抽签" << endl;
	cout << "----------------------------------" << endl;
	if (this->m_index == 1) {
		random_shuffle(this->v1.begin(), this->v1.end());
		cout << "第一轮抽签顺序如下：" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << (*it) << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(this->v2.begin(), this->v2.end());
		cout << "第二轮抽签顺序如下：" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << (*it) << " ";
		}
		cout << endl;
	}
	system("pause");
}

//随机生成分数
void SpeakerManager::sorceGet() {
	cout << "第" << this->m_index << "轮比赛正式开始" << endl;
	cout << "----------------------------------" << endl;
	vector<int> temp_v;
	
	if (this->m_index == 1) {
		temp_v = v1;
	}
	else {
		temp_v = v2;
	}

	deque<int> temp;
	multimap<int, int,greater<int>> temp_v2;
	int num = 0;
	for (vector<int>::iterator mit = temp_v.begin();mit != temp_v.end(); mit++) {
		num++;
		for (int i = 0; i < 12; i++) {
				int t = rand() % 40 + 61;
				temp.push_back(t);
			}
		sort(temp.begin(), temp.end());
		temp.pop_back();
		temp.pop_front();

		int pjf = accumulate(temp.begin(), temp.end(),0) / 10;
		this->m_speaker[*mit].m_score[m_index-1] = pjf;		

		temp_v2.insert(make_pair( pjf,*mit));

		temp.clear();

		if (num % 6 == 0) {
			cout << "第" << num / 6 << "组结果如下：" << endl;
			int cnt = 0;
			for (multimap<int, int, greater<int>>::iterator it = temp_v2.begin(); it != temp_v2.end(); it++) {
				cout << (*it).second << "号选手：" << this->m_speaker[(*it).second].m_name << "的分数是：" << (*it).first << endl;
				if (this->m_index == 1 && cnt < 3) {
					cnt++;
					this->v2.push_back((*it).second);
				}
				else if (this->m_index == 2 && cnt < 3) {
					cnt++;
					this->v3.push_back((*it).second);
				}
			}
			temp_v2.clear();


		}

		
			
	}system("pause");
	if (this->m_index == 1) {
		cout << "第一轮晋级的有：" << endl;
		for (vector<int>::iterator v2_it = v2.begin(); v2_it != v2.end(); v2_it++) {
			cout << (*v2_it) << "  ";
		}
		cout << endl;
	}
	else {
		cout << "晋级前三的分别是：" << endl;
		for (vector<int>::iterator v3_it = v3.begin(); v3_it != v3.end(); v3_it++) {
			cout << (*v3_it) << "  ";
		}
		cout << endl;
	}
	system("pause");

}

//保存比赛结果
void SpeakerManager::saveResult() {
	ofstream ofs;
	ofs.open("result.csv", ios::out|ios::app);
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		ofs << (*it) << "," << m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已保存" << endl;
	m_empty_flag = 1;
}

void SpeakerManager::showResult() {
	ifstream ifs;
	ifs.open("result.csv", ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		if (m_empty_flag == 0) {
			cout << "文件为空d(flag = 0" << endl;
			ifs.close();
			system("pause");
			system("cls");
			return;
		}
		else
		{
			char ch;
			ifs >> ch;
			if (ifs.eof()) {
				cout << "文件为空(ch读取";
				m_empty_flag = 0;
				ifs.close();
				system("pause");
				system("cls");
				return;
			}
			else {
				m_empty_flag = 1;
				ifs.putback(ch);
				string date;
				
				int cnt = 0;
				while (ifs >> date) {
					vector<string> temp_v;
					int target = -1;//逗号的位置
					int start = 0;//开始寻找的位置
					while (true) {
						
						target = date.find(",", start);
						if (target == -1) {
							break;
						}
						string temp = date.substr(start, target - start);
						//cout << temp << endl;
						temp_v.push_back(temp);
						start = target + 1;
						
					}
					cnt++;
					this->m_message.insert(make_pair(cnt, temp_v));
				}
				
			}
		}

		/*for (map<int, vector<string>>::iterator re_itt = m_message.begin(); re_itt != m_message.end(); re_itt++) {
			cout << "Match " << (*re_itt).first << " champigon is:" << endl;
			for (vector<string>::iterator s_itt = (*re_itt).second.begin(); s_itt != (*re_itt).second.end(); s_itt++) {
				cout << (*s_itt) << "  ";
			}
			cout << endl;
		}*/
		for (int i = 0; i < m_message.size(); i++) {
			cout << "the" << i+1 << "game:" << endl;
			cout << "冠军" << m_message[i + 1][0] << "  分数：" << m_message[i + 1][1] << "  ";;
			cout << "亚军" << m_message[i + 1][2] << "  分数：" << m_message[i + 1][3]<<"  ";
			cout << "季军" << m_message[i + 1][4] << "  分数：" << m_message[i + 1][5]<<endl;
			cout << "------------------------------------------------------" << endl;
		}
		
	}
	ifs.close();
	system("pause");
	system("cls");
}

void SpeakerManager::clearResult() {
	int choice;
	cout << "确认要清空文件？" << endl;
	cout << "输入 1 表示确认" << endl;
	cin >> choice;
	if (choice == 1) {
		ofstream ifs;
		ifs.open("result.csv", ios::trunc);
		ifs.close();
		cout << "清空成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "放弃清空" << endl;;
		system("pause");
		system("cls");
		return;
	}
}