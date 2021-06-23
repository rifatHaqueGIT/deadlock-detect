
#include "deadlock_detector.h"
#include "common.h"
//I GOT IT TO RUN under 10 seconds on i7-7700K CPU @ 4.20GHz with test7.txt
//fastGraph has containers suggested by the hints in a4 provided by Pavol Federl
class FastGraph {
     public:
    std::vector<std::vector<int>> adj_list;//The list of nodes where each vector is the adjacent nodes of a node.(A node is determined by its index)
    std::vector<int> out_counts;//Count of out going links from each node.(A node is determined by its index)
    std::unordered_map< int,std::string> nameTracker;// Keeps track of the node's name for a specified index
    };


/// this is the function you need to (re)implement
///
/// parameter edges[] contains a list of request- and assignment- edges
///   example of a request edge, process "p1" resource "r1"
///     "p1 -> r1"
///   example of an assignment edge, process "XYz" resource "XYz"
///     "XYz <- XYz"
///
/// You need to process edges[] one edge at a time, and run a deadlock
/// detection after each edge. As soon as you detect a deadlock, your function
/// needs to stop processing edges and return an instance of Result structure
/// with edge_index set to the index that caused the deadlock, and dl_procs set
/// to contain with names of processes that are in the deadlock.
///
/// To indicate no deadlock was detected after processing all edges, you must
/// return Result with edge_index = -1 and empty dl_procs[].
///
Result detect_deadlock(const std::vector<std::string> & edges)
{
    FastGraph graph;//Fast Graph Object
    // std::unordered_map< int,std::string> nameTracker;
    Word2Int w;//Making a Word2Int Object
    Result result;// Initializing the Result Struct
    result.dl_procs.clear(); // clearing the dl_procs. If this comes out empty then we know there were no deadlocks
    result.edge_index = -1; // Set as -1.If this comes out as -1 then we know there were no deadlocks
    std::vector<std::string> edge;// used to hold a parsed edge 
    std::vector<int> out;// used to copy over the out_count from graph. Used for algorithm
   long unsigned int node =0; // this number will hold the edge index that has the deadlock
   // used for algorithm
   for(const auto &  g :  edges){
      edge = split(g);//Split and simplify the 
        //Index for the 3 elements will always be 0,1,2 for (P) ->/<- (R). Where (P)-0, ->/<- -1, (R) - 2
        int p = w.get("P_" +edge[0]);// getting the int for a specified process
        int r = w.get("R_" +edge[2]);// getting the int for a specified resource

        graph.nameTracker[p] = "P_" + edge[0];//adding it to the tracker
        graph.nameTracker[r] = "R_" +edge[2];

        graph.adj_list.resize(graph.nameTracker.size());//resize to take in more elements
        graph.out_counts.resize(graph.nameTracker.size());

        if(edge[1].compare("->") == 0) // This will be always at index 1, and 
            graph.out_counts[p]++; // Increment out count for Process
        
        else if(edge[1].compare("<-") == 0)// This will be always at index 1
            graph.out_counts[r]++;// Increment out count for Resource
                
        
        //Putting both process and resource as adjacents
        graph.adj_list[p].push_back(r);
        graph.adj_list[r].push_back(p);
            
// The section below uses the pseudo code from the hint provided by Pavol Federl in a4
    out = graph.out_counts;//copy out counts
    std::vector<int> zeros;
   for(size_t i = 0 ; i<out.size();i++){//assign zeros to zeros vector
        if(out.at(i) == 0){
            zeros.push_back(i);
        }
    }

    while(!zeros.empty()){//run while zeros has values
        int n = zeros.back(); // assignning last value in zeros 
        zeros.pop_back(); // remove said value
        for(auto & n2 : graph.adj_list[n]){//run through the adjacency vector of the specified node
            if(--out[n2] == 0)// if any of them are zero add them to zeros
                zeros.push_back(n2);
    } 
    }

    for( size_t i = 0 ; i<out.size();i++){// run through our zeros vector
        if(out[i]>0 && graph.nameTracker[i].compare(0,2,"R_") != 0){// if the count is greater then 1 and its a process add it to dl_procs
            result.dl_procs.push_back(graph.nameTracker[i].erase(0,2)); // removes the "P_" that was prepended
        }
    }
    // Section over

    if(!result.dl_procs.empty()){ // if result does have characters then break
        result.edge_index = node;//the node that detected deadlock
        break;
    }
    node++;// after b/c first node is zero ,and if current node isnt a deadlock increment.
    }//end of big for loop
    return result;
}
