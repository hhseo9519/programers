from collections import deque


def solution(board, h, w):
    answer = 0
    color = board[h][w]
    N = len(board)

    for di, dj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ni, nj = h + di, w + dj

        if ni < 0 or nj < 0 or ni >= N or nj >= N:
            continue

        if board[ni][nj] == color:
            answer += 1

    return answer
