from websocket import create_connection
from threading import Thread

URL = input('Enter URL : ')

connection = create_connection(URL)

user = input('Enter the user-name : ')
status = input("Enter status : ")

connection.send("add-user(())"+user+"(())"+status+"\n")


class ChatReceiver(Thread):

    def __init__(self, ws) :
        Thread.__init__(self)
        self.ws = ws
    
    def run(self):

        while True :

            data = self.ws.recv()
            if data : 
                print('>>>', data, '\n')


ChatReceiver(connection).start()

while True : 

    message = input(">>>")

    connection.send("Message(())"+user+"(())"+message+"\n")


