//2. pair
pair<int, int> p = make_pair(2, 2);
pair<int, vector<int>> p2 = make_pair(2, vec);

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

int& value = M.at(key);/*key�� �ش��ϴ� value�� ������ �����´�. �̰��� pair�� ����Ű��
������� �����ϸ� �ȵȴ� �ش� key�� ������ ���ܸ� �߻����� catch try �ؾ��ϴµ� �����ϸ�
���� ����,, ���� find���� end()��ȯ�ϴ��� ���°� ����. find�Լ��� iterator��ȯ*/

