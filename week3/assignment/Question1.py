
def operation(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            arr[i] = 0


t = int(input())
while t:
    t -= 1
    n = int(input())
    arr = list(map(int, (input().split())))

    no_of_op = 0
    change = 1
    while change == 1:
        change = 0
        for i in range(n-1, 0, -1):
            if arr[i] < arr[i-1]:
                no_of_op += 1
                operation(arr, arr[i-1])
                change = 1

    print(no_of_op)
