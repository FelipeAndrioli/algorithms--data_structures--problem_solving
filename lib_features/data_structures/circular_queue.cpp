#include <iostream>
#include <vector>

class Circular_Queue {
    private:
        std::vector<int> data;
        int head;
        int tail;
        int size;
    public:
        Circular_Queue(int queue_size);
        bool is_empty();
        bool is_full();
        int front();
        int rear();
        bool enqueue(int value);
        bool dequeue();
};

Circular_Queue::Circular_Queue(int queue_size) {
    data.resize(queue_size);
    head = -1;
    tail = -1;
    size = queue_size;
}

bool Circular_Queue::is_empty() {
    if (head == -1) {
        return true;
    }

    return false;
}

bool Circular_Queue::is_full() {
    if ((tail + 1) % size == head) {
        return true;
    }

    return false;
}

int Circular_Queue::front() {
    if (is_empty()) {
        return -1;
    }

    return data[head];
}

int Circular_Queue::rear() {
    if (is_empty()) {
        return -1;
    }

    return data[tail];
}

bool Circular_Queue::enqueue(int value) {
    if (is_full()) {
        return false;
    }

    if (is_empty()) {
        head = 0;
    }

    tail = (tail + 1) % size;
    data[tail] = value;

    return true;
}

bool Circular_Queue::dequeue() {
    if (is_empty()) {
        return false;
    }

    if (head == tail) {
        head = -1;
        tail = -1;
        return true;
    }   

    head = (head + 1) % size;

    return true;
}