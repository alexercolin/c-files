class Node {
  constructor(info) {
    this.info = info;
    this.prox = null;
  }
}

class Lista {
  constructor() {
    this.head = null;
  }

  inserir(i) {
    const novo = new Node(i);
    novo.prox = this.head;
    this.head = novo;
  }

  imprimir() {
    let p = this.head;
    while (p !== null) {
      console.log(p.info);
      p = p.prox;
    }
  }

  vazia() {
    return this.head === null;
  }

  buscar(v) {
    let p = this.head;
    while (p !== null) {
      if (p.info === v) {
        return p;
      }
      p = p.prox;
    }
    return null;
  }
}

function main() {
  const lista = new Lista();

  if (lista.vazia()) {
    console.log("Lista vazia!");
  } else {
    console.log("Lista NÃO vazia!");
  }

  lista.inserir(10);
  lista.inserir(20);
  lista.inserir(5);

  console.log("Conteúdo da lista:");
  lista.imprimir();

  const elemento = 5;
  const encontrado = lista.buscar(elemento);
  if (encontrado === null) {
    console.log(`Não encontrou o elemento ${elemento}`);
  } else {
    console.log(`Encontrou o elemento ${elemento}`);
  }
}

main();
