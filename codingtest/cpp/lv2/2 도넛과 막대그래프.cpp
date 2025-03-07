#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void ring() {

}
vector<int> solution(vector<vector<int>> edges) {
	vector<int> answer;
	// 먼저 무관한 정점 찾기. 따로 빼서 보관
	vector<int> start;
	vector<int> end;
	map<int, int> M;
	vector<int>count;
	//도착지점을 시작점으로 만들어서 map을 만들고 map에 시작점을 넣으면 없는애가 있어
	//즉 역으로 만든거니까, 도착점이 없는애가 있어 걔가 정점이고 걔는 벡터에서 삭제
	for (int i = 0; i < edges.size(); i++) {
		if (M.find(edges[i][1]) != M.end()) {
			count.push_back(edges[i][1]);//자기한테 도착하는게 여러개야..? 걔는 고리의 연결부위

		}
		M[edges[i][1]] = edges[i][0];
	}
	//정점 빼기
	int star = 0;
	int stari = -1;
	for (int i = 0; i < edges.size(); i++) {
		for (int j = 0; j < edges.size(); j++) {
			auto it = M.find(edges[i][0]);
			if (it == M.end()) {
				star = edges[i][0];
				stari = i;
				break;
			}
		}
		edges.erase(edges.begin() + stari); // 정점 삭제
	}


	// 먼저 간선 정리하기 (여기엔 정점과 관련된 애들은 없어)
	map<int, vector<int>> map;
	for (int i = 0; i < edges.size(); i++) {
		map[edges[i][0]].push_back(edges[i][1]);
	}//insert로 바꾸면 왜 안되는지,
	
	 
	 
	 //고리 추출
	//count에 2개인 애들이 다 들어가있어 얘네부터 시작해서 돌아보자
	int eight_donout = 0;

	for (int i = 0; i < count.size(); i++) {
	
		int startpoint = count[i];
		auto iter = map.find(count[i]);//그 map의 pair (int ,vector)를 가리키는 부분
		//여기가 사실 함수부분(고리연결 그 부분 없애기)
		while ((iter->second).begin() == (iter->second).end()) {
			if (i == 0) {
				startpoint = count[i];
				auto iter = map.find(count[i]);
				int restartpoint = *(iter->second).begin(); ///이부분은 다시 보자..........와 어이없네
				(iter->second).erase((iter->second).begin());

			}
			else {
				startpoint = *(iter->second).begin();
				auto iter = map.find(startpoint);
				int restartpoint = *(iter->second).begin(); ///이부분은 다시 보자..........와 어이없네
				(iter->second).erase((iter->second).begin());
			}
			
		}
	}

	//잘못됐다. 이중map이 그래프처럼 사용되지가 않네 map안에 vector를 넣었으면 쉬웠지.
	//장점이 딱히 없다. 왜냐면 map[edges[i][0]][edges[i][0]] = edges[i][1];여기서 마지막에 저걸
	//[i][0]을 다시 넣는건 별로 의미가 없어.

	return answer;
}


for (int i = 0; i < dotcon.size(); i++) {
	int k = dotcon[i];//관계없는 점과 연결된 그래프 위의 점
	int point = dotcon[i];
	count = 0;

	while (true) {
		if (M[k].size() >= 2) {
			eightring += 1;
			break;
		}
		else if (M[k].size() == 1) {
			int next = M[k][0];
			M[k].erase(M[k].begin());
			k = next;
		}
		else if (M[k].size() == 0) {
			if (k == point) {
				ring += 1;
				break;
			}
			else if (k != point) {
				stick += 1;
				break;
			}
		}

	}

}

void check(int start) {//start는 관계없는 점과 연결된 그래프 위의 점
	queue <int> q;
	q.push(start);
	bool isvisited = false;//..?
	while (!q.empty()) {//empty는 비어있을때 true, 안비어있을 때 false니까 !로 하기
		int now = q.front();
		q.pop();
		if (now == start && isvisited) {
			ring++;
			return;
		}
		if (M[now].size() >= 2) {
			eightring++;
			return;
		}
		for (int i = 0; i < M[now].size(); i++) {
			q.push(M[now][i]);
		}

	}
}