#include <string>
#include <vector>
#include<map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    map<char, int> keyboard;//���⼭ char�� �ƴϰ� string?
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            char key = keymap[i][j];

            // key�� �������� �ʰų�, ���ο� �� j�� ���� ������ ������ �����
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