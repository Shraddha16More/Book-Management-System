#include<stdio.h>
#include<string.h>
typedef struct Book
{
	int bookId;
	char bookName[20];
	char author[20];
	char category[20];
	int price;
	int rating;
}Book;

int cntr=0;

void store(Book* ,int );
void storeHc(Book*);
void display(Book*);
int search(Book*); 
void delete1(Book*); 
void update(Book*);
void sort(Book*,int);
void top(Book*);
void displayy(Book*,int);

void main()
{
	Book b[10];
	int size=10;
	storeHc(b);
	int choice;
	do
	{
		printf("\n");
		printf("1.Store.\n");
		printf("2.Display the data.\n");
		printf("3.Search for the book.\n"); 
		printf("4.Delete record.\n");
		printf("5.Update.\n"); 
		printf("6.Sort.\n");
		printf("7.Top 3");
		printf("\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		fflush(stdin);
		
		switch(choice)
		{
			case 1:
				{
					store(b,size);
				}
				break;
			case 2:
				{
					display(b);
				}
				break;
			case 3:
				{
					int res=search(b);
					if(res==-2)
					{
						printf("Above are the Books!\n");
					}
					else if(res==-1)
					{
						printf("Book not found.\n");
					}
					else
					{
						displayy(b,res);
					}
				}
				break;
			case 4:
				{
					delete1(b);
				}
				break;
			case 5:
				{
					update(b);
				}
				break;
			case 6:
				{
					int ch;
	                printf("Sort by: 1)Price 2)Rating\n");
                	printf("Enter choice: ");
	                scanf("%d",&ch);
					sort(b,ch);
				}
				break;
			case 7:
				{
					top(b);
				}
				break;
			default:
				{
					printf("Invalid choice!");
				}
		}
    }
    while(choice!=0);	
}
void storeHc(Book* b)
{
	b[0].bookId=1;
	strcpy(b[0].bookName, "Ikigai");
    strcpy(b[0].author, "Rampal");
    strcpy(b[0].category, "fiction");
	b[0].price=100;
	b[0].rating=5;
	cntr++;
	
	b[1].bookId = 2;
    strcpy(b[1].bookName, "To_Kill_a_Mockingbird");
    strcpy(b[1].author, "Harper_Lee");
    strcpy(b[1].category, "Fiction");
    b[1].price = 150;
    b[1].rating = 4;
    cntr++;

    b[2].bookId = 3;
    strcpy(b[2].bookName, "The_Great_Gatsby");
    strcpy(b[2].author, "F._Scott_Fitzgerald");
    strcpy(b[2].category, "Classics");
    b[2].price = 120;
    b[2].rating = 3;
    cntr++;

    b[3].bookId = 4;
    strcpy(b[3].bookName, "Sapiens:_A_Brief_History_of_Humankind");
    strcpy(b[3].author, "Yuval_Noah_Harari");
    strcpy(b[3].category, "History");
    b[3].price = 130;
    b[3].rating = 6;
    cntr++;

    b[4].bookId = 5;
    strcpy(b[4].bookName, "Hower");
    strcpy(b[4].author, "Yuval_Noah_Harari");
    strcpy(b[4].category, "Dystopian_Fiction");
    b[4].price = 110;
    b[4].rating = 2;
    cntr++;

    b[5].bookId = 6;
    strcpy(b[5].bookName, "The_Catcher_in_the_Rye");
    strcpy(b[5].author, "J.D._Salinger");
    strcpy(b[5].category, "Coming_of_Age");
    b[5].price = 140;
    b[5].rating = 5;
    cntr++;

    b[6].bookId = 7;
    strcpy(b[6].bookName, "The_Hobbit");
    strcpy(b[6].author, "J.R.R._Tolkien");
    strcpy(b[6].category, "Fantasy");
    b[6].price = 160;
    b[6].rating = 9;
    cntr++;

    b[7].bookId = 8;
    strcpy(b[7].bookName, "The_Da_Vinci_Code");
    strcpy(b[7].author, "Dan_Brown");
    strcpy(b[7].category, "Mystery");
    b[7].price = 125;
    b[7].rating = 8;
    cntr++;
}

void store(Book* b,int size)
{
	if(cntr!=size)
	{
		printf("Enter Book Id: ");
		scanf("%d",&b[cntr].bookId);
		printf("Enter Name of Book: ");
		//gets(b[cntr].bookName);
		scanf("%s",&b[cntr].bookName);
		fflush(stdin);
		printf("Enter Authors's name: ");
		//gets(b[cntr].author);
		scanf("%s",&b[cntr].author);
		fflush(stdin);
		printf("Enter Category: ");
		gets(b[cntr].category);
		printf("Enter Price: ");
		scanf("%d",&b[cntr].price);
		printf("Rate the book: ");
		scanf("%d",&b[cntr].rating);
		
		cntr++;
	//	printf("\ncounter: %d\n",cntr);
	}
	else
	{
		printf("Stock of books is already full.\n");
	}
}

void display(Book* b)
{
	printf("Book Info\n");
	for(int i=0;i<cntr;i++)
	{
		displayy(b,i);
	}
}

int search(Book* b)
{
	int c;
	printf("Search by: 1)BookId 2)Name 3)Author 4)Category \n");
	scanf("%d",&c);
	if(c==1)
	{
		int id;
		printf("Enter Book Id: ");
		scanf("%d",&id);
		for(int i=0;i<cntr;i++)
		{
			if(b[i].bookId==id)
			{
				return i;
			}
		}
		return -1;
	}
	else if(c==2)
	{
		char bname[20];
		printf("Enter Book Name: ");
		scanf("%s",&bname);
		for(int i=0;i<cntr;i++)
		{
			if(strcasecmp(b[i].bookName,bname)==0)
			{
				return i;
			}
		}
		return -1;
	}
	else if(c==3)
	{
		char aname[20];
        int found = 0; 
        printf("Enter Author Name: ");
        fflush(stdin);
        scanf("%s", aname);

        for (int i = 0; i < cntr; i++)
        {
            if (strcasecmp(b[i].author, aname) == 0)
            {
                displayy(b, i);
                found = 1;  
            }
        } 
        return found ? -2 : -1;
		
	}
	else if(c==4)
	{
		char cname[20];
        int found = 0;
        printf("Enter Category: ");
        scanf("%s", &cname);

        for (int i = 0; i < cntr; i++)
        {
            if (strcasecmp(b[i].category, cname) == 0)
            {
                displayy(b, i);
                found = 1;
            }
        }
        return found ? -2 : -1;
	}
	else
	{
		printf("Invalid Input.");
	}
}

void delete1(Book* b)
{
	int id;
	printf("Enter id to delete: ");
	scanf("%d",&id);
	int found=0;
	for(int i=0;i<cntr;i++)
	{
		if(b[i].bookId==id)
		{
			found=1;
			for(int j=i;j<cntr;j++)
			{
				b[j]=b[j+1];
			}
			cntr--;
			break;
		}
    }
    if(found==1)
    {
    	for(int i=0;i<cntr;i++)
    	{
	    	displayy(b,i);
    	}
    }
    else
    {
    	printf("Book not found\n");
	}
    
}

void update(Book* b)
{
	int up;
	printf("Update 1)Price 2)Rating\n");
	scanf("%d",&up);
	if(up==1)
	{
		int id,index=-1;
		printf("Enter id of book to update price: ");
		scanf("%d",&id);
		for(int i=0;i<cntr;i++)
		{
			if(b[i].bookId==id)
			{
			 	 int p;
	        	 printf("Enter price: ");
	        	 scanf("%d",&p);
			     index=i;
			     b[i].price=p;
		    }
		}
		if(index!=-1)
			displayy(b,index);
		else
		{
			printf("Book not found!!");
		}
        
	}
	else if(up==2)
	{
		int id,index=-1;
		printf("Enter id of book to update rating: ");
		scanf("%d",&id);
		for(int i=0;i<cntr;i++)
		{
			if(b[i].bookId==id)
			{
			  	int rt;
		        printf("Enter ratings: ");
	        	scanf("%d",&rt);
				index=i;
				b[i].rating=rt;
			}
		}
		if(index!=-1)
        	displayy(b,index);
        else
            printf("Book not found!!");
    }
}

void sort(Book* b,int ch)
{
	if(ch==1)
	{
		for(int i=0;i<cntr;i++)
		{
			for(int j=i+1;j<cntr;j++)
			if(b[i].price>b[j].price)
			{
				Book temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
//		for(int i=0;i<cntr;i++)
//		{
//			displayy(b,i);
//		}		
	}
	else if(ch==2)
	{
		for(int i=0;i<cntr;i++)
		{
			for(int j=i+1;j<cntr;j++)
		    if(b[i].rating<b[j].rating)
		    {
		    	Book temp=b[i];
			    b[i]=b[j];
		    	b[j]=temp;
		    }
		}
//		for(int i=0;i<cntr;i++)
//		{
//			displayy(b,i);
//		}
	}
}
void top(Book* b)
{
	int c;
	printf("Top 3: 1.Low Priced Books 2.Rated Books");
	scanf("%d",&c);
	sort(b,c);
	for(int i=0;i<3;i++)
	{
		displayy(b,i);
	}
}
void displayy(Book* b,int i)
{
	printf("====================================================================================================================\n");
	printf("| %-3s | %-40s | %-20s | %-20s | %-8s | %-5s | \n","ID","Name","Author","Category","Price","Rating");
	printf("====================================================================================================================\n");
	printf("| %-3d | %-40s | %-20s | %-20s | %-8d | %-6d | \n",b[i].bookId,b[i].bookName,b[i].author,b[i].category,b[i].price,b[i].rating);
    printf("====================================================================================================================\n");
    printf("\n");
}

                    