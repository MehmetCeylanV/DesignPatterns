/*
 * BuilderPattern.cpp
 *
 *  Created on: Jan 7, 2020
 *      Author: mehmetcey
 */

#include <iostream>

class Car{
	std::string name;
	std::string color;
public:
	Car(std::string name, std::string color ) : name(name), color(color){}
};

class CarBuilder{
public:
	std::string color;
	virtual Car* build() = 0;
};

class FerrariBuilder: public CarBuilder{
public:
	Car* build() override{
		return new Car("Ferrari",color);
	}
};

class SportsCarBuildDirector{
	CarBuilder* builder;
public:
	SportsCarBuildDirector(CarBuilder* builder){
		this->builder = builder;
	}

	void construct(){
		builder->color = "RED";
	}
};

//int main() {
//	//The Director assembles a car instance in the example above,
//	//delegating the construction to a separate builder object that it has been given to the Director by the Client.
//	auto b = new FerrariBuilder();
//	auto d = new SportsCarBuildDirector(b);
//	d->construct();
//	auto c = b->build();
//}
