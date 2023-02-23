#include <stdio.h>

typedef struct {
    int X;
    int Y;
} data;

int searchCoor(data coor[], int size) {
    for (int i = 0; i < 100; i++)
    {
        
    }
    
}

int main() {
    int T; // Test Case
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        int N;
        scanf("%d", &N);

        N = (4 * N) - 1;

        int maxX, maxY, minX, minY;
        data coor[N];

        for (int j = 0; j < N; j++)
        {
            scanf("%d %d", &coor[j].X, &coor[j].Y);            
            
            getchar();
        }
        
    }
    
}