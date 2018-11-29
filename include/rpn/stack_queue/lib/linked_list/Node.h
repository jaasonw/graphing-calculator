#pragma once
#include <cstddef>

template<typename T>
struct Node
{
    T data;
    Node<T>* next = NULL;
    Node(T data) : data(data) {};
    Node(T data, Node<T>* next) : data(data), next(next) {};
};