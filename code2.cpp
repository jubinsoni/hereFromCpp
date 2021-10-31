#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        val = 0;
        next = NULL;
    }
};

void createList(Node** headptr,vector<int> &arr)
{
    Node* head = *headptr;
    Node* last = NULL;
    for(int i=0;i<arr.size();i++)
    {
        Node* newnode = new Node();
        newnode->val = arr[i];
        if(head == NULL)
        {
            head = newnode;
            last = head;
        }
        else
        {
            last->next = newnode;
            last = last->next;
        }
    }
    *headptr = head;
}

void printList(Node* head)
{
    Node* last = head;
    while(last != NULL)
    {
        cout << last->val << " ";
        last = last->next;
    }
    cout << endl;
}

void addAtHead(Node** headptr,int x)
{
    Node* head = *headptr;

    Node* newnode = new Node();
    newnode->val = x;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    *headptr = head;
}

void addAtLast(Node** headptr,int x)
{
    Node* head = *headptr;
    Node* last = *headptr;

    Node* newnode = new Node();
    newnode->val = x;

    if(last == NULL)
    {
        head = newnode;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
    }
    *headptr = head;
}

void addAtIndex(Node** headptr,int x,int ind)
{
    Node* head = *headptr;
    Node* last = *headptr;

    Node* newnode = new Node();
    newnode->val = x;

    if(ind == 0)
    {
        head = newnode;
    }
    else
    {
        while(ind > 1)
        {
            last = last->next;
            ind--;
        }
        newnode->next = last->next;
        last->next = newnode;
    }
    *headptr = head;
}

bool detectLoop(Node** headptr)
{
    Node* slow = *headptr;
    Node* fast = *headptr;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}

void createLoop(Node** headptr)
{
    Node* head = *headptr;
    Node* last = *headptr;

    while(last->next != NULL)
    {
        last = last->next;
    }

    //creating loop ... ponting again to head
    last->next = head->next;
}

void removeLoop(Node** headptr)
{
    Node* head = *headptr;
    Node* slow = *headptr;
    Node* fast = *headptr;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            break;
        }
    }

    fast = head;

    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(12);
    arr.push_back(14);
    arr.push_back(22);
    arr.push_back(27);

    Node* headptr = NULL;
    createList(&headptr,arr);
    printList(headptr);

    addAtHead(&headptr,4);
    printList(headptr);

    addAtLast(&headptr,4);
    printList(headptr);

    addAtIndex(&headptr,4,2);
    printList(headptr);

    cout << "detectLoop before creating loop => " << detectLoop(&headptr) << endl;
    createLoop(&headptr);
    cout << "detectLoop after creating loop => " << detectLoop(&headptr) << endl;
    removeLoop(&headptr);
    cout << "detectLoop after removing loop => " << detectLoop(&headptr) << endl;
    printList(headptr);

    return 0;
}