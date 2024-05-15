#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace ariel{
    class Graph{
        private:
            //A 2D Vector representing an adjacency matrix.
            std::vector<std::vector<int>> adjacencyMatrix;
        public:
            //A function for loading a 2D vector into the adjacency matrix.
            void loadGraph(const std::vector<std::vector<int>> &g);

            //A function for printing the number of vertecies and edges in the graph.
            void printStats() const;

            //A function that returns the adjacency matrix.
            std::vector<std::vector<int>> getAdjacencyMatrix() const;

            std::string printGraph() const;

            Graph& operator+(const Graph other);

            
    };
    


    std::ostream& operator<<(std::ostream& os, const Graph& obj);

    
};
