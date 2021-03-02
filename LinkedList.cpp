#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL; //these could be 0s but NULL means absolute nothingness
    this->tail = NULL;
    this-> count = 0; 
}

void LinkedList::display()
{
    if(this->count == 0)
    {
        cout << "the empty list" << endl;
    }
    else 
    {
        Node* currNode = this->head; //curNode and head point to the same place in memory
        while(currNode->getNextNode() != NULL)
        {
            //cout << currNode << "->"; --this shows the memory addresses
            cout << currNode->getPayload() << "->";
            currNode = currNode->getNextNode();
        }
        cout << currNode->getPayload() << endl;

    }
}

void LinkedList::addEnd(int value)
{
    Node* n = new Node(value);
    if(head == NULL)
    {
        //we have the empty list
        this->head = n;
        this->tail = n;
    }
    else 
    {
        //we have a list with at least one element in it, and we know that tail points to the
        //end of the list
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::removeEnd()
{
    if(this-> count > 0)
    {
        
        Node* n = this->tail;
        int value = n->getPayload();

        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
        }  
        else
        {
            Node* currNode = this->head;
            while(currNode->getNextNode() != tail)
            {
                currNode = currNode->getNextNode();
            }
            this->tail = currNode;
            this->tail->setNextNode(NULL);
        }


        this->count--;
        delete(n);
        return value;
    }
}
void LinkedList::addFront(int value)
{
    Node* n = new Node(value);
    if(head == NULL)
    {
        //we have the empty list
        this->head = n;
        this->tail = n;
    }
    else 
    {
        //we have a list with at least one element in it, and we know that tail points to the
        //end of the list
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

int LinkedList::removeFront()
{
    if(this-> count > 0)
    {
        Node* n = this->head;
        int value = n->getPayload();

        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
        }  
        else
        {
            Node* currNode = this->head;
            currNode = this->head->getNextNode();
            this->head = currNode;
        }


        this->count--;
        delete(n);
        return value;
    }
}
