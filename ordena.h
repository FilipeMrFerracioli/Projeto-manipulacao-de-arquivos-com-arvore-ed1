#ifndef ORDENA_H
#define ORDENA_H

#include <QStringList>
#include <Arvore.h>
#include <pessoa.h>

namespace minhaNamespace {
class Ordena
{
private:
    Arvore<Pessoa> listaPessoas;
public:
    Ordena();

    bool getEPorNome() const{
        return false;
    }

    Pessoa splitPessoa(QString linhaPessoa);

    void setLista(Pessoa pessoa);

    QString getLista() ;
    QString getListaDesc();
};
}

#endif // ORDENA_H

