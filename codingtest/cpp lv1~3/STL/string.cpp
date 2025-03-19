//4. string
string str("HELLOWorld");

string s1;
s1 = "HELLO";

string s2(s1);//복사 생성자

string str2(5, 'a');//문자 반복을 통한 삽입 가능
//string str3(5, "ab")(X);//이런식의 문자열 반복은 불가능

string str4;

auto ss = str2.find('f');//이렇게 하면 인덱스를 반환한다..!!
//string은 철저히 인덱스를 사용하긴 하네

str.substr(1, 3)[0];//이런식으로 뽑아온 string 문자열에서 문자 하나를 조회하는것 가능
str[3];//원래 이런식으로 문자열=문자배열 이니까 인덱스로 접근하는 것이 가능했다.

int j = str.length(); //null문자를 빼고 나머지의 개수를 반환한다.

str4.assign("HELLO"); //이런식으로 문자열을 할당해주는 함수를 이용하는 것도 가능

str.append("sss");// sss라는 문자열을 이어붙인다

int ans = str.compare(str2);// str이 str2보다 작으면 음수 반환,
//str2가 str보다 크다면 양수 반환, 두 문자열이 동일하다면 0을 반환
str.at(3); //string은 iterator형태가 아니라 인덱스 형태로 지정해주어야 함
//이것은 3번째 문자를 참조!!
//참조이기 때문에 값도 바꿀 수 ㅇㅆ음

auto k = str.at(3);

char& ch = str.at(3);//  ch라는 문자 하나를 가리키는 포인터에 참조를 통해 str의
// 세번째 인덱스를 배정해줌

str.clear(); //string을 비운다'

str.find('c');//string은 문자들을 담아놓는 컨테이너처럼 사용되는 것이고, 
//컨테이너 속 요소를 찾는 것 처럼 find()함수를 쓸 수 있다.
//이건인ㄴ덱스를 반환, 찾지 못한다면 end()를 반환



str.push_back('c'); //정말 문자열 벡터처럼 사용이 가능해서 벡터처럼 push_back을 할 수 있다

str.substr(3, 4);// substr은 인덱스를 넣어야 하고 3번 인덱스 부터 4개를 가져온다
//예를 들면 hyunhoseo가 있다면 인덱스 3인 n부터 4개 즉 nhos를 가져오게 된다

auto strit = s1.begin() + 3;//string도 배열 기반인 문자열이라서 iterator의 산술연산이 가능하다

s1.erase(strit);//p는 반복자를 말한다