//
//  priority queue.cpp
//  queue
//
//  Created by nimrat bedi on 16/08/18.
//  Copyright © 2018 nimrat bedi. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data,prt;
    node *next;
};
class queue{
    node *head;
public:
    queue()
    {
        head=NULL;
    }
    void create(int a,int b)
    {
        node *nn=new node;
        nn->next=NULL;
        nn->data=a;
        nn->prt=b;
        head=nn;
    }
    void enqueue(int a,int b)
    {
        if(head==NULL)
        {
            create(a,b);
        }
        else
        {
            node *ptr=head;
            node *ptr2;
            while(ptr!=NULL && b>ptr->prt)
            {
                ptr2=ptr;
                ptr=ptr->next;
            }
            if(ptr==head)
            {
                node *nn=new node;
                nn->data=a;
                nn->prt=b;
                nn->next=head;
                head=nn;
            }
            else if(ptr==NULL)
            {
                node *ptr1=head;
                while(ptr1->next!=NULL)
                {
                    ptr1=ptr1->next;
                }
                node *nn=new node;
                nn->data=a;
                nn->prt=b;
                nn->next=NULL;
                ptr1->next=nn;
            }
            else
            {
                node *nn=new node;
                nn->data=a;
                nn->prt=b;
                nn->next=ptr;
                ptr2->next=nn;
            }
        }
    }
    void dequeue()
    {
        node *ptr=head;
        head=head->next;
        delete(ptr);
    }
    void traverse()
    {
        node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
};
int main()
{
    queue q;
    q.enqueue(10,3);
    q.enqueue(20,1);
    q.enqueue(30,5);
    q.enqueue(40,4);
    q.enqueue(50,2);
    q.dequeue();
    q.traverse();
}
