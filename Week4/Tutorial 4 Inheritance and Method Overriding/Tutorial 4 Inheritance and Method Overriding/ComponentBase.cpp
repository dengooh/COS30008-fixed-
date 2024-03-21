// COS30008, tutorial 4, 2024

#include "ComponentBase.h"


ComponentBase::ComponentBase( double aBaseValue, const std::string& aMajorUnit, const std::string& aMinorUnits ) noexcept:
    fBaseValue(aBaseValue),
    fMajorUnit(aMajorUnit),
    fMinorUnits(aMinorUnits)
{}


double ComponentBase::getBaseValue() const noexcept
{
    return fBaseValue;
}


void ComponentBase::setBaseValue( double aBaseValue ) noexcept
{
    fBaseValue = aBaseValue;
}


const std::string& ComponentBase::getMajorUnit() const noexcept
{
    return fMajorUnit;
}


const std::string& ComponentBase::getMinorUnits() const noexcept
{
    return fMinorUnits;
}


double ComponentBase::getPotentialAt( double aCurrent, double aFrequency ) const noexcept
{
    return getReactance(aFrequency) * aCurrent;
}


double ComponentBase::getCurrentAt( double aVoltage, double aFrequency ) const noexcept
{
    return aVoltage / getReactance(aFrequency);
}


std::istream& operator>>( std::istream& aIStream, ComponentBase& aObject )
{
    double value;
    std::string unit;
    aIStream >> value >> unit;
    
    aObject.setBaseValue(value, unit);
    
    return aIStream;
}


std::ostream& operator<<( std::ostream& aOStream, const ComponentBase& aObject )
{
    double value = 0;
    std::string unit;
    aObject.toUnitValue(value, unit);
    
    aOStream << value << " " << unit;
    return aOStream;
}
