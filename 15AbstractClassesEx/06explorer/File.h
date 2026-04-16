// File.h
#ifndef FILE_H
#define FILE_H

#include <string>
#include <memory>
#include "FileSystemObject.h"
#include "ByteContainer.h"

class File : public FileSystemObject, public ByteContainer {
private:
    std::string contents;

public:
    File(std::string name, std::string contents)
        : FileSystemObject(name), contents(contents) {
    }

    std::string getBytes() const override {
        return this->contents;
    }

    size_t getSize() const override {
        return this->contents.length();
    }
};

#endif // FILE_H