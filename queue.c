
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue
{
    int r, f, data[SIZE];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q, int item)
{
    if (q->r == SIZE - 1)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        q->r = q->r + 1;
        q->data[q->r] = item;
        if (q->f == -1)
        {
            q->f = 0;
        }
    }
}

void dequeue(QUEUE *q)
{
    if (q->f == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nDequeued element: %d\n", q->data[q->f]);
        if (q->f == q->r)
        {
            // Queue is now empty
            q->f = -1;
            q->r = -1;
        }
        else
        {
            q->f = q->f + 1;
        }
    }
}

void display(QUEUE q)
{
    if (q.f == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue elements are: ");
        for (int i = q.f; i <= q.r; i++)
        {
            printf("%d\t", q.data[i]);
        }
        printf("\n");
    }
}

int main()
{
    int item, ch;
    QUEUE q;
    q.f = -1;
    q.r = -1;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Read the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            display(q);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
