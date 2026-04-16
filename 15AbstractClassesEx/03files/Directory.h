// Directory.h
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <memory>
#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
private:
    std::vector<std::shared_ptr<FileSystemObject>> children;

public:
    // Constructor
    Directory(std::string name)
        : FileSystemObject(name) {
    }

    void add(const std::shared_ptr<FileSystemObject>& obj) override {
        children.push_back(obj);
    }

    size_t getSize() const override {
        size_t totalSize = 0;
        for (const auto& child : children) {
            totalSize += child->getSize();
        }
        return totalSize;
    }
};

#endif // DIRECTORY_H