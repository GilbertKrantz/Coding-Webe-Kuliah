#include<stdio.h>
#include<cstring>
int main(){
	int T,N,V, box1 = -1000001, box2 = -1000001, box1index, count = 0;
	int array[100000], array3[100000];
	int dupe = -1;
	
	scanf("%d", &T);
	
	for(int i=0;i < T;i++){
		dupe = -1;
		box1 = -1000001;
		box2 = -1000001;
		scanf("%d", &N);
		for(int j=0;j < N;j++){
			scanf("%d", &V);
			if(V >= box1){
				box1 = V;
				box1index = j;
			}
			
			array[j] = V;
			
			
		}
		
		
		for(int j=0; j<N; j++){
			if((array[j] != array[box1index] )){
				if(array[j] >= box2){
				box2 = array[j];
				}
				
			}
			else{
				dupe++;
			}
		
			
		}
		
		if(dupe >= 1){
			box2 = array[box1index];
		}
		
		

		array3[count] = box1 + box2;
		count++;
		
	}
	
	
	for(int x=0; x<count; x++){
		
	
	printf("Case #%d: %d\n", x+1 ,array3[x]);
}
	
	
}
