#include <string>
#include <vector>
/// <summary>
/// ������ ���ϴ� ù��° ����̰� ��͸� ����ߴ�.
/// </summary>
using namespace std;
vector<vector<int>>A;

void dfs(int count, int n, vector<int>& accum, vector<int>& visited) {
    if (count == n) {

        A.push_back(accum);
        accum.clear();
        vector<int>visited(n, 0);

    }
    for (int i = count; i < n; i++) {
        if (visited[i] == 0) {
            accum.push_back(i + 1);
            visited[i] = 1;
            dfs(count, n, accum, visited);
        }
    }
    count++;
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size()
        vector<int>visited(n, 0);
    vector<int> accum;
    dfs(1, n, accum, visited);

    return answer;
}


///�ι�° ���--> ���� �� �߸��� �ڵ�

#include <string>
#include <vector>

using namespace std;
vector<vector<int>>A;

void dfs(int count, int n, vector<int>& accum, vector<int>& visited) {
    if (count == n / 2) {

        A.push_back(accum);
        accum.clear();
        vector<int>visited(n, 0);//�� �κ��� �߸� �Ǿ��µ� �̷��� �Ǹ� 123 124 125 �̷������� ������ ���� ���� 
        //�׳� �ƿ� ���µǴϱ� 123 ������ 112 �̰� ������ �ɰž�
        //�׷��� �߸��Ǿ���
        //�̰� �ƴ϶� �Ʒ�ó�� �ؾ���
    }
    for (int i = count; i < n; i++) {
        if (visited[i] == 0) {
            accum.push_back(i + 1);//count�� 0���� ��������
            visited[i] = 1;

            dfs(count + 1, n, accum, visited);
        }
    }

}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A; // ���� ��� ����

void dfs(int start, int count, int n, vector<int>& accum) {
    if (count == n / 2) {
        A.push_back(accum);
        return;
    }

    for (int i = start; i < n; i++) {
        accum.push_back(i + 1); // ���� ����
        dfs(i + 1, count + 1, n, accum); // ���� �ε������� Ž��--> �̷��� �ؾ� 135, 531 �� ���� ���� ������ ���ܳ��� ����.
        accum.pop_back(); // ��Ʈ��ŷ (�ǵ�����)--> �̰� ������ �̿��� dfs�� �ƴ϶� ��θ� �����ϱ� ���Ѱ��̱� ������ �򰥸��� ����
    }
}

//����° ������ Ȱ���� dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> A;

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size();
    vector<int>visited(n, 0);
    vector<int> accum;
    stack<int>s;
    s.push(1);
    while (!s.empty()) {//��� ���⼭�� accum�� ������ �ʿ� ����? 



    }

    return answer;
}