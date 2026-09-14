def str_to_YMD(strin):
    return int(strin[0:4]), int(strin[5:7]), int(strin[8:])

def solution(today, terms, privacies):
    today_ymd = list(str_to_YMD(today))
    result = []

    for i in range(len(privacies)):
        p_year, p_month, p_day = str_to_YMD(privacies[i][0:10])
        privacies[i] = [p_year, p_month, p_day, privacies[i][11]]

    for i in range(len(privacies)):
        for j in range(len(terms)):
            if privacies[i][3] == terms[j][0]:
                act_day = int(terms[j][2:])

                privacies[i][2] += act_day * 28

                if privacies[i][2] > 28:
                    privacies[i][1] += (privacies[i][2] - 1) // 28
                    privacies[i][2] = (privacies[i][2] - 1) % 28 + 1

                if privacies[i][1] > 12:
                    privacies[i][0] += (privacies[i][1]-1) // 12
                    privacies[i][1] = (privacies[i][1]-1) % 12 + 1

    for i in range(len(privacies)):
        if privacies[i][0] < today_ymd[0]:
            result.append(i+1)
        elif privacies[i][0] == today_ymd[0]:
            if privacies[i][1] < today_ymd[1]:
                result.append(i+1)
            elif privacies[i][1] == today_ymd[1]:
                if privacies[i][2] <= today_ymd[2]:
                    result.append(i+1)

    return result