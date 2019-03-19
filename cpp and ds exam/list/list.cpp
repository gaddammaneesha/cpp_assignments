#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class list
{
public:
	struct node *start;
	list()
	{
		start = NULL;
	}
	void insert(int el);
	void insert_pos(int pos, int el);
	void reverse();
	void forward();
	friend void print(struct node*);
	void backward()
	{
		if (start != NULL)
			print(start);
	}
	void delete_el(int el);
};
void list::insert(int el)
{
	struct node *temp = new struct node;
	struct node *curr;
	temp->data = el;
	temp->next = NULL;
	if (start == NULL)	//insert at beginning
	{
		start = temp;
	}
	else
	{
		//adding to the list
	}
	{
		curr = start;
		while (curr ->next!= NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void list::insert_pos(int pos, int e1)
{
	struct node *elem=new node;
	struct node*temp;
	elem->data = e1;
	int count = 0;
	if (pos == 0&&start==NULL)	//starting position and list is empty
	{
		start = elem;
		elem->next = NULL;
	}
	else if(pos==0) //starting position and list contain some elements
	{
		elem->next = start;
		start = elem;
	}
	else
	{
		temp = start;
		while (temp->next != NULL && (count + 1) != pos)
		{
			temp = temp->next;
			count++;

		}
		if (temp->next != NULL) //position found and didnt reached end
		{
			elem->next = temp->next;
			temp->next = elem;
		}
		if (temp->next == NULL&&(count + 1) == pos)	//position found and reached end
		{
			temp->next = elem;
			elem->next = NULL;
		}
	}
}
void list::delete_el(int el)
{
	struct node *temp=NULL ,*curr;
	if(start==NULL)
		cout << "list is empty\n";
	else
	{
		curr = start;
		while (curr->next != NULL&&curr->next->data != el) //peeking to the nodes
			curr = curr->next;
		if (curr->next != NULL)	//if element is found 
		{
			temp = curr->next;
			curr->next = temp->next;
			delete temp;
		}
		else
			cout << "element not found\n";
	}
}
void list::reverse()
{
	struct node *temp, *rev = NULL;
	if(start==NULL)
		cout << "list is empty\n";
	else
	{
		while (start != NULL)	//if list is not empty
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
}
void list::forward()
{
	struct node *temp;
	if(start==NULL)
		cout << "list is empty\n";
	else
	{					//if list is not empty
		temp = start;
		while (temp != NULL)
		{
			cout << temp->data<<"\n";
			temp = temp->next;
		}
	}
}
void print(struct node *curr)
{
	if (curr != NULL)		
	{
		print(curr->next);		//looping to the last element 
		cout << curr->data<<"\n";
	}
}
int main()
{
	list l;
	int ch,el,pos;
	while (1)
	{
		cout<<"0 insert elem 1 insert at pos 2 delete 3 reverse 4 forward 5 backward\n";
		cin >> ch;
		switch (ch)
		{
			case 0:cout << "enter element to be inserted\n";
			cin >> el;
			l.insert(el);
			break;
		case 1:cout<<"enter element to be inserted\n";
			cin>>el;
			cout<<"enter position\n";
			cin>> pos;
			l.insert_pos(pos,el);
			break;
		case 2:cout<<"enter element to be deleted\n";
			cin>>el;
			l.delete_el(el);
			break;
		case 3:l.reverse();
			break;

		case 4:cout<<"elements displayed in forward direction are\n";
			l.forward();
			break;
		case 5:cout<<"elements displayed in backward direction are\n";
			l.backward();
			break;
		default:cout<<"invalid coice\n";
		}
	}
	getchar();
	return 0;
}