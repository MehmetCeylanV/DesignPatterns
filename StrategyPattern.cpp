/*
 * StrategyPattern.cpp
 *
 *  Created on: Jan 14, 2020
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
	std::shared_ptr<Logger> logger;
public:
	App(std::shared_ptr<Logger> logger) : logger(logger){}

	void error(std::string msg){
		logger->log(msg);
	}

	void setLogger(std::shared_ptr<Logger> logger){
		this->logger = logger;
	}
};

//int main(){
//	std::shared_ptr<Logger> logger(new LogtoFile());
//	std::shared_ptr<App> app(new App(logger));
//	app->error("Error");
//}
