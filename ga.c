/**
 * This program simulates a basic genetic algorithm and performs operations of reproduction, crossover and mutation. I developed it as part of my coursework assignment in Soft Computing.
 * This concepts and algorithm are from the book "Fuzzy Logic with Engineering Applications" by Timothy J. Ross
 * 
 * @author Abhay Mittal
 *
 *
 * FITNESS FUNCTION => y = C1 x + C2 
 * The parameter set (C1,C2) is encoded in the form of bit strings.
 * The values in this program match those of an example present in the book but they can be changed.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAXSLEN 16
#define FLTLEN 6
#define MAXPOP 10
#define MAXDSIZE 10
#define INIT 0
#define ITER 1

char str[MAXPOP][MAXSLEN+1],sStr[MAXPOP][MAXSLEN+1]; //str represents strings in a current generation after cross over, reproduction and mutation. sStr represents strings selected from previous generation
int cb1[MAXPOP],cb2[MAXPOP],aCount[MAXPOP]; //cb1 and cb2 store the binary value of coefficients from each string, aCount stores the actual count i.e. the number of replications in next generation
float c1[MAXPOP],c2[MAXPOP],y[MAXPOP][MAXDSIZE],eCount[MAXPOP],f[MAXPOP]; //c1 and c2 store the value of coefficients, y stores the output for each data input, eCount stores the relative fitness and f stores the fitness value
float ciMax,ciMin, mutationRate; //ci max and min store the max and min possible values for coefficients. mutationRate is the rate at which mutation takes place. Its unit is per bit per generation.
int xd[MAXDSIZE],yd[MAXDSIZE],dSize,popSize,sLen,largeNum; //xd and yd store the data samples provided. dSize is the data size. popSize is the population size. sLen is the length of each string in the population. largeNum is a very large number used in determining the fitness value (explained later).

void printLine(int n) {
  // function to print a line of  n hypens '-' in stdoutput
  int i;
  for(i=0;i<n;i++)
    printf("-");
  printf("\n");
}

int nDigits(int num) {
  //function to determine the number of digits in an integer
  int n=0;
  if(num==0)
    return 1;
  while(num!=0) {
    n++;
    num/=10;
  }
  return n;
}

int binToInt(char bNum[MAXSLEN],int l, int r) {
  //function to return the integer value of a binary string
  int length=r-l+1;
  int i,j,pwr=1;
  int num=0;
  for(i=r;i>=l;i--) {
    num+=((bNum[i]-48)*pwr);
    pwr<<=1;
  }
  return num;
}

void displayTable(int choice,float max,float avg,float sum) {
  // this function generates a tabular view in the output
  int i,j,k;
  char yd[4];
  printf("%-*s | %-*s | %-*s | %-*s | %-*s | %-*s | ",MAXSLEN," ",MAXSLEN,"",MAXSLEN/2,"",FLTLEN,"",MAXSLEN/2,"",FLTLEN,"");
  for(i=0;i<dSize;i++) {

    printf("%-*s | ",FLTLEN,"");
  }
  printf("%-8s | %-8s | %-8s\n","","Expected","");
  
  printf("%-*s | %-*s | %-*s | %-*s | %-*s | %-*s | ",MAXSLEN," ",MAXSLEN,"",MAXSLEN/2,"C1",FLTLEN,"",MAXSLEN/2,"C2",FLTLEN,"");
  for(i=0;i<dSize;i++) {
    printf("%-*s | ",FLTLEN,"");
  }
  printf("%-8s | %-8s | %-8s\n","","Count =","Actual");
  if(choice==INIT)
    printf("%-*s | %-*s | %-*s | %-*s | %-*s | %-*s | ",MAXSLEN,"String no.",MAXSLEN,"String",MAXSLEN/2,"Bin",FLTLEN,"C1",MAXSLEN/2,"Bin",FLTLEN,"C2");
  else
    printf("%-*s | %-*s | %-*s | %-*s | %-*s | %-*s | ",MAXSLEN,"Selected String",MAXSLEN,"New String",MAXSLEN/2,"Bin",FLTLEN,"C1",MAXSLEN/2,"Bin",FLTLEN,"C2");
  for(i=0;i<dSize;i++) {
    sprintf(yd,"y%d",i+1);
    printf("%-*s | ",FLTLEN,yd);
  }
  printf("%-8s | %-8s | %-8s\n","f(x)","f/avg","Count");
  printLine(2*(MAXSLEN+3)+MAXSLEN+6+(dSize+2)*(FLTLEN+3)+28);

  for(i=0;i<popSize;i++) {
    if(choice==INIT)
      printf("%-*d | ",MAXSLEN,i+1);
    else
      printf("%-*s | ",MAXSLEN,sStr[i]);
    printf("%-*s | %*d | %*.2f | %*d | %*.2f | ",MAXSLEN,str[i],MAXSLEN/2,cb1[i],FLTLEN,c1[i],MAXSLEN/2,cb2[i],FLTLEN,c2[i]);
    for(j=0;j<dSize;j++) {
      printf("%*.2f | ",FLTLEN,y[i][j]);
    }
    printf("%8.2f | %8.2f | %4d\n",f[i],eCount[i],aCount[i]);
  }
  printf("\n ");
  printf("%*s sum = %8.2f\n",  2*(MAXSLEN+3)+MAXSLEN+6+(dSize+2)*(FLTLEN+3)-8,"",sum);
  printf("%*s average = %8.2f\n",  2*(MAXSLEN+3)+MAXSLEN+6+(dSize+2)*(FLTLEN+3)-11,"",avg);
  printf("%*s maximum = %8.2f\n",  2*(MAXSLEN+3)+MAXSLEN+6+(dSize+2)*(FLTLEN+3)-11,"",max);
}

void sortExp(float arr[],int index[], int length) {
  //this function performs bubble sort in arr[] and makes the corresponding changes in index[] too
  int i,j,tp;
  float temp;
  for(i=0;i<length;i++) {
    for(j=0;j<length-1-i;j++) {
      if(arr[j]<arr[j+1]) {
	temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;

	tp=index[j];
	index[j]=index[j+1];
	index[j+1]=tp;
      }
    }
  }
}

int main() {
  float teCount[MAXPOP],count,avg,sum,max;
  int index[MAXPOP];
  char temp;
  float error,threshold;
  int choice=INIT,i,j,k,tIndex;

  srand((unsigned)time(0)); //seed the random number generator with time
  
  popSize=4; // the number of strings in population
  dSize=4; // the number of data elements
  xd[0]=1;xd[1]=2;xd[2]=4;xd[3]=6; //x coordinates of data points
  yd[0]=1;yd[1]=2;yd[2]=3;yd[3]=6; //y coordinates of data points
  ciMax=5;ciMin=-2;
  //initialize the population strings
  strcpy(str[0],"000111010100");
  strcpy(str[1],"010010001100");
  strcpy(str[2],"010101101010");
  strcpy(str[3],"100100001001");
  largeNum=400; //a large numerial value from which the error in each string is subtracted to convert the problem into a maximization problem.
  threshold=0.8F; // the threshold value of the relative fitness (also known as expected count)
  sLen=12;
  mutationRate=0.005F;
  
  do {
    for(i=0;i<popSize;i++) {
      cb1[i]=binToInt(str[i],0,sLen/2-1); //calculate the binary value of c1 from each string
      cb2[i]=binToInt(str[i],sLen/2,sLen-1); //calculate the binary value of c2 from each string
      c1[i]=ciMin+((float)cb1[i]/((float)pow(2,sLen/2)-1))*(ciMax-ciMin); //calculate the value of c1 using the value of cmax and cmin
      c2[i]=ciMin+((float)cb2[i]/((float)pow(2,sLen/2)-1))*(ciMax-ciMin); //calculate the value of c1 using the value of cmax and cmin
      error=0; //initialize error to zero
      for(j=0;j<dSize;j++) {
	y[i][j]=c1[i]*xd[j]+c2[i];
	error+=(yd[j]-y[i][j])*(yd[j]-y[i][j]); //calculate the square of error and add it to the existing value
      }
      f[i]=largeNum-error; //Caclculate the fitness value of each string by subtracting the total error from a large number to change it to a maximization problem
    }

    sum=0;
    max=f[0];
    for(i=0;i<popSize;i++) { //find the sum of the fitness values and the maximum fitness value
      sum+=f[i];
      if(max<f[i])
	max=f[i];
    }
    avg=sum/(float)popSize; //find the average fitness value
    tIndex=0;
    count=0;
    for(i=0;i<popSize;i++) {
      eCount[i]=f[i]/avg; // determine the expected count or the relative fitness value
      if(eCount[i]>=threshold) { // if expected count is greater than fitness, determine the actual count else the actual count will be zero and the string will be eliminated from the next generation.
	teCount[tIndex]=eCount[i]; //tecount is an array which stores the expected count and index of the strings that are able to move to the next generation
	aCount[i]=1; //atleast one copy of survivor will be there.
	index[tIndex]=i;
	count++;
	tIndex++;
      }
      else
	aCount[i]=0;
    }
    
    if(count!=popSize) { //if the number of survivors is less than the population size, replicate the survivors
      sortExp(teCount,index,tIndex); //sort on the basis of expected counts

      for(i=0;count!=popSize;) { //the string with highest expected count replicates first, then next and so on in a circular fashion. Increase the actual counts.
	aCount[index[i]]++;
	count++;
	i=(i+1)%tIndex;
      }
    }
    displayTable(choice,max,avg,sum);
    printf("\nEnter 1 to display next iteration, any other number to exit: ");
    scanf("%d",&choice);
    if(choice==ITER) { //if next generation is to be generated
      j=0;
      //determine the strings which have to be eliminated
      for(i=0;i<popSize;i++) {
	if(aCount[i]==0)
	  index[j++]=i;
      }
      //The next loop simulates the process of REPRODUCTION
      //Put the copies in place of the eliminated strings
      for(j=0,i=0;i<popSize;i++) {
	while(aCount[i]>1) {
	  strcpy(str[index[j++]],str[i]);
	  aCount[i]--;
	}
      }

      //simulate the process of CROSSOVER
      for(i=0;i<popSize;i++)
	strcpy(sStr[i],str[i]);
      k=0;
      //first the initial two strings cross over, then the next two and so on.
      for(i=0;i<popSize;i+=2) {
	j=rand()%sLen; //determine a random position for the crossover
	for(;j<sLen;j++) {
	  temp=str[i][j];
	  str[i][j]=str[i+1][j];
	  str[i+1][j]=temp;
	}
      }
      //simulate the process of MUTATION
      float probab;
      for(i=0;i<popSize;i++) {
	for(j=0;j<sLen;j++) {
	  probab=((float)rand())/((float)RAND_MAX);
	  if(probab<mutationRate) {
	    if(str[i][j]=='0')
	      str[i][j]='1';
	    else
	      str[i][j]='0';
	  }
	}
      }

      
    }
  }
  while(choice==ITER);
  return 0;
}
