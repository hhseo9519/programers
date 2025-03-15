from itertools import combinations

def is_valid(secret, q, ans):
    for query, expected in zip(q, ans):
        # query와 secret의 교집합 크기 확인
        if len(set(secret) & set(query)) != expected:
            return False
    return True

def solution(n, q, ans):
    possible_codes = list(combinations(range(1, n + 1), 5))

    # 가능한 비밀 코드 후보 필터링
    valid_codes = [code for code in possible_codes if is_valid(code, q, ans)]

    return len(valid_codes)
