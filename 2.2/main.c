#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node{
    Node *next;
    char *val;
};

Node *find_last(Node *head, int k)
{
    Node *cur = head;
    Node *trailing = head;

    int i = 0;

    while(cur != NULL) {
        cur = cur->next;
        if (i>=k) {
            trailing = trailing->next;
        }
        i++;
    } 

    return trailing;
}

int main (int argc, char **argv)
{
    Node *head = NULL;
    char *line = NULL;
    size_t len = 0;
    int read;
    
    while((read = getline(&line, &len, stdin) >= 0)) {
        Node *cur = malloc(sizeof(Node));
        cur->val = malloc(sizeof(char)*(read+1));
        sprintf(cur->val, "%s", line);
        cur->next = head;
        head = cur;
    }

    Node *cur = head;

    while(cur != NULL){
        printf("%s", cur->val);
        cur = cur->next;
    }

    Node *res = find_last(head, 10);
    printf("10th to last is %s\n", res->val);

    return 0;
}
