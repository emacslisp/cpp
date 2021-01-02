#include<vector>
#include<iostream>

using namespace std;

struct node {
    int info;
    node *next;
};

class Queue2 {
    private:
        node *front;
        node *rear;
    public:
        Queue2();
        ~Queue2();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();
};