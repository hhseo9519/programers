#include <string>
#include <vector>
#include<map>
#include<cmath>
#include <algorithm>
using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    long long ans = n;
    long long num = n;
    map<char, int>M;
    map<int, char>M2;
    int count = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        M[i] = count;//a=1, b=2...z=26
        M2[count] = i;
        count++;
    }
    vector<int>seats;
    string koo = "";
    while (num != 0) {
        int num = num % 26;
        int nam = nam / 26;

        seats.push_back(nam);
    }
    sort(seats.rbegin(), seats.rend());

    for (int y : seats) {
        koo.push_back(M2[y]);
    }
    /* for(string ban : bans){//이부분을 바꿔보자
         long long k=0;
         int len=ban.size();
         for(int j=0;j<ban.size();j++){
             k+=pow(26,M[ban[j]])*M[ban[j]];
         }
         if(k<=n){
             ans--;
         }
     }*/

    for (string ban : bans) {
        if (ban <= koo) {
            ans--;
        }
    }
    //ans에 해당하는 것만 찾으면 됨
    vector<int>seat;


    while (ans != 0) {
        int namu = ans % 26;
        int ans = ans / 26;

        seat.push_back(namu);
    }
    sort(seat.rbegin(), seat.rend());

    for (int y : seat) {
        answer.push_back(M2[y]);
    }
    return answer;
}