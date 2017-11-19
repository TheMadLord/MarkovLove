
class markov_chain {
public:
    markov_chain();
    markov_chain(std::vector<node> n);
    markov_chain(std::vector<node> n, std::vector<edge> e);
    ~markov_chain();
    std::vector<node> getNodes();
    node* getNode(int value);
    node* getNode(std::string name);
protected:
    std::vector<node> nodes;
    std::vector<edge> edges;
};

class node {
public:
    int getValue();
    int getNumEdges();
    std::string getName();
    std::vector<node> getReachableNodes(node n);
protected:
    int value;
    int num_edges;
    std::string name; // ?
    std::vector<edge> outgoing_edges;

};

class edge {
public:
    node getOutgoingNode();
    node getIncomingNode();
    int getWeight();
protected:
    int weight;
    node outgoingNode;
    node incomingNode;
};
