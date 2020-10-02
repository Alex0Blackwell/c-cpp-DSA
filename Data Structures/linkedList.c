#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* link;
};
class ll
{
	node* f;
	public:
	ll()
	{
		f=NULL;
	}
	
	void crenode(int x)
	{
		node* nn=new node;
		nn->data=x;
		nn->link=NULL;
		if(f==NULL)
		{
			f=nn;
			return;
		}
		else
		{
			node* tmp=f;
			while(tmp->link!=NULL)
			{
				tmp=tmp->link;
			}
			tmp->link=nn;
			return;
		}
	}
	void delnode(int x)
	{
		node* tp=f;
		node* t1;
		if(f->data==x)
		{
			f=f->link;
			delete tp;
			return;
		}
		else
		{
		while( tp->data!=x && tp!=NULL)
		{
			t1=tp;
			tp=tp->link;
		}
		
		if(tp==NULL)
		{
			cout<<"not found";
			return;
		}
		else
		{
			t1->link=tp->link;
			cout<<"deleted";
			return;
		}
		}
		
	}
	void search()
	{
		int x;
		cin>>x;
		int c=0;
		node* t=f;
		while(t!=NULL&&t->data!=x)
		{
			c++;
			t=t->link;
		}
		if(t==NULL)
		{
			cout<<"not found";
			return;
		}
		cout<<"found at locn: "<<c;
	}
	void emp()
	{
		node* t=f;
		if(t==NULL)
		{
			cout<<"empty";
			return;
		}
		cout<<"not empty";	
	}
	void count()
	{
		int c=0;
		node* t=f;
		while(t!=NULL)
			c++;
		cout<<"no of elements: "<<c;
	}
	void dis()
	{
		node* t=f;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			t=t->link;
		}
	}
	void des()
	{
		f=NULL;
		cout<<"cleared";
	}
};
int main()
{
	ll l1;
	cout<<"1.crenode 2.delnode 3.search 4.empty 5.count 6.display 7. destroy";
	int c;
	cin>>c;
	while(c!=0)
	{

	switch(c)
	{
		case 1:
		int x;
		cin>>x;
		l1.crenode(x);
		break;
		case 2:
		int y;
		cin>>y;
		l1.delnode(y);
		break;
		case 3:
		l1.search();
		break;
		case 4:
		l1.emp();
		break;
		case 5:
		l1.count();
		break;
		case 6:
		l1.dis();
		break;
		case 7:
		l1.des();
		break;
	}
	cout<<"1.crenode 2.delnode 3.search 4.empty 5.count 6.display 7. destroy";
	
	cin>>c;
	}
	cout<<"loop ended";
}
