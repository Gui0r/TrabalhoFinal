
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// o struct cria uma "lista" de dados, mais pea uma estrutura
struct Tarefa {
    int id;
    string nomeTarefa;
    string descricao;
    string dataVencimento;
    string status;
};

// cria um vector para as tarefas existentes 
vector<Tarefa> tarefas;

void adicionarTarefa() {
    Tarefa novaTarefa; // cria uma tarefa que tem todos os campos do structure vazios
    cout << "Digite o ID da tarefa: ";
    cin >> novaTarefa.id; // atribui um id para a nova tarefa
    cin.ignore();
    cout << "Digite o nome da tarefa: ";
    getline(cin, novaTarefa.nomeTarefa); // atribui um nome para a nova tarefa
    cout << "Digite a descrição da tarefa: ";
    getline(cin, novaTarefa.descricao); // atribui uma descricao a tarefa
    cout << "Digite a data de vencimento da tarefa: ";
    getline(cin, novaTarefa.dataVencimento); // atribui uma data de vencimento a nova tarefa
    novaTarefa.status = "Pendente"; // atribui "pendente" a o status da nova tarefa
    tarefas.push_back(novaTarefa); // verifica se foi criado a nova tarefa
    cout << "Tarefa adicionada com sucesso!\n";
}

void listarTarefas() {
    if (tarefas.empty()) { // se não houver nemhuma tarefa 
        cout << "Não há tarefas cadastradas.\n";
    } else { // se houver tarefas
        cout << "Lista de Tarefas:\n";
        for (const auto& tarefa : tarefas) {
            cout << "ID: " << tarefa.id << "\n";
            cout << "Nome: " << tarefa.nomeTarefa << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Data de Vencimento: " << tarefa.dataVencimento << "\n";
            cout << "Status: " << tarefa.status << "\n\n";
        }
    }
}

int main() {
    int escolha;

    do {
        cout << "\nMenu:\n";
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Visualizar Tarefas\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 3);

    return 0;
}
