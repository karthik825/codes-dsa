#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list
{
    long long int data;
    struct list *next, *prev;
} * head, *end;

void create_list(int n)
{
    struct list *Node, *temp, *temp2;

    head = (struct list *)malloc(sizeof(struct list));

    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    end = head;

    temp = head;
    temp2 = head;
    for (int i = 2; i <= n; i++)
    {
        Node = (struct list *)malloc(sizeof(struct list));

        if (Node == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        if (i == 2)
        {
            Node->data = 1;
            Node->next = NULL;
            Node->prev = temp;
            end = Node;

            temp->next = Node;
            temp = temp->next;
        }
        else
        {
            
            Node->data = temp->data + temp2->data;
            Node->next = NULL;
            Node->prev = temp;
            end = Node;

            temp->next = Node;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

void delete (int r)
{
    struct list *save, *temp = head;
    int i = 1, j = 1, x = 1;
    while (temp != NULL)
    {
        if (i / x == 1)
        {
            if (i == 1 || i == 2)
            {
                head = head->next;
                head->prev = NULL;
                free(temp);
                temp = head;
            }
            else if (temp->next == NULL)
            {
                end = temp->prev;
                temp->prev->next = NULL;
                free(temp);
            }
            else
            {
                save = temp;
                temp = temp->next;
                save->prev->next = save->next;
                save->next->prev = save->prev;
                free(save);
            }
            x = pow(r, j);
            j++;
        }
        else
        {
            temp = temp->next;
        }
        i++;
    }
}

void printlist()
{
    struct list *temp = head;
    while (temp != NULL)
    {
        printf("%lld\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, r;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create_list(n);
    printf("Enter the factor of G.P.:-");
    scanf("%d", &r);
    printlist();
    printf("the required output is \n");
    delete (r);
    printlist();
    return 0;
}
