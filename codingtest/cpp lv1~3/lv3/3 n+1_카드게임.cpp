#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    int chance = coin;
    int originx = n / 3;
    vector<int>cor(cards.begin(), cards.begin() + n / 3 - 1);//�� ���� ī��
    sort(cor.begin(), cor.end());
    int count = 0;
    int estate = 0;
    int target = n + 1
        for (int j = cor.size() - 1; j < cor.size() / 2; j--) {
            if (cor[count] + cor[j] == target) {
                estate++;
                count++;
                j = cor.size();
            }
        }
    vector<int>newcoin(cards.begin() + n / 3, cards.begin() + n / 3 + coin + estate);//���� ����� �� �� �ִ� ��,,���⿡ ��� �߰��� ����


    return answer;
}