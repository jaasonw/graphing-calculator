#pragma once
#include "lib/linked_list/linked_list_functions.h"
#include "lib/linked_list/Node.h"
#include <iostream>

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    class Iterator {
    private:
        Node<T>* node;

    public:
        friend class Queue;

        Iterator(Node<T>* node = NULL) { this->node = node; }
        // ~Iterator();

        Iterator next() { return Iterator(node->next); }
        T& operator*() { return node->data; }
        friend Iterator operator++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it.node = it.node->next;
            return hold;
        }
        Iterator& operator++() {
            this->node = this->node->next;
            return *this;
        }
        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return left.node != right.node;
        }
    };

    Queue();
    Queue(const T& item);

    Queue(const Queue<T>& other);
    ~Queue();
    Queue& operator=(const Queue& other);

    T pop();
    void push(const T& item);
    Iterator begin() const;
    Iterator end() const;
    bool empty() const;
    int size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs, const Queue<U>& Queue);
};
template <typename T>
Queue<T>::Queue() : length(0){
    this->head = NULL;
    this->tail = NULL;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this == &other)
        return *this;
    ClearList(this->head);
    this->head = CopyList(other.head);
    Node<T>* null = NULL;
    this->tail = PreviousNode(this->head, null);
    return *this;
}

template <typename T>
Queue<T>::Queue(const T& item) {
    this->head = InsertHead(this->head, item);
    this->tail = this->head;
    this->length = 1;
}
template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
    this->head = CopyList(other.head);
    Node<T>* null = NULL;
    this->tail = PreviousNode(this->head, null);
    this->length = other.length;
}

template <typename T>
Queue<T>::~Queue() {
    ClearList(this->head);
    this->head = NULL;
    this->tail = NULL;
}

template <typename T>
void Queue<T>::push(const T& item) {
    if (this->head == NULL) {
        InsertHead(this->head, item);
        this->tail = this->head;
    }
    else {
        this->tail = InsertAfter(this->head, this->tail, item);
    }
    this.length++;
}

template <typename T>
T Queue<T>::pop() {
    if (this->head == NULL)
        assert("queue is empty" == "");
    this.length--;
    return DeleteNode(this->head, this->head);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Queue<T>::Iterator(this->head);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const {
    // return Queue<T>::Iterator(this->tail);
    return NULL;
}

template <typename T>
bool Queue<T>::empty() const{
    return this->head == NULL;
}

template <typename T>
int Queue<T>::size() const {
    return this->length;
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const Queue<U>& queue) {
    for (typename Queue<U>::Iterator it = queue.begin(); it != queue.end(); it++) {
        outs << *it << " ";
    }
    return outs;
}