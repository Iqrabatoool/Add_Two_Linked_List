#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		
};
class List{
	public:
		Node *current ,*head;
		List(){
			current = NULL;
			head = NULL;
		}
		void insert(int value){
			Node *newnode = new Node();
			newnode -> data = value;
			if(current!= NULL){
				newnode ->next = current;
				current = newnode;
				current ->next = newnode->next;
			}else{
				current = newnode;
				newnode->next = NULL;
				current->next = NULL;
			}
		}
		
		void add(Node *l1, Node *l2){
			int sum =0, carry = 0;
			while(l1 != NULL || l2 != NULL || carry !=0){
				if(l1==NULL && l2 != NULL){
					l1 = new Node();
					l1->data =0;
				}else if(l2 == NULL && l1 != NULL){
					l2 = new Node();
					l2->data = 0;
				}else if(l1==NULL && l2 == NULL && carry !=0){
					l1 = new Node();
					l2 = new Node();
					l1->data = 0;
					l2->data = 0;
				}
				sum = l1->data + l2->data +carry;
				carry = sum /10;
				sum = sum % 10;
		/////////////////////////////To Display and To Add Nodes in l3//////////////////////
				Node *l3 = new Node();
				l3 -> data = sum;
			if(current!= NULL){
				l3 ->next = NULL;
				current ->next = l3;;
				current = l3;
			}else{
				head = l3;
				current = l3;
				l3->next = NULL;
				current->next = NULL;
			}
			l1 = l1->next;
			l2 = l2->next;
			cout<<l3->data <<" -> ";
			}
			cout<<"NULL"<<endl;
		}

		void display(){
			Node *temp  = current;
			while(temp != NULL){
				cout<<temp->data<<" -> ";
				temp = temp ->next;
			}
			cout<<"NULL"<<endl;
		}
};
int main(){
	List l1 ,l2, l3;
	l1.insert(7);  l1.insert(5);
	l2.insert(6);  l2.insert(1);
	l1.display();  l2.display();
	l3.add(l1.current , l2.current);
return 0;
}
