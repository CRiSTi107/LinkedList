#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList *lst = new LinkedList();
    LinkedList::node *ptr_node;

    lst->Add(2);
    lst->Add(3);
    lst->Add(4);
    lst->Add(10);
    lst->Add(-50);
    lst->Add(100);

    cout<<"Head: "<<lst->get_head()<<endl
        <<"Size: "<<lst->get_size()<<endl
        <<"Tail: "<<lst->get_tail()<<endl;

    for(LinkedList::node* _iterator = lst->get_head(); _iterator != NULL; _iterator = _iterator->next)
    {
        cout<<"["<<_iterator<<"] = "<<_iterator->data<<endl;

        if(_iterator->data == 2)
            ptr_node = _iterator;

    }

    lst->Remove(100);
    lst->Remove(ptr_node);

    lst->Add(200);

    lst->InsertAt(40, 5);




    cout<<endl<<endl<<endl;

    cout<<"Head: "<<lst->get_head()<<endl
        <<"Size: "<<lst->get_size()<<endl
        <<"Tail: "<<lst->get_tail()<<endl;

    for(LinkedList::node* _iterator = lst->get_head(); _iterator != NULL; _iterator = _iterator->next)
    {
        cout<<"["<<_iterator<<"] = "<<_iterator->data<<endl;
    }




    return 0;
}