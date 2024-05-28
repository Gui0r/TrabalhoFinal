#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

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
    Tarefa novaTarefa; // cria uma tarefa que tem todos os campos do structure vazios
    novaTarefa.id = rand() % 20;// atribui um id aleatorio de 1 a 20 para a nova tarefa
    cin.ignore();
    cout << "Digite o nome da tarefa: ";
    getline(cin, novaTarefa.nomeTarefa); // atribui um nome para a nova tarefa
    cout << "Digite a descrição da tarefa: ";
    getline(cin, novaTarefa.descricao); // atribui uma descricao a tarefa
    cout << "Digite a data de vencimento da tarefa: ";
    getline(cin, novaTarefa.dataVencimento); // atribui uma data de vencimento a nova tarefa
    novaTarefa.status = "Pendente"; // atribui "pendente" a o status da nova tarefa
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
void editarTarefas(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int res;
    cout << "Digite o ID da tarefa a ser editada: ";
    cin >> res;
    for(auto& tarefa : tarefas){
        if(tarefa.id == res){
            Tarefa editTarefa;
            cout << "Nome: ";
            getline(cin, editTarefa.nomeTarefa);
            cout << "Descrição: ";
            getline(cin, editTarefa.descricao);
            cout << "Data de Vencimento: ";
            getline(cin, editTarefa.dataVencimento);
        }else{
            cout << "Não tem nenhuma tarefa com esse ID\n";
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
        cout << "5. Sair\n";
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

            break;
            case 5:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 5);

    return 0;
}
