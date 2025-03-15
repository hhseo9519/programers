import sys
sys.setrecursionlimit(10**8)
def solution(edges):
    answer = [0, 0, 0, 0]
    max_ = 0
    for i in range(len(edges)):
        if max_ <= edges[i][0] or max_ <= edges[i][1]:
            max_ = max(edges[i][0], edges[i][1], max_)
    graph1 = [[] for _ in range(max_ + 1)]
    graph2 = [[] for _ in range(max_ + 1)]
    visited = [False] * (max_ + 1)
    for i in range(len(edges)):
        graph1[edges[i][0]].append(edges[i][1])
        graph2[edges[i][1]].append(edges[i][0])

    def visit(visited, k):
        visited[k] = True
        if len(graph1[k]) == 2 and len(graph2[k]) >= 2:
            answer[3] += 1
            answer[1] -= 1
        if len(graph1[k]) == 0:
            answer[2] += 1
            answer[1] -= 1
        for go in graph1[k]:
            if not visited[go]:
                visit(visited, go)
    for i in range(1, len(graph1)):
        if len(graph1[i]) >= 2 and len(graph2[i]) == 0:
            answer[0] = i
            visited[i] = True
            continue

    for go in graph1[answer[0]]:
        for ele in graph2[go]:
            if ele == answer[0]:
                graph2[go].remove(answer[0])
        answer[1] += 1
        visit(visited, go)


    return answer

