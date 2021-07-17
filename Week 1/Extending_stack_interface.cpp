#include<iostream>
#include<string.h>


using namespace std;

struct node
{
    int val;
    int maxval;
    int premax;
    node *next;
};

struct nodes
{
    int value;
    nodes *link;
};

node *ptr=NULL,*top=NULL;
nodes *result=NULL,*p=NULL,*rear;

int spush(int n)
{

    ptr=new node;
    ptr->val=n;
    if(n>=top->maxval)
    {
        ptr->maxval=n;
        ptr->premax=top->maxval;
    }
    else
    {
        ptr->maxval=top->maxval;
        if(n>=top->premax)
        {
            ptr->premax=n;
        }
        else
        {
            ptr->premax=top->premax;
        }
    }
    ptr->next=top;
    top=ptr;

}

int main()
{
    int tc;
    cin>>tc;
    cin.ignore();

    for(int i=0;i<tc;i++)
    {

        char str[15];
        cin.getline(str,15);


        if(str[2]=='s')
        {
            int x=strlen(str);
            int num=0,i=1;

            x=x-1;
            while(str[x]!=' ')
            {
                int z=str[x]-48;

                num=num+(i*z);
                i=i*10;
                x=x-1;

            }
            ptr=new node;
            if(top==NULL)
            {
                ptr->val=num;
                ptr->maxval=num;
                ptr->premax=0;
                ptr->next=top;
                top=ptr;
            }
            else
            {
                spush(num);
            }

        }

        if(str[2]=='p')
        {
            ptr=top;
            top=top->next;
            delete ptr;
        }

        if(str[2]=='x')
        {
            p=new nodes;
            p->value=top->maxval;
            p->link=NULL;
            if(result==NULL)
            {
                result=p;
                rear=p;
            }
            else
            {
                rear->link=p;
                rear=p;
            }
        }
    }
    nodes *temp=result;
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->value;
        temp=temp->link;
    }
}
