#include <string>
#include <vector>
#include<algorithm>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> deliv = deliveries;
    vector <int> pick = pickups;
    int truck = cap;//�������� ���� ä��
    int memdv= n-1;//�ϴ� ���� �� ������ �����س�
    int mempk = n-1;
    int dv = 0;
    int pk = 0;
    for (int i = 0; i < n; i++) {
        if (deliveries[i] != 0) {
            dv = i;//dv�� ���� ����� ��
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pickups[i] != 0) {
            pk = i;//pk�� ���� ����� ��
            break;
        }
    }
    
    //��� ����
    while (mempk >= pk || memdv >=dv ) {//������ ���� ���°� �Ѵ� ������ �۾����� ����
        //�� ���̶� ���� ���� �ѹ� �� �ٳ�� ���� �����ϱ�.
        truck = cap;
        //��޺���
        while (truck != 0&&memdv!=-1) {//�� �������� ������ �� truck�� 0 �̸� ������ 
            //�׸��� -1�̸� ������
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
        //�����ϱ�
        truck = cap;
        while (truck != 0&&mempk!=-1) {//�� �������� ������
            if (pickups[mempk] <= truck) {
                truck -= pickups[mempk];
                mempk -= 1;
                if (mempk == pk-1) break;//�� while ���� ��� ����� �׷��Ŵ�
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
    //memdv�ϰ� mempk�߿� �� ū�� answer�� ����ֱ�


    return answer;
}