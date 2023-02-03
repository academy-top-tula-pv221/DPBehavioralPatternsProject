#include <iostream>

#include "Chain.h"

int main()
{
    Receiver* receiver = new Receiver(false, true, false);
    PaymentHandler* handler = new BankPaymentHandler();
    handler->Successor() = new PayPalTransferHandler();
    handler->Successor()->Successor() = new BankPaymentHandler();
    handler->Successor()->Successor()->Successor() = new PayPalTransferHandler();

    handler->Handle(receiver);
}
