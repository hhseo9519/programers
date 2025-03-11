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
		if (nrow >= 0 && nrow < avail.size() && ncol >= 0 && ncol < avail[0].size()) {//����Ű�� �ε����� ��ȿ�� ���
			if (avail[nrow][ncol] == 1) {//�ⱸ�� ���� �ȴٸ� �������� ���� ����
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
				avail[i][j] = 2;//�̰� �ڸ��� �������ٴ� ������
				pair<int, int> out = make_pair(i, j);
				check1(avail, requests, out);//�� ���¿��� ������Ʈ�� ���ش�..
			}

		}
	}
}
void dfs(int row, int col, vector<vector<int>>& avail) {
	for (int i = 0; i < 4; i++) {
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if (nrow >= 0 && nrow < avail.size() && ncol >= 0 && ncol < avail[0].size()) {//����Ű�� �ε����� ��ȿ�� ���
			if (avail[nrow][ncol] == 2) {//�ⱸ�� ���� �ȴٸ� �������� ���� ����
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
	int n= storage.size();//���� ����
	int m = storage[0].size();//���� ����
	vector<vector<int>>avail(n, vector<int>(m, 0));//��� 0���� ä������ ����
	//�� �ٱ� �κ��� �ʱ⿡ 1�� �Ǿ��־�� �� -> �������� ���� ����
	for (int i = 0; i < storage.size(); i++) {
		for (int j = 0; j < storage[0].size(); j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				avail[i][j] = 1;
			}

		}
	}
	//�Է� ���� �͵��� �ϳ��� ������
	for (string sto : requests) {//���⼭ requests�� �ٲ��ٰ���
		if (sto.length() == 2) {//�̰� �������� ���� ���
			char ns = sto.substr(0, 1)[0];
			chg2(requests, avail, n, m, ns);//���鼭 �Ź� ������Ʈ�� �ؾ��ϳ�,, �� �κи� ������Ʈ�� ��¦ �ϵ��� ���� 

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