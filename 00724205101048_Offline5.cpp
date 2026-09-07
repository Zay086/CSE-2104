#include <bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* prev;
    node* next;
};
node* header = nullptr;
node* tail = nullptr;
int counting=1;
//1:Insert First:

void insert_first(int data){

    node* temp= (node*)malloc(sizeof(node));
    temp->data=data;
    temp->prev=nullptr;
    temp->next=nullptr;

    if(header==nullptr){
        header=temp;
        tail=temp;
    }
    else{
        temp->next=header;
        header->prev=temp;
        header=temp;
        counting++;
    }
}

//2.Insert Last

void insert_last(int data){

    node* temp= (node*)malloc(sizeof(node));
    temp->data=data;
    temp->prev=nullptr;
    temp->next=nullptr;

    if(header==nullptr){
        header=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        counting++;
    }
}

//3a. Insert at given position

void insert_at_position(int data, int position){

    node* temp= (node*)malloc(sizeof(node));
    temp->data=data;
    temp->prev=nullptr;
    temp->next=nullptr;

    if(position<0){
        cout<<"Invalid position"<<endl;
        return;
    }

    if(position==1 || header==nullptr){
        insert_first(data);
        return;
    }

    node* ptr=header;
    
    while(ptr->next!=nullptr && counting<position){
        ptr=ptr->next;
    }

    if(ptr->next==nullptr){
        insert_last(data);
        return;
    }

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;
    counting++;
}

//3b. Insert after given value

void insert_after_value(int data, int value){

    node* temp= (node*)malloc(sizeof(node));
    temp->data=data;
    temp->prev=nullptr;
    temp->next=nullptr;

    node* ptr=header;
    
    while(ptr!=nullptr && ptr->data!=value){
        ptr=ptr->next;
    }

    if(ptr==nullptr){
        cout<<"Value not found"<<endl;
        return;
    }

    if(ptr==tail ){
        insert_last(data);
        return;
    }

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;
    counting++;
}

//4 Delete First
void delete_first(){
    if(header==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    node* temp=header;
    header=header->next;

    if(header!=nullptr){
        header->prev=nullptr;
    }
    else{
        tail=nullptr;
    }

    free(temp);
    counting--;
}

//5. Delete Last
void delete_last(){
    if(header==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    node* temp=tail;
    tail=tail->prev;

    if(tail!=nullptr){
        tail->next=nullptr;
    }
    else{
        header=nullptr;
    }

    free(temp);
    counting--;
}

//6a. Delete at given position
void delete_at_position(int position){
    if(position<0 || position>counting){
        cout<<"Invalid position"<<endl;
        return;
    }

    if(position==1){
        delete_first();
        return;
    }

    node* ptr=header;
    int count=1;

    while(ptr!=nullptr && count<position){
        ptr=ptr->next;
        count++;
    }

    if(ptr==nullptr){
        cout<<"Position not found"<<endl;
        return;
    }

    if(ptr==tail){
        delete_last();
        return;
    }

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);
    counting--;
}

//6b. Delete by value
void delete_by_value(int value){
    node* ptr=header;

    while(ptr!=nullptr && ptr->data!=value){
        ptr=ptr->next;
    }

    if(ptr==nullptr){
        cout<<"Value not found"<<endl;
        return;
    }

    if(ptr==header){
        delete_first();
        return;
    }

    if(ptr==tail){
        delete_last();
        return;
    }

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;

    free(ptr);
    counting--;

}
//7a.Printilng_Forward
void Printing_Forward(){

    node* ptr=header;

    if(ptr==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

//7b.Printing_Backward
void Printing_Backward(){

    node* ptr=tail;

    if(ptr==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}

//8. Searching
void Searching(int value){
    node* ptr=header;
    int position=1;

    while(ptr!=nullptr && ptr->data!=value){
        ptr=ptr->next;
        position++;
    }

    if(ptr==nullptr){
        cout<<"Value not found"<<endl;
        return;
    }

    cout<<"Value found at position: "<<position<<endl;
    return;
}

//9.Last Node
void Last_Node(){
    if(tail==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    cout<<"Last node value: "<<tail->data<<endl;
}

//10.Previous of the last node
void Previous_of_Last_Node(){
    if(tail==nullptr || tail->prev==nullptr){
        cout<<"No previous node"<<endl;
        return;
    }

    cout<<"Previous of last node value: "<<tail->prev->data<<endl;
}

//11.Size of the list
void Size_of_List(){
    cout<<"Size of the list: "<<counting<<endl;
}

//12.Reverse list Printing
void Reverse_List_Printing(){
    node* ptr=tail;

    if(ptr==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}


int main(){

    insert_last(10);
    insert_last(15);
    insert_last(16);
    insert_last(20);
    insert_last(25);

    cout<<"The Initial list is (forward): ";
    Printing_Forward();
    cout<<endl;

    cout<<"The Initial list is (backward): ";
    Printing_Backward();

    insert_first(5);
    cout<<"After inserting 5 at first: ";
    Printing_Forward();
    cout<<endl;

    insert_at_position(12, 4);
    cout<<"After inserting 12 at position 4: ";
    Printing_Forward();
    cout<<endl;

    insert_after_value(18, 16);
    cout<<"After inserting 18 after value 16: ";
    Printing_Forward();
    cout<<endl;

    Searching(12);
    
    cout<<"Last node value: ";
    Last_Node();
    cout<<endl;

    cout<<"Previous of last node value: ";
    Previous_of_Last_Node();
    cout<<endl;

    cout<<"Size of the list: ";
    Size_of_List();
    cout<<endl;

    cout<<"Reverse list printing: ";
    Reverse_List_Printing();
    cout<<endl;

    cout<<"After deleting first node: ";
    delete_first();
    Printing_Forward();
    cout<<endl;

    cout<<"After deleting last node: ";
    delete_last();
    Printing_Forward();
    cout<<endl;

    cout<<"After deleting node at position 2: ";
    delete_at_position(2);
    Printing_Forward();
    cout<<endl;

    cout<<"After deleting node with value 16: ";
    delete_by_value(16);
    Printing_Forward();
    cout<<endl;






}