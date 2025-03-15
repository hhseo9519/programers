#include <string>
#include <vector>
#include<map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    /*data���� ó���� 
    1. ext�� Ȯ���ؼ� �����ϰ�  
    2. sort_by�� �������� �������� �����ϸ� �ȴ�*/

//1. ���ı��ؿ� �ش��ϴ� ���� ���� ���� ���� ���� ������ map�� key�� ������ ���ڴ�
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

    //switch�����ε� �ѹ� �� �ۼ��غ���//string�� switch������ �ۼ� �� �� ����
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
    }//�˾Ƽ� key�� �°� ���� ��.
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
    /*auto�� ���� Ÿ���� �����ϱ� ���� ����,, 
    
   */
    auto it = remove_if(data.begin(), data.end(), [idx = name_to_idx[ext], val_ext](const auto& row) {
        return !(row[idx] < val_ext);
        });
    
    data.erase(it, data.end());
    //it���� data.end()���� ��� ����µ� �� it�� ���� remove _if���� ��ȯ �� �ݺ����̰�
    //�ݺ��ڴ� '���ο� ��'�� ��ȯ�ϴµ� �ڷ� �������� ��ҵ� �� ù��° ��Ҹ� ����Ű��
    //�ݺ��ڸ� ���Ѵ�. �׷��� it���� ������ ����� �ȴ�.

    //
    sort(data.begin(), data.end(), [idx = name_to_idx[sort_by]](const auto& row1, const auto& row2) {
        return row1[idx] < row2[idx];
        });
    //���� []�κп� �ܺκ����� ĸ���ؼ� �������� ������ �ϴ� ���� ���, parameter���� row���־���
    //parameter�� �� �״�� �Ű����� �̹Ƿ�, �ܺ��� ���� ���� ���� �����ϰų� �Ҽ��� ����. ����
    //�ܺο��� ������ ���� �Լ����ο��� �Ű������� �޾Ƽ� ����ϴ� ������ �ϴ� ���̴�. 
    //�׷��� ������,�ܺ� ������ �״�� ���������� �Ķ���Ϳ� ������ �ؾ��ϴµ�, �׷��� �ϴ� �ͺ���
    //����� ���� capture ������ ����ϴ°�  ���� �ʰڴ°�? �׸��� ������ ����� ���ұ� ������
    //���ٽ��� �Ű����� �κ��� �ܺ� ���� �����ϴ� ���� �Ұ��� �ϴ�.

    //int�� ��ȯ�ϴ� ���ٽĵ� �����ϴ�
       // `int`�� ��ȯ�ϴ� ���ٽ�
    auto add = [](int a, int b) -> int { return a + b; };

    std::cout << add(3, 4) << std::endl;  // ���: 7
    return 0;
    return data;
}
