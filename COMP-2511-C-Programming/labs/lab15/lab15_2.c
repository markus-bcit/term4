typedef struct node node;
struct node
{
    int data;
    node *next;
};

int find_sum (node* head) {
    node *p;
    int sum = 0;

    for (p = head; p != 0; p = p->next)
    {
        sum += p->data;
    }
    return sum;
}
