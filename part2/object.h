//
// Created by Jiawen Liu on 1/21/20.
//
#pragma once;
#ifndef ASSIGNMENT1_PART2_OBJECT_H
#define ASSIGNMENT1_PART2_OBJECT_H

#endif //ASSIGNMENT1_PART2_OBJECT_H


class Object {

public:
    virtual int hashCode() {
        return 1;
    }

    virtual bool equals(Object* object) {
        return this == object;
    }
};
