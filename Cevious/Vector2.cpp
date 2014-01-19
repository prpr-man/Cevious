#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <cmath>

Vector2::Vector2(void) : x(0), y(0)
{
}

Vector2::Vector2(const Vector2 &rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Vector2::Vector2(double x,double y){
    this->x = x;
    this->y = y;
}

bool Vector2::operator==(const Vector2 &rhs) const
{
    return (x==rhs.x && y==rhs.y);
}

bool Vector2::operator!=(const Vector2 &rhs) const
{
    return (x!=rhs.x || y==rhs.y);
}

Vector2 Vector2::operator*(double rhs) const
{
    return Vector2(x*rhs,y*rhs);
}

Vector2& Vector2::operator*=(double rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

Vector2 Vector2::operator/(double rhs) const
{
    return Vector2(x/rhs,y/rhs);
}

Vector2& Vector2::operator/=(double rhs)
{
    x /= rhs;
    y /= rhs;
    return *this;
}

Vector2 Vector2::operator+(const Vector2 &rhs) const
{
    return Vector2(x+rhs.x,y+rhs.y);
}

Vector2& Vector2::operator+=(const Vector2 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 &rhs) const
{
    return Vector2(x-rhs.x,y-rhs.y);
}

Vector2& Vector2::operator-=(const Vector2 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector2 Vector2::operator+(void) const
{
    return Vector2(x,y);
}

Vector2 Vector2::operator-(void) const
{
    return Vector2(-x,-y);
}

Vector2& Vector2::normalize(void)
{
    double mag = magnitude();
    if(mag > 0.0)(*this)/mag;
    
    return *this;
}

Vector2 Vector2::normalized(void) const
{
    return Vector2(x,y).normalize();
}

double Vector2::dot(const Vector2 &rhs) const
{
    return x*rhs.x + y*rhs.y;
}

double Vector2::magnitude(void) const
{
    return sqrt(x*x+y*y);
}

double Vector2::angle(const Vector2 &rhs, bool degree) const
{
    double theta = acos(dot(rhs)/(this->magnitude()*rhs.magnitude()));
    return degree ? theta * 180.0 / M_PI : theta;
}

double Vector2::distance(const Vector2 &lhs, const Vector2 &rhs)
{
    return (lhs-rhs).magnitude();
}













