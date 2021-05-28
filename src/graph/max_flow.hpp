
#define WHITE  0
#define YELLOW 1
#define RED    2

#include<stdint.h>
#include<vector>
#include"graph.hpp"

    /** Make a Depth First Search in the Graph and 
     * count all of the cycles inside of such Graph
     * 
     *  Significance of the colours:
     * 
     *  WHITE: Not explored
     *  YELLOW: Visited, but there's still adjacents to visit 
     *  RED: Visited, along with the adjacents
     */
    static bool depth_first_search(Graph g,counter first);

    //Visit a vertex
    static void visit_vertex (Graph g, counter index, std::vector<counter>* colour);

    static bool depth_first_search(Graph g,counter first) {
        std::vector<counter> colour;

        //Mark all vertices as : "NOT VISITED"
        for(int i = 0; i < g.vertices_num(); i++)
            colour.push_back(WHITE);

        //Loop through all vertices in the graph
        for(counter i = 0; i < g.vertices_num(); i++) 

            //if the curr vertex hasn't been visited
            if(colour.at(i) == WHITE) 

                //visiting current vertex
                //Obs: I'm sending a pointer to the 
                //memory address of the 'colour' std::vector
                //so that all recursive calls to 'visit_vertex'
                //can update when a vertex is visited
                visit_vertex(g, i,&colour);

        return true;
    }

    static void visit_vertex (Graph g, counter index, std::vector<counter>* colour) {
        //Mark current vertex as visited
        colour->at(index) = YELLOW;

        //Start adj std::vector
        std::vector<counter> curr_vertex_adj = g.get_adjs(index); 

        //Loop through adj std::vector of the curr_vertex
        for(int i = 0 ; i < curr_vertex_adj.size(); i++) 

            //if adj vertex hasn't been visited
            if(colour->at(curr_vertex_adj.at(i)) == WHITE)

                //recursive call to 'visit_vertex'
                visit_vertex(g,curr_vertex_adj.at(i),colour);
        
        //Mark vertex as completed
        colour->at(index) = RED;
    }