#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

/////////////////////////
/* FUNCIONES PROTOTIPO */
/////////////////////////

bool es_letra_diferente(string letras, char letra);
int funcionLps(string str, int i, string letters);
vector<int> funcionIteradora(string str);
void funcionKmp(string patron, string texto);


//////////////////////
/* CÓDIGO PRINCIPAL */
//////////////////////

int main() {

  // Declaramos un texto 
  string texto = "AAAAABAAAAAAB";

  // Declaramos un patrón
  string patron = "AAAA";

  // Llamamos a la funcion kmp
  funcionKmp(patron, texto);
}


//////////////
/* FUNCIONES */
//////////////


void funcionKmp(string patron, string texto) {

  vector<int> listaLps = funcionIteradora(patron);
  
  // Guardamos la longitud del patron
  int N = patron.length();
  int M = texto.length();
  
  int i = 0;
  int j = 0;
  
  while (i < M) {
    
    if (texto[i] == patron[j]) {
      i++, j++;
    }
    else if (texto[i] != patron[j]) {
      if (j - 1 == -1) {
        j = 0;
        i++;
      } else {
        j = j - 1;
      }
      j = listaLps[j];
    }

    if (j == N) {
      cout << "Patrón en: " << i - N << endl;
      (j - 1 == -1) ? j = 0 : j -= 1;
      j = listaLps[j];
    }
  }
}

vector<int> funcionIteradora(string str) {
  vector<int> lps;
  string letras_diferentes = "";
  for (int i = 0; str[i] != '\0'; i++) {
    lps.push_back(funcionLps(str, i, letras_diferentes));
    if (es_letra_diferente(letras_diferentes, str[i]))
      letras_diferentes += str[i];
  }
  return lps;
}

bool es_letra_diferente(string letras, char letra) {
  for (int i = 0; letras[i] != '\0'; i++)
    if (letras[i] == letra) return false;
  return true;
}

int funcionLps(string str, int i, string letters) {
  if (i == 0)
    return 0;

  if (es_letra_diferente(letters, str[i]))
    return 0;
    
  int longitud_maxima_global = 0;

  for (int j = 0; j < i; j++) {

    int longitud_maxima_actual = 0;

    for (int k = 0; k <= j; k++) {
      if (str[k] == str[i - j + k])
        longitud_maxima_actual++;
      else {
        longitud_maxima_actual = 0;
        break;
      }
    }
    if (longitud_maxima_actual > longitud_maxima_global)
      longitud_maxima_global = longitud_maxima_actual;
  }
  return longitud_maxima_global;
}