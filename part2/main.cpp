#pragma once;
#include <iostream>
#include <string.h>
#include "object.h"
#include "hashmap.h"
#include "string.h"


void FAIL() {   exit(1);    }
void OK(const char* m) { std:: cout << "All test cases in test " << m << " are passed" << std:: endl;}
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }


//TODO: 
//1. comment
//2. test cases: 
//   1) seperate true cases from false cases
//   2) insert the same string twice
//   3) resize
//   4) remove
//   5) contain_keys
//   6) get_keys
//   7) get_values

void test1() {
    Hashmap* h1 = new Hashmap();
    String * key_1 = new String("Hello");
    String * val_1 = new String("1");
    String * key_2 = new String("World");
    String * val_2 = new String("2");
    h1->put(key_1, val_1);
    t_true(h1->get_size() == 1);
    h1->put(key_2, val_2);
    t_true(h1->get_size() == 2);
    OK("1");
}


void test2() {
    Hashmap* h1 = new Hashmap();
    String * key_1 = new String("Hello");
    String * val_1 = new String("1");
    String * key_2 = new String("World");
    String * val_2 = new String("2");
    h1->put(key_1, val_1);
    h1->put(key_2, val_2);
    t_true(h1->get(key_1)->equals(val_1));
    t_true(h1->get(key_2)->equals(val_2));
    OK("2");
}


void test3() {
    Hashmap* h1 = new Hashmap();
    String * key_1 = new String("Hello");
    String * val_1 = new String("1");
    String * key_2 = new String("World");
    String * val_2 = new String("2");
    h1->put(key_1, val_1);
    h1->put(key_2, val_2);
    t_true(h1->remove(key_1)->equals(val_1));
    t_false(h1->remove(key_2)->equals(val_1));
    OK("3");
}


void test4() {
    Hashmap* h1 = new Hashmap();
    String * key_1 = new String("Hello");
    String * val_1 = new String("1");
    String * key_2 = new String("World");
    String * val_2 = new String("2");
    String * key_3 = new String("NEU");
    h1->put(key_1, val_1);
    h1->put(key_2, val_2);
    t_true(h1->containsKey(key_1));
    t_true(h1->containsKey(key_2));
    t_false(h1->containsKey(key_3));
    OK("4");
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
