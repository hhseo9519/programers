
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
        if (request.length() > 1) {//크레인의 경우를 말함
            for (string& s : storage) {
                for (char& c : s) {
                    if (c == request[0]) {
                        answer--;
                        c = '0';//비어있는 부분을 0으로 넣음 storage 0으로 만들기
                    }
                }
            }
        }
        else {//지게차 부분
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n, vector<bool>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i > 0 && i < n - 1 && j>0 && j < m - 1)    continue;//맨 바깥 부분은 검사할 필요도 없고 그냥  넘어가
                    q.push({ i,j });//지게차로 넣을거를 쭉 해놓은거지 지게차만 검사하면 되니까
                    visited[i][j] = true;//사각형 바깥쪽 부분만 true로 해놓기
                }
            }
            큐에는 테두리만 들어가있음
            while (!q.empty()) {
                pair<int, int> current = q.front();
                q.pop();

                if (storage[current.first][current.second] == request[0]) {
                    answer--;손 닿는 곳을 다 넣음
                        //아예 탐색 자체를 손 닿는 곳만 탐색하는거지.. 좋다
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