import java.util.*;
class Solution {
    int GIVE = 0;
    int TAKE = 1;

    public int solution(String[] friends, String[] gifts) {
        Map<String, Integer> idxMap = new HashMap<>();
        int idx = 0;

        for(String friend : friends) {
            idxMap.put(friend, idx++);
        }

        int[][] matrix = new int[friends.length][friends.length];
        int[][] giveAndTakeArr = new int[friends.length][2];
        String[] names;
        for(String gift : gifts) {
            names = gift.split(" ");

            int A = idxMap.get(names[0]);
            int B = idxMap.get(names[1]);

            matrix[A][B]++;
            giveAndTakeArr[A][GIVE]++;
            giveAndTakeArr[B][TAKE]++;
        }

        Map<Integer, Integer> answerMap = new HashMap<>();
        for(int i=0; i<matrix.length-1; i++) {
            for(int j=i+1; j<matrix[i].length; j++) {

                // A, B 간에 준 선물 숫자
                int A = matrix[i][j];
                int B = matrix[j][i];

                if((A == 0 && B == 0) || (A == B)) {
                    int AVal = giveAndTakeArr[i][GIVE] - giveAndTakeArr[i][TAKE];
                    int BVal = giveAndTakeArr[j][GIVE] - giveAndTakeArr[j][TAKE];

                    if(AVal == BVal) {
                        continue;
                    }

                    if(AVal > BVal) {
                        answerMap.put(i, answerMap.getOrDefault(i, 0) +1);
                    }else {
                        answerMap.put(j, answerMap.getOrDefault(j, 0) +1);
                    }
                }else {
                    if(A > B) {
                        answerMap.put(i, answerMap.getOrDefault(i, 0) +1);
                    }else {
                        answerMap.put(j, answerMap.getOrDefault(j, 0) +1);
                    }
                }
            }
        }

        int answer = 0;
        for(Map.Entry<Integer, Integer> entry : answerMap.entrySet()) {
            answer = Math.max(answer, entry.getValue());
        }

        return answer;
    }
}