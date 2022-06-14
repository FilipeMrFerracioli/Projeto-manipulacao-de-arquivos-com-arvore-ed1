#ifndef NO_H
#define NO_H

namespace minhaNamespace {

template<class T>
class No
{
private:
    T chave;
public:
    No<T>* esquerda;
    No<T>* direita;

    No<T>():
        chave(0),
        esquerda(0),
        direita(0)
    {

    }

    No<T>(T dado):
        chave(dado),
        esquerda(0),
        direita(0)
    {

    }

    ~No<T>() {
        if(this->esquerda != 0) delete this->esquerda;
        if(this->direita != 0)  delete this->direita;
    }

    T getDado() const { return chave; }
    void setDado(T chave) { this->chave = chave; }

    No<T>* getDireita() { return direita; }
    void setDireita(No<T>* direita) { this->direita = direita; }

    No<T>* getEsquerda() { return esquerda; }
    void setEsquerda(No<T>* esquerda) { this->esquerda = esquerda; }
};
}

#endif // NO_H
