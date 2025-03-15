class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(22, 6, 8);
    }

    public int solution(int n, int w, int num) {
        int tmp = n % w == 0 ? 0 : 1;
        int[][] box = new int[(n / w + tmp + 2)][w];
        dfs((n / w), 0, n, w, 1, box, true);
        int answer = 0;
        for (int i = 0; i < box.length && answer == 0; i++) {
            for (int j = 0; j < box[0].length; j++) {
                if (box[i][j] == num) {
                    int idx = i;
                    while (idx >= 0 && box[idx][j] != 0) {
                        answer++;
                        idx--;
                    }
                    break;
                }
            }
        }

        return answer;
    }

    private void dfs(int row, int col, int n, int w, int cnt, int[][] box, boolean dir) {
        if (cnt == n + 1) {
            return;
        }

        if (col == w) {
            dfs(row - 1, col - 1, n, w, cnt, box, !dir);
            return;
        } else if (col == -1) {
            dfs(row - 1, 0, n, w, cnt, box, !dir);
            return;
        }

        box[row][col] = cnt;

        if (dir) {
            dfs(row, col + 1, n , w, cnt + 1, box, dir);
        } else {
            dfs(row, col - 1, n , w, cnt + 1, box, dir);
        }

    }

}