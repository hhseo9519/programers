#include <string>
#include <vector>

using namespace std;
void check(vector<vector<int>> land, pair<int,int> start) {
    int count = 1;
    bool available = true;
    pair<int, int> now;
    pair<int, int>prev;
    //동서남북 bfs,dfs 구현하기
    while (available) {

        if (land[start.first - 1][start.second] == 1&&start.first>0) {//윗 부분 체크
            prev = start;
            count++;
            start.first -= 1;
           
        }else if (land[start.first][start.second + 1] == 1 && start.second < land[0].size() - 1) {
            prev = start;
            count++;
            start.second += 1;
        }
        else if (land[start.first + 1][start.second] == 1 && start.first < land.size() - 1) {
            prev = start;
            count++;
            start.first += 1;
        }
        else if (land[start.first][start.second - 1] == 1 && start.second > 0) {
            prev = start;
            count++;
            start.second -= 1;
        }
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (land[i][j] == 1) {
                pair<int, int> location = make_pair(i, j);
                check(land, location);
            }
        }
    }
    return answer + 1;
}