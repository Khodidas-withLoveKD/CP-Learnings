#include <iostream>

using namespace std;

class Node{

public:
    int value;
    Node *left_child;
    Node *right_child;
};

class bst{

    Node *root;

public:
    bst(){
        root = NULL;
    }
    bool isempty(){
        return root == NULL ;
    }
    void insert(int data);
    void traverse();
    void inorder(Node *root);
    void preorder(Node *root);
    void postorder(Node *root);
};

void bst::insert(int data){

    Node *new_node = new Node;
    new_node->value = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    if(isempty()){
        root = new_node;
        return;
    }

    Node *temp = root;

    while(temp != NULL){        //->left_child != NULL || temp->right_child != NULL){

        if(data < temp->value){
            if(temp->left_child != NULL)
                temp = temp-> left_child;
            else{
                temp->left_child = new_node;
                return;
            }
        }
        else{
            if(temp->right_child != NULL)
                temp = temp->right_child;
            else{
                temp->right_child = new_node;
                return;
            }
        }
    }
}

void bst :: inorder (Node *root){

    if(root->left_child != NULL)
        inorder(root->left_child);

    cout<<root->value<<" ";
    if(root->right_child != NULL){
        inorder(root->right_child);
    }

    return ;
}
void bst :: preorder(Node *root){

    cout<<root->value<<" ";
    if(root->left_child != NULL)
        preorder(root->left_child);

    if(root->right_child != NULL)
        preorder(root->right_child);

    return ;
}
void bst :: postorder(Node *root){

    if(root->left_child != NULL)
        postorder(root->left_child);

    if(root->right_child != NULL)
        postorder(root->right_child);

    cout<<root->value<<" ";
}
void bst :: traverse(){

    cout<<"\n\n------INORDER-----\n\n";
    inorder(root);
    cout<<"\n\n------PREORDER-----\n\n";
    preorder(root);
    cout<<"\n\n------POSTORDER-----\n\n";
    postorder(root);
}
int main()
{
    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30);

    cout<<"Binary tree created: "<<endl;
    b.traverse();

}
