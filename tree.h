#pragma once


#include "object.h"
#include "treeNode.h"
#include <sstream>
#include <string>

class Tree : public Object{
    private:
        TreeNode* root;
    public:
        Tree(TreeNode*);
        TreeNode* getRoot();
        void setRoot(TreeNode*);
        string toString()const;
};