#include <string>
#include <vector>

using namespace std;

bool posimpos(vector<string> park, string route, pair<int, int> location) {
    string ns = route.substr(0, 1);  //  방향 문자열
    string ns2 = route.substr(2, 1); // 숫자 부분
    int R = stoi(ns2);

    if (ns == "E") {
        if (location.second + R >= park[0].size()) return false;
        for (int i = 1; i <= R; i++) {
            if (park[location.first][location.second + i] == 'X') return false;
        }
    }
    else if (ns == "W") {
        if (location.second - R < 0) return false;
        for (int i = 1; i <= R; i++) {
            if (park[location.first][location.second - i] == 'X') return false;
        }
    }
    else if (ns == "S") {
        if (location.first + R >= park.size()) return false;
        for (int i = 1; i <= R; i++) {
            if (park[location.first + i][location.second] == 'X') return false;
        }
    }
    else if (ns == "N") {
        if (location.first - R < 0) return false;
        for (int i = 1; i <= R; i++) {
            if (park[location.first - i][location.second] == 'X') return false;
        }
    }

    return true;
}

void gogossing(vector<string> park, string route, pair<int, int>& location) {  // 참조 전달
    string ns = route.substr(0, 1);
    string ns2 = route.substr(2, 1);
    int R = stoi(ns2);

    if (ns == "E") location.second += R;
    else if (ns == "W") location.second -= R;
    else if (ns == "S") location.first += R;
    else if (ns == "N") location.first -= R;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> location;

    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S') {
                location = make_pair(i, j);
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        if (posimpos(park, routes[i], location)) {
            gogossing(park, routes[i], location);
        }
    }

    answer.push_back(location.first);
    answer.push_back(location.second);
    return answer;
}
