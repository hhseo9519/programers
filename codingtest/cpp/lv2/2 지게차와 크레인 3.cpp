
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int n = storage.size();
    int m = storage[0].size();
    int answer = n * m;

    for (string request : requests) {
        if (request.length() > 1) {//ũ������ ��츦 ����
            for (string& s : storage) {
                for (char& c : s) {
                    if (c == request[0]) {
                        answer--;
                        c = '0';//����ִ� �κ��� 0���� ���� storage 0���� �����
                    }
                }
            }
        }
        else {//������ �κ�
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n, vector<bool>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i > 0 && i < n - 1 && j>0 && j < m - 1)    continue;//�� �ٱ� �κ��� �˻��� �ʿ䵵 ���� �׳�  �Ѿ
                    q.push({ i,j });//�������� �����Ÿ� �� �س������� �������� �˻��ϸ� �Ǵϱ�
                    visited[i][j] = true;//�簢�� �ٱ��� �κи� true�� �س���
                }
            }
            ť���� �׵θ��� ������
            while (!q.empty()) {
                pair<int, int> current = q.front();
                q.pop();

                if (storage[current.first][current.second] == request[0]) {
                    answer--;�� ��� ���� �� ����
                        //�ƿ� Ž�� ��ü�� �� ��� ���� Ž���ϴ°���.. ����
                    storage[current.first][current.second] = '0';
                }
                else if (storage[current.first][current.second] == '0') {
                    for (int i = 0; i < 4; i++) {
                        int nx = current.first + dx[i];
                        int ny = current.second + dy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])   continue;

                        q.push({ nx, ny });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }


    return answer;
}