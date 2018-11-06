// лб6.кольцевая.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int item;
	node*next = NULL;
	node*head;
	node*end;
	node*current = NULL;
	int index;
};
int indexglobal = 0;
int current_pos;
int numb_of_x = 0;

node*init(node*Q) {
	node*pv = new node;
	cout << "Введите элемент" << endl;
	int x;
	cin >> x;
	pv->item = x;
	pv->next = NULL;
	pv->index = indexglobal;
	indexglobal++;
	//Q->head->next = pv;
	Q->head = pv;
	Q->end = pv;
	pv = NULL;
	delete pv;
	numb_of_x++;
	return Q;
}

node*push_end(node*Q) {
	node*pv = new node;
	cout << "Введите элемент" << endl;
	int x;
	cin >> x;
	pv->item = x;
	pv->next = NULL;
	pv->index = indexglobal;
	indexglobal++;
	Q->end->next = pv;
	Q->end = pv;
	pv = NULL;
	delete pv;
	numb_of_x++;
	return Q;
}

node*push_begin(node*Q) {
	node*pv = new node;
	cout << "Введите элемент" << endl;
	int x;
	cin >> x;
	pv->next = Q->head->next;
	pv->item = x;
	pv->index = indexglobal;
	indexglobal++;
	Q->head->next = pv;
	pv = NULL;
	delete pv;
	numb_of_x++;
	return Q;
}

node*push_after(node *Q) {
	node*pv = new node;
	cout << "Введите элемент" << endl;
	int x;
	cin >> x;
	pv->item = x;
	pv->index = indexglobal;
	indexglobal++;
	pv->next = Q->current->next;
	Q->current->next = pv;
	Q->end = pv;
	pv = NULL;
	delete pv;
	numb_of_x++;
	return Q;
}

node*push_before(node *Q) {
	if (Q->current == Q->head){ cout << "Добавление перед заголовочным элементом не разрешено" << endl; return Q; }
	else {
		node*pv = new node;
		cout << "Введите элемент" << endl;
		int x;
		cin >> x;
		pv->item = x;
		pv->index = indexglobal;
		indexglobal++;
		pv->next = Q->current;
		node*p = Q->head;
		while (p->next != Q->current) {
			p = p->next;
		}
		p->next = pv;
		p = NULL;
		delete p;
		pv = NULL;
		delete pv;
		numb_of_x++;
		return Q;
	}
}
node*del_before(node* Q) {
	if (Q->current == Q->head || Q->current == Q->head->next){
		cout << "Удаление заголовочного или элемента перед ним не разрешено" << endl; return Q;
	}
	else{
		node*pv = new node;
		pv = Q->head;
		while (pv->next != Q->current) {
			pv = pv->next;
		}
		node*p = Q->head->next;
		while (p->next != pv) {
			p = p->next;
		}
		pv = NULL;
		delete pv;
		p->next = Q->current;
		cout << "Done" << endl;
		numb_of_x--;
		return Q;
	}
}

node*del_after(node*Q) {
	node*pv = Q->current;
	pv = Q->current->next;
	Q->current->next = pv->next;
	pv = NULL;
	delete pv;
	numb_of_x--;
	return Q;
}

node*del_current(node*Q) {
	if (Q->current == Q->head){
		cout << "Удаление заголовочного элемента не разрешено" << endl; return Q;
	}
	else{
		node*pv = Q->head;
		while (pv->next != Q->current) {
			pv = pv->next;
		}
		pv->next = Q->current->next;
		Q->current = NULL;
		pv = NULL;
		delete pv;
		numb_of_x--;
		return Q;
	}
}

node*find_pos(node*Q) {
	node*pv = new node;
	cout << "Введите позицию" << endl;
	int p;
	cin >> p;
	pv = Q->head;
	bool flag = false;
	for(int i=0;i<numb_of_x;i++)
	{
		if (i == p) { Q->current = pv; flag = true; current_pos = p; }
		pv = pv->next;
	}
	if (!flag) { cout << "Не найдено" << endl; }
	else cout << "Значение: " << Q->current->item << " Ключ: " << Q->current->index << " Позиция: " << current_pos << endl;
	pv = NULL;
	delete pv;
	return Q;
}

node*find_x(node*Q) {
	node*pv = Q->head;
	int x;
	cout << "Введите значение" << endl;
	cin >> x;
	bool flag = false;
	for (int i = 0; i < numb_of_x;i++)
	{
		if (pv->item == x) { Q->current = pv; current_pos = i; flag = true; }
		pv = pv->next;
	}
	if (!flag) { cout << "Не найдено" << endl; }
	else cout << "Значение: " << Q->current->item << " Ключ: " << Q->current->index << " Позиция: " << current_pos << endl;
	pv = NULL;
	delete pv;
	return Q;
}


void show_current(node*Q) {
	cout << "Значение: " << Q->current->item << " Ключ: " << Q->current->index << " Позиция: " << current_pos << endl;
}

node*find_key(node*Q) {
	node*pv = Q->head;
	int p;
	cout << "Введите ключ" << endl;
	cin >> p;
	bool flag = false;
	
	for (int i = 0; i < numb_of_x; i++){
		if (p == i){
			flag = true;
			Q->current = pv;
			current_pos = p;
		}
		pv = pv->next;
	}
	if (!flag) { cout << "Не найдено" << endl; }
	else cout << "Значение: " << Q->current->item << " Ключ: " << Q->current->index << " Позиция: " << current_pos << endl;
	pv = NULL;
	delete pv;
	return Q;
}

void show(node*Q) {
	node*pv = Q->head;
	for (int i = 0;i < numb_of_x; i++){
		cout << "Значение: " << pv->item << " Ключ: " << pv->index << " Позиция: " << i << endl;
		pv = pv->next;
	}
	pv = NULL;
	delete pv;
}

node*clear(node*Q) {
	for (int i = 0; i < numb_of_x; i++){
		node*pv = Q->head->next;
		Q->head->next = Q->head->next->next;
		pv = NULL;
		delete pv;
	}
	numb_of_x=1;
	return Q;
}


node*make_circle(node*Q){
	Q->end->next = Q->head -> next;
	return Q;
}


int main()
{
	setlocale(0, "");
	node Q;
	int choice;
	int choice_add;
	int choice_choice;
	int choice_del;
	bool inited = false;
	do {
		cout << "1.Инициализация\n2.Добавление\n3.Удаление\n4.Очистка\n5.Вывод\n6.Показать выбранный элемент\n7.Сделать кольцевой" << endl;
		cin >> choice;
		switch (choice) {
		case 1:if (!inited) {
				   init(&Q); inited = true;
		}
			   else cout << "Уже инициализировано" << endl;
			   break;
		case 2: if (inited) {
					do {
						cout << "1.Добавление в конец\n2.Добавление в начало\n3.Добавление после выбранного элемента\n4.Добавление перед выбранным элементов\n5.Выбрать элемент" << endl;
						cin >> choice_add;
						switch (choice_add) {
						case 1: push_end(&Q); break;
						case 2: push_begin(&Q); break;
						case 3:if (Q.current) { push_after(&Q); }
							   else cout << "Элемент не выбран" << endl;
							   break;
						case 4:if (Q.current) { push_before(&Q); }
							   else cout << "Элемент не выбран" << endl;
							   break;
						case 5:
							do {
								cout << "1.По позиции\n2.По значению\n3.По ключу" << endl;
								cin >> choice_choice;
								switch (choice_choice) {
								case 1: find_pos(&Q); break;
								case 2: find_x(&Q); break;
								case 3: find_key(&Q); break;
								}
							} while (choice_choice != 0);
						}
					} while (choice_add != 0);
		}
				else cout << "Не инициализировано" << endl;
				break;
		case 3:
			if (!inited) { cout << "Не инициализировано" << endl; }
			else {
				do {

					cout << "1.Удаление после выбранного элемента\n2.Удаление перед выбранным элементом\n3.Удалить текущий элемент\n4.Выбрать элемент" << endl;
					cin >> choice_del;
					switch (choice_del) {

					case 2:if (Q.current) { del_before(&Q); show(&Q); }
						   else cout << "Элемент не выбран" << endl;
						   break;

					case 1: if (Q.current) { del_after(&Q); show(&Q); }
							else cout << "Элемент не выбран" << endl;
							break;

					case 3:if (Q.current) { del_current(&Q); show(&Q); }
						   else cout << "Элемент не выбран" << endl;
						   break;

					case 4:
						do {
							cout << "1.По позиции\n2.По значению\n3.По ключу" << endl;
							cin >> choice_choice;
							switch (choice_choice) {
							case 1: find_pos(&Q); break;
							case 2: find_x(&Q); break;
							case 3: find_key(&Q); break;
							}
						} while (choice_choice != 0);
					}
				} while (choice_del != 0);
			}
			break;
		case 4:
			if (!inited) { cout << "Не инициализировано" << endl; }
			else {
				clear(&Q); cout << "Выполнено" << endl;
			}
			break;
		case 5: show(&Q); break;
		case 6: if (Q.current) { show_current(&Q); }
				else cout << "Не выбран" << endl;
				break;
		case 7: if (inited){ make_circle(&Q); }
				else cout << "Не инициализировано" << endl;
				break;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}

