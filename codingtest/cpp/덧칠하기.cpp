#include <string>
#include <vector>

using namespace std;
//틀렸던 풀이
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


//맞은 풀이
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i = 0;  // 현재 칠할 구역의 인덱스

    while (i < section.size()) {
        answer++;  // 페인트 한 번 칠하기
        int paint_end = section[i] + m - 1;  // 현재 위치에서 m 길이만큼 칠함

        // 칠한 구역을 넘어가지 않는 다음 인덱스를 찾음
        while (i < section.size() && section[i] <= paint_end) {
            i++;
        }
    }

    return answer;
}
