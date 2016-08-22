#include "object.h"
#include "tree.h"
#include "treeNode.h"
#include <iostream>
#include <string>
#include <fstream>	

using namespace std;

Tree* getStudentsFile();

int main(int argc, char const *argv[]){
	/* code */
	Tree* organigrama = getStudentsFile();
	cout << "-------------------------------------------------------" << endl;
	cout << "                     ORGANIGRAMA                       " << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << organigrama->toString();
	return 0;
}


Tree* getStudentsFile() {
	ifstream treeFile;
	string texto;
	TreeNode* root;
	TreeNode* neo;
	VArrayList* temp = new VArrayList(0.5);
	if(ifstream("organigrama.txt")){
	    fstream treeFile("organigrama.txt");
	    string line;
	    int total = 0;
	    while(getline(treeFile, line)) {
	    	if (total == 0) {
	    		root = new TreeNode(line, NULL);
	    		total++;
	    	} else {
				int pos = 0;
				while (line.at(pos) == '\t') {
					pos++;
				}
				if (pos == 1) {
					TreeNode* nearestSon = new TreeNode(line.substr(pos, line.size()));
					root->addSon(nearestSon);
					temp->clear();
					temp->insert(nearestSon, 0);
				} else {
					neo = new TreeNode(line.substr(pos, line.size()));
					if (pos >= temp->size()) {
						temp->insert(neo, pos - 1);
					} else {
						temp->remove(pos - 1);
						temp->insert(neo, pos - 1);
					}
					static_cast<TreeNode*> (temp->get(pos - 2))->addSon(neo);
				}
			}
			treeFile.clear();
	    }
	}
	// cout << root->toString();
	Tree* myTree = new Tree(root);
	return myTree;
}