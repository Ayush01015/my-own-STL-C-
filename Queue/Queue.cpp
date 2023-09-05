#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Queue{
    private:
        int capacity;
        int rear,front;
        int *ptr;
    public:
        Queue();
        Queue(int);
        void view();
        void enQueue(int);
        bool isQueueFull();
        bool isQueueEmpty();
        int deQueue();
        int getRear();
        int getFront();
        int count();
};
Queue::Queue(){}
Queue::Queue(int cap){
    capacity = cap;
    rear = -1;
    front = -1;
    ptr = new int[capacity];
}
void Queue::enQueue(int data){
    if(isQueueEmpty()){
        front=0;
        rear=0;
        ptr[rear] = data;
    }else if(isQueueFull()){
        cout<<"Queue is Full\n";
    }else if(front>0 && rear == capacity-1){
        rear = 0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear] = data;
    }   
}
bool Queue::isQueueFull(){
    if((rear == capacity-1 && front==0)||(rear<front && front-rear==1))
        return true;
    return false;
}
bool Queue::isQueueEmpty(){
    if(rear==-1 && front==-1)
        return true;
    return false;
}
void Queue::view(){
    if(isQueueEmpty()){
        cout<<"Queue is Empty\n";
    }else if(rear==front){
            cout<<ptr[rear]<<" ";
    }else if(isQueueFull()){
        for(int i=0;i<=capacity-1;i++)
            cout<<ptr[i]<<" ";
        cout<<endl;
    }else if(rear<front){
        for(int i=0;i<=rear;i++)
            cout<<ptr[i];
        for(int i=front;i<=capacity-1;i++)
            cout<<ptr[i];
    }else if(front<rear){
        for(int i = front;i<=rear;i++)
            cout<<ptr[i]<<" ";
    }
}
int main(){
    
    return 0;
}
