#include "avl.hh"

using std::cout;

template <typename type_t>
void avl<type_t>::add(type_t arg, node *&nptr)
{
     if(!nptr)
        nptr = new node(arg);

    //recursively finding the place for new node
    else if(arg < nptr->value)
    {
        add(arg, nptr->left_ptr);
        
        //two children case
        if(nptr->left_ptr && nptr->right_ptr)
        {
            //subtree height difference greater than 1 
            if(getBalance(nptr) > 1)
            {
                if(arg < nptr->left_ptr->value)
                    nptr = rightRightRotate(nptr);
                else
                    nptr = rightLeftRotate(nptr);
            }
        }
        //one child case
        else if(nptr->left_ptr->height == 1 && !nptr->right_ptr)
        {
            if(arg < nptr->left_ptr->value)
                nptr = rightRightRotate(nptr);
            else
                nptr = rightLeftRotate(nptr);
        }
        //not checking left child becasue argument
        //is less than node's value
    }

    else if(arg > nptr->value)
    {
        add(arg, nptr->right_ptr);

        //two children case
        if(nptr->right_ptr && nptr->left_ptr)
        {
            //height differenced less than -1
            //subtree unbalanced on the right side
            if(getBalance(nptr) < -1)
            {
                if(arg > nptr->right_ptr->value)
                    nptr = leftLeftRotate(nptr);
                else
                    nptr = leftRightRotate(nptr);
            }
        }
        //one child case
        else if(nptr->right_ptr->height == 1 && !nptr->left_ptr)
        {
            if(arg > nptr->right_ptr->value)
                nptr = leftLeftRotate(nptr);
            else
                nptr = leftRightRotate(nptr);
        }
        //not checking right child becasue argument
        //is less than node's value
    }

    //argument equal to node's value
    //it's already on the tree
    else
       return;

    nptr->height = updateHeight(nptr->left_ptr, nptr->right_ptr);
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::destroy(type_t arg, node *nptr)
{
    node *tmp_ptr;

    if(!nptr)
        return nullptr;

    //recursively searching for node
    else if(arg < nptr->value)
        nptr->left_ptr = destroy(arg, nptr->left_ptr);
    else if(arg > nptr->value)
        nptr->right_ptr = destroy(arg, nptr->right_ptr);

    //finding minimal value in a subtree and switching
    else if(nptr->left_ptr && nptr->right_ptr)
    {
        tmp_ptr = min(nptr->right_ptr);
        nptr->value = tmp_ptr->value;
        nptr->right_ptr = destroy(nptr->value, nptr->right_ptr);
    }

    //one child
    else if(!nptr->right_ptr || !nptr->left_ptr)
    {
        tmp_ptr = nptr;
        if(!nptr->left_ptr)
            nptr = nptr->right_ptr;
        else if(!nptr->right_ptr)
            nptr = nptr->left_ptr;
    }
    
    //deleting the node
    else 
    {
        tmp_ptr = nptr;
        delete tmp_ptr;
    }    

    if(!nptr)
        return nptr;
   
    nptr->height = updateHeight(nptr->left_ptr, nptr->right_ptr);
 
    if(getBalance(nptr) > 1 && getBalance(nptr->left_ptr) < 0)
        return leftRightRotate(nptr);

    if(getBalance(nptr) > 1){
        return rightRightRotate(nptr); cout << "rr\n"; }

    if(getBalance(nptr) < -1 && getBalance(nptr->right_ptr) > 0)
        return rightLeftRotate(nptr);
    
    if(getBalance(nptr) < -1)
        return leftLeftRotate(nptr);
 
    //returns pointer to deleted node in order to allow recursion
    return nptr;
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::rightRightRotate(node *&nptr)
{
    node *tmp_ptr = nptr->left_ptr;
    nptr->left_ptr = tmp_ptr->right_ptr;
    tmp_ptr->right_ptr = nptr;

    nptr->height = updateHeight(nptr->left_ptr, nptr->right_ptr);
    tmp_ptr->height = updateHeight(nptr->right_ptr, nptr);

    return tmp_ptr;
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::leftLeftRotate(node *&nptr)
{
    node *tmp_ptr = nptr->right_ptr;
    nptr->right_ptr = tmp_ptr->left_ptr;
    tmp_ptr->left_ptr = nptr;
    
    nptr->height = updateHeight(nptr->left_ptr, nptr->right_ptr);
    tmp_ptr->height = updateHeight(nptr->right_ptr, nptr);

    return tmp_ptr;
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::leftRightRotate(node *&nptr)
{
    nptr->right_ptr = rightRightRotate(nptr->right_ptr);
    return leftLeftRotate(nptr);
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::rightLeftRotate(node *&nptr)
{
    nptr->left_ptr = leftLeftRotate(nptr->left_ptr);
    return rightRightRotate(nptr);
}

template <typename type_t>
void avl<type_t>::preorder(node *nptr)
{
    if(nptr)
    { 
        cout << nptr->value << "\n";
        preorder(nptr->left_ptr);
        preorder(nptr->right_ptr); 
    }
}

template <typename type_t>
void avl<type_t>::inorder(node *nptr)
{
    if(nptr)
    {
        inorder(nptr->left_ptr);
        cout << nptr->value << "\n";
        inorder(nptr->right_ptr);
    }
}

template <typename type_t>
void avl<type_t>::inorderHeight(node *nptr)
{
    if(nptr)
    {
        inorderHeight(nptr->left_ptr);
        cout << nptr->value << "\t";
        cout << nptr->height << "\n";
        inorderHeight(nptr->right_ptr);
    }
}

template <typename type_t>
void avl<type_t>::postorder(node *nptr)
{
    if(nptr)
    {
        postorder(nptr->left_ptr);
        postorder(nptr->right_ptr);
        cout << nptr->value << "\n";
    }
}

template <typename type_t>
typename avl<type_t>::node *avl<type_t>::min(node *nptr)
{
    if(!nptr)
        return nullptr;
    else if(!nptr->left_ptr)
        return nptr;
    else
        return min(nptr->left_ptr);
}

template <typename type_t>
void avl<type_t>::destroyTree(node *&nptr)
{
    if(nptr)
    {
        destroyTree(nptr->left_ptr);
        destroyTree(nptr->right_ptr);
        delete nptr;
    }
    nptr = nullptr;
}
