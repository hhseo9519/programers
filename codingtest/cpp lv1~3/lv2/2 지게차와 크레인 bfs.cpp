#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상하좌우 이동을 위한 배열
typedef pair<int, int> pii;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& avail) {
    int n = avail.size();
    int m = avail[0].size();
    queue<pii> q;

    // 2의 위치를 찾아 큐에 삽입
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (avail[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }

    // BFS 수행
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (avail[nx][ny] == 1) { // 인접한 곳에 1이 있으면 2를 1로 변경
                    avail[x][y] = 1;
                    break; // 더 이상 검사할 필요 없음
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> avail = {
        {1, 2, 1},
        {2, 9, 1},
        {1, 2, 2}
    };

    bfs(avail);

    // 결과 출력
    for (const auto& row : avail) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
