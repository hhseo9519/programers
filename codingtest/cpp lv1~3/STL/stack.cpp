//8. stack
stack<int>sta;//stack은 맨 위의 그 스택만 다룬다는 것을 명심하자
sta.push(3);
int top = sta.top();//stack의 맨 위에 있는 자료형 그대로 반환한다 iterator 없음
sta.pop(); //맨 위에 있는거 없앰
sta.size();
sta.empty();//비어있다면 true,, count랑 헷갈리지 말고.. 이건 true false의 문제다
//count는 함수 이름도 세는거잖아 근데 map이랑 set에서 쓰니까 1,0이 나오는거고
