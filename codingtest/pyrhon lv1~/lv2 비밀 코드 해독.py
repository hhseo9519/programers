from itertools import combinations

def is_valid(secret, q, ans):
    for query, expected in zip(q, ans):
        # query�� secret�� ������ ũ�� Ȯ��
        if len(set(secret) & set(query)) != expected:
            return False
    return True

def solution(n, q, ans):
    possible_codes = list(combinations(range(1, n + 1), 5))

    # ������ ��� �ڵ� �ĺ� ���͸�
    valid_codes = [code for code in possible_codes if is_valid(code, q, ans)]

    return len(valid_codes)
