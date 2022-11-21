import sys
dic = {'User':0, 'Score':0}
for line in sys.stdin.readlines():
    imfo = line.strip().split(",")
    dic['User'] = str(imfo[0])
    dic['Score'] = round(100*int(imfo[2])/int(imfo[1][2]), 2)
    print(dic['User']+",%.2f" %dic['Score'])