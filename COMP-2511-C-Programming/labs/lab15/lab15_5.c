
typedef struct node node;
struct node
{
    int data;
    node *next;
};
int remove(node **phead, int value)
{
    int removed = 0;

    for (node **p = phead; *p != 0;) {
        if ((*p)->data == value) {
            node *nodeToBeRemoved = *p;
            *p = nodeToBeRemoved->next;
            free(nodeToBeRemoved);
            removed = 1;
        } else {
            p = &(*p)->next;
        }
    }

    return removed;
}

int main()
{
}
/* return the sum of all nodes’ value, return 0 if the list is empty or head is null */
