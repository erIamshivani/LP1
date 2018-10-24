#include<iostream>
#include<queue>
using namespace std;

class node
{
	public: int data;
			node *left;
			node *right;
			
			node()
			{
				left=NULL;
				right=NULL;
				data=0;
			}
};

class Breadthfs
{
	public:
		node *root;
		node *head;
		
		Breadthfs()
		{
			root=NULL;
			head=NULL;
		}
		
		void insert(int data)
		{
			node *newnode = new node();
			newnode->data=data;
			if(root==NULL)
			{
				root=newnode;
				root->data=data;
				
			}
			else
			{
				node *curr=root;
				
				int flag=0;
				char dir;
				while(flag==0)
				{
					cout<<"\ncurrent node= "<<curr->data;
					cout<<"\nEnter Direction(l or r) : ";
					cin>>dir;
					if(dir=='l')
					{
						if(curr->left==NULL)
						{
							curr->left= newnode;
							flag=1;
							
						}
						else
						{
							curr=curr->left;
						}
					}
					else if(dir=='r')
					{
						if(curr->right==NULL)
						{
							curr->right= newnode;
							flag=1;
							
						}
						else
						{
							curr=curr->right;
						}
					}
				}
				
			}
		}
	
	
	void bfs()
{

		queue<node*> q;
		q.push(root);
		
		int qSize;
		
		while (!q.empty()) 
		{
			qSize = q.size();
			#pragma omp parallel for
			for (int i = 0; i < qSize; i++) 
			{
				node* currNode;
				#pragma omp critical
				{
				  currNode = q.front();
				  q.pop();
				  cout<<"\t"<<currNode->data;
				
				}
				#pragma omp critical
				{
				if(currNode->left)
					q.push(currNode->left);
				if(currNode->right)
					q.push(currNode->right);
				}		

			}
		}
	}
	
};

int main()
{
	int data=213;
	Breadthfs tree;
	do
	{
		cout<<"\nEnter element ";
		cin>>data;
		if(data==0)
		 break;
		tree.insert(data);
		
	}
	while(data!=0);
	
	tree.bfs();
	
	return 0;
}
