#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	int bt = fees[0];
	int bf = fees[1];
	int at = fees[2];
	int af = fees[3];
	map<int, pair<int, int>> m;//������ȣ, ���� �ð�, �����ð�


	for (int i = 0; i < records.size(); i++) {
		string inout = records[i].substr(11, 2);// iterator�� �����ͷ� ������ ã�� ����� �˰� �ʹ�.
		int number = stoi(records[i].substr(6, 4));
		int hour = stoi(records[i].substr(0, 2));
		int min = stoi(records[i].substr(3, 2));
		int time = hour * 60 + min;//���� �� �ð�, ���� �ð�

		if (inout == "IN") {
			m[number].first = time;//�̹� �ð�
		}
		else {//"OUT"�϶��� ��� �̶��� time�� ���� �����ð�
			m[number].second += time - m[number].first;//�ð��� �����ؼ� ��� ���ش�
			m[number].first = 99999;

		}
	}

	for (auto& p : m) {

		if (p.second.first != 99999) {
			//�����ð� ������Ʈ
			p.second.second += 1439 - p.second.first;
		}
		//�ð� ���
		int nt = p.second.second;
		if (nt <= bt) {
			answer.push_back(bf);
		}
		else {
			if ((nt - bt) % at != 0) {
				answer.push_back(bf + (((nt - bt) / at) + 1) * af);
			}
			else {
				answer.push_back(bf + ((nt - bt) / at) * af);
			}

		}

		
	}
	return answer;
}

