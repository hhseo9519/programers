import java.util.*;

class Solution {
    //시간복잡도 nlogn 제한
    int helper(int[] queue1, int[] queue2) {
        var count = 0;
        var q1 = new LinkedList<Long>();
        var q2 = new LinkedList<Long>();
        var q1Sum = 0L;
        var q2Sum = 0L;
        for (var i : queue1) {
            q1.offer((long)i);
            q1Sum += (long) i;
        }
        for (var i : queue2) {
            q2.offer((long)i);
            q2Sum += (long) i;
        }
        var sum = q1Sum + q2Sum;
        if (sum % 2 == 1) return -1;
        var length = q1.size() + q2.size();
        //부분합의 최대 구하기.
        while (true) {
            //count가 전체 크기를 넘어서면
            if (count > 600001) {
                return -1;
            }
            //q1의 합이 전체/2와 같아지면 
            if (q1Sum == sum/2) {
                return count;
            //q1의 합이 전체/2보다 크다면 
            } else if (q1Sum > sum/2) {
                var poll = q1.poll();
                q2.offer(poll);

                q2Sum += poll;
                q1Sum -= poll;
            //q1의 합이 전체/2보다 작으면
            } else if (q1Sum < sum/2) {
                var poll = q2.poll();
                q1.offer(poll);

                q1Sum += poll;
                q2Sum -= poll;
            }
            count++;
        }

    }
    public int solution(int[] queue1, int[] queue2) {

        var result1 = helper(queue1, queue2);
        var result2 = helper(queue2, queue1);
        return Math.min(result1, result2);
    }
}