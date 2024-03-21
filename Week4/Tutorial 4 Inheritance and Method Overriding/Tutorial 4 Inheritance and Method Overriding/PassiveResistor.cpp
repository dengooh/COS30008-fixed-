// COS30008, tutorial 4, 2024

#include "PassiveResistor.h"


PassiveResistor::PassiveResistor( double aBaseValue ) noexcept:
    ComponentBase( aBaseValue, "Ohm", "OkM" )
{}



bool PassiveResistor::mustAdjust( double aValue ) const noexcept
{
    if (aValue > 1000.0f)
    {
        return true;
    }
    
    return false;
}


// returns component dependent scalar (1.0/1000.0)
const double PassiveResistor::getScalar() const noexcept
{
    return 1.0f/1000.0f;
}


// returns (frequency-dependent) passive resistance value (base value)
double PassiveResistor::getReactance( double aFrequency ) const noexcept
{
    return getBaseValue();
}
