#include "proj3.hpp"
#include <vector>
#include <queue> // std::priority_queue lives here. 
#include <iostream>

std::vector<unsigned> TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start)
{
	std::vector<unsigned> journey;
    std::vector<bool> visited(graph.size(), false);
    int n = graph.size();
    int currCity = start;
    journey.push_back(start);
    visited[start] = true;

    for(int i = 0 ; i < n; i++) {
        unsigned nn = getNearestNeighbor(graph, currCity, visited);
        if(nn == UINT_MAX) break;
        visited[nn] = true;
        journey.push_back(nn);
        currCity = nn;
    }

	return journey;
}

unsigned getNearestNeighbor(const std::vector<std::vector<unsigned>>& graph, unsigned start, const std::vector<bool>& visited) {
    int min_cost = INT_MAX;
    unsigned min_cost_index = UINT_MAX;
    for(unsigned i = 0; i < (unsigned)graph.size(); i++) {
        if(!visited[i] && graph[start][i] != 0) {
            if(min_cost > graph[start][i]) {
                min_cost = graph[start][i];
                min_cost_index = i;
            }
        }
    }
    return min_cost_index;
}

std::vector<unsigned> TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph)
{
	std::vector<unsigned> journey;
    std::vector<unsigned> degree(graph.size(), 0);
    std::vector<unsigned> outCity(graph.size(), UINT_MAX);
    unsigned n = graph.size();
    std::priority_queue<Edge> pq;

    // Creating and sorting edges using pq.
    for(unsigned i = 0 ; i < n; i++) {
        for(unsigned j = i + 1 ; j < n ; j++) {
            Edge e(i, j, graph[i][j]);
            pq.push(e);
        }
    }

    while(!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if(degree[e.pt1] >= 2 || degree[e.pt2] >= 2) continue;
        
        if(outCity[e.pt1] == UINT_MAX) {
            outCity[e.pt1] = e.pt2;
        } else {
            outCity[e.pt2] = e.pt1;
        }
        degree[e.pt1]++;
        degree[e.pt2]++;
    }

    int count = 0;
    unsigned start = 0;
    // make path
    while(count < n) {
        journey.push_back(start);
        count++;
        start = outCity[start];
    }

	return journey; 
}



std::vector< std::vector<unsigned> > orderCrossover(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
														unsigned pickStart, unsigned pickLen)
{
	std::vector< std::vector<unsigned> > children; // (2, std::vector<unsigned>());

	// I found it easier to start with the child of the right size
	// and use indexing to place the right elements.
	// Feel free to do something different.
	std::vector<unsigned> oneChild;	
	std::vector<unsigned> otherChild;

    std::unordered_set<unsigned> segment_1;
    std::unordered_set<unsigned> segment_2;
    unsigned pLen = pickLen;

    for(unsigned i = pickStart ; i < pickStart + pickLen; i++) {
        segment_1.insert(j1[i]);
        segment_2.insert(j2[i]);
    }

    // child 1
    unsigned j2_count = 0;
    unsigned j2_itr = pickStart;
    pLen = pickStart;

    while(j2_count < (unsigned)j2.size()) {
        if(pLen == 0) {
            for(unsigned i = pickStart; i < pickStart + pickLen; i++) {
                oneChild.push_back(j1[i]);
            }
            pLen = -1;
        }

        if(segment_1.find(j2[j2_itr]) == segment_1.end()) {
            oneChild.push_back(j2[j2_itr]);
            pLen--;
        }

        j2_itr = (j2_itr+1)%(j2.size());
        j2_count++;
    }

    unsigned j1_count = 0;
    unsigned j1_itr = pickStart;
    pLen = pickStart;
    //Child 1
    while(j1_count < (unsigned)j1.size()) {
        if(pLen == 0) {
            for(unsigned i = pickStart; i < pickStart + pickLen; i++) {
                otherChild.push_back(j2[i]);
            }
            pLen = -1;
        }

        if(segment_2.find(j1[j1_itr]) == segment_2.end()) {
            otherChild.push_back(j1[j1_itr]);
            pLen--;
        }

        j1_itr = (j1_itr+1)%(j1.size());
        j1_count++;
    }

	children.push_back( oneChild );
	children.push_back( otherChild );


	return children;
}



std::vector<unsigned> mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength)
{
	// This starts with result as a copy of the initial journey.
	// As always, feel free to start differently (as long as your result is correct)
	std::vector<unsigned> result(journey);

    std::reverse(result.begin() + mutateStart, result.begin() + mutateStart + mutateLength);

	return result; 
}



std::vector<unsigned> unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion)
{

	std::vector< unsigned> journey;
    std::vector<bool> visited(graph.size(), false);
    int n = graph.size();
    std::vector<std::vector<unsigned>> unionGraph(n, std::vector<unsigned>(n, 0));

    for(unsigned i = 0 ; i < (unsigned)j1.size() -1; i++) {
        unionGraph[j1[i]][j1[i+1]] = graph[j1[i]][j1[i+1]];
    }

    unionGraph[j1[j1.size() - 1]][j1[0]] = graph[j1[j1.size()-1]][j1[0]];

    for(unsigned i = 0 ; i < (unsigned)j2.size() -1; i++) {
        unionGraph[j2[i]][j2[i+1]] = graph[j2[i]][j2[i+1]];
    }

    unionGraph[j2[j2.size() - 1]][j2[0]] = graph[j2[j2.size()-1]][j2[0]];

    visited[start] = true;
    journey.push_back(start);
    for(unsigned i = 0 ; i < numFromUnion; i++) {
        unsigned nn = getNearestNeighbor(unionGraph, start, visited);
        if(nn == UINT_MAX) {
            nn = getNearestNeighbor(graph, start, visited);
        }

        journey.push_back(nn);
        visited[nn] = true;
        start = nn;
    }

    for(unsigned i = numFromUnion; i < n; i++) {
        unsigned nn = getNearestNeighbor(graph, start, visited);
        if(nn == UINT_MAX) break;
        journey.push_back(nn);
        start = nn;
        visited[nn] = true;
    }

	return journey; 
}
