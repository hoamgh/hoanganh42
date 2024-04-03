#include<iostream>
using namespace std;

struct Node{
	int key;
	Node* next;
};

Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->key = data;
	newNode->next = NULL;
	return newNode;
}

void addHead(Node* &pHead, int data)
{
	Node* newNode = createNode(data);
	if (pHead == NULL)
	pHead = newNode;
	else{
		newNode->next = pHead;
		pHead = newNode;
	}
}

void addTail(Node* &pHead, int val){
	Node *newNode = createNode(val);
	if (pHead == NULL) pHead= newNode;
	else {
		Node *curNode = pHead;
		while (curNode -> next != NULL){
			curNode = curNode ->next;
		}
		curNode->next = newNode;
	}
} 

void removeHead (Node* &pHead){
	if (pHead != NULL){
		Node *nextNode = pHead->next;
		delete pHead;
		pHead = nextNode;
	}
}

void removeTail(Node *&pHead)
{
	if (pHead != NULL)
	{
		if (pHead->next == NULL)
		{
			delete pHead;
			pHead = NULL;
		}
		else 
		{
			Node *curNode = pHead;
			
			while(curNode->next->next != NULL)
				curNode = curNode->next;
				
			delete curNode->next;
			curNode->next = NULL;
			
		}
	}
	
}

void removeBeforeVal(Node *&pHead, int data)
{
	if(pHead != NULL && pHead->next != NULL)
	{
		Node *PrepreNode = NULL;
		Node *preNode = pHead;
		Node *curNode = pHead->next;
		while(curNode != NULL)
		{
			if(curNode->key == data)
			{
				if(preNode == pHead)
				{
					delete pHead;
					pHead = curNode;
				}
				else 
				{
					PrepreNode->next = curNode;
					delete preNode;
					preNode = curNode;
				}
			}
			PrepreNode = preNode;
			preNode = curNode;
			curNode = curNode->next;
		}
	}
}

void removeAfter (Node* &pHead, int val){
	if(pHead == NULL){
		return;
	}
	
	Node* curNode = pHead;
	
	while (curNode->next !=NULL && curNode->key != val){
		curNode = curNode->next;
	}
	
	if(curNode->next == NULL ){
		return;
	}
	Node* pTemp = curNode->next;
	curNode->next = pTemp->next;
	delete pTemp;
	pTemp = NULL;
}

bool addPos(Node*& pHead,int pos,int data)
{
	if(pos<0)
	return false;
	else
	{
		if(pos==0)
		addHead(pHead,data);
		else
		{
			Node* curNode = pHead;
			for(int i=0;i< pos-1; i++)
			{
				curNode=curNode->next;
				if(curNode==NULL)
				return false;
			}
			Node* newNode= createNode(data);
			newNode->next= curNode->next;
			curNode->next=newNode;
			
		}
	}
}

void addBefore(Node* &pHead, int data, int val){
	if(pHead == NULL) return;
	if(pHead->key == val){
		addHead(pHead, data);
		return;
	}
	
	Node* curNode = pHead;
	while(curNode->next != NULL){
		if(curNode->next->key == val){
			Node* newNode = createNode(data);
			newNode->next = curNode->next;
			curNode->next = newNode;
			return;
		}
		curNode = curNode->next;
	}
}

void RemovePos(Node*& pHead, int pos)
{
	if (pHead == NULL) return;
	if (pos == 0)
	{
		removeHead(pHead);
		return;
	}
	
	Node* pNode = pHead;
	
	for (int i = 0; i < pos - 1 && pNode->next != NULL; ++i, pNode = pNode->next);
	
	if (pNode->next == NULL) return;
	Node* newNextNode = pNode->next->next;
	delete pNode->next;
	pNode->next = newNextNode;
}

void addAfter (Node* &pHead, int data, int val)
{
	Node* newNode = createNode (data);
	
	Node* curNode = pHead;
	
	while (curNode != NULL && curNode -> key != val)
	{
		curNode = curNode -> next;
	}
	
	if (curNode != NULL)
	{
		newNode -> next = curNode -> next;
		curNode -> next = newNode;
	}
}


int countAppearance(Node* &pHead, int val){
	if (pHead == NULL)
	return 0;
	
	Node* cursor = new Node;	cursor = pHead;
	int* count = new int;
	
	for(*count = 0; cursor != NULL; cursor = cursor -> next){
		
		if (cursor -> key == val){
			*count +=1;
		}
		
		
	}
	
	delete cursor;
	return *count;
	
	
	//___
}
Node *reverseList (Node* pHead) {
	if (pHead != NULL) {
		Node* revList = NULL;
		Node* curNODE = pHead;
		while (curNODE != NULL) {
			addHead(revList, curNODE->key);
			curNODE = curNODE->next;
		}
	    return revList;
	}
}








void removeAll(Node *&pHead)
{	
	while (pHead != NULL)
		removeTail(pHead);
	
}

void printList(Node* pHead)
{
	Node* curNode = pHead;
	while(curNode != NULL)
	{
		cout << curNode->key << "->";
		curNode = curNode->next;
		if (curNode == NULL)
		cout << "NULL";
	}
}



int main()
{
	Node* pHead = NULL;
	addHead(pHead, 4);
	addHead(pHead, 3);
	addHead(pHead, 2);
	addHead(pHead, 1);
	addTail (pHead, 5);
	addTail (pHead, 3);
	addTail (pHead, 7);
	printList(pHead);
	cout << endl;
	Node * newList = reverseList(pHead);
	printList(newList);
	//removeTail (pHead);
	/*removeAfter(pHead, 1);
	printList (pHead);
	removeAfter(pHead, 3);
	printList (pHead);
	removeAfter(pHead, 6);
	printList (pHead);
	removeAfter(pHead, 7);*/
	/*addPos(pHead,0,8);
	addPos(pHead,8,8);
	addPos(pHead,5,8);
	*/
	/*RemovePos(pHead, 6);
	RemovePos(pHead, 0);
	RemovePos(pHead, 6);*/
	//printList (pHead);
	//addBefore(pHead, 7, 6);
	//cout << endl;
	//addAfter(pHead, 8, 7);
	//printList (pHead);
	//removeAll (pHead);
	//printList (pHead);
	//cout << endl << countAppearance(pHead, 3) << endl;
	return 0;
}
1
