/*Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers*/




#include <iostream>


using namespace std;

struct node
{

    int value;
    node* next;   //singly linked list for hashing separate chaining for collision handling

}*HashTable[10];

class hashing
{
public:
    hashing()//constructor
    {
        for(int i=0;i<10;i++)
        {
            HashTable[i]=NULL;//initialize hashtable to NULL

        }
    }
    int HashFunction(int value)// We use division hashing method for this
    {
        return(value%10);// ****mod fun is:- index=data value%10**** coz table size is 10
    }
    node* create_node(int x) // if the collision is occure the element store in next key by using linked list
    {
        node* temp=new node;
        temp->next=NULL;
        temp->value=x;  //here x is whatever value passing through the node the value store in temp
        return temp;
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            node* temp=new node;
            temp=HashTable[i]; // whatever the value store in the index it assign to the temp variable
            cout<<"a["<<i<<"]: ";
            while(temp!=NULL)
            {

                cout<<"->"<<temp->value;
                temp=temp->next;
            }
            cout<<"\n";
        }
    }
    int searchElement(int value)
    {
        bool flag=false;
        int hash_val=HashFunction(value);// call HashFunction to calculate hash table of searching element
        node* entry=HashTable[hash_val]; // entry will point to calculate hash index of searching
        cout<<"\nElement Found at: ";
        while(entry!=NULL)
        {
            if(entry->value=value)//if matching is done
            {

                cout<<hash_val<<":"<<entry->value<<endl;//print like -> Element found at:Index:dataValue
                flag=true;
            }
            entry=entry->next;// next node will point as"entry"node
        }
        if(!flag)//entry==NULL
            return -1;
    }
    void deleteElement(int value)
    {
        int hash_val=HashFunction(value);//to calculate index of element to be deleted.
        node* entry=HashTable[hash_val];//entry node will point to that index for which data to be deleted
        if(entry==NULL)//if no data at entry node
        {
            cout<<"No Element Found: ";
            return;//then no element found
        }
        if(entry->value==value){
            HashTable[hash_val]=entry->next;
            return;
        }
        while((entry->next)->value!=value)
        {

            entry=entry->next;
        }
        entry->next=(entry->next)->next;
    }
    void insertElement(int value)   // for inserting element
    {
        int hash_val=HashFunction(value);// calculate the index of data to be inserted
        node* temp=new node;
        node* head=new node;
        head=create_node(value);//call create_node funtion to create head node with value to be inserted
        temp=HashTable[hash_val];//temp will point to location in hash table for calculate index of element to be inserted to check whether it is null?
        if(temp==NULL)
        {

            HashTable[hash_val]=head;//it is null?
        }
        else
        {

            while(temp->next!=NULL)
            {

                temp=temp->next; //while value not matching find next entry

            }
            temp->next=head;
        }
    }


};

int main()
{

    int ch;
    long int data,search,del;
    hashing h;
    do
    {
        cout<<"\nTelephone book of client:\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit";
        cout<<"\n Enter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n Enter phone no. to be inserted: ";
            cin>>data;
            h.insertElement(data);// h is object of class hashing
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout<<"\nEnter the no to be searched: ";
            cin>>search;

            //If the search function return -1 then we consider the element not found
            if(h.searchElement(search)==-1) // call search fun & it if return -1
            {

                cout<<"No element found at key";
                continue;
            }
            break;
        case 4:
            cout<<"Enter the no to be delete: ";
            cin>>del;
            h.deleteElement(del);
            cout<<"Phone no. Deleted"<<endl;
            break;
        }
    }while(ch!=5);
    return 0;
}
