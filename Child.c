# include<stdio.h> 
# include<sys/types.h> 
# include<unistd.h> 
# define MAX_COUNT 10 
void ChildProcess(void); /*Child process prototype*/ 
void ParentProcess(void); /*parent process prototype*/ 
int main() 
{ 
 pid_t pid; 
 if(pid==0) 
 ChildProcess(); 
 else 
 ParentProcess(); 
} 
 void ChildProcess(void) 
 { 
 int i; 
 for(i=1; i<=MAX_COUNT; i++) 
 { 
 if(i%2==0) 
 { 
 printf("%d\n",i); 
 } 
 } 
 printf("This Line is from child,value=%d\n",i); 
 printf("Child Process :%d\n",getpid()); 
 printf(" *** Child process is done ***\n"); 
 } 
 void ParentProcess(void) 
 { 
 int i; 
 for(i=1;i<=MAX_COUNT;i++) 
 { 
 if(i%2!=0) 
 { 
 printf("%d\n",i); 
 } 
 } 
 printf("This Line is Parent,value=%d\n",i); 
 printf("Parent Process :%d\n",getpid()); 
 printf(" *** Child process is done ***\n"); 
 }
