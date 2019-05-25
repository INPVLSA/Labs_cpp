#include <iostream>

struct List{
    int num;
    List *next, *prev;
}*begin, *end;

List* add_to_begin(List **p, int in) {
    List * t = new List;
    (*p)-> prev = t;
    t -> num = in;
    t -> next = *p;
    t -> prev = NULL;

    return t;
}
List* add_to_end(List **p, int in) {
    List * t = new List;
    (*p)-> next = t;
    t -> num = in;
    t -> prev = *p;
    t -> next = NULL;

    return t;
}

void delete_list(List **begin){
    while(*begin != NULL) {
        List * t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
    std::cout << "Стек успешно удален\n";
}

void delete_max(List **begin){
    List * t = *begin;
    List * t1 = t;
    int max = t1->num;
    while(t1){
        if(t1->num > max)
            max = t1->num;
        t1 = t1->next;
    }
    List * p = t;
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

int answer(){
    std::cout << "Действие: ";
    int a = 0;
    std::cin >> a;
    return a; 
}

void add_to_list(){
    std::cout << "Добавить элемент:\n\t1. В начало\n\t2. В конец\n";
    switch (answer()){
        case 1:
            begin = add_to_begin(&begin, random());
            break;
        case 2:
            end = add_to_end(&end, random());
            break;
        default:
            return;
            break;
    }
}

void incorrect(){
    std::cout << "Некорректное значение\n";
}


void init(){
    if(begin != NULL){
        std::cout << "Память занята. Удалить существующий список?\n\t1. Удалить\n\t2. Отмена\nДействие: ";
        int a = 0;
        std::cin >> a;
        if(a == 1)
            // delete_list(&begin);
            std::cout << "";
    } else {
        int n = 0, in = 0;
        std::cout << "Количество элементов списка = "; 
        std::cin >> n;
        if(n > 0){
            List * t = new List;
            t -> num = random();
            t -> next = NULL;
            t -> prev = NULL;
            begin = t;
            end = t;

            for(int i = 1; i < n; i++) {
                in = random();
                begin = add_to_begin(&begin, in);
            }
        } else {
            std::cout << "Ошибка: Размерность списка должна быть больше 0\n";
        }
    }
}

void print_begin(List *p) {
    List * t = p;
    int i = 0;
    if(t == NULL) {
        std::cout << "\nСписок пуст\n\n";
    }
    while( t != NULL) {
        i++;
        std::cout << "[" << i << "]\t=>\t" << t->num << std::endl;
        t = t->next;
    }
}

void print_end(List *p) {
    List * t = p;
    int i = 0;
    if(t == NULL) {
        std::cout << "\nСписок пуст\n\n";
    }
    while( t != NULL) {
        i++;
        std::cout << "[" << i << "]\t=>\t" << t->num << std::endl;
        t = t->prev;
    }
}

void print(){
    std::cout << "Вывести список элемент:\n\t1. С начала\n\t2. С конца\n";
    switch (answer()){
        case 1:
            print_begin(begin);
            break;
        case 2:
            print_end(end);
            break;
        default:
            return;
            break;
    }
}



void menu(){
    int a = 0;
    std::cout << "Выберите действие: \n\t1. Создать\n\t2. Добавить\n\t3. Просмотреть\n\t4. Удалить\n\t5. Удалить максимальный элемент списка\n\t0. Выход\n";
    switch(answer()){
        case 1:
            init();
            break;
        case 2:
            add_to_list();
            break;
        case 3:
            print();
            break;
        case 4:
            delete_list(&begin);
            delete begin, end;
            break;
        case 5:
            delete_max(&begin);
            // delete_every_2(&bbegin);
            break;
        case 0:
            return;
            break;
        default:
            std::cout << "Ошибка: Введите корректное значение\n";
            break;
    }
    menu();
}

int main(){
    setlocale(LC_ALL, "Rus");
    menu();
    return 0;
}