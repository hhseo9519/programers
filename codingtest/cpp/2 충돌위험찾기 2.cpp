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
    //생성자도 만들어야하고
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
        this->count++;// 이 클래스의 count다.
        return true;
    }
    else return false;
    
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    

    
    map<int, pair<int, int>> map;//이제 여긴 포인트 번호를 누르면 값이 처음 위치가 튀어나옴
    //물론 벡터 그대로 써도 될거같긴 함
    for (int i = 0; i < points.size(); i++) {
        map.insert(make_pair(i + 1, make_pair(points[i][0], points[i][1])));
    }

    


    return answer;
}