#include <stdio.h>

int size = 10;
int bt[10];	//burst time
int rear = -1;  
int front = -1;
int tat[10];	//turn-around time
int wt[10];	//waiting time
int p[10];	//process

//for modified order
int rearM = -1;  
int frontM = -1;
int sizeM = 10;

//order based on burst time input
int enqueue(int data)
{
    if(front == -1)
        front = 0;
    
    //rear += 1;
    rear = (rear + 1) % size;    // for circular queue
    bt[rear] = data;
}

//order modified
int fcfs(int data)
{
    if(frontM == -1)
        frontM = 0;
    
    //rear += 1;
    rearM = (rearM + 1) % sizeM;    // for circular queue
    p[rearM] = data;
}

int clear()
{
	return front = -1, rear = -1;   
}

int isFull() 
{

   if(rear == size - 1)
      return 1;
   else
      return 0;
}

void display()
{
    int x;

    printf("Process\tBurst Time\n");

	//order based on burst time input
	if(frontM == -1)
	{
		for(x = front; x <= rear; x++)
	    	printf("P%d\t%d\n", x+1, bt[x]);
	}
	else
	{
		for(x = frontM; x <= rearM; x++)
	    	printf("P%d\t%d\n", p[x], bt[x]);
	}	
}

void displayTAT()
{
    int x;

    printf("Process\tBurst Time\tTurn-around Time\n");
    for(x = front; x <= rear; x++)
	{
		//order based on burst time input
    	if(p[x] == '\0')
    		printf("P%d\t%d\t\t%d\n", x+1, bt[x], tat[x]);
    	
    	//order modified
    	else 
    		printf("P%d\t%d\t\t%d\n", p[x], bt[x], tat[x]);
	}
}

int TAT()
{
	int x, sum = 0;
	
	for(x = front; x <= rear; x++)
	{
		tat[x] = bt[x] + sum;
		sum += bt[x];
	}
}

int WT()
{
	int x, sum = 0;
	
	for(x = front; x <= rear; x++)
	{
		wt[x] = tat[x] - bt[x];
	}
}

void displayWT()
{
    int x;

    printf("Process\tBurst Time\tWaiting Time\n");
    for(x = front; x <= rear; x++)
	{
		//order based on burst time input
    	if(p[x] == '\0')
    		printf("P%d\t%d\t\t%d\n", x+1, bt[x], wt[x]);
    	
    	//order modified
    	else 
    		printf("P%d\t%d\t\t%d\n", p[x], bt[x], wt[x]);
	}
}

float AWT()
{
	int x;
	float awt = 0;
	int sumAWT = 0;
	
    for(x = front; x <= rear; x++)
		sumAWT += wt[x];
	
	awt = (float)sumAWT / (float)(rear + 1);
	
	return awt;
}

float ATT()
{
	int x;
	float att = 0;
	int sumATT = 0;
	
    for(x = front; x <= rear; x++)
		sumATT += tat[x];
	
	att = (float)sumATT / (float)(rear + 1);
	
	return (float)att;
}
