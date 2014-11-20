import time
from Tkinter import *

def parse(packets):
	x = 0
	userData={}
	while x < len(packets):
		
		newPack = packets[x]
		userID = newPack[0:8]
		userAnswer = newPack[8:10]

		if userAnswer == '00':
			alphaAnswer = 'A'
		elif userAnswer == '01':
			alphaAnswer = 'B'
		elif userAnswer == '02':
			alphaAnswer = 'C'
		elif userAnswer == '03':
			alphaAnswer = 'D'
		else:
			alphaAnswer = 'Not a valid answer'
		userData[userID] = alphaAnswer
		
		x += 1
	return userData

def genKeyList(userDict):

     userIDList=userDict.keys()

     return userIDList
    
def answerCount(userDict,userList):

    loopCount = 0

    aCount = 0
    bCount = 0
    cCount = 0
    dCount = 0

    while loopCount < len(userList):

        currentUser = userList[loopCount]
        
        currentUserAnswer = userDict[currentUser]
    
        if currentUserAnswer == 'A':
            aCount += 1
        elif currentUserAnswer == 'B':
            bCount += 1
        elif currentUserAnswer == 'C':
            cCount += 1
        elif currentUserAnswer == 'D':
            dCount += 1

        loopCount +=1
        
    return (aCount,bCount,cCount,dCount)
	
def graph_points(seq, userWidth, userHeight):
    root = Tk()
    c = Canvas(root,width=userWidth, height=userHeight, bg='white')
    c.pack()
    y_stretch = 15
    y_gap = 20
    x_stretch = 10
    x_width = 20
    x_gap = 20
    loopCount = 1
    for x, y in enumerate(seq):
        x0 = x * x_stretch + x * x_width + x_gap
        y0 = userHeight - (y * y_stretch + y_gap)
        x1 = x * x_stretch + x * x_width + x_width + x_gap
        y1 = userHeight - y_gap
        print x0
        if loopCount == 1:
                c.create_rectangle(x0, y0, x1, y1, fill="red")
                c.create_text(x0+5, y0, anchor=SW, text=str(y))
                c.create_text(x0+5, 322 , anchor=SW, text = 'A')
        elif loopCount == 2:
                c.create_rectangle(x0, y0, x1, y1, fill="green")
                c.create_text(x0+5, y0, anchor=SW, text=str(y))
                c.create_text(x0+5, 322 , anchor=SW, text = 'B')
        elif loopCount == 3:
                c.create_rectangle(x0, y0, x1, y1, fill="yellow")
                c.create_text(x0+5, y0, anchor=SW, text=str(y))
                c.create_text(x0+5, 322 , anchor=SW, text = 'C')
        elif loopCount == 4:
                c.create_rectangle(x0, y0, x1, y1, fill="blue")
                c.create_text(x0+5, y0, anchor=SW, text=str(y))
                c.create_text(x0+5, 322 , anchor=SW, text = 'D')
        loopCount +=1        
    mainloop()		


    
testPackets = ['08957b8903', '8123579700', '12375ba902', '123bc49001', '57dbc46701',
               '57dbc46702', '12375ba901', '123857ab00', '167857ff03', '1857987a03',
               '7b8a175c00', '12387b9002', '6729bca802', '5878cda703', '7571657801',
               '8587b7ac02', '9876543201', 'acef543201', '0000001101', '0000000102',
               '2345789300', '123789ab00', '8918915602', '1897418403', '8154984601',
               '874819ba01', '019874af02', '48abc84f01', '17897feb02', '849fcea301']




print(time.time())			   
testDict = parse(testPackets)

userIDList = genKeyList(testDict)

numAnswers = answerCount(testDict,userIDList)

userWidth = 325
userHeight = 325

print(time.time())
graph_points(numAnswers,userWidth,userHeight)




