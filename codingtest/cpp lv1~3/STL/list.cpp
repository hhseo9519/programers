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
