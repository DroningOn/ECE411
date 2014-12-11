#Import necessary modules
import time
from Tkinter import *
import csv

def main():    
        global root
        global pollTime
        global GUIGraph
        global polling
        global defaultAns
        global newWorkbook       
        global writeCommand
        
        defaultTime = 60
        pollTime = defaultTime
        defaultAns = (0,0,0,0)
        
        root = Tk()
        root.title('CLASSBOY')
        root.protocol('WM_DELETE_WINDOW', closeProtocol)
        root.resizable(0,0)
        newWorkbook = open(time.strftime('%m%d%Y') + '.csv','wb')
        writeCommand = csv.writer(newWorkbook, dialect = 'excel')
        
        global canvas
        canvas = Canvas(root,width=625, height=625, bg='grey')
        canvas.pack()
        GUI(defaultAns,625,625)
        mainloop()

def closeProtocol():
        newWorkbook.close()
        root.destroy()
        
        
def changePollTime15():
        global pollTime
        pollTime = 15
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime30():
        global pollTime
        pollTime = 30
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime45():
        global pollTime
        pollTime= 45
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime60():
        global pollTime
        pollTime = 60
        pollCountDown.configure(text = str(pollTime))
        root.update()

        
def newParse():
        global polling
        global writeCommand
        canvas.delete("all")
        barGraph(defaultAns,625,625)
        polling = TRUE
        timer = time.time()
        

        while polling:
                currentTime = time.time()
                checkTime = currentTime - timer
                intCheckTime = int(checkTime)
                currentTimeLeft = str( pollTime - intCheckTime)
                pollCountDown.configure(text = currentTimeLeft)
                root.update()
                
                if intCheckTime > pollTime:
                        polling = FALSE

        pollCountDown.configure(text = "Time's Up!")
        root.update()
        testPackets = ['08957b8903', '8123579700', '12375ba902', '123bc49001', '57dbc46701',
                       '57dbc46702', '12375ba901', '123857ab00', '167857ff03', '1857987a03',
                       '7b8a175c00', '12387b9002', '6729bca802', '5878cda703', '7571657801',
                       '8587b7ac02', '9876543201', 'acef543201', '0000001101', '0000000102',
                       '2345789300', '123789ab00', '8918915602', '1897418403', '8154984601',
                       '874819ba01', '019874af02', '48abc84f01', '17897feb02', '849fcea301']

        testDict = parse(testPackets)
        userIDList = genKeyList(testDict)
        numAnswers = answerCount(testDict,userIDList)
        barGraph(numAnswers,625,625)
        writeCommand.writerow(numAnswers)

      
                        
        

def endPolling():
        global polling
        polling = FALSE
        
def parse(packets):
        """ This function receives a list of packets and separates
        them into their User ID and User Answer, and converts
        the answer into the corresponding letter for the response.
        It returns a dictionary of the User ID's (keys) and User 
        Answers (values).
        """
        
        #setting up variables
        loopCount = 0
        userData={}
        
        while loopCount < len(packets):
                #Gets the next packet in the list
                newPack = packets[loopCount] 
                #Separate out User ID and Answer
                userID = newPack[0:8]
                userAnswer = newPack[8:10]
                #Check the Answer and create a alphabetical response for the answer
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
                #Create new dictionary entry 
                userData[userID] = alphaAnswer  
                loopCount += 1
        return userData

def genKeyList(userDict):
        """ This function takes the dictionary of user data returns a list of the
        user ID's """
        
        userIDList=userDict.keys()
        return userIDList
    
def answerCount(userDict,userList):
        """ This function gets a count of the the answers from the dictionary of 
        user data, and returns a tuple of counts for each answer. """
        
        # setting up variables                
        loopCount = 0
        aCount = 0
        bCount = 0
        cCount = 0
        dCount = 0

        while loopCount < len(userList):
                        
                        #get an ID
                currentUser = userList[loopCount]
                
                        #get that ID's answer
                currentUserAnswer = userDict[currentUser]
                        
                        #increment the count for that answer
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

def GUI(seq,userWidth,userHeight):
    controls()
    GUIGraph = barGraph(seq,userWidth,userHeight)





        
def controls():

    menubar = Menu(root)

    pollDuration = Menu(menubar,tearoff = 0)
    pollDuration.add_command(label='15 secs', command = changePollTime15)
    pollDuration.add_command(label='30 secs', command = changePollTime30)
    pollDuration.add_command(label='45 secs', command = changePollTime45)
    pollDuration.add_command(label='60 secs', command = changePollTime60)
    menubar.add_cascade(label='Polling Duration',menu = pollDuration)
    
    root.config(menu=menubar)

    stopButton = Button(root,text = "Stop Polling", command = endPolling)
    stopButton.pack(side = RIGHT)    
    startButton = Button(root, text = "Start Polling", command = newParse)
    startButton.pack(side = RIGHT)

    pollTimeStr = str(pollTime)

    global pollCountDown
    pollCountDown = Label(root,text = pollTimeStr)
    pollCountDown.pack(side=BOTTOM) 
    
    timeLeft = Label(root,text = 'Time Left:')
    timeLeft.pack(side=BOTTOM)

                
        
        
def barGraph(seq, userWidth, userHeight):
    """ This function generates a bar graph of the answers"""
    



        
        #Setting up the variables
    y_stretch = 5
    y_gap = 20
    x_stretch = 30
    x_width = 120
    x_gap = 20
    loopCount = 1
    percent = '0%'

    total = seq[0]+seq[1]+seq[2]+seq[3]
    total = float(total)
        
        #Generate bar for each answer

    for x, y in enumerate(seq):

        x0 = x * x_stretch + x * x_width + x_gap
        y0 = userHeight - (y * y_stretch + y_gap)
        x1 = x * x_stretch + x * x_width + x_width + x_gap
        y1 = userHeight - y_gap
        if total > 0.00001:
                percent = y/total*100
                percent = "%0.2f" % percent
                stringY = "("+ str(y) + ")"
                percent = percent + "%" + stringY
        
        if loopCount == 1:
                canvas.create_rectangle(x0, y0, x1, y1, fill="blue")
                canvas.create_text(x0, y0, anchor=SW, text=percent)
                canvas.create_text(x0+25, 622 , anchor=SW, text = 'A')
        elif loopCount == 2:
                canvas.create_rectangle(x0, y0, x1, y1, fill="green")
                canvas.create_text(x0, y0, anchor=SW, text=percent)
                canvas.create_text(x0+25, 622 , anchor=SW, text = 'B')
        elif loopCount == 3:
                canvas.create_rectangle(x0, y0, x1, y1, fill="yellow")
                canvas.create_text(x0, y0, anchor=SW, text=percent)
                canvas.create_text(x0+25, 622 , anchor=SW, text = 'C')
        elif loopCount == 4:
                canvas.create_rectangle(x0, y0, x1, y1, fill="red")
                canvas.create_text(x0, y0, anchor=SW, text=percent)
                canvas.create_text(x0+25, 622 , anchor=SW, text = 'D')
        loopCount +=1       
              






if __name__== "__main__":
        main()
