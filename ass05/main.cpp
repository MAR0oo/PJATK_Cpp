#include <iostream>

template <typename E>
class MyStack {
private:

    class Node {
    public:
        E data;
        Node* next;
        Node(const E& d): data(d), next(nullptr) {}
    };
    Node* top;
public:
    MyStack(): top(nullptr) {}
    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }

    MyStack(const MyStack&) = delete;
    MyStack* operator=(const MyStack&) = delete;
    void push(const E& d) {
        Node* newNode = new Node(d);
        newNode->next = top;
        top = newNode;
    }
    E pop() {
        if (empty()) {
            throw std::out_of_range("Stos jest pusty");
        }
        E data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool empty() const {
        return top == nullptr;
    }
};

int main() {
    using std::cout; using std::endl; using std::string;

    MyStack<string> stS;
    MyStack<double> stD;
    for (int i = 5; i > 0; --i) {
        stS.push(std::to_string(double(i)));
        stD.push(double(i));
    }
    while (!stS.empty())
        cout << "string: " << stS.pop() << "  "
             << "double: " << stD.pop() << endl;
}
