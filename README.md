# Super Mario Bros

## Índice:
1. Sobre o Jogo
2. Informações Técnicas
3. Instruções de Uso e Instalação


# SOBRE O JOGO

Super Mario Bros é uma versão modernizada do jogo homônimo criado pela Nintendo em 1985. Através do uso da biblioteca gráfica Allegro, criamos um jogo que tenta ser fiel em relação aos recursos do jogo original, de forma que ainda cumpríssemos todos os requisitos solicitados.


# INFORMAÇÕES TÉCNICAS

Nesta seção, detalharemos o funcionamento de cada um dos requisitos base do projeto.

### Utilização de Árvore Binária

O jogo utiliza-se de uma árvore binária em seu seletor de fase, através de um arquivo, as informações de fases liberadas, passadas e bloqueadas são recuperadas sempre que o jogo é aberto. A utilização de uma árvore facilita no processo de navegação do mapa.

### Busca Binária Recursiva

A busca binária foi utilizada para encontrar de maneira eficiente alguém específico do ranking.

### Bubble Sort

O algoritmo de ordenação bubble sort foi utilizado para apresentar as 10 melhores pontuações, e também preparar a lista para a busca binária.

### Backtracking

O Backtracking foi a técnica utilizada para fazermos o efeito de volta no tempo. Utilizamos também uma pilha, para aumentar a eficiência desse algoritmo.


# INSTRUÇÕES DE USO E INSTALAÇÃO

 INSTALANDO:
 
Para rodar o jogo, é necessário ter instalado a biblioteca Allegro 5 instalada.
	
No Windows:

	•	Link com o CodeBlocks (ide passível de se instalar o Allegro): http://www.codeblocks.org/downloads;
	•	Link com um tutorial de como instalar o Allegro 5 na ide CodeBlocks: https://sites.google.com/a/liesenberg.biz/cjogos/home/software/ambiente-code-blocks-allegro-5
  
No Linux:

No Linux o Allegro deve ser instalado via ppa e o projeto deve ser compilado usando CMake:

	•	Link para instalar via PPA: https://wiki.allegro.cc/index.php?title=Install_Allegro_from_Ubuntu_PPAs
  
No MacOS:

No MacOS, basta utilizar a aplicação "homebrew", conforme esse tutorial: 

	• https://wiki.allegro.cc/index.php?title=Installing_with_homebrew
	
E seguir os mesmos passos que foram utilizados no linux, compilando via Cmake.

Pedimos que altere o CmakeLists.txt para apontar corretamente a localização das pastas include e lib do Allegro, estas pastas mudam conforme o sistema.

Se possível, usar a IDE Clion para testar o jogo.
  
O jogo utiliza uma pasta de recursos necessários, contendo todos os itens de jogo, como sons ou sprites. Devido a IDE que foi usada durante o desenvolvimento do projeto, não pudemos usar caminhos relativos. Então pedimos por favor que seja feito um Global Find-Replace em todos os arquivos do projeto para alterar as URIs para apontar corretamente à pasta de recursos em seu computador. Isso será arrumado em breve.

 JOGANDO:

	Para jogar, o usuário deverá ter o conhecimento dos seguintes botões:
		→: (seta para direita) usada para mover o Mario para a direita;
		←: (seta para esquerda) usada para mover o Mario para a esquerda;
		↑: (seta para cima) usada para fazer o Mario dar pulos;
		Shift: usada para fazer o Mario voltar no tempo.

Ao pular sobre um goomba, o Mario mata esse goomba, porém, atenção, ao ter mais de um goomba junto, o Mario sempre irá morrer se pular sobre estes, já que ele apenas mata um por vez.

A pontuação é dada pela coleta de moedas e ações como destruir um Bloco de Segredo e matar inimigos, você passa de fase assim que o Mario conseguir chegar ao final do mapa sem o tempo acabar.

A volta no tempo pode ser usada quando quiser, porém ela não volta a contagem de segundos que o Mario tem para chegar ao final da fase, portanto, utilize com cautela. Se o tempo acabar, voce automaticamente perde uma vida e seu progresso na fase.



