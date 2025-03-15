def solution(h1, m1, s1, h2, m2, s2):

    def atStart():
        if h1 == m1 == s1 == 0: return 1
        if h1 % 12 * 5 + m1 / 12 + s1 / (12 * 60) == s1 or m1 / 60 == s1: return 1
        return 0

    def checkAlarm(h, m, s):
        if h >= 12:
            return 1426 + checkAlarm(h-12, m, s)

        if h == m == s == 0: return 1
        alarm = h * 60 * 2 + m * 2 - 1 - h
        if 0 <= h * 5 + m / 12 <= s: alarm += 1
        if 0 <= m + s / 60 <= s: alarm += 1
        return alarm

    # print(checkAlarm(h1, m1, s1))
    # print(checkAlarm(h2, m2, s2))

    return checkAlarm(h2, m2, s2) - checkAlarm(h1, m1, s1) + atStart()

