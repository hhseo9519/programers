import java.util.*;
class Solution {
    //* target -> [s, e]
    public int solution(int[][] targets) {
        int answer = 0;

        //* e 기준 정렬
        Arrays.sort(targets, (o1, o2) -> o1[1] - o2[1]);

        int lastE = targets[0][1];
        for(int[] target : targets){
            //* 미사일의 Start가 E 밖에 있다.

            if(target[0] >= lastE){
                answer++;
                lastE = target[1];
            }
        }
        answer++;

        return answer;
    }
}