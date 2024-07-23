#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10

typedef struct node
{
    int coeff, exp;
    struct node *next;
}node;

node *makenode(int coeff, int exp)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

node *addterm(node *poly[], int id, int coeff, int exp)
{
    node *newnode = makenode(coeff,exp);
    if(poly[id] == NULL)
    {
        poly[id] = newnode;
        return poly[id];
    }

    if(exp >= poly[id]->exp)
    {
        if(poly[id]->exp == exp)
            poly[id]->coeff += coeff;
        else
        {
            newnode->next = poly[id];
            poly[id] = newnode;
        }
        return poly[id];
    }

    node *current = poly[id];
    while(current->next != NULL && current->next->exp >= exp)
        current = current->next;

    if(current->exp == exp)
        current->coeff += coeff;
    else
    {
        newnode->next = current->next;
        current->next = newnode;
    }

    return poly[id];
}

void print(node *poly[], int id)
{
    node *current = poly[id];
    while(current != NULL)
    {
        printf("%d %d ",current->coeff,current->exp);
        current = current->next;
    }
    printf("\n");
}

int EvaluatePoly(node *poly[], int id, int x)
{
    int value = 0;
    node *current = poly[id];
    while(current != NULL)
    {
        int a = pow(x,current->exp);
        value += (current->coeff)*a;
        current = current->next;
    }
    return value;
}

node *addpoly(node *poly[], int id1, int id2, int id3)
{
    node *current1 = poly[id1];
    node *current2 = poly[id2];
    while(current1 != NULL && current2 != NULL)
    {
        poly[id3] = addterm(poly,id3,current1->coeff,current1->exp);
        poly[id3] = addterm(poly,id3,current2->coeff,current2->exp);

        current1 = current1->next;
        current2 = current2->next;
    }
    return poly[id3];
}

void Destroy(node *poly[], int id)
{
    node *current = poly[id];
    while(current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    poly[id] = NULL;
}

void freePoly(node *poly[])
{
    for(int i=0; i<MAX; i++)
        Destroy(poly,i);
}

int main()
{
    node *poly[MAX] = {NULL};
    int id,coeff,exp,x;

    char cmd[10];
    while(1)
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"AddTerm")==0)
        {
            scanf("%d %d %d",&id,&coeff,&exp);
            poly[id] = addterm(poly,id,coeff,exp);
        }
        else if(strcmp(cmd,"PrintPoly")==0)
        {
            scanf("%d",&id);
            print(poly,id);
        }
        else if(strcmp(cmd,"EvaluatePoly")==0)
        {
            scanf("%d %d",&id,&x);
            printf("%d\n",EvaluatePoly(poly,id,x));
        }
        else if(strcmp(cmd,"AddPoly")==0)
        {
            int id1, id2, id3;
            scanf("%d %d %d",&id1,&id2,&id3);
            poly[id3] = addpoly(poly,id1,id2,id3);
        }
        else if(strcmp(cmd,"Destroy")==0)
        {
            scanf("%d",&id);
            Destroy(poly,id);
        }
        else if(strcmp(cmd,"*")==0)
            break;
    }
    freePoly(poly);

    return 0;
}
