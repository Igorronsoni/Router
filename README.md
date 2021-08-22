# Router

## Inf
Por motivos de força maior, não foi possível configurar o arquivo CMake para esta etapa do projeto, mas estou fazendo minhas orações ao 
nosso ateu homossexual Alan Turing para que na proxima entrega, tudo esteja funcionando do jeito que deve ser
#### Compilação

Para a compilação do programa, primeiro deve-se copiar o código abaixo

```sh
git clone https://github.com/Igorronsoni/Router.git
cd Router
rm -rf build && mkdir build && cd build && gcc -c ../implementation/util.c && gcc -c ../src/router.c && gcc -c ../implementation/terminal.c &&  gcc -o Router router.o terminal.o util.o -lm
```

#### Execução

Para a execução, copie e cole o código no seu terminal

```
./Router
```
