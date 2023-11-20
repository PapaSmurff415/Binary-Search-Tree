#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;
};

void Display(node *head);
void AddFront(node **head, int NewValue);
void AddRear(node **head, int NewValue);
void DelFront(node **head);
void DelRear(node **head);

int main()
{
    node *head = nullptr;

    cout <<"After adding to front:" << endl;
    AddFront(&head, 20);
    AddFront(&head, 10);
    Display(head);

    cout <<"After adding to rear:" << endl;
    AddRear(&head, 90);
    Display(head);

    cout << "After deleting front:" << endl;
    DelFront(&head);
    Display(head);

    cout << "After deleting the rear" << endl;
    DelRear(&head);
    Display(head);

    return 0;
}

void Display(node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *current = head;
    do
    {
        cout << current->value << endl;
        current = current->next;
    } while (current != head); // Continue until we reach the head again
}

void AddFront(node **head, int NewValue)
{
    node *newnode = new node();
    newnode->value = NewValue;

    if (*head == nullptr)
    {
        *head = newnode;
        newnode->next = newnode; // Point to itself to create a circular link
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = *head;
        newnode->prev = (*head)->prev;
        (*head)->prev->next = newnode;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void AddRear(node **head, int NewValue)
{
    node *newnode = new node();
    newnode->value = NewValue;

    if (*head == nullptr)
    {
        *head = newnode;
        newnode->next = newnode; // Point to itself to create a circular link
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = *head;
        newnode->prev = (*head)->prev;
        (*head)->prev->next = newnode;
        (*head)->prev = newnode;
    }
}

void DelFront(node **head)
{
    if (*head == nullptr)
    {
        cout << "Linked List can't be empty to perform delete operation!" << endl;
        return;
    }

    if ((*head)->next == *head)
    {
        delete *head;
        *head = nullptr;
    }
    else
    {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        node *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

void DelRear(node **head)
{
    if (*head == nullptr)
    {
        cout << "Linked List is already empty" << endl;
        return;
    }

    if ((*head)->next == *head)
    {
        delete *head;
        *head = nullptr;
    }
    else
    {
        node *temp = (*head)->prev;
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
        delete temp;
    }
}
