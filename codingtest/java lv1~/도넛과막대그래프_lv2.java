import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

class Solution {
    public int[] solution(int[][] edges) {

        int[] answer = new int[4];

        // [0-1] 연결상태 구현
        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, int[]> connCount = new HashMap<>();

        for (int[] edge : edges) {

            int from = edge[0], to = edge[1];

            if (!graph.containsKey(from))
                graph.put(from, new ArrayList<>());
            graph.get(from).add(to);

            if (!connCount.containsKey(from))
                connCount.put(from, new int[2]);
            if (!connCount.containsKey(to))
                connCount.put(to, new int[2]);

            connCount.get(from)[0]++;
            connCount.get(to)[1]++;
        }

        // [0-2] 총 정점수와 간선수 확인
        int countIndexs = connCount.size(), countEdge = edges.length;

        // [1-1] 생성된 정점 특정하기
        for (Entry<Integer, int[]> entry : connCount.entrySet()) {
            int[] info = entry.getValue();
            if (info[0] > 1 && info[1] == 0) {
                // 도착지로 설정되지 않고 2개이상의 간선의 출발지인것은 생성된 정점 외에는 불가
                answer[0] = entry.getKey();
            }
        }

        // [1-2] 모든 그래프의 수 확인 및 생성된 정점으로부터 연결된 간선정보 제거
        List<Integer> listForDelete = graph.get(answer[0]);
        int countGraph = listForDelete.size();
        for (int index : listForDelete) {
            connCount.get(index)[1]--;
        }
        graph.remove(answer[0]);
        connCount.remove(answer[0]);
        countIndexs--;
        countEdge -= listForDelete.size();

        // [2] 막대모양 그래프 갯수파악
        for (Entry<Integer, int[]> entry : connCount.entrySet()) {
            int[] info = entry.getValue();
            if (info[1] == 0) {
                // 도착지로 설정되지 않고 간선의 출발지인것은 막대그래프의 시작점
                answer[2]++;
            }
        }
        countGraph -= answer[2];
        countEdge += answer[2];

        // [3] 나머지 그래프 숫자파악
        answer[3] = countEdge - countIndexs;
        answer[1] = countGraph - answer[3];

        return answer;
    }
}