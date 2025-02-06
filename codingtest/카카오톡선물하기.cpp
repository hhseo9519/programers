#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
#include<sstream>
using namespace std;
pair<string, string>division(string gifts2) {
    pair<string, string>names;
    size_t pos = gifts2.find(' ');
    names=make_pair(gifts2.substr(0, pos),gifts2.substr(pos+1));
    return names;

}
int solution(const vector<string> friends, const vector<string> gifts) {
    int answer = 0;

    //이제 표를 만들어보자
      //int arr[friends.size()] //배열은 크기를 미리 알아야하니까 이렇게는 안됌
    vector<vector<int>>chart(friends.size(), vector<int>(friends.size(), 0));
    pair<string, string>fordivision;
    vector<int>giftscore(friends.size(),0);
    vector<int>bestgifter(friends.size(), 0);
    for (string gif : gifts) {
        fordivision=division(gif);
        auto it = find(friends.begin(), friends.end(), fordivision.first);
        int index = distance(friends.begin(), it);
        auto itto = find(friends.begin(), friends.end(), fordivision.second);
        int indexto = distance(friends.begin(), itto);

        chart[index][indexto] += 1;
        chart[indexto][index] -= 1;

    }
    int temp = 0;
    for (int i = 0; i < chart.size(); i++) {
        temp = 0;
        for (int j = 0; j < chart[0].size(); j++) {
            
            temp += chart[i][j];
            
        }
        giftscore[i] = temp;
    }
    int whob;
    for (int i = 0; i < friends.size(); i++) {
        whob = 0;
        for (int j = 0; j < friends.size(); j++) {
            if (chart[i][j] >0) {
                whob += 1;
            }
            else if (chart[i][j] == 0 && i != j) {
                if (giftscore[i] > giftscore[j]) {
                    whob += 1;
                }
                else {

                }
            }
        }
        bestgifter[i] = whob;
    }
    auto max_it = max_element(bestgifter.begin(), bestgifter.end());
    int ans = distance(bestgifter.begin(), max_it);
    answer = bestgifter[ans];

    return answer;
}
//다른 사람의 풀이 보통 map을 사용함,, map 사용법 정리하자
int solution(vector<string> friends, vector<string> gifts) {

    vector<int> point(friends.size(), 0);
    vector<vector<int>> count(friends.size(), vector<int>(friends.size(), 0));
    map<string, int> m;

    for (int i = 0; i < friends.size(); i++)
        m.insert({ friends[i], i });

    for (int i = 0; i < gifts.size(); i++) {
        string from, to;
        stringstream parse(gifts[i]);
        parse >> from >> to;

        int fromIdx = m[from], toIdx = m[to];/*map이라서 from과 to라는 key를 가지고
        value에 접근하여 사용하는 것이고, count표는 내가 만든 표와 같은 역할을 하는 
        것이다. 여기서 map을 사용하는 것과 stream parse를 사용하는 것을 알아가야 한다
        */
        count[fromIdx][toIdx]++;

        point[fromIdx]++;
        point[toIdx]--;
    }

    int ans = 0;

    for (int i = 0; i < friends.size(); i++) {
        int res = 0;

        for (int j = 0; j < friends.size(); j++) {
            if (i == j || count[i][j] < count[j][i]) continue;

            if (count[i][j] > count[j][i]) res++;
            else {
                if (point[i] > point[j]) res++;
            }
        }

        ans = max(res, ans);
    }

    return ans;
}