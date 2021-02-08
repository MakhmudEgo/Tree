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
	: _data(index), _parent(this)
	{}
	explicit Tree(const T& index, Tree *child)
	: _data(index), _parent(this)
	{
		if (child)
		{
			this->_children.push_back(child);
			child->_parent = this;
		}
	}
	explicit Tree(const T& index, Tree *child, Tree *parent)
	: _data(index), _parent(parent)
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
			std::cout << this->_data << " parent dead :(" << std::endl;
		}
		else
		{
			std::cout << this->_data << " child dead :(" << std::endl;
		}
	}

	//getters
	const T& getData() const
	{
		return (this->_data);
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
		this->_data = index;
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
	T _data;
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
			this->_data = tree._data;
		}
		for (size_t i = 0; i < tree._children.size(); ++i)
		{
			Tree *top = new Tree(tree._children[i]->_data, nullptr, parent);
			if (!tree._children[i]->_children.empty())
			{
				copyTree(*tree._children[i], top);
			}
		}
	}
};

template<class T>
int heightTree(const Tree<T>& tree)
{
	int height = 1;
	for (size_t i = 0; i < tree.getChildren().size(); ++i)
	{
		height = 1 + heightTree(*tree.getChildren()[i]);
	}
	return (height);
}

template<class T>
void printTree(const Tree<T> &tree)
{
	std::cout << tree.getData() << std::endl;
	for (size_t i = 0; i < tree.getChildren().size(); ++i)
	{
		printTree(*tree.getChildren()[i]);
	}
}

#endif //TREE_HPP
