import re

regex_pattern = r"\w\w\w\W\w\w\w\w\w\w\w\w\w\w\W\w\w\w"

test_string = input()
match = re.search(regex_pattern, test_string)

print(str(bool(match)).lower())