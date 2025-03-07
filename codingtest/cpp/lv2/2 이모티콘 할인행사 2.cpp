#include <string>
#include <vector>
using namespace std;

int dis[4] = { 40,30,20,10 };//������
vector<pair<int, int>> price(7, { 0,0 });//���ε� ����, ������
vector<int> answer(2, 0);

void    dfs(int cnt, int n, vector<vector<int>> users, vector<int> emoticons)
{
    if (cnt == n)// �̸�Ƽ�ܿ� ���� ���ΰ��� �������� �� �������� ��
    {
        int plus = 0, sum = 0;
        for (int i = 0; i < users.size(); i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (users[i][0] <= price[j].second) tmp += price[j].first;//���ϴ� �������̻��̸� ���Ű�++
            if (tmp >= users[i][1]) plus++;//���Ű��� ������ �� �̻��̸�
            else sum += tmp;//����++
        }
        if (plus > answer[0])//�����ڼ��� �� ������ 
        {
            answer[0] = plus;
            answer[1] = sum;
        }
        else if (plus == answer[0] && sum >= answer[1]) answer[1] = sum;// �����ڼ��� ���� ������ ũ��
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        price[cnt].first = (100 - dis[i]) * emoticons[cnt] / 100;//���ε� ����
        price[cnt].second = dis[i];//������
        dfs(cnt + 1, n, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    dfs(0, emoticons.size(), users, emoticons);
    return answer;
}