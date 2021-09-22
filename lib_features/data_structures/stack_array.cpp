#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> data;
    public:
        void push(int value);
        bool isEmpty();
        bool pop();
        int top();
        int stackSize();
};

void Stack::push(int value) {
    data.push_back(value);
}

bool Stack::isEmpty() {
    return data.empty();
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }

    data.pop_back();
    return true;
}

int Stack::top() {
    return data.back();
}

int main() {

    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    for (int i = 0; i < 4; i++) {
        if (!stack.isEmpty()) {
            cout << stack.top() << endl;
        }

        cout << (stack.pop() ? "true" : "false") << endl;
    }

    return 0;
}