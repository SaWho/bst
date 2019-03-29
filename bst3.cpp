#include <iostream>
using namespace std;

class node
{
	public:    
    int data;
    // Children
    node * left;
    node * right;
    node * parent;

    node(int val)				
	{
       	data = val;
       	left = NULL;
       	right = NULL;
       	parent = NULL;
    }
};

class BiST
{
    public:
    node *root;
    
    BiST()
    {
        root=NULL;
    }
    
    void insert(int value)								
    {
        insert2(root,value);
    }
    void insert2(node *curr, int value)
    {
    	
        if(curr==NULL)
        {
            curr= new node(value);
            if(root==NULL)
            	root=curr;
            return;
        }
        
        else if(curr->data > value)						
        {
            if(curr->left==NULL)
            {
               curr->left=new node(value);
               curr->left->parent= curr;
            }
            else
               insert2(curr->left,value);
        }
        
        else											
        {
            if(curr->right==NULL)
            {
                curr->right=new node(value);
                curr->right->parent= curr;
            }
            else
               insert2(curr->right,value);
        }
    }
    
    void display()										
    {
        display2(root);
    }
    void display2(node * curr)
    {
        if(curr==NULL)
        	return;
        display2(curr->left);
        cout<<curr->data<<" ; ";
        display2(curr->right);
    }
    
   Node *search(int value)									
    {
        return search2(root,value);
    }
    Node *search2(Node * curr,int value)
    {
        if(curr==NULL || value==curr->data)
            return curr;
        else if(value > curr->data)
            search2(curr->right,value);
        else
            search2(curr->left,value);
    }
    
	node *find_min(node *curr)							
    {
        if(curr!=NULL)
        {
            while(curr->left!=NULL)
            {
                curr=curr->left;
            }
        }
        return curr;
    }
    
    void replace_At_Parent(node *A,node *B)				
    {
        
        B->parent=A->parent;
        if(A->parent->data > A->data)
        {
            A->parent->left=B;
        }
        else
        {
            A->parent->right=B;
        }
        B=A;
        A->parent=NULL;
        A->left=NULL;
        A->right=NULL;
    }
  
    void swap(Node * A,Node * B)
    {
        int temp=A->data;
        A->data=B->data;
        B->data=temp;
    }
    
    void deleteNode(int value)
    {
        if(search(value)!=NULL)
        {
            if(root->data!=value)
            {
                Node *curr=search(value);
                if(curr->left==NULL && curr->right==NULL)
                {
                    if(curr->parent->data < curr->data)
                    {
                        curr->parent->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    replace_At_Parent(curr,curr->left);
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    replace_At_Parent(curr,curr->right);
                    delete curr;
                }
                else 
                {
                	
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        
                        if(curr->parent->right->data==curr->data)
                        {
                            curr->parent->right=NULL;
                        }
                        else
                        {
                            curr->parent->left=NULL;
                        }
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                    
            }
            else 
            {
                node * curr=root;
                
                if(curr->left==NULL && curr->right==NULL)
                {
                    root=NULL;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    root=curr->left;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    root=curr->right;
                    delete curr;
                }
                else
                {
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
            }
        }
        else
        {
            cout<<"The suggested value doesnot exist in tree."<<endl;
        }
    }
    
    int rangeSearch(int k1, int k2)								
    {
    	return rangeSearch2(root, k1, k2);
	}
	int rangeSearch2(node *curr,int k1,int k2)
	{
	    if(curr!=NULL)
	    {
	        if(curr->data > k1 && curr->data < k2)
		    {
	           	cout<<curr->data<<" ;";
	            return (1 + rangeSearch2(curr->left,k1,k2) + rangeSearch2(curr->right,k1,k2));
		    }
		    else
		    	return rangeSearch2(curr->left,k1,k2)+rangeSearch2(curr->right,k1,k2);
		}
	    else
	        return 0;
	}
	
	int height(node *curr)										
	{
	    if(curr==NULL)
	        return 0;
	    else 
	    {
	        int right=height(curr->right);
			int left=height(curr->left);

	        if(left < right)
	          	return (1+right);
	        else
	            return (1+left);
	    }
	}
	
	int count(node* curr)										
	{
	    if(curr!=NULL)
	        return (1+count(curr->left)+count(curr->right));
	    else
	        return 0;
	}
};


int main()
{
	BiST B1;
	
	for(int i=1; i<11; i++)
	{
		B1.insert(i);
	}
	
	B1.display();
	cout<<endl;
	cout<<"Inserting a few more random elements..."<<endl;
	B1.insert(15);
	B1.insert(18);
	B1.insert(12);
	B1.insert(22);
	B1.insert(19);
	
	B1.display();
	cout<<endl;
	
    cout<<"The height of the given Binary Search Tree is - "<<B1.height(B1.root)<<endl;
    
    
    cout<<"The number of nodes in the Binary Search Tree are - "<<B1.count(B1.root)<<endl;
	
	int val;
	cout<<"Please enter a number to be searched in the list"<<endl;
	cin>>val;
	
	
    if(B1.search(val)==NULL)
    {
        cout<<"The asked value "<<val<<" does not exist in the tree."<<endl;
    }
    else
    {
 		cout<<"The asked value "<<val<<" exists in the tree."<<endl;
    }
    
   
    if(B1.find_min(B1.root)!=NULL)
    {
        cout<<"Minimum value of the tree: "<<B1.find_min(B1.root)->data<<endl;
    }
    else
    {
        cout<<"Case invalid."<<endl;
    }
    
    int del;
    cout<<"Please enter the node you want to delete"<<endl;
    cin>>del;
    B1.deleteNode(del);
    if(B1.root!=NULL)
    {
        B1.display();
        cout<<endl;
    }
    else
    {
        cout<<"No element in the tree after deletion."<<endl;// the BST had just one element
    }
    
    
    cout<<"The height of the given Binary Search Tree is - "<<B1.height(B1.root)<<endl;
    
    
    cout<<"The number of nodes in the Binary Search Tree are - "<<B1.count(B1.root)<<endl;
    
    int n1,n2;
    cout<<"Please enter the range where you want to search values in the tree..."<<endl;
    cin>>n1;
    cin>>n2;
    cout<<"The values in the given range are:-"<<endl;
    int num= B1.rangeSearch(n1,n2);
    cout<<endl;
    cout<<"The number of values in the range are "<<num;
    
    return 0;
}
