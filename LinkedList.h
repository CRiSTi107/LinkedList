#ifndef LINKED_LIST_H

#define LINKED_LIST_H
#include "LinkedList.h"

#define NULL 0L

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    struct node
    {
        int data;
        struct node *next;
    };

    void Add(int value);
    void InsertAt(int value, int index);
    void Remove(int value);
    void Remove(node* ptr_node);
    node* Search(int value);

    node* get_head();
    node* get_tail();
    int   get_size();
    bool  is_empty();

private:
    node *head = NULL;
    node *precurrent = NULL;
    node *current = NULL;
    node *temp = NULL;
    node *tail = NULL;

    int ListSize;

};


#endif // LINKED_LIST_H



