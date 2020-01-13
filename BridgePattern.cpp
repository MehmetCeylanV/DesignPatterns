/*
 * BridgePattern.cpp
 *
 *  Created on: Jan 13, 2020
 *      Author: mehmetcey
 */

#include <iostream>
#include <memory>

class Logger{
public:
	virtual void log(std::string log) = 0;
};

class LogtoFile: public Logger{
	void log(std::string log){
		std:: cout << "Log to file " << log << std::endl;
	}
};

class LogtoDisplay: public Logger{
	void log(std::string log){
		std:: cout << "Log to display " << log << std::endl;
	}
};

class App{
protected:
	std::shared_ptr<Logger> logger;
public:
	App(std::shared_ptr<Logger> logger) : logger(logger){}
	void changeLogger(std::shared_ptr<Logger> new_logger){
		logger = new_logger;
	}
	virtual void error(std::string msg) = 0;
};

class App1 : public App{
public:
	App1(std::shared_ptr<Logger> logger) : App(logger){}

	void error(std::string msg){
		logger->log(msg);
	}
};

int main(){
	std::shared_ptr<Logger> lg(new LogtoFile());
	std::shared_ptr<App> app(new App1(lg));
	app->error("Error");
	app->changeLogger(std::shared_ptr<Logger>(new LogtoDisplay()));
	app->error("Error");
}

