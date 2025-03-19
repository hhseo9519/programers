//6. unordered_map

unordered_map<int, int> um;
um.begin();

um.end();//얘네도 뭐 임의의 순서는 있으니까 이런 함수가 정의되어 있긴 하다
//um.rbegin(), um.rend() 순서를 역순으로 바꾼다는게 의미가 없기 때문에 이런건 안된다
//사실상 MAP에서 위의 저거만 없고 key로 순서가 정해지지 않는 그런 MAP이라고 생각하자
