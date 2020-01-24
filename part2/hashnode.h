//
// Created by Jiawen Liu on 1/24/20.
//

#ifndef PART2_HASHNODE_H
#define PART2_HASHNODE_H

#endif //PART2_HASHNODE_H

#pragma once;
#include <cstring>
#include "object.h"

/**
 * Hashnode class is represent of key-value pairs
 * Hashmap objects are stored in each bucket in our Hashmap
 * The implementation of hashnode is using linked list
 */
class Hashnode : public Object{

public:
    Object* _key;
    Object* _value;
    Hashnode* next;

public:
    /**
     * Default constructor that construct an object of Hashnode
     * @param key       the key needs to be hased and specify where the value resides
     * @param val       the value needs to be stored in Hashmap
     * @param next      Hashnode pointer that points to the next Hashnode
     */
    Hashnode(Object* key, Object* val);

    /**
     * Hashnode constructor that make a copy of the given Hashnode
     * @param node      the node that needs to be copied
     */
    Hashnode(Hashnode* node);

    /**
    * Hashnode destructor that delete Hashnode object
    */
    ~Hashnode();
};

Hashnode::Hashnode(Object* key, Object* val) :Object() {
    _key = key;
    _value = val;
    next = NULL;
}

Hashnode:: Hashnode(Hashnode* node) :Object() {
    _key = node -> _key;
    _value = node -> _value;
    next = nullptr;
}

Hashnode:: ~Hashnode() {}

