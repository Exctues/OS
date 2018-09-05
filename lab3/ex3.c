#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Linked_list {
    Node *right; // Same as head
    Node *left;  // Same as tail
    int size;
} Linked_list;


void print_list(Linked_list *list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    if (list->size == 0) { // empty list case
        printf("List is empty\n");
        return;
    }
    printf("Elements of Linked_list:\n");

    Node *node = list->left;
    int i = 0;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
        i++;
    }
    printf("\n");
}


void append_right(Linked_list *list, int val) {
    // Check for Exceptions
    if (list == NULL) {
        printf("Exception. List is null\n");
        return;
    }
    // create node with given value
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (list->size == 0) { // empty list case
        list->right = node;
        list->left = node;
    } else {
        list->right->next = node;
        list->right = node;
        node->next = NULL;
    }
    list->size++;
}

void append_left(Linked_list *list, int val) {
    // Check for Exceptions
    if (list == NULL) {
        printf("Exception. List is null\n");
        return;
    }
    // create node with given value
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (list->size == 0) { // empty list case
        list->right = node;
        list->left = node;
    } else {
        node->next = list->left;
        list->left = node;
    }
    list->size++;
}

void insert(Linked_list *list, int val, int pos) {
    // Check for Exceptions
    if (list == NULL) {
        printf("Exception. List is null\n");
        return;
    }
    if (pos < 0) {
        printf("Exception. Position must >= 0\n");
        return;
    }
    if (pos > list->size) {
        printf("Exception. Position bigger than the size of the list\n");
        return;
    }

    if (list->size == 0) {// empty list case
        // create node with given value
        Node *node = malloc(sizeof(Node));
        node->val = val;
        node->next = NULL;

        list->right = node;
        list->left = node;
    } else {
        if (pos == 0) {
            append_left(list, val);
            return;
        }
        if (pos == list->size) {
            append_right(list, val);
            return;
        } else {
            Node *cur_node = list->left;
            while (pos > 1) {
                cur_node = cur_node->next;
                pos--;
            }
            // create node with given value
            Node *node = malloc(sizeof(Node));
            node->val = val;
            node->next = NULL;

            Node *tmp = cur_node->next;
            cur_node->next = node;
            node->next = tmp;
        }
    }
    list->size++;
}

void delete(Linked_list *list, int pos) {
    if (pos < 0) {
        printf("Exception. Position must >= 0\n");
        return;
    }
    if (pos >= list->size) {
        printf("Exception. Position equal or bigger than the size of the list\n");
        return;
    }
    if (pos == 0) {
        Node *tmp = list->left;
        list->left = list->left->next;
        free(tmp);
    } else {
        Node *cur_node = list->left;
        while (pos > 1) {
            cur_node = cur_node->next;
            pos--;
        }
        // BTW, cur_node always will be BEFORE NODE we need to delete, so cur_node->next is never NULL;
        Node *toRemove = cur_node->next;
        cur_node->next = toRemove->next;
        if (toRemove->next == NULL) { // It means that we deleted last element so we need change our right
            list->right = cur_node;
        }
        free(toRemove);
    }

    list->size--;
}

void init_list(Linked_list *list) {
    list->size = 0;
    list->left = NULL;
    list->right = NULL;
}

int main(void) {
    Linked_list *l = malloc(sizeof(Linked_list));
    init_list(l);

    append_left(l, -300);
    append_left(l, -200);
    append_left(l, -100);

    insert(l, 5, 2);
    insert(l, 55, 0);
    insert(l, 555, l->size);

    append_right(l, 100);
    append_right(l, 200);
    append_right(l, 300);

    print_list(l);
    delete(l, 1);
    print_list(l);
    delete(l, 3);
    print_list(l);
    delete(l, 0);
    print_list(l);
    delete(l, l->size - 1);
    print_list(l);
    return 0;
}
