#include <cmath>
#include <iostream>
using namespace std;
template<class T>
double Length(const pair<T, T>& vec) 
{
    return sqrt(vec.first * vec.first + vec.second * vec.second);
}
template<class T>
struct Octagon 
{
    using vertex_t = pair<T, T>;
    using vector_t = pair<T, T>;
    Octagon() = default;
    ~Octagon() = default;
    Octagon(const vertex_t& vx, const vector_t& vec) : vec(vec), vx(vx) 
    {
        square = 4.0 * sin(acos(-1) / 4.0) * Length(vec) * Length(vec);
    }
    void print() const 
    {
        cout << "Centre: (" << vx.first << ", " << vx.second << "), ";
        cout << "vector R is circumscribed circle: (" << vec.first << ", " << vec.second << "), ";
        cout << "S = " << square << endl;
    }
    vertex_t vec;
    vector_t vx;
    double square;
};