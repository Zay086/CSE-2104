#include <bits/stdc++.h>
using namespace std;

int counting=0;

struct node{
    
    int data;
    struct node * link;
    
};


node *header=nullptr;


//1:Insert First:

void insert_first(int data){

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    counting++;
    
    if(header==nullptr){
        header=temp;
        header->link=nullptr;
        
    }
    else{

        temp->link=header;
        header=temp;
        
    }
}

//2:Insert Last

void insert_last(int data){
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=nullptr;
    counting++;

    if(header==nullptr){
        header=temp;
    }
    else{
        
        struct node * ptr=header;
        
        while(ptr->link!=nullptr){
            ptr=ptr->link;
        }
        
        ptr->link=temp;
    }
}

//3a:Insert at Position
void insert_at_position(int data,int pos){
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    counting++;
    if(pos<1){
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(pos==1){
        temp->link=header;
        header=temp;
    }
    
    struct node * ptr=header;
        
    for(int i=1;ptr!=nullptr && i<pos-1;i++){
        ptr=ptr->link;
    }
    if(ptr==nullptr){
        cout<<"Position out of bounds"<<endl;
        return;
    }
     
    temp->link=ptr->link;
    ptr->link=temp;
    
}

//3b:Insert between two nodes after value.
void insert_after_value(int data, int value) {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    counting++;

    struct node *ptr = header;
    while (ptr != nullptr && ptr->data != value) {
        ptr = ptr->link;
    }

    if (ptr == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    temp->link = ptr->link;
    ptr->link = temp;
}

//4:Delete First:
void delete_first() {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node *temp = header;
    header = header->link;
    free(temp);
    counting--;
}

//5:Delete Last:
void delete_last() {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (header->link == nullptr) {
        free(header);
        header = nullptr;
        counting--;
        return;
    }

    struct node *ptr = header;
    while (ptr->link->link != nullptr) {
        ptr = ptr->link;
    }

    free(ptr->link);
    ptr->link = nullptr;
    counting--;
}  

//6a:Delete at Position:
void delete_at_position(int pos) {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    if (pos == 1) {
        struct node *temp = header;
        header = header->link;
        free(temp);
        counting--;
        return;
    }

    struct node *ptr = header;
    for (int i = 1; ptr != nullptr && i < pos - 1; i++) {
        ptr = ptr->link;
    }

    if (ptr == nullptr || ptr->link == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    struct node *temp = ptr->link;
    ptr->link = temp->link;
    free(temp);
    counting--;
}

//6b:Delete by Value:
void delete_by_value(int value) {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (header->data == value) {
        struct node *temp = header;
        header = header->link;
        free(temp);
        counting--;
        return;
    }

    struct node *ptr = header;
    while (ptr->link != nullptr && ptr->link->data != value) {
        ptr = ptr->link;
    }

    if (ptr->link == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    struct node *temp = ptr->link;
    ptr->link = temp->link;
    free(temp);
    counting--;
}

//7:Display:
void printing() {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node *ptr = header;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

//8:Search:
void searching(int value) {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node *ptr = header;
    int position = 1;
    while (ptr != nullptr) {
        if (ptr->data == value) {
            cout << "Value found at position: " << position << endl;
            return;
        }
        ptr = ptr->link;
        position++;
    }

    cout << "Value not found" << endl;
}

//9:Printing Last Node:
void print_last_node() {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node *ptr = header;
    while (ptr->link != nullptr) {
        ptr = ptr->link;
    }

    cout << "Last node value: " << ptr->data << endl;
}

//(10) previous_of_last_node() -> function to print the value of the previous node of last node
void previous_of_last_node() {
    if (header == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (header->link == nullptr) {
        cout << "There is no previous node of the last node" << endl;
        return;
    }

    struct node *ptr = header;
    while (ptr->link->link != nullptr) {
        ptr = ptr->link;
    }

    cout << "Previous node of last node value: " << ptr->data << endl;
}

//(11) list_size() -> function to print the size of the linked list
int list_size() {
    return counting;
}

//reversePrint() -> function to print the linked list in reverse order

void reversePrint(struct node *ptr) {

    if (ptr == nullptr) {
        return;
    }
    reversePrint(ptr->link);
    cout << ptr->data << " ";
}

int main() {
	
    insert_last(10);
    insert_last(20);
    insert_last(8);
    insert_last(6);

    cout << "Initial Linked List: ";
    printing();
    cout<<endl;

    insert_at_position(12, 2);
    cout << "Linked List after inserting 12 at position 3: ";
    printing();
    cout<<endl;

    insert_after_value(15, 20);
    cout << "Linked List after inserting 15 after value 20: ";
    printing();
    cout<<endl;

    cout << "Searching for value 8: ";
    searching(8); 
    cout<<endl;

    cout <<"Last node of the linked list: ";
    print_last_node();
    cout<<endl;

    cout <<"Previous node of last node: ";
    previous_of_last_node();
    cout<<endl;

    cout <<"Reverse of the linked list: ";
    reversePrint(header);
    cout << endl;

    cout <<"Size of the linked list: " << list_size() << endl;

    delete_first();
    cout << "Linked List after deleting first node: ";
    printing();
    cout << endl;

    delete_last();
    cout << "Linked List after deleting last node: ";
    printing();
    cout << endl;

    delete_at_position(2);
    cout << "Linked List after deleting node at position 2: ";
    printing();
    cout << endl;

    delete_by_value(15);
    cout << "Linked List after deleting node with value 15: ";
    printing();
    cout << endl;

    return 0;


}