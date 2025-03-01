#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// �� �ð��� �ð��� ���õ� ������ ������ Time Ŭ���� ����
class Time {
public:
    int h, m, s;

    // �ʷ� ��ȯ�� �ð��� ������ Time�� ���� �� �ֵ��� ������ ����
    Time(int seconds) {
        this->h = seconds / 3600;
        this->m = (seconds % 3600) / 60;
        this->s = (seconds % 3600) % 60;
    }

    // ��� �ð��� �ʷ� ��ȯ
    int toSeconds() {
        return h * 3600 + m * 60 + s;
    }

    // ������ ����ؼ� List ���·� ��ȯ
    vector<double> getDegree() {
        double hDegree = (h % 12) * 30.0 + m * 0.5 + s * (1 / 120.0);
        double mDegree = m * 6.0 + s * (0.1);
        double sDegree = s * 6.0;

        return vector<double>{hDegree, mDegree, sDegree};
    }
};

// ��ħ�� ��ħ�� ��ħ�� �Ǵ�
bool hourMatch(vector<double> cnt, vector<double> next) {
    if (cnt[0] > cnt[2] && next[0] <= next[2]) {
        return true;
    }

    // ��ħ�� 354������ 0���� �Ѿ �� ���� ���̽�
    if (cnt[2] == 354 && cnt[0] > 354) {
        return true;
    }
    return false;
}

// ��ħ�� ��ħ�� ��ħ�� �Ǵ�
bool minuteMatch(vector<double> cnt, vector<double> next) {
    if (cnt[1] > cnt[2] && next[1] <= next[2]) {
        return true;
    }

    // ��ħ�� 354������ 0���� �Ѿ �� ���� ���̽�
    if (cnt[2] == 354 && cnt[1] > 354) {
        return true;
    }
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    // ���� �ð���, ���� �ð��� �� ������ ����
    int start = Time(h1 * 3600 + m1 * 60 + s1).toSeconds();
    int end = Time(h2 * 3600 + m2 * 60 + s2).toSeconds();

    // ���� �ð����� 1�ʾ� �÷����� ���(������ �ʴ� ���ԵǸ� �ȵ�)
    // ������ �� + 1���� �Ǵ��ع���
    for (int i = start; i < end; i++) {
        vector<double> cnt = Time(i).getDegree();
        vector<double> next = Time(i + 1).getDegree();

        bool hMatch = hourMatch(cnt, next);
        bool mMatch = minuteMatch(cnt, next);

        // ��ħ�� ��ħ�� ��ħ�� ��ħ�� �߻����� ��,
        if (hMatch && mMatch) {
            // ��ħ�� ��ħ�� ������ ���ٸ� +1�� �������
            if (next[0] == next[1]) answer++;
            // �ƴ϶�� +2
            else answer += 2;
        }
        // �� �� �ϳ��� ��ġ�� +1
        else if (hMatch || mMatch) answer++;
    }

    // �� ������ ���۽ð��� ���� �˻縦 ��������
    // �׷��� 0�� �Ǵ� 12�ÿ� �����Ѵٸ�, �ѹ� ��ġ�� �����ϴ� ���̱� ������ +1
    if (start == 0 || start == 43200) answer++;
    return answer;
}