#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct node
{
    int x, y, step;
    struct node *next;
    struct node *prev;
}node;

node *makenode(int x, int y, int step)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->x = x;
    newnode->y = y;
    newnode->step = step;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

node *head = NULL;
node *tail = NULL;
int visited[MAX][MAX], a, b, c;

node *Dequeue()
{
    node *tmp = tail;
    node *prev = (tmp == NULL ? NULL : tmp->prev);

    if(tmp != NULL)
    {
        node *result = makenode(0, 0, 0);
        result->x = tmp->x;
        result->y = tmp->y;
        result->step = tmp->step;
        free(tmp);
        if(prev != NULL)
        {
            prev->next = NULL;
            tail = prev;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        return result;
    }
    else return NULL;
}

void Enqueue(int x, int y, int step)
{
    visited[x][y] = 1;
    node *newnode = makenode(x, y, step);

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

int target(int x, int y)
{
    return (x == c) || (y == c) || (x + y == c);
}

int newstate_of_x(int x, int y, int k)
{
    int x1;
    if(k == 0) x1 = a;
    else if(k == 1) x1 = x;
    else if(k == 2) x1 = 0;
    else if(k == 3) x1 = x;
    else if(k == 4) x1 = x + y - b;
    else if(k == 5) x1 = 0;
    else if(k == 6) x1 = a;
    else if(k == 7) x1 = x + y;
    return x1;
}

int newstate_of_y(int x, int y, int k)
{
    int y1;
    if(k == 0) y1 = y;
    else if(k == 1) y1 = b;
    else if(k == 2) y1 = y;
    else if(k == 3) y1 = 0;
    else if(k == 4) y1 = b;
    else if(k == 5) y1 = x + y;
    else if(k == 6) y1 = x + y - a;
    else if(k == 7) y1 = 0;
    return y1;
}

int findway()
{
    Enqueue(0, 0, 0);
    while(1)
    {
        node *tmp = Dequeue();
        if(tmp != NULL)
        {
            int x = tmp->x;
            int y = tmp->y;
            int step = tmp->step;
            free(tmp);

            if(target(x, y) == 1)
            {
                return step;
                break;
            }
            else
            {
                for(int k=0; k<=7; k++)
                {
                    int x1 = newstate_of_x(x, y, k);
                    int y1 = newstate_of_y(x, y, k);

                    if(x1 >= 0 && x1 <= a && y1 >= 0 && y1 <= b)
                    {
                        if(visited[x1][y1] == 0)
                            Enqueue(x1, y1, step+1);
                    }
                }
            }
        }
        else return -1;
    }
}

int main()
{
    scanf("%d %d %d",&a,&b,&c);

    for(int i=0; i<=a; i++)
        for(int j=0; j<=b; j++)
            visited[i][j] = 0;

    printf("%d\n",findway());

    return 0;
}
