/*
 * FactoryMeyhod.cpp
 *
 *  Created on: Jan 7, 2020
 *      Author: mehmetcey
 */

#include <iostream>

class Room{
};

class SimpleRoom : public Room{
public:
	SimpleRoom(){
		std::cout << "SimpleRoom" << std::endl;
	}
};

class MagicRoom : public Room{
public:
	MagicRoom(){
		std::cout << "MagicRoom" << std:: endl;
	}
};

class Home{
public:
	virtual Room* makeRoom() = 0;

	void addtoHome(){
		Room* a = makeRoom();
		std::cout << "Add to Home" << std::endl;
	}
};

class MagicHome : public Home{
public:
	MagicHome(){
		addtoHome();
	}

	Room* makeRoom(){
		return new MagicRoom();
	}

};

class SimpleHome : public Home{

	SimpleHome(){
		addtoHome();
	}

	Room* makeRoom(){
		return new SimpleRoom();
	}
};

//int main() {
//	auto h = new MagicHome();
//}


