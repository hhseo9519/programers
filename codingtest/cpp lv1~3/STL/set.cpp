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
S.erase(iter, last); //범위를 지정하여,, 삭제가능

S.count(key);//map에서의 count와 마찬가지로 중복을 허용하지 않기 때문에
//있다면 1 없다면 0 을 반환하게 될것이다.

S.find(key);//key를 찾게 되고 iterator를 반환 만약 찾지 못한다면 map과 마찬가지로 S.end()를 반환
