#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T> class Stack{
public:

    void push(T item){

        stack.push_back(item);
    }

    void pop(){

        if(!stack.empty()){
            stack.pop_back();
        }else{
            cout << "Cannot pop. Stack already is empty." << endl;
        }

    }

    T top(){

        if(!stack.empty()){
            return stack.back();
        }else{
            cout << "Stack is empty. There is no top element" << endl;
            return 0;
        }

    }

    bool empty(){

        if(!stack.empty()){
            return false;
        }else{
            return true;
        }

    }

    size_t size(){

        return stack.size();

    }

    void swap(Stack<T>& s){

        std::swap(stack,s.stack);

    }

    void print(){

        if(size() == 0){
            cout << "There are no elements in the stack." << endl;
        }
        else{
            cout << "{ ";

            for_each(stack.begin(), stack.end(), [](int value){
                cout << value << " ";
            });
            cout << "}" << endl;
        }

    }


private:

  vector<T> stack;

};



int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Stack class template |-|-|-|-|-|-|-|-|-|" << endl;

    Stack<int> s;
    Stack<int> s2;


    s.push(1);
    s.push(10);
    s.push(12);

    cout << "Elements in the stack (first)" << endl;

    s.print();

    cout << "Size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;

    s.pop();

    cout << "Elements in the stack (pop 1 element)" << endl;

    s.print();

    cout << "Size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;

    s2.push(154);

    cout << "Elements in the stack nº2 (first)" << endl;
    s2.print();

    s.swap(s2);

    cout << "After swapping stacks:" << endl;
    cout << "Stack 1: ";
    s.print();
    cout << "Stack 2: ";
    s2.print();

    return 0;

}
