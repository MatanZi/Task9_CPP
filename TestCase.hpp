//
// Created by Matan Zilka on 6/11/2018.
//

#ifndef TASK9_CPP_TESTCASE_HPP
#define TASK9_CPP_TESTCASE_HPP

#include "string"
#include "iostream"
#include "ostream"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TestCase{
private:
    int passed , failed;
    string funcName;
    ostream* out;

public:
    //------------------------ Constuctor ------------------------
    TestCase(string name , ostream& out);

    //------------------------ Functions ------------------------
    template <typename T>
    TestCase check_equal(const T &a , const T &b){
        if((T)a == (T)b){
            passed++;
        } else{
            failed++;
            *out<<funcName<< ": Failure in test #" <<passed+failed<<":"<<a<<"should equal"<< b<<"!"<<endl;
        }
        return *this;
    }

    template <typename T>
    TestCase check_different(const T &a , const T &b){
        if((T) a != (T) b){
            passed++;
        }else{
            failed++;
            *out<<funcName<< ": Failure in test #" <<passed+failed<<":"<<a<<"should not equal"<< b<<"!"<<endl;
        }
        return *this;
    }

    template <typename T>
    TestCase check_output(const T& a , string b){
        ostringstream os;
        os << a;
        if(os.str() == b){
            passed++;
        }
        else{
            failed++;
            *out<<funcName<< ": Failure in test #" <<passed+failed<<": string value should be "<<b<<"but is"<< os.str()<<"!"<<endl;
        }
        return *this;
    }

    template <typename T ,typename S ,typename X>
    TestCase check_function(T func , const S& a , const X& b){
        if (b == func(a))
            passed++;
        else
        {
            failed++;
            *out<< funcName << ": Failure in test #" << passed + failed << ": Function should return " << b << " but returned " << func(a) << "!" << endl;
        }
        return *this;
    }

    void print();
};

#endif //TASK9_CPP_TESTCASE_HPP
