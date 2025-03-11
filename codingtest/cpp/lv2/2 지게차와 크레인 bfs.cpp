#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �����¿� �̵��� ���� �迭
typedef pair<int, int> pii;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& avail) {
    int n = avail.size();
    int m = avail[0].size();
    queue<pii> q;

    // 2�� ��ġ�� ã�� ť�� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (avail[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }

    // BFS ����
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (avail[nx][ny] == 1) { // ������ ���� 1�� ������ 2�� 1�� ����
                    avail[x][y] = 1;
                    break; // �� �̻� �˻��� �ʿ� ����
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

    // ��� ���
    for (const auto& row : avail) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
