// TreeView.h
#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "Directory.h"

const std::string INDENT = "--->";

void buildTreeViewRecursive(
    std::ostringstream& oss,
    const std::shared_ptr<FileSystemObject>& currentObject,
    int depth)
{
    for (int i = 0; i < depth; ++i) {
        oss << INDENT;
    }
    oss << currentObject->getName() << std::endl;

    std::shared_ptr<FileSystemObjectsContainer> container =
        std::dynamic_pointer_cast<FileSystemObjectsContainer>(currentObject);

    if (container) {
        std::vector<std::shared_ptr<FileSystemObject>> sortedChildren;
        for (const auto& child : *container) {
            sortedChildren.push_back(child);
        }
        std::sort(sortedChildren.begin(), sortedChildren.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
            return a->getName() < b->getName();
            });

        for (const auto& child : sortedChildren) {
            buildTreeViewRecursive(oss, child, depth + 1);
        }
    }
}

std::string getTreeView(const std::vector<std::shared_ptr<FileSystemObject>>& rootObjects) {
    std::ostringstream oss;


    for (const auto& root : rootObjects) {
        buildTreeViewRecursive(oss, root, 0);
    }

    std::string result = oss.str();
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
}

#endif // TREE_VIEW_H