#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct BlockChain
{
	BlockChain* blockAbove; //null if none
	int stackNum;
	int val;
};

inline void empty(BlockChain blocks[], int base)
{
	//Take blocks off of base
	BlockChain* curr = &blocks[base];
	BlockChain* next = curr->blockAbove;
	curr->blockAbove = NULL;
	//curr->stackNum = curr->val;
	curr = next;
	while (curr != NULL)
	{
		curr->stackNum = curr->val;
		next = curr->blockAbove;
		curr->blockAbove = NULL;
		curr = next;
	}
}

inline void updateChain(BlockChain blocks[], int base, int value)
{
	blocks[base].stackNum = value;
	BlockChain* curr = blocks[base].blockAbove;
	while (curr != NULL)
	{
		curr->stackNum = value;
		curr = curr->blockAbove;
	}
}

inline BlockChain* findTopBlock(BlockChain blocks[], int base)
{
	BlockChain* curr = &blocks[base];
	while (curr->blockAbove != NULL)
	{
		curr = curr->blockAbove;
	}
	return curr;
}

inline void print(BlockChain blocks[], int numBlocks)
{
	for (int i = 0; i < numBlocks; i++)
	{
		cout << i << ":";
		if (blocks[i].stackNum == i)
		{
			BlockChain* curr = &blocks[i];
			while (curr != NULL)
			{
				cout << " " << curr->val;
				curr = curr->blockAbove;
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

	const int MAX_BLOCKS = 25;
	BlockChain blocks[MAX_BLOCKS];

	for (int i = 0; i < numBlocks; i++)
	{
		blocks[i].blockAbove = NULL;
		blocks[i].stackNum = i;
		blocks[i].val = i;
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

		BlockChain* f = &blocks[firstBlk];
		BlockChain* s = &blocks[secondBlk];

		if (firstWord == "pile")
		{
			//find element below, so we can update
			int curr = f->stackNum;
			BlockChain* t = &blocks[curr];
			while (t != NULL && t->blockAbove != f)
			{
				t = t->blockAbove;
			}
			if (t != NULL)	t->blockAbove = NULL;
			int bot = s->stackNum;
			f->stackNum = bot;

			if (secondWord == "onto")
			{
				if (s->blockAbove != NULL)
					empty(blocks, secondBlk);

				//place a onto b
				s->blockAbove = f;
				updateChain(blocks, firstBlk, bot);
			}
			else if (secondWord == "over")
			{
				BlockChain* curr = findTopBlock(blocks, secondBlk);
				curr->blockAbove = f;
				updateChain(blocks, firstBlk, bot);
			}
		}
		else if (firstWord == "move")
		{
			if (f->blockAbove != NULL)
				empty(blocks, firstBlk);

			//find element below, so we can update
			int curr = f->stackNum;
			BlockChain* t = &blocks[curr];
			while (t != NULL && t->blockAbove != f)
			{
				t = t->blockAbove;
			}
			if (t != NULL)	t->blockAbove = NULL;
			f->stackNum = s->stackNum;

			if (secondWord == "onto")
			{
				if (s->blockAbove != NULL)
					empty(blocks, secondBlk);

				s->blockAbove = f;
			}
			else if (secondWord == "over")
			{
				BlockChain* top = findTopBlock(blocks, secondBlk);
				top->blockAbove = f;
			}
		}
		//print(blocks, numBlocks);
	}

	print(blocks, numBlocks);	
}