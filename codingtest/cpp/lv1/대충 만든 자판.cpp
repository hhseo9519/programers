#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    //키 하나당 1회를 더 추가해야 횟수가 된다.
    //둘다 2차원 배열
    //매번 한 문자 검사를 할 때 1회누를때 나올 수 있는 거 쭉 하
    //2회 누를 때 나올 수 있는 문자 쭉 하고 이런식으러 검사하자
    for (int i = 0; i < targets.size(); i++) {
        //i는 문자가 배정되면 그때 증가시킬 거다.
        for (int j = 0; j < targets[i].size(); j++) {

        }
    }



    
    return answer;
}