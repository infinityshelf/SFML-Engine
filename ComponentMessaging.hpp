//
// Created by Estevan Hernandez on 8/3/17.
//

#ifndef SFML_ENGINE_COMPONENTMESSAGING_HPP
#define SFML_ENGINE_COMPONENTMESSAGING_HPP

#include <iostream>
#include <vector>
#include <SFML/System.hpp>

/* MESSAGES */

enum MESSAGE_TYPES {
    VECTOR2i,
    STRING,
    INT,
    FLOAT,
    BOOL
};

template <MESSAGE_TYPES> class Message;
class Describable {
public:
    std::string description;
};

template <> class Message<VECTOR2i>: public Describable {
public:
    Message<VECTOR2i>(sf::Vector2i &data):data_(data) { }
    const sf::Vector2i &data_;
};
template <> class Message<STRING>: public Describable {
public:
    Message<STRING>(std::string &data):data_(data) { }
    std::string &data_;
};
template <> class Message<INT>: public Describable {
public:
    Message<INT>(uint16_t &data):data_(data) { }
    uint16_t &data_;
};
template <> class Message<FLOAT>: public Describable {
public:
    Message<FLOAT>(float &data):data_(data) { }
    float &data_;
};

template <> class Message<BOOL>: public Describable {
public:
    Message<BOOL>(bool &data): data_(data) { }
    bool &data_;
};

/* MESSAGE HANDLER */

class MessageHandlerBase {
public:
    virtual ~MessageHandlerBase() = default;
};

template <MESSAGE_TYPES MT>
class MessageHandler : public MessageHandlerBase {
public:
    virtual void handleMessage(Message<MT> const &message) = 0;
};

/* MESSAGE DISPATCHER */

class MessageDispatcherBase {
protected:
    std::vector<MessageHandlerBase *> handlers;
    void addHandler(MessageHandlerBase *handler) {
        handlers.push_back(handler);
    }
    void removeHandler(MessageHandlerBase *handler) {
        handlers.erase(std::remove(handlers.begin(), handlers.end(), handler), handlers.end());
    }
};

template <MESSAGE_TYPES MT>
class MessageDispatcher : private MessageDispatcherBase {
public:
    using MessageDispatcherBase::addHandler;
    using MessageDispatcherBase::removeHandler;
    void dispatchMessage(Message<MT> const &data) {
        for (MessageHandlerBase *handler: handlers) {
            dynamic_cast<MessageHandler<MT> *>(handler)->handleMessage(data);
        }
    }
};

/* EXAMPLE USAGE */

/*

class Component {
public:
    virtual void update() = 0;
};

class Entity {
public:
    virtual void update() = 0;
protected:
    std::vector<Component *> components;
};

class Input: public Component, public MessageDispatcher<VECTOR2i> {
public:
    sf::Vector2i proposedVector;
    Input(MessageHandler<VECTOR2i> *handler) {
        addHandler(handler);
    }
    void update() override {
        proposedVector.x += 2;
        proposedVector.y += 4;
        proposedVector.z += 6;
        Message<VECTOR2i> message(proposedVector);
        dispatchMessage(message);
    }
};

class Physics: public Component, public MessageHandler<VECTOR2i> {
public:
    sf::Vector2i *proposedVector;
    void handleMessage(Message<VECTOR2i> const &message) override {
        std::cout << "I got a message! It says: x:" << message.data_.x << " y:" << message.data_.y << " z:" << message.data_.z << std::endl;
        proposedVector = &message.data_;
    }
    void update() override {
        std::cout << "I think I'm supposed to check for collisions" << std::endl;
    }
};

class Player: Entity {
public:
    Player() {
        Physics *physics = new Physics();
        Input *input = new Input(physics);
        components.push_back((Component *)input);
        components.push_back((Component *)physics);
    }
    void update() override {
        for (Component *component: components) {
            component->update();
        }
    }
};
 */
#endif //SFML_ENGINE_COMPONENTMESSAGING_HPP
