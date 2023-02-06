#pragma once
#include <iostream>
#include <stack>

using namespace std;

// interface Command
class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual bool CanExecute() = 0;
};

// receiver
class Television
{
	bool powerOn;
	int soundVolume;
public:
	Television() : powerOn{ false }, soundVolume{ 0 } {}
	void PowerOn()
	{
		cout << "tv power on\n";
		powerOn = true;
	}
	void PowerOff()
	{
		cout << "tv power off\n";
		powerOn = false;
	}

	void SoundAdd()
	{
		cout << "tv sound add, volume = " << ++soundVolume <<  "\n";
	}

	void SoundDel()
	{
		cout << "tv sound del, volume = " << --soundVolume << "\n";
	}
	bool IsPower()
	{
		return powerOn;
	}
	int SoundVolume()
	{
		return soundVolume;
	}
};

// concrete command
class TvOnCommand : public ICommand
{
	Television* tv;
public:
	TvOnCommand(Television* tv) : tv{ tv } {}
	void Execute() override
	{
		tv->PowerOn();
	}
	void Undo() override
	{
		tv->PowerOff();
	}
	bool CanExecute() override
	{
		return true;
	}
};

// concrete command
class TvSoundUpCommand : public ICommand
{
	Television* tv;
public:
	TvSoundUpCommand(Television* tv) : tv{ tv } {}
	void Execute() override
	{
		tv->SoundAdd();
	}
	void Undo() override
	{
		tv->SoundDel();
	}
	bool CanExecute() override
	{
		return tv->IsPower() && (tv->SoundVolume() < 5);
	}
};

// concrete command
class TvSoundDownCommand : public ICommand
{
	Television* tv;
public:
	TvSoundDownCommand(Television* tv) : tv{ tv } {}
	void Execute() override
	{
		tv->SoundDel();
	}
	void Undo() override
	{
		tv->SoundAdd();
	}
	bool CanExecute() override
	{
		return tv->IsPower() && (tv->SoundVolume() > 0);
	}
};

// invoker
class Controller
{
	ICommand* power;
	ICommand* soundUp;
	ICommand* soundDown;
	bool powerAction;

	stack<ICommand*> commandsHistory;
public:
	Controller(ICommand* power, ICommand* soundUp, ICommand* soundDown)
		: power{ power }, soundUp{ soundUp },
		soundDown{ soundDown }, powerAction{ false } {}

	void ButtonPower()
	{
		// CanExecute == true
		if (!powerAction)
			power->Execute();
		else
			power->Undo();
		powerAction = !powerAction;
	}
	void ButtonVolumePlus()
	{
		if (soundUp->CanExecute())
		{
			soundUp->Execute();
			commandsHistory.push(soundUp);
		}
	}
	void ButtonVolumeMinus()
	{
		if (soundDown->CanExecute())
		{
			soundDown->Execute();
			commandsHistory.push(soundDown);
		}
	}
	void ButtonUndo()
	{
		if (commandsHistory.size() > 0)
		{
			commandsHistory.top()->Undo();
			commandsHistory.pop();
		}
	}
};

// invoker
class MobileController
{
	ICommand* power;
	ICommand* soundUp;
	ICommand* soundDown;
	bool powerAction;

	stack<ICommand*> commandsHistory;
public:
	MobileController(ICommand* power, ICommand* soundUp, ICommand* soundDown)
		: power{ power }, soundUp{ soundUp },
		soundDown{ soundDown }, powerAction{ false } {}

	void MenuItemPower()
	{
		if (!powerAction)
			power->Execute();
		else
			power->Undo();
	}
	void MenuItemVolumePlus()
	{
		soundUp->Execute();
		commandsHistory.push(soundUp);
	}
	void MenuItemVolumeMinus()
	{
		soundDown->Execute();
		commandsHistory.push(soundDown);
	}
	void MenuItemUndo()
	{
		commandsHistory.top()->Undo();
		commandsHistory.pop();
	}
};

