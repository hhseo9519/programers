#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    //로봇끼리 동시에 같은 좌표에 있는 경우의 수를 세서 추가하라
    //마지막에 도착 할 때도 카운트
    //다른포인트가 경로에 있어도 그냥 지나가
    //포인트에서 포인트로 갈때 수직이동 다 한후 좌우이동
    //애들의 위치를 굳이 클래스를 통한 객체로 만들지 말고, pair에 순서대로 행,열의 좌표를 집어넣자
    //route의 개수만큼 pair벡터가 채워지겠지
    
    vector<pair<int, int>> location;
    map<int, pair<int, int>> map;//이제 여긴 포인트 번호를 누르면 값이 처음 위치가 튀어나옴
    //물론 벡터 그대로 써도 될거같긴 함
    for (int i = 0; i < points.size(); i++) {
        map.insert(make_pair(i + 1, make_pair(points[i][0], points[i][1])));
    }

    for (int i = 0; i < routes.size(); i++){ //route에 있는 자기 인덱스가 로봇의 번호--> 같은 인덱스 pair에 있는 자기 location
        int loc = routes[i][0];
        location.push_back(map[loc]);
    }
   //여기까지 하면 초기위치 끝;


    return answer;
}