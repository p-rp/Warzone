#include "PlayerStrategy.h"
#include "Map.h"

// PlayerStrategy Class

PlayerStrategy::PlayerStrategy(){}

PlayerStrategy::PlayerStrategy(const PlayerStrategy& ps)
{
    this->player = ps.player;
}

PlayerStrategy::~PlayerStrategy() {}

PlayerStrategy& PlayerStrategy::operator=(const PlayerStrategy& playerStrategy) {
    this->player = playerStrategy.player;
    return *this;
}

ostream& operator<<(std::ostream& out, const PlayerStrategy& playerStrategy) {
    out << "Player Strategy" << endl;
    out << "Player: " << *playerStrategy.player << endl;
    return out;
}

void PlayerStrategy::setPlayer(Player* player) {
    this->player = player;
}

 
HumanPlayerStrategy::HumanPlayerStrategy()  {}

HumanPlayerStrategy::HumanPlayerStrategy(const HumanPlayerStrategy& hps) : PlayerStrategy(hps) {}

HumanPlayerStrategy::~HumanPlayerStrategy() {}

HumanPlayerStrategy& HumanPlayerStrategy::operator=(const HumanPlayerStrategy& hps) {
    player = hps.player;
    return *this;
}


void  HumanPlayerStrategy::issueOrder() {}

vector<int> HumanPlayerStrategy::toAttack() {
    vector<int> attackList = vector<int>();
    /*vector<int> defendList = this->toDefend();
    vector<int> adjList = vector<int>();

    for (int i = 0; i < defendList.size(); i++) {
        
        for (int j = 0; j < defendList.size(); j++)
        {
           
       }
    }*/

    return attackList;
}

vector<int> HumanPlayerStrategy::toDefend()
{
         
    vector<int> defendList = vector<int>();
    for (int i = 0; i < player->getTerritoriesCollection().size(); i++)
    {
        int x = player->getTerritoriesCollection()[i]->getTerritoryID();
        defendList.push_back(x);
    }

    return defendList;
}

AggressivePlayerStrategy::AggressivePlayerStrategy()
{

}

AggressivePlayerStrategy::AggressivePlayerStrategy(const AggressivePlayerStrategy&)
{
}

AggressivePlayerStrategy::~AggressivePlayerStrategy()
{
}

AggressivePlayerStrategy& AggressivePlayerStrategy::operator=(const AggressivePlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    this->player = playerStrategy.player;
    return *this;
}

void AggressivePlayerStrategy::issueOrder()
{
}

vector<int> AggressivePlayerStrategy::toAttack()
{
    return vector<int>();
}

vector<int> AggressivePlayerStrategy::toDefend()
{
    return vector<int>();
}

BenevolentPlayerStrategy::BenevolentPlayerStrategy()
{
}

BenevolentPlayerStrategy::BenevolentPlayerStrategy(const BenevolentPlayerStrategy&)
{
}

BenevolentPlayerStrategy::~BenevolentPlayerStrategy()
{
}

BenevolentPlayerStrategy& BenevolentPlayerStrategy::operator=(const BenevolentPlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    this->player = playerStrategy.player;
    return *this;
}

void BenevolentPlayerStrategy::issueOrder()
{
}

vector<int> BenevolentPlayerStrategy::toAttack()
{
    return vector<int>();
}

vector<int> BenevolentPlayerStrategy::toDefend()
{
    return vector<int>();
}

NeutralPlayerStrategy::NeutralPlayerStrategy()
{
}

NeutralPlayerStrategy::NeutralPlayerStrategy(const NeutralPlayerStrategy&)
{
}

NeutralPlayerStrategy::~NeutralPlayerStrategy()
{
}

NeutralPlayerStrategy& NeutralPlayerStrategy::operator=(const NeutralPlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    this->player = playerStrategy.player;
    return *this;
}

void NeutralPlayerStrategy::issueOrder()
{
}

vector<int> NeutralPlayerStrategy::toAttack()
{
    return vector<int>();
}

vector<int> NeutralPlayerStrategy::toDefend()
{
    return vector<int>();
}

CheaterPlayerStrategy::CheaterPlayerStrategy()
{
}

CheaterPlayerStrategy::CheaterPlayerStrategy(const CheaterPlayerStrategy&)
{
}

CheaterPlayerStrategy::~CheaterPlayerStrategy()
{
}

CheaterPlayerStrategy& CheaterPlayerStrategy::operator=(const CheaterPlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    this->player = playerStrategy.player;
    return *this;
}

void CheaterPlayerStrategy::issueOrder()
{
}

vector<int> CheaterPlayerStrategy::toAttack()
{
    return vector<int>();
}

vector<int> CheaterPlayerStrategy::toDefend()
{
    return vector<int>();
}

ostream& operator<<(std::ostream& out, const HumanPlayerStrategy& hps) {
    out << "Human Player Strategy" << endl;
    out << "Player: " << hps.player << endl;
    return out;
}

ostream& operator<<(ostream& out, const AggressivePlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    out << "Aggressive Player Strategy" << endl;
    out << "Player: " << playerStrategy.player << endl;
    return out;
}

ostream& operator<<(ostream& out, const BenevolentPlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    out << "Benevolent Player Strategy" << endl;
    out << "Player: " << playerStrategy.player << endl;
    return out;
}

ostream& operator<<(ostream& out, const NeutralPlayerStrategy& playerStrategy)
{
    // TODO: insert return statement here
    out << "Neutral Player Strategy" << endl;
    out << "Player: " << playerStrategy.player << endl;
    return out;
}

ostream& operator<<(ostream& out, const CheaterPlayerStrategy& playerStrategy)
{
    // TODO: Cheater return statement here
    out << "Aggressive Player Strategy" << endl;
    out << "Player: " << playerStrategy.player << endl;
    return out;
}