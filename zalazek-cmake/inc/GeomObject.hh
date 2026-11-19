#ifndef GEOMOBJECT_HH
#define GEOMOBJECT_HH

#include <string>
#include "g3dVector.hh" 

typedef g3d::Vector Vector3D;

class GeomObject {
private:
    Vector3D _Pos_m;
    std::string _Name;

public:
    GeomObject() = default;
    ~GeomObject() = default;

    const std::string& GetName() const;
    void SetName(const std::string& Name);
    
    const Vector3D& GetPos_m() const;
    Vector3D& ModPos_m(int X, int Y, int Z);

    Vector3D& SetPos_m(int X, int Y, int Z);
};

#endif