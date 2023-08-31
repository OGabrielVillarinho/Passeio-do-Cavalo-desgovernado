#include <iostream>

using namespace std;


const int TAM = 100;
struct Queue {
    int front, rear, size;
    int data[TAM];
};

void create(Queue &queue) {
    queue.front = queue.rear = -1;
    queue.size = 0;
}

bool isEmpty(Queue &queue) {
    return queue.size == 0;
}

bool isFull(Queue queue) {
    return queue.size == TAM;
}

void enqueue(Queue &queue, int newData) {
    if (isFull(queue)) {
        cout << "Queue overflow" << endl;
        return;
    }

    if (isEmpty(queue)) {
        queue.front = queue.rear = 0;
    } else {
        queue.rear = (queue.rear + 1) % TAM;
    }
    queue.data[queue.rear] = newData;
    queue.size++;
}

void dequeue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue underflow" << std::endl;
        return;
    }
    if (queue.front == queue.rear) {
        queue.front = queue.rear = -1;
    } else {
        queue.front = (queue.front + 1) % TAM;
    }
    queue.size--;
}

int returnFront(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty" << std::endl;
        return -1; 
    }
    return queue.data[queue.front];
}

int main(int argc, char **argv) {
    Queue numbers;
    create(numbers);

    enqueue(numbers, 1);
    enqueue(numbers, 2);
    enqueue(numbers, 3);
    enqueue(numbers, 4);
    enqueue(numbers, 5);
    enqueue(numbers, 6);

    cout << "Número que está na frente da fila => " << returnFront(numbers) << endl;

    dequeue(numbers);
    
    cout << "Número que está na frente da fila depois de desinfileirar => " << returnFront(numbers) << endl;


}