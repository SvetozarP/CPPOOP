#ifndef Actionable_h
#define Actionable_h

struct Actionable {
    virtual void act() = 0;

    virtual ~Actionable() = default;
};


#endif
