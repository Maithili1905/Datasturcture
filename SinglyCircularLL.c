//SINGLY CIRCULAR LINKD LIST


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


    void InsertFirst(PPNODE Head , PPNODE Tail , int value)
	{
		PNODE newn = NULL;
		newn = (PNODE)malloc(sizeof(NODE));
		newn-> data = value;
		newn-> next = NULL;
		
		if((*Head == NULL) && (*Tail == NULL))
		{
            *Head = newn;
             *Tail = newn;
		}
        else
		{
            newn-> next = *Head;
            *Head = newn;
		}
          (*Tail)-> next = *Head;
	}


     void Display(PNODE Head , PNODE Tail)
	 {
         if((Head == NULL) && (Tail == NULL))
		 {
             return;
		 }
         do
		 {
            printf("| %d |<->",Head-> data);
            Head = Head-> next;
		 }while(Head != Tail-> next);
		 printf("\n");
	 }		 
		
		
		int Count(PNODE Head , PNODE Tail)
	 {
		 
		 int icnt = 0;
		 
         if((Head == NULL) && (Tail == NULL))
		 {
             return -1;
		 }
         do
		 {
            icnt++;
            Head = Head-> next;
		 }while(Head != Tail ->next);
		 return icnt;
	 }	

        void InsertLast(PPNODE Head , PPNODE Tail ,int value)
		{
            PNODE newn = NULL;
            newn = (PNODE)malloc(sizeof(NODE));
            newn-> data = value;
            newn-> next = NULL;
   
            if((*Head == NULL) && (*Tail == NULL))
			{
				*Head = newn;
                *Tail = newn;
			}
			else
			{
				(*Tail)-> next = newn;
				*Tail = newn;
			}
			(*Tail)-> next = *Head;
		}
		
		
		void InsertAtPos(PPNODE Head , PPNODE Tail ,int value ,int pos)
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
				InsertFirst(Head , Tail ,value);
			}
			else if(pos == size + 1)
			{
				InsertLast(Head ,Tail ,value);
			}
			else 
			{
				newn = (PNODE)malloc(sizeof(NODE));	
				newn-> data = value;
				
				for( i = 1; i < pos -1; i++)
				{
					temp = temp-> next;
				}
				newn-> next = temp-> next;
				temp-> next = newn;
			}
			(*Tail)-> next = *Head;
		}
		
		void DeleteFirst(PPNODE Head ,PPNODE Tail)
		{
			
			if((*Head == NULL) && (*Tail == NULL))
			{
				return;
			}
			
			if(*Head == *Tail)
			{
				free(*Head);
				*Head = NULL;
				*Tail = NULL;
			}
			else
			{
				*Head = (*Head)-> next;
				free((*Tail)-> next);
			}
             (*Tail)-> next = *Head;
			 
		}
		
		
		void DeleteLast(PPNODE Head , PPNODE Tail)
		{
			PNODE temp = *Head;
			
			if((*Head == NULL) && (*Tail == NULL))
			{
			return;
			}
			
			if(*Head == *Tail)
			{
				free(*Tail);
				*Tail = NULL;
				*Head == NULL;
			}
			else
			{
				while(temp-> next != *Tail)
				{
					temp = temp-> next;
				}
				free(*Tail);
				*Tail = temp;
			}
			(*Tail)-> next = *Head;
		}
		
		void DeleteAtPos(PPNODE Head ,PPNODE Tail ,int pos)
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
			
			if(pos == 1)
			{
				DeleteFirst(Head , Tail);
			}
			else if(pos > size)
			{
				DeleteLast(Head , Tail);
			}
			else
			{
				for(i = 1; i < pos - 1; i++)
				{
					temp = temp-> next;
				}
				temp2 = temp-> next;
				temp-> next = temp2-> next;
				free(temp2);
				temp2 = NULL;
			}
		}
				
				
		
			
                 				

int main()
{
	PNODE First = NULL;
	PNODE Last = NULL;
	
	int no = 0;
	int ret = 0;
	int ipos = 0;
	int choice = 1;
	
	printf("\nSINGLY CIRCULAR LINKED LIST\n");
	printf("**********************************\n");
	
	while(choice != 0)
	{
		//printf("\n insert your choice\n");
		printf("\n1. insert first");
		printf("\n2. insert last");
		printf("\n3. insert at position");
		printf("\n4. delete first");
		printf("\n5. delete last");
		printf("\n6. delete at position");
		printf("\n7. display"); 
		printf("\n8. Count the number of node");
		printf("\n0. exit\n");
		
		printf("insert your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			        printf("enter the number\n");
					scanf("%d", &no);
					InsertFirst(&First, &Last ,no);
					break;
					
			case 2:
                    printf("enter the number\n");
                    scanf("%d",&no);
                    InsertLast(&First , &Last , no);
                    break;

            case 3:
                    printf("enter the number\n");
                    scanf("%d",&no);
                    printf("enter the position\n");
                    scanf("%d",&ipos);
                    InsertAtPos(&First ,&Last , no, ipos);
                    break;	

            case 4:
                    DeleteFirst(&First , &Last);
                    break;
					
			case 5 :
                    DeleteLast(&First , &Last);
                    break;

            case 6:
                   printf("enter the position\n");
                   scanf("%d",&ipos);
                   DeleteAtPos(&First ,&Last ,ipos);
                   break;				   
					
			case 7 :
			        Display(First , Last);
					break;
					
			case 8 :
                    ret = Count(First , Last);
                    printf("count is :%d\n", ret);
                    break;

            case 0 :
                     printf("thank you for using this application\n");
                     break;
		}
	}
	
 return 0;
 
} 
