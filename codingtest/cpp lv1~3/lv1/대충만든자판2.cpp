#include <string>
#include <vector>
#include<map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    map<char, int> keyboard;//여기서 char가 아니고 string?
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            char key = keymap[i][j];

            // key가 존재하지 않거나, 새로운 값 j가 기존 값보다 작으면 덮어씌움
            if (keyboard.find(key) == keyboard.end() || j < keyboard[key]) {
                keyboard[key] = j;
            }
        }
    }
    int count = 0;
    
    
        for (int i = 0; i < targets.size(); i++) {
            count = 0;
            for (int j = 0; j < targets[i].size(); j++) {
                auto it=keyboard.find(targets[i][j]);
                if (it != keyboard.end()) {
                    count += it->second + 1;
                }
                else {
                    count = -1;
                    break;
                }
            }
            answer.push_back(count);
        }
    




    return answer;
}