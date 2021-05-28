#include "graph.hpp"

#include<iostream>
#include<fstream>
#include <array> 
#include<bits/stdc++.h>
/*
* Implementing the graph class
*  v0.1
*/

    // Start the graph with the 'min' size of Matrix
    Graph::Graph() {

        this->vertices = 0;
        this->edges    = 0;
    }

    // Start the graph matrix with a set size
    Graph::Graph(counter v) {
        
        this->edges    = 0;
        this->vertices = 0;

        for(int i =0 ; i < v; i++) 
            add_vertex();
    }

    //Return the number of vertices the graph has
    counter Graph::vertices_num() {
        return this->vertices;
    }

    //Return the number of edges the graph has
    counter Graph::edges_num() {
        return this->edges;
    }

    std::vector<counter> Graph::get_adjs(counter id) {
        return this->adj.at(id);
    }

    counter Graph::add_vertex() {
        counter result = -1;
        counter pos    = this->vertices;

       //std::cout<< "[Graph]: Ok! Inserting on matriz..." << std::endl;

        result = this->vertices;
        this->vertices++;

       // std::cout<< "[Graph]: Inserting in adj list..." << std::endl;

        std::vector<counter> it;
        this->adj.push_back(it);
        
       // std::cout<< "[Graph]: Adding vertex process is finished with success!" << std::endl;

        return result;
    }

    // Add a new Edge to the graph and return if the operation was a success
    bool Graph::add_edge(counter first, counter last, weight value) {
        bool result = false;

        if(has_vertex(first) && has_vertex(last)) {
            this->edges++;

            auto edges_pair        = std::make_pair(first,last);
            auto weight_edges_pair = std::make_pair(value,edges_pair);

            this->edges_weights.push_back(weight_edges_pair);
            add_adj(first, last);
            result = true;
        }

        return result;
    }

    bool Graph::has_vertex(counter id){
        bool result = false;

        if(id < this->adj.size()) 
            result = true;

        return result;
    }

    void Graph::add_adj(counter first, counter last) {
        auto it = &this->adj.at(first);
        it->push_back(last);
    }

    void Graph::print() {

        std::cout << "Number of vertices: " << this->vertices << std::endl;
        std::cout << "Number of edges   : " << this->edges << std::endl; 

        std::cout << "\nLists of Adjs:\n"; 

        for(int i = 0; i < adj.size(); i++) {
            std::cout << "v[" << i << "] :"; 
            for(auto j = this->adj.at(i).begin(); j != this->adj.at(i).end() ;++j) {
                std::cout << ' ' << *j; 
            }
            std::cout << '\n'; 
        } 

        std::cout << "\nLists of edges:\n"; 

        for(auto i = edges_weights.begin(); i != edges_weights.end(); i++) 
            std::cout<< "edges: " << i->second.first << "," << i->second.second << "\t weight: " << i->first << std::endl;
        

    }
