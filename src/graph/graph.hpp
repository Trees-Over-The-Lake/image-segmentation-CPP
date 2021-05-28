#ifndef graph_hpp
#define graph_hpp

#define EMPTY -1

#define WHITE  0
#define YELLOW 1
#define RED    2

#include <vector>
#include <stdint.h>

using weight  = int;
using counter = uint16_t;

class Graph {

    private: 

        //Attributes

        // Store the number of vertices in the graph
        counter vertices;

        // Store the number of edges in the graph
        counter edges;

        // A list of vertex and their adjacent vertexes
        std::vector<std::vector<counter>> adj;

        // A list of edges and their respective weights
        std::vector<std::pair<weight,std::pair<counter,counter>>> edges_weights;

        //*************************************************************************//

        //Private Functions:

        // Checks if the graph matrix have space, if does not, expand the matrix
        bool has_space();
        // Add a 'last' vertex to be adj to 'first'

        void add_adj(counter first,counter last);
        // Visit a specific vertex and verify the color of the adjs
        //This is a function only used in depth first search

        //Verify if a certain vertex exists
        bool has_vertex(counter id);

    public:

        //Constructors

        // Start the Graph with three empty vertices
        Graph();

        // Start the Graph with 'vertices' number of vertices
        Graph(counter vertices = 3);

        //*************************************************************************//
        //Getters

        // get number of vertices of the graph
        counter vertices_num();  

        // get number of edges of the graph
        counter edges_num();

        // get the adjs of a vertex by its index

        std::vector<counter> get_adjs(counter id);

        //*************************************************************************//
        //Basic graph operations
        
        /** Add a new Edge, by giving the coordenates of the first and last vertex
         *  (Obs: There is also the option of adding a weight to the 
         *  Edge, but if not specified, the 'weight' will be *EMPTY* )
         */ 
        bool add_edge(counter first, counter last, weight weight = EMPTY);

        // Add a new Vertex to the graph and return if it is successful 
        counter add_vertex();

        // Print all data about the graph
        virtual void print();  
};      

#endif