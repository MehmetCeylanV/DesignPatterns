/*
 * Adapter.cpp
 *
 *  Created on: Jan 13, 2020
 *      Author: mehmetcey
 */
#include <iostream>
#include <memory>


class LightningPhone{
public:
	virtual void recharge() = 0;
	virtual void lightningConnected() = 0;
};

class MicroUsbPhone{
public:
	virtual void recharge() = 0;
	virtual void microUsbConnected() = 0;
};

class IPhone : public LightningPhone{
	bool connected = false;
public:
	void recharge() override {
		if (connected)
			std::cout << "Charging" << std::endl;
	}
	void lightningConnected() override {
		connected = true;
	}
};

class Android : public MicroUsbPhone{
	bool connected = false;
public:
	void recharge() override {
		if (connected)
			std::cout << "Charging" << std::endl;
	}
	void microUsbConnected() override {
		connected = true;
	}
};

class MicroUsbToLightningAdapter : public MicroUsbPhone{
	std::unique_ptr<LightningPhone> lp;
public:
	MicroUsbToLightningAdapter(std::unique_ptr<LightningPhone> lp) : lp(std::move(lp)){}
	MicroUsbToLightningAdapter(LightningPhone* lp){
		this->lp.reset(lp);
	}

	void recharge() override {
		lp->recharge();
	}
	void microUsbConnected() override {
		lp->lightningConnected();
	}
};

//int main(){
//    std::unique_ptr<Android> an(new Android());
//    std::unique_ptr<IPhone> ip(new IPhone());
//
//    std::cout<< "Recharging android with MicroUsb" << std::endl;
//    an->microUsbConnected();
//    an->recharge();
//
//    std::cout<< "Recharging iPhone with Lightning" << std::endl;
//    ip->lightningConnected();
//    ip->recharge();
//
//    std::cout<< "Recharging iPhone with MicroUsb" << std::endl;
//    std::unique_ptr<MicroUsbToLightningAdapter> adapter(new MicroUsbToLightningAdapter(ip.get()));
//    adapter->microUsbConnected();
//    adapter->recharge();
//}


