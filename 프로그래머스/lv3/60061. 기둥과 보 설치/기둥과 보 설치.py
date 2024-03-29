def solution(n, build_frame):
    # 전체 좌표의 [기둥, 보]의 정보
    structure = [[[0, 0] for _ in range(n + 1)] for _ in range(n + 1)]          # structure[x좌표][y좌표] = [기둥 유무, 보 유무]

    for frame in build_frame:
        pos = [frame[0], frame[1]]
        condition = [frame[2], frame[3]]                                        # 0: 기둥, 1: 보 // 0: 삭제, 1: 설치

        # 한 좌표를 기준으로 주변 좌표의 [기둥, 보]의 정보
        surrounding = [[[0, 0] for _ in range(5)] for _ in range(5)]  # surrounding[상대적 x좌표][상대적 y좌표] = [기둥 유무, 보 유무]
        # 좌표값이 범위 밖일 시에 좌표값 조정
        for i in range(-2, 3):
            for j in range(-2, 3):
                if 0 <= pos[0] + i <= n and 0 <= pos[1] + j <= n:
                    surrounding[i + 2][j + 2] = structure[pos[0] + i][pos[1] + j]

        # 1. 기둥 설치 조건
        # 설치할 기둥이 (1) 바닥 위거나, (2, 3) 보의 한쪽 끝 부분에 위치하거나, (4) 다른 기둥 위에 있을 때
        if condition == [0, 1] and pos[1] < n:
            if pos[1] == 0 or surrounding[1][2][1] == 1 or surrounding[2][2][1] == 1 or surrounding[2][1][0] == 1:
                structure[pos[0]][pos[1]][0] = 1

        # 2. 기둥 삭제 조건
        # (1) 위에 기둥이 있는데 지지해줄 보가 없을 때, (2) 위에 보가 있는데 혼자 남을 때 (3) 왼쪽 위에 보가 있는데 혼자 남을 때는 삭제하지 못한다.
        elif condition == [0, 0]:
            if not ((surrounding[2][3][0] == 1 and surrounding[1][3][1] == 0 and surrounding[2][3][1] == 0) or
                    (surrounding[2][3][1] == 1 and (surrounding[1][3][1] == 0 or surrounding[3][3][1] == 0) and surrounding[3][2][0] == 0) or
                    (surrounding[1][3][1] == 1 and (surrounding[0][3][1] == 0 or surrounding[2][3][1] == 0) and surrounding[1][2][0] == 0)):
                structure[pos[0]][pos[1]][0] = 0

        # 3. 보 설치 조건
        # 설치할 보의 (1) 왼쪽이 기둥 위에 있거나, (2) 오른쪽이 기둥 위에 있거나, (3, 4) 양쪽에 보가 있을 때
        elif condition == [1, 1] and pos[0] < n:
            if surrounding[2][1][0] == 1 or surrounding[3][1][0] == 1 or (surrounding[1][2][1] == 1 and surrounding[3][2][1] == 1):
                structure[pos[0]][pos[1]][1] = 1

        # 4. 보 삭제 조건
        # (1) 위에 기둥이 있는데 지지해줄 기둥, 보가 없을 때, (2) 오른쪽 위에 기둥이 있는데 지지해줄 기둥, 보가 없을 때,
        # (3) 왼쪽에 보가 있는데 지지해줄 기둥이 없을 때, (4) 오른쪽에 보가 있는데 지지해줄 기둥이 없을 때는 삭제하지 못한다.
        elif condition == [1, 0]:
            if not ((surrounding[2][2][0] == 1 and surrounding[1][2][1] == 0 and surrounding[2][1][0] == 0) or
                    (surrounding[3][2][0] == 1 and surrounding[3][2][1] == 0 and surrounding[3][1][0] == 0) or
                    (surrounding[1][2][1] == 1 and surrounding[1][1][0] == 0 and surrounding[2][1][0] == 0) or
                    (surrounding[3][2][1] == 1 and surrounding[3][1][0] == 0 and surrounding[4][1][0] == 0)):
                structure[pos[0]][pos[1]][1] = 0

    answer = []
    for i in range(n + 1):
        for j in range(n + 1):
            if structure[i][j][0] == 1:
                answer.append([i, j, 0])
            if structure[i][j][1] == 1:
                answer.append([i, j, 1])
    return answer