#pragma once

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#define NULL 0
#include <iostream>

using namespace std;

class LinkedException
{
public:
    LinkedException(std::string error)
        : m_error(error)
    {
    }

    const char* getError() { return m_error.c_str(); }
};

template <typename T>
class LinkedList {

private:

    class Node {
        friend class LinkedList<T>;

    private:
        T data;
        Node* next;

    public:
        Node(T d, Node* n = 0) : data(d), next(n) {}
       
    };

    Node* head;  
    Node* tail;  
    int count;   
    
public:

    LinkedList(T* items, int count) :         //Copy elements 
        head(0), tail(0), count(0)
    {
        for (int i = 0; i < count; i++) {
            this->prepend(items[i]);
        }
    }

    LinkedList(const LinkedList<T>& src) :  //Copy constructor
        head(0), tail(0), count(0) 
    {
        Node* current = src.head;
        while (current != NULL) {
            this->prepend(current->data);
            current = current->next;
        }
    }

    LinkedList() : head(NULL), tail(NULL), count(0) {}  // Default constructor

    int getLength()      
    {   
        return count;
    }

    T getFirst() 
    {
        if (this->getLength() == 0) {
            throw LinkedException("IndexOutOfRange");
        }
        
        return head->data;
    }

    T getLast() {
        if (this->getLength() == 0) {
            throw LinkedException("IndexOutOfRange");
        }

        return tail->data;
    }

    T get(int index)   
    {
        if (index < 0 || index > this->count)      
            throw LinkedException("IndexOutOfRange");
           

        Node* node = this->head;
        for (int pos = 0; pos < index; pos++) {
            node = node->next;
        }

        return node->data; 
    }

    LinkedList<T>* getSubList(int startIndex, int endIndex)  
    {
        if (startIndex < 0 || startIndex > this->count)
            throw LinkedException("IndexOutOfRange");
        if (endIndex < 0 || endIndex > this->count)
            throw LinkedException("IndexOutOfRange");

        LinkedList<T> result;

        for (int i = startIndex; i <= endIndex; i++) {
            T element = (*this).get(i);
            result.prepend(element);
        }

        return &result;
    }

    void append(T item)
    {
        Node* new_head = new Node(item, head);

        if (this->empty()) {
            head = new_head;
            tail = new_head;
        }
        else {
            head = new_head;
        }
        count++;   
    }

    void prepend(T item) 
    {
        Node* new_tail = new Node(item, NULL);

        if (this->empty()) {
            head = new_tail;
        }
        else {
            tail->next = new_tail;
        }

        tail = new_tail;
        count++;
    }

    bool empty()      // Returns whether or not list contains any elements 
    {
        return count == 0;
    }
    
    void insertAt(T item, int index)  
    {

        if (index < 0 || index >= this->size)
            throw LinkedException("IndexOutOfRange");

        index = index + 1;
        
        Node* newNode = new Node(item);
        
        if (index == 1) {
            newNode->next = this->head->next;
            this->head = newNode;
            return;
        }
        
        index--;
        Node* ptr = this->head;

        while (ptr != NULL && --index) {
            ptr = ptr->next;
        }
        if (ptr == NULL) return;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    LinkedList<T> concat(LinkedList<T>& list)
    {
        this->tail->next = list.head;
        LinkedList<T> newList(*this);
        this->tail->next = NULL;
        
        return newList;
    }

    void pop_front()    //Remove first element 
    {
        Node* old_head = head;

        if (this->count == 1) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }

        delete old_head;
        count--;
    }

    void pop_back() {

        Node* old_tail = tail;

        if (this->count == 1) {
            head = NULL;
            tail = NULL;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }

            current->next = NULL;
            tail = current;
        }

        delete old_tail;
        count--;
    }

private:
    std::string m_error;


};

#endif

