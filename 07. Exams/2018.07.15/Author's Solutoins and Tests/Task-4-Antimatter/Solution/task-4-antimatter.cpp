#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

// NOTE: the MAX_COORD is 65535, which is 2^16 - 1, hence this representation
const int BITS_PER_COORD = 16;
const int MAX_COORD = (1 << BITS_PER_COORD) - 1;

struct Coordinates {
    int x;
    int y;

    Coordinates(int x, int y)
    : x(x),
    y(y) {}

    Coordinates plusOther(Coordinates other) {
        return Coordinates(this->x + other.x, this->y + other.y);
    }
};

class Particle {
private:
    bool antimatter;
    Coordinates position;
    Coordinates speed;
    int lifetime;
public:
    Particle(bool antimatter, int x, int y, int xSpeed, int ySpeed, int lifetime)
    : antimatter(antimatter)
    , position(x, y)
    , speed(xSpeed, ySpeed)
    , lifetime(lifetime) {}

    bool isAntimatter() {
        return this->antimatter;
    }

    Coordinates getSpeed() {
        return this->speed;
    }

    int getLifetime() {
        return this->lifetime;
    }

    Coordinates getPosition() {
        return this->position;
    }

    bool exists() {
        return lifetime > 0;
    }

    void update() {
        if (!this->exists()) {
            return;
        }

        this->position = this->position.plusOther(this->speed);
        this->lifetime--;
    }
};

int encodeCoordinates(Coordinates c) {
    // NOTE: the approach is equivalent to this: return c.x * 65536 + c.y;
    // we put the x part of the coordinate in the "higher" part of the value,
    // and the y part of the coordinate in the "lower" part of the value.
    // To make this easier to understand, imagine the coordinates were from 0 to 9,
    // and we wanted x and y in a single integer - we'd just multiply x by 10 and add y,
    // for example if we had x = 5; y = 3, then we could encode them as 53
    // (assuming x and y can't be larger than 9). Since the actual coordinates are up to 65535,
    // we need to multiply by 65535 + 1 = 65536. However, that is 2^16, so it is easier to just
    // shift-left x by that number of bits, then "OR" the y value in, which effectively replaces
    // the newly inserted 0s with the values of y. We know that int will fit this, because int
    // on the Judge system (as stated in the problem description) is 32 bits, so it has room for 2*16
    // bits. We don't really care that the higher encoded values will be negative, just that they
    // uniquely match a pair of actual coordinates in the task

    return (c.x << BITS_PER_COORD) | c.y;
}

bool outside(Coordinates c) {
    return c.x < 0 || c.y < 0 || c.x > MAX_COORD || c.y > MAX_COORD;
}

void updateParticles(list<Particle>& particles) {
    auto i = particles.begin();
    while (i != particles.end()) {
        i->update();
        if (!(i->exists()) || outside(i->getPosition())) {
            i = particles.erase(i);
        } else {
            i++;
        }
    }
}

void processCollisions(list<Particle>& particles) {
    unordered_set<int> matter;
    unordered_set<int> antimatter;

    for (Particle p : particles) {
        int encodedPosition = encodeCoordinates(p.getPosition());
        if (p.isAntimatter()) {
            antimatter.insert(encodedPosition);
        } else {
            matter.insert(encodedPosition);
        }
    }

    auto i = particles.begin();
    while (i != particles.end()) {
        bool hasCollision = false;
        int encodedPosition = encodeCoordinates(i->getPosition());
        if (i->isAntimatter()) {
            hasCollision = matter.find(encodedPosition) != matter.end();
        } else {
            hasCollision = antimatter.find(encodedPosition) != antimatter.end();
        }

        if (hasCollision) {
            i = particles.erase(i);
        } else {
            i++;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    list<Particle> particles;

    int numParticles;
    cin >> numParticles;

    for (int i = 0; i < numParticles; i++) {
        char type;
        int x, y, speedX, speedY;
        int lifetime;

        cin >> type >> x >> y >> speedX >> speedY >> lifetime;

        particles.push_back(Particle(type == 'a', x, y, speedX, speedY, lifetime));
    }

    int numSteps;
    cin >> numSteps;

    int currentStep = 0;
    int destroyedByCollision = 0;

    while (!particles.empty() && currentStep < numSteps) {
        updateParticles(particles);

        int beforeCollisions = particles.size();
        processCollisions(particles);
        destroyedByCollision += beforeCollisions - particles.size();

        currentStep++;
    }

    int numAntimatter = 0;
    int numMatter = 0;
    for (Particle p : particles) {
        if (p.exists()) {
            if (p.isAntimatter()) {
                numAntimatter++;
            } else {
                numMatter++;
            }
        }
    }

    cout << numMatter << " " << numAntimatter << endl;
    cout << destroyedByCollision << endl;

    return 0;
}
