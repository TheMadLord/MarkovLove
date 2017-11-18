#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "parser.hpp"

Conversation parseFile(std::string FileName){
 	std::string line;
  	std::ifstream myfile (FileName);
 	std::map<std::string, ConversationNode> lines;
 	std::list<ConversationNode> entries;
 	if (myfile.is_open()){
   		while ( getline (myfile,line) ){
            if(line[0] != '\n'){
                switch(line[0]){
                    case ('Y'):
                        break;
                    case ('G'):
                        break;
                    case ('E'):
                        break;
                    case ('V'):
                        break;
                }
            }
        }
 		myfile.close();
  	}else{
		 std::cout << "Unable to open file";
	}
}

