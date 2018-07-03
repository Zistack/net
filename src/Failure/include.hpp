#include <atomic>
#include <exception>
#include <string>

#define Clonable(Base) Base, Failure::Clonable::T<Base, T>
