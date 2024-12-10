#include<iostream>

using namespace std;

class Stack{
    private:
        int capacity;
        int peek;
        int *stackArray;

    public:
        Stack(int capacity){
            peek = -1;
            this->capacity = capacity;
            this->stackArray = new int[capacity];
        }

        Stack(){
            peek = -1;
            this->capacity = 10;
            this->stackArray = new int[10];
        }

        ~Stack(){
            delete[] stackArray;
        }

        void push(int element){
            if(isFull()){
                cout << "The Stack has overflowed!!!" << endl;
                return;
            }

            this->peek++;
            this->stackArray[this->peek] = element;
        }

        int pop(){
            int poppedElement = getPeekElement();

            if(poppedElement == 404){
                return 404;
            }

            this->stackArray[this->peek] = NULL;
            this->peek--;

            return poppedElement;
        }

        int getPeekElement(){
            if(isEmpty()){
                cout << "The Stack is Empty!!!" << endl;
                return 404;
            }

            int poppedElement = this->stackArray[this->peek];

            return poppedElement;
        }

        bool isFull(){
            return (this->peek + 1) >= capacity ? true : false;
        }

        bool isEmpty(){
            return (this->peek + 1) == 0 ? true : false;
        }

        void show(){
            cout << "*************Integer Stack:*************" << endl;
            cout << "----------------------------------------" << endl;
            for(int index = this->peek; index > -1; index--){
                cout << "|   " << this->stackArray[index] <<  "   |" << endl;
                cout << "|___" << "___" <<  "___|" << endl;
            }
        }
};

int main(){
    Stack integerStack;

    cout << "Popped element is: " << integerStack.pop() << endl;

    integerStack.push(2);
    integerStack.show();
    integerStack.push(5);
    integerStack.show();
    integerStack.push(8);
    integerStack.show();
    integerStack.push(12);
    integerStack.show();
    integerStack.push(-2);
    integerStack.show();
    integerStack.push(4);
    integerStack.show();
    integerStack.push(14);
    integerStack.show();
    integerStack.push(25);
    integerStack.show();
    integerStack.push(1);
    integerStack.show();
    integerStack.push(0);
    integerStack.show();
    integerStack.push(45);
    integerStack.show();

    cout << "Popped element is: " << integerStack.pop() << endl;
    integerStack.show();
    cout << "Popped element is: " << integerStack.pop() << endl;
    integerStack.show();
    cout << "Popped element is: " << integerStack.pop() << endl;
    integerStack.show();

    return 0;
}