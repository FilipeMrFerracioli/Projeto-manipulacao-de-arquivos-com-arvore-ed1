#ifndef ARVORE_H
#define ARVORE_H

#include <No.h>
#include <QString>
#include <pessoa.h>

namespace minhaNamespace {

template<class T>
class Arvore
{
private:
    No<T>* raiz;
public:
    Arvore<T>():
        raiz(0)
    {

    }

    ~Arvore<T>()
    {
        if(raiz != 0){
            delete raiz;
        }
    }

    No<T>** getRaiz() {
        return &raiz;
    }

    No<T>* getRaiz2() {
        return raiz;
    }

    void inserirRecursivo(No<T> **raiz, T elemento){
        if(*raiz == 0) {
            *raiz = new No<T>(elemento);
        } else
            if(elemento < (*raiz)->getDado())
                inserirRecursivo(&(*raiz)->esquerda, elemento);
            else
                if(elemento > (*raiz)->getDado() )
                    inserirRecursivo(&(*raiz)->direita, elemento);
                else throw std::string("Elemento já Existe");
    }

    //    QString centralEsq(No<T>* raiz){
    //        if(raiz != 0){
    //            QString res = "\n" + centralEsq(raiz->getEsquerda());
    //            //            res += raiz->getDado();
    //            res += raiz->getDado();
    //            res += centralEsq(raiz->getDireita());
    //            return res;
    //        }
    //    }

    //    QString centralEsq(No<T>* raiz){
    //        if(raiz != 0){
    //            QString res = "";

    //            res += centralEsq(raiz->getEsquerda());

    //            Pessoa pes = raiz->getDado();
    //            res += QString::number(pes.getMatricula());
    //            res += "\n";
    //            res += pes.getNome();

    //            res += centralEsq(raiz->getDireita());

    //            return res;
    //        }
    //    }

    QString centralEsq(No<T>* raiz){
        QString res = "";
        Pessoa pes;

        if(raiz != 0){
            res += centralEsq(raiz->getEsquerda());
            res += "\n";
            pes = raiz->getDado();
            res += QString::number(pes.getMatricula());
            res += "\n";
            res += pes.getNome();
            res += "\n";
            res += centralEsq(raiz->getDireita());
        }

        return res;
    }

    QString centralDir(No<T>* raiz){
        QString res = "";
        Pessoa pes;

        if(raiz != 0){
            res += centralDir(raiz->getDireita());
            res += "\n";
            pes = raiz->getDado();
            res += QString::number(pes.getMatricula());
            res += "\n";
            res += pes.getNome();
            res += "\n";
            res += centralDir(raiz->getEsquerda());
        }

        return res;
    }

    //    QString centralDir(No<T>* raiz)const{
    //        if(raiz != 0){
    //            QString res = "\n" + centralDir(raiz->getDireita());
    //            res += raiz->getDado();
    //            res += centralDir(raiz->getEsquerda());
    //            return res;
    //        }
    //    }

    void preFixEsq(No<T>* raiz)const{
        if(raiz != 0){
            //            std::cout<<std::endl<<"Elemento=>  "<<raiz->getDado();
            preFixEsq(raiz->getEsquerda());
            preFixEsq(raiz->getDireita());
        }
    }

    void preFixDir(No<T>* raiz)const{
        if(raiz != 0){
            //            std::cout<<std::endl<<"Elemento=>  "<<raiz->getDado();
            preFixDir(raiz->getDireita());
            preFixDir(raiz->getEsquerda());
        }
    }

    void posFixEsq(No<T>* raiz)const{
        if(raiz != 0){
            posFixEsq(raiz->getEsquerda());
            posFixEsq(raiz->getDireita());
            //            std::cout<<std::endl<<"Elemento=>  "<<raiz->getDado();
        }
    }

    void posFixDir(No<T>* raiz)const{
        if(raiz != 0){
            posFixDir(raiz->getDireita());
            posFixDir(raiz->getEsquerda());
            //            std::cout<<std::endl<<"Elemento=>  "<<raiz->getDado();
        }
    }

    int retornar_Maior(No<T> **raiz){
        T valor;
        No<T> *aux = 0;
        if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));
        else{
            aux = *raiz;
            valor = (*raiz)->getDado();
            *raiz = (*raiz)->esquerda;
            aux->esquerda = 0;
            aux->direita = 0;
            delete aux;
            return valor;
        }
    }

    void removerRecursivo(No<T> **raiz, T elemento){
        No<T> *aux = 0;

        if(*raiz != 0){
            if((*raiz)->getDado() == elemento){
                aux = *raiz;
                if((*raiz)->esquerda == 0){
                    *raiz = (*raiz)->direita;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;
                }else
                    if((*raiz)->direita == 0){
                        *raiz = (*raiz)->esquerda;
                        aux->esquerda = 0;
                        aux->direita = 0;
                        delete aux;
                    }else
                    {
                        (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                    }
            }else
            {
                if((*raiz)->getDado() < elemento)
                    removerRecursivo(&(*raiz)->direita,elemento);
                else
                    if((*raiz)->getDado() > elemento)
                        removerRecursivo(&(*raiz)->esquerda,elemento);
            }

        }
        else throw std::string("Elemento não Existe");
    }
};
}

#endif // ARVORE_H
