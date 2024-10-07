#include "Player.h"
#include <list>
using namespace std;

// Constructor
Player::Player()
{
	this->name = "Player";
	this->territoriesCollection = vector<Territory*>();
	this->hand = new Hand();
	this->ordersList = new OrdersList();
}


// Destructor
Player::~Player()
{
	
	delete hand;
	hand = NULL;
	delete ordersList;
	ordersList = NULL;
	delete &territoriesCollection;
}

// Copy Constructor
Player::Player(const Player& player)
{
	this->name = string(player.name);
	this->territoriesCollection = *new vector<Territory*>(player.territoriesCollection);
	this->hand = new Hand(*player.hand);
	this->ordersList = new OrdersList(*player.ordersList);
}


// Parameter Constructor
Player::Player(string name, vector<Territory*> territoriesCollection, Hand* hand, OrdersList* ordersList)
{
	this->name = name;
	this->territoriesCollection = territoriesCollection;
	this->hand = hand;
	this->ordersList = ordersList;
}


// Assignment Operator
Player& Player::operator = (const Player& player)
{
	this->name = player.name;
	this->territoriesCollection = player.territoriesCollection;
	this->hand = player.hand;
	this->ordersList = player.ordersList;
	return *this;
}

// Stream Insertion Operator
ostream& operator<<(ostream& out, const Player& player)
{
	out << "Player: " << player.name << endl;
	out << "Territories Collection: " << endl;
	for (int i = 0; i < player.territoriesCollection.size(); i++) {
		out << player.territoriesCollection[i]<< endl;
	}
	out << "Hand: " << player.hand << endl;
	out << "Orders List: " << player.ordersList << endl;
	out << endl;

	return out;
}

vector<int> Player::toDefend()
{
	return this->ps->toDefend();
}


vector<int> Player::toAttack()
{

	return this->ps->toAttack();
}


void Player::issueOrder()
{
	Orders *order = new Orders();
	this->ordersList->listOfOrders.push_back(*order);
}


// Getters
string Player::getName()
{
	return name;
}
vector<Territory*> Player::getTerritoriesCollection()
{
	return territoriesCollection;
}
Hand* Player::getHand()
{
	return hand;
}
OrdersList* Player::getOrdersList()
{
	return ordersList;
}

//Setters
void Player::setName(string newName)
{
	name = newName;
}
void Player::setTerritoriesCollection(vector <Territory*> newTerritoriesCollection)
{
	territoriesCollection = newTerritoriesCollection;
}
void Player::setHand(Hand* newHand)
{
	hand = newHand;
}
void Player::setOrdersList(OrdersList* newOrdersList)
{
	ordersList = newOrdersList;
}
void Player::setPlayerStrategy(PlayerStrategy* newPlayerStrategy)
{
	ps = newPlayerStrategy;
}

