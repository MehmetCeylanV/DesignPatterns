/*
 * VisitorPattern.cpp
 *
 *  Created on: Jan 22, 2020
 *      Author: mehmetcey
 */

#include <iostream>
#include <memory>

class Element;

class Visitor{
public:
	void virtual visit(Element* e) = 0;
	void virtual doSomething(Element* e) = 0;
};

class Element{
public:
	void virtual accept(Visitor* v) = 0;
};

class Visitor1 : public Visitor{
	void visit(Element* e) override {
		doSomething(e);
	}

	void doSomething(Element* e) override{
		std::cout << "Visitor1 did something" << std::endl;
	};
};

class Visitor2 : public Visitor{
	void visit(Element* e) override {
		doSomething(e);
	}

	void doSomething(Element* e) override{
		std::cout << "Visitor2 did something" << std::endl;
	};
};

class AnElement : public Element{
	void accept(Visitor* v){
		v->visit(this);
	}
};

int main(){
	std::unique_ptr<Element> e(new AnElement());
	std::unique_ptr<Visitor> v1(new Visitor1());
	std::unique_ptr<Visitor> v2(new Visitor2());
	e->accept(v1.get());
	e->accept(v2.get());
}

