/*
 * ObserverPattern.cpp
 *
 *  Created on: Jan 22, 2020
 *      Author: mehmetcey
 */

#include <iostream>
#include <memory>
#include <list>

class Observer{
public:
	void virtual onSomething() = 0;
};

class Observer1 : public Observer{
	void virtual onSomething(){
		std::cout << "Something happened" << std::endl;
	}
};

class Observer2 : public Observer{
	void virtual onSomething(){
		std::cout << "Something happened" << std::endl;
	}
};

class Source{
	std::list<Observer*> listeners;
public:

	void add_listener(Observer* ob){
		if (ob)
			listeners.push_back(ob);
	}

	void remove_listener(Observer* ob){
		if (ob){
			for (auto x : listeners){
				if (x == ob)
					listeners.remove(ob);
			}
		}
	}

	void notify_listeners(){
		for (auto l : listeners){
			l->onSomething();
		}
	}
};

//int main(){
//	std::unique_ptr<Observer> ob1(new Observer1());
//	std::unique_ptr<Observer> ob2(new Observer2());
//	std::unique_ptr<Source> source(new Source());
//	source->add_listener(ob1.get());
//	source->add_listener(ob2.get());
//	source->notify_listeners();
//}

