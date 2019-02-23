#include "Vec.h"
#include <iostream>
#include <math.h>

struct color {
  int r;
  int g;
  int b;
};

class Particle {
  public:
  color c;
  int type;
  float mass;
  vec2f pos;
  vec2f vel;
  vec2f acc;

  Particle() {}
  Particle(int x, int y, float _mass)
      : mass(_mass)
      , pos(vec2f(x, y))
      , vel(vec2f(0, 0))
      , acc(vec2f(0, 0))
      , type(rand() % 3 + 1)
  {
    c.r = 0;
    c.g = 0;
    c.b = 0;

    if (type == 1) {
      c.r = 255;
    } else if (type == 2) {
      c.g = 255;
    } else {
      c.b = 255;
    }
  }

  void update()
  {
    vel += acc;

    vec2f step = pos + vel;

    if (0 > step.x || step.x > width) {
      vel.x *= -1;
      vel *= 0.8;
    }

    if (0 > step.y || step.y > height) {
      vel.y *= -1;
      vel *= 0.8;
    }

    pos += vel;
    acc *= 0;
    // vel.limit(5);
  }

  void applyForce(vec2f force)
  {
    acc += force;
  }

  float dist(Particle other)
  {
    return sqrt(
        pow(other.pos.x - pos.x, 2) + pow(other.pos.y - pos.y, 2));
  }
};