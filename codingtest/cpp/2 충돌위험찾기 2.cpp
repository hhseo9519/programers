#include <string>
#include <vector>
#include<map>
using namespace std;
class Robot {
public : 
    int count = 0;
    pair <int, int> location;
    pair<int, int> next;
    void move(map<int,pair<int,int>>map);
    bool reach(map <int,pair<int,int>>map);
    vector<int>destination;
    //�����ڵ� �������ϰ�
private :

};
void Robot::move(map<int,pair<int,int>>map) {
    for (int i = 0; i < abs((map[destination[count]].first - location.first)); i++) {
        if ((map[destination[count]].first - location.first) > 0) {
            location.first++;
        }
        else if ((map[destination[count]].first - location.first) < 0) {
            location.first--;
        }
    }
}
bool Robot::reach(map <int, pair<int,int>>map) {
    if (location.first == map[destination[count]].first && location.second ==
        map[destination[count]].second) {
        this->count++;// �� Ŭ������ count��.
        return true;
    }
    else return false;
    
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    

    
    map<int, pair<int, int>> map;//���� ���� ����Ʈ ��ȣ�� ������ ���� ó�� ��ġ�� Ƣ���
    //���� ���� �״�� �ᵵ �ɰŰ��� ��
    for (int i = 0; i < points.size(); i++) {
        map.insert(make_pair(i + 1, make_pair(points[i][0], points[i][1])));
    }

    


    return answer;
}