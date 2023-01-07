#include<stdio.h>
#include<string.h>

int main(){
	
	int i,z,c,y,j,l,k;
	char a[100];
	char m,h;
	
	FILE *f;
	f =fopen("testdata.in","r");
	
	fscanf(f,"%d", &z);fgetc(f);
	
	for(l = 0; l <= z-1; l++){
		
		fscanf(f,"%[^\n]", &a);fgetc(f);
		
		fscanf(f,"%d", &y);fgetc(f);	
		
		k = strlen(a);
		int alphcount[26]={0},textcount[26]={0};
		
		for(j = 0; j<= y-1;j++){
			fscanf(f,"%c %c", &m,&h);
			fgetc(f);
			
				for(i = 0; i < k;i++){
					if(m == a[i] && textcount[m-'A']== 0){
						a[i] = h;
					}
				}
				textcount[m-'A'] = 1;
			}
			for(i = 0; i < k;i++){
				alphcount[a[i]-'A'] += 1;
			}
			for(i = 0; i< 26;i++){
				if(alphcount[i] != 0){
					printf("%c %d\n", i+'A',alphcount[i]);
				}
			}
					
	}
}
