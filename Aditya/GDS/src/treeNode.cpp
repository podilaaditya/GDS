#include<iostream>
#include<vector>
using namespace std;

// template<class T> 
// class TreeNode{
//     private:
//     T t;
//     vector<TreeNode> children;

//     public:
//             TreeNode();
//             TreeNode(T& t){
//                 this->t=t;
//             }
//             void insertChild(T&t){
//                 this->children.push_back(
//                     TreeNode(t)
//                 );
//             }
// };
template<typename T>
class Node{
    public:
            Node<T> *left;
            Node<T> *right;
            T val;
            Node<T>(T val){
                this->val=val;
                left=right=nullptr;
            }
};


template<typename T>
class BTree{
    Node<T>* root;
    // int size=0;
    void Inorder(Node<T>* root){
         if(!root) return;
            Inorder(root->left);
            cout<<root->val<<" ";
            Inorder(root->right);
    }
    public:
        BTree(){
            root=nullptr;
        }
        void insert(T val){
            Node<T>* newNode=new Node<T>(val);
            if(root== nullptr){
                root=newNode;
                return;
            }
            Node<T>* curr=root;
            while(true){
                if(val<curr->val){
                    if(curr->left==nullptr){
                        curr->left=newNode;
                        return;
                    }
                    curr=curr->left;
                }
                else{
                    if(curr->right==nullptr){
                        curr->right=newNode;
                        return;
                    }
                    curr=curr->right;
                }
            }
        }
        void traverseInorder(){
           Inorder(root);
        }

};
int main(){
    BTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.traverseInorder();
    return 0;
}