//
//  Shirt.h
//  AS257_AS262_lab_02
//
//  Created by Dean Roberts on 9/20/16.
//  Copyright © 2016 Dean Roberts. All rights reserved.
//

#ifndef Shirt_h
#define Shirt_h
#include <string>
using namespace std;
//as this is not a programming class, I will not be following c++ best practices.
class Shirt {
    
public:
    Shirt(string c, string t, string s): color(c), type(t), size(s){};
    string color;
    string type;
    string size;
private:
    
};

#endif /* Shirt_h */

