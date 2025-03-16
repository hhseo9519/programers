#include <string>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
string whatcode(int n, const vector<char> alphabet) { // 숫자를 주면 알파벳 코드로 바꿔줌
    string answer;
    vector<int> k;
    while (n != 0) {
        int remainder = n % 26;
        if (remainder == 0) {
            remainder = 26;
            n = n / 26 - 1;
        }
        else {
            n /= 26;
        }
        k.push_back(remainder);
    }
    reverse(k.begin(), k.end());
    for (int i = 0; i < k.size(); i++) {
        answer.push_back(alphabet[k[i]]);
    }
    return answer;
}


long long whatnum(string str, vector<long long>pow) {//문자를 주면 숫자로 바꿔줌
    int num = 0;
    for (int i = 0; i < str.size(); i++) {
        int c = str[i] - 'a' + 1;
        num += c * pow[c];
    }
    return num;
}
string solution(long long n, vector<string> bans) {
    string answer = "";

    vector<char> alphabet(28, ' ');//이걸 통해 나중에 숫자가 주어졌을 때 해당 알파벳 배열 찾기
    for (int i = 0; i <= 27; i++) {
        alphabet[i + 1] = 'a' + i;//인덱스 1에는 a, 2에는 b가 들어감
    }
    int ans = n;
    vector<long long> pow(12, 1);
    for (int i = 0; i < 11; i++) {
        pow[i + 1] = pow[i] * 26; //26의 0승은 pow[0],, pow[3]=26의 3승이다
    }
    string ansis = whatcode(n, alphabet);
    int y = ansis.length();
    int count = 0;
    for (int i = 0; i < bans.size(); i++) {
        if (bans[i].length() > y) {
            continue;
        }
        else if (bans[i].length() < y) {
            ans++;
            count++;
        }
        else {
            long long banning = whatnum(bans[i], pow);
            if (banning - count <= n) {
                ans++;
                count++;
            }
        }
    }
    answer = whatcode(ans, alphabet);
    return answer;
}