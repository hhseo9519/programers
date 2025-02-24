#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };//�ϵ����� ������ �ð����
int dx[4] = { 0, 1, 0, -1 };


bool isValid(int row, int col, int N, int M, vector<vector<int>>land) {
    return (row >= 0 && row < N && col >= 0 && col < M);
}

void dfs(vector<vector<int>>land, int row, int col,
    int& count) {
    if (land[row][col] != 1) {//1�� �ƴ϶�� ���̰ų� �̹� ���� ���差 ũ�⸦ Ȯ���� ��
        return;
    }
    //������� ���� 1�̱���!!
    count++; //������ �ִٴ� ���̴ϱ�


    for (int i = 0; i < 4; i++) {//�ϵ����� �ð� �������� Ȯ���ϰڴ�.
        int newrow = row + dy[i];
        int newcol = col + dx[i];

        if (isValid(newrow, newcol, land.size(), land[0].size(), land)) {

            dfs(land, newrow, newcol, count);
            
        }
    }

}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int N = land.size();
    int M = land[0].size();
    int count = 0;
    vector<int> col(M, 0);//���⼭�� �ִ��� ���� �ɰŴ�
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            //�������� �� ĭ���� ����!!
            count = 0;
            dfs(land, i, j, count);//����Լ��� ������ �ؾ���, 1�� �ƴϸ� �ٷ� Ż��
        
        }
    }
   
    return answer;
}

//����ð� �ʰ�,,,