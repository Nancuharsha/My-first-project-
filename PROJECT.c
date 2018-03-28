#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<windows.h>
#include<conio.h>
#include <time.h>
/*
linked list of total data.
*/
struct data
{
   char brandname[25];     
   int id;
   char type[30];
   char nameofobject[25];
   float costofbuying;
   float costofselling;
   int numberofpieces;                                                                 
   char housenumber[10];
   char areaname[25];
   char district[25] ;
   char state[25];
   int pincode;
   int phonenumber;
   struct data *nextdata;   
   	
};
  struct data *thalakaya; 
  /*
  linked list of email id
  */
struct data2
{
	char email[30];
    char password[25];
    char forgotpassword[25];
    int addtocart[100];
    int purchasehistory[100];
    int searchhistroy[100];
    struct data2 *nextdata2;
    };
	struct data2 *thalakaya2; 
	/*
	insertion of email into the first linked list
	*/
void newuser(char *s,char *t,char *u)
{
	int i=0;
	struct data2 *temp=malloc(sizeof(struct data2));
	strcpy(temp->email,s);
	strcpy(temp->password,t);
    strcpy(temp->forgotpassword,u);
	for(i=0;i<100;i++)
	{
		temp->purchasehistory[i]=0;
	}
		for(i=0;i<100;i++)
	{
		temp->addtocart[i]=0;
	}
			for(i=0;i<100;i++)
	{
		temp->searchhistroy[i]=0;
	}
	
	temp->nextdata2=thalakaya2;
	thalakaya2=temp;	
 }
 /*
 checking ,is email account is created?
 */
int check1(char *p,char *q)
{
	struct data2 *temp=thalakaya2;
	while(temp!=NULL)
	{
		if((!strcmp(temp->email,p))&&(!strcmp(temp->password,q)))
		return 1;
		temp=temp->nextdata2;
	}
	return 0;
  } 
/*
checking,is email account is created with forgot password?
*/   
int check2(char *e,char *f)
  {
  	struct data2 *temp=thalakaya2;
  	while(temp!=NULL)
  	{
  		if(!strcmp(temp->email,e)&&!strcmp(temp->forgotpassword,f))
  		return 1;
  		temp=temp->nextdata2;
	  }
	  return 0;
  }
/*
inserstion of data into the first linked list of electronic items
*/  
void inserstion(char *bn,int iid,char *tp,char *s,float a,float b,int c,char *d,char*an,char*dt,char*se,int pn,int no)
{
	
	struct data *temp=malloc(sizeof(struct data));
	strcpy(temp->brandname,bn);
	temp->id=iid;
	strcpy(temp->type,tp);
	strcpy(temp->nameofobject,s);
	temp->costofbuying=a;
	temp->costofselling=b;
	temp->numberofpieces=c;
	strcpy(temp->housenumber,d);
	strcpy(temp->areaname,an);
	strcpy(temp->district,dt);
	strcpy(temp->state,se);
	temp->pincode=pn;
	temp->phonenumber=no;
	temp->nextdata=thalakaya;
	thalakaya=temp;                                                                   
}
/*
   display to admin
*/
void displaydatatoadmin()
{
struct data *temp=thalakaya; 
	 printf("OUR PRESENT STOCK ");
	 printf("\nID    brand name     type        name                     buyingprice         sellingprice        nop housenumber area             district         state            pincode  phonenumber\n");
	 while(temp!=NULL)
	 {
        printf("%-6d",temp->id);
	 	printf("%-15s",temp->brandname);
	 	printf("%-12s",temp->type);
		printf("%-25s",temp->nameofobject);
	 	printf("%-20f",temp->costofbuying);
	 	printf("%-20f",temp->costofselling);
	 	printf("%-4d",temp->numberofpieces);
	 	printf("%-12s",temp->housenumber);
		printf("%-17s",temp->areaname);
	 	printf("%-17s",temp->district);
	 	printf("%-17s",temp->state);
	 	printf("%-10d",temp->pincode);
	 	printf("%d",temp->phonenumber);
	 	printf("\n");
	 	temp=temp->nextdata;
	 }
}
/*
  funtion to searchitems
*/
int searchanyitem(char *opp)
{
     char pakkaa='y';  	//
     char phonrrr[20];//
	 float liernjf[100]; //
	 char prroduct[30]; //
	 int ijdfks=0;//
	 int lwofn;//
	 float meddd;//
	 char brandddd[30];
	 int emnf=0;//
	 int kajdnf=0;
	 int lsdje=0;//kinfadf
	 char kinfadf;
	 int kidd=0;
	 int pleorn;//
	 struct data *temp=thalakaya;//
	 struct data2 *tempp=thalakaya2;
        kinmg:
          while(tempp!=NULL)
	        {
	        	if(!strcmp(tempp->email,opp))
	        	break;
	        	tempp=tempp->nextdata2;
			}	
		printf("ENTER THE PRODUCT TYPE \n");
	 	printf("PLEASE TYPE THE NAME AS IT\n");
	 	scanf("%s",prroduct);
		printf("\nbrand name     type        name                price               discount\n");
	 	while(temp!=NULL)
	 	{
	 		if(!strcmp(temp->type,prroduct))
	 	{
	 	  	while(tempp->searchhistroy[kidd]!=0)
			{
				kidd++;
			}
			 tempp->searchhistroy[kidd]=temp->id;
	         printf("%-15s",temp->brandname);
	         printf("%-12s",temp->type);
		     printf("%-20s",temp->nameofobject);
		     printf("%-20f",temp->costofselling);
		     printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);
		}
		  lsdje++;
	 		temp=temp->nextdata;
		}
		 if(lsdje==0)
		 	{
				printf("\nSORRY SIR YOU TYPED WRONG\n");
		       goto kinmg;
	        }
		    printf("\nIF YOU WANT TO SEE ANY ITEM FULL DETAILS PRESS Y IFNOT N\n");
            printf("DONOT WORRY TO CHECK WHETHER CAPS IS ON OR OFF\n");
            fflush(stdin);
	        scanf("%c",&pakkaa);
	        lsdje=0;
		    if(pakkaa=='y'||pakkaa=='Y')		   
		   {
		 	faamam:
		 	printf("\nENTER THE NAME OF THE ITEM\n");
		 	scanf("%s",phonrrr);
		 	printf("\nENTER THE BRAND NAME OF THE ITEM\n");
		 	scanf("%s",brandddd);
		 	temp=thalakaya;
		 	while(temp!=NULL)
		 	{
		 		if((!strcmp(temp->brandname,brandddd))&&(!strcmp(temp->nameofobject,phonrrr)))
		 		{
		 				while(tempp->searchhistroy[kidd]!=0)
			            {
				           kidd++;
			             }
			       tempp->searchhistroy[kidd]=temp->id;
		 			lsdje++;
		 		  printf("\nid     brand name     name                price nof discount\n");	
		 		  printf("%-6d",temp->id);
		          printf("%-15s",temp->brandname);
		          printf("%-20s",temp->nameofobject);
		          printf("%-6f",temp->costofselling);
                  printf("%-4f",temp->numberofpieces);
		          printf("%f",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);	
				  printf("\nIF YOU WANT TO ADDTO CART THE IEM PRESS Y IFNOT PRESS N\n");
				  printf("donot worry to check whether caplock is on or off\n");
				  fflush(stdin);
				 scanf("%c",&kinfadf);
				 if(kinfadf=='y'||kinfadf=='Y')
				 {
				 while(tempp->addtocart[kajdnf]!=0)
				 {
				 	kajdnf++;
				 }
				 tempp->addtocart[kajdnf]=temp->id;
				 }
				 kajdnf=0;
				 printf("\nIF YOU WANT TO BUY THE IEM PRESS Y IFNOT PRESS N\n");
				  printf("donot worry to check whether caplock is on or off\n");
				  fflush(stdin);
				 scanf("%c",&kinfadf);
				  if(kinfadf=='y'||kinfadf=='Y')
				  {
				  	 while(tempp->purchasehistory[kajdnf]!=0)
				 {
				 	kajdnf++;
				 }
				 tempp->purchasehistory[kajdnf]=temp->id;
				  }
				 }
		 		temp=temp->nextdata;
		 		lsdje++;
			 }
			 }
			 if(lsdje==1)
			{
				printf("\nSORRY SIR YOU TYPED WRONG\n");
			  goto faamam;
			 }
return 0;	
}
/*
  funtion to campareitems
*/
void campareitems(char *opp)
{	
	 char fatftft[30];//
	 char ppppaaae[30];//
	 char klksdl[30];//
	 char faaakkd[30];//
	 char laownc='y';
	 int pownf=0;
	 int kdal;
	 struct data *temp;//
	 struct data2 *tempp;
	 tempp=thalakaya2;
	  fanto:
		  	laowjer:
		  		 while(tempp!=NULL)
	        {
	        	if(!strcmp(tempp->email,opp))
	        	break;
	        	tempp=tempp->nextdata2;
			}	
		  	printf("\nENTER THE NAME OF THE PRODUCT \n");
		  	scanf("%s,",fatftft);
		  	printf("\nENTER THE BRAND NAME\n");
		  	scanf("%s",ppppaaae);
		  	printf("\nENTER THE ANOTHER PRODUCT NAME \n");
		  	scanf("%s",klksdl);
		  	printf("\nENTER THE ANOTHER BRAND NAME\n");
		  	scanf("%s",faaakkd);
		    temp=thalakaya;
		  	while(temp!=NULL)
		  	{
		  		if(!strcmp(temp->brandname,ppppaaae)&&!strcmp(temp->nameofobject,fatftft))
		  		goto faaaasd;
		  		temp=temp->nextdata;
			}
		
			  printf("\nSIR YOU TYPED SOMETHING WRONG\n");
			  goto fanto;
			    faaaasd:
			  	while(tempp->searchhistroy[pownf]!=0)
			    {
			 	pownf++;
			    }
			 tempp->searchhistroy[pownf]=temp->id;
		       printf("id     brand name     name                price               nop discount\n");
		       printf("%-6d",temp->id);
		       printf("%-15s",temp->brandname);
		       printf("%-20s",temp->nameofobject);
		       printf("%-20f",temp->costofselling);
               printf("%-4f",temp->numberofpieces);
		       printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);
		       temp=thalakaya;
		  	while(temp!=NULL)
		  	{
		  		if(!strcmp(temp->brandname,faaakkd)&&!strcmp(temp->nameofobject,klksdl))
		  		goto funntime;
		  		temp=temp->nextdata;
			  }
			  printf("\nSOMETHING WRONG YOU HAVE TYPED PLEASE ENTER AGAIN\n");
			  goto laowjer;
			  	  funntime:
			  pownf=0;
			  	while(tempp->searchhistroy[pownf]!=0)
			 {
			 	pownf++;
			 }
			 tempp->searchhistroy[pownf]=temp->id;
		     printf("%-6d",temp->id);
		     printf("%-15s",temp->brandname);
		     printf("%-20s",temp->nameofobject);
		     printf("%-6f",temp->costofselling);
             printf("%-4f",temp->numberofpieces);
		     printf("%f",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);
	         printf("\nIF YOU WANT TO ADD TO CARTTHE ANY OF THE ITEM PRESS Y\n");
		     printf("DONOT WORRY TO CHECK WHETHER CAPS LOCK IS ON OR OFF\n");
		     fflush(stdin);
		     scanf("%c",&laownc);
		     if(laownc=='y'||laownc=='Y')
		    {
			printf("\nwhich onE of the item you want to add to cart(if first one press 1) \n");
			scanf("%d",&kdal);
			if(kdal==2)
			{
				kdal=0;
		      while(tempp->addtocart[kdal]!=0)
			  {
			  	kdal++;
			  }
			  tempp->addtocart[kdal]=temp->id;
		   }
			else
			{
				
				kdal=0;
		      while(tempp->addtocart[kdal]!=0)
			  {
			  	kdal++;
			  }
			    temp=thalakaya;
		  	while(temp!=NULL)
		  	{
		  		if(!strcmp(temp->brandname,ppppaaae)&&!strcmp(temp->nameofobject,fatftft))
		  		break;
		  		temp=temp->nextdata;
			}
			 tempp->addtocart[kdal]=temp->id; 
			}
			printf("\nWE AHVE ADD TO TO YOUR CART\n");
		} 
		printf("\nIF YOU WANT TO BUY THE ANY OF THE ITEM PRESS Y\n");
		printf("DONOT WORRY TO CHECK WHETHER CAPS LOCK IS ON OR OFF\n");
		fflush(stdin);
		scanf("%c",&laownc);
		if(laownc=='y'||laownc=='Y')
		{
			printf("\nwhich on of hte item you want to buy(if first one press 1) \n");
			scanf("%d",&kdal);
			if(kdal==2)
			{
				kdal=0;
		      while(tempp->purchasehistory[kdal]!=0)
			  {
			  	kdal++;
			  }
			  tempp->purchasehistory[kdal]=temp->id;
		   }
			else
			{	
				kdal=0;
		      while(tempp->purchasehistory[kdal]!=0)
			  {
			  	kdal++;
			  }
			    temp=thalakaya;
		  	while(temp!=NULL)
		  	{
		  		if(!strcmp(temp->brandname,ppppaaae)&&!strcmp(temp->nameofobject,fatftft))
		  		break;
		  		temp=temp->nextdata;
			}
			 tempp->purchasehistory[kdal]=temp->id; 
			}
			printf("YOUR ORDER IS ON THE WAY\n");	
		}
}
/*
  search by brand funtion  
*/
void searchbybrand(char *opp)
{
	int i=0;
	char k[30];
	char lk;
	char ll[30];
	struct data2 *tempp=thalakaya2;
	struct data *temp=thalakaya;
    while(tempp!=NULL)
    {
    	if(!strcmp(tempp->email,opp))
         break;
    	tempp=tempp->nextdata2;
	}
	printf("ENTER THE BRAND NAME \n");
	scanf("%s",k);
    printf("brand name     type        name                price               discount\n");  
	while(temp!=NULL)
	{
		if(!strcmp(temp->brandname,k))
         {
         	while(tempp->searchhistroy[i]!=0)
         	{
         		i++;
			 }
			 tempp->searchhistroy[i]=temp->id;
          printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
		 }
		temp=temp->nextdata;
	}
	printf("\nIF YOU WANT TO BUY ANY ITEM PRESS Y IF NOT N \n");
	printf("DONOT WORRY TO CHECK WHETHER CAPS LOCK IS ON OR OFF \n");
	fflush(stdin);
	scanf("%c",&lk);
	if(lk=='y'||lk=='Y')
	{
		lsl:
		printf("\nENTER THE PRODUCT NAME \n");
		scanf("%s",ll);
		temp=thalakaya;
		while(temp!=NULL)
		{
			if(!strcmp(temp->brandname,k)&&!strcmp(temp->nameofobject,ll))
            break;
			temp=temp->nextdata;
		}
		i=0;
		while(tempp->purchasehistory[i]!=0)
		{
			i++;
		}
		tempp->purchasehistory[i]=temp->id;
		printf("YOU HAVE BRUGHT IT\n");
	}
	printf("IF YOU WANT TO BUY ANOTHER PRESS Y IFNOT N\n");
	printf("DONOT WORRY TO CHECK WHETHER CAPSLOCK IS ON OR OFF\n");
	fflush(stdin);
	scanf("%c",&lk);
	if(lk=='y'||lk=='Y')
	{
		goto lsl;
	} 
	printf("\nIF YOU WANT TO ADD TO CART ANY ITEM PRESS Y IF NOT N \n");
	printf("DONOT WORRY TO CHECK WHETHER CAPS LOCK IS ON OR OFF \n");
	fflush(stdin);
	scanf("%c",&lk);
	if(lk=='y'||lk=='Y')
	{
		pppp:
		printf("\nENTER THE PRODUCT NAME \n");
		scanf("%s",ll);
		temp=thalakaya;
		while(temp!=NULL)
		{
			if(!strcmp(temp->brandname,k)&&!strcmp(temp->nameofobject,ll))
            break;
			temp=temp->nextdata;
		}
		i=0;
		while(tempp->addtocart[i]!=0)
		{
			i++;
		}
		tempp->addtocart[i]=temp->id;
		printf("YOU HAVE ADD TO CART IT\n");
	}
    printf("IF YOU WANT TO ADD TO CART ANOTHER PRESS Y IFNOT N\n");
	printf("DONOT WORRY TO CHECK WHETHER CAPSLOCK IS ON OR OFF\n");
	fflush(stdin);
	scanf("%c",&lk);
	if(lk=='y'||lk=='Y')
	{
		goto pppp;
	 } 
}
/*
purchase history of items funtions
*/
void purchasehistroy(char *opp)
{
	int isjn=0;
     struct data *temp=thalakaya;
     struct data2 *tempp=thalakaya2;
     while(tempp!=NULL)
     {
     	if(!strcmp(tempp->email,opp))
     	break;
     	tempp=tempp->nextdata2;
	 }
	 	printf("brand name     type        name                price               discount\n");
        while(tempp->purchasehistory[isjn]!=0)
        {
        temp=thalakaya;
        while(temp!=NULL)
        {
        if(temp->id==tempp->purchasehistory[isjn])	
		{		
		printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);	 
          break;
 }temp=temp->nextdata;
 }isjn++;
}}
/*
  funtion to find total amount to be paid 
*/
void totalamount(char *opp)
{
	 int j=0;
	 float i=0;
	 struct data2 *tempp=thalakaya2;
     while(tempp!=NULL)
     {
     	if(!strcmp(tempp->email,opp))
     	break;
     	tempp=tempp->nextdata2;
	 }
	 while(tempp->purchasehistory[j]!=0)
	 {
	 
	 i=i+tempp->purchasehistory[j];
	 j++;
}
printf("\nTOTAL AMOUNT TO BE PAID \n%f",i);
}
/*
 funtion for search history
*/
void searchhis(char *opp)
{
	int i=0;
	struct data *temp=thalakaya;
	struct data2 *tempp=thalakaya2;
	 while(tempp!=NULL)
     {
     	if(!strcmp(tempp->email,opp))
     	break;
     	tempp=tempp->nextdata2;
	 }
	 printf("brand name     type        name                price              discount\n");
	 while(tempp->searchhistroy[i]!=0)
	 {
	 	temp=thalakaya;
	 	while(temp!=NULL)
	 	{
	 		if(tempp->searchhistroy[i]==temp->id)
	 		{
	 			printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
			 break;
			 }
		 temp=temp->nextdata;
		 }
	 	i++;
	 }
}
/*
   funtion to see cart 
*/
void seecart(char *opp)
{
	int isjn=0;
 struct data *temp=thalakaya;
     struct data2 *tempp=thalakaya2;
     while(tempp!=NULL)
     {
     	if(!strcmp(tempp->email,opp))
     	break;
     	tempp=tempp->nextdata2;
	 }
	 	printf("brand name     type        name                price               discount\n");
        while(tempp->addtocart[isjn]!=0)
        {
        temp=thalakaya;
        while(temp!=NULL)
        {
        if(temp->id==tempp->addtocart[isjn])	
		{		
		printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);	 
          break;
 }temp=temp->nextdata;
 }	isjn++;
}}
/*
    funtion to delete account
*/
void deleteaccount(char *opp)
{
  int i=1,j;
  struct data *temp=thalakaya;
  struct data2 *tempp=thalakaya2;
  struct data2 *temp1;
	while(tempp!=NULL)
	{
		if(!strcmp(tempp->email,opp))
		break;
     i++;
	 tempp=tempp->nextdata2;		
	}
   	if(i==1)  
	{
		thalakaya2=tempp->nextdata2;
	    free(tempp);
     }
	else
	{
	for(j=0;j<i-2;j++)
	{
		tempp=tempp->nextdata2;
	}
	temp1=tempp->nextdata2;
	tempp->nextdata2=temp1->nextdata2;
	free(temp1);
}
printf("\nYOUR ACCOUNT IS DELETED\n");
}
/*
   funtion for the deletecart
*/
void deletecart(char *opp)
{
	int i=0;
	struct data *temp=thalakaya;
	struct data2 *tempp=thalakaya2;
	while(tempp!=NULL)
	{
		if(!strcmp(tempp->email,opp))
		break;
		tempp=tempp->nextdata2;
	}
	while(tempp->addtocart[i]!=0)
	{
		tempp->addtocart[i]=0;
		i++;
	}
	printf("\nYOUR CART IS EMPTY\n");
}
/*
   funtion to find popular items
*/
void popit(char *opp)
{
	int i=0;
	char k;
	struct data *temp=thalakaya;
	struct data2 *tempp=thalakaya2;
	while(tempp!=NULL)
	{
		if(!strcmp(tempp->email,opp))
		{
			break;
		}
		tempp=tempp->nextdata2;
	}
	while(temp!=NULL)
	{
		if(temp->id==7)
		break;
		temp=temp->nextdata;
	}
	while(tempp->searchhistroy[i]!=0)
	{
		i++;
	}
	tempp->searchhistroy[i]=temp->id;
	printf("brand name     type        name                price               discount\n");
	printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
		  printf("IF YOU WANTTO BUY THE ITEM PRESS Y IF NOT N\n");	
		  printf("DONOT WORRY TO SEE WHETHER CAPSLOCK IS ON OR OFF\n");
		  fflush(stdin);
		  scanf("%c",&k);
		  if(k=='y'||k=='Y')
		  {
		  	i=0;
		  	while(tempp->purchasehistory[i]!=0)
		  	{
		  		i++;
		    }
		   tempp->purchasehistory[i]=temp->id;	  
		 } 
		  printf("IF YOU WANTTO ADD TO THE CART THE ITEM PRESS Y IF NOT N\n");	
		  printf("DONOT WORRY TO SEE WHETHER CAPSLOCK IS ON OR OFF\n");
		  fflush(stdin);
		  scanf("%c",&k);
		  if(k=='y'||k=='Y')
		  {
		  	i=0;
		  	while(tempp->addtocart[i]!=0)
		  	{
		  		i++;
		    }
		   tempp->addtocart[i]=temp->id;	  
		 } 
		 
}
/*
  funtion for gving items list.
*/
int displaydatatoconsumer(char *opp)
{
	 int lakae;//
	 struct data *temp=thalakaya;
     printf("OUR PRODUCTS \n");
	 printf("brand name     type        name                price               discount\n");
	 while(temp!=NULL)
	     {
	      printf("%-15s",temp->brandname);
	      printf("%-12s",temp->type);
		  printf("%-20s",temp->nameofobject);
		  printf("%-20f",temp->costofselling);
		  printf("%f\n",((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
		  temp=temp->nextdata; 
		 }
		 king:
		 	king2:
		 		king3:
		 			king4:
		 				king6:
		 					king7:
		 						king8:
		 							king9:
		 								king10:
		 									king11:
    printf("\nIF YOU WANT TO SEARCH ANY ITEM TYPE PRESS 1\nIF YOU WANT TO COMPARE ITEMS PRESS 2\nIF YOU WANT TO SEE YOU PURCHASE HISTORY PRESS 3\nIF YOU WANT TO SEE YOUR CART PRESS 4\nIF YOU WANT DELETE YOUR ACCOUNT PRESS 5\nIF YOU WANT TO SIGNOUT PRESS 6\nIF YOU WANT A PRINT OUT IN THE FILE PRESS 7\nIF YOU WANT TO CLEAR CART PRESS 8\nIF YOU WANT TO SEE SEARCH HISTEORY PRESS 9\nIF YOU WANT TO SEE TOTAL AMOUNT OF PURCHASE PRESS 10\nIF YOU WANT TO SEARCH BY BRAND PRESS 11\nIF YOU WANT TO SEE POPULAR ITEM PRESS 12\n");
	scanf("%d",&lakae);
	if(lakae==1)
	{
	searchanyitem(opp);	
	goto king;
	}
    if(lakae==2)
    {
    	campareitems(opp);
    	goto king2;
	}
	if(lakae==3)
	{
		purchasehistroy(opp);
	    goto king3;
	}
	if(lakae==4)
	{
		seecart(opp);
		goto king4;
	}
	if(lakae==5)
	{
		deleteaccount(opp);
	return 0;
	}
	if(lakae==6)
	{
		return 0;
	}
	if(lakae==7)
	{
		consumer(opp);
		goto king6;
	}
	if(lakae==8)
	{
		deletecart(opp);
		goto king7;
	}
	if(lakae==9)
	{
		searchhis(opp);
		goto king8;
	}
	if(lakae==10)
	{
		totalamount(opp);
		goto king9;
	}
	if(lakae==11)
	{
		searchbybrand(opp);
		goto king10;
	}
	if(lakae==12)
	{
		popit(opp);
		goto king11;
	}
 return 0;
}
/*
  funtion for the counsumer to print out in the file.
*/
int consumer(char *opp)
{
	 int i=0;
     struct data2 *tempp=thalakaya2; 
     struct data *temp=thalakaya;
	 while(tempp!=NULL)
	 {
	 	if(!strcmp(tempp->email,opp))
	 	break;
	 	tempp=tempp->nextdata2;
	 }
	  FILE *fayaaa;
	 fayaaa=fopen("custermers info.txt","w");
	  if(fayaaa==NULL)
	   {
	   	printf("YOUR FILE CANNOT OPEN");
	   	exit(0);
	   }
	   fprintf(fayaaa,"YOUR DATA OF THE ACCOUNT \n");
	   fprintf(fayaaa,"EMAIL ID %s\n",tempp->email);
	   fprintf(fayaaa,"PASSWORD %s\n",tempp->password);
	   fprintf(fayaaa,"FORGET PASSOWORD %S\n",tempp->forgotpassword);
       fprintf(fayaaa,"\nYOUR PURCHASE HISTORY\n");
       fprintf(fayaaa,"brand name     type        name                price               discount\n");
	   while(tempp->purchasehistory[i]!=0)
	   {
	   	temp=thalakaya;
	   	while(temp!=NULL)
	   	{ 
	   	if(temp->id==tempp->purchasehistory[i])
	   	 	{
			 fprintf(fayaaa,"%-15s",temp->brandname);
	         fprintf(fayaaa,"%-12s",temp->type);
		     fprintf(fayaaa,"%-20s",temp->nameofobject);
		     fprintf(fayaaa,"%-20f",temp->costofselling);
		     fprintf(fayaaa,"%f",(float)((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
		   }
		   temp=temp->nextdata;
		   }
		    i++;
	   	}
	   	fprintf(fayaaa,"\nYOUR CART HISTORY\n");
       fprintf(fayaaa,"brand name     type        name                price               discount\n");
	   	i=0;
	   	 while(tempp->addtocart[i]!=0)
	   {
	   	temp=thalakaya;
	   	while(temp!=NULL)
	   	{ 
	   	if(temp->id==tempp->addtocart[i])
	   	 	{
			 fprintf(fayaaa,"%-15s",temp->brandname);
	         fprintf(fayaaa,"%-12s",temp->type);
		     fprintf(fayaaa,"%-20s",temp->nameofobject);
		     fprintf(fayaaa,"%-20f",temp->costofselling);
		     fprintf(fayaaa,"%f",(float)((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100+5);
		   }
		   temp=temp->nextdata;
		   }
		    i++;
	   	}
	   		fprintf(fayaaa,"\nYOUR SEARCH HISTORY\n");
       fprintf(fayaaa,"brand name     type        name                price               discount\n");
	   	i=0;
	   	 while(tempp->searchhistroy[i]!=0)
	   {
	   	temp=thalakaya;
	   	while(temp!=NULL)
	   	{ 
	   	if(temp->id==tempp->searchhistroy[i])
	   	 	{
			 fprintf(fayaaa,"%-15s",temp->brandname);
	         fprintf(fayaaa,"%-12s",temp->type);
		     fprintf(fayaaa,"%-20s",temp->nameofobject);
		     fprintf(fayaaa,"%-20f",temp->costofselling);
		     fprintf(fayaaa,"%f",(float)((temp->costofselling-temp->costofbuying)/temp->costofbuying)*100);
		   }
		   temp=temp->nextdata;
		   }
		    i++;
	   	}  
	   	fclose(fayaaa);
	 return 0;
	}
/*
   funtion to print out all data of admin into the file.
*/	
int adminfile()
{
	struct data *temp=thalakaya;
	FILE *fayaap;
	fayaap=fopen("adminfinal.txt","w");
	if(fayaap==NULL)
	{
		printf("YOUR FILE CANNOT OPEN");
	    exit(0);
	}
    fprintf(fayaap,"\nID    brand name     type        name                     buyingprice         sellingprice         nop housenumber area             district         state            pincode  phonenumber\n");
    while(temp!=NULL)
    {
    	fprintf(fayaap,"%-6d",temp->id);
    	fprintf(fayaap,"%-15s",temp->brandname);
    	fprintf(fayaap,"%-12s",temp->type);
    	fprintf(fayaap,"%-25s",temp->nameofobject);
	 	fprintf(fayaap,"%-20f",temp->costofbuying);
	 	fprintf(fayaap,"%-20f",temp->costofselling);
	 	fprintf(fayaap,"%-4d",temp->numberofpieces);
	 	fprintf(fayaap,"%-12s",temp->housenumber);
		fprintf(fayaap,"%-17s",temp->areaname);
	 	fprintf(fayaap,"%-17s",temp->district);
	 	fprintf(fayaap,"%-17s",temp->state);
	 	fprintf(fayaap,"%-8d",temp->pincode);
	 	fprintf(fayaap,"%ld\n",temp->phonenumber);
    	temp=temp->nextdata;
	}
	return 0;
}
/*
    gobal variable for the game is declared
*/
char box[11][11]={
"   *   *   ","   *   *   ","   *   *   ","***********","   *   *   ","   *   *   ","   *   *   ","***********","   *   *   ","   *   *   ","   *   *   "};
/*
    inserstion of values to the positions of gobal values by palyer 1 
*/
int king(int a)
{
      
         if(a==7&&box[1][1]==' ')
    {
        box[1][1]='!';
       
       
    }
    else if(a==8&&box[1][5]==' ')
    {
        box[1][5]='!';
         
    }
    else if(a==9&&box[1][9]==' ')
    {
        box[1][9]='!';
        
    }
    else if(a==4&&box[5][1]==' ')
    {
        box[5][1]='!';
    
    }
   else if(a==5&&box[5][5]==' ')
    {
        box[5][5]='!';
        
    }
    else if(a==6&&box[5][9]==' ')
    {
        box[5][9]='!';
        
    }
    else if(a==1&&box[9][1]==' ')
    {
        box[9][1]='!';
        
    }
    else if(a==2&&box[9][5]==' ')
    {
        box[9][5]='!';
        
    }
    else if(a==3&&box[9][9]==' ')
    {
        box[9][9]='!';
        
    }
    else 
    {
        printf("your game is completed or you pressed other key");
    }
   return 0; 
}
/*
    insertion of vaules into the gobal values by players 2 or comp
*/
int king2(int a)
{
           if(a==7&&box[1][1]==' ')
    {
        box[1][1]='&';
       
       
    }
    else if(a==8&&box[1][5]==' ')
    {
        box[1][5]='&';
         
    }
    else if(a==9&&box[1][9]==' ')
    {
        box[1][9]='&';
        
    }
    else if(a==4&&box[5][1]==' ')
    {
        box[5][1]='&';
    
    }
    else if(a==5&&box[5][5]==' ')
    {
        box[5][5]='&';
        
    }
    else if(a==6&&box[5][9]==' ')
    {
        box[5][9]='&';
        
    }
    else if(a==1&&box[9][1]==' ')
    {
        box[9][1]='&';
        
    }
    else if(a==2&&box[9][5]==' ')
    {
        box[9][5]='&';
        
    }
    else if(a==3&&box[9][9]==' ')
    {
        box[9][9]='&';
        
    }
     else 
    {
        printf("your game is completed or you pressed other key");
    }
   return 0;
}
/*
check for the whether game is over or not
*/
int checck()
{
    int k=0;
    if(box[1][1]=='&' && box[1][1]==box[1][5] && box[1][9]==box[1][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[5][1]=='&' && box[5][1]==box[5][5] && box[5][9]==box[5][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[9][1]=='&' && box[9][1]==box[9][5] && box[9][9]==box[9][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[1][1]=='&' && box[1][1]==box[5][5] && box[9][9]==box[1][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[1][9]=='&' && box[1][9]==box[5][5] && box[1][9]==box[9][1])
    {
        printf("you game is over");getch();
        return k++;
    }
     if(box[1][1]=='&'&&box[1][1]==box[5][1]&&box[9][1]==box[1][1])
    {
    	printf("your game is over");getch();
    	return k++;
	}
	if(box[1][5]=='&'&&box[1][5]==box[5][5]&&box[9][5]==box[1][5])
    {
    	printf("your game is over");getch();
    	getch();
    	return k++;
	}
	if(box[1][9]=='&'&&box[1][9]==box[5][9]&&box[9][9]==box[1][9])
    {
    	printf("your game is over");getch();
    	return k++;
	}
    if((box[1][1]=='!'||box[1][1]=='&')&&(box[1][5]=='!'||box[1][5]=='&')&&(box[5][1]=='!'||box[5][1]=='&')&&(box[1][9]=='!'||box[1][9]=='&')&&(box[9][1]=='!'
	||box[9][1]=='&')&&(box[5][5]=='!'||box[5][5]=='&')&&(box[5][9]=='!'||box[5][9]=='&')&&(box[9][5]=='!'||box[9][5]=='&')&&(box[9][9]=='!'||box[9][9]=='&'))
	{
		printf("your game is over");getch();
		return k++;
	}
    return k;
}
/*
 check whether game is over or not .
*/
int checck2()
{
    int k=0;
    if(box[1][1]=='!' && box[1][1]==box[1][5] && box[1][9]==box[1][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[5][1]=='!' && box[5][1]==box[5][5] && box[5][9]==box[5][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[9][1]=='!' && box[9][1]==box[9][5] && box[9][9]==box[9][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[1][1]=='!' && box[1][1]==box[5][5] && box[9][9]==box[1][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[1][9]=='!' && box[1][9]==box[5][5] && box[1][9]==box[9][1])
    {
        printf("you game is over");getch();
        return k++;
    }
    if(box[1][1]=='!'&&box[1][1]==box[5][1]&&box[9][1]==box[1][1])
    {
    	printf("your game is over");getch();
    	return k++;
	}
	if(box[1][5]=='!'&&box[1][5]==box[5][5]&&box[9][5]==box[1][5])
    {
    	printf("your game is over");getch();
    	return k++;
	}
	if(box[1][9]=='!'&&box[1][9]==box[5][9]&&box[9][9]==box[1][9])
    {
    	printf("your game is over");getch();
    	return k++;
	}
    if((box[1][1]=='!'||box[1][1]=='&')&&(box[1][5]=='!'||box[1][5]=='&')&&(box[5][1]=='!'||box[5][1]=='&')&&(box[1][9]=='!'||box[1][9]=='&')&&(box[9][1]=='!'
	||box[9][1]=='&')&&(box[5][5]=='!'||box[5][5]=='&')&&(box[5][9]=='!'||box[5][9]=='&')&&(box[9][5]=='!'||box[9][5]=='&')&&(box[9][9]=='!'||box[9][9]=='&'))
	{
		printf("your game is over");getch();
		return k++;
	}
    return k;
}
/*
  printing the game or array on the screen 
*/
int print()
{
    int i,j;
    for(i=0;i<=10;i++)
    {
        for(j=0;j<=10;j++)
        {
            printf("%c",box[i][j]);
            if(j==10)
            break;
            
        }
        printf("\n");
        if(i==10)
        break;
    }
    return 0;
}
/*
main game funtion
*/
int game()
{
    int a,k,i,j,m,n,p,l,h,kk,ll,jj,hh;
   
    printf("Do you want play againist com press 1 or multy player press 2\n");
    scanf("%d",&p);
	switch(p)
	{
	case 1:  
	{
	for(i=0;i<=3;i++)
   {
      system("cls");
       print();
        printf("\nexample : if you want to enter in topleft position press 7 similarly top mid position press 8.\n"); 
        printf("press the number of position ");
        scanf("%d",&a);
        king(a);
        system("cls");
        print();
        fflush(stdin);
		kk=checck();
        if(kk==1)
        goto kk34;
        k=rand()%9+1;
        king2(k);
        system("cls");
        print();
        fflush(stdin);
	    ll=checck2();
        if(ll==1)
        goto kk1;
   } 
   kk34:
   	kk1:
   break;
   }
   case 2:
   	{
   		for(i=0;i<=3;i++)
   		{
   			system("cls");
   			printf("\nexample : if you want to enter in topleft position press 7 similarly top mid position press 8.\n"); 
		    printf("enter the num of position by the first player\n");
		    print();
			scanf("%d",&l);
		    king(l);
		    system("cls");
		    print();
		    fflush(stdin);
			jj=checck();
		    if(jj==1)
		    goto kkk;
			printf("enter the num of position by the second player\n");
		    scanf("%d",&h);
		    king2(h);
		    system("cls");
		    print();
		    fflush(stdin);
		    hh=checck2();
		   if(hh==1)
		   goto aaa;
		   }
		   kkk:
		   	aaa:
		   break;
	   }   
} return 0;
}
/*
   sort the main linked list 
*/
void sortthearray()
{
	int i=0,j=0,k=0;
	int a;
	char braand[30];
	char type[25];
	char pronam[30];
	float bp;
	float sp;
	int np;
	char hn[30];
	char an[30];
	char dn[30];
	char sn[30];
	int pin;
	int pn;
	struct data *temp=thalakaya;
	struct data *temp1;
	struct data *temp2;
	while(temp!=NULL)
	{
		i++;
		temp=temp->nextdata;
	}
	for(j=0;j<i;j++)
	{
		temp=thalakaya;
		temp1=thalakaya;
		temp2=thalakaya->nextdata;
		for(k=0;k<(i-j-1);k++)
		{
			if(temp1->costofselling>temp2->costofselling)
			{
				a=temp2->id;
				strcpy(braand,temp2->brandname);
				strcpy(type,temp2->type);
				strcpy(pronam,temp2->nameofobject);
				bp=temp2->costofbuying;
				sp=temp2->costofselling;
				np=temp2->numberofpieces;
				strcpy(hn,temp2->housenumber);
				strcpy(an,temp2->areaname);
				strcpy(dn,temp2->district);
				strcpy(sn,temp2->state);
				pin=temp2->pincode;
				pn=temp2->phonenumber;
			    temp2->id=temp1->id;
			    strcpy(temp2->brandname,temp1->brandname);
			    strcpy(temp2->type,temp1->type);
			    strcpy(temp2->nameofobject,temp1->nameofobject);
			    temp2->costofbuying=temp1->costofbuying;
			    temp2->costofselling=temp1->costofselling;
			    temp2->numberofpieces=temp1->numberofpieces;
			    strcpy(temp2->housenumber,temp->housenumber);
				strcpy(temp2->areaname,temp1->areaname);
				strcpy(temp2->district,temp1->district);
				strcpy(temp2->state,temp1->state);
				temp2->pincode=temp1->pincode;
				temp2->phonenumber=temp1->phonenumber;
			    temp1->id=a;
				strcpy(temp1->brandname,braand);
				strcpy(temp->type,type);
				strcpy(temp1->nameofobject,pronam);
				temp1->costofbuying=bp;
				temp1->costofselling=sp;
				temp1->numberofpieces=np;
				strcpy(temp1->housenumber,hn);
				strcpy(temp1->areaname,an);
				strcpy(temp1->district,dn);
				strcpy(temp1->state,sn);
				temp1->pincode=pin;
				temp1->phonenumber=pn;
			}
			temp1=temp1->nextdata;
			temp2=temp1->nextdata;
		}
	}
}
/*
main funtion 
*/
int main()
{

	int x;
	int cao,npw,mpw,k=0;
	char pw[30];
	char password[30];
	int lockfailure=0;
	thalakaya=NULL;
	thalakaya2=NULL;
	char emailname[30];
	char epassword[30];
	char forpass[30];
	char saraley[30];
	char ffff[30];
	char enjoy;
	char againracreate;
	char emailid[30];
	inserstion("samsung",1,"phone","z21",5444.2,5555.5,10,"4-345","kachiguda","warangal","telangana",506112,99999);
	inserstion("samsung",2,"phone","z22",5777.0,5987.5,5,"4-345","kachiguda","warangal","telangana",506112,999999);
	inserstion("nokia",3,"phone","asha206",3000.0,3200.0,15,"4-346","kachiguda","warangal","telangana",506112,9999999);
	inserstion("mi",4,"phone","redmi4",15000.0,15500.5,12,"8-3454","thorrur","mahabubnagar","karnataka",543255,9348465);
	inserstion("mi",5,"phone","redmi5",15000.0,15500.5,12,"8-3454","thorrur","mahabubnagar","karnataka",543255,9348465);
	inserstion("micromax",6,"phone","canvas",8000.0,8500.0,10,"49-239","urpanlly","kesamudram","maharastra",542543,9482349);
	inserstion("micromax",7,"phone","canvas-j",7000.0,7800.0,9,"847-23","pantnicenter","thigalaveni","tamilnadu",938434,9234324);
	sortthearray();
	system("color 9a");
	printf("                     \"Harsha\" WELCOMES YOU TO THE STORE\n");
	printf("--------------------------------------------------------------------------------------------");
	tostart:
	printf("\nIF ADMIN PRESS '0' \nIF NEW TO THE SITE PRESS 2\n ");
	scanf("%d",&cao);
	if(cao==2)
       {
       	printf("\nWE HAVE HAPPY TO SEE YOU SIR\n");
       	firstofcreat:
       	printf("WE ARE CREARTING A NEW ACCOUNT \n");
       	printf("ENTER YOUR EMAIL\n");
       	scanf("%s",emailname);
       	printf("\nENTER YOUR PASSWORD\n");
       	scanf("%s",epassword);
       	printf("\nENTER YOUR FORGET PASSWORD(for your safty when your password)\n");
		scanf("%s",forpass);
		newuser(emailname,epassword,forpass);
        if(check1(emailname,epassword))	
	    {
		  displaydatatoconsumer(emailname);	
		  goto popopop;
		}
		else
		{
			printf("\nYOUR ACCOUNT WAS NOT CREATED\n");
			printf("IF YOU WANT TO CREATE ANOTHER PRESS Y IFNOT N\n");
			printf(" DONOT WORRY TO CHECK WHETHER CAPSLOCK IS OFF OR ON\n");
			fflush(stdin);
			scanf("%c",&againracreate);
			if(againracreate=='y'||againracreate=='Y')
			{
				goto firstofcreat;
			}
	    }	   	
	   }
    if(cao==0) 
    {
    	start:
    	printf("ENTER THE PASSWORD\n");
        printf(" DONOT WORRY TO CHECK WHETHER CAPSLOCK IS OFF OR ON\n");
		scanf("%s",pw);
    	npw=strcmp(pw,"Harsha");
    	mpw=strcmp(pw,"Harsha");
    	if(npw==0||mpw==0)
    	{
		lllllll:
       	displaydatatoadmin();
       	adminfile();
       	goto pantp;
       	}
		   if(k>=2)
       	{
       		printf("\nENTER YOUR FORGET PASSWORD\n");
	        scanf("%s",saraley);
			if(saraley=="youalsoforgetspassword")
			goto lllllll; 
		   }
        printf("\nSORRY SIR WRONG PASSWORD \n");
        printf("YOU HAVE MAX 5 CHANCES\n");
        k++;
        if(k==4)
        {
         printf("YOUR CHANCES ARE OVER SIR MEANS YOUR NOT ADMIN YOU ARE GOING TO EXIT\n");		
        goto ened;
       }
        goto start;	
	}
	else
	{
		printf("SORRY SIR YOU PRESSED OTHER 0 AND 1");
		goto tostart;
	}
	ennd:
	ened:
		pantp:
			popopop:
			printf("SIR LETS HAVE A GAME IF AGREE PRESS Y IF NOT N\n");
			fflush(stdin);
			scanf("%c",&enjoy);
			if(enjoy=='y'||enjoy=='Y')
			{
			game();
	        printf("\nI THINK YOU HAVE A LOT OF FUN\n");
		 }
		  
      //*******************SOUND********************************///////////////////////////////////////////////////////////
        for (x = 0; x<5; x++)
        {
            Beep(523,500); // Jingle 
        }
         Beep(523,800);
		printf("\nTHANK YOU SIR FOR VIST .\n");
return 0; 
////
////
////
////
////
////
////
////
////
////
}
