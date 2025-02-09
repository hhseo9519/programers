#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    //board는 정사각형 2차원 벡터이다. 입력은 각 행을 쭉 준다.
    //칸이 주어질 때 맨 끝에 있는 칸이라면 잘못된 인덱스에 접근하게
   // 되는 경우가 생길 수도 있기 때문에 그 부분을 조심해서 생각하자

    //swich~case문은 정해진 값으로만 비교가 가능하기 때문에 그냥 if문을 사용하자
    int n = board.size();
    int dh[4] = { 0,1,-1,0 };
    int dw[4] = { 1,0,0,-1 };

    for (int i = 0; i <4; i++) {
        if (h + dh[i] >= 0 && h + dh[i] < n && w + dw[i] >= 0 && w + dw[i] < n) {
            if (board[h][w] == board[h + dh[i]][w + dw[i]]) {
                answer++;
            }
        }
    }


    return answer;
}