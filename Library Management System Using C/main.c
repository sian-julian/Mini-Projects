
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct book
{
    char bname[100];
    char author[100];
    float price;
};

struct users
{
    char name[100];
    int age;
    char place[100];
    char usname[100];
    char password[100];
};
int bookcount=0;
int usercount=0;

char username[]="admin";
char password[]="admin123";

void admin(struct book lib[],char username[],char password[],int *bookcount)
{
    char u[100],p[100];
    int ch2,j;
    float pupdate;  //to update the price
    char aname[100]; //to update books
    again:
    printf("\nEnter the username:");
    scanf("%s",u);
    printf("Enter the password:");
    scanf("%s",p);
    
    if(strcmp(u,username)==0 && strcmp(p,password)==0)
    {
        printf("\nWelcome Sian\n\n");
        again2:
        printf("****ADMIN MENU****\n");
        printf("1.Add Book\n2.Display Book\n3.Update Book\n4.Delete Book\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch2);
        
        switch(ch2)
        {
            case 1:
                printf("Enter the Book Name:");
                getchar();
                scanf("%[^\n]", lib[*bookcount].bname);
                
                printf("Enter the Author Name:");
                getchar();
                scanf("%[^\n]", lib[*bookcount].author);
                
                while(1)
                {
                    printf("\nEnter the Price:");
                    scanf("%f",&lib[*bookcount].price);
                    getchar();
                    if(lib[*bookcount].price>0)
                    {
                        break;
                    }
                    else
                    {
                        printf("\nInavlid Price.....please Enter a Valid Price");
                    }
                }
                
                (*bookcount)++;
                goto again2;
                break;
                
            case 2:
                if(*bookcount==0)
                {
                    printf("\nNo books Available");
                }
                else
                {
                    printf("\nLIST OF ALL BOOKS\n\n");
                    for(int i=0;i<*bookcount;i++)
                    {
                        printf("Book no %d\n",i+1);
                        printf("Book name:%s\n",lib[i].bname);
                        printf("Author name:%s\n",lib[i].author);
                        printf("Book price:%.2f\n\n",lib[i].price);     //adding a extra newline
                    }
                }
                goto again2;
                break;
                
            case 3:
                while(1)
                {
                    printf("Enter the book name:");
                    getchar();
                    scanf("%[^\n]", aname);
                  
                    int found=0;
                    for(int i=0;i<*bookcount;i++)
                    {
                        if(strcmp(lib[i].bname,aname)==0)
                        {
                            found=1;
                            while(1)
                            {
                                printf("\nEnter the new Price:");
                                scanf("%f",&pupdate);
                                getchar();
                                if(pupdate>0)
                                {
                                    lib[i].price=pupdate;
                                    break;
                                }
                                else
                                {
                                    printf("\nInavlid Price.....please Enter a Valid Price");
                                }
                            }
                            break;
                        }
                    }
                    if(found)
                    {
                        break;
                    }
                    else
                    {
                        printf("Book not found\n");
                        break;
                    }
                }
                goto again2;
                break;
                
            case 4:
                while(1)
                {
                    printf("Enter the name of the book to delete:");
                    getchar();
                    scanf("%[^\n]", aname);
                    int found=0;
                    for(int i=0;i<*bookcount;i++)
                    {
                        if(strcmp(lib[i].bname,aname)==0)
                        {
                            found=1;
                            
                            for(j=i;j<*bookcount-1;j++)
                            {
                                lib[j]=lib[j+1];
                            }
                            (*bookcount)--;
                            printf("\nBook '%s' deleted successfully.\n", aname);
                            break;
                        }
                    }
                    if (found)
                    {
                        break;  
                    }
                    else
                    {
                        printf("Book not found. Please try again.\n");
                        break;
                    }
                          
                }
                goto again2;
                break;
            case 5:
                return;
            default:
                printf("\nInvalid Choice....Try Again\n");
                goto again2;
        }
        
    }
    else
    {
        printf("\nInvalid username or password....Try again");
        goto again;
    }
}

void user(struct users cust[],int *usercount,int bookcount,struct book lib[])
{
    int ch3,i,j,ch4;
    char u[100],p[100],aname[100];
    again3:
    printf("1.Registation\n2.Login\n3.Exit\n");
    printf("Enter a choice:");
    scanf("%d",&ch3);
    
    switch(ch3)
    {
        case 1:
            printf("Enter the name:");
            getchar();
            scanf("%[^\n]", cust[*usercount].name);
            
            while (1) 
            {
                printf("Enter the age (minimum age is 10): ");
                scanf("%d",&cust[*usercount].age);
                
                if (cust[*usercount].age>=10)
                {
                    break;
                }
                else
                {
                    printf("Invalid age or you are below 10 yrs old...\n");
                }
            }
            
            printf("Enter the place:");
            getchar();
            scanf("%[^\n]", cust[*usercount].place);
            
            int unique;
            do
            {
                unique = 1;  
                printf("Enter the Username:");
                getchar();
                scanf("%[^\n]", cust[*usercount].usname);
    
                for(j=0;j<*usercount;j++)
                {
                    if(strcmp(cust[j].usname, cust[*usercount].usname) == 0)
                    {
                        unique = 0; 
                        printf("Username already exists. Please enter a unique Username.\n");
                        break;
                    }
                }
            } 
            while (!unique); 
            
            while (1) 
            {
                printf("Enter the Password (minimum 5 characters): ");
                getchar(); 
                scanf("%[^\n]", cust[*usercount].password);
                
                if (strlen(cust[*usercount].password)>=5)
                {
                    break;
                }
                else
                {
                    printf("Password is too short. Please enter at least 5 characters.\n");
                }
            }
            
            (*usercount)++;
            goto again3;
            break;
            
        case 2:
            printf("Enter Your Username:");
            getchar();
            scanf("%[^\n]", u);
            printf("Enter Your password:");
            getchar();
            scanf("%[^\n]", p);
            int found=0;
            
            for(i=0;i<*usercount;i++)
            {
                if(strcmp(u,cust[i].usname)==0 && strcmp(p,cust[i].password)==0)
                {
                    printf("Welcome %s", cust[i].name);
                    found=1;
                    again4:
                    printf("\n1.Display Books\n2.Search Books\n3.Exit\n");
                    printf("Enter the choice:");
                    scanf("%d",&ch4);
                    
                    switch(ch4)
                    {
                        case 1:
                            if(bookcount==0)
                            {
                                printf("\nNo books Available");
                            }
                            else
                            {
                                printf("\nLIST OF ALL BOOKS\n\n");
                                for(int i=0;i<bookcount;i++)
                                {
                                    printf("Book no %d\n",i+1);
                                    printf("Book name:%s\n",lib[i].bname);
                                    printf("Author name:%s\n",lib[i].author);
                                    printf("Book price:%.2f\n\n",lib[i].price);     //adding a newline
                                }
                            }
                            goto again4;
                            break;
                        
                        case 2:
                            while(1)
                            {
                                printf("Enter the book name:");
                                getchar();
                                scanf("%[^\n]", aname);
                                int found=0;
                                for(int i=0;i<bookcount;i++)
                                {
                                    if(strcmp(lib[i].bname,aname)==0)
                                    {
                                        found=1;
                                        printf("Book no %d\n",i+1);
                                        printf("Book name:%s\n",lib[i].bname);
                                        printf("Author name:%s\n",lib[i].author);
                                        printf("Book price:%.2f\n\n",lib[i].price);     //adding a newline
                                        break;
                                    }
                                }
                                if(found)
                                {
                                    break;
                                }
                                else
                                {
                                    printf("Book not found\n");
                                    break;
                                }
                            }
                            goto again4;
                            break;
                        
                        case 3:
                            goto again3;
                        
                        default:
                            printf("Invalid choice....Try Again");
                            goto again4;
                    }
                }
            }
            if(!found)
            {
                printf("Invalid Username or Password....try again\n");
                goto again3;
            }
            break;
            
        case 3:
            return;
        default:
            printf("Invalid Choice....Try again");
            goto again3;
    }
}

int main()
{
    struct book lib[100];
    struct users cust[100];
    int ch;
    char again;
    
    begin:
    printf("1.Admin\n2.User\n3.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
  
    switch(ch)
    {
        case 1:
            admin(lib,username,password,&bookcount);
            goto begin;
        case 2:
            user(cust,&usercount,bookcount,lib);
            goto begin;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice....Try Again\n\n");
            goto begin;
    }
    
    return 0;
}