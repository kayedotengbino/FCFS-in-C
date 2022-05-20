#include <stdio.h>
#include "fcfs.h"

int main() 
{
	int repeat, choice, element, multElement;
	int y = 0, orderChoice, ordered, x;
	
	do
	{
		printf("FCFS MENU\n[1] Burst Time\n[2] Order\n[3] Turn-around Time\n[4] Waiting Time\n[5] Average Waiting Time\n[6] Average Turn-around Time\n[7] Display\n[8]Exit\nChoice: ");
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
                    	
                    	
                        printf("Burst time for P%d: ", y+1);
                        scanf("%d", &element);
					    enqueue(element);
					    

                        printf("Add again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
					    if(multElement == 1)
					    	y++;
					   
                    }
                    else
                    {
                        printf("Sorry, stack is already full");
                        multElement = 0;
                        y = 1;
                    }
				}
				while(multElement == 1);
				
				break;
            case 2:
				system("cls");
				display();
				printf("\nDo you wish to have a desired order of the FCFS? (1 - yes | 0 - no): ");
				scanf("%d", &orderChoice);
				
				if(orderChoice == 1)
				{
					printf("\nBase on the table above, input Process number with corresponding burst time.\n");
					clear();
					for(x = 0; x <= y; x++)
					{
						//Process number
						printf("Process number: ");
						scanf("%d", &ordered);
						fcfs(ordered);
						
						//Corresponding burst time
						printf("Burst Time: ");
						scanf("%d", &element);
						enqueue(element);
					}
				}
				else
					printf("\nFCFS will follow the table above.");
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
                printf("\nATT: %.2f", ATT());
				break;
			case 7:
				system("cls");
                display();
				break;
			case 8:
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
