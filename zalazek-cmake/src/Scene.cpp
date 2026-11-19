#include "../inc/Scene.hh"

#include <iostream>

bool Scene::AddGeomObj(const std::string& ObjName) {
    // Sprawdzenie, czy obiekt już istnieje w mapie sceny
    if (this->find(ObjName) != this->end()) {
        std::cerr << "Blad: Obiekt o nazwie '" << ObjName << "' juz istnieje na scenie." << std::endl;
        return false;
    }
    
    // Utworzenie nowego obiektu i nadanie mu nazwy
    std::shared_ptr<GeomObject> newObj = std::make_shared<GeomObject>();
    newObj->SetName(ObjName);
    
    // Dodanie do mapy
    this->insert({ObjName, newObj});
    return true;
}

std::shared_ptr<GeomObject> Scene::FindGeomObj(const std::string& ObjName) {
    std::map<std::string, std::shared_ptr<GeomObject>>::iterator it = this->find(ObjName);
    if (it == this->end()) {
        return nullptr; 
    }
    return it->second;
}
