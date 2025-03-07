#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    string temp;
    for (int i = 0; i < callings.size(); i++) {
       auto it= find(players.begin(), players.end(), callings[i]);
       auto k = distance(players.begin(), it);
       temp = players[k - 1];
       players[k - 1] = players[k];
       players[k] = temp;
    }
    
    
    
    
    answer = players;
    return answer;
}