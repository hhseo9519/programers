#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b)
        {return a[1] < b[1]; });// 무슨 기준으로 sort?
    //첫번째 원소를 기준으로 오름차순 정렬한다.
   //r을 추가하면 내림차순으로 정렬할걸?
    int prev = 0;
    int startend = targets[0][1]-1;//제일 작은애
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