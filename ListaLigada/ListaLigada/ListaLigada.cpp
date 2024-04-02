
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == novo->valor) {
			cout << "Elemento ja existente na lista, digite outro valor." << endl;
			return;
		}
		aux = aux->prox;
	}

	if (primeiro == NULL) {
		primeiro = novo;
	}
	else {
		aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo; 
	}
}

void excluirElemento()
{
	int excluindo = 0;
	NO* aux = NULL;

	cout << "Digite o numero que deseja excluir: " << endl;
	cin >> excluindo;

	aux = posicaoElemento(excluindo);

	if (aux == NULL) {
		cout << "Elemento nao encontrado." << endl;
		return;
	}

	if (aux == primeiro) {
		primeiro = aux->prox; 
	}
	else {
		
		NO* ant = primeiro;
		while (ant->prox != aux) {
			ant = ant->prox;
		}
		
		ant->prox = aux->prox;
	}

	free(aux);

	cout << "Elemento excluido." << endl;
}

void buscarElemento()
{
	int buscado = 0;
	NO* aux = primeiro;

	cout << "Digite o numero que deseja buscar: " << endl;
	cin >> buscado;

	while (aux != NULL) {
		if (aux->valor == buscado) {
			cout << "Numero encontrado!" << endl;
			return;
		}
		aux = aux->prox;
	}
	cout << "Numero NAO encontrado!" << endl;
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}