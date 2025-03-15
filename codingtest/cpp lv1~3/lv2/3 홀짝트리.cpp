#include <string>
#include <vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;
    int num1 = 0;
    int num2 = 0;

    vector<unordered_map<int, vector<int>>>sorting(1000000);
    //ȥ�� �ִ� �ֵ��� ��� �ұ�?
    //map���� 0�� �ֵ��� �־��ֱ�

    //���� �����ִ� ��ȣ�� �˱����� map
    unordered_map<int, int> where;

    int count = 0;
    for (int i = 0; i < edges.size(); i++) {
        int k = edges[i][0];
        int r = edges[i][1];

        if (where.find(k) == where.end() && where.find(r) == where.end()) {
            where[k] = count;//sorting�� ��� �ε����� �ִ��� ������Ʈ
            where[r] = count;
            count++;
        }
        else if (where.find(k) != where.end() || where.find(r) != where.end()) {
            if (where.find(k) == where.end()) {//k�� ó���� ���->r�� ������
                where[k] = where[r];
                int index = where[k];
                sorting[index][k].push_back(r);
                sorting[index][r].push_back(k);
            }
            else {//r�� ó���� ���ų� �Ѵ� ó���� �ƴ� ���-> k�� ������
                where[r] = where[k];
                int index = where[k];
                sorting[index][k].push_back(r);//sorting�� �ε��� ���� �ϸ� map�� ������ 
                //�״��� [k]���� �ϸ� vector�� ���´�.�׷��� push_back
                sorting[index][r].push_back(k);
            }
        }

    }
    for (int i = 0; i < nodes.size(); i++) {
        int alone = nodes[i];
        if (where.find(alone) == where.end()) {
            //ȥ�� �ִٴ� ���̰�
            if (alone % 2 == 0) {//¦�����
                num1++;
            }
        }
    }
    for (int i = 0; i < sorting.size(); i++) {
        if (sorting[i].empty()) {
            break;
        }
        int hol = 0;
        int rhol = 0;
        for (unordered_map<int, vector<int>>::iterator it = sorting[i].begin(); it != sorting[i].end(); it++) {
            if (it->first % 2 == 0) {//����ȣ�� ¦�����
                if ((it->second.size() - 1) % 2 == 0) {//�ڽ��� ����� ���� ¦�������
                    hol++;//Ȧ¦ ��屸��..��Ʈ�� �ƴѰ���� �Ź� ����
                }
                else {
                    rhol++;//��Ȧ¦�̰ڱ���
                }

            }
            else {//��尡 Ȧ����ȣ
                if ((it->second.size() - 1) % 2 != 0) {//�ڽ� �� Ȧ��
                    hol++;
                }
                else {
                    rhol++;
                }
            }

        }
        if (rhol == 1 && hol > 1) {
            num1++;
        }
        else if (hol == 1 && rhol > 1) {
            num2++;
        }
        else if (hol == 1 && rhol == 1) {
            num1++;
            num2++;
        }
    }
    answer.push_back(num1);
    answer.push_back(num2);

    return answer;
}