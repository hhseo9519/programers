#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int,int>> answer;//�� �ؼ� 11�� �Ǹ� ���⿡�ٰ� ������Ʈ�� ��� �ҰŴ� 
//�׷��ٰ� �������� ȭ�� ���� ����ؼ� ������ ��
vector<int>apch(11, 0);
int score = -1;
int ctar = 0;
//Ž���ÿ� �̹� ȭ���� ������ n ����  �Ѿ�ٸ� �׸�Ž������
//ȭ���� ������ �Ű澲�� �ɵ�
//ȭ���� ���� = countarr�� ����
// vector<int>ans�� ���� ���ݱ��� ���� ������ üũ�ϴ� ��
//cnt�� �̹��� ������ ���� �����ϴ� ����  cnt=0�϶��� 10�� ����, cnt=1�̶�� 9�� ������ ����
void dfs(vector<vector<int>>rioncanwin,int apch_sco, int countarr, int n, int cnt,
	vector<pair<int, int>>ans) {
	if (countarr > n) {//���̾��� ȭ�� ���� ������ �׸� Ž��
		return;
	}
	if (cnt == 11) {//���⿡���� score������
		int temp = 0;
		for (int i = 0; i < ans.size(); i++) {
			temp += ans[i].first;
		}
		if (temp > score && temp > apch_sco) {
			score = temp;
			ctar = countarr;

			
			answer.clear();
			answer = ans;
		
		}
		return;
		//�̶��� �������� dfs �ٽ� �Ⱥθ��� return �ؾ���
	}
	//�� �κ��� ���ȣ���� ���� dfsŽ���� �ϴ� �ڵ�
	for (int i = 0; i < 2; i++) {
		if (i == 0) {//�ȳֱ�

		}
		else if (i == 1) {//�ֱ�
			countarr += rioncanwin[cnt][1];// �ι�°�� Ȱ ����
			if (apch[cnt] == 1) {
				ans.push_back(make_pair((10 - i) * 2, cnt));
				countarr += rioncanwin[cnt][1];
			}
			else if (apch[cnt] == 0) {
				ans.push_back(make_pair(10 - i, cnt));
				countarr += rioncanwin[cnt][1];
			}

		}
		dfs(rioncanwin,apch_sco, countarr, n, cnt + 1, ans);//cnt�� ó������ 0���� �����ϰ���
	}

}
vector<int> solution(int n, vector<int> info) {

	//����ġ�� ����
	float apch_sco = 0;//c++������ �ǿ������� �ϳ��� float�̶�� float�� �ȴ�.
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) {
			apch_sco += 10 - i;
			apch[i] = 1;
		}
	}
	// vector<vector<int>> rioncanwin(11, {2,0});//vector<vector<int>> rioncanwin(11, {2, 0});�� 11���� ���� ���� ���͸� �������� �� �࿡ {2, 0} ���� ���Ե� ���͸� �ִ� ����Դϴ�.
	vector<vector<int>>rioncanwin(11, vector<int>(2, 0));//����-->>Ȱ ���� ����
	for (int i = 0; i < info.size(); i++) {
		if (info[i] > 0) {//����ġ�� ���缭 ����ġ���� �ϳ� �� ���� �Դ� ����
			rioncanwin[i][0] = 10 - i;
			rioncanwin[i][1] = info[i] + 1;
		}
		else {//�ѹ� ��� ���� �� �ִ� ����
			rioncanwin[i][0] = 10 - i;
			rioncanwin[i][1] = 1;
		}
	}
	//���⼭ ���� rioncanwin�� ���� Ž������
	vector<pair<int, int>>ans;
	dfs(rioncanwin, apch_sco, 0, n, 0, ans);
	vector<int>answers(11, 0);
	//answer�� �� ������� ������ cnt�� �������
	for (pair<int, int> abcd : answer) {
		answers[10-(abcd.second)] = info[abcd.second] + 1;
	}



	return answers;
}