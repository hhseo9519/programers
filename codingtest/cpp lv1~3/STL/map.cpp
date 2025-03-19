//2. pair
pair<int, int> p = make_pair(2, 2);
pair<int, vector<int>> p2 = make_pair(2, vec);

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

int& value = M.at(key);/*key에 해당하는 value를 참조로 가져온다. 이것이 pair를 가리키는
참조라고 생각하면 안된다 해당 key가 없으면 예외를 발생시켜 catch try 해야하는데 웬만하면
쓰지 말자,, 차라리 find쓰고 end()반환하는지 보는게 낫다. find함수는 iterator반환*/

