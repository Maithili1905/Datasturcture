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


        void InsertFirst(PPNODE Head,PPNODE Tail, int value)
		{
			PNODE newn = NULL; 
			newn = (PNODE)malloc(sizeof(NODE));
			newn-> data = value;
			newn-> next = NULL;
			newn-> prev = NULL;
			
			if((*Head == NULL) && (*Tail == NULL)) 
			{
				*Head = newn;
				*Tail = newn;
			}
			else
			{
				newn-> next = *Head; 
				(*Head)-> prev = newn;
				*Head = (*Head)-> prev;
			}
			(*Tail)-> next = *Head;
			(*Head)-> prev = *Tail;
		}
		
		
		void Display(PNODE Head,PNODE Tail)
		{
			if((Head == NULL) && (Tail == NULL))
			{
				return;
			}
			
			do
			{
				printf("| %d |<=>",Head-> data);
				Head = Head-> next;
			}while(Head != Tail->next);
		}
		
		
		int Count(PNODE Head,PNODE Tail)
		{
			int icnt = 0;
			if((Head == NULL) && (Tail == NULL))
        {
            return 0;
        }
			
			do
			{
				icnt++;
				Head = Head-> next;
			}while(Head != Tail->next);
			return icnt;
		}
		
		void InsertLast(PPNODE Head,PPNODE Tail , int value)
		{
			PNODE newn = NULL;
			newn = (PNODE)malloc(sizeof(NODE));
			
			newn-> data = value;
			newn-> next = NULL;
			newn-> prev = NULL;
			
			if((*Head == NULL) && (*Tail == NULL))
			{
				*Head = newn;
				*Tail = newn;
			}
			else
			{
				(*Tail)-> next = newn;
				newn-> prev = *Tail;
				*Tail = (*Tail)-> next;
			}
             (*Tail)-> next = *Head;
             (*Head)-> prev = *Tail;
		}
		
		
		void InsertAtPos(PPNODE Head, PPNODE Tail , int value , int pos)
		{
			PNODE newn = NULL;
			PNODE temp = *Head;
			
			int size = 0;
			int i = 0;
			
			size = Count(*Head , *Tail);
			
			if((pos < 1) || (pos > (size + 1)))
			{
				return;
			}
			
			else if(pos == 1)
			{
				InsertFirst(Head , Tail , value);
			}
			else if(pos == size)
			{
				InsertLast(Head , Tail , value);
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
				temp-> next-> prev = newn;
				temp-> next = newn;
				newn-> prev = temp;
			}
			
			(*Tail)-> next = *Head;
             (*Head)-> prev = *Tail;
		}
		
		
		void DeleteFirst(PPNODE Head, PPNODE Tail)
		{
			PNODE temp = *Head;
			
			if((*Head != NULL) && (*Tail == NULL))
			{
				free(*Head);
				*Head = NULL;
				*Tail = NULL;
			}
			else
			{
				*Head = (*Head)->next;
				(*Head)-> prev = *Head;
				free(temp);
			}
			
			(*Tail)-> next = *Head;
             (*Head)-> prev = *Tail;
		}
		
		void DeleteLast(PPNODE Head , PPNODE Tail)
		{
			PNODE temp = *Tail;
			
			if((*Head == NULL) && (*Tail == NULL))
			{
				return;
			}
			
			if(*Head == *Tail )
			{
				free(*Tail);
				*Head = NULL;
				*Tail = NULL;
			}
			
			else
			{
				*Tail  = (*Tail )->prev;
                free((*Tail)->next);      // free(*Head -> prev);
        
			}
			(*Tail)-> next = *Head;
            (*Head)-> prev = *Tail;
		}
		
		
		void DeleteAtPos(PPNODE Head , PPNODE Tail , int pos)
		{
			PNODE temp = *Head;
			PNODE temp2 = NULL;
			
			int size = 0;
			int i = 0;
			
			size = Count(*Head , *Tail);
			
			if((pos < 1) && (pos > size))
			{
				return;
			}
			
			else if(pos == 1)
			{
				DeleteFirst(Head , Tail);
			}
			
			else if(pos == size)
			{
				DeleteLast(Head ,Tail);
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
			(*Tail)-> next = *Head;
            (*Head)-> prev = *Tail;
		}
			
				
				
				
			
				
				
				
				
			
		
			
int main()
{
	PNODE First = NULL;
	PNODE Last = NULL;
	
	int no = 0;
	int ipos = 0;
	int ret = 0;
	int choice = 1;
	
	printf("********************************\n");
	printf("DOUBLY CIRCULAR LINKED LIST\n");
	printf("********************************\n");
	
	while(choice != 0)
	{
		printf("\n1. insert first");
		printf("\n2. insert last");
		printf("\n3. insert at position");
		printf("\n4. delete first");
		printf("\n5. delete last");
		printf("\n6. delete at position");
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
				   InsertFirst(&First , &Last , no);
				   break;
				   
			case 2:
			       printf("enter the number\n");
				   scanf("%d",&no);
				   InsertLast(&First , &Last, no);
				   break;
				   
			case 3:
			       printf("enter the number\n");
				   scanf("%d",&no);
				   printf("enter the position\n");
				   scanf("%d",&ipos);
				   InsertAtPos(&First , &Last , no , ipos);
				   break;
				   
			case 4:
			       DeleteFirst(&First ,&Last);
				   break;
				   
			case 5:
			       DeleteLast(&First ,&Last);
				   break;
				   
			case 6:
			       printf("enter the position\n");
				   scanf("%d",&ipos);
				   DeleteAtPos(&First ,&Last , ipos);
				   break;
				   
			case 7:
			       Display(First,Last);
				   break;
				   
			case 8:
			       ret = Count(First,Last);
				   printf("count of node is :%d",ret);
				   break;
				   
			case 0 :
                    printf("thankyou for using this application\n");
                    break;
		}
	}
	
    return 0;
}	
