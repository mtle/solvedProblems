""" Define Node """
class Node:
#	def __init__ (self) :
#		self.data = None
#		self.next = None """
	def __init__ (self, data=None, node = None) :
		self.data = data
		self.next = node
#	def __init__ (self, data, node) :
#		self.data = data
#		self.next = node """        
""" end Node """

class LinkedList:
	def __init__ (self) :
		self.head = Node()
		self.tail = self.head
		self.count = 0
		
	def addNode(self, data) :
		node = Node(data, None)
		if (self.head == None) :
			self.head.next = node
			self.tail = node
		else:
			node.next = self.head.next
			self.head.next = node
		self.count += 1
		
	def deleteNode(self, key) :
		if ( self.head == None ) :
			return
		prev = None
		a = self.head
		while ( a != None ) :
			prev = a
			if ( a.data == key ) :
				prev.next = a.next
				break
			a = a.next

	def to_string(self) :
		result = ""
		curr = self.head.next
		
		result = result + "["
		
		while curr :
			result = result + str(curr.data)
			result = result + "]->"
			curr = curr.next

		result = result + "[null]"
		print (result)

	def printList(self) :
		a = self.head.next
		while ( a ):
		#while ( a != None ):
			print( a.data );
			#print("[" + a.data + "]->");
			a = a.next
		print ("[null]")
		
def main():
	l = LinkedList()
	l.addNode(10)
	l.addNode(20)
	l.printList()
	l.to_string()
	
if __name__ == "__main__":
    # execute only if run as a script
    main()

		

