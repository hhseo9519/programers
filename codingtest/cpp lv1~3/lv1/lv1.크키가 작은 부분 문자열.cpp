#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int length = p.size();//���ڿ��� ���̸� ��Ÿ���� �ٸ� �Լ�
    

    for (int i = 0; i < t.size() - length+1; i++) {
        long long k = 0;
        k = stoll(t.substr(i, length));
        if (k <= stoll(p)) {
            answer++;
        }
    }

    return answer;
}
//�ڵ� �� �� ������ �� ���߰ڴ�.
//long long�� ���� ��쵵 �����ϰڴ�.