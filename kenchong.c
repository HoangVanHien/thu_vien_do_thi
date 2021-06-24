/*lan luot m chang trai di tim co gai cua minh,
 moi lan 1 chang trai tim duoc 1 co gai cua minh, 
 neu 1 chang trai thay the vi tri 1 chang trai khac,
chang trai kia phai tim hon the khac
*/

//#include <stdio.h>


// Input: prefer[i][j] la ten co gai ma chang trai i thich thu j trong danh sach
//		  rank[i][j] la thu tu cua chang trai j trong so thich cua co gai i
// Output: fiancee[i] la ten hon phu cua co gai i


/*int* kenchong(int** prefer, int** rank, int n){
	int i, j;
	int next[n];	//next[i] la thu tu co gai thich nhat chua tu choi chang trai i
	//int fiancee[n];	//hon phu
	for (i = 1; i <= n; i++){
		next[i] = 0;
		rank[i][0] = n+1;	// chang trai 0(linh canh) nam cuoi danh sach cua cac co gai
		fiancee[i] = 0;		// khoi tao hon phu cua cac co gai la chang trai 0
	}
	int m, s, w, t;
	for(m = 1; m <= n; m++){
		s = m;
		do {//tim hon the cho chang tra/i s, neu thanh cong thi doi cho s va fiancee[w]
			next[s] += 1;
			w = prefer[s][next[s]];
			if (rank[w][s] < rank[w][fiancee[w]]) {
				t = fiancee[w];
				fiancee[w] = s;
				s = t;
			}
		}while(s = 0);
	}
	return (int*)fiancee;
}*/

#include <stdio.h>

int main(){
	FILE * in = fopen("kc.txt","r");
	
	int n;
	fscanf(in, "%d", &n);
	
	int prefer[n][n], rank[n][n];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fscanf(in, "%d", &prefer[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fscanf(in, "%d", &rank[i][j]);
		}
	}	
	
	int i, j;
	int next[n];	//next[i] la thu tu co gai thich nhat chua tu choi chang trai i
	int fiancee[n];	//hon phu
	for (i = 1; i <= n; i++){
		next[i] = 0;
		rank[i][0] = n+1;	// chang trai 0(linh canh) nam cuoi danh sach cua cac co gai
		fiancee[i] = 0;		// khoi tao hon phu cua cac co gai la chang trai 0
	}
	int m, s, w, tg;
	for(m = 1; m <= n; m++){
		s = m;
		do {//tim hon the cho chang tra/i s, neu thanh cong thi doi cho s va fiancee[w]
			next[s] += 1;
			w = prefer[s][next[s]];
			//printf("%d\t%d\n", fiancee[w], s);
			if (rank[w][s] < rank[w][fiancee[w]]) {
				tg = fiancee[w];
				fiancee[w] = s;
				s = tg;
			}
			//printf("%d\n", fiancee[w]);
		}while(s = 0);
	}
	
	return 0;
}