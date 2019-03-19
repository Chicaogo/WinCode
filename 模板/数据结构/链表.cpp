struct Node{
	int value;
	Node *prev,*next;
};

Node *head,*tail;

inline void initialize();				//新键链表
inline void insert(Node *p,int val);	//在 P 后面增加数据val值
inline void remove(Node *p);			//删除 P 
inline void recycle();					//链表内存回收 

inline void initialize()
{
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

inline void insert(Node *p,int val)
{
	Node *q = new Node();
	q->value = val;
	p->next->prev = q;
	q->next = p->next;
	p->next = q;
	q->prev = p;
}

inline void remove(Node *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

inline void recycle()
{
	while (head != tail)
	{
		head = head->next;
		delete head->prev;
	}
	delete tail;
}