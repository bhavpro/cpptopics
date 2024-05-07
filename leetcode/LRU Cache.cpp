#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

#define pii pair<int, int>

struct node
{
	pair<int, int> val;
	node *frwd;
	node *rev;

	node()
	{
		frwd = rev = NULL;
	}

	node(pii val) : val(val)
	{
		frwd = rev = NULL;
	}

	node(pii val, node *frwd, node *rev) : val(val)
	{
		this->frwd = frwd;
		this->rev = rev;
	}
};

struct dell
{
	int n;
	node *front;
	node *back;
	dell()
	{
		n = 0;
		back = front = NULL;
	}

	void push_front(pii p)
	{
		n++;
		node *nnode = new node(p);
		if (front == NULL && back == NULL)
		{
			front = back = nnode;
			return;
		}
		front->frwd = nnode;
		nnode->rev = front;
		front = nnode;
	}

	void erase(node *n)
	{
		if (front == NULL)
			return;
		// n is froont
		if (n == front)
		{
			this->n--;
			front = front->rev;
			delete n;
			if (this->n == 0)
				front = back = NULL;
			return;
		}

		// n is back
		if (n == back)
		{
			this->n--;
			back = back->frwd;
			delete n;
			if (this->n == 0)
				front = back = NULL;
			return;
		}

		this->n--;
		node *prev = n->frwd;
		node *next = n->rev;
		prev->rev = next;
		next->frwd = prev;
		if (this->n == 0)
			front = back = NULL;
		delete n;
	}

	node *begin()
	{
		return front;
	}

	int size()
	{
		return n;
	}

	node *getback()
	{
		return back;
	}

	void pop_back()
	{
		if (back == NULL)
			return;

		n--;
		node *temp = back;
		back = back->frwd;
		delete temp;
		if (n == 0)
		{
			front = NULL;
			back = NULL;
		}
	}

	void movetofront(node *n)
	{
		if(front == NULL)
		return;
		// n is front
		if(front == n)
		{
			return;
		}
		if(back == n)
		{
			back = back->frwd;
			back->rev = NULL;
			front->frwd = n;
			n->rev = front;
			front = n;
			return;
		}

		n->frwd->rev = n->rev;
		n->rev->frwd = n->frwd;
		front->frwd = n;
		n->rev = front;
		n->frwd = NULL;
		front = n;
	}
};

class LRUCache
{
	dell ll;
	unordered_map<int, node *> m;
	int capacity;

public:
	LRUCache(int capacity) : capacity(capacity)
	{
	}

	int get(int key)
	{
		if (m.count(key))
		{
			node *ptr = m[key];
			ll.movetofront(ptr);
			return m[key]->val.second;
		}
		return -1;
	}

	void put(int key, int value)
	{
		pii ins = {key, value};
		if (m.count(key))
		{
			node *ptr = m[key];
			ll.movetofront(ptr);
			ptr->val.second = value;
			return;

		}

		if (ll.size() == capacity)
		{

			m.erase(ll.getback()->val.first);
			ll.pop_back();
		}

		ll.push_front(ins);
		m[key] = ll.begin();
		
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */