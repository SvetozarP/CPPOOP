// Explorer.h
#ifndef EXPLORER_H
#define EXPLORER_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "File.h"
#include "Directory.h"
#include "Shortcuts.h"

class Explorer {
private:
    std::shared_ptr<Directory> currentDirectory;
    std::vector<std::shared_ptr<FileSystemObject>> clipboard;

    std::shared_ptr<Shortcuts> shortcutsContainer;

    std::vector<std::shared_ptr<FileSystemObject>>& globalRootObjects;

    std::shared_ptr<FileSystemObject> findObjectInContainer(
        const std::shared_ptr<FileSystemObjectsContainer>& container, const std::string& name) const
    {
        for (const auto& obj : *container) {
            if (obj->getName() == name) {
                return obj;
            }
        }
        return nullptr;
    }

    std::shared_ptr<FileSystemObject> findObjectInGlobalRoots(const std::string& name) const {
        for (const auto& obj : globalRootObjects) {
            if ((!shortcutsContainer || obj != shortcutsContainer) && obj->getName() == name) {
                return obj;
            }
        }
        return nullptr;
    }

    void removeObjectFromGlobalRoots(std::shared_ptr<FileSystemObject> obj) {
        globalRootObjects.erase(std::remove(globalRootObjects.begin(), globalRootObjects.end(), obj), globalRootObjects.end());
    }

    void addObjectToGlobalRoots(std::shared_ptr<FileSystemObject> obj) {
        globalRootObjects.push_back(obj);
    }


public:
    Explorer(std::vector<std::shared_ptr<FileSystemObject>>& initialGlobalRootObjects)
        : globalRootObjects(initialGlobalRootObjects) // Initialize reference to main's root vector
    {
    }


    void createFile(const std::string& filename, const std::string& contents) {
        std::shared_ptr<File> newFile = std::make_shared<File>(filename, contents);
        if (currentDirectory) {
            currentDirectory->add(newFile);
            newFile->setParent(currentDirectory);
        }
        else {
            addObjectToGlobalRoots(newFile);
            newFile->setParent(std::weak_ptr<FileSystemObject>());
        }
    }

    void createDirectory(const std::string& directoryName) {
        std::shared_ptr<Directory> newDirectory = std::make_shared<Directory>(directoryName);
        if (currentDirectory) {
            currentDirectory->add(newDirectory);
            newDirectory->setParent(currentDirectory);
        }
        else {
            addObjectToGlobalRoots(newDirectory);
            newDirectory->setParent(std::weak_ptr<FileSystemObject>());
        }
    }

    void cut(const std::string& name) {
        std::shared_ptr<FileSystemObject> objToCut = nullptr;

        if (currentDirectory) {
            objToCut = findObjectInContainer(currentDirectory, name);
        }
        else {
            objToCut = findObjectInGlobalRoots(name);
        }

        if (objToCut) {
            clipboard.push_back(objToCut);
        }
    }

    void paste() {
        for (const auto& obj : clipboard) {
            std::shared_ptr<FileSystemObject> oldParent = obj->getParent().lock();
            if (oldParent) {
                std::shared_ptr<FileSystemObjectsContainer> oldContainer =
                    std::dynamic_pointer_cast<FileSystemObjectsContainer>(oldParent);
                if (oldContainer) {
                    oldContainer->remove(obj);
                }
            }
            else {
                removeObjectFromGlobalRoots(obj);
            }

            if (currentDirectory) {
                currentDirectory->add(obj);
                obj->setParent(currentDirectory);
            }
            else {
                addObjectToGlobalRoots(obj);
                obj->setParent(std::weak_ptr<FileSystemObject>());
            }
        }
        clipboard.clear();
    }

    void createShortcut(const std::string& name) {
        if (!shortcutsContainer) {
            shortcutsContainer = std::make_shared<Shortcuts>();
            addObjectToGlobalRoots(shortcutsContainer);
        }

        std::shared_ptr<FileSystemObject> objToShortcut = nullptr;

        if (currentDirectory) {
            objToShortcut = findObjectInContainer(currentDirectory, name);
        }
        else {
            objToShortcut = findObjectInGlobalRoots(name);
        }

        if (objToShortcut) {
            shortcutsContainer->add(objToShortcut);
        }
    }

    void navigate(const std::string& path) {
        if (path == "..") {
            if (currentDirectory) {
                std::shared_ptr<FileSystemObject> parentOfCurrent = currentDirectory->getParent().lock();
                if (parentOfCurrent) {
                    std::shared_ptr<Directory> parentDir = std::dynamic_pointer_cast<Directory>(parentOfCurrent);
                    currentDirectory = parentDir;
                }
                else {
                    currentDirectory = nullptr;
                }
            }
        }
        else {
            std::shared_ptr<FileSystemObject> target = nullptr;

            if (currentDirectory) {
                target = findObjectInContainer(currentDirectory, path);
            }
            else {
                target = findObjectInGlobalRoots(path);
            }

            std::shared_ptr<Directory> targetDir = std::dynamic_pointer_cast<Directory>(target);
            if (targetDir) {
                currentDirectory = targetDir;
            }
        }
    }
};

#endif // EXPLORER_H