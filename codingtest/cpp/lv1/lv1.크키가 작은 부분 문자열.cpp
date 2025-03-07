#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int length = p.size();//문자열의 길이를 나타내는 다른 함수
    

    for (int i = 0; i < t.size() - length+1; i++) {
        long long k = 0;
        k = stoll(t.substr(i, length));
        if (k <= stoll(p)) {
            answer++;
        }
    }

    return answer;
}
//코딩 할 때 범위를 잘 봐야겠다.
//long long을 쓰는 경우도 존재하겠다.