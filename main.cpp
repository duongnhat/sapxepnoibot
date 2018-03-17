#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class node
{
	public:
    int data;
    node *tam;
    node *next;
    
    node *head= NULL;
	node *tail= NULL;
	node *bienLuu= NULL;
	node *link=NULL;
	
	void insert(int data)
	{
		node *link= new node;
	    
	    link->data = data;
	    link->next = head;
	    head = link;
	}
	
	void print()
	{
	    node *out = head;
	    while(out != NULL){
	        cout << out->data<<"  ";
	        out = out->next;
	    }
	}
	int dem()
	{
	    int soLuong=0;
	    class node *a=head;
	    for(a=head;a!=NULL;a=a->next){
	        soLuong++;
	    }
	    return soLuong;
	}
	int nhap(){
	    int data;
	    cout << "nhap gia tri: " << endl;
	    cin >> data;
	    return data;
	}
	
	void daoNguoc(){
	    int bien;
	    class node *dao = head;
	    bien=dem();
	    for(int i=1; i<=bien; i++){
	    	bienLuu=dao->next;
	        dao->next=tail;
	        tail=dao;
	        dao=bienLuu;
	    }
	    head=tail;
	}
	
	void sapXep() {
		node *a = head;
		node *b = head;
		node *truoc = NULL;
		node *temp = head;
		int sl=dem();
		int sl2=sl;
		cout << endl;
		for(int j=0; j<sl2-1; j++) {
			b = a->next;
			for(int i=0; i<sl-1; i++) {
				cout << "so sanh " << a->data << " va " << b->data << endl;
				
				if (a->data > b->data) {
					if (truoc == NULL) {
						head = b;
					} else {
						truoc->next = b;
					}
					a->next = b->next;
					b->next = a;
					
					temp = a;
					a = b;
					b = temp;
				}
				truoc=a;
				a=b;
				b = b->next;
			}
			tail = b;
			truoc = NULL;
			a = head;
			sl--;	
		}
	}	

	
	void timKiem(int giaTri)
	{
		node *tk = head;
		int viTri=1, i=0;
		while(tk!=NULL){
			if(tk->data==giaTri){
				cout<<"tim thay "<<giaTri<<" o vi tri thu: "<<viTri<<endl;
				i=1;
			}
			viTri++;
			tk=tk->next;
		}
		if(i==0){
			cout<<"khong tim thay"<<endl;
		}
	}
};



int main(int argc, char** argv) {
	node node1;
	node *conTro;
	conTro=&node1;
    int so=0, data, giaTri;
    cout << "so gia tri muon nhap: " << endl;
    cin >> so;
    for(int i=1; i<=so; i++){
        data = conTro->nhap();
        conTro->insert(data);
    }
    node1.print();
	conTro->daoNguoc();
	cout<<endl<<"sau dao nguoc: ";
	conTro->print();
    conTro->sapXep();
	cout<<endl<<"sau xap xep: ";
    conTro->print();
    cout<<endl<<"nhap gia tri can tim: "<<endl;
    cin>>giaTri;
    node1.timKiem(giaTri);
    return 0;
}

