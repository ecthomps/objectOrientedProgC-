/*
   Code from Oct 11th 
   (Last day to register to vote!!!)
   Yet even MORE fun with pointers and 
   linked lists
*/
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node * next;
    Node(string d = "", Node * nxt =nullptr){
        data = d;
        next = nxt;
    }
    
};

ostream & operator<<(ostream & out, Node * head){
  Node * ptr = head;
  while (ptr != nullptr){
    out<<ptr->data<<" ";
    ptr = ptr->next;
  }
return out;    
}

void insertRear(Node * & head, string data){
    Node * ptr = head;
    if (head == nullptr){
        head = new Node(data);
    }
    else {
    
      while (ptr->next != nullptr)
         ptr = ptr->next;
       ptr->next = new Node(data);     
    }
}

void deleteWord(Node * & head, Node * ptr){
    Node *walker = head;
    if (head== nullptr)
      return;
    else if (head == ptr){
        head= ptr->next;
        delete ptr;
    }
    else
    {
    while(walker != nullptr && walker->next != ptr)
       walker = walker->next;
    walker->next = ptr->next;
    delete ptr;
    }
}

void insertFront(Node * & head, string data){
    Node * ptr = new Node(data, head);
    head = ptr;
}
/*
Node * find(Node * head, string target){
 //   pre : the list pointed to by head ends in a nullptr
 //   post : returns ptr such that ptr->data = target || 
 //                                        ptr = nullptr

if (head == nullptr)
    return nullptr;
else if (head->data == target )
    return head;
else
   return (find(head->next, data));

}
*/
Node * find (Node * head, string target){
  Node *ptr = head;
  while (ptr != nullptr && ptr->data != target)
    ptr = ptr->next;
  return ptr;
}
void insertBefore(Node * & head, string word, string toInsert){
    Node *ptr = find(head, word);
    Node *walker = head;
    if (ptr == nullptr || head==ptr) // change the head
        head = new Node(toInsert, head);
    else {
        while (walker ->next != ptr)
         walker = walker->next;
        walker->next = new Node(toInsert, walker->next);
    }
}

int main(){
    Node * head = nullptr;
    Node * revHead = nullptr;
    Node * ptr;
    string word;
    string position;
    string words[] = {"cat", "dog", "fish","frog","dragon","dino"};
    for (int i = 0; i < 6; i++){
        //cout<<"gimme a word : ";
        //cin>>word;
        insertRear(head, words[i]);
        insertFront(revHead, words[i]);
    }
    cout<<"The words in ordeer are : ";
    cout<<head<<endl;
    cout<<"the words reversed are : ";
    cout<<revHead<<endl;
    cout<<"gimme a word to delete : ";
    cin>> word;
    ptr = find(head, word);
    if (ptr == nullptr)
       cout<<"word not in list\n";
     else {
         deleteWord(head, ptr);
         cout<<head<<endl;
     }  
     for (int i = 0; i < 3 ; i++){
       cout<<"gimme a word to add : ";
      cin>> word;  
      cout<<"gimme a what word to insert before : ";
      cin>> position;  
      insertBefore(head, position, word);
      cout<<"the resulting list is : "<<head<<endl;
     }
     
    return 0;
}



