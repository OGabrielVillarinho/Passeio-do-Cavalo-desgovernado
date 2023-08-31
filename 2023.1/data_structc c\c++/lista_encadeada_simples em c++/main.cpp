#include <iostream>

using namespace std;

struct Aluno {
    int id;
    string nome;
    short idade;
};

struct node {
    Aluno data;
    node *next;
};

void add(node *&root, Aluno aluno) {
    node *newNode = new node;
    newNode->data = aluno;

    if (root == NULL) {
        root = newNode;
        return;
    }

    node *aux = root;
    while (aux->next != NULL)
        aux = aux->next;
    
    aux->next = newNode;
        
}

void cleanList(node *&root) {
    while (root != NULL) {
        node *aux = root;
        root = root->next;
        delete aux;
    }
}

int len(node *root) {
    int count = 0;
    node *aux = root;
    while (aux != NULL) {
        count++;
        aux = aux->next;
    }

    return count;
}


void displayList(node *root, void(*printAluno)(Aluno)) {
    cout << "\n";
    node *aux = root;
    for (int i = 0; i < len(root); i++) {
        printAluno(aux->data);
        aux = aux->next;
        cout << "\n";
    }
}
void removeByID(node *&root, int id) {
    node *aux = root, *prev = NULL;
    while (aux->data.id != id) {
        prev = aux;
        aux = aux->next;
    }

    if (prev == NULL) {
        root = root->next;
    } else {
        prev->next = aux->next;
    }

    delete aux;
}

void swapNode(node *root, int p1, int p2) {
    int i = -1, j = -1;
    node *aux1 = root, *aux2 = root;
    while (++i < p1) aux1 = aux1->next;
    while (++j < p2) aux2 = aux2->next;
    Aluno value = aux1->data;
    aux1->data = aux2->data;
    aux2->data = value;
}

//Funções complementares para a struct aluno
void printAluno(Aluno aluno) {

    cout << "ID: " << aluno.id << "\n";
    cout << "Nome: " << aluno.nome << "\n";
    cout << "Idade: " << aluno.idade << "\n";
}


int main(int argc, char **argv) {
    node *root = NULL;

    add(root, {1, "Gabriel", 20});
    add(root, {2, "Diogo", 20});
    add(root, {3, "Caio", 20});
    add(root, {4, "Vidal", 20});
    displayList(root, printAluno);
    removeByID(root, 2);   
    displayList(root, printAluno);

    cleanList(root);
}