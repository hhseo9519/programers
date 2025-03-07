#include <string>
#include <vector>

using namespace std;
float dis[4] = { 0.9,0.8,0.7,0.6 };
//채울 표
vector<pair<int, int>> price(7,{ 0,0 });//할인율과 가격을 쓰자
vector<int> answer(2, 0);
void dfs(int cnt,vector<vector<int>> users, vector<int> emoticons) {
    if (cnt == emoticons.size()) {
        int plus = 0, sum = 0;
        for (int i = 0; i < users.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < emoticons.size(); j++) {
                if (users[i][0] <= price[i].first) {
                    tmp += price[j].first;
                }
                if (tmp >= users[i][1]) {
                    plus++;
                }
                else { sum += tmp; }
            }
            if (plus > answer[0]) {
                answer[0] = plus;
                answer[1] = sum;
            }
            else if (plus == answer[0] && sum >= answer[1]) {
                answer[1] = sum;

            }
            
        }
        return;
    }
    for (int i = 1; i < 5; i++) {
        price[cnt].first = i;
        price[cnt].second = emoticons[cnt] * dis[i - 1];
        dfs(cnt+1, users, emoticons);
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    dfs(0, users, emoticons);
    return answer;
}