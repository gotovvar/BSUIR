#include <iostream>
using namespace std;

struct Spisok {
    int info;
    Spisok* next, * prev;
} *begin, *end, *t;



void AddElem(int choice, Spisok** begin, Spisok** end, int inf)
{
    t = new Spisok;
    t->info = inf;
    if (choice == 0) {
        t->prev = NULL;
        t->next = *begin;
        (*begin)->prev = t;
        *begin = t;
    }
    else {
        t->next = NULL;
        t->prev = *end;
        (*end)->next = t;
        *end = t;
    }

}
void Del(Spisok** p) {
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

void ShowListBegin(Spisok* begin)
{
    if (begin == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    else {
        cout << "Output from the begining of the list : ";
        Spisok* tmp = begin;
        while (tmp)
        {
            cout << tmp->info << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void ShowListEnd(Spisok* end)
{
    if (end == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }
    else {
        cout << "Output from the end of the list : ";
        Spisok* tmp = end;
        while (tmp != NULL) {
            cout << tmp->info << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }
}

void deletelem(Spisok* b)
{
    struct Spisok* prev, * next;
    b = b->next;
    prev = b->prev;
    next = b->next;
    if (prev != NULL)
        prev->next = b->next;
    if (next != NULL)
        next->prev = b->prev;
    delete (b);
}

Spisok* HH(Spisok* b,Spisok** a) {
    Spisok* temp1 = b;
    Spisok* temp2 = b->next;

    if (temp2->next == NULL) {
        temp1->next = NULL;
        delete temp2;
        *a = temp1;
        return b;
    }

    while (temp2->next != NULL)
    {
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        temp1 = temp2->next;
        delete temp2;   
        if (temp1->next != NULL)
        {
            temp2 = temp1->next;
        }
        else {
            *a = temp1;
            return b;
        }
        if (temp2->next == NULL)
        {
            temp1->next = temp2->next;
            delete temp2;
            *a = temp1;
            return b;
        }
    }
}


int main()
{
    int in;
    Spisok* list1 = new Spisok;
    Spisok* begin = NULL;
    Spisok* end = NULL;

    cout << "Enter the first element of the list; ";
    cin >> in;
    list1->info = in;
    list1->next = list1->prev = NULL;
    begin = end = list1;
    int choise,num;
    while (true) {
        cout << "1. Adding to the end" << endl;
        cout << "2. Adding to the beginning" << endl;
        cout << "3. View from the beginning" << endl;
        cout << "4. View from the end" << endl;
        cout << "5. Sorting by parity" << endl;
        cout << "6. Deliting" << endl;
        cout << "7. Exit" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
        {
            int input;
            cout << "Adding to the end: ";
            cin >> input;
            AddElem(1, &begin, &end, input);
            break;
        }
        case 2:
        {
            int input;
            cout << "Adding to the begining ";
            cin >> input;
            AddElem(0, &begin, &end, input);
            break;
        }
        case 3:
        {
            ShowListBegin(begin);
            break;
        }
        case 4:
        {
            ShowListEnd(end);
            break;
        }
        case 5:
        {
           HH(begin,&end);
           break;
        }

        case 6:
        {
            cout << "The list is deleted" << endl;
            Del(&begin);
            break;
        }
        case 7:
        {
            Del(&begin);
            return 0;
            break;

        }

        default: {
            system("cls");
            cout << "The input Error!!!" << endl;
            return 0;
        }
        }
    }
}
