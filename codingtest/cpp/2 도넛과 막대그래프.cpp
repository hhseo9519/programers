#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void ring() {

}
vector<int> solution(vector<vector<int>> edges) {
	vector<int> answer;
	// ���� ������ ���� ã��. ���� ���� ����
	vector<int> start;
	vector<int> end;
	map<int, int> M;
	vector<int>count;
	//���������� ���������� ���� map�� ����� map�� �������� ������ ���¾ְ� �־�
	//�� ������ ����Ŵϱ�, �������� ���¾ְ� �־� �°� �����̰� �´� ���Ϳ��� ����
	for (int i = 0; i < edges.size(); i++) {
		if (M.find(edges[i][1]) != M.end()) {
			count.push_back(edges[i][1]);//�ڱ����� �����ϴ°� ��������..? �´� ���� �������

		}
		M[edges[i][1]] = edges[i][0];
	}
	//���� ����
	int star = 0;
	int stari = -1;
	for (int i = 0; i < edges.size(); i++) {
		for (int j = 0; j < edges.size(); j++) {
			auto it = M.find(edges[i][0]);
			if (it == M.end()) {
				star = edges[i][0];
				stari = i;
				break;
			}
		}
		edges.erase(edges.begin() + stari); // ���� ����
	}


	// ���� ���� �����ϱ� (���⿣ ������ ���õ� �ֵ��� ����)
	map<int, vector<int>> map;
	for (int i = 0; i < edges.size(); i++) {
		map[edges[i][0]].push_back(edges[i][1]);
	}//insert�� �ٲٸ� �� �ȵǴ���,
	
	 
	 
	 //�� ����
	//count�� 2���� �ֵ��� �� ���־� ��׺��� �����ؼ� ���ƺ���
	int eight_donout = 0;

	for (int i = 0; i < count.size(); i++) {
	
		int startpoint = count[i];
		auto iter = map.find(count[i]);//�� map�� pair (int ,vector)�� ����Ű�� �κ�
		//���Ⱑ ��� �Լ��κ�(������ �� �κ� ���ֱ�)
		while ((iter->second).begin() == (iter->second).end()) {
			if (i == 0) {
				startpoint = count[i];
				auto iter = map.find(count[i]);
				int restartpoint = *(iter->second).begin(); ///�̺κ��� �ٽ� ����..........�� ���̾���
				(iter->second).erase((iter->second).begin());

			}
			else {
				startpoint = *(iter->second).begin();
				auto iter = map.find(startpoint);
				int restartpoint = *(iter->second).begin(); ///�̺κ��� �ٽ� ����..........�� ���̾���
				(iter->second).erase((iter->second).begin());
			}
			
		}
	}

	//�߸��ƴ�. ����map�� �׷���ó�� �������� �ʳ� map�ȿ� vector�� �־����� ������.
	//������ ���� ����. �ֳĸ� map[edges[i][0]][edges[i][0]] = edges[i][1];���⼭ �������� ����
	//[i][0]�� �ٽ� �ִ°� ���� �ǹ̰� ����.

	return answer;
}


for (int i = 0; i < dotcon.size(); i++) {
	int k = dotcon[i];//������� ���� ����� �׷��� ���� ��
	int point = dotcon[i];
	count = 0;

	while (true) {
		if (M[k].size() >= 2) {
			eightring += 1;
			break;
		}
		else if (M[k].size() == 1) {
			int next = M[k][0];
			M[k].erase(M[k].begin());
			k = next;
		}
		else if (M[k].size() == 0) {
			if (k == point) {
				ring += 1;
				break;
			}
			else if (k != point) {
				stick += 1;
				break;
			}
		}

	}

}

void check(int start) {//start�� ������� ���� ����� �׷��� ���� ��
	queue <int> q;
	q.push(start);
	bool isvisited = false;//..?
	while (!q.empty()) {//empty�� ��������� true, �Ⱥ������ �� false�ϱ� !�� �ϱ�
		int now = q.front();
		q.pop();
		if (now == start && isvisited) {
			ring++;
			return;
		}
		if (M[now].size() >= 2) {
			eightring++;
			return;
		}
		for (int i = 0; i < M[now].size(); i++) {
			q.push(M[now][i]);
		}

	}
}