#include<stdio.h>
#include<dirent.h>
#include<string.h>

int result,count;
char file_name[256];
void search(char*);
int main()
{
result=1;count=0;
printf("This program will search the file in the current and subdirectories\n");
char dir_name[256];
getcwd(dir_name,256);
printf("\nEnter the filename to seacrh\n");
scanf("%s",file_name);
search(dir_name);
if(result==1)
printf("no file exists wit the name %s\n",file_name);
}

void search(char* dir_name)
{
char tempname[256];
DIR* opdir=opendir(dir_name);
count++;
if(opdir==NULL)
{
printf("Directory %s cannot be oppened\n",dir_name);
perror("opendir");
count--;
printf("Number of open files = %d\n",count);
return;
}

struct dirent* entry;
while((entry=readdir(opdir)) != NULL)
{
if(entry->d_type==DT_DIR && (strcmp(entry->d_name,"."))!=0 &&(strcmp(entry->d_name,".."))!=0)
{
strcpy(tempname,dir_name);
strcat(tempname,"/");
strcat(tempname,entry->d_name);
search(tempname);
}
if(strcmp(entry->d_name,file_name)==0)
{
printf("File found at location %s \n",dir_name);
result=0;
}
}
closedir(opdir);
return;
}
