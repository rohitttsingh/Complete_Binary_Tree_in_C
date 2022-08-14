// Online C compiler to run C program online
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *create(int data){
    Node *newnode = new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    
    return newnode;
}

Node *insert(Node *head, int data){
    
    if(head==NULL)
    head = create(data);
    
    else if(head->left==NULL)
    head->left = insert(head->left,data);
    
    else 
    head->right = insert(head->right,data);
    
    return head;
    
}

void print(Node *head){
    
    if(head==NULL) 
    return ;
    
    print(head->left);
    print(head->right);

    cout<<head->data<<" ";

}

void LOT(Node *head){
    queue<Node *> Q;
    Q.push(head);
    
    while(!Q.empty()){
        Node *current = Q.front();
        cout<<current->data<<" ";
        
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();

    }
}

int main() {
    Node *head=NULL;
    
    head = insert(head,12);
    head = insert(head,32);
    head = insert(head,42);
    head = insert(head,52);
    head = insert(head,1);
    head = insert(head,123);
    head = insert(head,13);
 
    print(head);
    
    cout<<endl;
    LOT(head);

    return 0;
}
