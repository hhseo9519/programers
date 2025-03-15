#include <string>
#include <vector>
#include<algorithm>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> deliv = deliveries;
    vector <int> pick = pickups;
    int truck = cap;//시작전에 가득 채워
    int memdv= n-1;//일단 제일 먼 곳으로 저장해놔
    int mempk = n-1;
    int dv = 0;
    int pk = 0;
    for (int i = 0; i < n; i++) {
        if (deliveries[i] != 0) {
            dv = i;//dv는 제일 가까운 곳
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pickups[i] != 0) {
            pk = i;//pk도 제일 가까운 곳
            break;
        }
    }
    
    //배달 시작
    while (mempk >= pk || memdv >=dv ) {//앞으로 현재 상태가 둘다 값보다 작아지면 종료
        //그 값이랑 같을 때는 한번 더 다녀올 수도 있으니까.
        truck = cap;
        //배달부터
        while (truck != 0&&memdv!=-1) {//다 내려놓을 때까지 즉 truck이 0 이면 종료해 
            //그리고 -1이면 종료해
            if (deliveries[memdv] <= truck) {
                truck-= deliveries[memdv];
                memdv -= 1;
                if (memdv == dv-1) break;
            }
            else if (deliveries[memdv] > truck) {
                
                deliveries[memdv] -= truck;
                truck = 0;
            }
        }
        //수거하기
        truck = cap;
        while (truck != 0&&mempk!=-1) {//다 내려놓을 때까지
            if (pickups[mempk] <= truck) {
                truck -= pickups[mempk];
                mempk -= 1;
                if (mempk == pk-1) break;//이 while 문을 계속 돌까봐 그런거다
            }
            else if (pickups[mempk] > truck) {
             
                pickups[mempk] -= truck;
                truck = 0;
            }
        }
        int big = max(mempk, memdv);
        if (big < 0) big = 0;
        answer += (2 * (big + 1));

    }
    //memdv하고 mempk중에 더 큰걸 answer에 집어넣기


    return answer;
}