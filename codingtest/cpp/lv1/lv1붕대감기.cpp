#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; //answer는 앞으로 현재체력을 나타낼것
    int count = 0;
    int event = 0;//공격받은 시간을 나타냄
    int recovery = 0;
    int Q = attacks.back()[0];
    /*bandage[0]=사전시간 t
      bandage[1]=초당회복량 x
      bandage[2]=추가 회복량 y    */
    for (int i = 0; i <= Q; i++) {
        if (i == attacks[count][0]) {
            
            recovery = (i - event - 1) * bandage[1] + ((i - event - 1) / bandage[0]) * bandage[2];
                
            answer += recovery;
            //최대체력 넘으면 그냥 최대체력으로 다시 복원
            if (answer > health) {
                answer = health;
            }
            //event공격받기
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