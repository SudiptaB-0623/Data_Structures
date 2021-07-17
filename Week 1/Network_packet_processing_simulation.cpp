#include<iostream>

using namespace std;

struct node
{
    int finish;
    node *next;
};

node *top=NULL,*rear=NULL,*ptrs=NULL;

struct nodes
{
    int arvl;
    int prcs;
    nodes *link;
};

nodes *first=NULL,*last=NULL,*ptr=NULL;

int main()
{
    int buffer,S;
    cin>>buffer>>S;


    for(int i=0;i<S;i++)
    {
        //cout<<"\n****"<<i<<"********\n";
        ptr=new nodes;
        cin>>ptr->arvl>>ptr->prcs;
        ptr->link=NULL;
        if(i==0)
        {
            first=ptr;
            last=ptr;
        }
        else
        {
            last->link=ptr;
            last=ptr;
        }
    }
    if(S!=0)
    {
        if(S==1)
        {
            cout<<first->arvl;
        }
        else
        {
            ptr=first;
            int x=0;
            for(int i=0;i<S;i++)
            {
                if(i==0)
                {
                    ptrs=new node;
                    ptrs->finish=ptr->prcs+ptr->arvl;
                    ptrs->next=NULL;
                    top=ptrs;
                    rear=ptrs;
                    cout<<"\n"<<ptr->arvl;
                    ptr=ptr->link;
                    x++;
                }
                else
                {
                    if(ptr->arvl<top->finish)
                    {
                        if(x<buffer)
                        {
                            ptrs=new node;
                            ptrs->finish=rear->finish+ptr->prcs;
                            ptrs->next=NULL;
                            cout<<"\n"<<rear->finish;
                            rear->next=ptrs;
                            rear=ptrs;
                            ptr=ptr->link;
                            x++;
                        }
                        else if(x>=buffer)
                        {
                            cout<<"\n"<<-1;
                            ptr=ptr->link;
                        }


                    }
                    else if(ptr->arvl>=top->finish)
                    {

                            if(ptr->arvl>rear->finish)
                            {
                                cout<<"\n"<<ptr->arvl;
                            }
                            else
                            {
                                cout<<"\n"<<rear->finish;
                            }
                            ptrs=new node;
                            ptrs->finish=rear->finish+ptr->prcs;
                            if(ptr->arvl>rear->finish)
                            {
                                ptrs->finish=(ptr->arvl-rear->finish)+ptrs->finish;
                            }
                            ptrs->next=NULL;
                            rear->next=ptrs;
                            rear=ptrs;
                            while(ptr->arvl>=top->finish)
                            {
                                node *temp=top;
                                top=top->next;
                                delete temp;
                                x=x-1;
                                if(top==NULL)
                                    break;
                            }
                            x++;
                            ptr=ptr->link;

                    }
                }
            }
        }
    }

}
