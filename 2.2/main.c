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
    char *line = malloc(sizeof(char)*128);
    size_t len = 128;
    int read;
    
    while((read = getline(&line, &len, stdin)) != -1) {
        printf("read %zu chars\n", read);
        printf("name: %s\n", line);

        Node *cur = malloc(sizeof(Node));
        // +1 for \0, -1 for \n
        char *val = malloc(sizeof(char)*read);
        memcpy(val, line, read);
        cur->val = val;
        printf("read %s\n", cur->val);
//        sprintf(cur->val, "%s", line);
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
