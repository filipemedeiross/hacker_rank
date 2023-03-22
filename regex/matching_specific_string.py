import re

regex_pattern = r'hackerrank'

test_string = input()
match = re.findall(regex_pattern, test_string)

print("Number of matches :", len(match))