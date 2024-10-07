#include "Map.h"
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

//Territory Implementation
Territory::Territory()
{
    territoryID = 0;
    territoryName = "Unknown_Territory";
    continentID = 0;
    continentName = "Unknown_Continent";
    armies = 0;
    isAdjacent = false;
    player =  string("Unknown_Player");
}
Territory::Territory(int territoryID, string territoryName ,int continentID, string continentName)
{
    this->territoryID = territoryID;
    this->territoryName = territoryName;
    this->continentID = continentID;
    this->continentName = continentName;    
    this->armies = 0;
    this->isAdjacent = false;
    player =  string("Unknown_Player");
}

//Getters
int Territory::getTerritoryID() 
{ 
   return territoryID; 
}

string Territory::getTerritoryName()
{
    return territoryName;
}

int Territory::getContinentID() 
{ 
   return continentID; 
}

string Territory::getContinentName()
{
    return continentName;
}

string Territory::getPlayer()
{
   return player;
}

int Territory::getArmies() 
{ 
   return armies; 
}

bool Territory::getAdjContinent()
{
    return isAdjacent;
}

vector<int> Territory::getAdjTerritoryOnMap()
{
    return adjTerritoryOnMap;
}

vector<int> Territory::getAdjTerritoryInContinent()
{
    return adjTerritoriesInContinent;
}

int Territory::getBelongedContinentID()
{
    return Territory::isAdjacent;
}

//Setters
void Territory::setTerritoryID(int territoryID)
{
    this->territoryID = territoryID;
}
void Territory::setTerritoryName(string territoryName)
{
    this->territoryName = territoryName;
}
void Territory::setAdjContinent(bool canLeave)
{
    isAdjacent = canLeave;
}


void Territory::setPlayer(string name)
{
    this->player = name;
}

void Territory::displayBorders()
{
    cout << "\nAdjacent to " << getTerritoryName() << " -> " << endl;
    for (auto i : adjTerritoryOnMap)
    {
        cout << adjTerritoryOnMap[i] << " ";
    }
}

//Continent Implementation
Continent::Continent()
{
    continentName = "";
    continentID = 0;
    bonus = 0;
}
Continent::Continent(string continentName, int continentID, int bonus)
{
    this->continentName = continentName;
    this->continentID = continentID;
    this->bonus = bonus;
}

//Check if territories in Continent are connected
bool Continent::isConnected()
{
    int length = this->territoriesInContinent.size(); //# of territories in one continent
    vector<int> visited;                            //Vector of territories that have been visited
    for (int i = 0; i < length; i++) {                      //Loop through all territories in one continent
        if (visited.empty()) {                        //Visit first territory node
            visited.push_back(this->territoriesInContinent[i]->getTerritoryID());
        }

        int length1 = territoriesInContinent[i]->adjTerritoriesInContinent.size();    //Get adjacent territories list length
        for (int j = 0; j < length1; j++) {                                                 //Loop adjacent territories      
            int temp = this->territoriesInContinent[i]->adjTerritoriesInContinent[j];   //Get adjacent territory ID
            int length2 = visited.size();                                             //Length of visited territories
            for (int k = 0; k < length2; k++) {                                             //Loop visited territories
                if (temp == visited[k]) {   //If adjacent territory has already been visited, dont add to visited list
                    break;
                }
                if (k == (length2 - 1)) {     //If adjacent territory has not been visited, add to visited list
                    if (temp != visited[k]) {
                        visited.push_back(temp);
                    }
                }
            }
        }
    }
    if (visited.size() != length) {         //Check if # of territories in continent = # of visited territories
        return false;
    }
    return true;                        //Graph is connected if all territories have been visited
}

//Getters
string Continent::getContinentName()
{
    return continentName;
}

int Continent::getContinentID()
{
    return continentID;
}

int Continent::getBonus(){
    return bonus;
}

vector<Territory*> Continent::getTerritoriesInContinent()
{
    return territoriesInContinent;
}

set<int> Continent::getConnectedContinent()
{
    return connectedContinents;
}



//Map Implementation
Map::Map()
{
    mapName = "Unknown_Map";
    continents = 0;
    territories = 0;
}
Map::Map(string mapName, int continents, int territories)
{
    this->mapName = mapName;
    this->continents = continents;
    this->territories = territories;
}

//Getters
string Map::getMapName()
{
    return mapName;
}

int Map::getContinents()

{
    return continents;
}

int Map::getTerritories()
{
    return territories;
}

vector<Territory*> Map::getTerritoriesList()
{
    return territoriesList;
}

vector<Continent*> Map::getContinentsList()
{
    return continentsList;
}

// Methods
void Map::displayTerritories()
{
    cout << "TERRITORIES: \n\n";
    for (auto i : territoriesList)
        cout << i->getContinentID() << " -> " << i->getTerritoryID() << " -> " << i->getTerritoryName() << endl;
}

void Map::displayContinents()
{
    cout << "CONTINENTS: \n\n";
    for (auto i : continentsList)
        cout << *i << "\n\n";
}

//Validate() method: Check if all continents in map are connected
//Map is valid if all continents are connected
bool Map::validate()
{
    int length = continentsList.size();
    set<int> visitedContinents;         //Set of Visited Continents
    set<int>::const_iterator iterator;   //Iterator to iterate over map and modify territories
    vector<bool> visited(length);

    //Check if Continents are connected
    for (int i = 0; i < length; i++) {
        if (continentsList[i]->isConnected()) {
            cout << "Map Continent " << continentsList[i]->getContinentName() << " is connected." << endl;
        }
        else {
            cout << "MAP IS INVALID - Map Continent " << continentsList[i]->getContinentName() << " is not connected." << endl;
            break;
        }
    }


    return true;
}
int Map::getCountryIndex(int ID) {
    int length = continentsList.size();
    int index = -1;
    for (int x = 0; x < length; x++) {
        Territory temp = *(this->territoriesList.at(x));
        if (temp.getContinentID() == ID) {
            index = x;
            break;
        }
    }
    return index;
}
void Map::dfs(int i, vector <bool>& visited, int leng) {
    visited[i] = true;
    for (int x = 1; x < leng; x++) {

        Territory temp = *(territoriesList.at(x));

        int tempID = temp.getContinentID();
        int index = 0;
        if ((visited[index] != true)) {

            dfs(index, visited, leng);
        }
        else {
            continue;
        }
    }
}
bool Map::belong_Onecontinent() {
    bool belongTo = true;
    int length = this->continentsList.size();
    for (int x = 0; x < length; x++) {
        Territory temp = *(territoriesList.at(x));
        int tempID = temp.getBelongedContinentID();

        belongTo = belongTo && continentMatched(tempID);
    }
    return belongTo;
}

bool Map::continentMatched(int continentID) {
    bool matched = false;
    int length = this->continentsList.size();
    if (continentID < 0) {
        return matched;
    }

    for (int x = 0; x < length; x++) {
        Continent temp = *(continentsList.at(x));
        int tempID = temp.getContinentID();
        matched = matched || (continentID == tempID);
    }
    return matched;
}

//Setters
void Map::setMapName(string mapName)
{
    this->mapName = mapName;
}



//Map Loader Implementation
MapLoader::MapLoader() {
    mapFile = "";
    accessMap = Map();
}
string MapLoader::getMapFile() {
    return mapFile;
}
void MapLoader::setMapFile(const string& mapFile) {
    this->mapFile += mapFile;
}
vector<string> MapLoader::parseString(const string& s) {
    vector<string> tokens;  //Vector of tokens parsed
    stringstream check(s);
    string temp;

    while (getline(check, temp, ' ')) {
        tokens.push_back(temp);
    }
    return tokens;
}
void MapLoader::readMap() {
    int cNum = 0;
    int tNum = 0;
    int adjRow = 0;
    string text;
    regex rx("; map:.");
    smatch mr;

    cout << getMapFile() << endl;
    ifstream file(getMapFile());
    getline(file, text);

    if (regex_search(text, mr, rx)) {
        cout << "Map Name is valid\n\n";
    }
    else {
        cout << "Wrong Map Format! Closing Program...";
        exit(0);
    }

    while (getline(file, text))    //Read file line by line
    {
        if (text == "[continents]")
        {
            while (getline(file, text))
            {
                if (text == "")
                    break;
                vector<string> tokens = parseString(text);
                Continent* c = new Continent(tokens[0], ++cNum, stoi(tokens[1]));
                MapLoader::accessMap.continentsList.push_back(c);
            }
            //for (auto i : worldMap.continents)
            //    cout << *i << endl;
        }

        if (text == "[countries]")
        {
            while (getline(file, text))
            {
                tNum++;
                if (text == "")
                    break;
                vector<string> tokens = parseString(text);
                int cID = stoi(tokens[2]);
                Territory* t = new Territory(stoi(tokens[0]), tokens[1], cID,  "");
                MapLoader::accessMap.continentsList[cID - 1]->territoriesInContinent.push_back(t);
                MapLoader::accessMap.territoriesList.push_back(t);
                
            };
        }

        if (text == "[borders]")
        {
            while (getline(file, text))
            {
                if (text == "")
                    break;
                vector<int> line = parseStringToInt(text);
                //worldMap.adjTerritoriesInContinent.push_back(parseStringToInt(text));
                for (auto i : line)
                {
                    MapLoader::accessMap.territoriesList[adjRow]->adjTerritoryOnMap.push_back(i);

                    int currentContinent = MapLoader::accessMap.territoriesList[adjRow]->getContinentID();
                    if (MapLoader::accessMap.territoriesList[i - 1]->getContinentID() == currentContinent)
                        MapLoader::accessMap.territoriesList[adjRow]->adjTerritoriesInContinent.push_back(i);
                }
                
                adjRow++;
            }

        }
    }
    file.close();
}

//Global Functions
ostream& operator << (ostream& out, const Continent& c) {
    out << c.continentName << " - CID:" << c.continentID;
    for (auto i : c.territoriesInContinent)
        out << "\n" << *i;
    return out;
}

ostream& operator << (ostream& out, const Territory& t) {
    out << t.territoryName << ":  ID:" << t.territoryID << ", Continent ID:" << t.continentID << ",  Armies: " << t.armies << endl;
    return out;
}

vector<int> parseStringToInt(const string& s) {
    vector<int> tokens;  //Vector of tokens parsed
    stringstream check(s);
    string temp;

    while (getline(check, temp, ' ')) {
        tokens.push_back(stoi(temp));
    }
    return tokens;
}




