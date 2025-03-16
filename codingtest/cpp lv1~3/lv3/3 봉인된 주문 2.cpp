#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    long long ans = n;

    // 1. ���ĺ� ���� �迭 ��� (0-indexed: 'a'�� index 0, 1-indexed ��ȯ�� M2����)
    int M[26];
    char M2[27]; // �ε��� 1~26 ���
    for (int i = 0; i < 26; i++) {

        M2[i + 1] = 'a' + i;//�������� �ϴ� ��ȯ�� ���� ����
    }

    // 2. �̸� ����� 26�� �ŵ����� �迭 (���� 0~26) ���� ��� POW26[4]��� 26�� �������̴�
    //ABS=A�� �ش��ϴ� ����
    vector<long long> pow26(27, 1);
    for (int i = 1; i <= 26; i++) {
        pow26[i] = pow26[i - 1] * 26;
    }

    // 3. bans ó��: �� ban ���ڿ��� ���� k ��� ��, ���ǿ� ������ ans ����
    //    (���� �ڵ忡���� �� ���ڸ��� k�� pow(26, M[ban[j]]) * M[ban[j]]�� ����)
    for (const string& ban : bans) {
        long long k = 0;

        for (int j = 0; j < ban.size(); j++) {
            int letterVal = ban[j] - 'a' + 1; //a�� 1�̴ϱ�,, M[c] ��� ���� ���
            k += pow26[ban.size() - j] * letterVal;

        }
        if (k <= n) {
            ans++;
        }
    }

    // 4. ans�� 26�������� ��ȯ (���ڿ���)
    //    ���⼭ ����: 0�� ��� ó���� �ʿ��� �� ������ ���� ������ �״�� ������.
    vector<int> seat;
    while (ans > 0) {
        ans--; // 1 ���� 0 ��� 26�� ������ ����
        int remainder = ans % 26 + 1; // 1���� 26���� �������� ����
        ans /= 26;
        seat.push_back(remainder);
    }
    // 5. �ùٸ� ������ ���� (������ sort(rbegin, rend)�� �������� ���� ��)
    reverse(seat.begin(), seat.end());

    // 6. ���ڸ� ���ڷ� ��ȯ�Ͽ� answer�� �߰�
    for (int num : seat) {
        // num�� 0�� ��찡 �ִٸ� ó��(��: 'z'�� �ش��ϰԲ�)������, ���⼭�� ���� �ڵ��� ����
        if (num == 0) {

        }
        answer.push_back(M2[num]);
    }

    return answer;
}
