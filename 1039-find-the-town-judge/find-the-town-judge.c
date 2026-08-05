struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int vertices;
    struct Node** adjlist;
};
struct Node* createNode(int x) {
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}
struct Graph* createGraph(int v) {
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices=v;
    graph->adjlist=(struct Node**)malloc((v+1)*sizeof(struct Node*));

    for(int i=0; i<v+1; i++) {
        graph->adjlist[i]=NULL;
    }
    return graph;
}

void addedge(struct Graph* graph, int u, int v) {
    struct Node* dest=createNode(v);
    dest->next=graph->adjlist[u];
    graph->adjlist[u]=dest;
}
int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    struct Graph* graph=createGraph(n);
    for(int i=0; i<trustSize; i++) {
        addedge(graph, trust[i][0], trust[i][1]);
    }
    for(int i=1; i<=n; i++) {
        struct Node* mover=graph->adjlist[i];
        if(mover==NULL) {
            int j;
            int trustedbyall=1;
            for(j=1; j<=n; j++) {
                if(j==i) continue;
                struct Node* a=graph->adjlist[j];
                int found=0;
                while(a) {
                    if(a->data==i) {
                        found=1;
                        break;
                    }
                    a=a->next;
                }
                if(!found) {
                    trustedbyall=0;
                    break;
                }

            }
            if(trustedbyall) return i;

        }
    }
    return -1;
}