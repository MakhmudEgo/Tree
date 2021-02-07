//
// Created by Mahmud Jego on 2/7/21.
//

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>

class Tree {
public:
	Tree(const int&);
	Tree(const int& index, Tree *child);
	Tree(const int& index, Tree *child, Tree *parent);
	Tree& operator=(const Tree&);
	virtual ~Tree();

	//getters
	int getIndex() const;
	const std::vector<Tree *> &getChildren() const;
	Tree *getParent() const;

	//setters
	void setIndex(int index);
	void setChildren(const std::vector<Tree *> &children);
	void setParent(Tree *parent);

	void addChild(Tree *newChild);
private:
	int _index;
	std::vector<Tree*> _children;
	Tree *_parent;

	void killChildren(Tree *parent);
};

int heightTree(const Tree *parent);

#endif //TREE_HPP
