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
    //-1�� ã���� ������ �� ���� �� �� �� ��ĭ��ŭ �Ʒ��� ��ĭ �����ͼ� �� Ȯ��

    for (int mat : mats) {
        for (int i = 0; i < park.size() ;i++) {//��
            for (int j = 0; j < park[0].size(); j++) {//��
                if (matcheckout(park, i, j, mat)) {
                    return mat;
                }
            }
        }
    }


    return -1;
}
//dp �˰������� Ǯ���
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// maxVal ������ ���� ū ���� ã�� �Լ�
int findLargestBelowMax(const vector<int>& vec, int maxVal) {
    int largest = -1;  // �ʱⰪ�� -1�� ����
    for (int num : vec) {
        if (num <= maxVal && num > largest) {  // maxVal ������ ���� ū ��
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

    // ù ��� ù ���� �� �ʱ�ȭ
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // ù ���̳� ù ���� ������ ���簢�� ũ��� 1
                } else {
                    // �ּҰ��� 1�� ���Ͽ� ���� ��ġ������ ���簢�� �� ���̸� ����
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    //dp[-1][0]�� ������ ���ɼ��� ���� �̰� ����� �˾Ƶ���
                }
                // �ִ� ���簢�� �� ���� ����
                max_square_side = max(max_square_side, dp[i][j]);
            }
        }
    }

    // ���� ū ���簢�� ���� ���̿� �´� ��Ʈ ũ�� ����
    return findLargestBelowMax(mats, max_square_side);
}