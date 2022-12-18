#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void mainmenu();
void mvt();
void mft();

int main(){
    mainmenu();
    return 0;
}
void mainmenu(){
    system("clear");
    printf("======================================================================\n");
    printf("\t\t OPERATING SYSTEMS MINI PROJECT\n\n");
    printf("\t1.MVT\n\t2.MFT\n\t3.EXIT\n\nENTER YOUR CHOICE BELOW:\n\n");
    printf("=======================================================================\n");
    printf("\n\n>>");

    int choice;
    scanf("%d", &choice);
    if(choice==1){
        system("clear");
        mvt();
    }
    else if(choice==2){
        system("clear");
        mft();
    }

    else if(choice==3){
        system("clear");
        printf("=======================================================================\n");
        printf("\t\t\t\t\tTHANK YOU\n");
        printf("=======================================================================\n");
        exit(0);
    }
}

void mvt(){
    int ms,mp[10],i, temp,n=0;
char ch = 'y';
system("clear");
printf("\nTotal Memory: ");
scanf("%d",&ms);
temp=ms;
for(i=0;ch=='y';i++,n++)
{
printf("\nEnter memory required for process %d:",i+1);
scanf("%d",&mp[i]);
if(mp[i]<=temp)
{
printf("\nMemory is allocated for Process %d ",i+1);
temp = temp - mp[i];
}
else
{
printf("\nMemory is Full");
break;
}
printf("\nDo you want to continue: ");
scanf(" %c", &ch);
}
printf("\n\nTotal Memory Available =%d", ms);
printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
for(i=0;i<n;i++)
printf("\n \t%d\t\t%d",i+1,mp[i]);
printf("\n\nTotal Memory Allocated = %d",ms-temp);
printf("\nTotal External Fragmentation = %d",temp);
    getchar();
}

void mft(){
  int ms, bs, nob, ef,n, mp[10],tif=0;
int i,p=0;
system("clear");
printf("Total memory: ");
scanf("%d",&ms);
printf("Enter the block size: ");
scanf("%d", &bs);
nob=ms/bs;
ef=ms - nob*bs;
printf("\nEnter the number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter memory required for process %d: ",i+1);
scanf("%d",&mp[i]);
}
printf("\nNo. of Blocks available in memory %d= ",nob);
printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
for(i=0;i<n && p<nob;i++)
{
printf("\n %d\t\t%d",i+1,mp[i]);
if(mp[i] > bs)
printf("\t\tNO\t\t---");
else
{
printf("\t\tYES\t%d",bs-mp[i]);
tif = tif + bs-mp[i];
p++;
}
}
if(i<n)
printf("\nMemory is Full, Remaining Processes cannot be accomodated");
printf("\n\nTotal Internal Fragmentation is %d",tif);
printf("\nTotal External Fragmentation is %d",ef);
getchar();
}