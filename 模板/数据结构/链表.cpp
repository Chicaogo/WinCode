#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

void insert(int num)
{
    Node * new_node, *current;
    new_node = (Node*)malloc(sizeof(Node));

    new_node->key = num;

    if(head == NULL || head->key > num)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        current = head;
        while(1)
        {
            if(current->next ==NULL || current->next->key > num )
            {
                new_node->next = current->next;
                current->next = new_node;
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

void print()
{
   Node * current;
   if(head == NULL)
   {
       printf("链表为空！\n");
   }
   current = head;
   while(current != NULL)
   {
       printf("%d\n",current->key);
       current = current->next;
   }
}

Node * delete(int num)
{
    Node * current = head;
    Node * answer;
    if(head != NULL && head->key == num)
    {
        head = head->next;
        return current;
    }
    else if(head != NULL && head->key > num)
    {
       return NULL;
    }

    while(current != NULL)
    {
        Node * answer;
        if(current->next != NULL && current->next->key == num)
        {
            answer = current->next;
            current->next = current->next->next;
            return answer;
        }else if(current->next != NULL && current->next->key > num)
        {
            return NULL;
        }

        current = current->next;
    }

    return NULL;
}

int main()
{
    Node * x;
    insert(14);
    insert(2);
    insert(545);
    insert(44);
    print();

    x = delete(44);
    if(x != NULL)
    {
        free(x);
    }
    print();


    return 0;
}