#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool matcheckout(vector<vector<string>> park, int x, int y,int size) {
    if (x + size > park.size() || y + size > park[0].size()) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (park[x+i][y+j] != "-1") {
                return false;
            }
        }
    }
    return true;
}
int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    sort(mats.rbegin(), mats.rend());
    //-1을 찾으면 옆으로 쭉 가고 그 맨 위 한칸만큼 아래로 한칸 내려와서 쭉 확인

    for (int mat : mats) {
        for (int i = 0; i < park.size() ;i++) {//행
            for (int j = 0; j < park[0].size(); j++) {//열
                if (matcheckout(park, i, j, mat)) {
                    return mat;
                }
            }
        }
    }


    return -1;
}
//dp 알고리즘으로 풀어보기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// maxVal 이하의 가장 큰 값을 찾는 함수
int findLargestBelowMax(const vector<int>& vec, int maxVal) {
    int largest = -1;  // 초기값을 -1로 설정
    for (int num : vec) {
        if (num <= maxVal && num > largest) {  // maxVal 이하의 가장 큰 값
            largest = num;
        }
    }
    return largest;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int height = park.size();
    int width = park[0].size();

    vector<vector<int>> dp(height, vector<int>(width, 0));
    int max_square_side = 0;

    // 첫 행과 첫 열의 값 초기화
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // 첫 행이나 첫 열에 있으면 정사각형 크기는 1
                } else {
                    // 최소값에 1을 더하여 현재 위치까지의 정사각형 변 길이를 저장
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    //dp[-1][0]에 접근할 가능성이 있음 이건 참고로 알아두자
                }
                // 최대 정사각형 변 길이 갱신
                max_square_side = max(max_square_side, dp[i][j]);
            }
        }
    }

    // 가장 큰 정사각형 변의 길이에 맞는 매트 크기 선택
    return findLargestBelowMax(mats, max_square_side);
}