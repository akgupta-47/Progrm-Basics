class Puzzle:
    def __init__(self, col, initState, goalState):
        self.col = col
        self.initState = initState
        self.goalState = goalState
        
    def equal(self):
        for i in range(0, len(self.initState)):
            if(self.initState[i] != self.goalState):
                return False
        return True
        
    def successful():
        print('goalState is reached')
        for j in range(0, len(self.initState)):
            print(initState[j])
        
    def moveUp(self, i):
        if(i - self.col >= 0):
            temp1 = self.initState[i]
            self.initState[i] = self.initState[i-3]
            self.initState[i-3] = temp1
        if(self.equal()):
            return True
        else:
            return False
    
    def moveDown(self, i):
        if(i + self.col >= len(self.initState)):
            temp1 = self.initState[i]
            self.initState[i] = self.initState[i+3]
            self.initState[i+3] = temp1
        self.equal()
        if(self.equal()):
            return True
        else:
            return False
    
    def moveLeft(self, i):
        if(i % self.col > 0):
            temp1 = self.initState[i]
            self.initState[i] = self.initState[i-1]
            self.initState[i-1] = temp1
        self.equal()
        if(self.equal()):
            return True
        else:
            return False
            
    def moveRight(self, i):
        if(i % self.col < self.col-1):
            temp1 = self.initState[i]
            self.initState[i] = self.initState[i-3]
            self.initState[i-3] = temp1
        self.equal()
        if(self.equal()):
            return True
        else:
            return False
        
    def iteratorFun(self):
        while(True):
            space = self.initState.index(0)
            if(self.moveUp(space)):
                self.successful()
                return
            else:
                self.moveUp(space)
            space = self.initState.index(0)
            if(self.moveDown(space)):
                self.successful()
                return
            else:
                self.moveDown(space)
            space = self.initState.index(0)
            if(self.moveRight(space)):
                self.successful()
                return
            else:
                self.moveRight(space)
            space = self.initState.index(0)
            if(self.moveLeft(space)):
                self.successful()
                return
            else:
                self.moveLeft(space)
            
     
inputCol = int(input())
inputIS = [1,2,3,0,4,6,7,5,8]
inputGS = [1,2,3,4,5,6,7,8,0]
p8 = Puzzle(inputCol,inputIS, inputGS)
p8.iteratorFun()
