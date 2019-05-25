#include <iostream>

using namespace std;

struct Stack {
    int num;
    Stack * next;
} *bbegin, *t;

Stack* add_stack(Stack *p, int in) {
    Stack *t = new Stack;
    t -> num = in;
    t -> next = p;
    return t;
}

void add_to_stack(){
    int in = 0;
    in = random();
    bbegin = add_stack(bbegin, in);
    cout << "Элемент успешно добавлен.";
}

void delete_stack(Stack **p) {
    while(*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
    cout << "Стек успешно удален";
}

void create_stack(){
    if(bbegin != NULL){
        cout << "Память занята. Удалить предыдущий стек?\n\t1. Удалить\n\t2. Отмена\nДействие: ";
        int a = 0;
        cin >> a;
        if(a == 1)
            delete_stack(&bbegin);
    } else {
        int n = 0, in = 0;
        cout << "Количество элементов стека = "; 
        cin >> n;
        if(n > 0){
            for(int i = 1; i <= n; i++) {
                in = random();
                bbegin = add_stack(bbegin, in);
            }
        } else {
            cout << "Ошибка: Размерность стека должна быть больше 0\n";
        }
    }
}

void view_stack(Stack *p) {
    Stack *t = p;
    int i = 0;
    if(t == NULL) {
        cout << "\nСтек пуст\n\n";
        return;
    }
    while( t != NULL) {
        i++;
        cout << "[" << i << "]\t=>\t" << t->num << endl;
        t = t -> next;
    }
}

void delete_max(Stack **begin){
    Stack * t = *begin;
    Stack * t1 = t;
    int max = t1->num;
    while(t1){
        if(t1->num > max)
            max = t1->num;
        t1 = t1->next;
    }
    Stack * p = t;
    while(p){
        if(p->num == max){
            if(p = *begin)
                *begin = p->next;
            t->next = p->next;
            t->num = p->num;
            p = p->next;
        } else {
            t = p;
            p = p->next;
        }
    }
    delete t1;
}

bool menu(){
    int a = 0;
    cout << "Выберите действие: \n\t1. Создать\n\t2. Добавить\n\t3. Просмотреть\n\t4. Удалить\n\t5. Удалить максимальный элемент стека\n\t0. Выход\nДействие: ";
    cin >> a;
    switch(a){
        case 1:
            create_stack();
            break;
        case 2:
            add_to_stack();
            break;
        case 3:
            view_stack(bbegin);
            break;
        case 4:
            delete_stack(&bbegin);
            break;
        case 5:
            delete_max(&bbegin);
            break;
        case 0:
            return false;
            break;
        default:
            cout << "Ошибка: Введите корректное значение\n";
            break;
    }
    menu();
}

int main(){
    setlocale(LC_ALL, "Rus");
    menu();
    return 0;
}