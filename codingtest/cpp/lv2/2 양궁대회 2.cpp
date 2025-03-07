#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int,int>> answer;//다 해서 11이 되면 여기에다가 업데이트를 계속 할거다 
//그러다가 마지막에 화살 수도 계산해서 적으면 끝
vector<int>apch(11, 0);
int score = -1;
int ctar = 0;
//탐색시에 이미 화살의 개수가 n 개가  넘어간다면 그만탐색하자
//화살의 개수만 신경쓰면 될듯
//화살의 개수 = countarr로 하자
// vector<int>ans는 내가 지금까지 넣은 점수들 체크하는 거
//cnt는 이번에 넣을지 말지 결정하는 점수  cnt=0일때는 10점 결정, cnt=1이라면 9점 먹을지 결정
void dfs(vector<vector<int>>rioncanwin,int apch_sco, int countarr, int n, int cnt,
	vector<pair<int, int>>ans) {
	if (countarr > n) {//라이언의 화살 수가 넘으면 그만 탐색
		return;
	}
	if (cnt == 11) {//여기에서는 score비교하자
		int temp = 0;
		for (int i = 0; i < ans.size(); i++) {
			temp += ans[i].first;
		}
		if (temp > score && temp > apch_sco) {
			score = temp;
			ctar = countarr;

			
			answer.clear();
			answer = ans;
		
		}
		return;
		//이때는 마지막에 dfs 다시 안부르고 return 해야지
	}
	//이 부분은 재귀호출을 통해 dfs탐색을 하는 코드
	for (int i = 0; i < 2; i++) {
		if (i == 0) {//안넣기

		}
		else if (i == 1) {//넣기
			countarr += rioncanwin[cnt][1];// 두번째가 활 개수
			if (apch[cnt] == 1) {
				ans.push_back(make_pair((10 - i) * 2, cnt));
				countarr += rioncanwin[cnt][1];
			}
			else if (apch[cnt] == 0) {
				ans.push_back(make_pair(10 - i, cnt));
				countarr += rioncanwin[cnt][1];
			}

		}
		dfs(rioncanwin,apch_sco, countarr, n, cnt + 1, ans);//cnt는 처음에는 0에서 시작하겠지
	}

}
vector<int> solution(int n, vector<int> info) {

	//어피치의 점수
	float apch_sco = 0;//c++에서는 피연산자중 하나라도 float이라면 float이 된다.
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) {
			apch_sco += 10 - i;
			apch[i] = 1;
		}
	}
	// vector<vector<int>> rioncanwin(11, {2,0});//vector<vector<int>> rioncanwin(11, {2, 0});는 11개의 행을 가진 벡터를 만들지만 각 행에 {2, 0} 값이 포함된 벡터를 넣는 방식입니다.
	vector<vector<int>>rioncanwin(11, vector<int>(2, 0));//점수-->>활 개수 순서
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) {//어피치가 맞춰서 어피치보다 하나 더 쏴야 먹는 점수
			rioncanwin[i][0] = 10 - i;
			rioncanwin[i][1] = info[i] + 1;
		}
		else {//한발 쏘면 먹을 수 있는 점수
			rioncanwin[i][0] = 10 - i;
			rioncanwin[i][1] = 1;
		}
	}
	//여기서 부터 rioncanwin을 통해 탐색하자
	vector<pair<int, int>>ans;
	dfs(rioncanwin, apch_sco, 0, n, 0, ans);
	vector<int>answers(11, 0);
	//answer에 다 들어있음 점수와 cnt가 들어있음
	for (pair<int, int> abcd : answer) {
		answers[10-(abcd.second)] = info[abcd.second] + 1;
	}



	return answers;
}