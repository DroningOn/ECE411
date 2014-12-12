######################################################################################
#Wireless Apparatus for Realtime Classroom Feedback a.k.a. PSUCLASSBOY               #
#Team T-08 (Michael Schmidt, Chris Halseth, Kyle Lu, Matt Downey)                    #
#December 2014                                                                       #
#                                                                                    # 
#This software application provides a parser for incoming packets for                #
#a classroom clicker system. Packets are read over USB from the base station,        #
#parsed, and displayed in a bar graph for the professor. The software also outputs   #
#a .csv file of the responses to each poll for the professor to review later.        #
######################################################################################




#Import necessary modules
import time
from Tkinter import *
import serial
import csv

def main():

        #Initializing global variables
        global root
        global pollTime
        global GUIGraph
        global polling
        global defaultAns
        global baseStation
        global canvas
        global newWorkbook
        global writeCommand

        x = 0
        baseStation = serial.Serial()        
        #Set-up default values for GUI
        defaultTime = 15
        pollTime = defaultTime
        defaultAns = (0,0,0,0)

        #Initialize serial port
        while x < 10:
                try:
                        baseStation = serial.Serial(x,timeout = 0)
                        
                except serial.serialutil.SerialException:
                        pass
                x += 1
                if baseStation.isOpen():
                        print baseStation
                        break

        #Set-up GUI root window for GUI
        root = Tk()
        root.title('CLASSBOY')

        #On-close protocol for GUI window
        root.protocol("WM_DELETE_WINDOW", portClose)

        #Make frame non-resizable
        root.resizable(0,0)

        #Setup a new Excel file to write
        newWorkbook = open('ECE411_'+time.strftime('%H_%M_%S_%m%d%Y') + '.csv', 'wb') 
        writeCommand = csv.writer(newWorkbook, dialect = 'excel')
        
        #Set-up canvas for bar graph
        canvas = Canvas(root,width=625, height=625, bg='grey')
        canvas.pack()
        #Initialize GUI
        GUI(defaultAns,625,625)
        
        mainloop()

        
def portClose():
        """This method closes the serial port and destroys the GUI window when
        close is pressed"""
        
        global baseStation
        baseStation.close()
        root.destroy()

		
def changePollTime15():
        """Sets the polling time to 15 seconds"""
        global pollTime
        pollTime = 15
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime30():
        """Sets the polling time to 30 seconds"""
        global pollTime
        pollTime = 30
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime45():
        """Sets the polling time to 45 seconds"""
        global pollTime
        pollTime= 45
        pollCountDown.configure(text = str(pollTime))
        root.update()
        

def changePollTime60():
        """Sets the polling time to 60 seconds"""
        global pollTime
        pollTime = 60
        pollCountDown.configure(text = str(pollTime))
        root.update()

        
def newParse():
        """This  is the main method, it polls the serial input,
        parses the incoming packets,sorts the packets and graphs them in
        the GUI"""

        #Initialize globals used in this method
        global polling
        global baseStation
        global writeCommand

        #Flush all the inputs on the serial port before polling
        baseStation.flushInput()

        #Initialize empty lists and dictionary
        packetList = []
        userDict = {}
        userIDList = []

        #Initialize string variables for comparison in polling-loop
        currentPacket = ''
        oldPacket = ''
        #Reset canvas graphs to 0,0,0,0
        canvas.delete("all")
        barGraph(defaultAns,625,625)

        #Set loop variable
        polling = TRUE
        
        #Get current time for loop timing
        timer = time.time()
        root.iconify()

        #Polling Loop
        while polling:
                time.sleep(.1) #.1 second wait interval for proper packet grabbing
                currentPacket = baseStation.read(5) #Grab a packet
                currentPacket = currentPacket.encode('hex') #Re-encoded packet to a hex string
                print currentPacket
                #Check if the current packet is the same as the packet already stored
                if currentPacket != oldPacket and currentPacket != '':
                        #If packet is different, add packet to the list
                        packetList.append(currentPacket)
                oldPacket = currentPacket #set the packet just added to the list as an old packet so the packet is not written to the list multiple times
                currentTime = time.time() #Get current time
                checkTime = currentTime - timer #Compare time at start of loop for timing, ends loop when currentTime-timer = set polling time
                #Convert time for displaying on the GUI
                intCheckTime = int(checkTime)
                currentTimeLeft = str( pollTime - intCheckTime)
                pollCountDown.configure(text = currentTimeLeft)
                #Update GUI
                root.update()
                print packetList
                #If time runs out exit the loops
                if intCheckTime > pollTime:
                        polling = FALSE

        
        #Display Time up on the GUI
        pollCountDown.configure(text = "Time's Up!")
        root.update()

        #Parse the packets into a dictionary                
        userDict = parse(packetList)

        #Get the User ID's from the dictionary
        userIDList = genKeyList(userDict)

        #Get the number of each answer
        numAnswers = answerCount(userDict,userIDList)
        root.deiconify()
        

        #Delete the default from the GUI
        canvas.delete("all")
        #Graph the answers on the GUI
        barGraph(numAnswers,625,625)

        #Write the tuple of answers to the excel file
        writeCommand.writerow(numAnswers)
        

def endPolling():
        """Method for when the stop button is pressed"""
        global polling
        polling = FALSE
        
		
def parse(packets):
        """ This function receives a list of packets and separates
        them into their User ID and User Answer, and converts
        the answer into the corresponding letter(e.g A,B,C,D) for the response.
        It returns a dictionary of the User ID's (keys) and User 
        Answers (values).
        """
        
        #setting up variables
        loopCount = 0
        userData={}
        
        while loopCount < len(packets):
                
                
                newPack = packets[loopCount] #Gets the next packet in the list

                #Separate out User ID and Answer
                userID = newPack[0:8]
                userAnswer = newPack[8:10]
                
                #Check the Answer and creates a alphabetical response for the answer
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
                
                userData[userID] = alphaAnswer  #Create new dictionary entry 
                
                loopCount += 1
        return userData

		
def genKeyList(userDict):
        """ This function takes the dictionary of user data and returns a list of the
        user ID's """

        userIDList=userDict.keys()

        return userIDList
    
	
def answerCount(userDict,userList):
        """ This function gets a count of the answers from the dictionary of 
        user data, and returns a tuple of counts for each answer. """
        
        # setting up variables                
        loopCount = 0
        aCount = 0
        bCount = 0
        cCount = 0
        dCount = 0
        
        #Counts totals for each answer
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
    """Quick set-up method for all the GUI widgets"""    
    controls()
    GUIGraph = barGraph(seq,userWidth,userHeight)
        
		
def controls():
    """Set-up for all the GUI control"""    

    #Set-up for the menu bar    
    menubar = Menu(root)

    pollDuration = Menu(menubar,tearoff = 0)
    pollDuration.add_command(label='15 secs', command = changePollTime15)
    pollDuration.add_command(label='30 secs', command = changePollTime30)
    pollDuration.add_command(label='45 secs', command = changePollTime45)
    pollDuration.add_command(label='60 secs', command = changePollTime60)
    menubar.add_cascade(label='Polling Duration',menu = pollDuration)
    
    root.config(menu=menubar)

    #Set-up for the Start and Stop button 
    stopButton = Button(root,text = "Stop Polling", command = endPolling)
    stopButton.pack(side = RIGHT)    
    startButton = Button(root, text = "Start Polling", command = newParse)
    startButton.pack(side = RIGHT)

    #Convert polling time into string
    pollTimeStr = str(pollTime)

    #Set-up for countdown widget
    global pollCountDown
    pollCountDown = Label(root,text = pollTimeStr)
    pollCountDown.pack(side=BOTTOM) 
    
    #Text widget for time left
    timeLeft = Label(root,text = 'Time Left:')
    timeLeft.pack(side=BOTTOM)

                
def barGraph(seq, userWidth, userHeight):
    """ This function generates a bar graph of the answers"""

    totalAnswer = 0
    
    
    for item in seq:
        totalAnswer += item       
    
    if totalAnswer  == 0:
        totalAnswer = 1
            
        
    
    #Setting up the variables
    y_stretch = 575 /(totalAnswer)
    y_space = 20
    x_stretch = 30
    x_width = 120
    x_space = 20
    loopCount = 1
    percent ='0%'

    total = seq[0]+seq[1]+seq[2]+seq[3]
    total = float(total)
    
        #Generate bar for each answer

    for x, y in enumerate(seq):
            
        #Get dimensions of the bars to be graphed
        x0 = x * x_stretch + x * x_width + x_space
        y0 = userHeight - (y * y_stretch + y_space)
        x1 = x * x_stretch + x * x_width + x_width + x_space
        y1 = userHeight - y_space
        if total > 0:
                percent = y/total*100
                percent = "%0.2f" % percent
                stringY = "("+ str(y) + ")"
                percent = percent + "%" + stringY 

        #Graph each bar
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
              






#run program
if __name__== "__main__":
        main()
