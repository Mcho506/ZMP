#include "../inc/GeomObject.hh"


const std::string& GeomObject::GetName() const {
    return _Name;
}

void GeomObject::SetName(const std::string& Name) {
    _Name = Name;
}

const Vector3D& GeomObject::GetPos_m() const {
    return _Pos_m;
}

Vector3D& GeomObject::ModPos_m(int X, int Y, int Z) {
    Vector3D move = Vector3D(X, Y, Z);
    return _Pos_m += move;
}
Vector3D& GeomObject::SetPos_m(int X, int Y, int Z) {
    _Pos_m = Vector3D(X, Y, Z);
    return _Pos_m;
}

const int GeomObject::GetRotation() const {
    return _Rotation;
}
int GeomObject::ModRotation(int deg) {
    return _Rotation += deg;
}