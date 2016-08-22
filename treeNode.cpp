#include "object.h"
#include "varraylist.h"
#include "treeNode.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

TreeNode::TreeNode(Object* data, string label, TreeNode* parent, int depth):data(data), label(label), parent(parent), depth(depth){
    children = new VArrayList(0.5);
}
TreeNode::TreeNode(Object* data, string label):data(data), label(label), parent(NULL), index(0), depth(0){
    children = new VArrayList(0.5);
}
TreeNode::TreeNode(string label):data(NULL), label(label), parent(NULL), index(0), depth(0){
    children = new VArrayList(0.5); 
}
TreeNode::TreeNode(string label, TreeNode* parent):data(NULL), label(label), parent(parent), index(0), depth(0){
    children = new VArrayList(0.5); 
}

Object* TreeNode::getData() {
    return this->data; 
}
VArrayList* TreeNode::getChildren() {
    return this->children;    
}

TreeNode* TreeNode::getLeftSon() {
    if (this->children->size() == 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->children->get(0));
}
TreeNode* TreeNode::getRigthSon() {
    if (this->children->size() == 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->children->last());

}
TreeNode* TreeNode::getRigthBrother() {
    int rightIndex = this->index + 1;
    if (rightIndex > this->parent->getChildCount()) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->parent->children->get(rightIndex));
}     
TreeNode* TreeNode::getLeftBrother() {
    int rightIndex = this->index - 1;
    if (rightIndex < 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->parent->children->get(rightIndex));
}
void TreeNode::addSon(TreeNode* newSon) {
    newSon->setIndex(this->getChildCount());
    newSon->setParent(this);
    newSon->depth = this->depth + 1;
    this->children->insert(newSon, this->children->size());
}
int TreeNode::getChildCount() {
    return this->children->size();
}
int TreeNode::getIndex() {
    return this->index;
}
int TreeNode::getDepth() {
    if (this->parent == NULL)
        return 0;
    return this->parent->getDepth() + 1;
}
void TreeNode::setIndex(int index) {
    this->index = index;
}
void TreeNode::setParent(TreeNode* parent) {
    this->parent = parent;
}
TreeNode* TreeNode::getSon(int pos) {
    return static_cast<TreeNode*> (this->children->get(pos));
}


string TreeNode::toString(){
    stringstream ss;
    TreeNode* temp = this->parent;
    for (int i = 0; i < this->getDepth(); i++) {
        if (i == this->getDepth() - 1) {
            ss << "|-----";
        } else {
            ss << "|\t";
        }
    }

    ss << "-> " << this->label << endl;
    for (int i = 0; i < this->getChildCount(); i++) {
        ss << this->getSon(i)->toString();
    }
    return ss.str();
}