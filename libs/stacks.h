int stack[100];
int top = -1;
void push(int num[], int id)
{
	num[++top] = id;
}

void initialize(int stack[])
{
    for (int i = 0; i<100; i++)
    {
        stack[i] = 0;
    }
}
char pop()
{	
	if (top == -1)
	{
		return -1;
	}
	else
	{
	 	return stack[top--];
	}
}

int length_stack(int stack[])
{
    int i=0;
    while(stack[i]!=0)
    {
        i++;
    }
    return i;
}