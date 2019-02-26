#pragma once

#include <iostream>
#include <memory>

template <typename type_t>
class avl
{
    /*
    structure holding avl tree's node it contains value 
    node's height and pointers to left and right children
    height is 0 when node has no children
    */
    struct node
    {
        type_t value;
        int height;
        node *left_ptr;
        node *right_ptr;
        //paramatric constructor initlializing node with given value
        node(type_t inintValue):value(inintValue), height(0), left_ptr(nullptr), right_ptr(nullptr) {};
    };
    
    node *root;
    
    public:

    //class constructor initliazing root with pointer to null 
    avl(void):root(nullptr) {};
    ~avl(void) {};
    
    //public methods 
    void insert(type_t arg) { add(arg,root); }
    void remove(type_t arg) { root = destroy(arg,root); } 
    void displayPreorder(void) { preorder(root); }
    void displayInorder(void) { inorder(root); }
    void displayHeight(void) { inorderHeight(root); }
    void displayPostorder(void) { postorder(root); }
    void displayTreeHeight(void) { std::cout << "\n" << checkHeight(root); }
    void displayRootValue(void) { std::cout << "\n" << checkValue(root); }
    void clearTree(void) { destroyTree(root); }

    private:

    /*
    method adds passed value to given
    node pointer passed by reference

    method recursively finds the right place 
    for new node, dynamicaly allocates new node 
    then checks if tree is balanced
    (no two subtree have height difference greater than 1)
    and balances the tree using single or double rotation methods  
    
    if passed argument is already on the tree 
    method doesn't add it and doesn't return anything
    */
    void add(type_t arg, node *&nptr);

    /*
    method deletes node from a tree and rebalances it 
    it returns pointer to the deleted node

    method recursively finds the node to be deleted
    and then checks how many children does it have

    case with two children
    method calls method finding the minimal 
    value in a subtree and passes the right child 
    of deleted node as an argument
    then it switches values of nodes
    the deleted node now has the minimal 
    value in it's right subtree
    then the method recursively deletes the minmal node
    because tree can't have two equal valued nodes

    case with one child
    method checks which child is not null
    if left is null then it assigns 
    right child's value to the deleted node
    if right is null then it assigns 
    left child's value to the deleted node

    case with no children
    if node has no children the method delets the node
    */
    node *destroy(type_t arg, node *nptr);

    /*
    method recursively goes through the root
    and then through left and right subtree
    printing node's values
    */
    void preorder(node *nptr);

    /*
    method recursively goes through left subtree 
    then through the root and then 
    through the right subtree printing node's values
    */
    void inorder(node *nptr);

    /*
    method displays tree inorder printing 
    node's values and height of every node
    */
    void inorderHeight(node *nptr);

    /*
    method recursively goes through the right subtree
    then throught the root and then
    throught the left subtree printing node's values
    */   
    void postorder(node *nptr);

    /*
    nodes connected by right pointers

    node 1 becomes left child of node 2
    left child of node 2 becomes right child of node 1
    */
    node *rightRightRotate(node *&nptr);
    
    /*
    nodes connected by left pointers
    mirror reflection of right-right rotation
    */
    node *leftLeftRotate(node *&nptr);

    /*
    double rotation 

    it consists of two rotation 
    left-left and right-right
    */
    node *leftRightRotate(node *&nptr);
    
    /*
    double rotation
    mirror reflection of left-right rotation
    */
    node *rightLeftRotate(node *&nptr);
    
    //returns the formula for height update after balancing the tree if pointers are not null
    int updateHeight(node *nptr, node *tmp_ptr) { return (!nptr && !tmp_ptr) ? 0 : 1 + max(getHeight(nptr), getHeight(tmp_ptr)); }
    //method returns greater of two passed intigers
    int max(int arg1,int arg2) { return (arg1 >= arg2) ? arg1 : arg2; }
    //recursively finds minimal value in given pointer subtree
    node *min(node *nptr);
    //returns node's height if it's not pointing to null
    int checkHeight(node *nptr) { return (!isEmpty()) ? (nptr->height + 1) : 0; }
    //returns node's value if it's not poiting to null
    type_t checkValue(node *nptr) { return (!isEmpty()) ? nptr->value : 0; }
    bool isEmpty() {return (!root) ? true : false; }
    //returnes node's height if it's not pointing to null
    int getHeight(node *nptr) { return (!nptr) ? 0 : nptr->height; }
    //returns the height difference if pointers are not null
    int getBalance(node *nptr) { return (!nptr) ? 0 : (getHeight(nptr->left_ptr) - getHeight(nptr->right_ptr)); }

    /*
    method recursively deletes entire subtree by deleting 
    node pointers sand assinging them to null 
    it traverses the tree in postorder
    */
    void destroyTree(node *&nptr);
};