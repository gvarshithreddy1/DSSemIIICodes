#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LL
{
    public:
        int count = 0;
        LL()
        {
            head = nullptr;
            int count = 0;
        }

        //methods for inserting data
        void insertEnd(int data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;

            if(head == nullptr)
            {
                head = newNode; 
            }
            else
            {
                Node *current = head;
                while(current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
            count++;
            
        }

        void insertFront(int data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;

            if(head != nullptr)
            {
                Node *current = head;
                newNode->next = current;
                head = newNode;
            }
            else{
                head = newNode;
            }
            count++;


        }

        void insert(int data, int position)
        {
            if(position==1)
                insertFront(data);

            else if(position > count)
            {
                
                cout<< "Linked list has only "<< count << " nodes. But your position exceeded the size.(max = " << count+1 << " )"<< endl;
                count--;
            }
            else{
                Node *newNode = new Node();
                newNode->data = data;
                newNode->next = nullptr;

                Node *current = head;
                for(int i =1; i < position -1; i++)
                {
                    current = current->next;
                }
                Node *temp = current->next;
                current->next = newNode;
                newNode->next = temp;

            }
            count++;           
        }


        //methods for DELETION
        void deleteFront()
        {
            if(head == nullptr)
            {
                cout << "Cannot delete elements from empty list. " << endl;
            }
            else{
                Node *current = head;
                head = current->next;
                current = nullptr;
                count--;
            }

        }

        void deleteEnd()
        {
            if(head == nullptr)
            {
                cout << "Cannot delete elements from empty list. " << endl;
            }
            else{
                Node *current = head;
                Node *current1 =nullptr;
                while(current->next != nullptr)
                {
                    current1 = current;
                    current = current->next;
                }
                current1->next = nullptr;
                count--;
            }
            
        }

        void deletePos(int position)
        {
            if(head == nullptr)
            {
                cout << "Cannot delete elements from empty list. " << endl;
            }
            else{
                if(position == 1)
                {
                    deleteFront();
                }
        
                else{
                    Node *current = head;
                    for(int i = 1; i < position-1; i++)
                    {
                        current = current->next;
                    }
                    Node *delNode = current->next;
                    current->next = delNode->next;
                    count--;
                }
                

            }
        }


        int size()
        {
            return count;
        }

        void reverse()
        {
            if(head == nullptr)
            {
                cout << "Can't reverse an empty linked list." << endl;
            }
            else
            {
                Node *current = head;
                Node *prev = nullptr;
                Node *next = nullptr;
                while(current != nullptr)
                {
                    
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }
                head = prev;
            }
        }


        void print()
        {
            if(head == nullptr)
            {
                cout << "The linked list is empty" << endl;
            }
            else{
                Node *current = head;
                while(current->next != nullptr)
                {

                    cout << current->data << " --> ";
                    current = current->next;
                }
                cout << current->data << " --> null" << endl;
            }
        }


    private:
        Node *head;
};



int main()
{
    LL newll;

    newll.insertEnd(1);
    newll.insertEnd(2);
    newll.insertEnd(3);
    newll.insertFront(5);
    newll.insert(6,4);
    newll.print();
    newll.reverse();
    newll.print();
    newll.deleteFront();
    newll.print();
    newll.deletePos(1);
    newll.print();
    newll.deleteEnd();
    newll.print();
    cout << newll.size() << endl;
    LL ll2;
    ll2.print();
    ll2.deleteFront();
    return 0;
}