#include <iostream>
using namespace std;

#define n 10

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    ~stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << "Pushing " << x << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element for popping..." << endl;
            return;
        }
        top--;
        cout << "Popping..." << endl;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return 404;
        }
        return arr[top];
    }

    bool full()
    {
        return top == n - 1; // Corrected condition for full stack
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    cout << "Top is: " << st.Top() << endl;
    st.pop();
    cout << "Top is:  " << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "Top is: " << st.Top() << endl;
    cout << "Is Full: " << st.full() << endl;
    cout << "Is Empty: " << st.empty() << endl;

    return 0;
}
