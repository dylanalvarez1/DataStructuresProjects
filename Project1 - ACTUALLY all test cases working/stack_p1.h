#include <stdlib.h>
#include <iostream>

#ifndef stack_p1_p1_h
#define stack_p1_p1_h
template <typename T>
class stack_p1
{
    private:
        struct Node
        {
            T data;
            Node* next = NULL; 
        };
        Node* top;
        int size;

    public:
        stack_p1();
        bool isEmpty(); 
        T pop();
        void push(T item);
        T peek();
        stack_p1<T>& operator=(const stack_p1<T>& other);
        bool operator==(const stack_p1<T>& other);
        int getSize();
    
};

template <class T>
stack_p1<T>::stack_p1()
{
    this->top = NULL;
}

template <class T>
bool stack_p1<T>::isEmpty()
{
    return (this->top == NULL);
}

/**
 * pushes to stack_p1 the item of type template T
 * */
template <class T>
void stack_p1<T>::push(T item)
{
   Node* addNode = new Node();
   addNode->data = item;
   addNode->next = this->top; 
   this->top = addNode;
   this->size++;
  
}

/**
 * @return the element of what was just deleted
 * */
template <class T>
T stack_p1<T>::pop()
{
    Node* first = this->top;
    T info = first->data;
    this->top = this->top->next;
    free(first);
    this->size--;
    return info;
}

template <class T>
T stack_p1<T>::peek()
{
    if(this->top == NULL)
    {
        return NULL;
    }
    return this->top->data;
}

template <class T>
int stack_p1<T>::getSize()
{
    return this->size;
}


template <class T>
stack_p1<T>& stack_p1<T>::operator=(const stack_p1<T>& other)
{
    
    this->top = new Node();
    Node* temp  = this->top;
    
    for(Node* i = other.top; i != NULL; i = i->next)
    {
        temp->data = i->data;
        if(i->next != NULL)
        {
            temp->next = new Node();
            temp = temp->next;
        }
       
    }
    
    return *this;
}


template <class T>
bool stack_p1<T>::operator==(const stack_p1<T>& other)
{
    Node* temp = this->top;
    for(Node* i = other.top; i != NULL; i = i->next)
    {
       if(i->data != temp->data)
       {
           return false;
       }
       temp = temp->next;

    }
    return true;
}



#endif