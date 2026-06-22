#include <iostream>
using namespace std;

// fila

struct NoFila {
    int senha;
    NoFila* prox;
};

struct Fila {
    NoFila* inicio;
    NoFila* fim;
    int quantidade;
};

void inicializarFila(Fila &f) {
    f.inicio = NULL;
    f.fim = NULL;
    f.quantidade = 0;
}

bool filaVazia(Fila &f) {
    return f.inicio == NULL;
}

void enfileirar(Fila &f, int senha) {
    NoFila* novo = new NoFila;
    novo->senha = senha;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f.inicio = novo;
        f.fim = novo;
    } else {
        f.fim->prox = novo;
        f.fim = novo;
    }

    f.quantidade++;
}

int desenfileirar(Fila &f) {
    if (filaVazia(f))
        return -1;

    NoFila* aux = f.inicio;
    int senha = aux->senha;

    f.inicio = f.inicio->prox;

    if (f.inicio == NULL)
        f.fim = NULL;

    delete aux;
    f.quantidade--;

    return senha;
}

// guichê

struct Guiche {
    int id;
    Fila atendidas;
    Guiche* prox;
};

Guiche* listaGuiches = NULL;

Guiche* buscarGuiche(int id) {

    Guiche* aux = listaGuiches;

    while (aux != NULL) {

        if (aux->id == id)
            return aux;

        aux = aux->prox;
    }

    return NULL;
}

void abrirGuiche(int id) {

    if (buscarGuiche(id) != NULL) {
        cout << "Guiche ja existe!\n";
        return;
    }

    Guiche* novo = new Guiche;

    novo->id = id;
    inicializarFila(novo->atendidas);

    novo->prox = listaGuiches;
    listaGuiches = novo;

    cout << "Guiche aberto com sucesso!\n";
}

int contarGuiches() {

    int total = 0;

    Guiche* aux = listaGuiches;

    while (aux != NULL) {
        total++;
        aux = aux->prox;
    }

    return total;
}


int main() {

    Fila senhasGeradas;
    inicializarFila(senhasGeradas);

    int controleSenha = 0;
    int totalAtendidas = 0;

    int opcao;

    do {

        cout << "\n=========================\n";
        cout << "Senhas aguardando: "
             << senhasGeradas.quantidade << endl;

        cout << "Guiches abertos: "
             << contarGuiches() << endl;

        cout << "=========================\n";

        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Abrir guiche\n";
        cout << "3 - Realizar atendimento\n";
        cout << "4 - Listar senhas atendidas\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao) {

            case 1: {

                controleSenha++;

                enfileirar(
                    senhasGeradas,
                    controleSenha
                );

                cout << "Senha gerada: "
                     << controleSenha << endl;

                break;
            }

            case 2: {

                int id;

                cout << "ID do guiche: ";
                cin >> id;

                abrirGuiche(id);

                break;
            }

            case 3: {

                if (filaVazia(senhasGeradas)) {
                    cout << "Nao ha senhas aguardando.\n";
                    break;
                }

                int id;

                cout << "Guiche que esta chamando: ";
                cin >> id;

                Guiche* g = buscarGuiche(id);

                if (g == NULL) {
                    cout << "Guiche nao encontrado.\n";
                    break;
                }

                int senha =
                    desenfileirar(senhasGeradas);

                enfileirar(
                    g->atendidas,
                    senha
                );

                totalAtendidas++;

                cout << "Senha "
                     << senha
                     << " atendida no guiche "
                     << id
                     << endl;

                break;
            }

            case 4: {

                int id;

                cout << "ID do guiche: ";
                cin >> id;

                Guiche* g = buscarGuiche(id);

                if (g == NULL) {
                    cout << "Guiche nao encontrado.\n";
                    break;
                }

                cout << "\nSenhas atendidas pelo guiche "
                     << id << ":\n";

                NoFila* aux =
                    g->atendidas.inicio;

                if (aux == NULL) {
                    cout << "Nenhuma senha atendida.\n";
                }

                while (aux != NULL) {

                    cout << aux->senha << endl;

                    aux = aux->prox;
                }

                break;
            }

            case 0:

                if (!filaVazia(senhasGeradas)) {

                    cout << "Ainda existem senhas aguardando atendimento!\n";

                    opcao = -1;
                }

                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    cout << "\nSistema encerrado.\n";
    cout << "Total de senhas atendidas: "
         << totalAtendidas << endl;

    return 0;
}