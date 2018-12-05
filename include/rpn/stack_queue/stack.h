#pragma once
#include <iostream>
#include "lib/linked_list/List.h"

template <typename T>
class Stack {
private:
    List<T> list;
    int length;
public:
    class Iterator {
    private:
        Node<T>* node;

    public:
        friend class Stack;
        
        Iterator(Node<T>* node = NULL) { this->node = node; }
        Iterator(const typename List<T>::Iterator& it) {
            this->node = it.getNode();
        }
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

    Stack();
    Stack(const T& item);

    T pop();
    void push(const T& item);
    Iterator begin() const;
    Iterator end() const;
    bool empty() const;
    int size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs, const Stack<U>& stack);
    
};
template <typename T>
Stack<T>::Stack() {
    this->list = List<T>();
}
template <typename T>
Stack<T>::Stack(const T& item) {
    this->list = List<T>(item);
}

template <typename T>
void Stack<T>::push(const T& item) {
    this->length++;
    this->list.insert_head(item);
}

template <typename T>
T Stack<T>::pop() {
    if (this->list.begin() != NULL)
        this->length--;
    return this->list.del(this->list.begin());
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const {
    return Stack<T>::Iterator(this->list.begin());
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const {
    return Stack<T>::Iterator(this->list.end());
}

template <typename T>
bool Stack<T>::empty() const {
    return this->list.empty();
}

template <typename T>
int Stack<T>::size() const {
    return this->list.length;
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const Stack<U>& stack) {
    for (typename Stack<U>::Iterator it = stack.begin(); it != stack.end(); it++) {
        outs << *it << " ";
    }
    return outs;
}