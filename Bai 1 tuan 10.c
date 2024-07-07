#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
	int data;
	Node * next;
};
typedef struct Node Node;

struct List{
	Node *phead;
	Node *ptail;
};
typedef struct List List;

void KhoiTao(List *list){
	list->phead = list->ptail = NULL;
}

Node* GetNode(int value){
	Node *newnode = (Node *)malloc(sizeof(Node));
	if(newnode==NULL){
		printf("Unable to allocate memory");
		return NULL;
	}
	else{
		newnode->data = value;
		newnode->next = NULL;
	}
	return newnode;
}

void ThemDau(List *list, int value){
	Node *newnode = GetNode(value);
	if(list->phead == NULL){
		list->phead = list->ptail = newnode;
	}
	else{
		newnode->next = list->phead;
		list->phead = newnode;
	}
}

void ThemSauDau(List *list,int data){
	Node *newnode = GetNode(data);
	if(list->phead == NULL){
		list->phead = list->ptail = newnode;
	}
	else{
		newnode->next = list->phead->next;
		list->phead->next = newnode;
	}
}

void ThemCuoi(List *list,int value){
	Node *newnode = GetNode(value);
	if(list->phead == NULL){
		list->phead = list->ptail = newnode;
	}
	else{
		list->ptail->next = newnode;
		list->ptail = newnode;
	}
}
void ThemTruocCuoi(List *list,int value){
	Node *newnode = GetNode(value);
	if(list->phead == NULL){
		list->phead = list->ptail = newnode;
	}
	else if(list->phead == list->ptail){
		ThemDau(list,value);
	}
	else{
		Node *p = list->phead;
		while(p->next != list->ptail){
			p = p->next;
		}
		newnode->next = list->ptail;
		p->next = newnode;
	}
}

void Xoa(List *list, int value) {
    Node *current = list->phead;
    Node *prev = NULL;

    while (current) {
        if (current->data == value) {
            if (prev == NULL) {
                // Node to be deleted is the head
                list->phead = current->next;
                free(current);
                current = list->phead;
            } else {
                // Node to be deleted is not the head
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    // Update the tail pointer
    if (list->phead == NULL) {
        list->ptail = NULL;
    } else {
        Node *temp = list->phead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        list->ptail = temp;
    }
}

void Sua(List *list){
	int value,fix;
	printf("Nhap node muon sua: ");
	scanf("%d",&value);
	printf("Gia tri moi: ");
	scanf("%d",&fix);
	Node *current = list->phead;
	while(current){
		if(current->data == value){
			current->data = fix;
		}
		current = current->next;
	}
}

void InChan(List *list){
	Node *current = list->phead;
	while(current){
		if(current->data %2 == 0)
			printf("%d->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}

Node* Max(List *list) {
    if (list == NULL || list->phead == NULL) return NULL; // Handle empty list case
    
    Node* max = list->phead;
    for (Node *p = list->phead->next; p != NULL; p = p->next) {
        if (p->data > max->data) {
            max = p; // Update max to point to the node with the greater value
        }
    }
    return max;
}

bool Prime(int n){
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return n>1;
}

void CountPrime(List *list){
	Node *current = list->phead;
	while(current){
		if(Prime(current->data)){
			printf("%d->",current->data);
		}
		current = current->next;
	}
	printf("NULL\n");
}
void DaoNguoc(List *list){
	Node *prev = NULL;
	Node *current = list->phead;
	Node *next = NULL;
	while(current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->phead = prev;
}

void ThemKTruocP(List *list,Node * k,Node * p){
	Node *current = list->phead;
	Node *target = NULL;
	if(current == NULL) return;
	
	if(current->data == p->data){
		k->next = current;
        list->phead = k;
        return;
	}
	
	while(current != NULL && current->data != p->data){
		target = current;
		current = current->next;
	}
	
	if(current == NULL) return;
	
	k->next = target->next;
	target->next = k;
}
void ThemKSauP(List *list,Node *k,Node *p){
	Node *current = list->phead;
	if(current == NULL) return;
	while(current->data != p->data){
		current = current->next;
	}
	if(current == NULL) return;
	k->next = current->next;
	current->next = k;
}

void ThemTruocChanDau(List *list){
	Node *current = list->phead;
	int value;
	printf("Nhap node muon them: ");
	scanf("%d",&value);
	while(current){
		if(current->data %2 ==0){
			Node *k = GetNode(value);
			ThemKSauP(list,k,current);
			break;
		}
		current = current->next;
	}
}
void XoaDau(List *list){
	Node *current = list->phead;
	Xoa(list,current->data);
}

void XoaCuoi(List *list){
	Node *current = list->ptail;
	Xoa(list,current->data);
}

void XoaMax(List *list){
	Node *max = Max(list);
	Xoa(list,max->data);
}

void XoaKTruocP(List *list,Node *p){
	Node *current = list->phead;
	Node *prev = NULL;
	while(current != NULL && current->data != p->data){
		prev = current;
		current = current->next;
	}
	Xoa(list,prev->data);
	
}


void TachDanhSachPrime(List *l1, List *l2) {
    Node *current = l1->phead;
    Node *next;

    while (current != NULL) {
        next = current->next; // Save the next node
        if (!Prime(current->data)) {
            // Node is not prime, move it to l2
            ThemCuoi(l2, current->data);

            // Delete the current node from l1
            Xoa(l1, current->data);
        }
        current = next; // Move to the next node
    }
}

void SapXep(List *list){
	int temp;
	for(Node *p =list->phead;p!=NULL;p=p->next){
		for(Node *q=p->next;q!=NULL;q=q->next){
			if(q->data < p->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}

void XoaTrung(List *list) {
    if (list->phead == NULL || list->phead == list->ptail) {
        return; // No need to remove duplicates if the list is empty or has only one element
    }

    Node *current = list->phead;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    // Update the tail pointer
    if (list->phead == NULL) {
        list->ptail = NULL;
    } else {
        Node *temp = list->phead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        list->ptail = temp;
    }
}


void Merge(List *l1,List *l2,List *l3){
	Node *p1 = l1->phead;
	Node *p2 = l2->phead;
	while(p1){
		ThemCuoi(l3,p1->data);
		p1 = p1->next;
	}
	while(p2){
		ThemCuoi(l3,p2->data);
		p2 = p2->next;
	}
	SapXep(l3);
	XoaTrung(l3);
}
void Nhap(List *list,int n){
	if(n<=0) return;
	for(int i=0;i<n;i++){
		int value;
		printf("Nhap node thu %d: ",i+1);
		scanf("%d",&value);
		ThemCuoi(list,value);
	}
}

void In(List *list){
	Node *current = list->phead;
	while(current){
		printf("%d->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	List list;
	List l2,l3;
	KhoiTao(&l2);
	KhoiTao(&list);
	KhoiTao(&l3);
	Nhap(&list,n);
	Nhap(&l2,n);
//	Xoa(&list);
//	Sua(&list);
//	InChan(&list);
//	Node *p = Max(&list);
//	printf("Max: %d",p->data);
//	DaoNguoc(&list);
//	Node *k = GetNode(10);
//	Node *p = GetNode(3);
//	ThemKTruocP(&list,k,p);
//	ThemTruocChanDau(&list);
//	XoaMax(&list);
//	TachDanhSachPrime(&list,&l2);
	Merge(&list,&l2,&l3);
	In(&l3);
//	In(&l2);
}
