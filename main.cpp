
#include <algorithm>
#include <stack>
#include <queue>

# include "Tree.hpp"

/*
 * the parent cleans up all of its children
 */

int main()
{

	std::cout << std::endl << "Tree" << std::endl << std::endl;
	{

		Tree *tree1 = new Tree(1);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree *tree2 = new Tree(2);
		tree1->addChild(tree2);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree *tree3 = new Tree(3);
		tree2->addChild(tree3);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree *tree4 = new Tree(4);
		tree2->addChild(tree4);
		tree4->addChild(new Tree(5, new Tree(6, new Tree(7))));
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		tree2->addChild(new Tree(8));
		tree2->addChild(new Tree(9));
		tree2->addChild(new Tree(10));
		tree2->addChild(new Tree(11));
		tree2->addChild(new Tree(12));
		tree2->addChild(new Tree(13));
		delete tree1;
	}

	return (0);
}
