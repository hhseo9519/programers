#include <string>
#include <vector>
#include<set>
#include<map>

using namespace std;
int drow[4] = { -1,0,1,0 };
int dcol[4] = { 0,1,0,-1 };
void dfs(int row, int col,vector<vector<int>>&land,int num,int &count) {
    land[row][col] = num;
    count++;
    for (int i = 0; i < 4; i++) {
        
        int newrow = row + drow[i];
		int newcol = col + dcol[i];
        if (newrow < 0 || newrow >= land.size() || newcol < 0 || newcol >= land[0].size()) {
            continue;
        }
        if (land[newrow][newcol] == 1)
            dfs(newrow, newcol, land, num, count);
    
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    int count = 0;
    int num = 2;
    
    map<int, int>M;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            
            if (land[i][j] == 1) {
                count = 0;
                dfs(i, j, land,num,count);
               
                M.insert(make_pair(num, count));
                num++;
            }
        }
    }
    //���� �����ϸ� ���� ��ġ���� num���� �� ä�����ִ�.
    
    for (int i = 0; i < land[0].size(); i++){
        int temp = 0;
        set<int> S;
        for (int j = 0; j < land.size(); j++) {
            S.insert(land[j][i]);
        }
        for (auto it : S) {
            temp += M[it];// �������� �ʴ� Ű�� 0���� ��ȯ�ȴ�
        }
        answer = max(answer, temp);
    }

    return answer;
}