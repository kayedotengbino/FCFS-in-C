#include <stdio.h>
#include "fcfs.h"

int main() 
{
	int repeat, choice, element, multElement;
	int x = 1;
	
	do
	{
		printf("FCFS MENU\n[1] Burst Time\n[2] Display\n[3] Turn-around Time\n[4] Waiting Time\n[5] Average Waiting Time\n[6] Average Turn-around Time\n[7] Exit\nChoice: ");
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice)
		{
			case 1:
				system("cls");
	
				do
				{
                    if(!isFull())
                    {
                    	
                    	
                        printf("Burst time for P%d: ", x);
                        scanf("%d", &element);
					    enqueue(element);
					    
					    

                        printf("Add again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
					    if(multElement == 1)
					    	x++;
					   
                    }
                    else
                    {
                        printf("Sorry, stack is already full");
                        multElement = 0;
                        x = 1;
                    }
				}
				while(multElement == 1);
				
				break;
            case 2:
				system("cls");
				display();
				
				break;
            case 3:
                system("cls");
                TAT();
                displayTAT();
                
				break;
            case 4:
            	system("cls");
                WT();
                displayWT();
				break;
            case 5:
				system("cls");
                displayWT();
                printf("\nAWT: %.2f", AWT());
				break;
			case 6:
				system("cls");
                displayTAT();
                printf("\nAWT: %.2f", ATT());
				break;
			case 7:
				printf("Thank you!\n");
				return 0;
			default:
				printf("Invalid choice.\n");
				break;
		}
		
		printf("\nDo you wish to go back to menu? (1 = YES | 0 = NO): ");
		scanf("%d", &repeat);
		
		system("cls");
	}
	while(repeat == 1);
	
	return 0;
}
