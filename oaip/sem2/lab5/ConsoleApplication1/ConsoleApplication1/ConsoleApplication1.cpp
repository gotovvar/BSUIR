#include <iostream>

using namespace std;

struct Stack {
	int info;
	Stack* next;
};

Stack* InStack(Stack*, int);
void View(Stack*);
void Del_All(Stack**);
void Sort_p(Stack**);
void Sort_info(Stack*);
Stack* HH(Stack*);

Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View(Stack* p) {
	Stack* temp = p;
	while (temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	}
}

void Del_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Sort_p(Stack** p) {
	Stack* t = NULL, * tl, * r;
	if ((*p)->next->next == NULL) return;
	while ((*p)->next->next != t) {
		for (tl = *p; tl->next->next != t; tl = tl->next)
			if (tl->next->info > tl->next->next->info) {
				r = tl->next->next;
				tl->next->next = r->next;
				r->next = tl->next;
				tl->next = r;
			}
		t = tl->next;
	}
}

void Sort_info(Stack* p) {
	Stack* t = NULL, * tl;
	int r;
	while (p->next != t) {
		for (tl = p; tl->next != t; tl = tl->next)
			if (tl->info > tl->next->info) {
				r = tl->info;
				tl->info = tl->next->info;
				tl->next->info = r;
			}
		t = tl;
	} 
}


int main()
{
	setlocale(LC_ALL, "ru");

	Stack* begin = 0;

	int n, c, kod, i;
	while (true) {
		cout << "1 - Создание стека" << endl;
		cout << "2 - Просмотр стека" << endl;
		cout << "3 - Добавление элементов в стек" << endl;
		cout << "4 - Удаление стека" << endl;
		cout << "5 - Решение ИЗ" << endl;
		cout << "6 - Сортировка перестановкой адресов" << endl;
		cout << "7 - Сортировка обменом информацией" << endl;
		cout << "0 - Выйти из программы" << endl;
		cin >> kod;
		switch (kod) {
		case 1: {
			if (begin != NULL) {
				cout << "Отчистите память!" << endl;
				break;
			}
			cout << "Введите кол-во элементов: ";
			cin >> n;
			for (i = 0; i < n; ++i) {
				cout << "Info(" << i + 1 << ")= ";
				cin >> c;
				begin = InStack(begin, c);
			}break;
		}


		case 2: {
			if (!begin) {
				cout << "Стек пуст!" << endl;
				break;
			}
			cout << "------Stack-------" << endl;
			View(begin);
		}break;


		case 3: {
			cout << "Кол-во добавляемых элементов: ";
			cin >> n;
			for (i = 0; i < n; ++i) {
				cout << "Info(" << i + 1 << ")= ";
				cin >> c;
				begin = InStack(begin, c);
			}break;
		}


		case 4: {
			if (!begin) {
				cout << "Стек уже пуст!" << endl;
				break;
			}
			Del_All(&begin);
			cout << "Стек удален!" << endl;
		} break;


		case 5: {
			Stack* temp = new Stack;
			temp->info = 7;
			temp->next = NULL;
			Stack* ex = begin;
			View(begin);
			while (begin->next->next != NULL) {
				begin = begin->next;
			}
			begin->next = temp;
			temp->next = begin->next->next;
			cout << "---------------" << endl;
			View(begin);
		}


		case 6: {
			if (!begin) {
				cout << "Стек пуст!" << endl;
				break;
			}
			begin = InStack(begin, 1000000);
			Sort_p(&begin);
			Stack* a = begin;
			begin = begin->next;
			delete a;
		}break;


		case 7: {
			if (!begin) {
				cout << "Стек пуст!" << endl;
				break;
			}
			Sort_info(begin);

		}break;


		case 0: 
			return 0;

		default: cout << "Ошибка выбора!" << endl;
		}
	}
}