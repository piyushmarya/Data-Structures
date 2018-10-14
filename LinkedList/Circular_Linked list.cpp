#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
class circular_linked_list
{
	public:
    node *head,*tail;
    circular_linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_beg();
    void display();
    void insert2();
    void deletion();
    void searching();
};
node* createnode(int x)
{
    node *temp=new node;
    temp->info=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void circular_linked_list::insert_beg()
{
    int n;
    cout<<"Enter the no. of elements you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        node *p,*ptr;
        p=createnode(ele);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            p->next=head;
            head->prev=p;
            head=p;
        }
    }
    tail->next=head;
    head->prev=tail;
}
void circular_linked_list::insert2()
{
    int ch,ele,x;
    cout<<"\n Enter choice: \n 1 for insertion in beginning \n 2 for insertion at end \n 3 for insertion in between \n";
    cin>>ch;
    node *p=NULL,*temp,*ptr;
    while(ch!=0)
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter the element to add: ";
            cin>>ele;
            p=createnode(ele);
            p->next=head;
            head->prev=p;
            head=p;
            tail->next=head;
            head->prev=tail;
            break;
        case 2:
            cout<<"Enter the element to add: ";
            cin>>ele;
            p=createnode(ele);
            tail->next=p;
            p->prev=tail;
            tail=p;
            tail->next=head;
            head->prev=tail;
            break;
        case 3:
            cout<<"\n Enter an element you want to add: ";
            cin>>ele;
            cout<<"Enter the element after you want to add: ";
            cin>>x;
            p=createnode(ele);
            ptr=head;
            while(ptr->info!=x)
            {
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=p;
            p->prev=ptr;
            temp->prev=p;
            p->next=temp;
            break;
        default:
            cout<<"Wrong choice\nPlease enter 1-3 else 0 to exit.";
            break;
        }
        cout<<"\n Enter choice to insert: ";
        cin>>ch;
    }
    cout<<"\n Element Inserted";
}
void circular_linked_list::deletion()
{
    int ele;
    cout<<"\n Enter an element you want to delete: ";
    cin>>ele;
    node *temp,*p;
    p=head;
    if(head->info==ele)   
    {
        head=head->next;
        tail->next=head;
        head->prev=tail;
    }
    else if(tail->info==ele)  
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
    }
    else                 
    {
        while(p->info!=ele)
        {
            p=p->next;
        }
        temp=p->prev;
        temp->next=p->next;
        p->next->prev=temp;
    }
    cout<<"\nElement deleted";

}
void circular_linked_list::searching()
{
    int ele;
    cout<<"Enter element you want to search: ";
    cin>>ele;
    node *p;
    p=head;
    while(p->info!=ele && p->next!=head)
    {
        p=p->next;
    }
    if(p->info==ele)
        cout<<"\n Node exists";
    else
        cout<<"\n Node does not exist";
}

void circular_linked_list::display()
{
    node *ptr=head;
    if(head==NULL)
        cout<<"Linked List is empty";
    else
        while(ptr->next!=head)
        {
            cout<<ptr->info<<"->";
            ptr=ptr->next;
        }
        cout<<ptr->info;
}
int main()
{
    int ch;
    circular_linked_list l1;
    l1.insert_beg();
    cout<<"\nEnter choice:\n1 for insertion\n2 for deletion\n3 for searching\n4 for display\n";
    cin>>ch;
    while(ch!=0)
    {
        switch(ch)
        {
        case 1:
            l1.insert2();
            break;
        case 2:
            l1.deletion();
            break;
        case 3:
            l1.searching();
            break;
        case 4:
            l1.display();
            break;
        default:
            cout<<"\n Wrong choice \n";
            break;
        }
        cout<<"\n Enter choice again: \n 1 for insertion \n 2 for deletion \n 3 for searching \n 4 for display  \n";
        cin>>ch;
    }
}
