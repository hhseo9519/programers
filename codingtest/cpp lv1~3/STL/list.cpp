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
