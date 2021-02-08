# include "Tree.hpp"

/*
 * the parent cleans up all of its children
 */

int main()
{

	std::cout << std::endl << "Tree" << std::endl << std::endl;
	{

		Tree<int> *tree1 = new Tree<int>(1);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree<int> *tree2 = new Tree<int>(2);
		tree1->addChild(tree2);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree<int> *tree3 = new Tree<int>(3);
		tree2->addChild(tree3);
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		Tree<int> *tree4 = new Tree<int>(4);
		tree2->addChild(tree4);
		tree4->addChild(new Tree<int>(5, new Tree<int>(6, new Tree<int>(7))));
		std::cout << "heightTree : " << heightTree(tree1) << std::endl;

		tree2->addChild(new Tree<int>(8));
		tree2->addChild(new Tree<int>(9));
		tree2->addChild(new Tree<int>(10));
		tree2->addChild(new Tree<int>(11));
		tree2->addChild(new Tree<int>(12));
		tree2->addChild(new Tree<int>(13));

		Tree<std::string> stringTree("parent", new Tree<std::string>("child1", new Tree<std::string>("child2", new Tree<std::string>("child3"))));

		Tree<int> newTree(1);
		newTree = *tree1;

		Tree<int> *copyTree = new Tree<int>(newTree);

		delete copyTree;
		delete tree1;
	}

	return (0);
}
