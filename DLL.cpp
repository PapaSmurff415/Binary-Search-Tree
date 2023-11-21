#include <iostream>
using namespace std;

class node // creating a node
{
public:
    int value;
    node *next;
    node *prev; // Add a pointer for the previous node
};

void PrintList(node *head);
void AddFront(node **head, int NewValue);
void AddEnd(node **head, int NewValue);
void AddAfter(node *previous, int NewValue);

void DelFront(node **head);
void DelEnd(node **head);
void DelAfter(node *prev);

int main()
{
    // initialize node and allocate mem;
    node *head = new node(); // or node *first=new node();
    node *second = new node();
    node *third = new node();

    // Assigning value and connecting nodes to each other
    head->value = 1;     // first->value=1;
    head->prev = nullptr; // Set prev for the head to nullptr
    head->next = second; // first->next=second;

    second->value = 2;
    second->prev = head; // Set prev for the second node
    second->next = third;

    third->value = 3;
    third->prev = second; // Set prev for the third node
    third->next = nullptr;

    cout << "Before adding to front:\n";
    PrintList(head);

    cout << "After adding it to front:" << endl;
    AddFront(&head, 10); //&head returning mem address
    PrintList(head);

    cout << "After adding to end:" << endl;
    AddEnd(&head, 90);
    PrintList(head);

    cout << "After inserting at specific location:" << endl;
    AddAfter(third, 23);
    PrintList(head);

    cout << "After deleting front:" << endl;
    DelFront(&head);
    PrintList(head);

    cout << "After deleting the end" << endl;
    DelEnd(&head);
    PrintList(head);

    cout << "After deleting from a specific location" << endl;
    DelAfter(second);
    PrintList(head);

    return 0;
}

void PrintList(node *head)
{
    while (head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
}

void AddFront(node **head, int NewValue)
{
    node *newnode = new node();
    newnode->value = NewValue;
    newnode->next = *head;
    newnode->prev = nullptr; // Set prev for the new node to nullptr
    if (*head != nullptr)
    {
        (*head)->prev = newnode; // Update the previous head's prev pointer
    }
    *head = newnode;
}

void AddEnd(node **head, int NewValue)
{
    node *newnode = new node();
    newnode->value = NewValue;
    newnode->next = nullptr;
    newnode->prev = nullptr; // Set prev for the new node to nullptr

    if (*head == nullptr)
    {
        *head = newnode;
        return;
    }

    node *last = *head;
    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = newnode;
    newnode->prev = last; // Update the new node's prev pointer
}

void AddAfter(node *previous, int NewValue)
{
    if (previous == nullptr)
    {
        cout << "previous node cannot be NULL!!" << endl;
        return;
    }

    node *newnode = new node();
    newnode->value = NewValue;
    newnode->next = previous->next;
    newnode->prev = previous; // Set prev for the new node to previous

    if (previous->next != nullptr)
    {
        previous->next->prev = newnode; // Update the next node's prev pointer
    }

    previous->next = newnode;
}

void DelFront(node **head)
{
    if (*head == nullptr)
    {
        cout << "Linked List can't be empty to perform delete operation!" << endl;
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    if (*head != nullptr)
    {
        (*head)->prev = nullptr; // Update the new head's prev pointer
    }
    delete temp;
}

void DelEnd(node **head)
{
    if (*head == nullptr)
    {
        cout << "Linked List is already empty" << endl;
        return;
    }

    if ((*head)->next == nullptr)
    {
        delete *head;
        *head = nullptr;
        return;
    }

    node *current = *head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void DelAfter(node *prev)
{
    if (prev == nullptr || prev->next == nullptr)
    {
        cout << "Cannot delete as previous node is NULL or there is no next node\n";
        return;
    }

    node *temp = prev->next;
    prev->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = prev; // Update the next node's prev pointer
    }
    delete temp;
}
