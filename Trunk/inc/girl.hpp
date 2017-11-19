#pragma once
#include <map>
#include <string>


#define GIRL_MOOD_ANGRY 0
#define GIRL_MOOD_NEUTRAL 1
#define GIRL_MOOD_HAPPY 2
#define GIRL_MOOD_LOVE 3

class Girl{
private:
    std::string name;
    int mood;
public:
    Girl(std::string name);

    std::string getName();

    int getMood();

    void setMood(int mood);

    void modifyMood(int change);

    std::string fillVars(std::string line);
};
