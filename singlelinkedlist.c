#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* createnode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertatbeginning(struct Node** head, int val)
{
    struct Node* newNode = createnode(val);
    newNode->next = *head;
    *head = newNode;
    /*printf("Node inserted at the beginning.\n");*/
}
void insertatend(struct Node** head, int val)
{
    struct Node* newNode = createnode(val);
    if (*head == NULL)
    {
        *head = newNode;
    } else
    {
        struct Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
   /* printf("Node inserted successfully at the end.\n"); */
}
void insertafterposition(struct Node** head, int val, int pos)
{
    struct Node* newNode = createnode(val);
    struct Node* temp = *head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted successfully after position %d.\n", pos);
}
void deleteafterposition(struct Node** head, int pos)
{
    if (*head == NULL)
    {
        printf("Linked list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i <= pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("No node found after position %d.\n", pos);
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node after position %d deleted successfully.\n", pos);
    }
}
void deletefrombeginning(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Linked list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    /*printf("Node deleted successfully from the beginning.\n");*/
}
void deletefromend(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Linked list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(temp);
    /*printf("Node deleted successfully from the end.\n");*/
}
void reverselinkedlist(struct Node** head)
{
    struct Node* prevNode = NULL;
    struct Node* currentNode = *head;
    struct Node* nextNode = NULL;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    *head = prevNode;
}


void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = NULL;
    int ch, val, pos;

    while (1)
    {
        printf("\n--- Choose the operation ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after position\n");
        printf("4. Delete after position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Display linked list\n");
        printf("8. Reverse linked list\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &val);
                insertatbeginning(&head, val);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &val);
                insertatend(&head, val);
                break;
            case 3:
                printf("Enter the position after which to insert: ");
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertafterposition(&head, val, pos);
                break;
            case 4:
                printf("Enter the position after which to delete: ");
                scanf("%d", &pos);
                deleteafterposition(&head, pos);
                break;
            case 5:
                deletefrombeginning(&head);
                break;
            case 6:
                deletefromend(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                reverselinkedlist(&head);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
