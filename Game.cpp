#include "Game.h"
#include <sstream>
#include <cstring>
#include <string>
// -------------------- Object class ----------------------



Object::Object(){

}

Object::Object(string name, int value) {
	// IMPLEMENT ME


  if (value < 0) {
        throw std::invalid_argument("Negative value detected");
    }

	
 this->name = name;
    this->value = value;
    this->owner_ = nullptr;
	
}

Object::~Object() {

	delete [] owner_;
}

string Object::getName() const {
	// IMPLEMENT ME

	return name; // dummy
}

int Object::getValue() const {
	// IMPLEMENT ME


	return 0; // dummy
}

string Object::getType() {
  return type;
}

string Object::print() const {
	// IMPLEMENT ME
int values = getValue();
    return ", name: " + getName() + ", value: " + std::to_string(values);
}


void Object::use() {
	// IMPLEMENT ME

}

std::ostream& operator<<(std::ostream& os, const Object& o) {
	// IMPLEMENT ME
return os << o.print();
}

// ------------------- Food class ----------------------



Food::Food(string name, int value) : Object(name, value) {}


Food::~Food() {}



string Food::getName() const {
	// IMPLEMENT ME

	  return Object::getName();// dummy
}

int Food::getValue() const {
	// IMPLEMENT ME


	 return Object::getValue(); // dummy
}



string Food::print() const {
	// IMPLEMENT ME
int values = getValue();
    return "Food, name: " + getName() + ", value: " + std::to_string(values);
}



void Food::use(Player& player) {
	// IMPLEMENT ME

}

std::ostream& operator<<(std::ostream& os, const Food& o) {
	// IMPLEMENT ME
  return os << o.print();

}



// ------------------- Weapon class ----------------------

Weapon::Weapon(string name, int value) : Object(name, value) {}


Weapon::~Weapon() {}


string Weapon::getName() const {
	// IMPLEMENT ME

 return Object::getName();// dummy
}



int Weapon::getValue() const {
	// IMPLEMENT ME


	return Object::getValue(); // dummy
}



string Weapon::print() const {
	// IMPLEMENT ME
int values = getValue();
    return "Weapon, name: " + getName() + ", value: " + std::to_string(values);
}



void Weapon::use() {
	// IMPLEMENT ME

}

std::ostream& operator<<(std::ostream& os, const Weapon& o) {
	// IMPLEMENT ME
return os << o.print();
	
}





// ------------------- Armour class ----------------------

Armour::Armour(string name, int value) : Object(name, value) {}

Armour::~Armour() {}



string Armour::getName() const {
	// IMPLEMENT ME

	 return Object::getName(); // dummy
}

int Armour::getValue() const {
	// IMPLEMENT ME


	return Object::getValue(); // dummy
}



string Armour::print() const {
	// IMPLEMENT ME
int values = getValue();
    return "Armour, name: " + getName() + ", value: " + std::to_string(values);
}



std::ostream& operator<<(std::ostream& os, const Armour& o) {
	// IMPLEMENT ME

	 return os << o.print();
}



// ------------------- Player class ----------------------

Player::Player() {} // REMOVE ME

Player::Player(string name) {
	// IMPLEMENT ME
 this->name_ = name;
  this->health_ = 100;
  this->type_;
  this->stamina_ = 100;
  this->armor_ = 0;
  this->weapon_ = nullptr;
  this->gold_ = 0;
  this->inventory_ = new std::vector<Object*>();
   
}

Player::~Player() {

	 delete [] weapon_;
  delete inventory_;
}

string Player::getName() const {
	// IMPLEMENT ME

 return name_; // dummy
}

int Player::getHealth() const {
	// IMPLEMENT ME

	return health_; // dummy
}

int Player::getStamina() const {
	// IMPLEMENT ME

	  return stamina_; // dummy
}




void Player::pickup(std::unique_ptr<Object> o) {
	// IMPLEMENT ME
 if (health_ <= 0) {
    throw std::logic_error("Player is dead");
  }
  o->setOwner(this);
  inventory_->push_back(o.release());
}




void Player::addObjectToInventory(Object* o) {
  o->setOwner(this);
  inventory_->push_back(o);
}

string Player::getInventory() const {
	// IMPLEMENT ME

  std::stringstream ss;
  ss << "List of items: " << name_ << ": " << std::endl;
  for (const auto& o : *inventory_) {
    ss << o->getName() << std::endl;
  }
  return ss.str();
}

string Player::print() const {
	// IMPLEMENT ME

std::stringstream ss;
  ss << "Name: " << name_ << std::endl;
  ss << "Type: " << type_ << std::endl;
  ss << "Health: " << health_ << std::endl;
  ss << "Stamina: " << stamina_ << std::endl;
  ss << "List of items:" << std::endl;
  for (const auto& o : *inventory_) {
    ss << " " << o->print() << std::endl;
  }
  if (weapon_) {
    ss << "Weapon in use: " << weapon_->getName() << std::endl;
  } else {
    ss << "Weapon in use: none" << std::endl;
  }
  if (armor_) {
    ss << "Armour in use: " << armor_->getName() << std::endl;
  } else {
    ss << "Armour in use: none" << std::endl;
  }
  return ss.str();
}

bool Player::use(string name) {

if (health_ <= 0) {
throw std::logic_error("Cannot use items when dead");
}

for (int i = 0; i < inventory_->size(); i++) {
if (inventory_->at(i)->getName() == name) {
// Call the use() function of the object in inventory
inventory_->at(i)->use();
return true;
}
}

// If the object is not found in the inventory, return false
return false;
}



std::ostream& operator<<(std::ostream& os, const Player& p) {
	// IMPLEMENT ME
os << p.print();
	return os;
}

// ------------------- Fighter class ----------------------

Fighter::Fighter(string name) : Player(name) {
  typez_ = "Fighter";
}

Fighter::~Fighter() {}

bool Fighter::attack(Player& other) {
  if (healthbar_ <= 0 || other.healthbar_ <= 0) {
    throw std::logic_error("Stop! " + other.namez_ + " is already dead.");
  }

  if (staminabar_ < 10) {
    return false;
  }

  staminabar_ -= 10;

  int attackStrength = 10 + (weapons_ ? weapons_->getValue() : 0);
  int defendStrength = 0;
  for (const auto& o : other.inventorys_) {
    if (o->getType() == "Armour") {
      defendStrength += o->getValue();
    }
  }

  if (attackStrength > defendStrength) {
    other.healthbar_ -= attackStrength - defendStrength;
    return true;
  }

  return false;
}
// ------------------- Healer class ----------------------

Healer::Healer(string name) {
	// IMPLEMENT ME

}

Healer::~Healer() {}

bool Healer::heal(Player& other) {
	// IMPLEMENT ME

	return false; // dummy
}
