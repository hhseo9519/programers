#include<vector>
#include<map>
#include<string>
#include<set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
#include<iterator>//next �Լ��� ����
using namespace std;

/// <summary>
/// auto last = next(iter,3) -> 3��ŭ �� �� iterator�� ���Ѵ�.
/// next��� �ؼ� �ϳ��� �� ���Ÿ� iter = ++iter;�̷������� ����,,�� �������� �ؾ��� ��������
/// begin(), end(), rbegin(), rend() find()�� ���� iterator�� ��ȯ
/// string�� find�� iterator��ȯ ���� �˰����� find�Լ�(vector,list)���õ�
/// iterator�� ��ȯ�Ѵ�.
/// </summary>

int main() {
	//1. vector

	vector<int>vec;


	vector<int>vec2(5, 0);//5���� ĭ�� ����� ��� 0���� �ʱ�ȭ

	vector<vector<int>>vec3(5, vector<int>(5, 0));//5X5 �迭�� ����� �� ���� 0���� �ʱ�ȭ

	int frovec = vec.front();//ù��° ���Ҹ� ��ȯ.. �ٵ� ���� �̷��ʿ䰡?

	int bacvec = vec.back();
	//int whatIs = vec.find(3); vectorŬ���� ���ο��� find�Լ��� �������� ����
	//�׷��� ������ algorithm�� find �Լ��� ����ؾ� ��

	auto whatIS = find(vec.begin(), vec.end(), 8);//ã���� iterator ��ȯ
	//�⺻������ find�Լ��� iterator�� ��ȯ�Ѵ� string������ index�� ��ȯ
	//���� ã�� ���ϸ� vec.end()�� ��ȯ
	//�ٵ� �̰͵� �� �ڿ��� ��ĭ �� �ִ� �װŰ���? �翬��? ���� �׷���!!

	//���� �̷��� �հ� �ڸ� ��ȸ�� �ʿ� ���� 
	//vec[0], vec[vec.size()_1]�� �ϸ� ��
	int baccc = vec[vec.size() - 1];
