
typedef struct node node;
struct node
{
    int data;
    node *next;
};
int insert_asc(node **phead, int value, int data)
{
    node **tracer;
    node *newNode = malloc(sizeof(node));
    if (newNode == 0)
        return 0;
    newNode->data = value;
    for (tracer = phead; *tracer != 0; tracer = &(*tracer)->next)
    {
        if ((*tracer)->data >= value)
        {
            break;
        }
    }
    newNode->next = *tracer;
    *tracer = newNode;
    return 1;
}

int main()
{
}
/* return the sum of all nodes’ value, return 0 if the list is empty or head is null */
