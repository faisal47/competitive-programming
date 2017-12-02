#include <stdio.h>
#include <string.h>
typedef struct
{
    char player_name[22];
    int attacking_power,defence_power;
} argentina;
int main ()
{
    argentina array[11];
    char temp[22];
    int t,i,j,k,len1,len2,l,flag,temp1,temp2;
    scanf("%d\n",&t);
    for(i=1; i<=t; i++)
    {
        for(j=0; j<10; j++)
            scanf("%s %d %d",array[j].player_name,&array[j].attacking_power,&array[j].defence_power);
        for(j=0; j<9; j++)
            for(k=j+1; k<10; k++)
            {
                if(array[j].attacking_power<array[k].attacking_power)
                {
                    temp1=array[j].attacking_power;
                    array[j].attacking_power=array[k].attacking_power;
                    array[k].attacking_power=temp1;
                    temp2=array[j].defence_power;
                    array[j].defence_power=array[k].defence_power;
                    array[k].defence_power=temp2;
                    strcpy(temp,array[j].player_name);
                    strcpy(array[j].player_name,array[k].player_name);
                    strcpy(array[k].player_name,temp);
                }
                else if(array[j].attacking_power==array[k].attacking_power&&array[j].defence_power>array[k].defence_power)
                {
                    temp2=array[j].defence_power;
                    array[j].defence_power=array[k].defence_power;
                    array[k].defence_power=temp2;
                    strcpy(temp,array[j].player_name);
                    strcpy(array[j].player_name,array[k].player_name);
                    strcpy(array[k].player_name,temp);
                }
                else if(array[j].attacking_power==array[k].attacking_power&&array[j].defence_power==array[k].defence_power)
                {
                    len1=strlen(array[j].player_name);
                    len2=strlen(array[k].player_name);
                    if(len1<=len2)
                    {
                        for(l=0; l<len1; l++)
                        {
                            if(array[j].player_name[l]<array[k].player_name[l])
                                break;
                            else if(array[j].player_name[l]>array[k].player_name[l])
                            {
                                strcpy(temp,array[j].player_name);
                                strcpy(array[j].player_name,array[k].player_name);
                                strcpy(array[k].player_name,temp);
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(l=0; l<len2; l++)
                        {
                            if(array[j].player_name[l]<array[k].player_name[l])
                                break;
                            else if(array[j].player_name[l]>array[k].player_name[l])
                            {
                                strcpy(temp,array[j].player_name);
                                strcpy(array[j].player_name,array[k].player_name);
                                strcpy(array[k].player_name,temp);
                                break;
                            }
                        }
                    }
                }
            }
        printf("Case %d:\n%c",i,40);
        for(j=0; j<4; j++)
            for(k=j+1; k<5; k++)
            {
                len1=strlen(array[j].player_name);
                len2=strlen(array[k].player_name);
                if(len1<=len2)
                {
                    for(l=0; l<len1; l++)
                    {
                        if(array[j].player_name[l]<array[k].player_name[l])
                            break;
                        else if(array[j].player_name[l]>array[k].player_name[l])
                        {
                            strcpy(temp,array[j].player_name);
                            strcpy(array[j].player_name,array[k].player_name);
                            strcpy(array[k].player_name,temp);
                            break;
                        }
                    }
                }
                else
                {
                    for(l=0; l<len2; l++)
                    {
                        if(array[j].player_name[l]<array[k].player_name[l])
                            break;
                        else if(array[j].player_name[l]>array[k].player_name[l])
                        {
                            strcpy(temp,array[j].player_name);
                            strcpy(array[j].player_name,array[k].player_name);
                            strcpy(array[k].player_name,temp);
                            break;
                        }
                    }
                }
            }
        flag=0;
        for(j=0; j<5; j++)
        {
            if(flag==1)
                printf(", %s",array[j].player_name);
            else
            {
                flag=1;
                printf("%s",array[j].player_name);
            }
        }
        printf("%c\n%c",41,40);
        for(j=5; j<9; j++)
            for(k=j+1; k<10; k++)
            {
                len1=strlen(array[j].player_name);
                len2=strlen(array[k].player_name);
                if(len1<=len2)
                {
                    for(l=0; l<len1; l++)
                    {
                        if(array[j].player_name[l]<array[k].player_name[l])
                            break;
                        else if(array[j].player_name[l]>array[k].player_name[l])
                        {
                            strcpy(temp,array[j].player_name);
                            strcpy(array[j].player_name,array[k].player_name);
                            strcpy(array[k].player_name,temp);
                            break;
                        }
                    }
                }
                else
                {
                    for(l=0; l<len2; l++)
                    {
                        if(array[j].player_name[l]<array[k].player_name[l])
                            break;
                        else if(array[j].player_name[l]>array[k].player_name[l])
                        {
                            strcpy(temp,array[j].player_name);
                            strcpy(array[j].player_name,array[k].player_name);
                            strcpy(array[k].player_name,temp);
                            break;
                        }
                    }
                }
            }
        flag=0;
        for(j=5; j<10; j++)
        {
            if(flag==1)
                printf(", %s",array[j].player_name);
            else
            {
                flag=1;
                printf("%s",array[j].player_name);
            }
        }
        printf("%c\n",41);
    }
    return 0;
}
