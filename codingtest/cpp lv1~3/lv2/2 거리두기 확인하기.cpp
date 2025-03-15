#include <string>
#include <vector>

using namespace std;
int up[8] = { -1,-2,0,0,1,2,0,0 };
int right[8] = { 0,0,1,2,0,0,-1,-2 };
int cr[4] = { -1,1,1,-1 };
int cr2[4] = { 1,1,-1,-1 };
bool check4(vector<string>place, int row, int col) {
    bool checking = true;
    for (int i = 0; i < 8; i++) {
        int newi = row + up[i];
        int newj = col + right[i];
        if (newi >= 0 && newi < 5 && newj >= 0 && newj < 5) {
            if (place[newi][newj] == 'P') {
                if (i == 0 || i == 4 || i == 2 || i == 6) {
                    return false;
                }
                else {
                    if (i == 1) {//위로 두칸
                        if (place[newi + 1][newj] != 'X') {
                            return false;
                        }
                    }
                    else if (i == 5) {//아래로
                        if (place[newi - 1][newj] != 'X') {
                            return false;
                        }

                    }
                    else if (i == 3) {
                        if (place[newi][newj - 1] != 'X') {
                            return false;
                        }

                    }
                    else if (i == 7) {
                        if (place[newi][newj + 1] != 'X') {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return checking;
}
bool checkcross(vector<string>place, int row, int col) {
    bool checking = true;
    for (int i = 0; i < 4; i++) {
        int newi = row + cr[i];
        int newj = col + cr2[i];

        if (newi >= 0 && newi < 5 && newj >= 0 && newj < 5) {//이럼 체크 해봐
            if (i == 0) {//오위
                if (place[newi][newj - 1] == 'X' && place[newi + 1][newj] == 'X') {

                }
                else {
                    return false;
                }
            }
            else if (i == 1) {//오아래
                if (place[newi - 1][newj] == 'X' && place[newi][newj - 1] == 'X') {

                }
                else {
                    return false;
                }
            }
            else if (i == 2) {//왼아래
                if (place[newi - 1][newj] == 'X' && place[newi][newj + 1] == 'X') {

                }
                else {
                    return false;
                }
            }
            else if (i == 3) {//왼위
                if (place[newi + 1][newj] == 'X' && place[newi][newj + 1] == 'X') {

                }
                else {
                    return false;
                }
            }
        }

    }
    return checking;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        bool ans = true;
        bool ans2 = true;
        vector<string> place = places[i];
        vector<pair<int, int>>checkfor;
        for (int j = 0; j < place.size(); j++) {
            for (int u = 0; u < place[0].size(); u++) {
                if (place[j][u] == 'P') {

                    checkfor.push_back(make_pair(j, u));
                }
            }
        }//하나의 방의 사람을 모두체크하고 checkfor에 넣음

        for (auto p : checkfor) {
            int row = p.first;
            int col = p.second;

            //앞뒤 양옆 체크하는 애
            ans = check4(place, p.first, p.second);

            //대각선 체크하는애
            ans2 = checkcross(place, p.first, p.second);
        }
        if (ans == true && ans2 == true) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}