class meansMode:
    def __init__(self):
        self.count = 0
        self.max   = None
        self.min   = None
        self.sum   = 0.0
        self.mean  = 0.0 
        self.occ   = [0]*(110)
        self.maxOcc= 0 

    def insert(self,data):
        self.occ[data] += 1
        if self.occ[data] > self.maxOcc:
            self.maxOcc = self.occ[data]
        print(self.maxOcc)
        self.count += 1
        self.sum += data
        self.mean= self.sum/self.count
        if (self.min == None) or (data<self.min):
            self.min = data
        if (self.max == None) or (data>self.max):
            self.max = data

    def getMax(self):
        return self.max

    def getMin(self):
        return self.min

    def getMean(self):
        return self.mean

    def getMode(self):
        return self.maxOcc


test = meansMode()
test.insert(10)
print("max = ",test.getMax())
print("min = ",test.getMin())
x=test.getMean()
print("mean = ",x)
y=test.getMode()
print("mode = ", y)




