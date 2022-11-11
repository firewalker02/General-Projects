/***************************************
* S22 ? Assignment 2 *
* Author: Last name, first name *
* Email: Your email address *
* eecs_username: Your EECS login username *
* York num: Your YorkU student number
****************************************/

#include <stdio.h>
#include <ctype.h>  // for tolower
#include <string.h>
#include <stdlib.h>

#define SIZE 42
#define fieldLength 250



struct db_type
{
   char name[fieldLength];
   
   int age;

   int height;   // cm
   float BMI;
   char status[fieldLength] ;
};

 
char prompt_menu(void);
void enterNew(struct db_type * pArr[]);  
void init_list(struct db_type * pArr[]); 
void displayDB(struct db_type * pArr[]);   
void sortDB(struct db_type * pArr[]);
void updateRecord(struct db_type * pArr[]); 
void removeRecord(struct db_type * pArr[]);
void clearDB(struct db_type * pArr[]);
int length(struct db_type * pArr[]);

int main(int argc, char *argv[])
{
    
    struct db_type * db_pArr[SIZE];  // main db storage

    init_list(db_pArr);  // set to NULL
    
    char choice;
    for(; ;){
      choice = prompt_menu();
      switch (choice)
      {
         case 'n': enterNew(db_pArr); break;
         case 'd': displayDB(db_pArr); break;
        
         case 's': sortDB(db_pArr); break;
	   
         case 'c': clearDB(db_pArr); break;  
        
         case 'u': updateRecord(db_pArr); break;
         case 'r': removeRecord(db_pArr);break;
         
         case 'q': exit(1); // terminate the whole program
       }
	
     }
     return 0;
}

int length(struct db_type * pArr[SIZE]){
	int t;
	for(t=0;pArr[t]!=NULL&&t<SIZE;t++);
	return t;
}
char prompt_menu(void){
  char s[80];
  while(1){
    printf("\n-----------------------------------------------------------------\n");
    printf("|    %-20s","(N)ew record");
    printf("%-20s","(R)emove record");
    printf("(U)pdate record\t|\n");
    printf("|    %-20s","(S)ort database");
    printf("%-20s","(C)lear database");
    printf("(D)isplay database\t|\n");
  
    printf("|    %-20s","(Q)uit");
    printf("*Case Insensitive*\t\t\t|\n");
    printf("-----------------------------------------------------------------\n");
    printf("choose one: ");
  
    fgets(s,50, stdin); // \n added
    //scanf("%s", s);  
    if (strlen(s) == 2 && strchr("edlsuqrcwnvpr", tolower(*s))) 
       return tolower(*s); // s[0], return the first character of s  
    //else
    printf("not a valid input!\n");
	 
 }
}


void init_list(struct db_type * pArr[]){
  int t;
  for (t=0; t<SIZE; t++)
  { 
     pArr[t]= NULL;
  }
}

/* delete all the records in the database */
void clearDB(struct db_type * pArr[]){
   char yn[3];
   printf("are you sure to clear database? (y) or (n)? ");
    
   fgets(yn,3,stdin);
   
   // complete the function by calling init_list();
   if(strcmp(yn,"y\n")==0) 
   init_list(pArr);
   else 
   return;
}


/* input items into the database */
/* hint: need malloc */
void enterNew(struct db_type * pArr[SIZE])
{  

// float *weight=(float *)malloc(sizeof(float)); 
 float weight;
 char *s; //char *p=(char *)calloc(fieldLength,sizeof(char *));
 char p1[fieldLength];
  struct db_type * newStruct=(struct db_type *)malloc(sizeof(struct db_type *)); 
  if(newStruct==NULL) exit(0);
 // if(p==NULL) exit(0);
 
   printf("name: "); 
   fgets(p1,fieldLength,stdin);
  //fgets(newStruct->name,fieldLength,stdin);
 // scanf("%s" ,p);
 strcpy(newStruct->name,p1);
  //strcpy(newStruct->name,p);
   printf("age: ");
  scanf("%d",&newStruct->age);
   printf("height (cm): ");
   scanf("%d",&newStruct->height);
   printf("weight (kg): "); 
   scanf("%f",&weight);
   
   
   int height=newStruct->height;
   float height1=height*1.0/100.0;
   height1=height1*height1;
   float BMI=weight;//adjust pointer

   BMI=BMI/height1;
   
   newStruct->BMI=BMI;
  
   if(BMI<18.5)
   s="Underweight";
   else if(BMI>=18.5&&BMI<=24.999) 
     s="Normal";
   else if(BMI>=25&&BMI<=29.999) 
   s="Overweight";
   else if(BMI>=30&&BMI<=34.999)
   s="Obese I";
   else if(BMI>=35&&BMI<=39.999)
   s="Obese II";
   else 
   s="Obese III";
   strcpy(newStruct->status,s);
   int len=length(pArr);
  *(pArr+len)=newStruct;
   
}

/* remove an existing item from the database */
void removeRecord (struct db_type * pArr[])	
{
  char s[fieldLength];
 // struct db_type* rem=NULL;
  printf("enter full name to remove: ");
fgets(s,fieldLength,stdin);
int t; int p=0;int h=0;
for(t=0;t<SIZE&&pArr[t]!=NULL;t++)
if(strcmp(pArr[t]->name,s)==0){
//rem=pArr[t];
p=t; h=1;break;
}
if(h==1){ 
for(t=p;t<SIZE-1&&pArr[t]!=NULL;t++){
//free(pArr[t]);
pArr[t]=pArr[t+1];
//struct db_type * newStruct=(struct db_type *)malloc(sizeof(struct db_type *)); 
//newStruct=pArr[t+1];
//pArr[t]=newStruct;
if(t==SIZE-2)
pArr[t+1]=NULL;
}
int len=strlen(s);
s[len-1]='\0';
printf("record [%s] removed successfully.",s);
}
else
printf("record not found!");
   

}

/* display all the records in the database. Generate output with the same formaing as the sample output 
 use \t to align well
*/
void displayDB(struct db_type * pArr[]){
  
 int t;
 printf("===============================\n");
t=length(pArr);
 if(t==0){ 
 printf("========== %d records ==========\n",t);
 return;}
 for (t=0; t <SIZE ; t++)
  {
     if( pArr[t] != NULL)
     {
        printf("\nname:\t%s",   pArr[t]->name );  
        printf("age:\t%d",   pArr[t]->age );
        printf("\nheight: %d",   pArr[t]->height );
        printf("\nBMI:\t%.1f",   pArr[t]->BMI );
        printf("\nstatus: %s\n",   pArr[t]->status );
     } 
     else 
     break;
  }
  printf("\n========== %d records ==========\n",t);
 
}


 /* modify an existing item */
void updateRecord (struct db_type * pArr[])	{
   char s[fieldLength];  char *r; char *o;//float *weight=(float *)malloc(sizeof(float)); 
   float weight;
  printf("enter full name to search: ");
  fgets(s,fieldLength,stdin);
  int t; int p=0; int y=0;
for(t=0;t<SIZE&&pArr[t]!=NULL;t++)
if(strcmp(pArr[t]->name,s)==0){
p=1; y=t;break;
}
if(p==1){
printf("record found, enter new weight (kg) : ");
scanf("%f",&weight);
//struct db_type * newStruct=(struct db_type *)malloc(sizeof(struct db_type *)); 
//newStruct=pArr[t];
//int age=newStruct->age;
//r=&pArr[t]->name
//newStruct->age=pArr[t]->age;
//newStruct->height=pArr[t]->height;
//newStruct->BMI=pArr[t]->BMI;
//r=pArr[t]->name;
//o=pArr[t]->status;
//newStruct->name[0]=*r;
//newStruct->status[0]=*o;
//free(pArr[t]);
//pArr[t]=NULL;
//int h=newStruct->height;
int h=pArr[y]->height;
//printf("Age is %d\n:",pArr[t]->age);
float height1=(h*1.0)/100;
height1=height1*height1;

//newStruct->BMI=weight/height1;
pArr[y]->BMI=weight/height1;//update pointer here
//printf("Age is now after 1'st printf %d\n:",pArr[t]->age);
 //float B=newStruct->BMI;
 float B=pArr[y]->BMI;
   if(B<18.5)
   strcat(pArr[y]->status," -> Underweight");
   else if(B>=18.5&&B<=24.999)
    strcat(pArr[y]->status," -> Normal");
   else if(B>=25&&B<=29.999)
  strcat(pArr[y]->status," -> Overweight"); //s="Overweight";
   else if(B>=30&&B<=34.999)
  strcat(pArr[y]->status," -> Obese I");
   else if(B>=35&&B<=39.999)
    strcat(pArr[y]->status," -> Obese II");
   else 
   strcat(pArr[y]->status," -> Obese III");
   //
     // if(B<18.5)
  // strcat(newStruct->status," -> Underweight");
   //else if(B>=18.5&&B<=24.999)
    //strcat(newStruct->status," -> Normal");
   //else if(B>=25&&B<=29.999)
  //strcat(newStruct->status," -> Overweight"); //s="Overweight";
   //else if(B>=30&&B<=34.999)
  //strcat(newStruct->status," -> Obese I");
  // else if(B>=35&&B<=39.999)
   // strcat(newStruct->status," -> Obese II");
  // else 
  // strcat(newStruct->status," -> Obese III");
  // o=newStruct->status;
   //pArr[t]=newStruct; pArr[t]->age=age;
  // free(newStruct);
   //r=&s;
  //strcpy(pArr[t]->name,s);
  // pArr[t]->name[0]=
   int len=strlen(s);
   s[len-1]='\0';
   printf("record [%s] updated successfully.",s);
}	
else 
printf("record not found!");
}

 
// sort the record, either by name or BMI, prompt use for choice
void sortDB(struct db_type * pArr[])
{
 char take[3]; 
 int t; //char s;
 //char* s=(char *) malloc(sizeof(char *)); 
 int i; int min=0; int tr=0; int r=0; int p; int q;
  printf("sort by name (n) or BMI (b)? ");
  fgets(take,3,stdin);
  //scanf("%c",&s);
  if(strcmp(take,"b\n")==0) {
 	for(t=0;t<SIZE&&pArr[t]!=NULL;t++){ 
  	float o=pArr[t]->BMI; tr=t;
  for(i=t;i<SIZE&&pArr[i]!=NULL;i++){ 
  	if(pArr[i]->BMI<o){
  	o=pArr[i]->BMI;
  	tr=i;
  	}
  	
  }
  struct db_type* swap=pArr[t];
  pArr[t]=pArr[tr];
  pArr[tr]=swap;
  }
  //
  } 
  else{
   //printf("Fault not here\n");	//strcpy(s,pArr[0]);
  for(t=0;t<SIZE-1&&pArr[t]!=NULL;t++){ 
  tr=t; min=0;
  for(i=t;i<SIZE-1&&pArr[i]!=NULL/*&&pArr[i+1]!=NULL*/;i++){
  //int r=0; 
  char *k=pArr[t]->name;
  char *l=pArr[i]->name;
  	 p=strcmp(k,l);
     if(p>0){
      struct db_type * newStruct=pArr[t];
  pArr[t]=pArr[i];
  pArr[i]=newStruct;
     }
    //q=strcmp(l,k);
  // printf("Fault not here,2nd time\n");
//if(p<q)
// r=p;
 //else
 //r=q;
   //printf("Fault not here,2nd time\n");
 //if(r<min){
 //min=r;
 //if(r==p)
 //tr=t;
 //else
 //tr=i;
 //}
 
  }
  
 
  //struct db_type * newStruct=pArr[t];
  //pArr[t]=pArr[tr];
  //pArr[tr]=newStruct;
  //min=0;
 // printf("Fault not here,3rd time\n");
  }
  
  }
}




