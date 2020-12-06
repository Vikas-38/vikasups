#include <bits/stdc++.h>
using namespace std;
struct node
{	int data;
	struct node *left,*right;
	
};
node *newnode(int a)
{	node *t=new node;
	t->data=a;
	t->left=NULL;
	t->right=NULL;
	return t;
}
int printnode(node*,int,int);
void printn(node*,int);
int main()
{	
	node *root=newnode(20);
	root->left=newnode(8);
	root->right=newnode(22);
	root->left->left=newnode(4);
	root->left->right=newnode(12);
	root->left->right->left=newnode(10);
	root->left->right->right=newnode(14);
	cout<<"tree already constructed"<<endl;
	int target;
	cout<<"target value="<<endl;
	cin>>target;
	int k;
	cout<<"k distance="<<endl;
	cin>>k;
	printnode(root,target,k);
	return 0;
}
int printnode(node *root,int target,int k)
{	if(root==NULL)
		return -1;
	if(root->data==target)
	{	printn(root,k);
		return 0;
	}
	int lnode=printnode(root->left,target,k);
	if(lnode!=-1)
	{		if(lnode+1==k)
				cout<<root->data<<endl;
			else
				printn(root->right,k-lnode-2);
			return 1+lnode;
	}
	int rnode=printnode(root->right,target,k);
	if(rnode!=-1)
	{		if(rnode+1==k)
				cout<<root->data<<endl;
			else
				printn(root->left,k-rnode-2);
			return 1+rnode;
			
	}
	return -1;
}
void printn(node *root,int k)
{		if(root==NULL||k<0)
				return;
		if(k==0)
		{	cout<<root->data<<endl;
				return;
				
		}
		printn(root->left,k-1);
		printn(root->right,k-1);
}
