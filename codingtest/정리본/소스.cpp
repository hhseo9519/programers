#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<sstream>
using namespace std;

int main() {

	//1. sort�Լ�
	vector<vector<int>> vec(5, vector<int>(4, 0));
	//���sort�� �ǹ̰� ���� ������
	sort(vec.begin(), vec.end());
	//�̷����̶�� ���ڿ��� ���ϵ��� ���� ���ϵ��� �� �����ش�


	string str = "HELLOWORLD";
	sort(str.begin(), str.end()); //�̷������� ���ĺ� ������� �ٲ� �� �ִ�


	//2. max,min
	int a = 10, b = 20;
	int maxing = max(a, b);
	int mining = min(a, b);

	//3. max element, min element
	vector<int> vec2 = { 1,2,4,5,7,23,5,78,56,3,5, };//�ڿ� ��ǥ�� �־ ��ȿ, �ƹ��� ȿ�� ����
	auto it = max_element(vec2.begin(), vec2.end());
	auto it2 = min_element(vec2.begin(), vec2.end());

	//4.isdigit, isalpha  #include<cctype>
	string str2 = "HFSS444444";
	bool whatisit = isdigit(str2[3]); //���ڰ� ������ true�� ��ȯ �ƴ� false
	bool whatisit2 = isalpha(str[7]); //���ĺ��� ������ true ��ȯ, �ƴ� false

	//5. substr, stoi, to_string
	string str4 = "129483";
	string extract = str4.substr(3, 3);
	int inte =stoi(str4.substr(3, 3));
	string goback = to_string(inte);

	//6. compare -->string���� ��� �����ϴ�
	string str5 = "hello friend";
	string str4 = str5.substr(2, 6);

	int compresult = str5.compare(str4);//str5�� str4���� ������ ����
										//ũ�� ���
										//������ 0
	
	int comprrsult2 = str5.compare(2, 6, str4);//�̷��� 0�� ��ȯ�ϰ���
											  //�Ѵ� llo fr�̴ϱ�

	// 7. stringstream ss(string str)
	//���� Ȥ�� ������ �������� ���ڿ� ������..
	/*�̰� find(' ')�� ����ؼ� �� �κ��� ã�� �� ������ �� iterator ����������
	������ ������ �������� ���� �� �ֱ� �ѵ� �̰� ����*/

	string str6 = "hi my name is seo        hyeon hooo !!  ";
	stringstream ss(str6);
	string time;
	string baby;
	string good;

	ss >> time >> baby >> good;// �̷��� �ϸ� hi my name ���� ����.
	// baby���Ŀ� 300���� string�� �͵� str6�� �ܾ���� �� �Ҵ�Ǹ� �������� ������ ��	
	vector<string> s(100);
	ss >> s[0] >> s[1] >> s[2] >> s[4] >> s[5]>>s[6];//�̷��� �Ҷ� �� �� ���鵵
	//�� ���ӵ� ���鵵 �� ó����
	
	//string������ ����
	string str7 = "hi my \n name is \n ";
	stringstream ss2(str7);
	ss2 >> s[10] >> s[11] >> s[12] >> s[13] >> s[14] >> s[15] >> s[16];
	//�����̶� ������ �����־ �ϳ��� �����ڷ� ������

	//8. iterswap #include<iterator>
	//���� ������ �����̳ʿ����� �۵� ����,, iter������ �ڷ����� ���ƾ���
	//�׷��� ���� �ٸ� ���͸� ����Ű�� iter�� ��ȯ�� �����ϴ�!!
	vector<int>vecc(2);
	vector<int>vecc2(5);
	vecc2[5] = 100;
	auto it5 = vecc2.begin() + 4;
	vecc[0] = 1;
	vecc[1] = 2;
	auto it3 = vecc.begin();
	auto it4 = vecc.begin() + 1;


	iter_swap(it3, it4);
	iter_swap(it3, it5);

}