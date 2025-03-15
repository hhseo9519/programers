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
    sort(toplev.rbegin(), toplev.rend());//r�� ����Ͽ� �������� ����;
    int left = 1;
    int right = toplev[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        if()
    }
    for (int i = toplev[0]; i >0; i--) {
        
        //���⼭���ʹ� ����� �ϴ°���
        time = 0;
        for (int j = 0; j < times.size(); j++) {
            if (i < diffs[j]) {
                int plustime=(diffs[j]-i)* (times[j] + times[j - 1]);//������ ������ Ȯ���ϱ� ������ 
                //������ ����� ���� �������� �ʾƵ� �ȴ�.
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
// ���� Ž�� Ȱ�� Ǯ��
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
            end = level - 1;// �̷��� ����ϱ� �������� while���� Ż�� �� �� �ְ� �ǳ�;
            //������ �������� end�� start�� ������ ���ðŰ�, �� ��Ȳ���� �ѹ� �� �ϰ� �Ǹ� end�� start�� �ϳ����̷� �ٲ�
            //�׷��� �ᱹ �������� level = (start+end)/2 �� �ϰ� �Ǹ� �� ���� end�� ���󰡰� ��.���� level���� 1�� �۾����°���. 
            //���� �����̶� ����Ʈ���� ����ϴ� �� level�� ���ϴ°���. �ּ��� �� ����. �׷��� �������� +1�� ���־�� �Ѵ�.
        }
        else
        {
            start = level + 1;
            //�� �������� ���� start�� end�� �̹� ���� ���� ���� �̶��� totaltime�� limit���� ū ���´ϱ�. 
            //�ᱹ �̶��� start�� �ϳ� �÷��� end�� �������ٸ� �׶��� �ᱹ ���� if���·� ���Ŵ�. �׷��� ���� ����. �׷� �ٽ� ���� ����
            //������ ������ ��Ȳ�� �������� �Ŵϱ�.
        }

        level = (start + end) / 2;

    }


    return level + 1;
}
// �ٽ� �غ���
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
        //totaltime=0���� ���� �ٽ� time�� �˻��س����� �ڵ�
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
        else if (totalTime > limit) {//������ �� ���� ���
            start = level + 1;
        }
        else {
            end = level - 1;
        }
        level = (start + end) / 2;
        answer = level + 1;

    }
    return answer;
}//�±� �ѵ� ���� �̰� ~���� ū �ּڰ��̶� �׷���..
//�׷��ϱ� �� ��� Ÿ���ϰ� �񱳸� �ذ��鼭 start�� end�� ã��. �̰ǶȰ���
//�׷� start�� end�� �������� ���� �� �������� ���� ��� ����Ű�� ������?
//���࿡ �� ���ڰ� �� ������ break�ϰ� ���������� �ٵ� �׷��� ���� ��Ȳ���ݾ�?
//�Ƹ� start , [],[],end �̷����ϰž� []�� �ϳ��ϼ��� ���� �ϳ���� �ٷ� ��������
//�ΰ���� start,end --> end,start �̷��� �ٲ�鼭 ����
//start�� end�� �������� �ѹ� �� �ϰ� �ᱹ ��߳����� ���𰡰� �ٲ�鼭 �׶��� mid���� 
//���ǿ� ���� �ٲ��ٵ�, ������ �װź��� ū �ּڰ��̾�
�� �񱳽�,

��ȣ�� ������, ���� ���� ã�� ���̰�
��ȣ�� ������, ���� ���� ã�� ���̴�.
�ڵ� ����,
[5. �ڵ�]

#include <iostream>

// �迭 �� �ߺ� �� ���� �� ��ȿ������
// �ߺ� �� ���� �� ������ ���� �� �ִ� Ž��
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
