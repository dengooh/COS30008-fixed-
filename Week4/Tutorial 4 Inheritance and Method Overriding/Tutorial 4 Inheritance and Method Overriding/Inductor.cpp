// COS30008, Tutorial 4, 2024

#define _USE_MATH_DEFINES

#include "Inductor.h"
#include <cmath>


Inductor::Inductor( double aBaseValue ) noexcept:
    ComponentBase( aBaseValue, "H", "Hmunp" )
{}


bool Inductor::mustAdjust( double aValue ) const noexcept
{
    if ( aValue < 1.0f )
    {
        return true;
    }
    
    return false;
}


const double Inductor::getScalar() const noexcept
{
    return 1000.0f;
}


double Inductor::getReactance( double aFrequency ) const noexcept
{
    return (2 * M_PI * aFrequency * getBaseValue());
}


