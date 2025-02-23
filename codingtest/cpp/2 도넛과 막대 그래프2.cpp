#include <string>
#include <vector>
#include<map>
#include<queue>
using namespace std;
int eightring = 0;//8�� ���
int stick = 0;//����
int ring = 0;//����
vector<vector<int>> M(10000000);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    //ũ�Ⱑ 1000000�̰� �⺻�� 0���� �ʱ�ȭ �Ǿ��ִ� ���͸� �����.
    vector<int>in (1000000) ;
    vector<int>out(1000000);

    for (int i = 0; i < edges.size(); i++) {
        in[edges[i][0]] += 1;
        out[edges[i][1]] += 1;
    }
    //�����°� 0��, �����°� 2�� �̻��� ������� �� ã��
    int dot = 0;
    for (int i = 0; i < out.size(); i++) {
        if (in[i] >= 2 && out[i] ==0) {
            dot = i;//���� ����!!
            break;
        }
    }
    //������� ���� ����� �� ã��
    vector<int> dotcon;
  
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] == dot) {
            dotcon.push_back(edges[i][1]);
        }
        //���� �������� 
        M[edges[i][0]].push_back(edges[i][1]);

    }
   
    //����� ������ ���� �׷��� ���� ã��
 
    int count = 0;
    int restart = 0;
    for (int i = 0; i < dotcon.size(); i++) {
        int k = dotcon[i];//������� ���� ����� �׷��� ���� ��
        int point = dotcon[i];
        count = 0;
        vector<int> visited(1000000);

        while (true) {
            if (M[k].size() >= 2) {
                eightring += 1;
                break;
            }
            else if (M[k].size() == 1) {
                visited[k] = 99;
                int next = M[k][0];
                M[k].erase(M[k].begin());
                k = next;
                

            }
            else if (M[k].size() == 0) {
                if (k == point&&visited[k]!=0) {
                    ring += 1;
                    break;
                }
                else if (k != point) {
                    stick += 1;
                    break;
                }
            }

        }

    }

   
    answer.push_back(dot);
    answer.push_back(ring);
    answer.push_back(stick);
    answer.push_back(eightring);
    return answer;
}