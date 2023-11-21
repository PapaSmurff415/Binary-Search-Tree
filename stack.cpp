#include <iostream>
#define MAXSIZE 100
using namespace std;

class stack
{
    public:
    int items[MAXSIZE];
    int top;

    stack() //ctor to initialize the stack
    {
        top = -1; //initialize to -1 which is empty as soon as stack has been created.
    }
};

/*
    -> isEmpty
    -> PUSH
    -> POP
    -> PEEK
    -> DISPLAY
*/
int isEmpty(stack *s);
void display(stack *s);
void push(stack *s, int NewValue);
void pop(stack *s);
void peek(stack *s);



int isEmpty(stack *s)
{
    //cout<<"Stack underflow!!!" <<endl;
    return (s->top == -1);
}

void display(stack *s)
{
    if(isEmpty(s))
    {
        cout<<"Nothing to display as stack is empty" <<endl;
        return;
    }

    for(int i=0; i <= s->top; i++)
    {
        cout<<s->items[i] <<endl;
    }
}

void push(stack *s, int NewValue)
{
    if (s->top == MAXSIZE -1)
    {
        cout<<"Can't add due to buffer overflow!" <<endl;
        return;
    }
/*
    -> increment the top first [++(s->top)]
    -> assign 's->item[s->top] with NewValue'
*/
    //s->items[++(s->top)] = NewValue;
    s->top ++;
    s->items[s->top] = NewValue;
}

void pop(stack *s)
{
    if(isEmpty(s))
    {
        cout<<"Nothing to delete!" <<endl;
        return;
    }

    s->top --;
}

void peek(stack *s)
{
    if(isEmpty(s))
    {
        cout<<"Stack is Empty!!" <<endl;
        return;
    }
    cout <<s->items[s->top] <<endl;
}

int main()
{
    stack MyStack; //Creating new object called MyStack using `class stack`

    cout<<"After PUSH operation:" <<endl;
    push(&MyStack,10);
    push(&MyStack,20);
    push(&MyStack,30);
    display(&MyStack);

    cout<<"PEEK after PUSH operation: " <<endl;
    peek(&MyStack);

    cout<<"After POP operation:" <<endl;
    pop(&MyStack);
    display(&MyStack);

    cout<<"After PEEK operation: " <<endl;
    peek(&MyStack);
    display(&MyStack);

    return 0;
}
