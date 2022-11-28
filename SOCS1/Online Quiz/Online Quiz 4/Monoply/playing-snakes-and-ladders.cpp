#include <stdio.h>

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	int k[n];
	int res = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &k[i]);
		res += k[i];
		if(res == 9){
			res = 21;
		}
		
		else if(res == 33){
			res = 42;
		}
		
		else if(res == 76){
			res = 92;
		}
		
		else if(res == 53){
			res = 37;
		}
		
		else if(res == 80){
			res = 59;
		}
		
		else if(res == 97){
			res = 88;
		}
	}
	
	printf("%d\n", res);
}
