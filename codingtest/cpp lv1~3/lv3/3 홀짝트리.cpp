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
    //혼자 있는 애들은 어떻게 할까?
    //map만들어서 0인 애들은 넣어주기

    //내가 속해있는 번호를 알기위한 map
    unordered_map<int, int> where;

    int count = 0;
    for (int i = 0; i < edges.size(); i++) {
        int k = edges[i][0];
        int r = edges[i][1];

        if (where.find(k) == where.end() && where.find(r) == where.end()) {
            where[k] = count;//sorting의 몇번 인덱스에 있는지 업데이트
            where[r] = count;
            count++;
        }
        else if (where.find(k) != where.end() || where.find(r) != where.end()) {
            if (where.find(k) == where.end()) {//k가 처음인 경우->r의 것으로
                where[k] = where[r];
                int index = where[k];
                sorting[index][k].push_back(r);
                sorting[index][r].push_back(k);
            }
            else {//r이 처음인 경우거나 둘다 처음이 아닌 경우-> k의 것으로
                where[r] = where[k];
                int index = where[k];
                sorting[index][k].push_back(r);//sorting의 인덱스 까지 하면 map이 나오고 
                //그다음 [k]까지 하면 vector가 나온다.그래서 push_back
                sorting[index][r].push_back(k);
            }
        }

    }
    for (int i = 0; i < nodes.size(); i++) {
        int alone = nodes[i];
        if (where.find(alone) == where.end()) {
            //혼자 있다는 말이고
            if (alone % 2 == 0) {//짝수라면
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
            if (it->first % 2 == 0) {//노드번호가 짝수라면
                if ((it->second.size() - 1) % 2 == 0) {//자식의 노드의 수가 짝수개라면
                    hol++;//홀짝 노드구나..루트가 아닌경우라고 매번 생각
                }
                else {
                    rhol++;//역홀짝이겠구나
                }

            }
            else {//노드가 홀수번호
                if ((it->second.size() - 1) % 2 != 0) {//자식 수 홀수
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