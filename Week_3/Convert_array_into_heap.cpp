#include<iostream>

using namespace std;

int count=0;

class node
{
	public:
		int a,b;
		node* next;
};

node *front=NULL;
node *rear=NULL;

void pushback(int l,int r)
{
	node *temp=new node();
	temp->a=l;
	temp->b=r;
	temp->next=NULL;

	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
	}

}

void shiftdown(int array[],int par,int len)
{
		int left=(2*par)+1;
		int right=(2*par)+2;

		if( right < len)    		//if right child exists
		{
			if( (array[left]<array[right]) && (array[left]<array[par]) )
			{
				pushback(par,left);
				swap(array[par],array[left]);
				count++;

				if((left*2)+1<len)
					shiftdown(array,left,len);

			}
			else if( (array[right]<array[left]) && (array[right]<array[par]) )
			{
				pushback(par,right);
				swap(array[par],array[right]);
				count++;

				if((right*2)+1<len)
					shiftdown(array,right,len);

			}
		}
		else
		{
			if( array[left]<array[par] )
			{
				pushback(par,left);
				swap(array[par],array[left]);
				count++;

				if((left*2)+1<len)
					shiftdown(array,left,len);

			}
	
		}

}

int main()
{
	int size;
	cin>>size;
	
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];

	int last=(size-2)/2;			//last non leaf node

	for(int par_node=last;par_node>=0;par_node--)
	{
		if((par_node*2)+1<size)
			shiftdown(arr,par_node,size);
	}

	cout<<count<<"\n";
	node *flag=front;
	while(flag!=NULL)
	{
		cout<<flag->a<<" "<<flag->b<<"\n";
		flag=flag->next;
	}

	return 0;
}
