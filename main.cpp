#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include<time.h>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main(void)
{
    clock_t tStart = clock();//time library used 
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cout<<"Enter the no of nodes and then edges\n";
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cout<<"Enter the value of x and y and then the node weight\n";
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout <<  "The minimum cost of this tree is "<<  minimumCost << endl;
    cout<<"Time taken: %.2fs\n"<< (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;//time library used 
return 0;
    return 0;
}
