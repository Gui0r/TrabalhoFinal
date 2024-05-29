#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <regex>

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
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int resp;
    Tarefa novaTarefa; // cria uma tarefa que tem todos os campos do structure vazios
    novaTarefa.id = rand() % 20;// atribui um id aleatorio de 1 a 20 para a nova tarefa
    cin.ignore();
    cout << "Digite o nome da tarefa: ";
    getline(cin, novaTarefa.nomeTarefa); // atribui um nome para a nova tarefa
    cout << "Digite a descrição da tarefa: ";
    getline(cin, novaTarefa.descricao); // atribui uma descricao a tarefa
    cout << "Digite a data de vencimento da tarefa (DD/MM/AAAA): ";
    getline(cin, novaTarefa.dataVencimento); // atribui uma data de vencimento a nova tarefa
     cout << "Sua tarefa está concluida ou em pendencia? (1 para pendente ou 2 para concluida): ";
     cin >> resp;
    if (resp = 1){
        novaTarefa.status = "Pendente"; // atribui pendente ao status da tarefa
    }else{
        novaTarefa.status = "Concluida"; // atribui concluido ao status da tarefa
    }
    tarefas.push_back(novaTarefa); // criado a nova tarefa
    cout << "Tarefa adicionada com sucesso!\n";
}

void listarTarefas() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    if (tarefas.empty()) { // se não houver nemhuma tarefa 
        cout << "Não há tarefas cadastradas.\n";
    } else { // se houver tarefas
        cout << "========== Lista de Tarefas: ==========\n";
        for (const auto& tarefa : tarefas) { // cria uma variavel tarefa que represetara os elementos do vetor / o "auto" verifica automaticamente que tipo de dados é com base no vector
            cout << "ID: " << tarefa.id << "\n";
            cout << "Nome: " << tarefa.nomeTarefa << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Data de Vencimento: " << tarefa.dataVencimento << "\n";
            cout << "Status: " << tarefa.status << "\n\n";
        }
    }
}

void editarTarefas() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int id;
    cout << "Digite o ID da tarefa a ser editada: ";
    cin >> id;
    cin.ignore(); 

    for (auto& tarefa : tarefas) {
        if (tarefa.id == id) {
            cout << "Digite o novo nome da tarefa: ";
            string nome;
            getline(cin, nome);
            if (!nome.empty()) {
                tarefa.nomeTarefa = nome;
            }

            cout << "Digite a nova descrição da tarefa: ";
            string descricao;
            getline(cin, descricao);
            if (!descricao.empty()) {
                tarefa.descricao = descricao;
            }

            cout << "Digite a nova data de vencimento da tarefa: ";
            string dataVencimento;
            getline(cin, dataVencimento);
            if (!dataVencimento.empty()) {
                tarefa.dataVencimento = dataVencimento;
            }

            cout << "Digite o novo status da tarefa: ";
            string status;
            getline(cin, status);
            if (!status.empty()) {
                tarefa.status = status;
            }

            cout << "Tarefa editada com sucesso!\n";
            return;
        }
    }
    cout << "Não foi encontrada nenhuma tarefa com o ID fornecido.\n";
}

void removerTarefa() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int id;
    cout << "Digite o ID da tarefa para ser removida: ";
    cin >> id;

    auto it = remove_if(tarefas.begin(), tarefas.end(), [id](const Tarefa& tarefa) {
        return tarefa.id == id;
    });

    if (it != tarefas.end()) {
        tarefas.erase(it, tarefas.end());
        cout << "Tarefa removida com sucesso!\n";
    } else {
        cout << "Não foi encontrada nenhuma tarefa com o ID fornecido.\n";
    }
}

void pesquisarTarefas() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string nome;
    cout << "Digite o nome (ou as primeiras letras) da tarefa que deseja pesquisar: ";
    cin >> nome;

    bool found = false;
    for (const auto& tarefa : tarefas) {
        if (tarefa.nomeTarefa.find(nome) == 0) { // verifica se o nome da tarefa começa com a string fornecida
            if (!found) {
                cout << "========== Resultados da Pesquisa: ==========\n";
                found = true;
            }
            cout << "ID: " << tarefa.id << "\n";
            cout << "Nome: " << tarefa.nomeTarefa << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Data de Vencimento: " << tarefa.dataVencimento << "\n";
            cout << "Status: " << tarefa.status << "\n\n";
        }
    }

    if (!found) {
        cout << "Nenhuma tarefa encontrada com o critério de pesquisa fornecido.\n";
    }
}

/*
  if (tarefas.empty()) { // se não houver nemhuma tarefa 
        cout << "Não há tarefas cadastradas.\n";
    } else { // se houver tarefas
        cout << "========== Lista de Tarefas: ==========\n";
        for (const auto& tarefa : tarefas) { // cria uma variavel tarefa que represetara os elementos do vetor / o "auto" verifica automaticamente que tipo de dados é com base no vector
            cout << "ID: " << tarefa.id << "\n";
            cout << "Nome: " << tarefa.nomeTarefa << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Data de Vencimento: " << tarefa.dataVencimento << "\n";
            cout << "Status: " << tarefa.status << "\n\n";
        }
    }
    */

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int escolha;

    do {
        cout << "========== Menu: ==========\n";
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Visualizar Tarefas\n";
        cout << "3. Editar Tarefas\n";
        cout << "4. Remover Tarefa\n";
        cout << "5. Buscar Tarefa\n";
        cout << "6. Filtrar tarefa por status\n";
        cout << "7. Sair\n";
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
                editarTarefas();
            break;
            case 4:
                removerTarefa();
            break;
            case 5:
                pesquisarTarefas();
                break;
            case 6:

            break;
            case 7:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 7);

    return 0;
}
