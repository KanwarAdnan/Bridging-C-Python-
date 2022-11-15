import os
from ctypes import cdll , CDLL
from ctypes.util import find_library

current_dir = os.path.abspath(os.getcwd())
lib = (current_dir + "\\LinkedList\\LinkedList.dll")
linkedList = cdll.LoadLibrary(find_library(lib))

class LinkedList:
    def __init__(self)->None:
        '''
            1) isEmpty(self)    -> object:
                This method tells whether list is empty or not. It doesnt work for python scripts.

            2) isIndex(self,index : int)    -> object:
                This method tells whether the index is valid or not. It doesnt work for python scripts.

            3) getHead(self)   -> object:
                This method provides you the head of linkedlist. It won't be useful.

            4) getLast(self)    -> object:
                This method provides you the last node of linkedlist. It won't be useful.

            5) getNodeById(self,index : int)    -> object:
                This method provides the node at specific id. It doesnt work for python scripts.

            6) getFirst(self)   -> int:
                This method returns the first element.

            7) getLast_(self)   -> int:
                This method returns the last element.

            8) getElementById(self,index : int) -> object:
                This method returns the element at specific id.

            9) getMiddle(self)  -> int:
                This method returns the middle element.

            10) insertAtHead(self,value : int)  -> None:
                This method inserts a node at the head of the linkedlist.

            11) insertAtLast(self,value : int)  -> None:
                This method inserts a node at the last of the linkedlist.

            12) insertAtId(self,index : int, value : int)   -> None:
                This method inserts a node at the specific id in the linkedlist.
            
            13) print(self) -> None:
                This method prints the complete linkedlist.
            
            14) reverse(self)   -> None:
                This method reverses the complete linkedlist.

            15) printRev(self)  -> None:
                This method prints the linkedlist in reverse mode.

            16) getLength(self) -> int:
                This method returns the length of the linkedlist.

            17) doesExists(self,value : int)    -> object:
                This method tells whether an element exits or not in the linkedlist. This doens't work for python scripts.

            18) removeFirst(self)   -> None:
                This method removes the first element in the linkedlist.

            19) removeLast(self)    -> None:
                This method removes the last element in the linkedlist.

            20) removeById(self,index : int)    -> None:
                This method removes the element in the linkedlist at a specific index.

            21) removeByValue(self,value : int) -> None:
                This method removes the speicfic element from the linkedlist.

            22) deleteList()    -> None:
                This method deletes the complete linkedlist.
        '''
        pass

    def isEmpty(self)->object:
        """ This method tells whether list is empty or not. It doesnt work for python scripts."""
        return linkedList.isEmpty()

    def isIndex(self,index : int)->object:
        """ This method tells whether the index is valid or not. It doesnt work for python scripts."""
        return linkedList.isIndex(index)

    def getHead(self)->object:
        """ This method provides you the head of linkedlist. It won't be useful."""
        return linkedList.getHead()

    def getLast(self)->object:
        """ This method provides you the last node of linkedlist. It won't be useful."""
        return linkedList.getLast()

    def getNodeById(self,index : int)->object:
        """ This method provides the node at specific id. It doesnt work for python scripts."""
        return linkedList.getNodeById(index)

    def getFirst(self)->int:
        """ This method returns the first element."""
        return linkedList.getFirst()

    def getLast_(self)->int:
        """ This method returns the last element."""
        return linkedList.getLast_()

    def getElementById(self,index : int)->object:
        """ This method returns the element at specific id."""
        return linkedList.getElementById(index)

    def getMiddle(self)->int:
        """ This method returns the middle element."""
        return linkedList.getMiddle()

    def insertAtHead(self,value : int)->None:
        """ This method inserts a node at the head of the linkedlist."""
        return linkedList.insertAtHead(value)

    def insertAtLast(self,value : int)->None:
        """ This method inserts a node at the last of the linkedlist."""
        return linkedList.insertAtLast(value)

    def insertAtId(self,index : int, value : int)->None:
        """ This method inserts a node at the specific id in the linkedlist."""
        return linkedList.insertAtId(index , value)
    
    def print(self)->None:
        """ This method prints the complete linkedlist."""
        return linkedList.print()
    
    def reverse(self)->None:
        """ This method reverses the complete linkedlist."""
        return linkedList.reverse()

    def printRev(self)->None:
        """ This method prints the linkedlist in reverse mode."""
        return linkedList.printRev()

    def getLength(self)->int:
        """ This method returns the length of the linkedlist."""
        return linkedList.getLength()

    def doesExists(self,value : int)->object:
        """ This method tells whether an element exits or not in the linkedlist. This doens't work for python scripts."""
        return linkedList.doesExists(value)

    def removeFirst(self)->None:
        """ This method removes the first element in the linkedlist."""
        return linkedList.removeFirst()

    def removeLast(self)->None:
        """ This method removes the last element in the linkedlist."""
        return linkedList.removeLast()

    def removeById(self,index : int)->None:
        """ This method removes the element in the linkedlist at a specific index."""
        return linkedList.removeById(index)

    def removeByValue(self,value : int)->None:
        """ This method removes the speicfic element from the linkedlist."""
        return linkedList.removeByValue(value)

    def deleteList(self)->None:
        """ This method deletes complete linkedlist."""
        return linkedList.deleteList()

def test():
    # Making sure all the methods work
    l1 = LinkedList()

    # adding 6 
    l1.insertAtHead(1)
    l1.insertAtLast(2)
    l1.insertAtId(1,2)
    l1.insertAtHead(1)
    l1.insertAtLast(2)
    l1.insertAtId(1,2)

    # Removing 4
    l1.removeByValue(2)
    l1.removeFirst()
    l1.removeLast()
    l1.removeById(1)

    # Checking
    l1.isEmpty()
    l1.isIndex(1)

    # getting 8
    values = [
        l1.getElementById(1),
        l1.getFirst(),
        l1.getLast(),
        l1.getLast_(),
        l1.getLength(),
        l1.getMiddle(),
        l1.getNodeById(1),
        l1.getHead()
    ]

    print(values,len(values))

    # some others
    l1.reverse()
    l1.doesExists(1)

    # printing
    l1.print()
    l1.printRev()

    # deleting complete linkedlist
    l1.deleteList()

    print("\n\nThe Code Worked")
    print("\tCreated By Kanwar Adnan")

if __name__== "__main__":
    test()