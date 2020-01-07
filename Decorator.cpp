/*
 * Decorator.cpp
 *
 *  Created on: Jan 7, 2020
 *      Author: mehmetcey
 */

#include <iostream>
#include <memory>

class Shape{
public:
	virtual void draw() = 0;
};

class SimpleShape : public Shape{
	std::string color;
public:
	SimpleShape(std::string color) : color(color){
	}

	void draw() override {
		std::cout << "Paint " << color << std::endl;
	}
};

class Decorator : public Shape{
public:
	std::unique_ptr<Shape> _sh;

	Decorator(std::unique_ptr<Shape> sh) : _sh(std::move(sh)){
	}

	void draw() override{
		_sh->draw();
	}
};

class PaintDecorator : public Decorator{
public:
	PaintDecorator(std::unique_ptr<Shape> sh) : Decorator(std::move(sh)){}

	void paint() {
		std::cout << "Paint" << std::endl;
	}

	void draw() override{
		paint();
		_sh->draw();
	}
};

class CutDecorator : public Decorator{
public:
	CutDecorator(std::unique_ptr<Shape> sh) : Decorator(std::move(sh)){}

	void cut() {
		std::cout << "Cut" << std::endl;
	}

	void draw() override{
		cut();
		_sh->draw();
	}
};

int main(){
    std::unique_ptr<Shape> my_shape = std::make_unique<SimpleShape>("Red");

    my_shape = std::make_unique<PaintDecorator>(std::move(my_shape));
    my_shape = std::make_unique<CutDecorator>(std::move(my_shape));
    my_shape->draw();
}
