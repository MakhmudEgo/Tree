//
// Created by Mahmud Jego on 2/7/21.
//

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>

template<class T>
class Tree {
public:
	explicit Tree(const T&index)
	: _index(index), _parent(this)
	{}
	explicit Tree(const T& index, Tree *child)
	: _index(index), _parent(this)
	{
		if (child)
		{
			this->_children.push_back(child);
			child->_parent = this;
		}
	}
	explicit Tree(const T& index, Tree *child, Tree *parent)
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
	explicit Tree(const Tree& tree)
	: _parent(this)
	{
		operator=(tree);
	}
	Tree& operator=(const Tree& tree)
	{
		if (this != &tree)
		{
			copyTree(tree, this);
		}
		return (*this);
	}
	virtual ~Tree()
	{
		if (this == this->_parent)
		{
			killChildren(this);
		}
		if (this == this->_parent)
		{
			std::cout << this->_index << " parent dead :(" << std::endl;
		}
		else
		{
			std::cout << this->_index << " child dead :(" << std::endl;
		}
	}

	//getters
	int getIndex() const
	{
		return (this->_index);
	}
	const std::vector<Tree *> &getChildren() const
	{
		return (this->_children);
	}
	Tree *getParent() const
	{
		return (this->_parent);
	}

	//setters
	void setIndex(int index)
	{
		this->_index = index;
	}
	void setChildren(const std::vector<Tree *> &children)
	{
		for (int i = 0; i < children.size(); ++i)
		{
			this->_children.push_back(children[i]);
		}
	}
	void setParent(Tree *parent)
	{
		if (parent)
		{
			this->_parent = parent;
			parent->addChild(this);
		}
	}
	void addChild(Tree *newChild)
	{
		if (newChild)
		{
			newChild->_parent = this;
			this->_children.push_back(newChild);
		}
	}

private:
	T _index;
	std::vector<Tree*> _children;
	Tree *_parent;

	void killChildren(Tree *parent)
	{
		for (size_t i = 0; i < parent->_children.size(); ++i)
		{
			if (!parent->_children.empty())
			{
				killChildren(parent->_children[i]);
			}
			delete parent->_children[i];
		}
	}
	void copyTree(const Tree& tree, Tree *parent)
	{
		if (parent == this)
		{
			this->_index = tree._index;
		}
		for (size_t i = 0; i < tree._children.size(); ++i)
		{
			Tree *top = new Tree(tree._children[i]->_index, nullptr, parent);
			if (!tree._children[i]->_children.empty())
			{
				copyTree(*tree._children[i], top);
			}
		}
	}
};

template<class T>
int heightTree(const Tree<T> *parent)
{
	int height = 1;
	for (size_t i = 0; i < parent->getChildren().size(); ++i)
	{
		height = 1 + heightTree(parent->getChildren()[i]);
	}
	return (height);
}

#endif //TREE_HPP
