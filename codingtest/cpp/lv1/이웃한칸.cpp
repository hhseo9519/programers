#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    //board�� ���簢�� 2���� �����̴�. �Է��� �� ���� �� �ش�.
    //ĭ�� �־��� �� �� ���� �ִ� ĭ�̶�� �߸��� �ε����� �����ϰ�
   // �Ǵ� ��찡 ���� ���� �ֱ� ������ �� �κ��� �����ؼ� ��������

    //swich~case���� ������ �����θ� �񱳰� �����ϱ� ������ �׳� if���� �������
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