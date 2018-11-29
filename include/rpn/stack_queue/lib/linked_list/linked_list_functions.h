#pragma once
#include "Node.h"
#include <cassert>
#include <iostream>

// prints the list
template <typename T>
void PrintList(Node<T>* head) {
    if (head == NULL)
        return;
    else {
        std::cout << head->data << " ";
        PrintList(head->next);
    }
}

// prints the list
template <typename T>
void PrintList_Cursor(Node<T>* head, Node<T>* cursor) {
    if (head == NULL) {
        std::cout << "NULL";
        return;
    }
    else {
        if (head == cursor)
            std::cout << '{' << head->data << '}' << " ";
        else
            std::cout << head->data << " ";
        PrintList_Cursor(head->next, cursor);
    }
}

template <typename T>
void PrintList_backwards(Node<T>* head) {
    if (head == NULL)
        return;
    if (head->next != NULL)
        PrintList_backwards(head->next);
    std::cout << head->data << " ";
}

// returns a pointer to a node with key or null
template <typename T>
Node<T>* SearchList(Node<T>* head, const T& key) {
    if (head == NULL)
        return NULL;
    if (head->data == key)
        return head;
    else
        return SearchList(head->next, key);
}

// Inserts an element at the beginning of the list (next to the head pointer)
template <typename T>
Node<T>* InsertHead(Node<T>*& head, const T& item) {
    Node<T>* node;
    if (head == NULL) {
        node = new Node<T>(item);
        head = node;
    }
    else {
        node = new Node<T>(item, head);
        head = node;
    }
    return node;
}

// insert after ptr
// head: pointer to list, doesnt get used, just to know wtf list im adding to
// after: node to insert after
// item: the item
template <typename T>
Node<T>* InsertAfter(Node<T>*& head, Node<T>* after, const T& item) {
    if (head == NULL)
        return InsertHead(head, item);
    return InsertHead(after->next, item);
}

template <typename T>
Node<T>* InsertBefore(Node<T>*& head, Node<T>* before, const T& item) {
    Node<T>* previous = PreviousNode(head, before);
    // beginning of list case
    if (previous == NULL) {
        head = new Node<T>(item, head);
        return head;
    }
    else {
        Node<T>* addNode = new Node<T>(item, previous->next);
        previous->next = addNode;
        return addNode;
    }
}

// returns the a pointer to the node behind
template <typename T>
Node<T>* PreviousNode(Node<T>* head, Node<T>* previous) {
    if (head == NULL)
        assert("head node is null somehow" == "");
    if (head == previous)
        return NULL;
    if (head->next == previous)
        return head;
    else
        return PreviousNode(head->next, previous);
}

template <typename T>
T DeleteNode(Node<T>*& head, Node<T>* deleteThis) {
    if (head == NULL)
        assert("tried to delete non existant node or empty list" == "");
    Node<T>* previous = PreviousNode(head, deleteThis);
    T temp = deleteThis->data;
    if (previous == NULL)
        head = deleteThis->next;
    else
        previous->next = deleteThis->next;
    delete deleteThis;
    return temp;
}
template <typename T>
Node<T>* CopyList(Node<T>* head) {
    if (head == NULL)
        return NULL;
    return new Node<T>(head->data, CopyList(head->next));
}

template <typename T>
void ClearList(Node<T>*& head) {
    if (head == NULL)
        return;
    if (head->next != NULL)
        ClearList(head->next);
    delete head;
    head = NULL;
}

template <typename T>
T& At(Node<T>* head, int pos) {
    if (head == NULL)
        assert("index out of bounds" == "");
    if (pos == 0)
        return head->data;
    else
        return At(head->next, pos - 1);
}

// returns the node the item should be after, null if it should be placed in
// front
template <typename T>
Node<T>* WhereThisGoes(Node<T>* head, T item, bool ascending = true) {
    // if list is empty, return null to indicate item should be placed in front
    if (head == NULL)
        return NULL;

    if (ascending) {
        if (item < head->data)
            return NULL;
        if (head->next == NULL || item < head->next->data)
            return head;
        return WhereThisGoes(head->next, item, ascending);
    } else {
        if (item > head->data)
            return NULL;
        if (head->next == NULL || item > head->next->data)
            return head;
        return WhereThisGoes(head->next, item, ascending);
    }
}

template <typename T>
Node<T>* InsertSorted_and_add(Node<T>*& head, T item, bool ascending = true) {
    Node<T>* location = WhereThisGoes(head, item, ascending);
    if (location == NULL)
        return InsertHead(head, item);
    return InsertAfter(head, location, item);
}

template <typename T>
Node<T>* InsertSorted(Node<T>*& head, T item, bool ascending = true) {
    Node<T>* location = WhereThisGoes(head, item, ascending);
    if (location == NULL) {
        // if list is empty
        if (head->next == NULL) 
            return InsertHead(head, item);
        else if (head->next->data != item)
            return InsertHead(head, item);
    }
    if (location->data != item)
        return InsertAfter(head, location, item);
    return NULL;
}