#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "parser.hpp"

ConversationNode* parseELine(std::string line, std::map<std::string, std::string>* vars){
    ConversationNode* ret = new ConversationNode();
    //get starting points for each field
    int nameStart = 0;
    int moodStart = line.find("|");
    int textStart = line.find(" ", moodStart);
    int branchsStart = line.find("|",textStart);
    int probStart =  line.find("|",branchsStart+1);
    //get each field
    ret->name = line.substr(0,moodStart);
    ret->mood = line.substr(moodStart+1,textStart-moodStart-1);
    ret->text = line.substr(textStart+1, branchsStart-textStart-1);
    std::string branchs = line.substr(branchsStart+1, probStart-branchsStart-1);
    std::string probs = line.substr(probStart+1);
    //parse branchs
    int i = 0;
    while((i = branchs.find(",", i)) < branchs.size()){
        ret->branchs.push_back(branchs.substr(0,i));
        branchs = branchs.substr(i+1);
    }
    ret->branchs.push_back(branchs);
    i = 0;
    while((i = probs.find(",", i)) < probs.size()){
        ret->Probalities.push_back(std::stoi (probs.substr(0,i))/100.0f);
        probs = probs.substr(i+1);
    }
    ret->Probalities.push_back(std::stoi(probs)/100.0f);
    return ret;
}

ConversationNode* parseGLine(std::string line, std::map<std::string, std::string>* vars){
    ConversationNode* ret = new ConversationNode();
    //get starting points for each field
    int nameStart = 0;
    int textStart = line.find("|",nameStart);
    int branchsStart = line.find("|",textStart+1);
    //get each field
    ret->name = line.substr(0,textStart);
    ret->text = line.substr(textStart+1, branchsStart-textStart-1);
    std::string branchs = line.substr(branchsStart+1);
    //parse branchs
    int i = 0;
    while((i = branchs.find(",", i)) < branchs.size()){
        ret->branchs.push_back(branchs.substr(0,i));
        branchs = branchs.substr(i+1);
    }
    ret->branchs.push_back(branchs);
    return ret;
}


ConversationNode* parseYLine(std::string line, std::map<std::string, std::string>* vars){
    ConversationNode* ret = new ConversationNode();
    //get starting points for each field
    int nameStart = 0;
    int textStart = line.find("|",nameStart);
    int branchsStart = line.find("|",textStart+1);
    int probStart =  line.find("|",branchsStart+1);
    //get each field
    ret->name = line.substr(0,textStart);
    ret->text = line.substr(textStart+1, branchsStart-textStart-1);
    std::string branchs = line.substr(branchsStart+1, probStart-branchsStart-1);
    std::string probs = line.substr(probStart+1);
    //parse branchs
    int i = 0;
    while((i = branchs.find(",", i)) < branchs.size()){
        ret->branchs.push_back(branchs.substr(0,i));
        branchs = branchs.substr(i+1);
    }
    ret->branchs.push_back(branchs);
    i = 0;
    while((i = probs.find(",", i)) < probs.size()){
        ret->Probalities.push_back(std::stoi (probs.substr(0,i))/100.0f);
        probs = probs.substr(i+1);
    }
    ret->Probalities.push_back(std::stoi(probs)/100.0f);
    if(line.find("EMOTION_DOWN") != -1){
        ret->mod = -1;
    }else if(line.find("EMOTION_UP") != -1) {
        ret->mod = 1;
    }else{
        ret->mod = 0;
    }
    return ret;
}

void parseVLine(std::string line, std::map<std::string, std::string>* vars){
    int p1 = line.find("|");
    int p2 = line.find("|", p1+1);
    std::string name =  line.substr(p1+1,p2-p1-1);
    std::string value = line.substr(p2+1);
    if(value[value.size() - 1] == '\r'){
        value = value.substr(0,value.size() - 1);
    }
    vars->emplace(name, value);
}

std::string fillVars(std::string line, std::map<std::string, std::string> *vars){
    for(std::map<std::string,std::string>::iterator it = vars->begin(); it != vars->end(); ++it){
            std::string outString = "";
            std::string var = it->first;
            std::string value = it->second;
            int i = 0;
            while((i = line.find("+" + var, i)) < line.size()){
                outString = line.substr(0,i) +  (value)+  (line.substr(i + var.size()+1));
                line = outString;
            }
    }
    return line;
}

Conversation* parseFile(std::string FileName){
  	std::ifstream myfile (FileName);
 	std::string line;
	ConversationNode* cur;
    std::map<std::string, std::string> vars;
	Conversation* ret = new Conversation();
 	if (myfile.is_open()){
   		while ( getline (myfile,line) ){
            line = fillVars(line,&vars);
            switch(line[0]){
                case ('Y'):
                    cur = parseYLine(line, &vars);
                    ret->nodes.emplace(cur->name,cur);
                    break;
                case ('G'):
                    cur = parseGLine(line, &vars);
                    ret->nodes.emplace(cur->name,cur);
                    break;
                case ('E'):
                    ret->entrypoints.push_back(cur = parseELine(line, &vars));
                    ret->nodes.emplace(cur->name,cur);
                    break;
                case ('V'):
                    parseVLine(line, &vars);
                    break;
            }
        }
 		myfile.close();
  	}else{
		 std::cout << "Unable to open file";
	}
	return ret;
}

ConversationNode::ConversationNode(){

}
Conversation::Conversation(){
}

