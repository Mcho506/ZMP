#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <string>
#include <memory>
#include "GeomObject.hh"

class Scene : public std::map<std::string, std::shared_ptr<GeomObject>> {
public:
    Scene() = default;
    ~Scene() = default;

    bool AddGeomObj(const std::string& ObjName);
    std::shared_ptr<GeomObject> FindGeomObj(const std::string& ObjName);
};

#endif // SCENE_HH