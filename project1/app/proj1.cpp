#include "proj1.hpp"
#include <iostream>
#include <limits>
#include <vector>

void tspHelper(const std::vector<std::vector<long>> & graph, std::vector<std::vector<long>>& memo, std::vector<std::vector<int>>& path, 
                           unsigned n, long maskedValue) {
    
        memo[0][1] = LONG_MAX;

    for(int i = 1; i < n; i++) {
        if(graph[i][0] != 0)
            memo[i][maskedValue] = graph[i][0];
    }

    // Trying out for all the possible mask values
    for(int i = maskedValue; i >= 1; i--) {
        for(int j = 1; j < n; j++) {
            if( ((i & (1 << j)) != 0))
                continue;

            int mask = i | (1 << j);
            for(int k = 1; k < n; k++) {
                if(graph[j][k] == 0 || (i & (1 << k)) != 0)
                    continue;

                int newMask = mask | (1 << k);
                long travelingCost = LONG_MAX;

                if (memo[k][newMask] == LONG_MAX)
                    travelingCost = LONG_MAX;
                else
                    travelingCost = memo[k][newMask] + graph[j][k];

                if(memo[j][mask] > travelingCost)
                {
                    memo[j][mask] = travelingCost;
                    path[j][mask] = k;
                }
            }
        }
    }

    int pathMask = 1;
    for(int city = 1;city < n; city++){
        pathMask = (1 | (1 << city));
        if(graph[0][city] != 0 && memo[city][pathMask] != LONG_MAX){
            if(memo[0][1] > memo[city][pathMask] + graph[0][city]) {
                memo[0][1] = memo[city][pathMask] + graph[0][city];
                path[0][1] = city;
            }
        }
    }
}

void findJourneyPath(int n, int startMask, std::vector<unsigned> &journey, std::vector<std::vector<int>> &path)
{
    int count = 1;
    int start = 0;
    while(count != n) {
        int city = path[start][startMask];
        journey.push_back(city);
        startMask = startMask | (1 << city);

        start = city;
        count++;
    }
    return;
}

std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n)
{
    std::vector<unsigned> journey;

    long maskedValue = 1 << n;
    maskedValue--;

    // This 2d vector stores the minimum travelingCost to traverse 
    std::vector<std::vector<long>> memo(n, std::vector<long>(maskedValue + 1, LONG_MAX));
    //This would be used to find out the journey vector 
    std::vector<std::vector<int>> path(n, std::vector<int>(maskedValue + 1, -1));

    tspHelper(graph, memo, path, n, maskedValue);
    
    journey.push_back(0); //We always start from city 0
    findJourneyPath(n, 1, journey, path);

    return journey;
}



// Returns the cost of the journey described here.
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
	long sum = 0;
    for(auto it = journey.begin(); it != journey.end()-1; it++){
        sum = sum + graph[*it][*(it+1)];
    }
    sum += graph[journey.back()][journey.front()];
    return sum;
}

