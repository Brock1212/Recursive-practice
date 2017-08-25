// File Name: assign4_bcy3.cpp
//
// Author: Brock Yarbrough
// Date: 03/27/2015
// Assignment Number: 4
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// This file checks the functionality of 5 recursive functions without using loops.
//

#include<iostream>
#include<cassert>
#include<iomanip>

using namespace std;

struct Node {
	int value;
	Node *next;
	};

void tableOfSquares(int);
float power(float, int);
bool isMember(int [], int, int);
int maxNode(Node *);
int maxNodeRec(Node *);
bool palindrome(string);

int main()
{
    cout << "***Table of squares test 1(5)***" << endl;
	tableOfSquares(5);
	cout << endl << "***Table of squares test 2(10)***" << endl;
    tableOfSquares(15);

    cout << endl << "***Power test 1(2^5)***" << endl;
    cout << power(2,5) << endl;
    cout << "***Power test 2(8^3)***" << endl;
    cout << power(8,3) << endl;
    cout << "***Power test 3(4.7^4)***" << endl;
    cout << power(4.7,4) << endl;

    int array[10] = {0,1,22,3,42,54,6,78,8,29};
    int target1 = 22;
    int target2 = 44;
    int target3 = 29;

    cout << endl <<"Array being used for testing {0,1,22,3,42,54,6,78,8,29}" << endl;

    cout << "***isMember test 1(target 22)***" << endl;
    if (isMember(array,10,target1))
       cout << target1 << " is in the array" << endl;
    else
       cout << target1 << " is not in the array" << endl;

     cout << "***isMember test 2(target 44)***" << endl;
     if (isMember(array,10,target2))
     	cout << target2 << " is in the array" << endl;
     else
    	 cout << target2 << " is not in the array" << endl;

     cout << "***isMember test 3(target 29)***" << endl;
     if (isMember(array,10,target3))
      	cout << target3 << " is in the array" << endl;
     else
    	 cout << target3 << " is not in the array" << endl;


     Node *head = NULL;

     Node *newNode = new Node;
     newNode->value = 12;
     newNode->next = NULL;
     head = newNode;

     newNode = new Node;
     newNode->value = 37;
     newNode->next = NULL;
     head -> next = newNode;

     newNode = new Node;
     newNode->value = 8;
     newNode->next = NULL;
     head -> next->next = newNode;

     newNode = new Node;
     newNode->value = 78;
     newNode->next = NULL;
     head -> next->next->next = newNode;

     newNode = new Node;
     newNode->value = 64;
     newNode->next = NULL;
     head -> next->next->next->next = newNode;

     newNode = new Node;
     newNode->value = 52;
     newNode->next = NULL;
     head -> next->next->next->next->next = newNode;

     cout << endl << "max node of {12,37,8,78,64,52} is " << maxNode(head) << endl;
     cout << endl;

     cout << "***Palindrome Test 1***" << endl;
     cout << "Is 'Do geese see God' a palindrome?: ";
     if(palindrome("Do geese see God"))
    	 cout << "yes" << endl;
     else
    	 cout << "no" << endl;

     cout << "***Palindrome Test 2***" << endl;
     cout << "Is 'abracadabra' a palindrome?: ";
     if(palindrome("abracadabra"))
         cout << "yes" << endl;
     else
         cout << "no" << endl;


	return 0;
}

//***********************************************************
// void tableOfSquares (int n): writes a table of numbers and
// there square up until the number specified
//
// param-1 int n, the last number in the table
//
// returns: nothing, void
//***********************************************************
void tableOfSquares (int n)
{
	if (n > 0)
	{
		tableOfSquares(n-1);
		cout << n << setw(5) << (n*n) << endl;
	}
}

//***********************************************************
// float power(float number, int p): raises a number sent to
// the function by the power sent to the function
//
// param-1 float number, the number being multiplied
// param-2 int p, the power the float number is being raised to
//
// returns: number raised to the specified power
//***********************************************************
float power(float number, int p)
{
	if (p == 0)
		return 1;
	else
		return number * power(number, p-1);
}

//***********************************************************
// bool isMember(int array[], int size, int target): finds
// out if a number is part of an array sent to it
//
// param-1 int array, the list being looked through
// param-2 int size, size of the array
// param-3 int target, the number being looked for in the list
//
// returns: true if target is a member of the array
//***********************************************************
bool isMember(int array[], int size, int target)
{
	if (array[size] == target)
	   return true;
	else if (size == 0)
		return false;
	else
		return isMember(array,size-1, target);

}

//***********************************************************
// int maxNode(Node *first): makes sure a list sent to it isnt
// empty and then calls function to search for the node with
// the highest value
//
// param-1 Node *first, pointer to the firt node of the list
//
// returns: maximum value in the list
//***********************************************************
int maxNode(Node *first)
{
	assert(first != NULL);
	return maxNodeRec(first);
}

//***********************************************************
// int maxNodeRec(Node *first): searches for the node with
// the highest value
//
// param-1 Node *first, pointer to the firt node of the list
//
// returns: maximum value in the list
//***********************************************************
int maxNodeRec(Node *first)
{
	if (first == NULL)
			return 0;
	else
	{
		if (first->value > maxNodeRec(first->next))
			return first->value;
		else
			return maxNodeRec(first->next);
	}
}

//***********************************************************
// bool palindrome(string n: checks if a string is a palindrome
//
// param-1 string n, string being checked
//
// returns: true if the string is a palindrome
//***********************************************************
bool palindrome(string n)
{
	if (n.size() == 0 || n.size() == 1)
		{
			return true;
		}

	int size = n.size();
	char first = tolower(n[0]);
	char last = tolower(n[size-1]);

	if(first == last)
	{
		return palindrome(n.substr(1,size-2));
	}
	else if(isspace(first))
		return palindrome(n.substr(1,size));
	else if (isspace(last))
		return palindrome(n.substr(0,size - 1));
	else
	    return false;
}
