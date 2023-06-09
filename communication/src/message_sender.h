#ifndef _MESSAGE_SENDER_H
#define _MESSAGE_SENDER_H

#include "message_validator.h"

#include <coresrv/nk/transport-kos.h>
#include <coresrv/sl/sl_api.h>

#include <forte/NavigationCommand.idl.h>

class NavigationMessageSender {
    NkKosTransport *transport;
    struct forte_NavigationCommand_proxy *proxy;
    void sendAutoMessage(std::unique_ptr<Message> message);
    void sendManualMessage(std::unique_ptr<Message> message);
public:
    NavigationMessageSender(NkKosTransport *transport_, struct forte_NavigationCommand_proxy *proxy_): 
         transport(transport_), proxy(proxy_) {};
         
    void sendMessage(std::unique_ptr<Message> message);
};

#endif