#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    long long ans = n;

    // 1. 알파벳 매핑 배열 사용 (0-indexed: 'a'는 index 0, 1-indexed 변환은 M2에서)
    int M[26];
    char M2[27]; // 인덱스 1~26 사용
    for (int i = 0; i < 26; i++) {

        M2[i + 1] = 'a' + i;//마지막에 하는 변환을 위한 과정
    }

    // 2. 미리 계산한 26의 거듭제곱 배열 (지수 0~26) 예를 들어 POW26[4]라면 26의 네제곱이다
    //ABS=A에 해당하는 숫자
    vector<long long> pow26(27, 1);
    for (int i = 1; i <= 26; i++) {
        pow26[i] = pow26[i - 1] * 26;
    }

    // 3. bans 처리: 각 ban 문자열에 대해 k 계산 후, 조건에 맞으면 ans 감소
    //    (원래 코드에서는 각 문자마다 k에 pow(26, M[ban[j]]) * M[ban[j]]를 더함)
    for (const string& ban : bans) {
        long long k = 0;

        for (int j = 0; j < ban.size(); j++) {
            int letterVal = ban[j] - 'a' + 1; //a가 1이니까,, M[c] 대신 직접 계산
            k += pow26[ban.size() - j] * letterVal;

        }
        if (k <= n) {
            ans++;
        }
    }

    // 4. ans를 26진법으로 변환 (문자열로)
    //    여기서 주의: 0인 경우 처리가 필요할 수 있으나 원래 로직을 그대로 유지함.
    vector<int> seat;
    while (ans > 0) {
        ans--; // 1 빼서 0 대신 26이 나오게 조정
        int remainder = ans % 26 + 1; // 1부터 26까지 나오도록 조정
        ans /= 26;
        seat.push_back(remainder);
    }
    // 5. 올바른 순서로 정렬 (원래는 sort(rbegin, rend)로 내림차순 정렬 후)
    reverse(seat.begin(), seat.end());

    // 6. 숫자를 문자로 변환하여 answer에 추가
    for (int num : seat) {
        // num가 0인 경우가 있다면 처리(예: 'z'에 해당하게끔)하지만, 여기서는 원래 코드대로 진행
        if (num == 0) {

        }
        answer.push_back(M2[num]);
    }

    return answer;
}
