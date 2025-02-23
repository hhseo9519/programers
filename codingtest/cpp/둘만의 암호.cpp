#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    //������ �̿��ؼ� ������ �ɰ� ������
    vector<char> alphabet;
    for (char c = 'a'; c <= 'z'; c++) {
        alphabet.push_back(c);
    }
    vector<char> ::iterator iter;
    for (int i = 0; i < skip.size(); i++) {
       auto it= find(alphabet.begin(), alphabet.end(), skip[i]);
       alphabet.erase(it);//��? distance �Լ� �Ƚᵵ �̰� ��??
       //erase�Լ��� ������ �� �˾ƺ��� �ڴµ�?


    }
    int k = alphabet.size();
    
    for (int i = 0; i < s.size(); i++) {
        auto it = find(alphabet.begin(), alphabet.end(), s[i]);
        //it�� �����Ͷ�,, �ε����� �˷��� distance�Լ��� �����
        int dist = distance(alphabet.begin(), it);
        s[i] = alphabet[(dist+index) %k];
    }

    answer = s;
    return answer;
}