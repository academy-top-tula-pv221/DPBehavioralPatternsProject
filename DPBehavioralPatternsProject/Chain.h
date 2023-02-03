#pragma once
#include <iostream>
using namespace std;

class Receiver
{
	bool bankTransfer;
	bool moneyTransfer;
	bool payPalTransfer;
public:
	bool& BankTransfer() { return bankTransfer; }
	bool& MoneyTransfer() { return moneyTransfer; }
	bool& PayPalTransfer() { return payPalTransfer; }
	Receiver(bool b, bool m, bool p)
		: bankTransfer{ b }, moneyTransfer{ m }, payPalTransfer{ p } {}
};

class PaymentHandler
{
	PaymentHandler* successor;
public:
	PaymentHandler*& Successor(){ return successor; }
	virtual void Handle(Receiver* receiver) = 0;
};

class BankPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->BankTransfer())
			cout << "Bank transfer is ok\n";
		else if (Successor() != nullptr)
		{
			cout << "Bank transfer is crash\n";
			Successor()->Handle(receiver);
		}
			
	}
};

class MoneyTransferHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->MoneyTransfer())
			cout << "Money transfer is ok\n";
		else if (Successor() != nullptr)
		{
			cout << "Money transfer is crash\n";
			Successor()->Handle(receiver);
		}
			
	}
};

class PayPalTransferHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->PayPalTransfer())
			cout << "PayPal transfer is ok\n";
		else if (Successor() != nullptr)
		{
			cout << "PayPal transfer is crash\n";
			Successor()->Handle(receiver);
		}
			
	}
};


class Chain
{
};

