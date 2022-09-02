#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
  int value;
  struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}

void AddNodeAtEnd(struct node** head, const int num)
{
    struct node* it = *head;
    
    // move iterator to the last position
    while (it->next != NULL)
    {
        it = it->next;
    }
    struct node* el = malloc(sizeof(struct node));
    it->next = el;
    el->value = num;
    el->next = NULL;
}

void RemoveNode(const int idx, struct node** head)
{
    struct node* temp;
    struct node* prev;
    
    temp = *head;
    prev = *head;
    for (int i = 0; i < idx; i++) {
        if (i == 0 && idx == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == idx - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
    
}

int main() {
    // Initialize nodes
    struct node *head;
    
    // Allocate memory
    head = malloc(sizeof(struct node));
    
    // Assign value values
    head->value = 1;
    head->next = NULL;
    
    // Connect nodes
    AddNodeAtEnd(&head, 2);
    AddNodeAtEnd(&head, 3);
    
    // printing node-value
    printLinkedlist(head);
    RemoveNode(6, &head);
    puts("");
    printLinkedlist(head);
    puts("");
}
