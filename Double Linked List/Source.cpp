#include<iostream>
using namespace std;
class Doublelinkedlist {
	struct node {
		int date;
		node* next;
		node* prv;
		node() {
			next = NULL;
			prv = NULL;
		}
	};
	node* head = NULL;
public:
	void append(int val) {
		node* k = new node;
		k->date = val;
		if (head == NULL) {
			head = k;
		}
	
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = k;
		}

	}
	void insert_at_pos(int val, int pos) {
		node* k = new node;
		k->date = val;
		k->next = NULL;
		if (head == NULL) {
			head = k;
			return;
		}
		if (pos == 0) {
			k->next = head;
			head->prv = k;
			k = head;
			return;
		}
		node* temp = head;
		for (int i = 1; i <= pos && temp != NULL; i++) {
			temp = temp->next;
			if (temp == NULL) {
				this->append(val);
				return;
			}
			k->prv = temp->prv;
			temp->next->prv = k;
			temp->prv = k;
			k->next = temp;

		}


	}
	void remove(int val) {
		if (head == NULL) {
			return;
		}
		node* temp = head;
		if (temp->date == val) {
			head = temp->next;
			if (head != NULL) 
				head->prv = NULL;
				delete temp;
				return;
			}
		while (temp != NULL && temp->date == val) {
			temp = temp->next;
		}
		if (temp == NULL) {
			return;
		}
		else {
			temp->prv->next = temp->next;
		//	if(temp->next!=NULL)
			temp->next->prv = temp->prv;
			delete temp;
		}



	}
	void remove_at_pos(int val) {
		if (head == NULL) {
			return;
		}
		node* temp = head;
		while (temp->next->next != NULL)
			temp = temp->next;
		int p = temp->next->date;
		delete temp->next;
		temp->next = NULL;




	
	}
};
int main() {






	return 0;
}