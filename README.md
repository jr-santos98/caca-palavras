# Caça Palavras

Esse software recebe um arquivo de texto simples contendo as palavras a serem
procuradas e um caça-palavras.
O código [*caca-palavras.c*](caca-palavras.c) irá encontrar as palavras na sequência que aparecem no
arquivo de texto de forma dinâmica.
Já o código [*th-caca-palavras.c*](th-caca-palavras.c) irá criar uma thread para
encontrar cada uma das palavras.

# Execução

Para executar o programa, basta dar clone no repositório e utilizar o comando
*make* para compilar os códigos. A partir dai, basta executar o códigos para
que o programa seja executado.

# Utilizando um Caça-palavras próprio

O [caça palavras](Animes - Caça Palavras.pdf) criado, foi feito utilizando uma
plataforma de criação automatizada chamado [Geniol](https://www.geniol.com.br/palavras/caca-palavras/criador/).
Pode se utilizar qualquer caça-palavras na execução desse programa.

O requesito para utilizar o seu caça-palavras próprio, é editar o arquivo [*palavras.txt*](palavras.txt),
de forma a utilizar no máximo 20 palavras a serem buscadas em um caça-palavras de no máximo
30 letras de largura e 30 letras de comprimento. Para aumentar essas características, é necessário
alterar o código fonte.

Cada palavra deve ser registrada em uma linha, seguido por uma linha contendo um "-",
após isso, basta inserir o caça-palavras sem espaçamento entre as colunas.
