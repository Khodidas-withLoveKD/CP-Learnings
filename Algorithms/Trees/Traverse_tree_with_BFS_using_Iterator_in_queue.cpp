#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

Node* createNode(int v){
    Node *node = new Node();
    node->value = v;
    node->left = node->right = NULL;
    return node;
}
void printTree(Node *root){
    cout<<root->value<<" ";
    if(root->left != NULL)
        printTree(root->left);
    if(root->right != NULL)
        printTree(root->right);
}
void BFS(Node *root){
    queue<Node*> q;

    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        cout<<node->value<<" ";
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
}
int main(){
/*
            1
           / \
          2   3
         /
        4
*/
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);

    cout<<"Sadu print\n";
    printTree(root);
    cout<<"\nBFS: ";
    BFS(root);
}
