#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} nd;

nd *head = NULL;

nd *createnode()
{
    nd *new_node = (nd *)malloc(sizeof(nd));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}

void display()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    nd *ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(back to head)\n");
}

void Insert_At_Start()
{
    nd *new_node = createnode();
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        nd *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

void Insert_At_End()
{
    nd *new_node = createnode();
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        nd *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void Insert_At_Position()
{
    int pos, i = 1;
    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        Insert_At_Start();
        return;
    }
    nd *new_node = createnode();
    nd *temp = head;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Position out of range.\n");
            free(new_node);
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void Deletion_At_Start()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    nd *temp = head;
    if (head->next == head)
    {
        head = NULL;
        free(temp);
        return;
    }
    nd *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
    printf("Node Deleted\n");
}

void Delete_At_End()
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    nd *temp = head, *prev = NULL;
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    printf("Node Deleted\n");
}

void Deletion_at_position()
{
    int pos, i = 1;
    printf("Enter the position where you want to delete: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    if (pos == 1)
    {
        Deletion_At_Start();
        return;
    }
    nd *temp = head, *prev = NULL;
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == head)
        {
            printf("Position out of range.\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    printf("Node Deleted\n");
}

int main()
{
    while (1)
    {
        int ch;
        printf("\n==============================\n");
        printf("            MENU              ");
        printf("\n==============================\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Kth Position\n");
        printf("4. Delete from Start\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Kth Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Insert_At_Start();
            break;
        case 2:
            Insert_At_End();
            break;
        case 3:
            Insert_At_Position();
            break;
        case 4:
            Deletion_At_Start();
            break;
        case 5:
            Delete_At_End();
            break;
        case 6:
            Deletion_at_position();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Wrong Input. Please try again.\n");
        }
    }
    return 0;
}
