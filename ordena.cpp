#include "ordena.h"

namespace minhaNamespace {

Ordena::Ordena():
    listaPessoas()
{

}

Pessoa Ordena::splitPessoa(QString linhaPessoa)
{
    QStringList pessoa = linhaPessoa.split(";");

    if(pessoa.length() != 2) return Pessoa();

    return Pessoa(pessoa[0].toInt(), pessoa[1], getEPorNome());
}

void Ordena::setLista(Pessoa pessoa)
{
    //    listaPessoas.inserirInicio(pessoa);
    listaPessoas.inserirRecursivo(listaPessoas.getRaiz(), pessoa);
}

QString Ordena::getLista()
{
    //        return listaPessoas.centralEsq(listaPessoas.getRaiz2());
    return listaPessoas.centralEsq(listaPessoas.getRaiz2());
}

QString Ordena::getListaDesc()
{
    //    return listaPessoas.centralDir(&(*listaPessoas.getRaiz()));
    return listaPessoas.centralDir(listaPessoas.getRaiz2());
}

}
