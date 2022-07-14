#include <iostream>
#include <stdlib.h>
#include <string.h>

struct data{
	int id;
	char name[105];
	int age;
	data *next, *prev;
}*head, *tail, *now;

void push(int id, char name[105], int age){//Create new node at pointer head
	data *curr =(data *) malloc(sizeof(data));
	curr->id=id;
	strcpy(curr->name,name);
	curr->age=age;
	curr->next=NULL;
	curr->prev=NULL;
	
	
	if(head == NULL){
		head = now = tail = curr;
	}	
	else{
		head->prev = curr;
		curr->next = head;
		head = curr;
		now = head;
	}
	
}

void initialize(){
	head = now = tail = NULL;
	std::cout << "Initialized." << std::endl;
}

void pop(){//Delete node from pointer head
	if(head == NULL)
		std::cout << "No data available. " << std::endl;
	else{
		if(head==tail){ 
			free(head);
			head= tail = NULL;
		}else{
			data *curr = head;
			head = head->next;
			head->prev = NULL;
			curr->next = NULL;
			free(curr);
		}
	}
}

void printAll(){//Prints all the node
	if(head==NULL)
		std::cout << "No data available. " << std::endl;
	else{
		data *curr = head;
		while(curr!=NULL){
			std::cout << "ID: " << curr->id << std::endl;
			std::cout << "Name: "  << curr->name << std::endl;
			std::cout << "Age: "  << curr->age << std::endl;
			std::cout << std::endl;
			curr = curr->next;
		}
	}
}

void moveNext(){//Move current to next position
	if(now->next){
		now = now->next;
	}else{
		std::cout << "No data. " << std::endl;
	}
}

void movePrevious(){//Move current to previous position
	if(now->prev){
		now = now->prev;
	}else{
		std::cout << "No data. " << std::endl;
	}
}

void printHead(){//Prints head
	if(head==NULL)
		std::cout<< "No data available. " << std::endl;
		else{
		data *curr = head;
			std::cout << "ID: " << curr->id << std::endl;
			std::cout << "Name: "  << curr->name << std::endl;
			std::cout << "Age: "  << curr->age << std::endl;
			std::cout << std::endl;
		}
}

void printTail(){//Prints tail
	if(tail==NULL)
		std::cout << "No data available. " << std::endl;
		else{
		data *curr = tail;
			std::cout << "ID: " << curr->id << std::endl;
			std::cout << "Name: "  << curr->name << std::endl;
			std::cout << "Age: "  << curr->age << std::endl;
			std::cout << std::endl;
		}
}

void printCurrent(){//Prints current
	if(now==NULL)
		std::cout << "No data available. " << std::endl;
		else{
		std::cout << "ID: " << now->id << std::endl;
		std::cout << "Name: "  << now->name << std::endl;
		std::cout << "Age: "  << now->age << std::endl;
		std::cout << std::endl;
		}
}

int main(){
	
	int menu;
	
	int id, age;
	char name[105];
	
	std::cout << "Choose your program:" << std::endl;
	std::cout << "1. Initialize" << std::endl;
	std::cout << "2. Push" << std::endl;
	std::cout << "3. Pop" << std::endl;
	std::cout << "4. Move Next" << std::endl;
	std::cout << "5. Move Previous" << std::endl;
	std::cout << "6. Print Head" << std::endl;
	std::cout << "7. Print Tail" << std::endl;
	std::cout << "8. Print Current" << std::endl;
	std::cout << "9. Print All" << std::endl;
	std::cout << "0. Quit" << std::endl;	
	std::cout << "______________________________________________" << std::endl;
	std::cin >> menu;
	std::cout << std::endl;
	
	switch(menu){
		case 1: {
			initialize();
			return main();
		}
		case 2: {
			std::cout << "Insert ID: ";
			std::cin >> id;
			std::cout << "Insert Name: ";
			std::cin >> name;
			std::cout << "Insert Age: ";
			std::cin >> age;
			std::cout << std::endl;
			push(id,name,age);
			return main();
		}
		case 3: {
			pop();
			return main();
		}
		case 4: {
			moveNext();
			return main();
		}
		case 5: {
			movePrevious();
			return main();
		}
		case 6: {
			printHead();
			return main();
		}
		case 7: {
			printTail();
			return main();
		}
		case 8: {
			printCurrent();
			return main();
		}
		case 9: {
			printAll();
			return main();
		}
		default:{
			return 0;
		}
	}
	
	return 1;
}
