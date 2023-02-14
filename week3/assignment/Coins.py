import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')


def findlargestcoinlessthan_k(coins, k):
    i = len(coins)-1
    while (i >= 0):
        if (coins[i] <= k):
            return coins[i]
        i = i-1
    return None


def minimumcoins(coins, x):
    numcoins = 0
    coins.sort()
    while (x > 0):
        large = findlargestcoinlessthan_k(coins, x)
        if (large == None):
            return None
        else:
            x = x - large
            numcoins += 1
    return numcoins


coins = list(map(int, input().strip().split()))
x = int(input())
print(minimumcoins(coins, x))
