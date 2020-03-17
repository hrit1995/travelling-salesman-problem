#include "proj2.hpp"
#include <queue> // This is where std::priority_queue lives.
#include <stack> // you may want std::stack for your depth-first traversal.
/*
void generategraph() {
    int n = 1000;

    srand(time(NULL));

    std::cout<<"{"<<std::endl;
    for(int i = 0 ; i < n; i++) {
        std::cout<<"{ ";
        for(int j = 0 ; j < n; j++) {
            if(i == j) {
                std::cout<<0<<",";
            } else {
                if(j != n-1)
                    std::cout<<rand()%n<<",";
                else
                    std::cout<<rand()%n;
            }
        }
        if(i != n-1)
            std::cout<<"},"<<std::endl;
        else
            std::cout<<"}"<<std::endl;
    }
    std::cout<<"};"<<std::endl;
    return;
}
*/

std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{

//    generategraph();
	std::vector<Edge> mst;
    std::priority_queue<Edge> pq;
    for(int i = 0 ; i < graph.size(); i++) {
        if(graph[0][i] != 0) {
            Edge e(0, i, graph[0][i]);
            pq.push(e);
        }
    }

    std::vector<unsigned> visited(graph.size(), false);
    visited[0] = true;

    /* prim's algorithm for mst */
    while(!pq.empty()) {
        Edge t = pq.top();
        pq.pop();
        unsigned u = t.pt1;
        unsigned v = t.pt2;
        unsigned wt = t.weight;

        if(visited[v]) continue;

        visited[v] = true;

        Edge newEdge(u, v, wt);
        mst.push_back(newEdge);

        for(int i = 0; i < graph.size() ; i++) {
            if(graph[v][i] != 0 && !visited[i]) {
                Edge e(v, i, graph[v][i]);
                pq.push(e);
            }
        }
        
    }
	return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.
unsigned mstCost(const std::vector<Edge> & vE) 
{
	unsigned sum =0;
	for(auto e: vE)
	{
		sum += e.weight;
	}
	return sum;
}

unsigned costOfJourney(const std::vector<std::vector<unsigned>> & graph, const std::vector<unsigned> & journey)
{
    unsigned cost  = 0;
    for(auto it = journey.begin() ; it != journey.end()-1 ; it++) {
        cost += graph[*it][*(it+1)];
    }

    cost += graph[journey.back()][journey.front()];
    return cost;
}

unsigned waste(const std::vector<Edge> & tree, const std::vector<unsigned> & journey, const std::vector<std::vector<unsigned>> & graph)
{
	return costOfJourney(graph, journey) - mstCost(tree);
}


std::vector<unsigned> computeTSPJourney(const std::vector< Edge > & mst, unsigned start)
{
    std::vector<std::list<unsigned>> mstAdjList(1001);
    std::vector<unsigned> journey;

    // Vreating the graph adj list from mst */
    for(int i = 0 ; i < mst.size(); i++) {
        mstAdjList[mst[i].pt1].push_back(mst[i].pt2);
    }

    std::stack<unsigned> stk;
    stk.push(start);
    // Doing an iterative preorder traversla of the graph
    while(!stk.empty()) {
        unsigned i = stk.top();
        journey.push_back(i);
        stk.pop();

        for(auto itr = mstAdjList[i].begin() ; itr != mstAdjList[i].end(); itr++) {
            stk.push(*itr);
        }
    }

   return journey;
}
