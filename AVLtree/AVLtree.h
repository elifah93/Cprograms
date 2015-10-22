struct node{
	int data;
	struct node* left;
	struct node* right;
	
	int height;
};

struct node* newNode(int);
void insert(struct node**, int);
void updateHeight(struct node**);
void displayRest( struct node *);
int getHeight(struct node*);
int numLeaves(struct node*);
void Balance(struct node**);
void leftRotation(struct node**);
void rightRotation(struct node**);
void rightLeftRotation(struct node**);
void leftRightRotation(struct node**);
void AVLTree();
int max(int, int);
void insertAVL();
void printAVL();
int countAVL();
int searchAVL(int);
int binaryTreeSearch(struct node*,int);

struct node* root;
int numElements=0;

struct node* newNode(int x)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data   = x;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 0;  // new node is initially added at leaf
    return(node);
}

//recursive routing for inserting
//insert x into the tree rooted at r
void insert(struct node** r, int x)
{
	if ((*r)==NULL)
		(*r)=newNode(x);
	else
	{
		if(x<(*r)->data)
			insert(&(*r)->left,x);
		else
			insert(&(*r)->right,x);

		updateHeight(r);
	}

	//check for inbalances
	Balance(&(*r));
	return;
}

//may assume r is not NULL
void updateHeight(struct node ** r)
{
	(*r)->height=1+ max(getHeight((*r)->left),getHeight((*r)->right));
}

void displayRest(struct node * r)
{
	if(r!=NULL)
	{
		printf("%d\n", r->data);
		displayRest(r->left);
		//printf("%d\n", r->data);
		displayRest(r->right);
		//printf("%d\n", r->data);
	}
	else
		return;
}
int getHeight(struct node* r)
{
	if(r==NULL)
		return -1;
	else
		return r->height;
}

int numLeaves(struct node* r)
{
	if(r==NULL)
		return 0;
	if(r->left==NULL&&r->right==NULL)
		return 1;
	else
		return numLeaves(r->left)+numLeaves(r->right);
}

void Balance(struct node** r)
{
	if(r==NULL)
		return;
	
	if(getHeight((*r)->left)-getHeight((*r)->right)>1)
	{
		if(getHeight((*r)->left->left)>=getHeight((*r)->left->right))
			rightRotation(&(*r));
		else
			leftRightRotation(&(*r));
	}

	else if(getHeight((*r)->right)-getHeight((*r)->left)>1)
	{
		if(getHeight((*r)->right->right)>=getHeight((*r)->right->left))
			leftRotation(&(*r));
		else
			rightLeftRotation(&(*r));
	}
	return;
}

void leftRotation(struct node** r)
{
	
	struct node *a =(*r);
	struct node *b=a->right;
	struct node *bl=b->left;
	(*r)=b;
	b->left=a;
	a->right=bl;
	updateHeight(&a);
	updateHeight(&b);
	return;
}
	
void rightRotation(struct node** r)
{
	struct node *a =(*r);
	struct node *b=a->left;
	struct node *br=b->right;
	(*r)=b;
	b->right=a;
	a->left=br;
	updateHeight(&a);
	updateHeight(&b);
	return;
}

void rightLeftRotation(struct node** r)
{
	rightRotation(&(*r)->right);
	leftRotation(&(*r));
	return;
}
	
void leftRightRotation(struct node** r)
{
	leftRotation(&(*r)->left);
	rightRotation(&(*r));
	return;
}
	
void AVLTree()
{
	root=NULL;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

void insertAVL(int x)
{
	insert(&root,x);
	numElements++;
}

void printAVL()
{
	displayRest(root);
}

int countAVL()
{
	return numElements;
}

int searchAVL(int x)
{
	return binaryTreeSearch(root,x);
}

int binaryTreeSearch(struct node* r,int x)
{
	if (r==NULL)
	{
		return -1;
	}	

	if (x < r->data)
		binaryTreeSearch(r->left, x);	

	else if (x > r->data)
		binaryTreeSearch(r->right, x);	
	
	else
		return r->data;
}