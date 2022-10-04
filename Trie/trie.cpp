#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Posibles char's = abecedario #26 minusculas
//                   + abecedario #26 mayúsculas
//                   + numeros (0 -> 9) #10
//                   total = 62 char's por acomodar
const int N = 62;

// Creación de un nodo
struct Nodo {
  char letra;
  Nodo *n[N];
  bool flag;
};

// Alocar nuevos nodos
Nodo *nuevo_nodo(char l) {
  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
  nodo->letra = l;
  for (int i = 0; i < N; i++)
    nodo->n[i] = {NULL};
  nodo->flag = false;
  return (nodo);
}

// Regresa el índice del 0-61 de un numero, letra mayu o minus
int es_mayuscula_minuscula_numero(char letra) {
  int indice = 0;
  if (int(letra) >= 65 && int(letra) <= 90)
    indice = int(letra) - 55; // mayúsculas
  else if (int(letra) >= 97 && int(letra) <= 122)
    indice = int(letra) - 61; // minúsculas
  else if (int(letra) >= 48 && int(letra) <= 57)
    indice = int(letra) - 48; // numeros
  return indice;
}

// Verifica si es número, letra mayús o minus
bool es_ma_mi_nu(char letra) {
  bool flag = false;
  if (int(letra) >= 65 && int(letra) <= 90)
    flag = true; // mayúsculas
  else if (int(letra) >= 97 && int(letra) <= 122)
    flag = true; // minúsculas
  else if (int(letra) >= 48 && int(letra) <= 57)
    flag = true; // numeros
  return flag;
}

// Insertar al Trie
void insertar_palabra(string palabra, int i, int m, Nodo *trie) {

  int indice = es_mayuscula_minuscula_numero(palabra[i]);

  if (i < m) {
    if (i == m - 1) {
      if (trie->n[indice] == NULL) {
        trie->n[indice] = nuevo_nodo(palabra[i]);
        trie->n[indice]->flag = true;
        return;
      }
    } else {
      if (trie->n[indice] == NULL) {
        trie->n[indice] = nuevo_nodo(palabra[i]);
        insertar_palabra(palabra, i + 1, m, trie->n[indice]);
      } else {
        insertar_palabra(palabra, i + 1, m, trie->n[indice]);
      }
    }
  }

  return;
}

// Buscar del trie
void busqueda_palabra(string palabra, int i, int m, Nodo *trie) {
  int indice = es_mayuscula_minuscula_numero(palabra[i]);
  if (i < m) {
    if (i == m - 1) {
      if ((trie->n[indice] != NULL) && (trie->n[indice]->letra == palabra[i])) {
        cout << palabra << endl;
      }
    } else {
      if ((trie->n[indice] != NULL) && (trie->n[indice]->letra == palabra[i])) {
        busqueda_palabra(palabra, i + 1, m, trie->n[indice]);
      }
    }
  }
}

void busqueda(string palabra, int i, int m, Nodo *trie) {

  int indice = es_mayuscula_minuscula_numero(palabra[i]);

  // Casos base
  if (i < m) {
    if (i == m - 1) {
      if ((trie->n[indice]->flag == true) && (trie->n[indice] != NULL)) {
        cout << true << endl;
        return;
      }
    }
    if (trie->flag == true) {
      cout << false << endl;
      return;
    }
    if (trie->n[indice] == NULL) {
      cout << false << endl;
      return;
    }
    if (trie->n[indice] != NULL)
      busqueda(palabra, i + 1, m, trie->n[indice]);
  }
}

// Checa si es nodo último
bool nodo_ultimo(Nodo *trie) { return trie->flag != false; }

// Depth First Search Recorrido
void dfs(Nodo *raiz, char str[], int nivel) {

  // Caso base
  if (nodo_ultimo(raiz)) {
    str[nivel] = '\0';
    cout << str << endl;
  }

  int i;
  for (i = 0; i < N; i++) {
    if (raiz->n[i]) {
      str[nivel] = raiz->n[i]->letra;
      dfs(raiz->n[i], str, nivel + 1);
    }
  }
}

// Código principal
int main() {

  cout << "INGRESAR PALABRAS" << endl;
  string n;
  cout << "Ingresa un numero n: ";
  getline(cin >> ws, n);
  if (n == "") {
    cout << "Input inválido. Vuelve a intentarlo" << endl;
    return 1;
  }
  int tamano_n = n.length();
  for (int i = 0; i < tamano_n; i++) {
    if (n[i] < 48 || n[i] > 57) {
      cout << "Input inválido. Vuelve a intentarlo" << endl;
      return 1;
    }
  }

  int num = stoi(n);

  cout << endl << "Ahora ingresa " << num << " palabras: " << endl << endl;

  vector<string> vPalabras;
  string linea;
  for (int i = 0; i < num; i++) {
    cout << "Palabra " << i + 1 << ": ";
    getline(cin >> ws, linea);
    int nLinea = linea.length();
    for (int j = 0; j < nLinea; j++) {
      if (!es_ma_mi_nu(linea[j])) {
        cout << "Input inválido. Vuelve a intentarlo" << endl;
        return 1;
      }
    }
    vPalabras.push_back(linea);
    cout << endl;
  }

  // Código de inserción
  int nPalabras = vPalabras.size();

  Nodo *raiz = new Nodo;

  for (int i = 0; i < nPalabras; i++) {
    string palabra = vPalabras[i];
    int n = palabra.length();
    insertar_palabra(palabra, 0, n, raiz);
  }

  cout << "BUSCAR PALABRAS" << endl;
  string m;
  cout << "Ingresa un numero m: ";
  getline(cin >> ws, m);
  if (m == "") {
    cout << "Input inválido. Vuelve a intentarlo" << endl;
    return 1;
  }
  int tamano_m = m.length();
  for (int i = 0; i < tamano_m; i++) {
    if (m[i] < 48 || m[i] > 57) {
      cout << "Input inválido. Vuelve a intentarlo" << endl;
      return 1;
    }
  }

  int num2 = stoi(m);

  if (num < num2) {
    cout << "Ingresa un numero valido de palabras a buscar" << endl;
    return 0;
  }

  cout << endl
       << "Ahora ingresa " << num2 << " palabras a buscar: " << endl
       << endl;

  vector<string> vPalabrasBusqueda;
  for (int i = 0; i < num2; i++) {
    cout << "Palabra " << i + 1 << ": ";
    getline(cin >> ws, linea);
    int nLinea = linea.length();
    for (int j = 0; j < nLinea; j++) {
      if (!es_ma_mi_nu(linea[j])) {
        cout << "Input inválido. Vuelve a intentarlo" << endl;
        return 1;
      }
    }
    vPalabrasBusqueda.push_back(linea);
    cout << endl;
  }

  cout << endl;
  cout << "DFS TRIE" << endl;
  cout << endl;
  int nivel = 0;
  char str[20];
  dfs(raiz, str, nivel);

  cout << endl;
  cout << "BOOLEANOS BÚSQUEDA DE PALABRAS" << endl;
  cout << endl;
  // Código de búsqueda
  for (int i = 0; i < nPalabras; i++) {
    string palabra = vPalabrasBusqueda[i];
    int n = palabra.length();
    busqueda(palabra, 0, n, raiz);
  }
}
