#include<stdio.h>
#include<stdlib.h>

struct broken
{
    char ch;
    struct broken *next;
};

typedef struct broken broken;
broken *start, *end, *temp, *use;

int main()
{
    char ch;
    int flag, f;
    while((ch=getchar())!=EOF)
    {
        flag=1;
        start =(broken*)malloc(sizeof(broken));
        end=start;
        while(ch!='\n')
        {
            if(ch=='[')
            {
                f=1;
                flag=0;
            }
            else if(ch==']')
            {
                flag=1;
            }
            else
            {
                if(flag)
                {
                    end->ch=ch;
                    end->next=(broken*)malloc(sizeof(broken));
                    end=end->next;
                }
                else
                {
                    if(f)
                    {
                        f=0;
                        temp=(broken*)malloc(sizeof(broken));
                        temp->ch=ch;
                        temp->next=start;
                        start=temp;
                    }
                    else
                    {
                        use=(broken*)malloc(sizeof(broken));
                        use->ch=ch;
                        use->next=temp->next;
                        temp->next=use;
                        temp=use;
                    }
                }
            }
            ch=getchar();
        }
        temp=start;
        while(temp!=end)
        {
            printf("%c", temp->ch);
            temp=temp->next;
        }
        printf("\n");
        free(start);
    }

    return 0;
}
