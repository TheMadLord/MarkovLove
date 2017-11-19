#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "parser.hpp"

std::string stripLineEnd(std::string line){
    std::string ret = line;
    int i = line.length()-1;
    while(line[i] == '\r' ||line[i] == '\t' ||line[i] == '\n' || line[i] == ' '){
        ret = ret.substr(0,i);
        i--;
    }
    return ret;
}

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
            line = stripLineEnd(line);
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
    ConversationNode* END = new ConversationNode();
    END->name = "END";
    END->mod =  0;
    END->text = "END";
    END->branchs = {"END","END"};
    END->Probalities = {50.0f,50.0f};

    ConversationNode* START = new ConversationNode();
    START->name = "START_OVER";
    START->mod =  0;
    START->text = "<START OVER>";
    START->branchs = {"START_OVER","START_OVER"};
    START->Probalities = {50.0f,50.0f};

    ConversationNode* WIN = new ConversationNode();
    WIN->name = "WIN";
    WIN->mod =  0;
    WIN->text = "WIN";
    WIN->branchs = {"WIN","WIN"};
    WIN->Probalities = {50.0f,50.0f};

    nodes.emplace("END",END);
    nodes.emplace("START_OVER",START);
    nodes.emplace("WIN",WIN);
}


ConversationHandler::ConversationHandler(Conversation* con){
    this->convo = con;
}

std::vector<std::string> ConversationHandler::getStartText(){
    std::vector<std::string> ret;
    ret.push_back("");
    srand(time(NULL));
    int i = rand() % convo->entrypoints.size();
    int j;
    do {
        j = rand() % convo->entrypoints.size(); // UPON "FIXING" i, REACHES HERE ONCE THEN CRASHES
    } while(j == i);
    ret.push_back((top = convo->entrypoints.at(i))->text);
    ret.push_back((buttom = convo->entrypoints.at(j))->text);
    return ret;
}

std::vector<std::string> ConversationHandler::getText(int i){
    ConversationNode* root = (i == 0)? top:buttom;
    std::vector<std::string> ret;
    if(convo->getNode(root->branchs[0])->name== "START_OVER"){
            ret = getStartText();
            return ret;
    }
    float r = (rand() % 100)/100.0f;
    float t = 0;
    std::cout <<  "GOT NEW  LINES=)\n";
    for(int ii = 0; ii < root->Probalities.size(); ++t){
        if(r < t+root->Probalities.at(ii)){
            root = this->convo->getNode(root->branchs.at(ii));
            break;
        }else{
            t += root->Probalities.at(ii);
        }
    }
    ret.push_back(root->text);
    i = rand() % root->branchs.size();
    printf("%d\n", root->branchs.size());
    std::string ts = root->branchs.at(i);
    std::cout << "Line 1:<" + ts +">\n\n";

    ret.push_back((top = convo->getNode(ts))->text);



    if(root->branchs.size() == 1){
        ret.push_back("");
        if(top->name == "START_OVER"){
            ret = getStartText();
            ret[0] = root->text;
            return ret;
        }
    }else{
        int j;
        do{
            j = rand() % root->branchs.size();
        }while(j == i);
        ts = root->branchs.at(j);
        std::cout << "Line 2: " + ts +"\n\n";
        ret.push_back((buttom = this->convo->getNode(ts))->text);
    }
    return ret;
}
ConversationNode* Conversation::getNode(std::string name){

    for(std::map<std::string,ConversationNode*>::iterator it = nodes.begin(); it != nodes.end(); ++it){
       // std::cout << it->first + " : " + it->second->text + "\n";
    }
        ConversationNode*  ret = this->nodes.at(name);
        return ret;

}


