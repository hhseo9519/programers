#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int memdv = n-1;//인덱스로 바꿈
    int mempk = n-1;
    int pk;
    int dv;
    while (memdv >= 0 || mempk >= 0) {
        int truck = cap;
        pk = -1;
        dv = -1;
        int count = 0;
        while (truck != 0) {
            if (memdv == -1) { 
                break; }
            if (deliveries[memdv] <= truck) {
                if (deliveries[memdv] != 0) {
                    count++;
                    if (count == 1) {
                        dv = memdv;//이 과정에서 저장이 한번 되는게 문제야 실제로 deliveries가 0인데도
                    }
                }
                
                truck -= deliveries[memdv];
                memdv--;//처리했으니까 인덱스 줄여
            }
            else if (deliveries[memdv] > truck) {
                if (deliveries[memdv] != 0) {
                    count++;
                    if (count == 1) {
                        dv = memdv;
                    }
                }
               
                deliveries[memdv] -= truck;
                truck = 0;
                break;
            }
        }
        truck = cap;
        count = 0;
        while (truck != 0) {
            if (mempk == -1) { break; }
            if (pickups[mempk] <= truck) {
                if (pickups[mempk] != 0) {
                    count++;
                    if (count == 1) {
                        pk = mempk;
                    }
                }
                truck -= pickups[mempk];
                mempk--;
            }
            else if (pickups[mempk] > truck) {
                if (pickups[mempk] != 0) {
                    count++;
                    if (count == 1) {
                        pk = mempk;
                    }
                }
                pickups[mempk] -= truck;
                truck = 0;
                break;
            }
        }
        int big = max(pk, dv);
        answer += 2 * (big + 1);

    }




    return answer;
}