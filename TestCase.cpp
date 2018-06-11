//
// Created by Matan Zilka on 6/11/2018.
//

#include "TestCase.hpp"

//------------------------ Constuctor ------------------------
TestCase::TestCase(string name, ostream &out) {
    this->funcName = name;
    this->out = &out;
    this->failed = 0;
    this->passed = 0;
}


//------------------------ Functions ------------------------

void TestCase::print() {
    cout<<funcName<<" " << failed<< " failed " << passed << " passed " << passed+failed << " total "<< endl;
}