/*
 * AbstractFactory.cpp
 *
 *  Created on: Jan 7, 2020
 *      Author: mehmetcey
 */

#include <iostream>

class Button{
public:
	virtual void paint() = 0;
};

class WinButton : public Button{
	void paint() override {
		std::cout << "WinButton" << std::endl;
	}
};

class LinuxButton : public Button{
	void paint() override {
		std::cout << "LinuxButton" << std::endl;
	}
};

class AbstractFactory{
public:
	virtual Button* createButton() = 0;
};

class WinFactory : public AbstractFactory{
public:
	Button* createButton(){
		return new WinButton();
	}
};

class LinuxFactory : public AbstractFactory{
public:
	Button* createButton(){
		return new LinuxButton();
	}
};

AbstractFactory* fac(int x){
	if (x)
		return new WinFactory();
	else
		return new LinuxFactory();
}

int main() {
	auto f = fac(1);
	Button* b = f->createButton();
	b->paint();
}

