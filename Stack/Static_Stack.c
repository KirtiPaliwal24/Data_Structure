#include<stdio.h>
#include<limits.h>
int pop(int *, int *);
void push(int *, int *, int);
int main()
{
    int N = 3;
    int Stack[N];
    int choice, top = -1;
    do
    {
        printf("Enter your choice...\n1.Push\n2.Pop\n3.Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            push(Stack, &top, N);
        }
        else if(choice == 2)
        {
            int key = pop(Stack, &top);
            if(key != INT_MAX)
                printf("%d is deleted from stack\n", key);
        }
        else if(choice == 3)
        {
            break;
        }
        else{
            printf("Invalid Choice! Please enter between 1 to 3.\n");
        }
    }while(choice);
    return 0;
}

/*
    Definition of Push function....
    Here, stack and top are pointers due to call by reference. 
    Key is used to insert element within the stack.
*/
void push(int *stack, int *top, int N)
{
    // Checking Overflow Condition
    if(*top == N-1)
        printf("Stack is full!!\n");
    else
    {
        int key;
        printf("Enter element to insert within the stack... ");
        scanf("%d",&key);
        *top = *top + 1; 
        // Note : top is a pointer, top++ or top = top + 1 will change address stored in it not original top value.
        stack[*top] = key;
    }
}

/*
    Definition of Pop function....
    Here, stack and top are pointers due to call by reference. 
    Since, deleted element needs to be returned by function, hence it is not a void function
*/
int pop(int *stack, int *top)
{
    // Underflow Condition
    if(*top == -1){
        printf("Stack is empty!!\n");
        return INT_MAX;
    }
    else
    {
        int key;
        key = stack[*top]; // Store element at the top of the stack
        *top = *top - 1;
        // Note : top is a pointer, top-- or top = top-1 will change the address stored in it not the original top value.
        return key;
    }
}