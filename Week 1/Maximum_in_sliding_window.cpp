#include<iostream>

using namespace std;

struct node
{
    int val;
    node *pre;
    node *next;
};

node *top=NULL,*rear=NULL,*ptr=NULL,*del=NULL;

int addnode(int num)
{
    if(num>rear->val)
    {
        int flag=0;
        while(num>rear->val)
        {

            del=rear;

            if(top==rear)
            {
                ptr=new node;
                ptr->val=num;
                ptr->pre=NULL;
                ptr->next=NULL;
                top=ptr;
                rear=ptr;
                delete del;
                flag++;
                break;
            }
            else if(top!=rear)
            {
                rear=rear->pre;
                rear->next=NULL;
                delete del;
            }
        }
        if(flag==0)
        {

                ptr=new node;
                ptr->val=num;
                ptr->pre=rear;
                ptr->next=NULL;
                rear->next=ptr;
                rear=ptr;

        }
    }
    else
    {
        ptr=new node;
        ptr->val=num;
        ptr->pre=rear;
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
    }
}

int main()
{
    int n,m;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;

    ptr=new node;
    ptr->val=arr[0];
    ptr->pre=NULL;
    ptr->next=NULL;
    top=ptr;
    rear=ptr;

    for(int i=1;i<m;i++)
    {
        addnode(arr[i]);
    }

    cout<<"\n"<<top->val<<" ";

    for(int i=0,j=m-1;j<n;i++,j++)
    {
        if(i>=1)
        {
            addnode(arr[j]);
            if(top->val==arr[i-1])
            {
                del=top;
                top=top->next;
                top->pre=NULL;
                delete del;
            }
            cout<<top->val<<" ";
        }
    }

}
