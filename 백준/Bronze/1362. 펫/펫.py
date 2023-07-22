# BOJ_1362 : 펫
import sys

num_of_scenario = 0
while True:
    # 1. 적정 체중, 실제 체중을 입력 받는다.
    appropriate_weight, weight = map(int, sys.stdin.readline().split())
    if (appropriate_weight, weight) == (0, 0):
        break
    num_of_scenario += 1

    pet_emotion = None
    while True:
        # 2. 펫에게 가할 작용을 입력 받는다.
        action_type, action_num = sys.stdin.readline().split()
        if (action_type, action_num) == ('#', '0'):
            break

        # 2-1. 펫이 action 을 한다.
        if action_type == 'E':
            weight -= int(action_num)
        elif action_type == 'F':
            weight += int(action_num)

        # 2-2. 펫 상태의 변화를 확인한다.
        if (appropriate_weight // 2) < weight < (appropriate_weight * 2):
            pet_emotion = 'happy'
        elif weight <= 0:
            pet_emotion = 'dead'
            while True:
                action_type, action_num = sys.stdin.readline().split()
                if (action_type, action_num) == ('#', '0'):
                    break
            break
        else:
            pet_emotion = 'sad'

    # 3. 펫 상태를 출력한다.
    if pet_emotion == 'happy':
        print(f"{num_of_scenario} :-)")
    elif pet_emotion == 'sad':
        print(f"{num_of_scenario} :-(")
    elif pet_emotion == 'dead':
        print(f"{num_of_scenario} RIP")
