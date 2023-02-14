# references
# https://www.youtube.com/watch?v=zH4z15UpABs&ab_channel=MisterCode
# https://ocw.tudelft.nl/wp-content/uploads/Algoritmiek_Scheduling_to_Minimize_Maximum_Lateness.pdf
import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')
n = int(input())
time_dead = []
for i in range(n):
    time, dead = input().strip().split()
    time_dead.append([int(time), int(dead)])
time_dead.sort(key=lambda x: x[1])
currenttime = 0
Maxlazy = []
for i in time_dead:
    currenttime += i[0]
    Maxlazy.append(max(0, currenttime-i[1]))
print(Maxlazy)
