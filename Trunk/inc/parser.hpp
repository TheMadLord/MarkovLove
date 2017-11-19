#pragma once

#include <string>
#include <list>
#include <vector>
#include <map>
class ConversationNode;

class Conversation{
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
    int mod;
    ConversationNode();
};
class ConversationHandler{
private:
    Conversation* convo;
    ConversationNode* top;
    ConversationNode* buttom;
public:
    ConversationHandler(Conversation* con);
    std::vector<std::string> getText(int i);
    std::vector<std::string> getStartText();
};

Conversation* parseFile(std::string FileName);
