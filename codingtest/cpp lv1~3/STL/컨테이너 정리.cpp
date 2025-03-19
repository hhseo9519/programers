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
	
	int frovec=vec.front();//ù��° ���Ҹ� ��ȯ.. �ٵ� ���� �̷��ʿ䰡?
	
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


	//2. pair
	pair<int, int> p = make_pair(2, 2);
	pair<int, vector<int>> p2= make_pair(2, vec);

	//3. map
	map<int, int>M;
	
	M.insert(make_pair(1, 1));//
	
	M[2] = 2;//�̰� ���ŵ� ����
	
	map<int, int>::iterator it;//iterator ����
	
	it = M.begin();
	//it->first, it->second�� ��� (������ ����)
	
	M.erase(it);//iterator�� ���� �����
	M.erase(2);//key�� ���� ���� �����
	
	M.clear();
	
	M.empty();//��������� true �������� false�� ��ȯ�Ѵ�.
	
	int key = 2;
	M.count(key); //key�� �ִ��� �ִٸ� 1 ������ 0 ��ȯ ������ ������ 1�ƴϸ� 0�̱� ��
	
	M.rbegin();
	M.rend();//rbegin�� rend�� ������������ �����ϰ� ���� �� ����ϴ� ��
			//�ֳĸ� ���� end�� ������ iterator���� �ϳ� �� �� ���� ��ȯ�ϱ� ������
			//�̰� �ʿ��ϴ�.
	
	M.find(key);// �̰��� �ش� ����� itertor�� ��ȯ�Ѵ�.
				// ã�� ���� ���� M.end()�� ��ȯ�Ѵ�.
	
	int &value=M.at(key);/*key�� �ش��ϴ� value�� ������ �����´�. �̰��� pair�� ����Ű��
	������� �����ϸ� �ȵȴ� �ش� key�� ������ ���ܸ� �߻����� catch try �ؾ��ϴµ� �����ϸ�
	���� ����,, ���� find���� end()��ȯ�ϴ��� ���°� ����. find�Լ��� iterator��ȯ*/
	
	
	
	//4. string
	string str("HELLOWorld");
	
	string s1;
	s1 = "HELLO";
	
	string s2(s1);//���� ������
	
	string str2(5, 'a');//���� �ݺ��� ���� ���� ����
	//string str3(5, "ab")(X);//�̷����� ���ڿ� �ݺ��� �Ұ���
	
	string str4;

	auto ss=str2.find('f');//�̷��� �ϸ� �ε����� ��ȯ�Ѵ�..!!
	//string�� ö���� �ε����� ����ϱ� �ϳ�

	str.substr(1, 3)[0];//�̷������� �̾ƿ� string ���ڿ����� ���� �ϳ��� ��ȸ�ϴ°� ����
	str[3];//���� �̷������� ���ڿ�=���ڹ迭 �̴ϱ� �ε����� �����ϴ� ���� �����ߴ�.
	
	int j = str.length(); //null���ڸ� ���� �������� ������ ��ȯ�Ѵ�.

	str4.assign("HELLO"); //�̷������� ���ڿ��� �Ҵ����ִ� �Լ��� �̿��ϴ� �͵� ����
	
	str.append("sss");// sss��� ���ڿ��� �̾���δ�

	int ans = str.compare(str2);// str�� str2���� ������ ���� ��ȯ,
	//str2�� str���� ũ�ٸ� ��� ��ȯ, �� ���ڿ��� �����ϴٸ� 0�� ��ȯ
	str.at(3); //string�� iterator���°� �ƴ϶� �ε��� ���·� �������־�� ��
			   //�̰��� 3��° ���ڸ� ����!!
	//�����̱� ������ ���� �ٲ� �� ������
	
	auto k = str.at(3);
	
	char& ch = str.at(3);//  ch��� ���� �ϳ��� ����Ű�� �����Ϳ� ������ ���� str��
						 // ����° �ε����� ��������

	str.clear(); //string�� ����'

	str.find('c');//string�� ���ڵ��� ��Ƴ��� �����̳�ó�� ���Ǵ� ���̰�, 
				  //�����̳� �� ��Ҹ� ã�� �� ó�� find()�Լ��� �� �� �ִ�.
				  //�̰��Τ������� ��ȯ, ã�� ���Ѵٸ� end()�� ��ȯ
				  
				  

	str.push_back('c'); //���� ���ڿ� ����ó�� ����� �����ؼ� ����ó�� push_back�� �� �� �ִ�
	
	str.substr(3, 4);// substr�� �ε����� �־�� �ϰ� 3�� �ε��� ���� 4���� �����´�
	//���� ��� hyunhoseo�� �ִٸ� �ε��� 3�� n���� 4�� �� nhos�� �������� �ȴ�
	
	auto strit = s1.begin() + 3;
	
	s1.erase(strit);//p�� �ݺ��ڸ� ���Ѵ�

	//5. set
	
	set<int> S;//�ڵ������� int������ key�� ������������ �����Ѵ�
	
	set<int>S2(pred);//pred�� ���� ���ı����� ���� �� �ִ�.
	
	S.insert(3);
	S.insert(3);//���� ������ ���� �ʰ� �ߺ����� ���� ��������� �ʱ� ������ �׳� ������ٰ�
				//�� �� �ִ�
	
	S.begin();
	
	S.end();//������ �Ǿ��ֱ� ������ begin�� end�� ���� ���� �����ϴ�
	
	S.rbegin();
	
	S.rend();//�̰��� �ִ� ������ map���� ���� �ߴ�
	
	S.clear();//map�� �� �� �ִ� �͵��� ���� �� �����ϴٰ� ���� �ǰڴ�.

	set<int>::iterator iter;
	iter = S.begin();
	S.erase(key);//�� key�� �־ ���� �Ҽ��� �ְ�
	//S.erase(iter, iter+3);//set�� ���� �����̳ʿ����� ��������� ���� ����
	int n = 4;
	auto last = next(iter, n);//n��ŭ �� ������ iterator
	S.erase(iter,last ); //������ �����Ͽ�,, ��������

	S.count(key);//map������ count�� ���������� �ߺ��� ������� �ʱ� ������
				 //�ִٸ� 1 ���ٸ� 0 �� ��ȯ�ϰ� �ɰ��̴�.
	
	S.find(key);//key�� ã�� �ǰ� iterator�� ��ȯ ���� ã�� ���Ѵٸ� map�� ���������� S.end()�� ��ȯ

	//6. unordered_map

	unordered_map<int, int> um;
	um.begin();
	
	um.end();//��׵� �� ������ ������ �����ϱ� �̷� �Լ��� ���ǵǾ� �ֱ� �ϴ�
	//um.rbegin(), um.rend() ������ �������� �ٲ۴ٴ°� �ǹ̰� ���� ������ �̷��� �ȵȴ�
	//��ǻ� MAP���� ���� ���Ÿ� ���� key�� ������ �������� �ʴ� �׷� MAP�̶�� ��������

	//7.arr
	//ũ�Ⱑ ������ ��쿡�� array�� ���� ũ�Ⱑ �����̶�� vector�� ���°� ����.
	int arr[4] = { 0,1,2,3 };

	
	int arr[4] = {};//��� ���Ҹ� 0���� �ʱ�ȭ
	
	int arr[] = { 1,2,3 }; //�˾Ƽ� �迭�� ũ�Ⱑ 3�� �ȴ�

	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	//2���� �迭�� �̷������� ���� �����ϴ�. �� �྿ �شٰ� �����ϸ� �ȴ�

	//8. stack
	stack<int>sta;//stack�� �� ���� �� ���ø� �ٷ�ٴ� ���� �������
	sta.push(3);
	int top = sta.top();//stack�� �� ���� �ִ� �ڷ��� �״�� ��ȯ�Ѵ� iterator ����
	sta.pop(); //�� ���� �ִ°� ����
	sta.size();
	sta.empty();//����ִٸ� true,, count�� �򰥸��� ����.. �̰� true false�� ������
				//count�� �Լ� �̸��� ���°��ݾ� �ٵ� map�̶� set���� ���ϱ� 1,0�� �����°Ű�

	//9.queue
	queue<int>q; // FIFO��� ���� �������
	q.push(3);
	q.push(4);
	q.pop();// �� �� ��Ҹ� ���ش� .. stack�� �򰥸� ���� �����ݾ� ť�� ��������
	int back = q.back();
	int fr = q.front();//stack �� ���������� iterator�̷��� ���� ť�� ������

	//10. list
	/*����Ʈ�� � ��ġ�������� ȿ�������� ���� ������ �ȴ�. �ڷᱸ������ ��� ��
	����Ʈ�� �´�*/

	list<int>list1;
	
	list<int>list2(50, 10);// ��� 10���� �ʱ�ȭ�� 50���� list ���Ϳ� ����ϰ� �ʱ�ȭ �ǳ�
	
	list1.front();
	
	list1.back();//front�� back�� �翬�� ���� ��ȯ�Ѵ�.

	list1.push_back(20);// �� �ڿ� 20�� �߰��Ѵ�
	
	list1.push_front(10);//�� �տ� 10�� ���� �ִ´�
	
	list1.pop_front();
	
	list1.pop_back();

	//list1.find(10); ��� �Ұ���
	//����ó��
	auto jk = find(list1.begin(), list1.end(), 3);// �̷������� �ؼ� iterator�� ��ȯ
	
	list<int>::iterator listiter;
	//auto listiter = list1.begin() + 4;
	//�ε����� ���� �����̳ʸ� �����ϰ� iterator�� ���������� ������� �ϴ� ���� �ȵȴ�.
	listiter = list1.begin()++;
	list1.insert(listiter, 30);//������ iterator��ġ
	//���� ����Ű�� �ִ� ��ġ�� ���� ���� �ִ� �ִ� ��ĭ �ڷ� �з�����.. �̰� �翬��
	//�׷��� �� ��ġ�� ���� �ִ°� �ǹ̰� �ִٰ� �� �� �ְڴ�
	list1.erase(listiter);// �� ��ġ�� list�� ����
	list1.sort();//�˾Ƽ� �������� ���� sort�� ������ �׳� �������� �����̶�� ���� �ȴ�.
	