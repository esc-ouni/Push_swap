#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int count_nodes(struct node *head) {
    int count = 0;
    struct node *current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

struct node *find_median_node(struct node *head, int *num_nodes) {
    *num_nodes = count_nodes(head);
    int i;
    struct node *current = head;
    for (i = 0; i < (*num_nodes) / 2; i++) {
        current = current->next;
    }
    return current;
}

struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void sort_list(struct node **head) {
    int i, j, k;
    struct node *p, *q, *top;
    top = (struct node *) malloc(sizeof(struct node));
    top->next = *head;
    p = *head;
    i = 0;
    while (p->next) {
        q = p->next;
        j = i;
        while (q) {
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
    struct node *head = create_node(5);
    head->next = create_node(3);
    head->next->next = create_node(2);
    head->next->next->next = create_node(0);
    head->next->next->next->next = create_node(1);
    head->next->next->next->next->next = create_node(4);

    sort_list(&head);

    int num_nodes;
    struct node *median_node = find_median_node(head, &num_nodes);
    printf("Node with median value: %d\n", median_node->data);
    printf("Number of nodes: %d\n", num_nodes);
    return 0;
}

