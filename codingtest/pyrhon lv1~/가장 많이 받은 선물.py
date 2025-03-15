def solution(friends, gifts):
    friends.sort()
    result = {}
    bonus = {}
    gift_point = {}
    next_month = {}

    for i in friends:
        gift_point[i] = 0
        next_month[i] = 0
        result[i] = 0
        a = friends.copy()
        a.remove(i)
        for aa in a:
            if i < aa:
                bonus[i+' '+aa] = [0, 0]
            else:
                bonus[aa + ' ' + i] = [0, 0]
        # 선물지수 dict

    for i in gifts:
        a = i.split(" ")
        result[a[0]] += 1
        # 선물지수
        gift_point[a[0]] += 1
        gift_point[a[1]] -= 1
        if a[0] < a[1]:
            bonus[a[0] + ' ' + a[1]][0] += 1
        else:
            bonus[a[1] + ' ' + a[0]][1] += 1

    for i in bonus:
        a = i.split(' ')[0]
        b = i.split(' ')[1]
        if bonus[i][0] > bonus[i][1]:
            next_month[a] += 1
        if bonus[i][0] < bonus[i][1]:
            next_month[b] += 1
        if bonus[i][0] == bonus[i][1]:
            if gift_point[a] > gift_point[b]:
                next_month[a] += 1
            if gift_point[a] < gift_point[b]:
                next_month[b] += 1
    answer = 0

    for tt in next_month.values():
        if answer < tt:
            answer = tt

    return answer

