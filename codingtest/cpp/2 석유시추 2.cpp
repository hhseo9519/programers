#include <string>
#include <vector>
#include <stack>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
int dy[4] = { - 1, 0, 1, 0};//�ϵ����� ������ �ð����
int dx[4] = { 0, 1, 0, -1 };
stack <pair<int, int>> toVisit;

bool isValid(int row, int col, int N, int M,vector<vector<int>>land) {
    return (row >= 0 && row < N && col >= 0 && col < M);
}

void check(vector<vector<int>>land, int row, int col,
    int& count,vector<pair<int,int>>&score){
    if (land[row][col] !=1) {//1�� �ƴ϶�� ���̰ų� �̹� ���� ���差 ũ�⸦ Ȯ���� ��
        return;
    }
    //������� ���� 1�̱���!!
    count++; //������ �ִٴ� ���̴ϱ�
    toVisit.push(make_pair(row, col));
    
    for (int i = 0; i < 4; i++) {//�ϵ����� �ð� �������� Ȯ���ϰڴ�.
        int newrow = row + dy[i];
        int newcol = col + dx[i];
       
        if (isValid(newrow, newcol, land.size(), land[0].size(),land)) {
            check(land, newrow, newcol,count,score);
        }
    }
    if (!toVisit.empty()) {
        score.push_back(make_pair(toVisit.top().first, toVisit.top().second));
        toVisit.pop();
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    int count = 0;
    vector<pair<int, int>> score;//���� �湮�� ������ �ִ� ������ �� ������ ���差�� ũ��� �ٲ� ���߿� �� Ž���ϴ� ���� �����Ŵ�.
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            //�������� �� ĭ���� ����!!
            score.clear();
            count = 0;
            check(land,i,j,count,score);//����Լ��� ������ �ؾ���, 1�� �ƴϸ� �ٷ� Ż��
            count = score.size();
            for (int k = 0; k < score.size(); k++) {//score.size()�� 0�� ��� �̰� ���� ���� ����.
                land[score[k].first][score[k].second] = count;
            }
        }
    }
    
    int maxVal = -1;
    for (auto& row : land) {//���� �߻� ����� ���̱�
        maxVal = max(maxVal, *max_element(row.begin(), row.end()));
    }
    answer = maxVal;
    return answer;
}

//����ð� �ʰ�,,,