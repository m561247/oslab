  #include<stdio.h>
 #include<unistd.h>
 #include<sys/types.h>

int main(){

  pid_t A, B, C, D,E,F,G,H,I,J,pid11;
  printf("Parent of all: %d\n",getpid());

  A = fork();

  if(A == 0)
  {   // A child Process. Lets say B.
      printf("A : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
      B = fork();
      if(B == 0){ // A child process. Lets say D.
        printf("B : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
}
else{
    // A child process. Lets say E.
    D = fork();
    if(D == 0){ 
        printf("D : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
        // A child process. Lets say H.
        F = fork();
        if(F == 0)
        { 
            printf("F : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
            // A child process. Lets say I.
            G = fork();
            if(G == 0)
            {   
            printf("G : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
            }
        }
        
    }
    else{
        E = fork();
        if(E == 0)
        { // A child process. Lets say F.
        printf("E : Child with id: %d and its Parent id: %d \n", getpid(),getppid());   
        } 
    }

  }
 }
 if(A > 0){
   C = fork();
  if(C == 0){ // A child process. Lets say C.
    printf("C : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
    // A child process. Lets say G.
    J=fork();
    if(J == 0)
    {
        printf("J : Child with id: %d and its Parent id: %d \n", getpid(),getppid());
    }
   }
  }
for(int i=0; i<3; i++) 
   wait(NULL);  
}
