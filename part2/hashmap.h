//
// Created by Jiawen Liu on 1/21/20.
//
#pragma once;
#include <cstring>
#include "object.h"

#ifndef ASSIGNMENT1_PART2_HASHMAP_H
#define ASSIGNMENT1_PART2_HASHMAP_H

#endif //ASSIGNMENT1_PART2_HASHMAP_H


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


    /**
     * Default constructor that construct an object of Hashnode
     * @param key       the key needs to be hased and specify where the value resides
     * @param val       the value needs to be stored in Hashmap
     * @param next      Hashnode pointer that points to the next Hashnode
     */
    Hashnode(Object* key, Object* val) {
        _key = key;
        _value = val;
        next = NULL;
    }

    /**
     * Hashnode constructor that make a copy of the given Hashnode
     * @param node      the node that needs to be copied
     */

    Hashnode(Hashnode* node) {
        _key = node -> _key;
        _value = node -> _value;
        next = nullptr;
    }

    /**
     * Hashnode destructor that delete Hashnode object
     */
    ~Hashnode() {
    }
};

class Hashmap : public Object {

private:
    Hashnode** table;
    int size;
    int capacity;


public:

    /**
     * Default constructor that constructs an empty HashMap with
     * the default initial capacity 16
    */
    Hashmap() {
        table = new Hashnode* [16];
        size = 0;
        capacity = 16;
        for(int i = size; i < capacity; i++){
            table[i] = nullptr;
        }
    }

    /**
     * Destructor that delete Hashmap object
     */
    ~Hashmap() {
        delete[] table;
    }


    /**
     * Returns the number of key-value (Hashnode) mappings in this map.
     */
    int get_size(){
        return size;
    }


    /**
     * return index for hashcode of key
     * @param key       the key that used to be hashed and get location of an object that needs to be stored
     * @return index    index of the inner array
     */
    int index_for(Object* key) {
        if(key) {
            return key->hashCode() & (capacity - 1);
        }
    }

    /**
     * resize of inner array when size hits its threshold(capacity)
     */

    void resize() {
        capacity *= 2;
        Hashnode** newTable = new Hashnode* [capacity];
        for(int i = 0; i < size; i++){
            Hashnode* needAdd = new Hashnode(table[i]);
            while(table[i] != NULL) {
                int index = index_for(needAdd->_key);
                while(newTable[index] != NULL) {
                    newTable[index] = newTable[index]->next;
                }
                newTable[index] = needAdd;
                table[i] = table[i]->next;
            }
        }
        delete [] table;
        table = newTable;
    }


    /**
     * Associates the specified value with the specified key in this map.
     * If the map previously contained a mapping for the key, the old value is replaced.
     * @param key   key with which the specified value is to be associated
     * @param val   value to be associated with the specified key
     * @return  the previous value associated with key, or null if there was no mapping for key.
     */
    Object* put(Object* key, Object* val) {

        if(size == capacity) {
            resize();
        }

        int index = index_for(key);

        Hashnode* node = new Hashnode(key, val);

        Hashnode* cur = table[index];

        if(cur == NULL) {
            table[index] = node;
            size++;
        }
        else {
            while(cur->next != NULL) {
                if(cur->_key->equals(key)){
                    cur->_value = val;
                    return cur->_value;
                }
                cur = cur->next;
            }

            if(cur->_key->equals(key)) {
                cur->_value = val;
            } else {
                cur->next = node;
                size++;
            }
        }
        return NULL;
    }


    /**
     * Returns the value to which the specified key is mapped, or null if this map contains no mapping for the key.
     * @param key   the key whose associated value is to be returned
     * @return  the value to which the specified key is mapped, or null if this map contains no mapping for the key
     */
    Object* get(Object* key){
        int index = index_for(key);

        Hashnode* cur = table[index];

        while(cur != NULL){
            if(cur->_key->equals(key)){
                return cur->_value;
            }
            cur = cur->next;
        }

        return NULL;
    }


    /**
     * Returns true if this map contains a mapping for the specified key.
     * @param key   The key whose presence in this map is to be tested
     * @return  true if this map contains a mapping for the specified key, otherwise false
     */
    bool containsKey(Object* key){
        int index = index_for(key);

        Hashnode* cur = table[index];

        while(cur != NULL){
            if(cur->_key->equals(key)){
                return true;
            }
            cur = cur->next;
        }
        return false;
    }


    /**
     * Removes the mapping for the specified key from this map if present.
     * @param key   key whose mapping is to be removed from the map
     * @return  the previous value associated with key, or null if there was no mapping for key.
     */
    Object* remove(Object* key) {
        int index = index_for(key);
        Hashnode* cur = table[index];
        Hashnode* pre = NULL;

        while(cur != NULL){
            if(cur->_key->equals(key)){
                if(pre != NULL){
                    pre->next = cur->next;
                } else {
                    table[index] = cur->next;
                }
                size--;
                return cur->_value;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return NULL;
    }

};