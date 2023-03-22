import re

regex_pattern = r"^\d\w\w\w\w\.$"

test_string = input()
match = re.search(regex_pattern, test_string)

print(str(bool(match)).lower())