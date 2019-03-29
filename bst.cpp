#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insert(int value){
        insertHelper(root, value);
    }
    void insertHelper(Node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new Node(value);
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) {
                curr->left = new Node(value);
                curr->left->parent = curr;
            }
            // Move left and call insert there. 
            else insertHelper(curr->left, value);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) {
                curr->right = new Node(value);
                curr->right->parent = curr;
            }
            // Move right and call insert there. 
            else insertHelper(curr->right, value);
        }
    }
    void display(){
        displayHelper(root);
    }
    void displayHelper(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        displayHelper(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        displayHelper(curr->right);
    }
    Node * search(int value){
        return searchHelper(root, value);
    }
    Node * searchHelper(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return searchHelper(curr->left, value);
        // Right
        else  return searchHelper(curr->right, value);
    }
Node* find_min(Node* a)
{

	if(root==NULL)
	{	cout<<"There is no min node"<<endl;
		return NULL;
	}
	else if(a->left!=NULL)
		find_min(a->left);
	else 
		return a;
}
void replace_At_Parent(Node* a,Node* b)
{
	if(a->parent->data>a->data)
		a->parent->left=b;
	else
		a->parent->right=b;
	b->parent=a->parent;
	b->left=a->left;
	b->right=a->right;
	a->left->parent=b;
	a->right->parent=b;
	delete a;
}
void deleteNode(int val)
{
	Node* temp;
	temp=search(val);
	if(temp==NULL)
	{	cout<<"No such node exists"<<endl;
		return;

	}
	else
	{
		Node* temp1;
		temp1=find_min(temp->right);
		if(temp1==NULL)
		{
			temp->left->parent=temp->parent;
			if(temp->parent->data>temp->data)
				temp->parent->left=temp->left;
			else
				temp->parent->right=temp->left;
			delete temp;
		}
		else
		{
			temp1->parent->left=NULL;
			replace_At_Parent(temp,temp1);
	}	}
}
};

int main(){
    
	BST obj;
for(int i=1;i<=16;i++)
{
obj.insert(3*i%17);
}
 obj.display();
obj.deleteNode(5);
obj.display();
/* bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
    bst1.insertHelper(8);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
    bst1.print2D();
    bst1.binary_delete(bst1.root,5);
    bst1.print2D();
    bst1.binary_delete(bst1.root,6);
    bst1.print2D();
    cout << "Deleting 2" << endl;
    bst1.binary_delete(bst1.root,2);
    bst1.print2D();
    bst1.binary_delete(bst1.root,4);
    bst1.print2D();
    bst1.binary_delete(bst1.root,7);
    bst1.print2D();
    bst1.binary_delete(bst1.root,8);
    bst1.print2D();
    bst1.binary_delete(bst1.root,3);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();
*/
}
