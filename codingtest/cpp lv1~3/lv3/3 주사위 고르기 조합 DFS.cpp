#include <string>
#include <vector>
/// <summary>
/// 조합을 구하는 첫번째 방법이고 재귀를 사용했다.
/// </summary>
using namespace std;
vector<vector<int>>A;

void dfs(int count, int n, vector<int>& accum, vector<int>& visited) {
    if (count == n) {

        A.push_back(accum);
        accum.clear();
        vector<int>visited(n, 0);

    }
    for (int i = count; i < n; i++) {
        if (visited[i] == 0) {
            accum.push_back(i + 1);
            visited[i] = 1;
            dfs(count, n, accum, visited);
        }
    }
    count++;
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size()
        vector<int>visited(n, 0);
    vector<int> accum;
    dfs(1, n, accum, visited);

    return answer;
}


///두번째 방법--> 내가 쓴 잘못된 코드

#include <string>
#include <vector>

using namespace std;
vector<vector<int>>A;

void dfs(int count, int n, vector<int>& accum, vector<int>& visited) {
    if (count == n / 2) {

        A.push_back(accum);
        accum.clear();
        vector<int>visited(n, 0);//이 부분이 잘못 되었는데 이렇게 되면 123 124 125 이런식으로 저장할 수가 없음 
        //그냥 아예 리셋되니까 123 다음에 112 이게 나오게 될거야
        //그래서 잘못되었다
        //이게 아니라 아래처럼 해야지
    }
    for (int i = count; i < n; i++) {
        if (visited[i] == 0) {
            accum.push_back(i + 1);//count가 0부터 시작했음
            visited[i] = 1;

            dfs(count + 1, n, accum, visited);
        }
    }

}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A; // 조합 결과 저장

void dfs(int start, int count, int n, vector<int>& accum) {
    if (count == n / 2) {
        A.push_back(accum);
        return;
    }

    for (int i = start; i < n; i++) {
        accum.push_back(i + 1); // 숫자 선택
        dfs(i + 1, count + 1, n, accum); // 다음 인덱스부터 탐색--> 이렇게 해야 135, 531 과 같은 같은 조합이 생겨나지 않음.
        accum.pop_back(); // 백트래킹 (되돌리기)--> 이건 스택을 이용한 dfs가 아니라 경로를 저장하기 위한것이기 때문에 헷갈리지 말자
    }
}

//세번째 스택을 활용한 dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> A;

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size();
    vector<int>visited(n, 0);
    vector<int> accum;
    stack<int>s;
    s.push(1);
    while (!s.empty()) {//사실 여기서는 accum의 역할이 필요 없나? 



    }

    return answer;
}