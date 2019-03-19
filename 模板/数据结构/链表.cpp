struct Node{
	int value;
	Node *prev,*next;
};

Node *head,*tail;

inline void initialize();				//�¼�����
inline void insert(Node *p,int val);	//�� P ������������valֵ
inline void remove(Node *p);			//ɾ�� P 
inline void recycle();					//�����ڴ���� 

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