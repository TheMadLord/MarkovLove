


markov_chain{

};

markov_chain(std::vector<node> n);

~markov_chain() {}

edge();

~edge() {}

node();

~node() {}

node* markov_chain::getNode(int value){
}

node* markov_chain::getNode(std::string name){

}

std::vector<node> node::getReachableNodes(node){

}

std::vector<node> markov_chain::getNodes() { return &nodes; }

int node::getValue() { return &value; }

int node::getNumEdges() { return &num_edges; }

std::string node::getName() { return &name; }

node edge::getOutgoingNode() { return &outgoingNode; }

node edge::getIncomingNode() { return &incomingNode; }

int edge::getWeight() { return &weight; }
