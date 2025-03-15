def solution(mats, park):
    answer = -1
    mats.sort()
    for w in mats:
        for i in range(len(park)):
            for j in range(len(park[0])):
                if not park[i][j].isalpha():
                    count = 0
                    for r in range(i, min(len(park), i+w)):
                        for c in range(j, min(len(park[0]), j+w)):
                            if not park[r][c].isalpha():
                                count += 1
                    if count == w * w:
                        answer = w
    return answer