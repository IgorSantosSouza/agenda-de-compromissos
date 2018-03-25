#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

template <typename T> class No{
	public:
		No():prox(NULL),ant(NULL){};
		T n;
		No* prox;
		No* ant;
};

template <typename T> class Lista{
	public:
        Lista():primeiro(NULL),ultimo(NULL),atual(NULL), quant(0){};
		No<T> *primeiro;
		No<T> *ultimo;
		No<T> *atual;
		int quant;

		void inserir(T n){
			No<T> *novo_no = new No<T>();
			novo_no->n = n;
			if(quant == 0){
				primeiro = novo_no;
				ultimo = novo_no;
			}
			else{
				atual = busca_prox(novo_no);
				if(atual != NULL){
					novo_no->prox = atual;
					if(atual != primeiro){
						novo_no->ant = atual->ant;
						novo_no->ant->prox = novo_no;
					}
					else{
						novo_no->ant = NULL;
						primeiro = novo_no;
					}
					atual->ant = novo_no;
				}
				else{
					ultimo->prox = novo_no;
					novo_no->prox = NULL;
					novo_no->ant = ultimo;
					ultimo = novo_no;
				}
			}
			quant++;
		}

		No<T>* busca_prox(No<T>* novo_no){
			No<T>* A = primeiro;
			while(A != NULL){
				if(A->n >= novo_no->n){
					return A;
				}
				A= A->prox;
			}
			return NULL;
		}

		void remover(T n){
			No<T>* A = busca(n);
			if(A != NULL){
				if(A == primeiro){
					if(quant == 1){
						primeiro = NULL;
						ultimo = NULL;
					}
					else{
						primeiro = A->prox;
						primeiro->ant == NULL;
					}
					free(A);
				}
				else if(A == ultimo){
					ultimo = A->ant;
					ultimo->prox = NULL;
					free(A);
				}
				else{
					A->prox->ant = A->ant;
					A->ant->prox = A->prox;
					free(A);
				}
				quant --;
			}
		}
		
		No<T>* busca(T n){
            No<T>* A = primeiro;
			while(A != NULL){
				if(A->n == n){
					return A;
				}
				A = A->prox;
			}
			return NULL;
		}
};

class Compromisso{
	private:
		string titulo;
		int dia;
		int mes;
		int ano;
		string local;
		
	public:
		Compromisso():titulo(""),dia(1),mes(1),ano(1),local(""){};
		Compromisso(string t, int d, int m, int a, string l){
			if( (d < 1) || (d > 31)){
				d = 1;
			}
			if( (m < 1) || (m > 12)){
				m = 1;
			}
			dia = d;
			mes = m;
			ano = a;
			titulo = t;
			local = l;
		}
		void setTitulo(string s){
			titulo = s;
		}
		void setDia(int x){
			if( (x < 1) || (x > 31)){
				x = 1;
			}
			dia = x;
		}
		void setMes(int x){
			if( (x < 1) || (x > 12)){
				x = 1;
			}
			mes = x;
		}
		void setAno(int x){
			ano = x;
		}
		void setLocal(string s){
			local = s;
		}
		string getTitulo(){
			return titulo;
		}
		int getDia(){
			return dia;
		}
		int getMes(){
			return mes;
		}
		int getAno(){
			return ano;
		}
		string getLocal(){
			return local;
		}
};

class Pessoa{
	private:
		string nome;
	public:
		Lista<Compromisso> agenda;
		Pessoa(){
		};
		Pessoa(string n):nome(n){};
		void setNome(string n){
			nome = n;
		}
		string getNome(){
			return nome;
		}
		
};

bool operator>=(Compromisso A, Compromisso B){
	if((A.getAno() > B.getAno()) || ((A.getAno() == B.getAno()) && (A.getMes() > B.getMes())) 
						|| ((A.getAno() == B.getAno()) && (A.getMes() == B.getMes())) && (A.getDia() >= B.getDia())){
		return true;
	}
}

bool operator==(Compromisso A, Compromisso B){
	if((A.getTitulo() == B.getTitulo()) && (A.getDia() == B.getDia())
			&& (A.getMes() == B.getMes()) && (A.getAno() == B.getAno()) && (A.getLocal() == B.getLocal()) ){
					
		return true;
	}
	else{
		return false;
	}
}

bool operator>=(Pessoa A, Pessoa B){
	if(A.getNome().length() >= B.getNome().length()){
		return true;
	}
	else{
		return false;
	}
}

bool operator==(Pessoa A, Pessoa B){
	if(A.getNome() == B.getNome()){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	Lista<Pessoa> lista;
	No<Pessoa>* atual;
	No<Compromisso>* comp_atual;
	lista.inserir(Pessoa("Ana"));
	lista.inserir(Pessoa("Maria"));
	lista.inserir(Pessoa("Joao"));
	atual = lista.primeiro;
	lista.primeiro->n.agenda.inserir(Compromisso("Compromisso A1", 1, 1, 2000, "Local 1"));
	lista.primeiro->prox->n.agenda.inserir(Compromisso("Compromisso B1", 2, 2, 2000, "Local 1"));
	lista.primeiro->prox->n.agenda.inserir(Compromisso("Compromisso B2", 13, 6, 1999, "Local 2"));
	lista.primeiro->prox->n.agenda.inserir(Compromisso("Compromisso B3", 10, 6, 1999, "Local 3"));
	lista.primeiro->prox->prox->n.agenda.inserir(Compromisso("Compromisso C1", 3, 3, 2000, "Local 1"));
	lista.primeiro->prox->prox->n.agenda.inserir(Compromisso("Compromisso C2", 22, 9, 2000, "Local 1"));
	
	for(int i=0; i<lista.quant; i++){
		cout<<atual->n.getNome()<<endl;
		comp_atual = atual->n.agenda.primeiro;
		for(int i=0; i<atual->n.agenda.quant; i++){
			cout<<comp_atual->n.getTitulo()<<endl;
			comp_atual = comp_atual->prox;
		}
		atual = atual->prox;
	}
	
	system("pause");
	return 0;

}
