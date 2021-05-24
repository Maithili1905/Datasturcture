//SINGLY LINEAR LINKED LIST


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

 void InsertFirst(PPNODE Head,int value)           
  {
	  PNODE newn = NULL;
	  newn = (PNODE)malloc(sizeof(NODE));
	  newn-> data = value;
	  newn-> next = NULL;
	  
	  if(*Head == NULL)
	  {
		  *Head = newn;
	  }
	  else
	  {
		  
			  newn-> next = *Head;
			  *Head = newn;
		  
	  }
  }
  
  void Display(PNODE Head)
  {
	  while(Head != NULL)
	  {
		  printf("| %d |->",Head-> data);
		  Head = Head-> next;
	  }
  }
  
  int Count(PNODE Head)
  {
	  int cnt = 0;
	  
	  while(Head != NULL)
	  {
		  
		  cnt++;
		  Head = Head-> next;
	  }
	  return cnt;
  }
  
  void InsertLast(PPNODE Head, int value)
  {
	  PNODE newn = NULL;
	  PNODE temp = NULL;
	  
	  newn = (PNODE)malloc(sizeof(NODE));
	  newn-> data = value;
	  newn-> next = NULL;
	  
	  
	  
	  if(*Head == NULL)
	  {
		  *Head = newn;
	  }
	  else
	  {
		  temp = *Head;
		  
		  while(temp-> next != NULL)
		  {
			  temp = temp-> next;
		  }
		  
		  temp-> next = newn;
		 
	  }
  }
  
  void InsertAtPos(PPNODE Head , int value , int pos)
  {
	  int size = 0;
	  int i = 0;
	  PNODE newn = NULL;
	  PNODE temp = NULL;
	  
	  size = Count(*Head);
	  
	  if((pos < 1) || (pos > (size +1)))
	  {
        return;
	  }
      else if(pos == 1)
	  {
         InsertFirst(Head,value);
	  }
      else if(pos == size +1)
	  {
          InsertLast(Head, value);
	  }
   
      else
	  {
		  newn = (PNODE)malloc(sizeof(NODE));
		  newn-> data = value;
		  
		  temp = *Head;
		  
		  for(i = 0; i < pos - 1; i++)
		  {
			  temp = temp-> next;
		  }
		  
		  newn-> next = temp-> next;
		  temp-> next = newn;
		  
	  }
  }
  
  void DeleteFirst(PPNODE Head)
  {
	  PNODE temp = *Head;
	  
	  if(temp-> next != NULL);
	  {
		  *Head = temp-> next;
		  free(temp);
		  temp = NULL;
	  }
  }
      

   void DeleteLast(PPNODE Head)
   {
    PNODE temp = *Head;
    
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
	    if(pos == 1)
	   {
		   DeleteFirst(Head);
	   }
	   
	   else if(pos == size)
	   {
		   DeleteLast(Head);
	   }
	   
	   else
	   {
		   for(i = 1 ; i < pos - 1; i++)
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
	int ch = 1;
	int no = 0;
	int ret = 0;
	int ipos = 0;
	
	printf("singlylinked list application\n");
	printf("-----------------------------------------\n");
	
	while(ch != 0)
	{
		printf("\n1. insert first");
		printf("\n2. insert last");
		printf("\n3. insert at a position");
		printf("\n4. delete first");
		printf("\n5. delete last");
		printf("\n6. delete at a position");
		printf("\n7. display");
		printf("\n8. count the nodes");
		printf("\n0. exit\n");
		
		printf("\nenter the choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
			       printf("enter the number\n");
				   scanf("%d",&no);
				   InsertFirst(&First , no);
				   break;
				   
			case 2:
			       printf("enter the number\n");
				   scanf("%d",&no);
				   InsertLast(&First, no);
				   break;
				   
			case 3:
			       printf("enter the number");
				   scanf("%d",&no);
				   printf("enter the position");
				   scanf("%d", &ipos);
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
					
			case 8:
			        ret = Count(First);
					printf("count of elements is:  %d",ret);
					break;
					
			case 0:
			       exit;
				   break;
		}
	}
	return 0;
}
