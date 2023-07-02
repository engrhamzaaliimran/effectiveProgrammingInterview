#include <iostream>
#include <memory>
#include <algorithm>
#include <limits.h>

using namespace std;

class mystack
{
private:
    struct node
    {
        int data;
        shared_ptr<node> next;
    };
    shared_ptr<node> top;
    int max = INT_MIN;

public:
    mystack()
    {
        top = nullptr;
    }
    void push(int data)
    {
        if (top == nullptr)
        {
            top = make_shared<node>();
            top->data = data;
            top->next = nullptr;
            max = data;
        }
        else
        {
            shared_ptr<node> temp = make_shared<node>();
            temp->data = data;
            temp->next = top;
            top = temp;
            if (max < data)
                max = data;
        }
    }
    int pop()
    {
        int to_return = top->data;
        top = top->next;
        return to_return;
    }
    int topElement()
    {
        return top->data;
    }
    /*
     * This function is for checking the stack implementation
     */
    void print()
    {
        shared_ptr<node> temp = top;
        while (temp != nullptr)
        {
            cout << "| " << temp->data << " |" << endl;
            temp = temp->next;
        }
        cout << "______" << endl;
    }
    int getMax()
    {
        return max;
    }
};

int main()
{
    mystack stk;
    stk.push(14);
    stk.push(97);
    stk.push(10);
    stk.print();
    cout << "Max = " << stk.getMax() << endl;
    cout << "pop element = " << stk.pop() << endl;
    stk.print();
    cout << "top element = " << stk.topElement() << endl;
    stk.print();
}
