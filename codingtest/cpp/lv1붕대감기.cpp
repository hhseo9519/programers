#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; //answer�� ������ ����ü���� ��Ÿ����
    int count = 0;
    int event = 0;//���ݹ��� �ð��� ��Ÿ��
    int recovery = 0;
    int Q = attacks.back()[0];
    /*bandage[0]=�����ð� t
      bandage[1]=�ʴ�ȸ���� x
      bandage[2]=�߰� ȸ���� y    */
    for (int i = 0; i <= Q; i++) {
        if (i == attacks[count][0]) {
            
            recovery = (i - event - 1) * bandage[1] + ((i - event - 1) / bandage[0]) * bandage[2];
                
            answer += recovery;
            //�ִ�ü�� ������ �׳� �ִ�ü������ �ٽ� ����
            if (answer > health) {
                answer = health;
            }
            //event���ݹޱ�
            answer -= attacks[count][1];
            if (answer <= 0) {
                return -1;
            }
            count++;
            event = i;


        }
    }
   
    return answer;
}