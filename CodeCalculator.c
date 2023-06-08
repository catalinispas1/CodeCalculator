#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head;

void insertAtStart(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    head = node;
}

void get_result(double* final_result, int* number_of_operations)
{
    Node* n = head;
    int count_operations = 0;
    n = n->next;

    while(n != NULL)
    {
        if(n->data == 0 && n->next->data == 0)
        {
            *final_result = *final_result + n->next->next->data + n->next->next->next->data;
            n = n->next->next->next->next;
        }
        else if(n->data == 0 && n->next->data == 1)
        {
            *final_result = *final_result + n->next->next->data - n->next->next->next->data;
            n = n->next->next->next->next;
        }
        else if(n->data == 1 && n->next->data == 0)
        {
            *final_result = *final_result + n->next->next->data * n->next->next->next->data;
            n = n->next->next->next->next;
        }
        else if(n->data == 1 && n->next->data == 1)
        {
            *final_result = *final_result + (double)n->next->next->data / n->next->next->next->data;
            n = n->next->next->next->next;
        }

        count_operations ++;

        if(count_operations > *number_of_operations)
        {
            printf("Too many operations, first digit should be bigger\n");
            *final_result = 0;
            return;
        }
    }

    if(count_operations < *number_of_operations)
    {
        printf("Too few operations, first digit should be bigger\n");
        *final_result = 0;
    }
}

int main()
{
    long long n;
    printf("Enter the number:\n");
    scanf("%lld", &n);
    printf("%lld\n",n);
    int number_of_operations = 0;

    while(n != 0)
    {
        if(n / 10 == 0)
        {
            number_of_operations = n;
        }
        int digit = n % 10;
        insertAtStart(digit);
        n = n / 10;
    }

    double final_result = 0;
    
    get_result(&final_result, &number_of_operations);

    printf("%.2f", final_result);
}