int Length( List L )
{
	int len = 0;
	PtrToLNode p;
	if( L == NULL )
		return len;
	p = L;
	while( p != NULL )
	{
		p = p->Next;
		len++;
	}
	return len;
}