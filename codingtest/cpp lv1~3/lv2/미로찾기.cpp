#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int N, M;                       // �̷� ũ��
int maze[MAX][MAX];             // �̷� ǥ���� 2���� �迭
int visited[MAX][MAX];          // �湮 ��Ͽ� 2���� �迭
int dist[MAX][MAX];             // �̵�ĭ ��Ͽ� 2���� �迭

int x_dir[4] = { -1, 1, 0, 0 };   // ��ȭ�¿� x�� ����
int y_dir[4] = { 0, 0, -1, 1 };   // ��ȭ�¿� y�� ����

queue<pair<int, int> > q;        // Ž�� ��ǥ ����� queue

// �̷� ��� Ž��
void bfs(int start_x, int start_y) {

    visited[start_x][start_y] = 1;          // �Է� ���� ���� ��ǥ�� �湮
    q.push(make_pair(start_x, start_y));     // queue �� ����
    dist[start_x][start_y]++;               // ���� ��ǥ���� �̵��� ĭ�� 1�� ����

    // ��� ��ǥ�� Ž���� ������ �ݺ�
    while (!q.empty()) {

        // queue �� front ��ǥ��, ���� ��ǥ�� ����
        int x = q.front().first;
        int y = q.front().second;

        // qeueu �� front ��ǥ ����
        q.pop();

        // ���� ��ǥ�� �����¿�� ������ ��ǥ Ȯ��
        for (int i = 0; i < 4; ++i) {

            // ���� ��ǥ�� �����¿�� ������ ��ǥ
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            // ������ ��ǥ��, �̷� ���� �����ϴ���, �湮�� ���� ������, �̵��� �������� Ȯ��
            if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
                && !visited[x_new][y_new] && maze[x_new][y_new] == 1) {

                visited[x_new][y_new] = 1;              // ���� ��ǥ�� �湮�� ������ ����
                q.push(make_pair(x_new, y_new));        // ���� ��ǥ�� queue �� ����
                dist[x_new][y_new] = dist[x][y] + 1;    // ���� ��ǥ���� �̵��� �Ÿ� ����
            }
        }
    }
}

int main() {

    cin >> N >> M;                      // �̷� ũ�� �Է�

    for (int i = 0; i < N; ++i) {            // �̷� �Է�

        string row;                     // �� �Է�
        cin >> row;

        for (int j = 0; j < M; ++j) {        // �� �� ��ǥ�� ����
            maze[i][j] = row[j] - '0';    // �� �� ��ǥ������ ���� �����̱� ������, ���ڷ� ��ȯ
        }
    }

    bfs(0, 0);                          // �̷� Ž�� ����

    cout << dist[N - 1][M - 1];             // ���� ��ǥ������ �Ÿ� ���
}