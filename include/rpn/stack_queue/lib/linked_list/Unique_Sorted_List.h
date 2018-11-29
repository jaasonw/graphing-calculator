#pragma once
#include "Node.h"
#include "linked_list_functions.h"
#include <iostream>

template <typename T>
class UniqueSortedList {
private:
    Node<T>* list;
    Node<T>* insert_head(const T& item);
public:
    UniqueSortedList();
    UniqueSortedList(T item);

    UniqueSortedList(const UniqueSortedList& other);
    UniqueSortedList& operator=(const UniqueSortedList& other);
    ~UniqueSortedList();

    Node<T>* insert(const T& item, bool ascending = true);
    T del(Node<T>* before);

    void print() const;
    Node<T>* search(const T& key) const;
    Node<T>* previous(Node<T>* previous) const;
    T& operator[](int index) const;
    Node<T>* begin() const;
    Node<T>* end() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs, const UniqueSortedList<U>& l);
};

template <typename T>
Node<T>* UniqueSortedList<T>::insert_head(const T& item) {
    return InsertHead(this->list, item);
}
template <typename T>
UniqueSortedList<T>::UniqueSortedList() : list(NULL) {}

template <typename T>
UniqueSortedList<T>::UniqueSortedList(T item) {
    list = new Node<T>(item);
}

template <typename T>
UniqueSortedList<T>::UniqueSortedList(const UniqueSortedList& other) {
    this->list = CopyList(other.list);
}

template <typename T>
UniqueSortedList<T>::~UniqueSortedList() {
    ClearList(this->list);
    // just to be safe 👍
    delete this->list;
}
template <typename T>
UniqueSortedList<T>& UniqueSortedList<T>::operator=(const UniqueSortedList& other) {
    if (this == &other)
        return *this;
    ClearList(this->list);
    this->list = CopyList(other.list);
    return *this;
}

template <typename T>
Node<T>* UniqueSortedList<T>::insert(const T& item, bool ascending) {
    if (this->list == NULL)
        return this->insert_head(item);
    else
        return InsertSorted(list, item, ascending);
}

template <typename T>
T UniqueSortedList<T>::del(Node<T>* item) {
    return DeleteNode(this->list, item);
}

template <typename T>
void UniqueSortedList<T>::print() const {
    PrintList(this->list);
}

template <typename T>
Node<T>* UniqueSortedList<T>::search(const T& key) const {
    return SearchList(this->list, key);
}

template <typename T>
Node<T>* UniqueSortedList<T>::previous(Node<T>* previous) const {
    return PreviousNode(this->list, previous);
}

template <typename T>
T& UniqueSortedList<T>::operator[](int index) const {
    return At(this->list, index);
}

template <typename T>
Node<T>* UniqueSortedList<T>::begin() const {
    return list;
}

template <typename T>
Node<T>* UniqueSortedList<T>::end() const {
    // because i cant pass null directly into the function >:/
    Node<T>* null = NULL;
    return PreviousNode(this->list, null);
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const UniqueSortedList<U>& l) {
    l.print();
    return outs;
}