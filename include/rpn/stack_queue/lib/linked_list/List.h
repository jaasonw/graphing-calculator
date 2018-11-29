#pragma once
#include "Node.h"
#include "linked_list_functions.h"
#include <iostream>

template<typename T>
class List
{
private:
    Node<T>* list;
public:
    class Iterator {
    private:
        Node<T>* node;

    public:
        friend class List;
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

        Node<T>* getNode() const { return this->node; }
    };

    List();
    List(T item);

    List(const List& other);
    List& operator=(const List& other);
    ~List();

    Iterator insert_head(const T& item);
    Iterator insert_after(Node<T>* after, const T& item);
    Iterator insert_before(Node<T>* before, const T& item);
    Iterator insert_sorted(const T& item, bool ascending = true);
    Iterator insert_sorted_unique(const T& item, bool ascending = true);
    T del(Node<T>* before);
    T del(List<T>::Iterator before);
    void print() const;
    Iterator search(const T& key);
    Iterator previous(List<T>::Iterator previous);
    T& operator[](int index);
    Iterator begin() const;
    Iterator end() const;
    bool empty() const;
    

    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs, const List<U>& l);
};
template <typename T>
List<T>::List() : list(NULL) {}

template <typename T>
List<T>::List(T item) {
    list = new Node<T>(item);
}

template <typename T>
List<T>::List(const List& other) {
    this->list = CopyList(other.list);
}

template <typename T>
List<T>::~List() {
    ClearList(this->list);
    // just to be safe 👍
    delete this->list;
}
template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this == &other)
        return *this;
    ClearList(this->list);
    this->list = CopyList(other.list);
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::insert_head(const T& item) {
    return List<T>::Iterator(InsertHead(this->list, item));
}

template <typename T>
typename List<T>::Iterator List<T>::insert_after(Node<T>* after, const T& item) {
    return List<T>::Iterator(InsertAfter(this->list, after, item));
}

template <typename T>
typename List<T>::Iterator List<T>::insert_before(Node<T>* before, const T& item) {
    return List<T>::Iterator(InsertBefore(this->list, before, item));
}

template <typename T>
typename List<T>::Iterator List<T>::insert_sorted(const T& item, bool ascending) {
    if (this->list == NULL)
        return this->insert_head(item);
    else
        return InsertSorted_and_add(list, item, ascending);
}

template <typename T>
typename List<T>::Iterator List<T>::insert_sorted_unique(const T& item, bool ascending) {
    if (this->list == NULL)
        List<T>::Iterator(this->insert_head(item));
    else
        return List<T>::Iterator(InsertSorted(list, item, ascending));
}

template <typename T>
T List<T>::del(Node<T>* item) {
    return DeleteNode(this->list, item);
}

template <typename T>
T List<T>::del(List<T>::Iterator it) {
    return DeleteNode(this->list, it.node);
}

template <typename T>
void List<T>::print() const {
    PrintList(this->list);
}

template <typename T>
typename List<T>::Iterator List<T>::search(const T& key) {
    return List<T>::Iterator(SearchList(this->list, key));
}

template <typename T>
typename List<T>::Iterator List<T>::previous(List<T>::Iterator previous) {
    return List<T>::Iterator(PreviousNode(this->list, *previous));
}

template <typename T>
T& List<T>::operator[](int index) {
    return At(this->list, index);
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return List<T>::Iterator(list);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    // wait, i think this returns null??
    return NULL;
    // because i cant pass null directly into the function >:/
    // Node<T>* null = NULL;
    // return Iterator(PreviousNode(this->list, null));
}

template <typename T>
bool List<T>::empty() const {
    return this->list == NULL;
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const List<U>& l) {
    l.print();
    return outs;
}