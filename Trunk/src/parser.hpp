#pragma once

#include <string>
#include <list>
#include <vector>
#include <map>
class ConversationNode;

class Conversation{
private:
    std::map<std::string, ConversationNode* > nodes;
public:
    ConversationNode* entrypoints;
    std::string getVarValue(std::string varName);
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
