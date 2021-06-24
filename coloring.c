#include<stdio.h>
#include<string.h>

int a[10000][10000];
int m[10000];
int sm = 0;
char mau[6][10] = {"red", "green", "blue", "yellow", "black"};

//xoa bac cua dinh i
void del(int b[], int n, int i, int k){
	b[i] = k+n+1;
	for(int j = 0; j < n; j++){
		if(a[i][j] == 1){
			b[j] = b[j] - 1;
		}
	}
	return;
}

// to mau cho cac dinh
void xuly(int n, int v[]){
    int kt;
    for(int i = 0;i < n; i++){
        if(!m[v[i]]){
            sm++;
            m[v[i]] = sm;
            for(int j = i+1;j < n; j++){
                if((a[v[i]][v[j]] == 0) && (m[v[j]] == 0)){
                    kt = 1;
                    for(int k = i+1;k < j; k++){
                        if((a[v[k]][v[j]] == 1) && (m[v[i]] == m[v[k]])){
                            kt = 0;
                            break;
                        }
					}
                    if(kt == 1) m[v[j]] = sm;
                }
			}
        }
	}
}

int main(){
	int m0, n, i, j, t=0, t1, t2, k=0, x=0;
	
	FILE *in, *out;
	in = fopen("dothi.txt", "r");
	fscanf(in, "%d%d",&n, &m0);
	int b[n];
	
	// gan gia tri cho mang a
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			a[i][j] = 0;
		}
		b[i] = 0;
	}

	// lap ma tran ke
	for(i = 0; i < m0; i++){
		fscanf(in, "%d%d", &t1, &t2);
		a[t1-1][t2-1] = 1;
		a[t2-1][t1-1] = 1;
	}
	
	//Tim bac cua cac dinh
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			b[i] = b[i] + a[i][j];
		}
	}
	
	// tim bac max
	for(i = 0; i < n; i++){
		k = (k > b[i]) ? k : b[i];
	}
	
	int v[n];
	// gan tri tri cho mang v
	for(i = 0; i < n; i++){
		v[i] = 0;
	}
	
	// tim dinh goc la dinh co bac < k va lon nhat (F0)
	for(i = 0; i < n; i++){
		if(b[i] < k){
			v[n-1] = i;
			t = n-1;
			x = t-1;
			del(b, n, i, k);
			break;
		}
	}	
	
	// tim cac dinh lien ke voi dinh F0, F1, F2,...; xoa 
	while(x > -1){
		for(i = 0; i < n; i++){
			if((a[v[t]][i] == 1) && (b[i] < k)){
				v[x] = i;
				x--;
				del(b, n, i, k);
			}
		}
		t--;
	}
		
	xuly(n, v);
		
	out = fopen("dothitomau.dot", "w+");
	fprintf(out,"graph dothi\n{\n");
	for (i = 0; i < n; i++) {
		fprintf(out, " %d [fillcolor=%s, style=filled];\n", v[i]+1, mau[m[v[i]]-1]);
	}
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if(a[i][j] == 1) {
				fprintf(out, " %d -- %d;\n", i+1, j+1);
			}
		}
	}
	fprintf(out, "}\n");
	
	fclose(in);
	fclose(out);
	
	
	return 0;
}