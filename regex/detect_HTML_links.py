import re

pattern_html = re.compile(r'<a .*?</a>')
pattern_link = re.compile(r'<a href="(.+?)"')
pattern_name = re.compile(r'>([\w \.,/]+)<')

N = int(input())

for _ in range(N):
    text = input()
    match = pattern_html.findall(text)

    for html in match:
        link = pattern_link.search(html)
        name = pattern_name.search(html)

        print(link.group(1), end=',')
        print(name.group(1).strip() if name else '')
