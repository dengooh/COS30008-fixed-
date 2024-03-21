// COS30008, tutorial 4, 2024


#define _USE_MATH_DEFINES

#include "Capacitor.h"
#include <cmath>


Capacitor::Capacitor( double aBaseValue ) noexcept:
    ComponentBase(aBaseValue, "F", "Fmunp")
{}


bool Capacitor::mustAdjust( double aValue ) const noexcept
{
    if (aValue < 1.0f)
    {
        return true;
    }
    
    return false;
}


const double Capacitor::getScalar() const noexcept
{
    return 1000.0f;
}


double Capacitor::getReactance( double aFrequency ) const noexcept
{
    return 1 / (2 * M_PI * aFrequency * getBaseValue());
}
