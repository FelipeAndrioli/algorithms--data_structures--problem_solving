#include <iostream>
#include <vector>

class Queue {
    private:
        //store elements
        std::vector<int> data;
        //pointer to indicate the start position
        int head;
    public:
        Queue();
        bool enqueue(int x);    //insert an element into the queue. Return true if the operation is successful
        bool dequeue();         //Dequeue an element from the queue. Return true if the operation is successful
        bool clear_queue();     //Clear the entire queue and set head to 0. Return true if the operation is successful        
        int front();            //Get the front item from the queue
        bool is_empty();        //Checks whether the queue is empty or not
        void show_queue();      //Show the entire queue
};

Queue::Queue() {
    head = 0;
}

bool Queue::enqueue(int x) {
    data.push_back(x);
    return true;
}

bool Queue::dequeue() {
    if (is_empty()) {
        return false;
    }

    head++;
    return true;
}

bool Queue::clear_queue() {

    if (!(head >= data.size())) {
        data.clear();
        head = 0;
    } else {
        return false;
    }

    return true;
}

int Queue::front() {
    return data[head];
}

bool Queue::is_empty() {

    return head >= data.size();
}

void Queue::show_queue() {

    if (!(head >= data.size())) {
        for (int i = head; i < data.size(); i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Queue is empty!" << std::endl;
    }
}

int main() {

    Queue myqueue;
    myqueue.enqueue(5);
    myqueue.enqueue(3);
    myqueue.enqueue(4);
    myqueue.enqueue(6);
    myqueue.enqueue(9);


    if (!myqueue.is_empty()) {
        std::cout << myqueue.front() << std::endl;
    }

    myqueue.dequeue();

    if (!myqueue.is_empty()) {
        std::cout << myqueue.front() << std::endl;
    }

    myqueue.show_queue();

    if (myqueue.clear_queue()) {
        std::cout << "Queue cleared successful" << std::endl;
    } else {
        std::cout << "Queue already cleared" << std::endl;
    }

    return 0;
}