/*
 * Singleton.cpp
 *
 *  Created on: Jan 7, 2020
 *      Author: mehmetcey
 */
#include <iostream>

class Singleton{
private:
	static Singleton* ins;
	Singleton(){
		std::cout << "Singleton" << std::endl;
	};
public:
	static Singleton* getInstance(){
		if (ins){
			std::cout << "Singleton ins" << std::endl;
		}
		else{
			ins = new Singleton();
		}
		return ins;
	}
};

Singleton* Singleton::ins = 0;

int main() {
	auto a = Singleton::getInstance();
	auto b = Singleton::getInstance();
}
