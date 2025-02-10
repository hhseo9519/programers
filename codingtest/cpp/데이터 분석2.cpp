#include <string>
#include <vector>
#include<map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    /*data들을 처음에 
    1. ext로 확인해서 추출하고  
    2. sort_by를 기준으로 오름차순 정렬하면 된다*/

//1. 정렬기준에 해당하는 값이 서로 같은 경우는 없기 때문에 map의 key에 넣으면 좋겠다
    int size = data.size();
    map<int, int>m;
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
        what2 = 0;
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
    for (int i = 0; i < size; i++) {
        if (data[i][what] < val_ext) {
            m.insert(make_pair(data[i][what2],i));
        }
    }//알아서 key에 맞게 정렬 됌.
    for (auto k : m) {
        answer.push_back(data[k.second]);
    }
     return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> name_to_idx;
    name_to_idx["code"] = 0;
    name_to_idx["date"] = 1;
    name_to_idx["maximum"] = 2;
    name_to_idx["remain"] = 3;
    /*auto를 통해 타입을 지정하기 좋게 만듦,, 
    
   */
    auto it = remove_if(data.begin(), data.end(), [idx = name_to_idx[ext], val_ext](const auto& row) {
        return !(row[idx] < val_ext);
        });
    
    data.erase(it, data.end());
    //it부터 data.end()까지 모두 지우는데 저 it는 위의 remove _if에서 반환 한 반복자이고
    //반복자는 '새로운 끝'을 반환하는데 뒤로 보내버린 요소들 중 첫번째 요소를 가리키는
    //반복자를 말한다. 그래서 it부터 끝까지 지우게 된다.

    //
    sort(data.begin(), data.end(), [idx = name_to_idx[sort_by]](const auto& row1, const auto& row2) {
        return row1[idx] < row2[idx];
        });
    //위에 []부분에 외부변수를 캡쳐해서 가져오는 역할을 하는 식을 썼고, parameter에는 row를넣었다
    //parameter는 말 그대로 매개변수 이므로, 외부의 값에 대해 직접 접근하거나 할수가 없다. 그저
    //외부에서 가져온 식을 함수내부에서 매개변수로 받아서 사용하는 역할을 하는 것이다. 
    //그렇기 때문에,외부 변수를 그대로 가져오려면 파라미터에 참조를 해야하는데, 그렇게 하는 것보다
    //만들어 놓은 capture 도구를 사용하는게  좋지 않겠는가? 그리고 도구를 만들어 놓았기 때문에
    //람다식의 매개변수 부분은 외부 값을 참조하는 것이 불가능 하다.

    //int를 반환하는 람다식도 가능하다
       // `int`를 반환하는 람다식
    auto add = [](int a, int b) -> int { return a + b; };

    std::cout << add(3, 4) << std::endl;  // 출력: 7
    return 0;
    return data;
}
