#include <iostream>

//#include "Chain.h"
//void ChainExample()
//{
//    Receiver* receiver = new Receiver(false, true, false);
//    PaymentHandler* handler = new BankPaymentHandler();
//    handler->Successor() = new PayPalTransferHandler();
//    handler->Successor()->Successor() = new BankPaymentHandler();
//    handler->Successor()->Successor()->Successor() = new PayPalTransferHandler();
//
//    handler->Handle(receiver);
//}

//
//#include "Command.h"
//void CommandExample()
//{
//    Television* tv = new Television();
//
//    Controller* pult = new Controller(new TvOnCommand(tv),
//        new TvSoundUpCommand(tv),
//        new TvSoundDownCommand(tv));
//
//    pult->ButtonPower();
//    pult->ButtonVolumePlus();
//    pult->ButtonVolumePlus();
//    pult->ButtonVolumePlus();
//    pult->ButtonVolumeMinus();
//    pult->ButtonVolumePlus();
//    pult->ButtonVolumePlus();
//    cout << "\n";
//    pult->ButtonUndo();
//    pult->ButtonUndo();
//    pult->ButtonUndo();
//    pult->ButtonUndo();
//
//    pult->ButtonPower();
//    pult->ButtonVolumePlus();
//}

//#include "Mediator.h"
//void MediatorExample()
//{
//    ManagerMediator* manager = new ManagerMediator();
//    Colleague* customer = new CustomerColleague(manager);
//    Colleague* developer = new DeveloperColleague(manager);
//    Colleague* tester = new TesterColleague(manager);
//
//    manager->Customer() = customer;
//    manager->Developer() = developer;
//    manager->Tester() = tester;
//
//    customer->Send("Order!!! I need of program!!!");
//    developer->Send("Program is ready!");
//    tester->Send("Program testing and is correct!");
//}

//#include "Startegy.h"
//void StrategyExample()
//{
//    std::string file = "file01.txt";
//    Archiver* archiver = new Archiver(new ArjСompression());
//    archiver->Archiving(file);
//
//    archiver->Compression() = new ZipСompression();
//    archiver->Archiving(file);
//
//    archiver->Compression() = new RarСompression();
//    archiver->Archiving(file);
//}

#include "State.h"

int main()
{
    Water* water = new Water(new LiquidWaterState());

    water->Heating();
    water->Heating();
    water->Heating();
    water->Frosting();
    water->Frosting();
    water->Frosting();
}
