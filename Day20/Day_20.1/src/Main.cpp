#include<iostream>
#include<string>
using namespace std;
class Exception
{
private:
	string message;
public:
	Exception( string message = " " ) throw( ) : message( message )
	{	}
	string getMessage( void )const throw( )
	{
		return this->message;
	}
};
class Iterator; //Forward Declaration
class LinkedList;	//Forward Declaration
class Node
{
private:
	int data;
	Node *next;
public:
	Node( int data = 0 )throw( )
	{
		this->data = data;
		this->next = NULL;
	}
	friend class Iterator;
	friend class LinkedList;
};
class Iterator
{
private:
	Node *trav;
public:
	Iterator( Node *node )throw( )
	{
		this->trav = node;
	}
	bool operator!=( Iterator &other )const throw( )
	{
		return this->trav != other.trav;
	}
	int operator*( void )const throw( )
	{
		return this->trav->data;
	}
	void operator++( void )
	{
		this->trav = this->trav->next;
	}
};
class LinkedList
{
private:
	Node *head;
	Node *tail;
public:
	LinkedList( void ) : head( NULL ), tail( NULL )
	{	}
	bool empty( void )const throw( )
	{
		return this->head == NULL;
	}
	void addLast( int data )throw( bad_alloc )
	{
		Node *newNode = new Node( data );
		if( this->empty( ) )
			this->head = newNode;
		else
			this->tail->next = newNode;
		this->tail = newNode;
	}
	/*void printList( void )const throw( Exception )
	{
		if( this->empty() )
			throw Exception("Linked List is empty.");
		Node *trav = this->head;
		while( trav != NULL )
		{
			cout<<trav->data<<"	";
			trav = trav->next;
		}
		cout<<endl;
	}*/
	void removeFirst( void  )throw( Exception )
	{
		if( this->empty() )
			throw Exception("Linked List is empty.");
		else if( this->head == this->tail )
		{
			delete this->head;
			this->head = this->tail = NULL;
		}
		else
		{
			Node *ptrNode = this->head;
			this->head = this->head->next;
			delete ptrNode;
		}
	}
	Iterator begin( void )
	{
		Iterator itr( this->head );
		return itr;
	}
	Iterator end( void )
	{
		Iterator itr( NULL );
		return itr;
	}
	~LinkedList( void )
	{
		while( !this->empty())
			this->removeFirst();
	}
};
int main( void )
{
	LinkedList list;
	list.addLast( 10 );
	list.addLast( 20 );
	list.addLast( 30 );

	Iterator itrStart =  list.begin();
	Iterator itrEnd =  list.end();
	while( itrStart != itrEnd ) //itrStart.opeartor*( );
	{
		cout<<(*itrStart)<<"	"; //operator<<(cout,itrStart);
		++ itrStart; //itrStart.operator++( );
	}
	cout<<endl;
	return 0;
}
