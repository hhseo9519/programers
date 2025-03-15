#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    long long time = 0;
    vector<int> toplev;
    toplev = diffs;
    sort(toplev.rbegin(), toplev.rend());//r을 사용하여 내림차순 정렬;
    int left = 1;
    int right = toplev[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        if()
    }
    for (int i = toplev[0]; i >0; i--) {
        
        //여기서부터는 계산을 하는거지
        time = 0;
        for (int j = 0; j < times.size(); j++) {
            if (i < diffs[j]) {
                int plustime=(diffs[j]-i)* (times[j] + times[j - 1]);//문제의 조건이 확실하기 때문에 
                //범위를 벗어나는 것을 걱정하지 않아도 된다.
                time += (plustime + times[j]);

            }
            else if (i >= diffs[j]) {
                time += times[j];
                }
        }
        if (time > limit) {
            answer = i + 1;
            break;
        }
        else if (time == limit) {
            answer = i;
            break;
        }

    }
    return answer;
}
// 이진 탐색 활용 풀이
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {

    long long totalTime = 0;

    long long start = 1;
    long long end = limit;

    long long level = (start + end) / 2;



    while (start <= end)
    {
        totalTime = 0;

        for (long long i = 0; i < diffs.size(); i++)
        {
            if (diffs[i] <= level)
            {
                totalTime += times[i];
            }
            else
            {
                long long error = diffs[i] - level;
                totalTime += (times[i] + times[i - 1]) * error + times[i];
            }
        }

        if (totalTime <= limit)
        {
            end = level - 1;// 이렇게 만드니까 마지막에 while문을 탈출 할 수 있게 되네;
            //마지막 순간에는 end랑 start가 같은게 나올거고, 그 상황에서 한번 더 하게 되면 end랑 start가 하나차이로 바뀜
            //그러면 결국 마지막에 level = (start+end)/2 를 하게 되면 더 작은 end를 따라가게 돼.원래 level보다 1이 작아지는거지. 
            //원래 레벨이란 리미트내에 통과하는 그 level을 말하는거지. 최소의 그 레벨. 그래서 마지막에 +1을 해주어야 한다.
        }
        else
        {
            start = level + 1;
            //이 순간에는 아직 start랑 end가 이미 같을 수가 없어 이때는 totaltime이 limit보다 큰 상태니까. 
            //결국 이때도 start를 하나 늘려서 end와 같아진다면 그때는 결국 위의 if상태로 들어갈거다. 그래서 문제 없음. 그럼 다시 위로 가면
            //위에서 설명한 상황과 같아지는 거니까.
        }

        level = (start + end) / 2;

    }


    return level + 1;
}
// 다시 해보기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    long long totalTime = 0;

    long long start = 1;
    long long end = limit;

    long long level = (start + end) / 2;



    while (start <= end) {
        //totaltime=0으로 놓고 다시 time을 검사해나가는 코드
        totalTime = 0;

        for (long long i = 0; i < diffs.size(); i++)
        {
            if (diffs[i] <= level)
            {
                totalTime += times[i];
            }
            else
            {
                long long error = diffs[i] - level;
                totalTime += (times[i] + times[i - 1]) * error + times[i];
            }
        }
        if (totalTime == limit) {
            answer = level;
            break;
        }
        else if (totalTime > limit) {//레벨이 좀 낮은 경우
            start = level + 1;
        }
        else {
            end = level - 1;
        }
        level = (start + end) / 2;
        answer = level + 1;

    }
    return answer;
}//맞긴 한데 지금 이게 ~보다 큰 최솟값이라 그렇다..
//그러니까 음 계속 타겟하고 비교를 해가면서 start랑 end를 찾아. 이건똑같아
//그럼 start랑 end가 같아지는 순간 그 순간에는 내가 어디를 가리키고 있을까?
//만약에 그 숫자가 딱 있으면 break하고 끝나지겠지 근데 그렇지 않은 상황이잖아?
//아마 start , [],[],end 이런식일거야 []는 하나일수도 있지 하나라면 바로 같아지고
//두개라면 start,end --> end,start 이렇게 바뀌면서 끝나
//start랑 end가 같아지면 한번 더 하고 결국 어긋나겠지 무언가가 바뀌면서 그때의 mid값은 
//조건에 따라서 바뀔텐데, 지금은 그거보다 큰 최솟값이야
값 비교시,

등호가 있으면, 하한 값을 찾는 것이고
등호가 없으면, 상한 값을 찾는 것이다.
코드 참조,
[5. 코드]

#include <iostream>

// 배열 내 중복 값 없을 시 유효하지만
// 중복 값 있을 시 문제가 있을 수 있는 탐색
int bsearch(const int* arr, const int len, const int value)
{
    int idx = len;
    int lo = 0, hi = len - 1;

    while (lo <= hi) {
        const int mid = (lo + hi);
        const int v = arr[mid];

        if (v >= value) {
            idx = mid;
            hi = mid - 1;

            if (v == value) {
                break;
            }
        }
        else {
            lo = mid + 1;
        }
    }

    return idx;
}

template <bool lower>
int search(const int* arr, const int len, const int value)
{
    int lo = 0, hi = len - 1;

    while (lo <= hi) {
        const int mid = (lo + hi);
        const int v = arr[mid];

        if (lower) {
            if (v < value) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        else {
            if (v <= value) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }

    if (lower) {
        return lo;
    }
    return hi + 1;
}
