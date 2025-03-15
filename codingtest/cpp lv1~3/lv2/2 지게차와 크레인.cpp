#include <string>
#include <vector>
int drow[4] = { -1,0,1,0 };
int dcol[4] = { 0,1,0,-1 };
using namespace std;
void check1(vector<vector<int>>& avail, vector<string>& requests, pair<int, int> out) {
	int row = out.first;
	int col = out.second;
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (nrow >= 0 && nrow < avail.size() && ncol >= 0 && ncol < avail[0].size()) {//가리키는 인덱스가 유효한 경우
			if (avail[nrow][ncol] == 1) {//출구와 연결 된다면 지게차가 접근 가능
				avail[row][col] = 1;
				break;
			}

		}
	}
}

void chg1(vector<string>& requests, vector<vector<int>>& avail, int n, int m, char T) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (requests[i][j] == T && avail[i][j] == 1) {
				requests[i][j] = '9';
				avail[i][j] = 2;//이건 자리만 없어졌다는 말이죠
				pair<int, int> out = make_pair(i, j);
				check1(avail, requests, out);//그 상태에서 업데이트를 해준다..
			}

		}
	}
}
void dfs(int row, int col, vector<vector<int>>& avail) {
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (nrow >= 0 && nrow < avail.size() && ncol >= 0 && ncol < avail[0].size()) {//가리키는 인덱스가 유효한 경우
			if (avail[nrow][ncol] == 2) {//출구와 연결 된다면 지게차가 접근 가능
				avail[row][col] = 1;
				dfs(nrow, ncol, avail);

			}

		}
	}

}
void check2(vector<vector<int>>& avail, vector<string>& requests) {
	int n = avail.size();
	int m = avail[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (avail[i][j] == 1) {
				int row = i;
				int col = j;
				dfs(i, j, avail);
			}
		}
	}
}
void chg2(vector<string>& requests, vector<vector<int>>& avail, int n, int m, char T) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (requests[i][j] == T) {
				requests[i][j] = '9';
				avail[i][j] = 2;

			}
		}
	}
	check2(avail, requests);

}

int solution(vector<string> storage, vector<string> requests) {
	int answer = 0;
	int n= storage.size();//세로 길이
	int m = storage[0].size();//가로 길이
	vector<vector<int>>avail(n, vector<int>(m, 0));//모두 0으로 채워놓은 상태
	//맨 바깥 부분은 초기에 1로 되어있어야 함 -> 지게차가 접근 가능
	for (int i = 0; i < storage.size(); i++) {
		for (int j = 0; j < storage[0].size(); j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				avail[i][j] = 1;
			}

		}
	}
	//입력 받은 것들을 하나씩 봐보자
	for (string sto : requests) {//여기서 requests는 바꿔줄거임
		if (sto.length() == 2) {//이건 지게차로 빼는 경우
			char ns = sto.substr(0, 1)[0];
			chg2(requests, avail, n, m, ns);//빼면서 매번 업데이트를 해야하네,, 그 부분만 업데이트를 살짝 하도록 하자 

		}
		else {
			char ns = sto.substr(0, 1)[0];
			chg1(requests, avail, n, m, ns);

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (requests[i][j] != 9) {
				answer++;
			}
		}
	}
	return answer;
}