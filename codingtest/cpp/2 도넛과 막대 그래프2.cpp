#include <string>
#include <vector>
#include<map>
#include<queue>
using namespace std;
int eightring = 0;//8자 모양
int stick = 0;//막대
int ring = 0;//도넛
vector<vector<int>> M(10000000);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    //크기가 1000000이고 기본값 0으로 초기화 되어있는 벡터를 만든다.
    vector<int>in (1000000) ;
    vector<int>out(1000000);

    for (int i = 0; i < edges.size(); i++) {
        in[edges[i][0]] += 1;
        out[edges[i][1]] += 1;
    }
    //들어오는게 0개, 나가는게 2개 이상인 관계없는 점 찾기
    int dot = 0;
    for (int i = 0; i < out.size(); i++) {
        if (in[i] >= 2 && out[i] ==0) {
            dot = i;//문제 없음!!
            break;
        }
    }
    //관계없는 점이 연결된 점 찾기
    vector<int> dotcon;
  
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] == dot) {
            dotcon.push_back(edges[i][1]);
        }
        //간선 정리까지 
        M[edges[i][0]].push_back(edges[i][1]);

    }
   
    //연결된 점들을 통해 그래프 개수 찾기
 
    int count = 0;
    int restart = 0;
    for (int i = 0; i < dotcon.size(); i++) {
        int k = dotcon[i];//관계없는 점과 연결된 그래프 위의 점
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