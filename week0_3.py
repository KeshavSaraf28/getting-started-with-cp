# n = 2**18
# sum = 0
# for i in range(n):
#     if "11" not in bin(i):
#         sum += 1
# print(sum)

# it follows fibonacci's algorithm with fib(3) as n=1
n = int(input())
a = 1
b = 1
for i in range(n):
    temp = a+b
    a = b
    b = temp
print(b)
