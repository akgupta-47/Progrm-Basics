class Greedy:
    def __init__(self, sta, fin):
        self.sta = sta
        self.fin = fin
    def printObj(self):
        print(self.sta, self.fin)
    
n = int(input('enter num of activities '))
objList = []
for i in range(0, n):
    star = int(input())
    fin = int(input())
    objList.append(Greedy(star,fin))
    
def findQ(obl, n):
    objList.sort(key=lambda x: x.fin)
    i=0
    print(objList[i].fin, i)
    for j in range(1, n):
        if (objList[j].sta >= objList[i].fin):
            print(objList[j].fin, j)
            i = j
    
    
findQ(objList, n)
