#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *createNode()
{
    node *h1;
    h1 = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &(h1->data));
    h1->next = NULL;
    return h1;
}

void display()
{
    node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("Linked List is empty.");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void Insert_At_Start()
{
    node *temp;
    temp = createNode();
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    printf("\nNode Inserted At Start.\n");
}

void Insert_At_End()
{
    node *temp, *ptr;
    temp = createNode();
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    temp->next = NULL;
    printf("\nNode Inserted At End.\n");
}

void Insert_At_After_Value()
{
    node *temp, *ptr;
    int chomu;

    printf("Enter the data after which you want to insert: ");
    scanf("%d", &chomu);

    temp = createNode();
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr != NULL && ptr->data != chomu)
        {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("Node with data %d not found.\n", chomu);
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
            printf("\nNode Inserted after %d\n", chomu);
        }
    }
}

void Insert_At_Before_Value()
{
    node *temp, *ptr, *prev = NULL;
    int chomu;

    printf("Enter the data before which you want to insert: ");
    scanf("%d", &chomu);

    temp = createNode();
    if (head == NULL)
    {
        head = temp;
    }
    else if (head->data == chomu)
    {
        temp->next = head;
        head = temp;
        printf("\nNode Inserted before %d\n", chomu);
    }
    else
    {
        ptr = head;
        while (ptr != NULL && ptr->data != chomu)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("Node with data %d not found.\n", chomu);
        }
        else
        {
            temp->next = ptr;
            prev->next = temp;
            printf("\nNode Inserted before %d\n", chomu);
        }
    }
}

void Insert_At_Position()
{
    node *temp, *ptr;
    int pos, i = 1;
    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos);
    temp = createNode();

    if (head == NULL)
    {
        head = temp;
    }
    else if (pos == 1)
    {
        temp->next = head;
        head = temp;
        printf("\nNode Inserted at position %d\n", pos);
    }
    else
    {
        ptr = head;
        while (ptr != NULL && i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }

        if (ptr == NULL)
        {
            printf("Position %d is out of bounds.\n", pos);
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
            printf("\nNode Inserted at position %d\n", pos);
        }
    }
}

void Deletion_At_Start()
{
    node *temp;
    if (head == NULL)
    {
        printf("There is no node to delete.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        printf("\nNode deleted from beginning.\n");
    }
}

void Delete_At_End()
{
    node *ptr, *temp;
    if (head == NULL)
    {
        printf("There is no node to delete\n");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
        printf("\nNode deleted from End.\n");
    }
    else
    {
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
        printf("\nNode deleted from End.\n");
    }
}

void Delete_At_After_Value()
{
    node *temp, *ptr, *kochu;
    int chomu;

    printf("Enter the data after which you want to delete: ");
    scanf("%d", &chomu);

    if (head == NULL)
    {
        printf("There is no node to delete\n");
        return;
    }

    ptr = head;
    while (ptr != NULL && ptr->data != chomu)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("No node exists after the given value.\n");
    }
    else
    {
        kochu = ptr->next;
        temp = kochu->next;
        ptr->next = temp;
        free(kochu);
        printf("\nNode deleted after %d\n", chomu);
    }
}

void Delete_Before_A_Value()
{
    node *temp, *ptr, *prev = NULL;
    int chomu;

    printf("Enter the data before which you want to delete: ");
    scanf("%d", &chomu);

    if (head == NULL)
    {
        printf("There is no node to delete.\n");
        return;
    }

    if (head->data == chomu)
    {
        printf("There is no node before the given value.\n");
        return;
    }

    ptr = head;
    while (ptr->next != NULL && ptr->next->data != chomu)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("Node with data %d not found.\n", chomu);
    }
    else if (prev == NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = prev->next;
        prev->next = ptr->next;
        free(temp);
    }
    printf("\nNode deleted before %d\n", chomu);
}

void Deletion_at_position()
{
    node *ptr, *temp;
    int pos, i = 1;
    if (head == NULL)
    {
        printf("There is no node to delete.\n");
        return;
    }

    printf("Enter the position where you want to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("\nNode deleted at position 1\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL && i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }

        if (ptr == NULL || ptr->next == NULL)
        {
            printf("Position %d is out of bounds.\n", pos);
        }
        else
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            printf("\nNode deleted at position %d\n", pos);
        }
    }
}

void freeLinkedList()
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
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
        printf("3. Insert After a Value\n");
        printf("4. Insert Before a Value\n");
        printf("5. Insert at Kth Position\n");
        printf("\n6. Delete from Start\n");
        printf("7. Delete from End\n");
        printf("8. Delete After a Value\n");
        printf("9. Delete Before a Value\n");
        printf("10. Delete at Kth Position\n");
        printf("\n11. Display List\n");
        printf("12. Exit\n");
        printf("==============================\n");

        printf("\nEnter your choice: ");
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
            Insert_At_After_Value();
            break;
        case 4:
            Insert_At_Before_Value();
            break;
        case 5:
            Insert_At_Position();
            break;
        case 6:
            Deletion_At_Start();
            break;
        case 7:
            Delete_At_End();
            break;
        case 8:
            Delete_At_After_Value();
            break;
        case 9:
            Delete_Before_A_Value();
            break;
        case 10:
            Deletion_at_position();
            break;
        case 11:
            printf("\nThe Final Linked List is:\n");
            display();
            break;
        case 12:
            printf("Exiting...\n");
            freeLinkedList();
            exit(0);
        default:
            printf("Wrong Input. Please try again.\n");
        }
    }
    return 0;
}
