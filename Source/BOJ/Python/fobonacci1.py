global DP
DP = [-1] * 47

DP[0] = 0
DP[1] = 1

# 단순한 피보나치
def fibonachi(n):
    # 탈출문
    if n == 0:
        return 0
    if n == 1:
        return 1

    return fibonachi(n-1) + fibonachi(n-2)

def d_fibonachi(n):
    DP = []
    DP.append(0)
    DP.append(1)
    for i in range(2, 11):
        DP.append(DP[i-1] + DP[i-2])
    print(DP[10])


def fibo(n):
    if n == 0:
        return DP[0]
    if n == 1:
        return DP[1]
    # 이미 계산된 경우
    if(DP[n] != -1):
        return DP[n]

    for i in range(2, n + 1):
        DP[i] = DP[i-1] + DP[i-2]
    return DP[n]

n = int(input(""))
print(fibo(n))



