#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

static int height;
static int width;

#include "Particle.h"
using namespace std;

#define PARTICLE_AMOUNT 1000
Particle particles[PARTICLE_AMOUNT];
vec2f GRAVITY = vec2f(0, 0.01);

class Example : public olc::PixelGameEngine {
  public:
  Example()
  {
    sAppName = "Example";
  }

  bool OnUserCreate() override
  {
    width = ScreenWidth();
    height = ScreenHeight();

    for (int i = 0; i < PARTICLE_AMOUNT; i++) {
      particles[i] = Particle(
          rand() % (width - 10) + 5,
          rand() % (height - 10) + 5,
          1);
    }

    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override
  {
    Clear(olc::Pixel(0, 0, 0));

    for (int i = 0; i < PARTICLE_AMOUNT; i++) {
      particles[i].applyForce(GRAVITY);

      for (int n = 0; n < PARTICLE_AMOUNT; n++) {
        float dist = particles[i].dist(particles[n]);

        if (dist < 4) {
          particles[i].applyForce(((
            particles[n].pos - particles[i].pos
          ) / 10).invert());

          particles[i].acc.limit(0.01);
        }
      }

      particles[i].update();
      Draw(particles[i].pos.x, particles[i].pos.y, olc::Pixel(255, 255, 255));
    }

    return true;
  }
};

int main()
{
  Example demo;
  if (demo.Construct(256, 240, 4, 4))
    demo.Start();

  return 0;
}