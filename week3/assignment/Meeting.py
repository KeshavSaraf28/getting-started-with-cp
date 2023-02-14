import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')
n = int(input())
meetings = []
for i in range(n):
    start, end = input().split()
    meetings.append([int(start), int(end)])

# meeting whose end time is earliest and does not conflict with the previously selected meeting.
meetings.sort(key=lambda x: x[1])
print(*meetings)
end = 0
result = []
for i in meetings:
    if i[0] >= end:
        result.append(i)
        end = i[1]
print(len(result))

#  meeting whose starting time is earliest and does not conflict with the previously selected meeting.
meetings.sort(key=lambda x: x[0])
print(*meetings)
end = 0
result = []
for i in meetings:
    if i[0] >= end:
        result.append(i)
        end = i[1]
print(len(result))
