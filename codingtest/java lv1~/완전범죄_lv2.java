import java.util.Arrays;

class Solution {
    public int solution(int[][] info, int n, int m) {
        int numItems = info.length;
        // INF 값 (충분히 큰 값)
        int INF = 1000000000;
        // dp[a] : A의 흔적 합이 a일 때, B의 흔적 합의 최소값 (a는 0 ~ n-1)
        int[] dp = new int[n];
        Arrays.fill(dp, INF);
        dp[0] = 0; // 초기 상태: A=0, B=0

        // 각 물건에 대해 dp 업데이트
        for (int i = 0; i < numItems; i++) {
            int costA = info[i][0];
            int costB = info[i][1];
            int[] newDp = new int[n];
            Arrays.fill(newDp, INF);
            for (int a = 0; a < n; a++) {
                if (dp[a] == INF) continue; // 이 상태는 달성 불가능
                int b = dp[a];
                // 1. A가 이 물건을 훔치는 경우
                int newA = a + costA;
                if (newA < n) { // A가 잡히지 않도록
                    // B 흔적은 그대로 b
                    newDp[newA] = Math.min(newDp[newA], b);
                }
                // 2. B가 이 물건을 훔치는 경우
                int newB = b + costB;
                if (newB < m) { // B가 잡히지 않도록
                    // A 흔적은 그대로 a
                    newDp[a] = Math.min(newDp[a], newB);
                }
            }
            dp = newDp;
        }

        // 모든 물건을 처리한 후, A의 흔적이 0 ~ n-1 중에서 B의 흔적이 m 미만인 경우 중 최소 A 흔적을 찾음
        for (int a = 0; a < n; a++) {
            if (dp[a] < m) {
                return a;
            }
        }
        // 유효한 배분이 하나도 없는 경우
        return -1;
    }
}