#include"Manager.h"
#include<map>
#include<ctime>
#include<random>

int main() {
	
	int choice;
	/*for (map<int, Speaker>::iterator it = me.m_speaker.begin(); it != me.m_speaker.end(); it++) {
		cout << (*it).second.m_name << ":" << (*it).second.m_score[0] << ","
			<< (*it).second.m_score[1] << endl;
	}测试代码*/
	srand(unsigned(time(NULL)));
	SpeakerManager me;
	while (true) {
		
		me.showMenu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开启新一轮演讲比赛
			me.matchStart();
			break;
		case 2://查看保存的记录
			me.showResult();
			break;
		case 3://清空之前的记录
			me.clearResult();
			break;
		case 4://退出
			me.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
		me.initSystem();
		me.speakerCreat();
	}
	return 0;
}