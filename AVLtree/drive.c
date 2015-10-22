#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "AVLtree.h"

int main()
{
	AVLTree();
 
  /* Constructing tree given in the above figure */
  insertAVL(10);
 insertAVL(20);
  insertAVL(30);
  insertAVL(40);
  insertAVL(50);
  insertAVL(25);

  printAVL();
  printf("%d\n",countAVL());
  printf("%d\n",searchAVL(1));
	return 0;
}