#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> apeach;
vector<int> lion;
vector<int> maxRes; // 정답 배열
int maxDiff = 0; // 최대 점수차

// dpt : 깊이, (10-dpt)가 점수가 됨
// asc : 현재 어피치 점수
// lsc : 현재 라이언 점수
// n : 현재 사용한 화살의 개수
void dfs(int dpt, int asc, int lsc, int n) {//계속 asc를 해주지만 변한건 없음
    if (dpt == 11) {
        if (lsc <= asc) return;
        lion[10] += N - n; // 남은 화살 0점에 몰아주기
        if (lsc - asc > maxDiff) {
            maxRes = lion;
            maxDiff = lsc - asc;
        }
        else if (lsc - asc == maxDiff) { // 점수가 같은 경우, 낮은 점수에 많이 맞힌 경우가 정답
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
    }//여기 까지는 dpt가 11이 되었을 때 이므로 나랑 비슷하다.

    // 라이언이 해당 점수(10-dpt)를 획득하는 경우
    int next = apeach[dpt] + 1;
    if (next + n <= N) { // 화살 최대 개수를 넘기면 안됨 --> 최대 화살의 개수보다 작다면,
        int nasc = asc; // 다음 깊이에서의 어피치 점수
        int nlsc = lsc + 10 - dpt; // 다음 깊이에서의 라이언 점수
        if (next != 1) nasc -= (10 - dpt);//
        lion.push_back(next);
        dfs(dpt + 1, nasc, nlsc, next + n);//계속 가서 11이 되면 멈추겠군,
        lion.pop_back(); // 백트래킹
    }

    // 해당 점수는 선택하지 않음(화살을 사용하지 않음)
    lion.push_back(0);
    dfs(dpt + 1, asc, lsc, n);
    lion.pop_back(); // 백트래킹
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;

    int total = 0; // 어피치의 초기 점수
    for (int i = 0; i < info.size(); i++) {
        if (info[i]) {
            total += (10 - i);
        }
    }

    dfs(0, total, 0, 0);

    // maxDiff가 0인 경우 업데이트가 되지 않았으므로 어떠한 방법으로도 어피치의 점수를 넘길 수 없음
    if (maxDiff == 0) maxRes.push_back(-1);
    return maxRes;
}