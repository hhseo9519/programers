#include <string>
#include <vector>

using namespace std;
//Ʋ�ȴ� Ǯ��
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for (int i = 0; i < section.size(); i++) {
        if (section[i + 1] - section[i]+1 <= m) {
            answer++;
            i++;
        }
        else if (section[i + 1] - section[i] + 1 > m) {
            answer++;
        }
        if (i == section.size() - 1) {
            answer++;
            break;
        }
    }



    return answer;
}


//���� Ǯ��
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i = 0;  // ���� ĥ�� ������ �ε���

    while (i < section.size()) {
        answer++;  // ����Ʈ �� �� ĥ�ϱ�
        int paint_end = section[i] + m - 1;  // ���� ��ġ���� m ���̸�ŭ ĥ��

        // ĥ�� ������ �Ѿ�� �ʴ� ���� �ε����� ã��
        while (i < section.size() && section[i] <= paint_end) {
            i++;
        }
    }

    return answer;
}
