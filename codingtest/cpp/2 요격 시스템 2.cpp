#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b)
        {return a[1] < b[1]; });// ���� �������� sort?
    //ù��° ���Ҹ� �������� �������� �����Ѵ�.
   //r�� �߰��ϸ� ������������ �����Ұ�?
    int prev = 0;
    int startend = targets[0][1]-1;//���� ������
    for (vector<int>target : targets) {
        
        if (startend>=target[0]||startend>=target[1]-1) {
            
        }
        else {
            answer++;
            startend = target[1]-1;
        }
    }

    return answer;
}