#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> costMatrix;
vector<pair<int, pair<int,int>>> edges;  
vector<int> parent;

int findParent(int v){
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v]);
}

void unionSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a != b) parent[b] = a;
}

int main(){
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int n;
        cin >> n;

        costMatrix.assign(n, vector<int>(n));
        edges.clear();
        parent.resize(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> costMatrix[i][j];
                if(j < n-1){
                    char comma;
                    cin >> comma;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(costMatrix[i][j] > 0){
                    edges.push_back({ costMatrix[i][j], {i, j} });
                }
            }
        }

        sort(edges.begin(), edges.end());

        for(int i = 0; i < n; i++)
            parent[i] = i;

        vector<pair<int, pair<int,int>>> mst;

        for(auto &e : edges){
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if(findParent(u) != findParent(v)){
                mst.push_back(e);
                unionSet(u, v);
            }
        }

        cout << "Case " << t << ":\n";
        for(auto &e : mst) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            char a = 'A' + u;
            char b = 'A' + v;

            cout << a << "-" << b << " " << w << "\n";
        }
    }
    return 0;
}