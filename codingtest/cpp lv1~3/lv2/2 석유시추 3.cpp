#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };//북동남서 순서로 시계방향
int dx[4] = { 0, 1, 0, -1 };


bool isValid(int row, int col, int N, int M, vector<vector<int>>land) {
    return (row >= 0 && row < N && col >= 0 && col < M);
}

void dfs(vector<vector<int>>land, int row, int col,
    int& count, vector<pair<int, int>>& score) {
    if (land[row][col] != 1) {//1이 아니라면 땅이거나 이미 석유 매장량 크기를 확인한 곳
        return;
    }
    //여기까지 오면 1이구나!!
    count++; //석유가 있다는 말이니까
   

    for (int i = 0; i < 4; i++) {//북동남서 시계 방향으로 확인하겠다.
        int newrow = row + dy[i];
        int newcol = col + dx[i];

        if (isValid(newrow, newcol, land.size(), land[0].size(), land)) {
            dfs(land, newrow, newcol, count, score);
        }
    }
    
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    int count = 0;
    unordered_set<int, int> S;
    vector<int> col(M,0);
    vector<pair<int, int>> score;//내가 방문한 석유가 있는 지역은 다 석유의 매장량의 크기로 바뀌어서 나중에 또 탐색하는 일이 없을거다.
    
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            //석유시추 각 칸마다 시작!!
            score.clear();
            count = 0;
            dfs(land, i, j, count, score);//재귀함수로 구성을 해야함, 1이 아니면 바로 탈락
            count = score.size();
            for (int k = 0; k < score.size(); k++) {//score.size()가 0인 경우 이건 시작 되지 않음.
                land[score[k].first][score[k].second] = count;
            }
        }
    }
  
    return answer;
}

//실행시간 초과,,,