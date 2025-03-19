//9.queue
queue<int>q; // FIFO라는 것을 기억하자
q.push(3);
q.push(4);
q.pop();// 맨 앞 요소를 없앤다 .. stack과 헷갈릴 때는 지났잖아 큐는 누워있음
int back = q.back();
int fr = q.front();//stack 과 마찬가지로 iterator이런거 없어 큐랑 스택은
