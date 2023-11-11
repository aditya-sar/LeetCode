class Graph {
public:
    vector<vector<int>> a;
    int n;
    int MAX = 500000000;

    Graph(int n, vector<vector<int>>& edges) {
        this -> n = n;
        a = vector<vector<int>>(n, vector<int>(n, MAX));
        for(int i=0; i<n; i++) {
            a[i][i] = 0;
        }
        for(vector<int> &v : edges) {
            a[v[0]][v[1]] = v[2];
        }
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        if(a[edge[0]][edge[1]] <= edge[2]) {
            return;
        }
        a[edge[0]][edge[1]] = edge[2];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                a[i][j] = min(
                    a[i][j], a[i][edge[0]] + edge[2] + a[edge[1]][j]
                );
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if(a[node1][node2] == MAX) {
            return -1;
        }
        return a[node1][node2];
    }
};
