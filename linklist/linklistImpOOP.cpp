
#include <iostream>
#include <memory>

using namespace std;

class linklist
{
private:
    struct node
    {
        int data;
        shared_ptr<node> next_ptr;
    };
    node mylist;
    shared_ptr<node> head;

public:
    linklist()
    {
        mylist.data = 0;
        mylist.next_ptr = nullptr;
        head = nullptr;
    }
    void add_data(int data)
    {
        if (head == nullptr)
        {
            head = make_shared<node>();
            head->data = data;
            head->next_ptr = nullptr;
        }
        else
        {
            shared_ptr<node> temp_node;
            temp_node = head;
            while (temp_node->next_ptr != nullptr)
            {
                temp_node = temp_node->next_ptr;
            }
            /*temp_node will be pointing to the last node*/
            temp_node->next_ptr = make_shared<node>();
            temp_node = temp_node->next_ptr;
            temp_node->data = data;
            temp_node->next_ptr = nullptr;
        }
    }
    void print_list()
    {
        shared_ptr<node> temp_node;
        temp_node = head;
        cout << endl;
        while (temp_node != nullptr)
        {
            cout << temp_node->data;
            temp_node = temp_node->next_ptr;
            if (temp_node != nullptr)
                cout << "-> ";
        }
        cout << endl;
    }

    bool search_list(int key)
    {
        shared_ptr<node> temp_node;
        temp_node = head;
        cout << endl;
        while (temp_node != nullptr)
        {
            if (temp_node->data == key)
                return 1;
            temp_node = temp_node->next_ptr;
        }
        return 0;
    }
    /***
     * The reason of following function is to enable the object of other list
     * to access the head so that it can travers the second list for the usage of merging.
     */
    shared_ptr<node> getHead()
    {
        return head;
    }


    void mergeSortedLists(shared_ptr<node> head2)
    {
        shared_ptr<node> mergedListHead;
        shared_ptr<node> mergedListTail;
        if (head == nullptr)
        {
            head = head2;
        }
        if (head2 == nullptr)
        {
            return;
        }

        if (head->data < head2->data)
        {
            mergedListHead = head;
            mergedListTail = head;
            head = head->next_ptr;
        }
        else
        {
            mergedListHead = head2;
            mergedListTail = head2;
            head2 = head2->next_ptr;
        }
        while (head != nullptr && head2 != nullptr)
        {
            if (head->data < head2->data)
            {
                mergedListTail->next_ptr = head;
                mergedListTail = head;
                head = head->next_ptr;
            }
            else
            {
                mergedListTail->next_ptr = head2;
                mergedListTail = head2;
                head2 = head2->next_ptr;
            }
        }
        if (head != nullptr)
            mergedListTail->next_ptr = head;
        else if (head2 != nullptr)
            mergedListTail->next_ptr = head2;
        head = mergedListHead;
    }
};

int main()
{
    linklist mylist1, mylist2;

    mylist1.add_data(455);
    mylist1.add_data(456);
    mylist1.add_data(899);

    mylist1.print_list();

    mylist2.add_data(3);
    mylist2.add_data(8);
    mylist2.add_data(12);

    mylist2.print_list();

    mylist1.mergeSortedLists(mylist2.getHead());
    mylist1.print_list();
}
