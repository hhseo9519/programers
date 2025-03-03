#include <string>
#include <vector>

using namespace std;
//���� ���ϴ� ����
vector<int>answer(11, 0);
int score = -1;

void dfs(int cnt, int n,int cc, int apch_sco, vector<pair<int, int>> rion, vector<pair<int, int>>& realscore, vector<int> info) {
	if (cc > n) {//�̹� ȭ���� �Ѿ �� ��� �׸�Ž��
		return;
	}

	if (cnt == rion.size()) {//�̶� ���ϸ� �ǰ�
		int temp = 0;
		int count = 0;
		for (int i = 0; i < realscore.size(); i++) {
			count += realscore[i].second;
		}
		if (count >= n) {//n�� �̻� ��� �ȴٸ� out!!
			return;
		}
		for (int i = 0; i < realscore.size(); i++) {
			temp += (realscore[i].first);
		}
		if (temp > score && temp > apch_sco) {
			score = temp;
			int k = 0;
			vector<int>answer(11);// �ٽ� �����ϸ� �ʱ�ȭ �ȴ�.
			//���� �� ����
			for (int i = 0; i < answer.size(); i++) {
				answer[i] = realscore[i].second;
			}

			if (count < n) {
				answer[10] += (n - count);
			}
		}
	}
	pair<int, int> prev = realscore[cnt];
	for (int i = 0; i < 2; i++) {
		if (i == 1 && rion[cnt].second == 1) {
			realscore[cnt] = make_pair(rion[cnt].first, rion[cnt].second);//���� �״��� ȭ�� ��
			cc += rion[cnt].second;
		}
		if (i == 1 && rion[i].second > 1) {
			realscore[cnt] = make_pair((rion[cnt].first) * 2, rion[cnt].second);//����ġ ������ ���ְ� ���� �Դ°Ŵϱ�.
			cc += rion[cnt].second;
		}
		dfs(cnt + 1, n,cc, apch_sco, rion, realscore, info);
		realscore[cnt] = prev;  // ��Ʈ��ŷ: ���� ������ ����
	}
}

vector<int> solution(int n, vector<int> info) {

	int apch_sco = 0;//����ġ ����
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) apch_sco += 10 - i;
	}

	vector<pair<int, int>> rion;//���̾��� ���� �� �ִ� ������ �׿� �´� �����ϴ� ȭ�� �� ������ ǥ

	for (int i = 0; i < info.size(); i++) {
		if (info[i] != 0) {
			rion.push_back(make_pair(10 - i, info[i] + 1));//����, ȭ�� �� --> rion�� ������ ������
		}
		else {
			rion.push_back(make_pair(10 - i, 1));
		}
	}
	//ȭ���� ���� ��� 0�߿� �� ����
	//���� rion���� rion�� �����ϴ� ȭ���� ������ ����ִ�
	vector<pair<int, int>>realscore(rion.size());//���� ���� ��� ����
	dfs(0, n,0, apch_sco, rion, realscore, info);


	return answer;
}