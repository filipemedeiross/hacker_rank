import re

regex_pattern = r"\S\S\s\S\S\s\S\S"

test_string = input()
match = re.search(regex_pattern, test_string)

print(str(bool(match)).lower())