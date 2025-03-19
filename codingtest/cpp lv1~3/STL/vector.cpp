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

	int frovec = vec.front();//첫번째 원소를 반환.. 근데 굳이 이럴필요가?

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
