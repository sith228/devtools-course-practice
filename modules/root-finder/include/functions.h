// Copyright 2017 Maxim Doronin

#ifndef MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_
#define MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_

#include <vector>

class Function {
 public:
    explicit Function(std::vector<float> koefs);
    virtual float f(float x) const = 0;
    virtual float df(float x) const = 0;
    virtual float d2f(float x) const = 0;
 protected:
    std::vector<float> koefs;
};

class Polynomial2Degree : public Function {
 public:
    explicit Polynomial2Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Polynomial3Degree : public Function {
 public:
    explicit Polynomial3Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Polynomial4Degree : public Function {
 public:
    explicit Polynomial4Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Exponent : public Function {
 public:
    explicit Exponent(std::vector<float> koefs) : Function(koefs) {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

#endif  // MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_
