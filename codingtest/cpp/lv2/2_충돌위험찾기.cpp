#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    //�κ����� ���ÿ� ���� ��ǥ�� �ִ� ����� ���� ���� �߰��϶�
    //�������� ���� �� ���� ī��Ʈ
    //�ٸ�����Ʈ�� ��ο� �־ �׳� ������
    //����Ʈ���� ����Ʈ�� ���� �����̵� �� ���� �¿��̵�
    //�ֵ��� ��ġ�� ���� Ŭ������ ���� ��ü�� ������ ����, pair�� ������� ��,���� ��ǥ�� �������
    //route�� ������ŭ pair���Ͱ� ä��������
    
    vector<pair<int, int>> location;
    map<int, pair<int, int>> map;//���� ���� ����Ʈ ��ȣ�� ������ ���� ó�� ��ġ�� Ƣ���
    //���� ���� �״�� �ᵵ �ɰŰ��� ��
    for (int i = 0; i < points.size(); i++) {
        map.insert(make_pair(i + 1, make_pair(points[i][0], points[i][1])));
    }

    for (int i = 0; i < routes.size(); i++){ //route�� �ִ� �ڱ� �ε����� �κ��� ��ȣ--> ���� �ε��� pair�� �ִ� �ڱ� location
        int loc = routes[i][0];
        location.push_back(map[loc]);
    }
   //������� �ϸ� �ʱ���ġ ��;


    return answer;
}