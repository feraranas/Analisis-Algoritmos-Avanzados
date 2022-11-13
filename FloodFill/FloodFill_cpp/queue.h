#include <iostream>

template <typename T> class Queue {
private:
  struct x {
    T value;
    x *next;
  };

  x *inicio;
  x *fin;

public:
  Queue<T>() {
    inicio = nullptr;
    fin = nullptr;
  }

  /* Crea nodo */
  x *crea_nuevo(T v) {
    x *nuevo = new x();
    nuevo->value = v;
    nuevo->next = nullptr;
    return nuevo;
  }

  /* Agregar a queue: al final de la cola
  ¿Qué ocupar?
    - Arreglo estático
    - Arreglo dinámico
    - Vectores
    - Apuntadores
    - Lista ligada: simple, doble
  */
  void push(T v) {
    if (inicio == nullptr) {
      x *nuevo = crea_nuevo(v);
      inicio = nuevo;
      fin = nuevo;
      return;
    }
    x *tmp = fin;
    x *nuevo = crea_nuevo(v);
    tmp->next = nuevo;
    fin = tmp->next;
  }

  /* Eliminar del queue: eliminas al inicio de la cola
   */
  T pop() {
    if (inicio == nullptr)
      return;
    T v = inicio->value;
    x *tmp = inicio;
    inicio = inicio->next;
    tmp->next = NULL;
    delete tmp;
    return v;
  }

  /* Imprimir para debuggear */
  void imprimir_queue() {
    if (inicio == nullptr) {
      std::cout << "vacio" << std::endl;
      return;
    }
    x *tmp = inicio;
    while (tmp != nullptr) {
      std::cout << tmp->value << " ";
      tmp = tmp->next;
    }
    std::cout << std::endl;
  }

  /* checa si queue esta vacio o no */
  bool empty() {
    bool check = false;
    if (inicio == nullptr)
      check = true;
    return check;
  }
};
