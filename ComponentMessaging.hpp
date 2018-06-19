//
// Created by Estevan Hernandez on 8/3/17.
//

#ifndef SFML_ENGINE_COMPONENTMESSAGING_HPP
#define SFML_ENGINE_COMPONENTMESSAGING_HPP

#include <iostream>
#include <vector>
#include <SFML/System.hpp>

class MessageBase {
public:
    virtual ~MessageBase() {};
};

template <class T>
class Message: public MessageBase {
private:
    T data_;
    std::string name_;
    //std::string description_;
public:
    Message(T data, std::string name) {
        data_ = data;
        name_ = name;
        //description_ = description;
    }
    const std::string &name = name_;
    //const std::string &description = description_;
    const T &data = data_;

};

/* MESSAGE HANDLER */

class Handler {
public:
    virtual void handleMessage(MessageBase const &message) {
        std::cout << "message: " << &message << std::endl;
    };
};

/* DISPATCHER */
class Dispatcher {
protected:
    std::vector<Handler *> handlers;
    void addHandler(Handler *handler) {
        handlers.push_back(handler);
    }
    void removeHandler(Handler *handler) {
        handlers.erase(std::remove(handlers.begin(), handlers.end(), handler), handlers.end());
    }
    void dispatchMessage(MessageBase const &message) {
        for (Handler *handler: handlers) {
            Handler &handlerRef = *handler;
            handlerRef.handleMessage(message);
        }
    }  
};

#endif //SFML_ENGINE_COMPONENTMESSAGING_HPP
