/*
Problem : Create a singly linked list that does the following:

			 1> create nodes based on user input
			 
			 2> add a node at 
			 	a> Start
			 	b> End
			 	c> at any other point
	
			 3> print the list according to following inputs
			 	a> all the nodes
			 	b> till specific index
			 	c> a specific range, with a start and end point
			
			 4> Search for a specific node.
			 
			 5> Delete any node.
			 
			 
*/


#include <iostream>
using namespace std;


// pre req: the structure for a singly linked list of data type integer.
struct Node{
	int data;
	Node* next;
};


// Task 1 --- Create nodes as per the request of the user.
Node* addNodes()
{
	int n;
	cout<< "How many nodes should be there?"<< endl;
	cin >> n;
	
	if(n==0)
	{
		cout <<" No nodes created!";
		return nullptr;
	}
	
	int value;
	cout << " What should be the value of the first node?"<< endl;
	cin >> value;
	
	Node* head = new Node;
	head->data = value;
	head->next = nullptr;
	
	Node* current = head;
	
	for(int i= 2; i<= n; i++)
	{
		cout << " Enter the value of your new node: "<< endl;
		cin >> value;
		
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
	
		current->next = newNode;
		current = newNode;
	}
	
	cout<< "LIST CREATED!"<< endl;
	return head;
}

// Task 2 A --- add at the start of the list
Node* addAtStrt( Node* start, int value)
{
	Node* newNode = new Node;
 	newNode->data = value;
 	newNode->next = start;
 	start = newNode;
 	
 	cout << "Task Executed!"<< endl;
 	return newNode;
 	
}

// Task 2 B --- add at the end of the list
Node* addAtEnd(Node* end, int value)
{

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	end->next = newNode;
	
	cout << "Task Executed!"<< endl;
	return newNode;
}

// Task 2 C --- add at specific point
Node* addAtChc( Node* temp, int mid, int value)
{

	while(temp!= nullptr)
	{
		
		if(temp->data == mid)
		{
			Node* newNode= new Node;
			newNode->data = value;
			newNode->next = temp->next;
			temp->next = newNode;
			cout << "Task Executed!"<< endl;
			return newNode;
		
		}
		temp= temp->next;
	}
	cout << " Value "<< mid << " not found. Hence no node is added." << endl;
	return nullptr;
}


// Task 3 A --- Print all nodes
void printListAll(Node* start)
{	
	cout << "The list is printed as following: "<< endl;
	while(start!=nullptr)
	{
		cout << start->data<<" ";
		start = start->next;
	}
	cout << "Task Executed!"<< endl;
}



// Task 3 B --- Print till specific index from start
void printListSp(Node* start, int end)
{
	if (start == nullptr)
	{
		cout<< "list is shorter than given index!"<< endl; // To avoid the list becomming zero when user enters a bigger number
		return;
	}
	cout << "The list is printed from 1 index till " << end << endl;
	for(int i=1; i<= end && start != nullptr; i++)
	{
		cout << start->data<<" ";
		start = start->next;

		if (start == nullptr && i<= end)
		{
		cout << "\n List ended before index"<< end << endl;
		
		return;
		
		}
	}
	cout << "Task Executed!"<< endl;

}


// Task 3 C --- Print from a specific start and ending
void printlistRng(Node* start, int strt, int end)
{

	if(strt > end)
	{
		cout << "invalid range(start > end)"<< endl;
		return;
	}
	cout << "The list is printed from " << strt << "index till " << end << endl;
	int num= 1;
	
	while( start != nullptr && num < strt)
	{
		start = start->next;
		num++;
	}
	
	while(start!= nullptr && num <= end)
	{
		cout << start->data<< " ";
		start = start->next ;
		num++;
	}
	cout << "\n Task Executed!"<< endl;
	
	

}

//Task 4 --- Search for any value
void srchVal(Node* start, int value)
{
	Node* temp = start;
	int n=1;
	bool state = false;
		while(temp!= nullptr)
		{
			if(temp->data == value)
			{
				cout<< " Value is found, its index is: "<< n << endl;
				state = true;
			}
			
			n++;
			temp= temp->next;
		}
		if(state == false)
		{
			cout<< "Value is not found!"<< endl;
		}
		
		return ;
}
	
//task 5 --- delete value
Node* delValue(Node* head, int value)
{
	if (head == nullptr)
		return nullptr;
	
	else if(head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
		} 
	else
	{
	
		Node* current = head;
		bool found = false;
		while( current!= nullptr && current->next != nullptr)
		{
			if (current->next->data == value)
				{
					Node* temp = current->next ;
					current->next = temp->next ;
					delete temp;
					found = true;
 					break;
				
				}
			current = current->next;
			
		}
		if (!found) // to check if the value is nullptr then atleast we have something to show
			{
				cout << "Incorrect values!"<< endl;
			}
		else
		{
			cout << "Task Executed!"<< endl;
		}
		return head;
	}
	
}

// Extra deleting function to clean the memory
void deleteList(Node* head)
{
	while (head!= nullptr)
	{
		Node * temp= head;
		head = head->next ;
		delete temp;
	}
	cout <<"All nodes, deleted memory is now free." << endl;
}





// The main function with the menue

int main()
{
	Node* head = nullptr;
	int choice, value, position, startIdx, endIdx, midVal;
	
	do{
		cout<< "\n ------- LINKED LIST MENU --------\n";
		cout<< "1_ Create nodes"<< endl;
		cout<< "2_ Add node at start"<< endl;
		cout<< "3_ Add node at end"<< endl;
		cout<< "4_ Add node after a given value"<< endl;
		cout<< "5_ Print all nodes"<< endl;
		cout<< "6_ Print till a specific index"<< endl;
		cout<< "7_ Search for a value"<< endl;
		cout<< "8_ Delete a value"<< endl;
		cout<< "9_ Print from a specific node till specific endpoint"<< endl;
		cout<< "0_ Exit"<< endl;
		cout<< "Enter your choice: "<< endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				head = addNodes();
				break;
			
			case 2:
				cout << "Enter value to add at start: "<< endl;
				cin >> value;
				head = addAtStrt(head, value);
				break;
				
			case 3:
				if(head == nullptr)
				{
					cout << "List is empty! Creating first node instead."<< endl;
					cout << "enter value: "<< endl;
					cin >> value;
					head = addAtStrt(head, value);
				}
				else
				{
					cout << "Enter value to add at end: "<< endl;
					cin >> value;
					
					{
						Node* temp = head;
						while(temp->next != nullptr)
							temp = temp->next;
						addAtEnd(temp, value);
					}
				}
				break;
				
			case 4:
				cout << "Enter Value after which to insert: "<< endl;
				cin >> midVal;
				cout << "Enter new node Value: "<< endl;
				cin >> value;
				addAtChc(head, midVal, value);
				break;
				
			case 5:
				printListAll(head);
				break;
			
			case 6:
				cout << "Enter index till which to print: "<< endl;
				cin >> endIdx;
				printListSp(head, endIdx);
				break;
				
			case 7:
		
				cout << "Enter value to search:"<< endl;
				cin >> value; 
				srchVal(head, value);
				break;
				
			case 8:
				
				cout << "Enter value to delete: "<< endl;
				cin >> value;
				head = delValue(head, value);
				break;
				
			case 9:
				cout << "Enter start Index: "<< endl;
				cin >> startIdx;
				cout <<"Enter end Index: "<< endl;
				cin >> endIdx;
				printlistRng(head, startIdx, endIdx);
				break;

			case 0:
				cout<< "Exiting program"<< endl;
				break;
			
			default:
				cout <<" Invalid choice! Try again!"<< endl;
			
		}
		
	} while (choice != 0);
	deleteList(head);
	return 0;

}
