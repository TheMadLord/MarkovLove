#pragma once
#include <map>
#include <string>


#define GIRL_MOOD_ANGRY 0
#define GIRL_MOOD_NEUTRAL 1
#define GIRL_MOOD_HAPPY 2
#define GIRL_MOOD_LOVE 3

#define GIRL_LOC_MISSING -1
#define GIRL_LOC_FORREST 0
#define GIRL_LOC_BAKERY 1
#define GIRL_LOC_LIBRARY 2

class Girl{
private:
    std::string name;
    int mood;
    int location;
public:
    Girl(std::string name);

    std::string getName();

    int getMood();

    void setMood(int mood);

    void modifyMood(int change);

    std::string fillVars(std::string line);

    void setLocation(int i){
        if(i >= GIRL_LOC_MISSING and i<= GIRL_LOC_LIBRARY){
            locaction = i;
        }
    }

    int getLocation(int i){
        return location;
    }

    void updateLocation(){
        location = rand()%3;
    }
};
