#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H
#include <iostream>

template <typename list_type> class CustomList
{
private:

    struct node{        //node structure
        list_type data = 0;
        node* prev = nullptr;
        node* next = nullptr;
    };

    size_t size;
    node *first;
    node *last;

    node* find(size_t n);

public:
    CustomList();
    void push_back(list_type data);
    void push_forward(list_type data);
    void pop_back();
    void pop_forward();

    void swap(size_t initial, size_t target);
    void sort();

    size_t getSize();
    void set(size_t target, size_t target_data);
    void show();


};

#endif // CUSTOMLIST_H
