#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int count_nodes(struct node *head) {
    int count = 0;
    struct node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

struct node *find_median_node(struct node *head) {
    int count = count_nodes(head);
    int i;
    struct node *current = head;
    for (i = 0; i < count / 2; i++) {
        current = current->next;
    }
    return current;
}

void sort_list(struct node **head) {
    int i, j, k;
    struct node *p, *q, *top;
    top = (struct node *) malloc(sizeof(struct node));
    top->next = *head;
    p = *head;
    i = 0;
    while (p->next != NULL) {
        q = p->next;
        j = i;
        while (q != NULL) {
            if (p->data > q->data) {
                k = p->data;
                p->data = q->data;
                q->data = k;
                j = 1;
            }
            q = q->next;
        }
        if (j == 0)
            break;
        p = p->next;
        i++;
    }
    *head = top->next;
}

int main() {
    struct node *tmp;
    struct node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(10);
    head->next->next->next->next->next = create_node(11);
    head->next->next->next->next->next->next = create_node(7);
    head->next->next->next->next->next->next->next = create_node(8);
    head->next->next->next->next->next->next->next->next = create_node(9);
    head->next->next->next->next->next->next->next->next->next = create_node(5);
    head->next->next->next->next->next->next->next->next->next->next = create_node(6);

    sort_list(&head);

    while(head->next)
    {
        if (head->data > head->next->data)
            
        // printf("%d\n", head->data);
        // head = head->next;
    }

    // struct node *median_node = find_median_node(head);
    // printf("Node with median value: %d\n", median_node->data);
    return 0;
}