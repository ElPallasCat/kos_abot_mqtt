#include "message_sender.h"
#include <iostream>


void NavigationMessageSender::sendManualMessage(std::unique_ptr<Message> message) {
       auto manual_payload = message->getManualMessagePayload();

    forte_NavigationCommand_SetNavigationCommand_req req;
    forte_NavigationCommand_SetNavigationCommand_res res;     
    req.value.command = (uint8_t) manual_payload.cmd;
    req.value.durationMs = manual_payload.valMs;
    req.value.speed = manual_payload.speed;

    if (forte_NavigationCommand_SetNavigationCommand(&proxy->base, &req, NULL, &res, NULL) == rcOk) {
        if (res.result == 1) {
            std::cout << "[NavMessageSender] Command sucsessfull applied by controller" << std::endl;
        } else {
            std::cerr << "[NavMessageSender] Command sent but not applied by controller. COntroller is busy..." << std::endl;
        }

    } else {
          std::cerr << "[NavMessageSender] Error sending command to naviation controller" << std::endl;
    }
    nk_req_reset(&req);
}


void NavigationMessageSender::sendAutoMessage(std::unique_ptr<Message> message) {

}


void NavigationMessageSender::sendMessage(std::unique_ptr<Message> message) {
    //if (!message->isManualMessage()) {
    //   std::cerr << "[NavMessageSender] Sending auto message...." << std::endl;
    //    sendAutoMessage(std::move(message));
    //    return;
    }

    std::cerr << "[NavMessageSender] Sending manual message...." << std::endl;
    sendManualMessage(std::move(message));
}