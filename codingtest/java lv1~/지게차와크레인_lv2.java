import java.util.*;
class Solution {
    public int solution(String[] storage, String[] requests) {
        int i0, i1, i2, t0, t1, answer = 0, n = storage.length, m = storage[0].length();
        int[][] map = new int[n+2][m+2];
        Queue<int[]> queue = new LinkedList<>();
        for(i0 = 0; i0 < n; i0++)
            for(i1 = 0; i1 < m; i1++)
                map[i0+1][i1+1] = storage[i0].charAt(i1);
        for(i0 = 0; i0 < requests.length; i0++)
        {
            if(requests[i0].length()==2)
                for(i1 = 1; i1 <= n; i1++)
                    for(i2 = 1; i2 <= m; i2++)
                        if(map[i1][i2] == requests[i0].charAt(0))
                            map[i1][i2] = 0;
            DFS(i0+1, requests[i0].charAt(0), 0, 0, n+2, m+2, map, queue);
            while(!queue.isEmpty())
            {
                map[queue.peek()[0]][queue.peek()[1]] = 0;
                queue.poll();
            }
        }
        for(i1 = 1; i1 <= n; i1++)
        {
            for(i2 = 1; i2 <= m; i2++)
                if(map[i1][i2] > 0)
                    answer++;
        }
        return answer;
    }
    int[][] dir = {{0,-1},{0,1},{1,0},{-1,0}};
    void DFS(int x, int k, int r, int c, int n, int m, int[][] map, Queue<int[]> queue)
    {
        int i0;
        map[r][c] = -x;
        for(i0 = 0; i0 < 4; i0++)
            if(r+dir[i0][0]>=0&&r+dir[i0][0]<n&&c+dir[i0][1]>=0&&c+dir[i0][1]<m)
            {
                if(map[r+dir[i0][0]][c+dir[i0][1]]<=0&&map[r+dir[i0][0]][c+dir[i0][1]]>-x)
                    DFS(x, k, r+dir[i0][0], c+dir[i0][1], n, m, map, queue);
                else if(map[r+dir[i0][0]][c+dir[i0][1]] == k)
                    queue.add(new int[]{r+dir[i0][0], c+dir[i0][1]});
            }
    }
}