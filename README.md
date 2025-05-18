# Projeto: Simulador de Movimentação de Peças de Xadrez em C

##  Objetivos

Este projeto tem como finalidade:

- Simular os movimentos das principais peças do xadrez utilizando **estruturas de repetição** (`for`, `while`, `do-while`).
- Utilizar **loops aninhados** para simular movimentos complexos, como o "L" do **Cavalo**.
- Explorar o uso de **recursividade** em movimentos contínuos como os da **Rainha**, **Bispo** e **Torre**.

##  Como criar o projeto no Visual Studio 2022

1. Abra o **Visual Studio 2022**.
2. Vá em `Arquivo` > `Novo` > `Projeto...`.
3. Selecione **"Aplicativo de Console (C)"**.
4. Nomeie o projeto como `XadrezMovimento`.
5. Escolha o local de salvamento e clique em `Criar`.
6. No arquivo `main.c`, insira o código do simulador.
7. Pressione `Ctrl + S` para salvar o projeto.

## Como compilar e executar

1. Clique em `Compilar > Compilar Solução` (ou `Ctrl + Shift + B`).
2. Após a compilação, clique em `Depurar > Iniciar sem Depuração` (ou `Ctrl + F5`) para executar o programa.
3. Interaja com o console para selecionar a peça e ver os movimentos possíveis no tabuleiro.

##  Peças Simuladas e Técnicas Aplicadas

- **Torre**:
  - Movimento vertical e horizontal.
  - Implementado com `for` e `while`.

- **Bispo**:
  - Movimento diagonal.
  - Implementado com `for` aninhado.

- **Rainha**:
  - Combinação de Torre + Bispo.
  - Implementado com `recursividade` e `loops`.

- **Cavalo**:
  - Movimento em "L".
  - Implementado com `loops aninhados` e múltiplas condições.

## 🧠 Técnicas e Conceitos

- Matrizes 2D (`tabuleiro[8][8]`) representam o tabuleiro de xadrez.
- Uso de loops para marcar e exibir posições válidas.
- Recursividade opcional para movimentações contínuas (ex: Rainha em múltiplas direções).
- Condições de limite para evitar sair do tabuleiro.


## 👨‍💻 Ricardo Augusto

Desenvolvido como parte de um projeto acadêmico para treinar estruturas de repetição, recursividade e lógica de programação com linguagem C.
