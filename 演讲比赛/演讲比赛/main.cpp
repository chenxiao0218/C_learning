#include"Manager.h"
#include<map>
#include<ctime>
#include<random>

int main() {
	
	int choice;
	/*for (map<int, Speaker>::iterator it = me.m_speaker.begin(); it != me.m_speaker.end(); it++) {
		cout << (*it).second.m_name << ":" << (*it).second.m_score[0] << ","
			<< (*it).second.m_score[1] << endl;
	}���Դ���*/
	srand(unsigned(time(NULL)));
	SpeakerManager me;
	while (true) {
		
		me.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://������һ���ݽ�����
			me.matchStart();
			break;
		case 2://�鿴����ļ�¼
			me.showResult();
			break;
		case 3://���֮ǰ�ļ�¼
			me.clearResult();
			break;
		case 4://�˳�
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