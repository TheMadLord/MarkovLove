#include "girl.hpp"

Girl::Girl(std::string  name){
    this->name = name;
}

std::string Girl::getName(){
    return this->name;
}

int Girl::getMood(){
    return this->mood;
}

void Girl::modifyMood(int change){
    this->mood += change;
    if(mood < GIRL_MOOD_ANGRY){
        mood = GIRL_MOOD_ANGRY;
    }
    if(mood > GIRL_MOOD_LOVE){
        mood = GIRL_MOOD_LOVE;
    }
}

void Girl::setMood(int mood){
    this->mood = mood;
    if(mood < GIRL_MOOD_ANGRY){
        mood = GIRL_MOOD_ANGRY;
    }
    if(mood > GIRL_MOOD_LOVE){
        mood = GIRL_MOOD_LOVE;
    }
}


std::string Girl::fillVars(std::string line){
            std::string outString = line;
            std::string var = "name";
            std::string value = this->name;
            int i = 0;
            while((i = outString.find("+" + var, i)) < outString.size()){
                outString = outString.substr(0,i) +  (value)+  (outString.substr(i + var.size()+1));
            }
    return outString;
}
