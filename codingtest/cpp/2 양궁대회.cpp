#include <string>
#include <vector>

using namespace std;
//점수 정하는 벡터
vector<int>answer(11, 0);
int score = -1;

void dfs(int cnt, int n,int cc, int apch_sco, vector<pair<int, int>> rion, vector<pair<int, int>>& realscore, vector<int> info) {
	if (cc > n) {//이미 화살을 넘어서 쏜 경우 그만탐색
		return;
	}

	if (cnt == rion.size()) {//이때 비교하면 되고
		int temp = 0;
		int count = 0;
		for (int i = 0; i < realscore.size(); i++) {
			count += realscore[i].second;
		}
		if (count >= n) {//n발 이상 쏜게 된다면 out!!
			return;
		}
		for (int i = 0; i < realscore.size(); i++) {
			temp += (realscore[i].first);
		}
		if (temp > score && temp > apch_sco) {
			score = temp;
			int k = 0;
			vector<int>answer(11);// 다시 선언하면 초기화 된다.
			//점수 판 삽입
			for (int i = 0; i < answer.size(); i++) {
				answer[i] = realscore[i].second;
			}

			if (count < n) {
				answer[10] += (n - count);
			}
		}
	}
	pair<int, int> prev = realscore[cnt];
	for (int i = 0; i < 2; i++) {
		if (i == 1 && rion[cnt].second == 1) {
			realscore[cnt] = make_pair(rion[cnt].first, rion[cnt].second);//점수 그다음 화살 수
			cc += rion[cnt].second;
		}
		if (i == 1 && rion[i].second > 1) {
			realscore[cnt] = make_pair((rion[cnt].first) * 2, rion[cnt].second);//어피치 점수를 없애고 내가 먹는거니까.
			cc += rion[cnt].second;
		}
		dfs(cnt + 1, n,cc, apch_sco, rion, realscore, info);
		realscore[cnt] = prev;  // 백트래킹: 원래 값으로 복원
	}
}

vector<int> solution(int n, vector<int> info) {

	int apch_sco = 0;//어피치 점수
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) apch_sco += 10 - i;
	}

	vector<pair<int, int>> rion;//라이언이 얻을 수 있는 점수와 그에 맞는 쏴야하는 화살 수 정리한 표

	for (int i = 0; i < info.size(); i++) {
		if (info[i] != 0) {
			rion.push_back(make_pair(10 - i, info[i] + 1));//점수, 화살 수 --> rion이 점수가 있을때
		}
		else {
			rion.push_back(make_pair(10 - i, 1));
		}
	}
	//화살이 남는 경우 0발에 다 쏘자
	//현재 rion에는 rion이 쏴야하는 화살의 개수가 들어있다
	vector<pair<int, int>>realscore(rion.size());//실제 점수 계산 벡터
	dfs(0, n,0, apch_sco, rion, realscore, info);


	return answer;
}