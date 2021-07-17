#include<iostream>
#include<string.h>

using namespace std;

struct node
{
    int index;
    char ch;
    node *next;
};

int main()
{
    string s;
    cin>>s;
    int i=0,flag=0;

    node *ptr=NULL,*top=NULL;


    for(;i<s.length();i++)
    {

        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
                ptr=new node;
                ptr->index=i+1;

                ptr->ch=s[i];
                ptr->next=top;
                top=ptr;
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(top==NULL)
            {
                cout<<i+1;
                flag++;
                break;
            }
            if((((s[i]==')')&&(top->ch=='('))||((s[i]==']')&&(top->ch=='['))||((s[i]=='}')&&(top->ch=='{')))&&(i!=0))
            {
                ptr=top;
                top=top->next;
                delete ptr;
            }
            else
            {
                cout<<i+1;
                flag++;
                break;
            }
        }
    }
    if(flag==0)
    {
        if(top==NULL)
        {
            cout<<"Success";
        }
        else
        {
            cout<<top->index;
        }
    }
}
