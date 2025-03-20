#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
#include<iterator>
#include<sstream>
using namespace std;

int main() {

	//1. sort함수
	vector<vector<int>> vec(5, vector<int>(4, 0));
	//사실sort의 의미가 없긴 하지만
	sort(vec.begin(), vec.end());
	//이런식이라면 문자열을 비교하듯이 숫자 비교하듯이 쭉 비교해준다


	string str = "HELLOWORLD";
	sort(str.begin(), str.end()); //이런식으로 알파벳 순서대로 바꿀 수 있다


	//2. max,min
	int a = 10, b = 20;
	int maxing = max(a, b);
	int mining = min(a, b);

	//3. max element, min element
	vector<int> vec2 = { 1,2,4,5,7,23,5,78,56,3,5, };//뒤에 쉼표가 있어도 유효, 아무런 효과 없음
	auto it = max_element(vec2.begin(), vec2.end());
	auto it2 = min_element(vec2.begin(), vec2.end());

	//4.isdigit, isalpha  #include<cctype>
	string str2 = "HFSS444444";
	bool whatisit = isdigit(str2[3]); //숫자가 맞으면 true을 반환 아님 false
	bool whatisit2 = isalpha(str[7]); //알파벳이 맞으면 true 반환, 아님 false

	//5. substr, stoi, to_string
	string str4 = "129483";
	string extract = str4.substr(3, 3);
	int inte =stoi(str4.substr(3, 3));
	string goback = to_string(inte);

	//6. compare -->string에서 사용 가능하다
	string str5 = "hello friend";
	string str4 = str5.substr(2, 6);

	int compresult = str5.compare(str4);//str5가 str4보다 작으면 음수
										//크면 양수
										//같으면 0
	
	int comprrsult2 = str5.compare(2, 6, str4);//이러면 0을 반환하겠지
											  //둘다 llo fr이니까

	// 7. stringstream ss(string str)
	//공백 혹은 개행을 기준으로 문자열 나누기..
	/*이건 find(' ')를 사용해서 그 부분을 찾고 그 다음에 저 iterator 다음꺼부터
	뽑으면 공백을 기준으로 나눌 수 있긴 한데 이게 편함*/

	string str6 = "hi my name is seo        hyeon hooo !!  ";
	stringstream ss(str6);
	string time;
	string baby;
	string good;

	ss >> time >> baby >> good;// 이렇게 하면 hi my name 까지 들어간다.
	// baby이후에 300개의 string이 와도 str6의 단어들이 다 할당되면 나머지는 공백이 들어감	
	vector<string> s(100);
	ss >> s[0] >> s[1] >> s[2] >> s[4] >> s[5]>>s[6];//이렇게 할때 저 긴 공백도
	//즉 연속된 공백도 잘 처리함
	
	//string에서의 개행
	string str7 = "hi my \n name is \n ";
	stringstream ss2(str7);
	ss2 >> s[10] >> s[11] >> s[12] >> s[13] >> s[14] >> s[15] >> s[16];
	//공백이랑 개행이 섞여있어도 하나의 구분자로 생각함

	//8. iterswap #include<iterator>
	//같은 종류의 컨테이너에서만 작동 가능,, iter끼리의 자료형이 같아야함
	//그래서 서로 다른 벡터를 가리키는 iter는 교환이 가능하다!!
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