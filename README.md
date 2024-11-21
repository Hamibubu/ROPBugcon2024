# Workshop de Return-Oriented Programming (ROP) - BUGCON 2024

Presentación utilizada [aqui](https://view.genially.com/6733f67216580c329a1096c5/presentation-rop).

## Introducción

Este repositorio contiene los archivos utilizados durante el workshop sobre **Return-Oriented Programming (ROP)** que se realizó en la **BUGCON 2024**. El objetivo de este taller fue introducir a los participantes en el concepto de ROP, una técnica de explotación que permite ejecutar código malicioso sin necesidad de inyectar código, aprovechando fragmentos de código ya presente en el binario objetivo.

En este workshop, se discutieron los fundamentos de ROP y cómo los atacantes pueden encadenar gadgets existentes en la memoria para ejecutar sus propios comandos. Estos gadgets son fragmentos de código que terminan en una instrucción `ret` y pueden ser utilizados para alterar el flujo de ejecución de un programa.

## ¿Qué es Return-Oriented Programming (ROP)?

**Return-Oriented Programming (ROP)** es una técnica de explotación de vulnerabilidades que utiliza el control del flujo de ejecución en un programa para ejecutar código arbitrario sin necesidad de inyectar código. En lugar de escribir nuevos fragmentos de código, un atacante explota fragmentos existentes en el binario o en las bibliotecas cargadas en la memoria.

La técnica se basa en encadenar pequeños fragmentos de código llamados "gadgets". Cada gadget termina con una instrucción `ret`, lo que permite al atacante encadenar estos gadgets para ejecutar instrucciones arbitrarias. ROP se utiliza principalmente en situaciones donde las protecciones como la **Ejecución no válida (DEP)** y **Protección de la pila (ASLR)** están habilitadas.

## Compilación de los Binarios

Los binarios utilizados en este workshop fueron compilados con **GCC** usando las siguientes opciones:

```bash
gcc -m32 -fno-stack-protector -no-pie <binario.c> -o binario
```
## Explicación de las opciones de compilación:

- -m32: Compila el binario para una arquitectura de 32 bits. Esto es necesario porque ROP generalmente se realiza en un entorno de 32 bits debido a las características específicas de la arquitectura y la estructura de la pila.

- -fno-stack-protector: Desactiva la protección de la pila. En un entorno seguro, la protección de la pila está habilitada para prevenir ataques como el desbordamiento de búfer. Al desactivarla, permitimos que los atacantes manipulen la pila para lograr el control del flujo de ejecución.

- -no-pie: Desactiva la compilación de un binario independiente de la posición (PIE). PIE asigna direcciones aleatorias a las secciones del binario en la memoria, lo que complica los ataques de ROP. Desactivarlo permite a los participantes trabajar con direcciones fijas y facilita la explotación.

## Objetivos del Workshop

Durante el workshop, los participantes aprenderan a:

1. Entender la técnica de Return-Oriented Programming (ROP): Aprender cómo los atacantes pueden usar gadgets existentes en el binario para controlar el flujo de ejecución.
2. Explotar vulnerabilidades de desbordamiento de búfer: Usar un desbordamiento de búfer para controlar la dirección de retorno de una función y encadenar gadgets de ROP.
3. Crear un payload de ROP: Encadenar gadgets y construir un payload para ejecutar código arbitrario.