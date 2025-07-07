
typedef struct node node;
struct node
{
    int data;
    node *next;
};
int find_sum(node *head);

int main()
{
    node *p;
    int m = 0;

    for (p = head; p != 0; p = p->next)
    {
        if (p->data > m)
        {
            m = p->data;
        }
    }
}
/* return the sum of all nodes’ value, return 0 if the list is empty or head is null */
