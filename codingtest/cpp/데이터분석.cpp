#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;  // second ���� �������� �������� ����
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

    //switch�����ε� �ѹ� �� �ۼ��غ���//string�� switch������ �ۼ� �� �� ����
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
        //�̷��� �ϸ� ū �ֵ��� �ε����� �� ������. �� ������ �� �ε����� 
        //�ִ� �ֵ� ������� for������ ������ Ȯ���ϸ� �ȴ�.
        if (data[i][what] < val_ext) {
            pairs = make_pair(i, data[i][what2]);
            extracted.push_back(pairs);
        }
        //code������� �� ������ �ִ�.
    }
    //map�� ����ؼ� key�� value�� �ؼ� ������ �ؾ��ϳ����� �̰� �ڵ�� �ϴ°Ŵϱ�,,

    //�����ϴ� ��� �� ����...��� �ٸ� �������� ����//�� ���� �̷��� �߾�� �ϳ�
  


    //c++���� main�Լ� ���ο� �ٸ� ����� �Լ��� ������� �ʴ´�.
   
    sort(extracted.begin(), extracted.end(), comparePairs);

    for (int i = 0; i < size;i++) {
        if (data[i][0] == extracted[i].first) {
            answer.push_back(data[i]);
        }
    }




    return answer;
}
