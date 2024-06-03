#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <regex>

using namespace std;

// O struct cria uma "lista" de dados, mais para uma estrutura
struct Tarefa {
    int id;
    string nomeTarefa;
    string descricao;
    string dataVencimento;
    string status;
};

// Cria um vector para as tarefas existentes 
vector<Tarefa> tarefas;

void adicionarTarefa() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int resp;
    Tarefa novaTarefa; // Cria uma tarefa que tem todos os campos do structure vazios
    novaTarefa.id = rand() % 20; // Atribui um id aleatorio de 1 a 20 para a nova tarefa
    cin.ignore();
    cout << "Digite o nome da tarefa: ";
    getline(cin, novaTarefa.nomeTarefa); // Atribui um nome para a nova tarefa
    cout << "Digite a descrição da tarefa: ";
    getline(cin, novaTarefa.descricao); // Atribui uma descricao a tarefa
    cout << "Digite a data de vencimento da tarefa (DD/MM/AAAA): ";
    getline(cin, novaTarefa.dataVencimento); // Atribui uma data de vencimento a nova tarefa
    cout << "Sua tarefa está concluida ou em pendencia? (1 para pendente ou 2 para em progresso e 3 para concuida): ";
    cin >> resp;

    switch (resp) {
        case 1:
            novaTarefa.status = "Pendente"; 
            break;
        case 2:
            novaTarefa.status = "Em progresso";
            break;
        case 3:
            novaTarefa.status = "Concluida";
            break;
    }

    // Adiciona a nova tarefa ao vetor
    tarefas.push_back(novaTarefa);

    cout << "Tarefa adicionada com sucesso!\n";
}

void listarTarefas() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    if (tarefas.empty()) { // Se não houver nenhuma tarefa 
        cout << "Não há tarefas cadastradas.\n";
    } else { // Se houver tarefas
        cout << "========== Lista de Tarefas: ==========\n";
        for (const auto& tarefa : tarefas) { // Cria uma variavel tarefa que represetará os elementos do vetor / o "auto" verifica automaticamente que tipo de dados é com base no vector
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
            if (!nome.empty()) { // Esse comando impede que o usuario atribua campos vazios, ou seja, se ele clicar enter sem digitar nada o campo que esta a ser editado permanecera o mesmo 
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

    auto a = remove_if(tarefas.begin(), tarefas.end(), [id](const Tarefa& tarefa) {
        return tarefa.id == id;
    });

    if (a != tarefas.end()) {
        tarefas.erase(a, tarefas.end());
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
        if (tarefa.nomeTarefa.find(nome) == 0) { // Verifica se o nome da tarefa começa com a string fornecida
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

void filtrarTarefasPorStatus() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int opcao;
    cout << "Escolha o status para filtrar as tarefas (1 para Pendente, 2 para Em Progresso, 3 para Concluída): ";
    cin >> opcao;
    
    string status;
    switch (opcao) {
        case 1:
            status = "Pendente";
            break;
        case 2:
            status = "Em progresso";
            break;
        case 3:
            status = "Concluída";
            break;
        default:
            cout << "Opção inválida.\n";
            return;
    }

    cout << "========== Tarefas com Status: " << status << " ==========\n";
    for (const auto& tarefa : tarefas) {
        if (tarefa.status == status) {
            cout << "ID: " << tarefa.id << "\n";
            cout << "Nome: " << tarefa.nomeTarefa << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Data de Vencimento: " << tarefa.dataVencimento << "\n";
            cout << "Status: " << tarefa.status << "\n\n";
        }
    }
}

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
                filtrarTarefasPorStatus();
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
