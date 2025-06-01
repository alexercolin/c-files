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

  remover(v) {
    // Se a lista estiver vazia
    if (this.head === null) {
      return false;
    }

    // Se o elemento a ser removido é o primeiro
    if (this.head.info === v) {
      this.head = this.head.prox;
      return true;
    }

    // Procurar o elemento na lista
    let anterior = this.head;
    let atual = this.head.prox;

    while (atual !== null) {
      if (atual.info === v) {
        anterior.prox = atual.prox;
        return true;
      }
      anterior = atual;
      atual = atual.prox;
    }

    // Elemento não encontrado
    return false;
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

  // Testando a função de remoção
  console.log("\nTestando remoção:");

  // Remover elemento 20
  if (lista.remover(20)) {
    console.log("Elemento 20 removido com sucesso");
  } else {
    console.log("Elemento 20 não encontrado para remoção");
  }

  console.log("Lista após remoção do 20:");
  lista.imprimir();

  // Remover elemento 5
  if (lista.remover(5)) {
    console.log("Elemento 5 removido com sucesso");
  } else {
    console.log("Elemento 5 não encontrado para remoção");
  }

  console.log("Lista após remoção do 5:");
  lista.imprimir();

  // Tentativa de remover elemento inexistente
  if (lista.remover(99)) {
    console.log("Elemento 99 removido com sucesso");
  } else {
    console.log("Elemento 99 não encontrado para remoção");
  }
}

main();
