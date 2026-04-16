// Directory.h
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
private:
    std::vector<std::shared_ptr<FileSystemObject>> children;

public:
    Directory(std::string name)
        : FileSystemObject(name) {
    }

    void add(const std::shared_ptr<FileSystemObject>& obj) override {
        children.push_back(obj);
        std::sort(children.begin(), children.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
            return a->getName() < b->getName();
            });
    }

    size_t getSize() const override {
        size_t totalSize = 0;
        for (const auto& child : children) {
            totalSize += child->getSize();
        }
        return totalSize;
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override {
        return this->children.begin();
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override {
        return this->children.end();
    }
};

#endif // DIRECTORY_H