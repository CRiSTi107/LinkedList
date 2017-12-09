#ifndef LINKED_LIST_H

#include "LinkedList.h"
#include <stdlib.h>

#define NULL 0L

LinkedList::LinkedList()
{
    head = NULL;
    precurrent = NULL;
    current = NULL;
    temp = NULL;
    tail = NULL;
}

LinkedList::~LinkedList()
{
    for(LinkedList::node* _iterator = head; _iterator != NULL; )
    {
        LinkedList::node* tmp = _iterator;
        _iterator = _iterator->next;

        delete tmp;

        ListSize--;
    }

    tail = NULL;
    head = NULL;
}



void LinkedList::Add(int value) {
    if(head == NULL)
    {
        head = (node*)malloc(sizeof(node));

        if(head == NULL) return;

        head -> data = value;
        head -> next = NULL;

        current = head;
        precurrent = head;

        tail = head;

        ListSize = 1;
    }
    else
    {
        temp = (struct node*)malloc(sizeof(node));

        if(temp == NULL) return;


        temp -> data = value;
        temp -> next = NULL;

        /*precurrent = temp;

        current -> next = precurrent;

        current = precurrent;*/

        tail->next = temp;
        tail = temp;

        ListSize++;
    }

}

void LinkedList::InsertAt(int value, int index) {

    if(index < 0)
        return;
    else if(index == 0)
    {
        temp = (struct node*)malloc(sizeof(node));

        if(temp == NULL) return;

        temp->data = value;
        temp->next = head;

        head = temp;

        ListSize++;
    }
    else if(index == ListSize)
    {
        temp = (struct node*)malloc(sizeof(node));

        if(temp == NULL) return;

        temp->data = value;
        temp->next = NULL;

        tail->next = temp;

        tail = temp;

        ListSize++;

    }
    else if(index > ListSize)
    {
        Add(value);
    }
    else
    {
        int temp_index = 0;

        for(LinkedList::node* _iterator = head; _iterator != NULL && temp_index <= index; _iterator = _iterator->next)
            if(_iterator->next != NULL)
                if(temp_index++ == index - 1)
                {
                    temp = (struct node*)malloc(sizeof(node));

                    if(temp == NULL) return;

                    temp->data = value;

                    precurrent = _iterator;

                    current = precurrent->next;

                    precurrent->next = temp;

                    temp->next = current;

                    if(current->next == NULL)
                        tail = precurrent;

                    ListSize++;
                }
    }
}

void LinkedList::Remove(int value) {
    if(head != NULL)
        if(head->data == value)
        {
            if(ListSize > 1)
            {
                temp = head;
                head = head->next;
                delete temp;

                ListSize--;
            }
            else if(ListSize == 1)
            {
                delete head;
                head = NULL;

                tail = NULL;

                ListSize--;
            }
        }

    for(LinkedList::node* _iterator = head; _iterator != NULL; _iterator = _iterator->next)
    {
        if(_iterator->next != NULL)
            if(_iterator->next->data == value)
            {
                precurrent = _iterator;
                temp = precurrent->next;
                current = temp->next;

                precurrent->next = current;

                delete temp;

                if(precurrent->next == NULL)
                    tail = precurrent;

                ListSize--;

                return;
            }
    }
}

void LinkedList::Remove(node *ptr_node) {
    if(head == ptr_node)
    {
        if(ListSize > 1)
        {
            temp = head;
            head = head->next;
            delete temp;

            ListSize--;
        }
        else if(ListSize == 1)
        {
            delete head;
            head = NULL;

            ListSize--;
        }
    }

    for(LinkedList::node* _iterator = head; _iterator != NULL; _iterator = _iterator->next)
    {
        if(_iterator->next != NULL)
            if(_iterator->next == ptr_node)
            {
                precurrent = _iterator;
                temp = precurrent->next;
                current = temp->next;

                precurrent->next = current;

                delete temp;

                if(precurrent->next == NULL)
                    tail = precurrent;

                ListSize--;

                return;
            }
    }
}

LinkedList::node *LinkedList::Search(int value) {
    for(LinkedList::node* _iterator = head; _iterator != NULL; _iterator = _iterator->next)
    {
        if(_iterator->data == value)
            return _iterator;
    }
}



LinkedList::node* LinkedList::get_head() {
    return head;
}

LinkedList::node* LinkedList::get_tail() {
    return tail;
}

int LinkedList::get_size() {
    return ListSize;
}

bool LinkedList::is_empty() {
    return (ListSize == 0) ? true : false;
}

#endif // LINKED_LIST_H