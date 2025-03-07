#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    //제일 작은 x,y 제일 큰 x,y+1씩 이렇게 풀면 끝

    int lux = 0;
    int luy = 0;
    int rdx = 0;
    int rdy = 0;
    int smallx = 100;
    int smally = 100;
    int bigx = 0;
    int bigy = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                lux = i;
                luy = j;
                smallx = min(lux, smallx);
                smally = min(luy, smally);
                bigx = max(lux, bigx);
                bigy = max(luy, bigy);

            }
        }

    }

    answer.push_back(smallx);
    answer.push_back(smally);
    answer.push_back(bigx + 1);
    answer.push_back(bigy + 1);


    return answer;
}