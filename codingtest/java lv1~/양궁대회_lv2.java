import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Solution {
    public int count(int[] info, int bin) {
        int cnt = 0;
        for (int i = 0; i < 11; ++i) {
            if ((bin >> i & 1) == 1) {
                cnt += info[10 - i] + 1;
            }
        }
        return cnt;
    }

    public int sum(int[] score, int bin) {
        int s = 0;
        for (int i = 0; i < 11; ++i) {
            if ((bin >> i & 1) == 1) {
                s += score[10-i];
            }
        }
        return s;
    }
    public boolean check(int bin, int b){
        for(int i=0;i<11;++i){
            if((bin>>i&1) == (b>>i&1))
                continue;
            return (b>>i&1)==1;
        }
        return true;
    }

    public int[] solution(int n, int[] info) {
        var apeach = IntStream.range(0, 11).map(i -> info[i]>0?10-i:0).sum();
        var score = IntStream.range(0, 11).map(i ->
                info[i] > 0 ? 20 - 2 * i : 10 - i).toArray();
        int max = -1;
        int bin = 0;
        var answer = new int[11];
        for (int b = 0; b < 2048; ++b) {
            if (count(info, b) <= n) {
                var s = sum(score, b);
                if (max < s) {
                    max = s;
                    bin = b;
                }
                else if(max == s && check(bin,b)){
                    bin = b;
                }
            }
        }
        for (int i = 0; i < 11; ++i) {
            if ((bin >> i & 1) == 1) {
                answer[10-i] = info[10-i]+1;
            }
        }
        answer[10] = n-count(info,bin);
        if(max<=apeach)
            answer = new int[]{-1};
        return answer;
    }
}