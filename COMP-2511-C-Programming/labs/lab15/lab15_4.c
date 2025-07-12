
typedef struct node node;
struct node
{
    int data;
    node *next;
};
int insert_end(node **phead, int value)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == 0)
        return 0;

    newNode->data = value;
    newNode->next = 0;

    if (*phead == 0)
    {
        *phead = newNode;
        return 1;
    }

    node *p;
    for (p = *phead; p->next != 0; p = p->next)
        ;

    p->next = newNode;
    return 1;
}

int main()
{
}
/* return the sum of all nodes’ value, return 0 if the list is empty or head is 0 */
