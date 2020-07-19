#include<stdio.h>
#include<stdlib.h>


//You are given a string s containing "1"s and "0"s and an integer k. 
//Return the minimum number of swaps required so that there's a group of k contiguous "1"s. 
//Swaps must be adjacent.
/*Constraints:

n <= 100,000 where n is the length of s.
Example 1

Input:
s = "10011"
k = 3

Output:
2

Explanation:
We can swap the first "1" right twice to have 3 contiguous "1"s.*/


int main(){
	
	
	int n,k;
	printf("How many elements is the string:");
	scanf("%d",&n);
	char s[n];
	printf("Enter a string s containing '1's and '0's:\n");
	scanf("%s",s);
	printf("Enter an integer k:");
	scanf("%d",&k);
	
	printf("\ns=%s",s);
	printf("\nk=%d",k);
	
	int *array=(int*)malloc(n*sizeof(n));
	
	int i,j,count=0,count2=0,count3=0,a=0;
	
	for(i=0;i<n;i++){
		if(s[i]=='1'&&s[i+1]=='1'){
			count++;
			
		}
		
		if(s[i]=='1'){
		   	array[a]=i;	
			a++;
			count2++;		
			
		}
		
		
		
	}
	
	array=(int*)realloc(array,count2*sizeof(int));
	
	printf("\n\nThe place of 1's in string:");
	for(i=0;i<count2;i++){
		printf("\n%d",array[i]);
	}
	
	//count+1=Number of adjacent 1s
	int swapp_=k-(count+1);
	
	
	
	
	int *array2=(int*)malloc(count2*sizeof(n));
	
	int b=0;
	
	if(swapp_==0){
		printf("\n\nThe minimum number of swaps required:%d",0);
	}
	
	else{
	    for(i=0;i<count2-1;i++){
	    	if(array[i+1]-array[i]-1!=0){
	    		array2[b]=array[i+1]-array[i]-1;
	    		count3++;
	    		b++;
	    		
	
			}
		}	
		
		
		
	}	
	
	array2=(int*)realloc(array2,count3*sizeof(int));
	
	int m,l,x;
	for(m=1;m<count3;m++){
		for(l=0;l<m;l++){
			if(array2[m]<array2[l]){
				int temp=array2[l];
				array2[l]=array2[m];
				array2[m]=temp;
			}
		}
	}
	printf("\n\nDistance of 1s in string to adjacent 1s(from small to large):");
	for(x=0;x<count3;x++){
		printf("\narray2=%d ",array2[x]);
	}
	
	        
	int sum=0,t;
	for(t=0;t<count3;t++){
		sum+=array2[t];
		swapp_--;
		if(swapp_==0){
			printf("\n\nThe minimum number of swaps required:%d",sum);
			break;
		}
		
	}			
	
		
	free(array);
	free(array2);
	
	return 0;
}

