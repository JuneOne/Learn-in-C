void InorderTraversal( BinTree BT )
{
	if( BT )
	{
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);		
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal( BinTree BT )
{
	if( BT )
	{
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);		
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal( BinTree BT )
{
	if( BT )
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

void LevelorderTraversal( BinTree BT )
{
	BinTree queue[100];
	BinTree temp;
	int rear, front;
	rear = front = 0;
	if( !BT )
		return;
	queue[++rear] = BT;
	while( (rear % 100 ) != front )
	{
		temp = queue[(++front) % 100];
		printf(" %c", temp->Data);
		if( temp->Left != NULL )
			queue[(++rear) % 100] = temp->Left;
		if( temp->Right != NULL )
			queue[(++rear) % 100] = temp->Right;
	}
}