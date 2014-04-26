//Devang Bacharwar B12059
# include <iostream>
# include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;
 

class BST
{
    public:
        void search(int, node **, node **); 
        void searching(int, node *);   
        void insert(node *,node *);
        void del(int);
        void leaf_deletion(node *,node *);
        void onesidetree_deletion(node *,node *);
        void bothsidetree_deletion(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        BST()
        {
            root = NULL;
        }
};

//Devang Bacharwar B12059

void BST::searching(int item, node *tree)
{
    node *ptr;
    if (root == NULL)
    {
        return;
    }
    if (item == root->data)
    {
        cout<<"root : "<<root->data<<endl;
        return;
    }
    if (item < root->data){
        cout<<"root : "<<root->data;
        ptr = root->left;
        cout<<" -> left : ";
    }
    else{
        cout<<"root : "<<root->data;
        ptr = root->right;
        cout<<" -> right : ";
    }
    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            cout<<"\t"<< ptr->data;
            return;
        }
        if (item < ptr->data){
            cout<<ptr->data<<" -> left : ";
            ptr = ptr->left;
        }
        else{
            cout<<ptr->data<<" -> right : ";
            ptr = ptr->right;
        }
    }
}

void BST::search(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->data)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->data){
        ptr = root->left;
    }
    else{
        ptr = root->right;
    }
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            *loc = ptr;
            *par = ptrsave;
            cout<< ptr->data;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->data){
            ptr = ptr->left;
        }
    else{
        ptr = ptr->right;
    }
    }
    *loc = NULL;
    *par = ptrsave;
}
 

void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->data = newnode->data;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->data == newnode->data)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->data > newnode->data)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);    
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left of "<< tree->data <<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right of "<< tree->data <<endl;
            return;
        }   
    }
}
 

void BST::del(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    search(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        leaf_deletion(parent, location);
    if (location->left != NULL && location->right == NULL)
        onesidetree_deletion(parent, location);
    if (location->left == NULL && location->right != NULL)
        onesidetree_deletion(parent, location);
    if (location->left != NULL && location->right != NULL)
        bothsidetree_deletion(parent, location);
    free(location);
}
 

void BST::leaf_deletion(node *par, node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
 

void BST::onesidetree_deletion(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}
 

void BST::bothsidetree_deletion(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        leaf_deletion(parsuc, suc);
    else
        onesidetree_deletion(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
 

void BST::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->data<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}
 
void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<"  ";
    }
}
 

void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}

//Devang Bacharwar B12059
int main()
{
    int choice, num;
    BST binarysearchtree;
    node *temp;
    while (1)
    {
        cout<<"Enter your choice for binary search tree:"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Search"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
	        cin>>temp->data;
            binarysearchtree.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            binarysearchtree.del(num);
            break;
        case 3:
            cout<<"Inorder Traversal of binary search tree:"<<endl;
            binarysearchtree.inorder(root);
            cout<<endl;
            break;
	    case 4:
            cout<<"Preorder Traversal of binary search tree:"<<endl;
            binarysearchtree.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of binary search tree:"<<endl;
            binarysearchtree.postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display binary search tree:"<<endl;
            binarysearchtree.display(root,1);
            cout<<endl;
            break;
        case 8:
            exit(1);
        case 7:
            cout<<"Enter the element you want to search for:\n";
            cin>>num;
            binarysearchtree.searching(num,root);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 
