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
	map<int, pair<int, int>> m;//차량번호, 들어온 시간, 누적시간


	for (int i = 0; i < records.size(); i++) {
		string inout = records[i].substr(11, 2);// iterator나 포인터로 공백을 찾는 방법을 알고 싶다.
		int number = stoi(records[i].substr(6, 4));
		int hour = stoi(records[i].substr(0, 2));
		int min = stoi(records[i].substr(3, 2));
		int time = hour * 60 + min;//내가 들어간 시각, 나간 시각

		if (inout == "IN") {
			m[number].first = time;//이번 시각
		}
		else {//"OUT"일때의 경우 이때는 time이 내가 나간시각
			m[number].second += time - m[number].first;//시간을 누적해서 계산 해준다
			m[number].first = 99999;

		}
	}

	for (auto& p : m) {

		if (p.second.first != 99999) {
			//누적시간 업데이트
			p.second.second += 1439 - p.second.first;
		}
		//시간 계산
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

