import re

regex_pattern = r"\d\d\D\d\d\D\d\d\d\d"

test_string = input()
match = re.search(regex_pattern, test_string)

print(str(bool(match)).lower())