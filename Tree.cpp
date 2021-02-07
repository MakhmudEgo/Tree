//
// Created by Mahmud Jego on 2/7/21.
//

#include "Tree.hpp"

Tree::Tree(const int &index)
: _index(index), _parent(nullptr)
{}

Tree::Tree(const int &index, Tree *child)
: _index(index), _parent(nullptr)
{
	if (child)
	{
		this->_children.push_back(child);
		child->_parent = this;
	}
}

Tree::Tree(const int &index, Tree *child, Tree *parent)
: _index(index), _parent(parent)
{
	if (parent)
	{
		parent->addChild(this);
	}
	if (child)
	{
		this->_children.push_back(child);
		child->_parent = this;
	}
}

void Tree::addChild(Tree *newChild)
{
	if (newChild)
	{
		newChild->_parent = this;
		this->_children.push_back(newChild);
	}
};

int Tree::getIndex() const
{
	return (this->_index);
}

const std::vector<Tree *> &Tree::getChildren() const
{
	return (this->_children);
}

Tree *Tree::getParent() const
{
	return (this->_parent);
}

void Tree::setIndex(int index)
{
	this->_index = index;
}

void Tree::setChildren(const std::vector<Tree *> &children)
{
	for (int i = 0; i < children.size(); ++i)
	{
		this->_children.push_back(children[i]);
	}
}

void Tree::setParent(Tree *parent)
{
	if (parent)
	{
		this->_parent = parent;
		parent->addChild(this);
	}
}

Tree::~Tree()
{
	if (!this->_parent)
	{
		killChildren(this);
	}
	if (!this->_parent)
	{
		std::cout << this->_index << " parent dead :(" << std::endl;
	}
	else
	{
		std::cout << this->_index << " child dead :(" << std::endl;
	}
}

void Tree::killChildren(Tree *parent)
{
	for (int i = 0; i < parent->_children.size(); ++i)
	{
		if (!parent->_children.empty())
		{
			killChildren(parent->_children[i]);
		}
		delete parent->_children[i];
	}
}

Tree &Tree::operator=(const Tree& tree)
{
	if (this == &tree) {
		return *this;
	}

	_parent = new Tree(tree._index);
	_children = tree._children;

	for (int i = 0; i < tree._children.size(); ++i) {
		_children[i] = new Tree(tree._children[i]->_index);
		*_children[i] = *(tree._children[i]);
	}

	return (*this);
}

int heightTree(const Tree *parent)
{
	int height = 1;
	for (int i = 0; i < parent->getChildren().size(); ++i)
	{
		height = 1 + heightTree(parent->getChildren()[i]);
	}
	return (height);
}