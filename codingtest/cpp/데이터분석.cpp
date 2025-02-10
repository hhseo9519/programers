#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;  // second 값을 기준으로 오름차순 정렬
}
vector<vector<int>> solution(vector<vector<int>> data, 
    string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    vector<pair<int,int>>extracted;

    int size = data.size();

    int what = 0;

    if (ext == "code") {
        what = 0;
    }
    else if (ext == "date") {
        what = 1;
    }
    else if (ext == "maximum") {
        what = 2;
    }
    else {
        what = 3;
    }

    //switch문으로도 한번 더 작성해보자//string은 switch문으로 작성 할 수 없음
    int what2 = 0;
    if (sort_by == "code") {
        what2= 0;
    }
    else if (sort_by == "date") {
        what2 = 1;
    }
    else if (sort_by == "maximum") {
        what2 = 2;
    }
    else {
        what2 = 3;
    }
    pair<int, int>pairs;
    for (int i = 0; i < size; i++) {
        //이렇게 하면 큰 애들의 인덱스가 다 들어가진다. 이 다음에 이 인덱스에 
        //있는 애들 범위기반 for문으로 돌려서 확인하면 된다.
        if (data[i][what] < val_ext) {
            pairs = make_pair(i, data[i][what2]);
            extracted.push_back(pairs);
        }
        //code순서대로 쭉 들어가져ㅁ 있다.
    }
    //map을 사용해서 key와 value로 해서 정렬을 해야하나보다 이거 코드로 하는거니까,,

    //정렬하는 방법 쉘 정렬...등등 다른 여러가지 정렬//퀵 정렬 이런걸 했어야 하나
  


    //c++에서 main함수 내부에 다른 선언된 함수를 허용하지 않는다.
   
    sort(extracted.begin(), extracted.end(), comparePairs);

    for (int i = 0; i < size;i++) {
        if (data[i][0] == extracted[i].first) {
            answer.push_back(data[i]);
        }
    }




    return answer;
}
