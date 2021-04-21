#include <math.h>
#include <utility>

template<class vType>
struct Vector3
{
    Vector3() {}
    Vector3(vType _x, vType _y, vType _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& pVector) {(*this) = pVector; }
    Vector3(Vector3&& pVector) { x = std::move(_vector.x); y = std::move(_vector.y); z = std::move(_vector.z); }

    vType x{0}, y{0}, z{0};

    vType dot(Vector3 _vector3) const
    {
        return _vector3.x * x + _vector3.y * y + _vector3.z * z;
    }
    vType length() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    //operators
    void operator=(const Vector3& _vector) { x = _vector.x; y = _vector.y; z = _vector.z; }
    void operator=(Vector3&& _vector) {x = std::move(_vector.x); y = std::move(_vector.y); z = std::move(_vector.z); }

    template<class T>
    Vector3 operator+(const T& _val) { return {x + _val, y + _val, z + _val}; }
    Vector3 operator+(const Vector3& _vector) {return {x + _vector.x, y + _vector.y, z + _vector.z}; }

    template<class T>
    Vector3 operator-(const T& _val) { return {x - _val, y - _val, z - _val}; }
    Vector3 operator-(const Vector3& _vector) {return {x - _vector.x, y - _vector.y, z - _vector.z}; }
    Vector3 operator-() {return {-x, -y, -z};}

    template<class T>
    Vector3 operator*(const T& _val) { return {x * _val, y * _val, z * _val}; }
    Vector3 operator*(const Vector3& _vector) {return{x * _vector.x, y * _vector.y, z * _vector.z}; }

    template<class T>
    Vector3 operator/(const T& _val) { return {x / _val, y / _val, z / _val}; }
    Vector3 operator/(const Vector3& _vector) {return{x / _vector.x, y / _vector.y, z / _vector.z}; }
};
