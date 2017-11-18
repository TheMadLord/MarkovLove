#pragma once

#include <string>
#include <list>
#include <vector>
#include <map>
class ConversationNode;

class Conversation{
private:
public:

    std::map<std::string, ConversationNode* > nodes;
    std::vector<ConversationNode*> entrypoints;
    ConversationNode* getNode(std::string name);
    Conversation();
};

class ConversationNode{
public:
    std::string text;
    std::string name;
    std::string mood;
    std::vector<std::string> branchs;
    std::vector<float> Probalities;
    ConversationNode();

};

Conversation* parseFile(std::string FileName);
