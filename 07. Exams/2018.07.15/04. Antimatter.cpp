#include <iostream>
#include <list>
#include <unordered_map>

#pragma GCC optimize ("O3")

class Particle {
private:
  static const int MAX_POSITION = 65535;
  static const int MIN_POSITION = 0;

  bool hasCollided = false;
  bool isMatterType;
  int positionX;
  int positionY;
  int speedX;
  int speedY;
  int lifetime;
public:
  Particle(bool isMatter, int positionX, int positionY, int speedX, int speedY, int lifetime) :
      isMatterType(isMatter),
      positionX(positionX),
      positionY(positionY),
      speedX(speedX),
      speedY(speedY),
      lifetime(lifetime) { }

  void tick() {
    --this->lifetime;
    this->positionX += speedX;
    this->positionY += speedY;
  }

  bool isAlive() const {
    return this->lifetime > 0 &&
           !this->hasCollided &&
           this->positionX >= MIN_POSITION && this->positionX <= MAX_POSITION &&
           this->positionY >= MIN_POSITION && this->positionY <= MAX_POSITION;
  }

  long getPosition() const {
    return this->positionX * MAX_POSITION + this->positionY;
  }

  bool isMatter() const {
    return this->isMatterType;
  }

  void setCollided() {
    this->hasCollided = true;
  }
};

int main() {
  std::ostream::sync_with_stdio(false);
  std::istream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::list<Particle> particles;
  int particlesCount;
  std::cin >> particlesCount;

  for (int i = 0, positionX, positionY, speedX, speedY, lifetime; i < particlesCount; ++i) {
    char type;
    std::cin >> type >> positionX >> positionY >> speedX >> speedY >> lifetime;
    particles.emplace_back(type == 'm', positionX, positionY, speedX, speedY, lifetime);
  }

  std::unordered_map<long, std::list<Particle*>> particlesByPosition;
  for (auto& particle: particles) {
    particlesByPosition[particle.getPosition()].push_back(&particle);
  }

  int ticks;
  std::cin >> ticks;

  size_t collidedParticles = 0;

  while (--ticks >= 0) {
    particlesByPosition.clear();
    particles.remove_if([&](Particle& particle) {
      particle.tick();
      if (particle.isAlive()) {
        particlesByPosition[particle.getPosition()].push_back(&particle);
        return false;
      }
      return true;
    });

    for (auto const& position : particlesByPosition) {
      bool hasMatter = false;
      bool hasAntimatter = false;
      std::list<Particle*> particlesList = position.second;
      for (auto const& particle: particlesList) {
        if (particle->isMatter()) {
          hasMatter = true;
        } else {
          hasAntimatter = true;
        }
        if (hasMatter && hasAntimatter) {
          break;
        }
      }
      if (hasMatter && hasAntimatter) {
        for (auto const& particle: particlesList) {
          particle->setCollided();
        }
        collidedParticles += particlesList.size();
      }
    }
  }

  size_t matterParticlesCount = 0, antimatterParticlesCount = 0;
  for (auto const& particle : particles) {
    if (particle.isAlive()) {
      if (particle.isMatter()) {
        ++matterParticlesCount;
      } else {
        ++antimatterParticlesCount;
      }
    }
  }

  std::cout << matterParticlesCount << " " << antimatterParticlesCount << std::endl << collidedParticles << std::endl;

  return 0;
}
