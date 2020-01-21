/*
 * CommandPattern.cpp
 *
 *  Created on: Jan 21, 2020
 *      Author: mehmetcey
 */
#include <memory>
#include <iostream>
#include <queue>

class Command{
public:
	virtual void execute() = 0;
};

class Cut : public Command{
public:
	void execute(){
		std::cout << "Cut cut" << std::endl;
	}
};

class Wash : public Command{
public:
	void execute(){
		std::cout << "Wash wash" << std::endl;
	}
};

class Cook : public Command{
public:
	void execute(){
		std::cout << "Cook cook" << std::endl;
	}
};

class Chef{
	std::queue<Command*> jobs;
public:
	Chef(){}
	void addToQueue(Command* c){
		if (c)
			jobs.push(c);
	}
	void run(){
		Command* c = jobs.front();
		if (c){
			c->execute();
			jobs.pop();
		}
	}
	~Chef(){}
};

//int main(){
//	std::unique_ptr<Chef> a_chef(new Chef());
//	std::unique_ptr<Command> cut(new Cut());
//	std::unique_ptr<Command> wash(new Wash());
//	std::unique_ptr<Command> cook(new Cook());
//
//	a_chef->addToQueue(wash.get());
//	a_chef->addToQueue(cut.get());
//	a_chef->addToQueue(cook.get());
//
//	a_chef->run();
//	a_chef->run();
//	a_chef->run();
//}

