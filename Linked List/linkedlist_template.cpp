#include <iostream>
using namespace std;
template<typename tValue>
struct node
{
    tValue data;
    struct node *next;
};
template<typename tValue>
class linked_list
{
    node<tValue> *head,*tail;
    static int count;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(tValue n)
    {
        node<tValue> *tmp=new node<tValue>;
        tmp->data =n;
        tmp->next = NULL;
        if(head == NULL)
        {
            head =tmp;
            tail = tmp;
        }
        else
        {
            tail ->next =tmp;
            tail=tail->next;
        }
        count++;
    }
    void disp()
    {
        node<tValue> *tmp = head;
        if(tmp==NULL)
        {
            cout<<"Linked list is empty";
        }
        while(tmp!=NULL)
        {
            cout<<tmp->data<<"=>";
            tmp=tmp->next;
        }
        disp_counnt();
    }
    static void disp_counnt()
    {
        cout<<"\nNumber of Nodes in Linked list :"<<count<<"\n";
    }
    void deleteNode(int position)
    {
        node<tValue> *temp = head;
        if(temp==NULL )
        {
            cout<<"Linked list is empty";
            return;
        }
        if (temp == NULL || temp->next == NULL)
            return;
        if (position == 0)
        {
            head = temp->next;
            free(temp);
            return;
        }
        for (int i=0; temp!=NULL && i<position-1; i++)
            temp = temp->next;
        node<tValue> *next = temp->next->next;
        count--;
        free(temp->next);
        temp->next = next;
    }
    void insertPos( int pos, float ele)
    {
        node<tValue>** current = &head;
        if (pos < 1 || pos > count + 1)
            cout << "Invalid position!" << endl;
        else
        {
            while (pos--)
            {
                if (pos == 0)
                {

                    node<tValue> *temp=new node<tValue>;
                    temp->data =ele;
                    temp->next=NULL;
                    temp->next = *current;
                    *current = temp;
                }
                else
                    current = &(*current)->next;
            }
            count++;
        }
    }
};
template<typename tValue>
int linked_list<tValue>::count=0;
int main()
{
    int tchoice,mchoice;
    linked_list<int> obj1;
    linked_list<float> obj2;
    linked_list<long> obj3;
    linked_list<char> obj4;
    do
    {
        cout<<"----------------------\n";
        cout<<"1.Int Type\n2.float type\n3.long type\n4.char type\n5.Exit\n";
        cout<<"----------------------\n";
        cout<<"Enter the choice of data type:\n";
        cin>>tchoice;
        switch(tchoice)
        {
        case 1:
            do
            {
                cout<<"---------------------------------------\n";
                cout<<"1.Insert the new node\n2.Display and Count of nodes in Linked list\n3.Insert the node at particular position\n4.Delete the node at particular position\n5.Exit\n";
                cout<<"---------------------------------------\n";
                cout<<"Enter the operation to perform:\n";
                cin>>mchoice;
                switch(mchoice)
                {
                case 1:
                    int a;
                    cout<<"Enter the element to insert:";
                    cin>>a;
                    obj1.add_node(a);
                    break;
                case 2:
                    obj1.disp();
                    break;
                case 3:
                    int in_pos;
                    int ele;
                    cout<<"Enter the position of node to insert:";
                    cin>>in_pos;
                    cout<<"Enter the element to insert:";
                    cin>>ele;
                    obj1.insertPos(in_pos,ele);
                    break;
                case 4:
                    int pos;
                    cout<<"Enter the position of node to delete:";
                    cin>>pos;
                    obj1.deleteNode(pos);
                    break;
                default:
                    break;
                }
            }
            while(mchoice<=4);
            break;
        case 2:
            do
            {
                cout<<"---------------------------------------\n";
                cout<<"1.Insert the new node\n2.Display and Count of nodes in Linked list\n3.Insert the node at particular position\n4.Delete the node at particular position\n5.Exit\n";
                cout<<"---------------------------------------\n";
                cout<<"Enter the operation to perform:\n";
                cin>>mchoice;
                switch(mchoice)
                {
                case 1:
                    float a;
                    cout<<"Enter the element to insert:";
                    cin>>a;
                    obj2.add_node(a);
                    break;
                case 2:
                    obj2.disp();
                    break;
                case 3:
                    int in_pos;
                    float ele;
                    cout<<"Enter the position of node to insert:";
                    cin>>in_pos;
                    cout<<"Enter the element to insert:";
                    cin>>ele;
                    obj2.insertPos(in_pos,ele);
                    break;
                case 4:
                    int pos;
                    cout<<"Enter the position of node to delete:";
                    cin>>pos;
                    obj2.deleteNode(pos);
                    break;
                default:
                    break;
                }
            }
            while(mchoice<=4);
            break;
        case 3:
            do
            {
                cout<<"---------------------------------------\n";
                cout<<"1.Insert the new node\n2.Display and Count of nodes in Linked list\n3.Insert the node at particular position\n4.Delete the node at particular position\n5.Exit\n";
                cout<<"---------------------------------------\n";
                cout<<"Enter the operation to perform:\n";
                cin>>mchoice;
                switch(mchoice)
                {
                case 1:
                    long a;
                    cout<<"Enter the element to insert:";
                    cin>>a;
                    obj3.add_node(a);
                    break;
                case 2:
                    obj3.disp();
                    break;
                case 3:
                    int in_pos;
                    long ele;
                    cout<<"Enter the position of node to insert:";
                    cin>>in_pos;
                    cout<<"Enter the element to insert:";
                    cin>>ele;
                    obj3.insertPos(in_pos,ele);
                    break;
                case 4:
                    int pos;
                    cout<<"Enter the position of node to delete:";
                    cin>>pos;
                    obj3.deleteNode(pos);
                    break;
                default:
                    break;
                }
            }
            while(mchoice<=4);
            break;
        case 4:
            do
            {
                cout<<"---------------------------------------\n";
                cout<<"1.Insert the new node\n2.Display and Count of nodes in Linked list\n3.Insert the node at particular position\n4.Delete the node at particular position\n5.Exit\n";
                cout<<"---------------------------------------\n";
                cout<<"Enter the operation to perform:\n";
                cin>>mchoice;
                switch(mchoice)
                {
                case 1:
                    char a;
                    cout<<"Enter the element to insert:";
                    cin>>a;
                    obj4.add_node(a);
                    break;
                case 2:
                    obj4.disp();
                    break;
                case 3:
                    int in_pos;
                    char ele;
                    cout<<"Enter the position of node to insert:";
                    cin>>in_pos;
                    cout<<"Enter the element to insert:";
                    cin>>ele;
                    obj4.insertPos(in_pos,ele);
                    break;
                case 4:
                    int pos;
                    cout<<"Enter the position of node to delete:";
                    cin>>pos;
                    obj4.deleteNode(pos);
                    break;
                default:
                    break;
                }
            }
            while(mchoice<=4);
            break;
        default:
            exit(0);
        }
    }
    while(tchoice<=4);
    return 0;
}

