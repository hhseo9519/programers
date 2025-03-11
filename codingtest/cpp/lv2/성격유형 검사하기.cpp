#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int arrs[8] = { 0 };
    char arr[8] = { 'R','T','C','F','J','M','A','N' };
    for (int i = 0; i < survey.size(); i++) {
        char k = survey[i].substr(0, 1)[0];
        char g = survey[i].substr(1, 1)[0];
        int a, b;
        for (int j = 0; j < 8; j++) {//뭐랑 뭐인지 찾기 a의 경우는 1점일때 3, b의 경우는 7점일때 3
            if (k == arr[j]) {
                a = j;
            }
            if (g == arr[j]) {
                b = j;
            }
        }
        if (choices[i] == 1) {
            arrs[a] += 3;
        }
        else if (choices[i] == 2) {
            arrs[a] += 2;
        }
        else if (choices[i] == 3) {
            arrs[a] += 1;
        }
        else if (choices[i] == 5) {
            arrs[b] += 1;
        }
        else if (choices[i] == 6) {
            arrs[b] += 2;
        }
        else if (choices[i] == 7) {
            arrs[b] += 3;
        }

    }
    for (int i = 0; i < 8; i += 2)
        if (arrs[i] >= arrs[i + 1]) {
            answer.push_back(arr[i]);
        }
        else {
            answer.push_back(arr[i + 1]);
        }

    return answer;
}