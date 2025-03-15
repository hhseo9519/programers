def solution(bandage, health, attacks):
    maxHealth=health
    rowSuccess=0
    attackStatus=False
    for i in range(1,attacks[-1][0]+1):
        for attack in attacks:
            if attack[0]==i:
                health-=attack[1]
                attackStatus=True
                rowSuccess=0
                break
        if health<=0:
            return -1
        if not attackStatus:
            health+=bandage[1]
            rowSuccess+=1
            if rowSuccess==bandage[0]:
                health+=bandage[2]
                rowSuccess=0
        health=min(maxHealth,health)
        attackStatus=False
    return health

