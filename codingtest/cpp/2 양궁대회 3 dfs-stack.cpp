#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> apeach;
vector<int> lion;
vector<int> maxRes; // ���� �迭
int maxDiff = 0; // �ִ� ������

// dpt : ����, (10-dpt)�� ������ ��
// asc : ���� ����ġ ����
// lsc : ���� ���̾� ����
// n : ���� ����� ȭ���� ����
void dfs(int dpt, int asc, int lsc, int n) {//��� asc�� �������� ���Ѱ� ����
    if (dpt == 11) {
        if (lsc <= asc) return;
        lion[10] += N - n; // ���� ȭ�� 0���� �����ֱ�
        if (lsc - asc > maxDiff) {
            maxRes = lion;
            maxDiff = lsc - asc;
        }
        else if (lsc - asc == maxDiff) { // ������ ���� ���, ���� ������ ���� ���� ��찡 ����
            for (int i = 10; i >= 0; i--) {
                if (lion[i] == maxRes[i]) continue;
                else {
                    if (lion[i] > maxRes[i]) {
                        maxRes = lion;
                    }
                    break;
                }
            }
        }
        return;
    }//���� ������ dpt�� 11�� �Ǿ��� �� �̹Ƿ� ���� ����ϴ�.

    // ���̾��� �ش� ����(10-dpt)�� ȹ���ϴ� ���
    int next = apeach[dpt] + 1;
    if (next + n <= N) { // ȭ�� �ִ� ������ �ѱ�� �ȵ� --> �ִ� ȭ���� �������� �۴ٸ�,
        int nasc = asc; // ���� ���̿����� ����ġ ����
        int nlsc = lsc + 10 - dpt; // ���� ���̿����� ���̾� ����
        if (next != 1) nasc -= (10 - dpt);//
        lion.push_back(next);
        dfs(dpt + 1, nasc, nlsc, next + n);//��� ���� 11�� �Ǹ� ���߰ڱ�,
        lion.pop_back(); // ��Ʈ��ŷ
    }

    // �ش� ������ �������� ����(ȭ���� ������� ����)
    lion.push_back(0);
    dfs(dpt + 1, asc, lsc, n);
    lion.pop_back(); // ��Ʈ��ŷ
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;

    int total = 0; // ����ġ�� �ʱ� ����
    for (int i = 0; i < info.size(); i++) {
        if (info[i]) {
            total += (10 - i);
        }
    }

    dfs(0, total, 0, 0);

    // maxDiff�� 0�� ��� ������Ʈ�� ���� �ʾ����Ƿ� ��� ������ε� ����ġ�� ������ �ѱ� �� ����
    if (maxDiff == 0) maxRes.push_back(-1);
    return maxRes;
}