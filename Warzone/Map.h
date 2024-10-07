#pragma once
#include <vector>
#include <set>
#include <string>

using namespace std;

class Territory {

public:
    int territoryID;    //Territory ID
    string territoryName;   //Territory Name
    int continentID;    //Continent ID
    string continentName;   //Continent Name  
    string player; // Player Name
    int armies;     // Number of armies
    bool isAdjacent;  //Connected Continent Check

    vector<int> adjTerritoryOnMap;  //List of Adjacent Territories on entire map
    vector<int> adjTerritoriesInContinent;    //List of Adjacent Territories in same continent

    //Constructors
    Territory();
    Territory(int territoryId, string territoryName, int continentID,  string continentName);

    // Methods
    void displayBorders();

    //Getters
    int getTerritoryID();
    string getTerritoryName();
    int getContinentID();
    string getContinentName();   
    string getPlayer();
    int getArmies();
    bool getAdjContinent();

    int getBelongedContinentID();    
   
    vector<int> getAdjTerritoryOnMap(); 
    vector<int> getAdjTerritoryInContinent();

    //Setters
    void setTerritoryID(int territoryID);
    void setTerritoryName(string territoryName);
    void setAdjContinent(bool canLeave);
    void setPlayer(string name);
    
};

class Continent {
public:
    int continentID;    
    int bonus;
    string continentName;   //Continent Name
    vector<Territory*> territoriesInContinent; //List of Territories in Continent
    set<int> connectedContinents;    //Adjacent Continent

    //Constructors
    Continent();
    Continent(string continentName, int continentID, int bonus);

    // Methods
    bool isConnected();

    //Getters
    int getContinentID();
    int getBonus();
    string getContinentName();
    vector<Territory*> getTerritoriesInContinent();
    set<int> getConnectedContinent();
    
};

class Map {
public:
    string mapName;   //Map Name

    int territories;   //Number of all Territories
    int continents;   //Number of all Continents
    
    vector<Territory*> territoriesList; //Territories Vector
    vector<Continent*> continentsList;  //Continents Vector
    

    //Constructors
    Map();
    Map(string mapName, int continents, int territories);

    // Mehotds
    void displayTerritories();
    void displayContinents();
    void dfs(int i, vector<bool>& visited, int leng);
    bool validate();
    bool belong_Onecontinent();
    bool continentMatched(int continentID);

    //Getters
    string getMapName();
    int getContinents();
    int getTerritories();
    int getCountryIndex(int ID);
    vector<Territory*> getTerritoriesList();
    vector<Continent*> getContinentsList();
    void dfs(int i, set <bool>& visited);

    //Setters
    void setMapName(string mapName);

    

   
};

class MapLoader {

public:
    Map accessMap;
    string mapFile;
    MapLoader();
    string getMapFile();
    void setMapFile(const string& mapFile);
    vector<string> parseString(const string& s);
    void readMap();
};

//Global Functions
ostream& operator << (ostream& out, const Continent& c);
ostream& operator << (ostream& out, const Territory& t);
vector<int> parseStringToInt(const string& s);


//Global Variables
//static Map worldMap;