#pragma once

// 二次元のベクトルクラスです．
// 必要そうな機能は全て実装したつもりです．
class Vector2 {
public:
    double x;
    double y;
        
    Vector2(void);
    Vector2(const Vector2 &rhs);
    Vector2 (double x,double y);
        
    bool operator==(const Vector2 &rhs) const;
    bool operator!=(const Vector2 &rhs) const;
        
    Vector2 operator*(double rhs) const;
    Vector2& operator*=(double rhs);
    Vector2 operator/(double rhs) const;
    Vector2& operator/=(double rhs);
        
    Vector2 operator+(const Vector2 &rhs) const;
    Vector2& operator+=(const Vector2 &rhs);
    Vector2 operator-(const Vector2 &rhs) const;
    Vector2& operator-=(const Vector2 &rhs);
        
    Vector2 operator+(void) const;
    Vector2 operator-(void) const;
        
    Vector2& normalize(void);
    Vector2 normalized(void) const;
        
    double dot(const Vector2 &rhs) const;
    double magnitude(void) const;
    double angle(const Vector2 &rhs, bool degree=false) const;
        
    static double distance(const Vector2 &lhs, const Vector2 &rhs);
};
    
inline Vector2 operator*(double lhs,const Vector2 &rhs)
{
    return Vector2(rhs.x*lhs,rhs.y*lhs);
}

