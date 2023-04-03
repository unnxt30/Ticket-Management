#define TICKETS 50

int stack[TICKETS] = {0};
int top = -1;

void push(int id)
{
	stack[++top] = id;
}

int pop()
{	
	if (top == -1)
	{
		return 1;
	}
	else
	{
	 	top--;
        return 0;
	}
}