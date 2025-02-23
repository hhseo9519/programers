#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    //나눗셈 이용해서 돌리면 될거 같은데
    vector<char> alphabet;
    for (char c = 'a'; c <= 'z'; c++) {
        alphabet.push_back(c);
    }
    vector<char> ::iterator iter;
    for (int i = 0; i < skip.size(); i++) {
       auto it= find(alphabet.begin(), alphabet.end(), skip[i]);
       alphabet.erase(it);//오? distance 함수 안써도 이게 돼??
       //erase함수의 문법을 좀 알아봐야 겠는데?


    }
    int k = alphabet.size();
    
    for (int i = 0; i < s.size(); i++) {
        auto it = find(alphabet.begin(), alphabet.end(), s[i]);
        //it는 포인터라서,, 인덱스를 알려면 distance함수를 써야함
        int dist = distance(alphabet.begin(), it);
        s[i] = alphabet[(dist+index) %k];
    }

    answer = s;
    return answer;
}