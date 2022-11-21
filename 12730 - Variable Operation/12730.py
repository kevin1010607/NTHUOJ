import sys
words = []
for line in sys.stdin.readlines():
    words.append(line.strip())
term1 = str(round(float(words[0])*float(words[1]), 1))
term2 = str(int(words[2])*words[3])
print(term1+term2)