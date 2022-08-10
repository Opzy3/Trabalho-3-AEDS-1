//Arquivo "lista.h" com as assinaturas das funções
typedef struct elemento *Lista;

// criacao da lista
Lista* criar();

//Função para liberar as listas
void liberar();

// Função para inserir um elemento na lista
int inserir(Lista *li, int number);

// Função para somar as 2 listas 
void somar(Lista *l1, Lista *l2);