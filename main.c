#include "Mylib.h"

void graphviz(cgraph_t g, char* file){
	int i,j;
	FILE* ptr=fopen(file,"w");
	if(g->directed) fprintf(ptr,"digraph dothi\n{\n");
	else fprintf(ptr,"graph dothi\n{\n");
	for(i=0;i<g->n;++i){
		fprintf(ptr,"%d [fillcolor=white, style=filled];\n",i);
	}
	for(i=0,j=cgraph_ivec_size(g->from);i<j;++i){
		if(g->directed) fprintf(ptr,"%d -> %d;\n",g->from[i],g->to[i]);
		else fprintf(ptr,"%d -- %d;\n",g->from[i],g->to[i]);
	}
	fprintf(ptr,"}");
	fclose(ptr);
}

int main(){
	int i,x,y,Vsize,Esize,direct;
	double w;
	cgraph_ivec_t edges=cgraph_ivec_create();
	cgraph_rvec_t weights=cgraph_rvec_create();
	char file[100];
	printf("Nhap file: ");
	scanf("%s",file);
	FILE *ptr=fopen(file,"r");
	if(ptr==NULL){
		printf("cant open %s\n",file);
		return -1;
	}
	fscanf(ptr,"%d %d %d",&Vsize,&Esize,&direct);
	for(i=0;i<Esize;++i){
		fscanf(ptr,"\n%d %d %lf",&x,&y,&w);
		cgraph_ivec_push_back(&edges,x);
		cgraph_ivec_push_back(&edges,y);
		cgraph_rvec_push_back(&weights,w);
	}
	fclose(ptr);
	cgraph_t g=cgraph_create(edges,Vsize,direct);

	graphviz(g,"../Product/Graph.dot");	

	for(;;){
		printf("Menu\n1. Prufer code\n2. So thanh phan lien thong\n3. Tim thanh phan lien thong cua mot dinh\n4. Dijkstra\n5. Topo\n6. Kiem tra DAG\n7. Kruscal\n8. Prim\n9. Thoat\nLua chon cua ban: ");
		scanf("%d",&i);
		switch(i){
			case 1:{
				cgraph_ivec_t prufer=cgraph_ivec_create();
				if(cgraph_to_prufer(g,&prufer)) cgraph_ivec_print(prufer);
				else printf("Do thi khong co prufer code\n");
				cgraph_ivec_free(&prufer);
				break;
			}
			case 2:{
				printf("So thanh phan lien thong la: %d\n", tplt_count(g) );
				break;
			}
			case 3:{
				printf("Nhap dinh: ");
				scanf("%d",&x);
				cgraph_ivec_t tplt=cgraph_ivec_create();
				if(tplt_find(g,x,&tplt)) cgraph_ivec_print(tplt);
				else printf("Khong tim thay thanh phan lien thong cua dinh\n");
				cgraph_ivec_free(&tplt);
				break;
			}
			case 4:{
				printf("Nhap dinh xuat phat: ");
				scanf("%d",&x);
				if(x<0||x>=g->n){
					printf("Khong ton tai dinh vua nhap\n");
					break;
				}
				printf("Nhap dinh dich: ");
				scanf("%d",&y);
				if(y<0||y>=g->n){
					printf("Khong ton tai dinh vua nhap\n");
					break;
				}
				cgraph_ivec_t vpath = cgraph_ivec_create(),
			               	  epath = cgraph_ivec_create();
			 	if(cgraph_get_shortest_path_dijkstra(g, &vpath, &epath, x, y, weights, CGRAPH_ALL)!=-1){
	 				int sum;
	 				for(i=0,sum =0;i<cgraph_ivec_size(epath);++i){
	 					sum+=weights[epath[i]];
	 				}
	 				printf("Do dai duong di: %d\nDanh sach dinh: ",sum );
	 				for(i=0;i<cgraph_ivec_size(vpath);++i){
	 					printf("%d ",vpath[i]);
	 				}
	 			}
	 			else printf("Khong tim thay duong di");
 				printf("\n" );
 				cgraph_ivec_free(&vpath);
 				cgraph_ivec_free(&epath);
				
				break;
			}
			case 5:{
				cgraph_ivec_t topo=cgraph_ivec_create();
				cgraph_topological_sorting(g, &topo, CGRAPH_OUT);
                printf("Topo: ");
                for(i = 0; i < cgraph_ivec_size(topo); ++i){
                    printf("%d -> ", topo[i]);
                }
                printf("\n");
                cgraph_ivec_free(&topo);
                break;
			}
			case 6:{
				if(cgraph_is_dag(g)) printf("Do thi la mot DAG\n");
				else printf("Do thi khong phai la mot DAG\n");
				break;
			}
			case 7:{
				cgraph_ivec_t kruskal=cgraph_ivec_create();
				if(cgraph_kruskal( g, weights,&kruskal)){
					double sum=0;
					for(i=0;i<cgraph_ivec_size(kruskal);++i){
						printf("%d %d %-.1lf\n",g->from[kruskal[i]],g->to[kruskal[i]],weights[kruskal[i]] );
						sum+=weights[kruskal[i]];
					}
					printf("Tong trong so cay bao trum nho nhat: %-.1lf\n",sum );
				}
				else printf("Khong the tao kruskal code\n");
				cgraph_ivec_free(&kruskal);
				break;
			}
			case 8:{
				cgraph_ivec_t prim=cgraph_ivec_create();
				if(cgraph_prim( g, weights,&prim)){
					double sum=0;
					for(i=0;i<cgraph_ivec_size(prim);++i){
						printf("%d %d %-.1lf\n",g->from[prim[i]],g->to[prim[i]],weights[prim[i]] );
						sum+=weights[prim[i]];
					}
					printf("Tong trong so cay bao trum nho nhat: %-.1lf\n",sum );
				}
				else printf("Khong the tao prim code\n");
				cgraph_ivec_free(&prim);
				break;
			}
			case 9:{
				cgraph_ivec_free(&edges);
				cgraph_rvec_free(&weights);
				cgraph_destroy(&g);
				return 0;
				break;
			}
		}
	}

	
}