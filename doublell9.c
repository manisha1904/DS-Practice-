#include<stdlib.h>
#include<stdio.h>
void insertion(int,struct node*);
void display(struct node*);
void del(int,struct node*);
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
int main(){
	int n,x;
	struct node* head;
	printf("Enter no. of elements in the linklist\n");
	scanf("%d",&n);
	insertion(n,head);
	display(head);
	del(x,head);
	display(head);
	return 0;
}
/*Function to insert nodes */
void insertion(int n,struct node* head){
	struct node* temp= NULL;
	struct node* p=NULL;
	for(int i=0;i<n;i++){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the coefficient & power for node no. %d",i+1);
		scanf("%d",&(temp->data));
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL){
			head=temp;
		}
		else{
			p=head;
			while(p->next != NULL){
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
			temp->next=NULL;
		}
	}
	}
	/*Function to traverse the  linked list*/
	void display(struct node* head){
		struct node* temp=NULL;
		printf("\nForward traversal of linked list\n");
		while(head!=NULL){
			printf("%d->",head->data);
			temp=head;
			head=head->next;
		}
		printf("\nBackward traversal of linked list is given by\n");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->prev;
		}
	}
	void del(int value,struct node* head){
		while(head->data!=value){
			head=head->next;
		}
		head->next=(head->next)->next;
		((head->next)->next)->prev=head;
	}
  