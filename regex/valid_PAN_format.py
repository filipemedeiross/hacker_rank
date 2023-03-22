import re

regex_pattern = r"[A-Z]{5}[0-9]{4}[A-Z]"

N = int(input())

for _ in range(N):
    test_string = input()

    if re.fullmatch(regex_pattern, test_string):
        print("YES")
    else:
        print("NO")