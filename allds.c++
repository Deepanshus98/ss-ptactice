//Linked list ans uu circular
#include <iostream>
using namespace std;
struct Node { 
   int data; 
   Node *prev; 
   Node *next; 
}; 
Node* head = NULL; 
void insert(int newdata) { 
   Node* newnode = new Node; 
   newnode->data  = newdata; 
   newnode->prev = NULL; 
   newnode->next = head;     
   if(head !=  NULL) 
      head->prev = newnode ;     
      head = newnode; 
}   
void display() { 
   Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
  } 
} 
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The doubly linked list is: ";
   display(); 
   return 0; 
}
//BST
#include<stdio.h>
#include<stdlib.h>
struct node{
   int key;
   node *left, *right;
};
struct node *newNode(int item){
   struct node *temp = new Node;
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}
struct node* search(struct node* root, int key){
   if (root == NULL || root->key == key)
      return root;
   if (root->key < key)
      return search(root->right, key);
   return search(root->left, key);
}
struct node* insert(struct node* node, int key){
   if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insert(node->left, key);
      else if (key > node->key)
         node->right = insert(node->right, key);
   return node;
}
int main(){
   struct node *root = NULL;
   root = insert(root, 23);
}
//Trie
#include <bits/stdc++.h>

using namespace std;
struct Node {
  Node * links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void deleteEnd() {
    cntEndWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie {
  private:
    Node * root;

  public:
    /** Initialize your data structure here. */
    Trie() {
      root = new Node();
    }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      node = node -> get(word[i]);
      node -> increasePrefix();
    }
    node -> increaseEnd();
  }

 int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }


  int countWordsStartingWith(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
      } else {
        return 0;
      }
    }
    return node -> getPrefix();
  }

  void erase(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
        node -> reducePrefix();
      } else {
        return;
      }
    }
    node -> deleteEnd();
  }
};

int main() {
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}
//stack 
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};

class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};

//Queue
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};

//heap
//Heap
#include <bits/stdc++.h>
using namesapce std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent =index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
            
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void delete(){
        if(size==o){
            cout<<"nothing to delete";
            return;
        }
        arr[1]==arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftidx =2*i;
            int rightidx=2*i+1;
            if(leftidx<size && arr[i]<arr[leftidx]){
                swap(arr[i],arr[leftidx]);
                i=leftidx;
            }
            else if(rightidx<size && arr[i]<arr[rightidx]){
                swap(arr[i],arr[rightidx]);
                i=rightidx;
            }
            else{
                return;
            }
            
        }
        
    
    }
    void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left <= n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]< arr[right]){
            largest=right;
        }
        if(largest !=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
	 void heapsort(int arr[],int n){
        int size=n;
        while(size>1){
            swap(arr[size],arr[1]);
            size--;
            heapify(arr,size,1);
        }
    }
}
