 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list
{
    float data;
    struct list *next;
} * head;

void create_list(int n)
{
    struct list *node, *temp;

    head = (struct list *)malloc(sizeof(struct list));

    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head->data = ((float)rand() / RAND_MAX);
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= n; i++)
    {
        node = (struct list *)malloc(sizeof(struct list));

        if (node == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        node->data = ((float)rand() / RAND_MAX);
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
}
void reverse(int r)
{
    struct list *temp = head, *temp1, *prev, *next, *current;
    int i = 1, k;
    while (temp->next != NULL)
    {
        k = pow(r, i);
        temp1 = temp->next;
        prev = temp1;
        if(prev->next==NULL)
        {
        	break;
        }	
        current = prev->next;
        next = current->next;
        for (int j = 1; j < k; j++)
        {
            current->next = prev;
            prev = current;
            current = next;
            if (current == NULL)
            {
                break;
            }
            if (next != NULL)
            {
                next = next->next;
            }
        }
        temp1->next = current;
        temp->next = prev;
        temp = temp1;
        i++;
    }
}
void print()
{
    struct list *temp = head;
    while (temp != NULL)
    {
        printf("%f\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, r;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    printf("Enter the factor of G.P.:-");
    scanf("%d", &r);
    create_list(n);
    print();
    printf("after reversing in pattern is\n");
    reverse(r);
    print();
    return 0;
}
