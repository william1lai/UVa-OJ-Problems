#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct BlockChain
{
	int blockAbove; //-1 if none
	int stackNum;
};

inline void empty(BlockChain* blocks, int base)
{
	//Take blocks off of base
	int curr = blocks[base].blockAbove;
	blocks[base].blockAbove = -1;
	blocks[curr].stackNum = curr;
	int temp = blocks[curr].blockAbove;
	while (temp != -1)
	{
		blocks[curr].blockAbove = -1;
		blocks[temp].stackNum = temp;
		curr = temp;
		temp = blocks[curr].blockAbove;
	}
}

inline void updateChain(BlockChain* blocks, int base, int value)
{
	blocks[base].stackNum = value;
	int curr = blocks[base].blockAbove;
	while (curr != -1)
	{
		blocks[curr].stackNum = value;
		curr = blocks[curr].blockAbove;
	}

}

inline int findTopBlock(BlockChain* blocks, int base)
{
	int curr = base;
	while (blocks[curr].blockAbove != -1)
	{
		curr = blocks[curr].blockAbove;
	}
	return curr;
}

inline void print(BlockChain* blocks, int numBlocks)
{
	for (int i = 0; i < numBlocks; i++)
	{
		cout << i << ":";
		if (blocks[i].stackNum == i)
		{
			int curr = i;
			while (curr != -1)
			{
				cout << " " << curr;
				curr = blocks[curr].blockAbove;
			}
		}
		cout << endl;
	}
}

int main()
{
	int numBlocks;
	cin >> numBlocks;
	cin.ignore(1000, '\n');

	BlockChain* blocks = new BlockChain[numBlocks];

	for (int i = 0; i < numBlocks; i++)
	{
		blocks[i].blockAbove = -1;
		blocks[i].stackNum = i;
	}

	string firstWord;
	string secondWord;
	int firstBlk;
	int secondBlk;
	string line;

	while (getline(cin, line))
	{	
		stringstream ss(line);

		ss >> firstWord;
		if (firstWord == "quit") break;
		ss >> firstBlk >> secondWord >> secondBlk; 

		if (blocks[secondBlk].stackNum == blocks[firstBlk].stackNum) continue;

		if (firstWord == "pile") //this is inefficient somehow
		{
			//find element below, so we can update
			int curr = blocks[firstBlk].stackNum;
			int t = blocks[curr].blockAbove;
			while (t != firstBlk && t != -1)
			{
				curr = blocks[curr].blockAbove;
				t = curr;
			}
			blocks[curr].blockAbove = -1;
			blocks[firstBlk].stackNum = secondBlk;

			if (secondWord == "onto")
			{
				if (blocks[secondBlk].blockAbove != -1)
					empty(blocks, secondBlk);

				//place a onto b
				blocks[secondBlk].blockAbove = firstBlk;
				updateChain(blocks, firstBlk, secondBlk);
			}
			else if (secondWord == "over")
			{
				int curr = findTopBlock(blocks, secondBlk);
				blocks[curr].blockAbove = firstBlk;
			}
		}
		else if (firstWord == "move")
		{
			if (blocks[firstBlk].blockAbove != -1)
				empty(blocks, firstBlk);

			//find element below, so we can update
			int curr = blocks[firstBlk].stackNum;
			int t = blocks[curr].blockAbove;
			while (t != firstBlk && t != -1)
			{
				curr = blocks[curr].blockAbove;
				t = curr;
			}
			blocks[curr].blockAbove = -1;
			blocks[firstBlk].stackNum = secondBlk;

			if (secondWord == "onto")
			{
				if (blocks[secondBlk].blockAbove != -1)
					empty(blocks, secondBlk);

				blocks[secondBlk].blockAbove = firstBlk;
			}
			else if (secondWord == "over")
			{
				int top = findTopBlock(blocks, secondBlk);
				blocks[top].blockAbove = firstBlk;
			}
		}
	}

	print(blocks, numBlocks);	
}