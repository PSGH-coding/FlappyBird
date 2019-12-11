#ifndef TOUCHES_HPP
#define TOUCHES_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Touches{
  private :
    bool space;
  public :
    Touches(void);

    bool get_space(void);

    void set_space(bool b);

};

#endif
