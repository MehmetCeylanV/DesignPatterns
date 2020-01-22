/*
 * StatePattern.cpp
 *
 *  Created on: Jan 21, 2020
 *      Author: mehmetcey
 */

#include <iostream>
#include <memory>

class Webpage{

	class State{
	public:
		virtual void goToNewState(Webpage* page) = 0;
	};

	class Closed : public State{
		void goToNewState(Webpage* page) override {
			std::cout << "Page is closed, it is last state" << std::endl;
		}
	};

	class Closing : public State{
		void goToNewState(Webpage* page) override {
			std::cout << "Page is closing, next state is closed" << std::endl;
			page->setState(new Closed());
		}
	};

	class Opened : public State{
		void goToNewState(Webpage* page) override {
			std::cout << "Page is opened, next state is closing" << std::endl;
			page->setState(new Closing());
		}
	};

	class Opening : public State{
		void goToNewState(Webpage* page) override {
			std::cout << "Page is opening, next state is opened" << std::endl;
			page->setState(new Opened());
		}
	};

private:
	State* state;

public:
	Webpage(){
		state = new Opening();
	};

	void setState(State* state){
		this->state = state;
	}

	void run(){
		state->goToNewState(this);
	};
};

//int main(){
//	std::unique_ptr<Webpage> p(new Webpage());
//	p->run();
//	p->run();
//	p->run();
//	p->run();
//	p->run();
//}



