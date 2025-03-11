#include <string>
#include <vector>
#include <queue>
using namespace std;

int dhor[4] = { -1, 0, 1, 0 };
int dver[4] = { 0, 1, 0, -1 };

void check1(char target, vector<string>& storage, vector<vector<int>>& avail) {
	vector<pair<int, int>>me;
	for (int i = 0; i < storage.size(); i++) {
		for (int j = 0; j < storage[0].size(); j++) {
			if (storage[i][j] == target && avail[i][j] == 1) { //target이고 접근 가능한 경우
				storage[i][j] = '9';
				// avail[i][j] = 1;//이렇게 바로 바꾸면 안됨
				me.push_back({ i,j });

			}
		}
	}
	for (pair<int, int> mes : me) {
		for (int k = 0; k < 4; k++) {

			int nrow = mes.first + dhor[k];
			int ncol = mes.second + dver[k];
			// Ensure the indices are within bounds
			if (nrow >= 0 && nrow < avail.size() && ncol >= 0 && ncol < avail[0].size()) {
				avail[nrow][ncol] = 1;
			}
		}
	}
	for (pair<int, int> mes : me) {
		avail[mes.first][mes.second] = 3;//빈부분은 3
	}

}

void bfs(vector<vector<int>>& avail, vector<vector<bool>> &visited) {
	int n = avail.size();
	int m = avail[0].size();
	queue<pair<int, int>> q;
	
	//2의 위치를 찾아 큐에 삽입
	for (int i = 0; i < avail[0].size(); i++) {
		if (avail[0][i] == 3) {
			q.push({ 0,i });
		}
	}
	for (int i = 0; i < avail[0].size(); i++) {
		if (avail[avail.size() - 1][i] == 3) {
			q.push({ 0,i });
		}
	}
	for (int i = 0; i < avail.size(); i++) {
		if (avail[i][0] == 3) {
			q.push({ 0,i });
		}
	}
	for (int i = 0; i < avail.size(); i++) {
		if (avail[i][avail[0].size() - 1] == 3) {
			q.push({ 0,i });
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dhor[i];
			int ny = y + dver[i];

			if (nx >= 0 && nx < avail.size() && ny >= 0 && ny < avail[0].size()) {
				if (avail[nx][ny] == 3&&visited[nx][ny]==false) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
				else if (avail[nx][ny] != 3) {
					avail[nx][ny] = 1;
				}
			}
		}

	}




}


//for문을 나왔지만 x랑 y는 유지 되잖아

void check2(char target, vector<string>& storage, vector<vector<int>>& avail, vector<vector<bool>> &visited) {
	for (int i = 0; i < storage.size(); i++) {
		for (int j = 0; j < storage[0].size(); j++) {
			if (storage[i][j] == target) {
				if (avail[i][j] != 1) {
					avail[i][j] = 3;
				}
				storage[i][j] = '9';
			}
		}
	}//여기까지 크레인으로 다 뺀 경우
	//여기부터 avail을 업데이트 해주어야 한다.->2옆에 1이 있다면 2도 1로 바꾸자!!//bfs로
	visited = vector<vector<bool>>(avail.size(), vector<bool>(avail[0].size(), false));
	bfs(avail,visited);



}
int solution(vector<string> storage, vector<string> requests) {
	int answer = 0;
	vector<vector<int>> avail(storage.size(), vector<int>(storage[0].size(), 0));
	vector<vector<bool>> visited(avail.size(), vector<bool>(avail[0].size(), false));
	// Correct the initialization of avail
	for (int i = 0; i < avail.size(); i++) { // avail의 크기만큼 돌고
		for (int j = 0; j < avail[0].size(); j++) { // 내부적으로 각 열을 검사
			if (i == 0 || i == avail.size() - 1 || j == 0 || j == avail[0].size() - 1) {
				avail[i][j] = 1;
			}
			else {
				avail[i][j] = 0;
			}
		}
	}

	for (string req : requests) {
		char a = req.substr(0, 1)[0];
		if (req.length() == 1) { // 지게차의 경우

			check1(a, storage, avail);
		}
		else { // 크레인의 경우
			check2(a, storage, avail,visited);
		}
	}
	//이제서야 answer를 만들자
	for (int i = 0; i < avail.size(); i++) {
		for (int j = 0; j < avail[0].size(); j++) {
			if (storage[i][j] != '9') {
				answer++;
			}
		}
	}
	return answer;
}
