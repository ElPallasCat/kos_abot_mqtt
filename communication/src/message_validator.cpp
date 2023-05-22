#include "message_validator.h"
#include <iostream>
 
using namespace rapidjson;

std::unique_ptr<Message> MessageValidator::validateMessage(std::string message) {
    Document document;
    document.Parse(message.c_str());
    if (!document.IsObject() || document.HasParseError() || !document.HasMember("cmd") || !document["cmd"].IsString()) {
        return nullptr;
    }

    Message *msg = new Message();
    auto uPrt = std::unique_ptr<Message>(msg);

    auto cmd = document["cmd"].GetString();
    msg->mp.cmd = -1;
    msg->mp.speed = -1;
    msg->isManual = true;
    if (strcmp(cmd,"forward") == 0) {
        msg->mp.cmd = 0;
    } 
    if (strcmp(cmd, "back") == 0) {
        msg->mp.cmd = 1;
    }
    if (strcmp(cmd, "left") == 0) {
        msg->mp.cmd = 2;
    }
    if (strcmp(cmd, "right") == 0) {
        msg->mp.cmd = 3;
    }
    if (strcmp(cmd, "stop") == 0) {
        msg->mp.cmd = 4;
        return uPrt;
    }

    //if (strcmp(cmd, "auto") == 0) {
    //    return validateAuto(message);
    //}

    if (msg->mp.cmd < 0) {
        return nullptr;
    }

    if (!document.HasMember("val") || !document["val"].IsDouble()) {
        return nullptr;
    }
    
    msg->mp.valMs = (int)(document["val"].GetDouble() * 1000);
    if (msg->mp.valMs < 0) {
        return nullptr;
    }

    return uPrt;
}


std::unique_ptr<Message> MessageValidator::validateAuto(std::string message) {

    return nullptr;
}


bool Message::isManualMessage() {
    return isManual;
}

manual_message_payload Message::getManualMessagePayload() {
    return mp;
}

auto_message_payload Message::getAutoMessagePayload() {
    return ap;
}