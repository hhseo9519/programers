#include<vector>
#include<map>
#include<string>
#include<set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
#include<iterator>//next 함수를 위해
using namespace std;

/// <summary>
/// auto last = next(iter,3) -> 3만큼 더 간 iterator를 말한다.
/// next라고 해서 하나만 더 갈거면 iter = ++iter;이런식으로 하지,,ㅋ 전위연산 해야함 주의하자
/// begin(), end(), rbegin(), rend() find()는 거의 iterator를 반환
/// string의 find만 iterator반환 안함 알고리즘의 find함수(vector,list)역시도
/// iterator를 반환한다.
/// </summary>

int main() {
	//1. vector
	
	vector<int>vec;
	
	
	vector<int>vec2(5, 0);//5개의 칸을 만들고 모두 0으로 초기화
	
	vector<vector<int>>vec3(5, vector<int>(5, 0));//5X5 배열을 만들고 각 열을 0으로 초기화
	
	int frovec=vec.front();//첫번째 원소를 반환.. 근데 굳이 이럴필요가?
	
	int bacvec = vec.back();
	//int whatIs = vec.find(3); vector클래스 내부에는 find함수가 존재하지 않음
	//그렇기 때문에 algorithm의 find 함수를 사용해야 함
	
	auto whatIS = find(vec.begin(), vec.end(), 8);//찾으면 iterator 반환
	//기본적으로 find함수는 iterator를 반환한다 string에서만 index를 반환
	//만약 찾지 못하면 vec.end()를 반환
	//근데 이것도 맨 뒤에서 한칸 더 있는 그거겠지? 당연히? ㅇㅇ 그렇다!!

	//굳이 이렇게 앞과 뒤를 조회할 필요 없음 
	//vec[0], vec[vec.size()_1]을 하면 됌
	int baccc = vec[vec.size() - 1];


	//2. pair
	pair<int, int> p = make_pair(2, 2);
	pair<int, vector<int>> p2= make_pair(2, vec);

	//3. map
	map<int, int>M;
	
	M.insert(make_pair(1, 1));//
	
	M[2] = 2;//이건 갱신도 가능
	
	map<int, int>::iterator it;//iterator 선언
	
	it = M.begin();
	//it->first, it->second로 사용 (포인터 개념)
	
	M.erase(it);//iterator를 통해 지운다
	M.erase(2);//key를 통해 직접 지운다
	
	M.clear();
	
	M.empty();//비어있으면 true 차있으면 false를 반환한다.
	
	int key = 2;
	M.count(key); //key가 있는지 있다면 1 없으면 0 반환 개수는 무조건 1아니면 0이긴 해
	
	M.rbegin();
	M.rend();//rbegin과 rend는 내림차순으로 정렬하고 싶을 때 사용하는 것
			//왜냐면 원래 end가 마지막 iterator보다 하나 더 간 것을 반환하기 때문에
			//이게 필요하다.
	
	M.find(key);// 이것은 해당 요소의 itertor를 반환한다.
				// 찾지 못한 경우는 M.end()를 반환한다.
	
	int &value=M.at(key);/*key에 해당하는 value를 참조로 가져온다. 이것이 pair를 가리키는
	참조라고 생각하면 안된다 해당 key가 없으면 예외를 발생시켜 catch try 해야하는데 웬만하면
	쓰지 말자,, 차라리 find쓰고 end()반환하는지 보는게 낫다. find함수는 iterator반환*/
	
	
	
	//4. string
	string str("HELLOWorld");
	
	string s1;
	s1 = "HELLO";
	
	string s2(s1);//복사 생성자
	
	string str2(5, 'a');//문자 반복을 통한 삽입 가능
	//string str3(5, "ab")(X);//이런식의 문자열 반복은 불가능
	
	string str4;

	auto ss=str2.find('f');//이렇게 하면 인덱스를 반환한다..!!
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
	
	auto strit = s1.begin() + 3;
	
	s1.erase(strit);//p는 반복자를 말한다

	//5. set
	
	set<int> S;//자동적으로 int형식의 key를 오름차순으로 정렬한다
	
	set<int>S2(pred);//pred를 통해 정렬기준을 만들 수 있다.
	
	S.insert(3);
	S.insert(3);//따로 에러가 나진 않고 중복으로 값이 저장되지는 않기 때문에 그냥 사라진다고
				//볼 수 있다
	
	S.begin();
	
	S.end();//정렬이 되어있기 때문에 begin과 end를 쓰는 것이 가능하다
	
	S.rbegin();
	
	S.rend();//이것이 있는 이유는 map에서 설명 했다
	
	S.clear();//map서 할 수 있는 것들이 거의 다 가능하다고 보면 되겠다.

	set<int>::iterator iter;
	iter = S.begin();
	S.erase(key);//그 key를 넣어서 삭제 할수도 있고
	//S.erase(iter, iter+3);//set과 같은 컨테이너에서는 산술연산이 되지 않음
	int n = 4;
	auto last = next(iter, n);//n만큼 그 다음의 iterator
	S.erase(iter,last ); //범위를 지정하여,, 삭제가능

	S.count(key);//map에서의 count와 마찬가지로 중복을 허용하지 않기 때문에
				 //있다면 1 없다면 0 을 반환하게 될것이다.
	
	S.find(key);//key를 찾게 되고 iterator를 반환 만약 찾지 못한다면 map과 마찬가지로 S.end()를 반환

	//6. unordered_map

	unordered_map<int, int> um;
	um.begin();
	
	um.end();//얘네도 뭐 임의의 순서는 있으니까 이런 함수가 정의되어 있긴 하다
	//um.rbegin(), um.rend() 순서를 역순으로 바꾼다는게 의미가 없기 때문에 이런건 안된다
	//사실상 MAP에서 위의 저거만 없고 key로 순서가 정해지지 않는 그런 MAP이라고 생각하자

	//7.arr
	//크기가 고정된 경우에는 array를 쓰고 크기가 동적이라면 vector를 쓰는게 좋다.
	int arr[4] = { 0,1,2,3 };

	
	int arr[4] = {};//모든 원소를 0으로 초기화
	
	int arr[] = { 1,2,3 }; //알아서 배열의 크기가 3이 된다

	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	//2차원 배열은 이런식으로 선언도 가능하다. 한 행씩 준다고 생각하면 된다

	//8. stack
	stack<int>sta;//stack은 맨 위의 그 스택만 다룬다는 것을 명심하자
	sta.push(3);
	int top = sta.top();//stack의 맨 위에 있는 자료형 그대로 반환한다 iterator 없음
	sta.pop(); //맨 위에 있는거 없앰
	sta.size();
	sta.empty();//비어있다면 true,, count랑 헷갈리지 말고.. 이건 true false의 문제다
				//count는 함수 이름도 세는거잖아 근데 map이랑 set에서 쓰니까 1,0이 나오는거고

	//9.queue
	queue<int>q; // FIFO라는 것을 기억하자
	q.push(3);
	q.push(4);
	q.pop();// 맨 앞 요소를 없앤다 .. stack과 헷갈릴 때는 지났잖아 큐는 누워있음
	int back = q.back();
	int fr = q.front();//stack 과 마찬가지로 iterator이런거 없어 큐랑 스택은

	//10. list
	/*리스트는 어떤 위치에서든지 효율적으로 삭제 삽입이 된다. 자료구조에서 배운 그
	리스트가 맞다*/

	list<int>list1;
	
	list<int>list2(50, 10);// 모두 10으로 초기화된 50개의 list 벡터와 비슷하게 초기화 되네
	
	list1.front();
	
	list1.back();//front와 back은 당연히 값을 반환한다.

	list1.push_back(20);// 맨 뒤에 20을 추가한다
	
	list1.push_front(10);//맨 앞에 10을 집어 넣는다
	
	list1.pop_front();
	
	list1.pop_back();

	//list1.find(10); 사용 불가능
	//벡터처럼
	auto jk = find(list1.begin(), list1.end(), 3);// 이런식으로 해서 iterator를 반환
	
	list<int>::iterator listiter;
	//auto listiter = list1.begin() + 4;
	//인덱스를 가진 컨테이너를 제외하고 iterator를 저런식으로 산술연산 하는 것은 안된다.
	listiter = list1.begin()++;
	list1.insert(listiter, 30);//지정된 iterator위치
	//현재 가리키고 있는 위치로 들어가고 원래 있던 애는 한칸 뒤로 밀려난다.. 이게 당연히
	//그래야 저 위치에 집어 넣는게 의미가 있다고 할 수 있겠다
	list1.erase(listiter);// 이 위치의 list를 삭제
	list1.sort();//알아서 오름차순 정렬 sort는 원래가 그냥 오름차순 정렬이라고 보면 된다.
	