//DOUBLY LINEAR LINKED LIST


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


        void InsertFirst(PPNODE Head , int value)
		{
			PNODE newn = NULL;
			newn = (PNODE)malloc(sizeof(NODE));
			newn-> data = value;
			newn-> next = NULL;
			newn-> prev = NULL;
			
			if(*Head == NULL)
			{
				*Head = newn;
			}
			else
			{
				newn-> next = *Head;
				(*Head)-> prev = newn;
				*Head = newn;
			}
		}
		
		void Display(PNODE Head)
		{
			
			while(Head != NULL)
			{
				printf("| %d |<=>",Head-> data);
				Head = Head-> next;
			}
		}
		
		int Count(PNODE Head)
		{
			int icnt = 0;
			while(Head != NULL)
			{
				icnt++;
				Head = Head-> next;
			}
			return icnt;
		}
		
		
		void InsertLast(PPNODE Head ,int value)
		{
			PNODE newn = NULL;
			PNODE temp = *Head;
			newn = (PNODE)malloc(sizeof(NODE));
			newn-> data = value;
			newn-> next = NULL;
			newn-> prev = NULL;
			
			if(*Head == NULL)
			{
				*Head = newn;
			}
			else
			{
				while(temp-> next != NULL)
				{
					temp = temp-> next;
				}
				temp-> next = newn;
				newn-> prev = temp;
			}
			
		}
		
		void InsertAtPos(PPNODE Head , int value, int pos)
		{
			PNODE newn =  NULL;
			PNODE temp = *Head;
			
			int size = 0;
			int i = 0;
			
			size = Count(*Head);
			
			if((pos < 1) || (pos > (size + 1)))
			{
				return;
			}
			else if(pos == 1)
			{
				InsertFirst(Head ,value);
			}  
			else if(pos == size)
			{
				InsertLast(Head, value);
			}
			else
			{
				newn = (PNODE)malloc(sizeof(NODE));
				newn-> data = value;
				
				for(i = 1; i < pos -1; i++)
				{
					temp = temp-> next;
				}
				newn-> next = temp-> next;
				temp-> next->prev = newn;
				temp-> next = newn;
				newn-> prev = temp;
			}
		}
		
		
		void DeleteFirst(PPNODE Head)
		{
			PNODE temp = *Head;
			
			if(temp != NULL)
			{
				*Head = temp-> next;
				temp-> next->prev = *Head;
				free(temp);
				temp = NULL;
			}
		}
		
		void DeleteLast(PPNODE Head)
		{
			PNODE temp = *Head;
			if(*Head == NULL)
			{
				return;
			}
			
			if((*Head)-> next == NULL)
			{
				free(*Head);
				*Head = NULL;
			}
			
			else
			{
				while(temp-> next-> next != NULL)
				{
					temp = temp-> next;
				}
				free(temp-> next);
				temp-> next = NULL;
			}
		}
		
		void DeleteAtPos(PPNODE Head , int pos)
		{
			PNODE temp = *Head;
			PNODE temp2 = NULL;
			int size = 0;
			int i = 0;
			
			size = Count(*Head);
			
			if((pos < 1) || (pos > size))
			{
				return;
			}
			
			else if(pos == 1)
			{
				DeleteFirst(Head);
			}
			
			else if(pos == size)
			{
				DeleteLast(Head);
			}
			
			else
			{
				for(i = 1; i < pos - 1; i++)
				{
					temp = temp-> next;
				}
				
				temp2 = temp-> next;
				temp-> next = temp2-> next;
				temp2-> next-> prev = temp;
				free(temp2);
				temp2 = NULL;
				}
		}
				
				
		
		
int main()
{
	PNODE First = NULL;
	
	int no = 0; 
	int ret  = 0;
	int ipos = 0;
	int choice = 1;
	
	printf("********************************\n");
	printf("DOUBLY LINEAR LINKED LIST\n");
	printf("********************************\n");
	
	while(choice != 0)
	{
		printf("\n1. insert first");
		printf("\n2. insert last");
		printf("\n3. insert at position");
		printf("\n4. delete first");
		printf("\n5. delete last");
		printf("\n6. delete at pos");
		printf("\n7. display");
		printf("\n8. count the nodes");
		printf("\n0. exit");
		
		printf("\nenter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			       printf("enter the number\n");
				   scanf("%d",&no);
				   InsertFirst(&First,no);
				   break;
				   
			case 2 :
			        printf("enter the number\n");
					scanf("%d", &no);
					InsertLast(&First , no);
					break;
					
			case 3:
			       printf("enter the number\n");
				   scanf("%d", &no);
				   printf("enter the position\n");
				   scanf("%d",&ipos);
				   InsertAtPos(&First , no, ipos);
				   break;
				   
			case 4:
                    DeleteFirst(&First);
                    break;

            case 5:
                    DeleteLast(&First);
                     break;
					 
				   
			case 6:
			       printf("enter the position\n");
				   scanf("%d",&ipos);
				   DeleteAtPos(&First , ipos);
				   break;
				   
				   
			case 7 :
			        Display(First);
					break;
					
			case 8 :
			        ret = Count(First);
					printf("count of nodes is :%d",ret);
					break;
					
			case 0 :
			        printf("thank you for using this application\n");
					break;
		}
		
		
	}
	return 0;
}



