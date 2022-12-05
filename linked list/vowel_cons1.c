#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//#include"myLL.h"

struct node
{
    int info;
    struct node *next;
};

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void traverse(struct node *start)
{
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf("%c ", p->info);
        p = p->next;
    }
}

void insbeg(struct node **start, char x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = *start;
    *start = p;
}
void insaft(struct node **q, char x)
{
    struct node *p, *r;
    p = getnode();
    p->info = x;
    r = (*q)->next; // p->next=q->next;
    p->next = r;    // q->next=p;
    (*q)->next = p;
}
void insend(struct node **start, char x)
{
    struct node *p, *q;
    q = *start;
    if (q == NULL)
    {
        insbeg(start, x);
    }

    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        p = getnode();
        p->info = x;
        p->next = NULL;
        q->next = p;
    }
}

int delbeg(struct node **start)
{
    if (*start == NULL)
    {
        printf("void deletion");
        exit(1);
    }

    int x;
    struct node *p;
    p = *start;
    x = p->info;
    *start = (*start)->next;
    free(p);
    return x;
}
int delafter(struct node **p)
{
    if (*p == NULL || (*p)->next == NULL)
    {
        printf("void deleteion");
        exit(1);
    }

    char x;
    struct node *q, *r;
    q = (*p)->next;
    r = q->next;
    (*p)->next = r;

    x = q->info;

    free(q);
    return x;
}

void vowel_cons(struct node **start)
{
    struct node *p, *r, *n;
    char x;
    if ((*start) != NULL)
    {
    if ((*start)->info == 'a' || (*start)->info == 'e' || (*start)->info == 'i' || (*start)->info == 'o' || (*start)->info == 'u')
    {
        p = (*start);
        r = (*start)->next;
        n = (*start)->next;
    }
    else
    {
        p = NULL;
        r = NULL;
        n = (*start);
    }
    
        while (n != NULL)
        {
            if (n->info == 'a' || n->info == 'e' || n->info == 'i' || n->info == 'o' || n->info == 'u')
            {
                n = n->next;
                if (p == NULL)
                {

                    {
                        x = delafter(&(r));
                    }
                    insbeg(&(*start), x);
                    p = *start;
                    // r = p;
                }
                else
                {
                    x = delafter(&r);
                    insaft(&p, x);
                    p = p->next;
                }
            }
            else
            {
                r = n;
                n = n->next;
            }
        }
    }
    else
    {
        printf("node doesnot exist");
    }
}

int main()
{
    struct node *start;
    start = NULL;

    // insbeg(&start,'y');
    // insbeg(&start,'e');
    // insbeg(&start,'n');
    // insbeg(&start,'o');
    // insbeg(&start,'m');
    // insbeg(&start,'e');
    // insbeg(&start,'a');
    // insbeg(&start,'i');
    // insbeg(&start,'u');
    // insend(&start, 'a');
    // insend(&start, 'x');
    insend(&start, 'k');
    insend(&start, 'i');
    traverse(start);
    printf("\n");
    vowel_cons(&start);
    traverse(start);
}