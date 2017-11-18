#include <string>

class ConversationNode;

class Conversation{
private:
//std::map Vars;
public:
    ConversationNode* entrypoints;
    std::string getVarValue(std::string varName);
    Conversation();
};

class ConversationNode{
public:
    std::string text;
    ConversationNode* branchs;
    float* Probalities;
    ConversationNode();

};

Conversation parseFile(std::string FileName);
